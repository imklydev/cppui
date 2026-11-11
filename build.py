#!/usr/bin/env python3
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent
BUILD = ROOT / "build"


def fail(msg):
    print(f"error: {msg}", file=sys.stderr)
    sys.exit(1)


def run(cmd):
    print("+", " ".join(map(str, cmd)), flush=True)
    if subprocess.run(cmd).returncode != 0:
        fail(f"command failed: {cmd[0]}")

def build_project():
    if not shutil.which("cmake"):
        fail("cmake not found in PATH")

    if shutil.which("ninja"):
        generator = "Ninja"
    elif shutil.which("make"):
        generator = "Unix Makefiles"
    elif shutil.which("mingw32-make"):
        generator = "MinGW Makefiles"
    else:
        fail("neither ninja nor make found in PATH")

    BUILD.mkdir(exist_ok=True)

    # Extra args are forwarded to cmake, e.g.:
    #   python build.py -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=...
    run(["cmake", "-S", str(ROOT), "-B", str(BUILD), "-G", generator, *sys.argv[1:]])
    run(["cmake", "--build", str(BUILD)])

def merge_lib_with_sdl_libs():
    ar = shutil.which("ar")
    if not ar:
        fail("ar not found in PATH")

    bundle_libs = BUILD / "bundle_libs.txt"
    if not bundle_libs.exists():
        fail(f"{bundle_libs} not found")

    libs = [Path(l.strip()) for l in bundle_libs.read_text().splitlines() if l.strip()]

    out = libs[0]

    with tempfile.TemporaryDirectory() as tmp:
        tmp = Path(tmp)

        mri = ["CREATE libcppui.a"]
        for i, lib in enumerate(libs):
            shutil.copyfile(lib, tmp / f"lib{i}.a")
            mri.append(f"ADDLIB lib{i}.a")

        mri += ["SAVE", "END"]

        bundle_mri = (tmp / "bundle.mri")

        bundle_mri.write_text("\n".join(mri) + "\n")

        with open(bundle_mri, "r") as f:
            if(subprocess.run(["ar", "-M"], stdin=f, cwd=tmp).returncode != 0):
                fail("ar -M (merging cppui with SDL3 static libraies) failed")
        shutil.copyfile((tmp / "libcppui.a"), out)

    
    print(f"Bundled cppui with SDL3 dependencies")

def create_dist_folder():
    DIST = ROOT / "dist"
    LIB = DIST / "lib"

    # Recreate dist folder
    if DIST.exists():
        shutil.rmtree(DIST)
    DIST.mkdir()

    LIB.mkdir()

    # Copy public headers
    shutil.copytree(ROOT / "include", DIST / "include")

    # Copy compiled library
    shutil.copy2(BUILD / "libcppui.a", LIB / "libcppui.a")

    print(f"Created distribution folder at {DIST}")

def main():
    build_project()

    # Merge cppui with SDL3 static libraries, so it works as a standalone lib
    merge_lib_with_sdl_libs()

    create_dist_folder()


if __name__ == "__main__":
    main()