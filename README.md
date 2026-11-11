# cppui - A C++ framework for creating performant, cross-platform desktop apps.

## Plans for cppui
- Create a component-based architecture for building user interfaces, similar to [React](https://github.com/react/react/) or other web frameworks.

## Third-Party libraries used
- [SDL](https://www.libsdl.org/): the rendering backend cppui uses
- [SDL_ttf](https://github.com/libsdl-org/SDL_ttf): for font loading and text rendering
- [SDL_image](https://github.com/libsdl-org/SDL_image): for rendering image files

## Building cppui from source
cppui uses CMake, alongside a custom python build system to merge SDL static libraries to create a standalong library.

To build cppui, run: 
```bash
python build.py
```
alongside any other arguments you want to be forwarded to CMake. For example:
```bash
python build.py -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=...
```

You will need CMake, ninja or make, and SDL3, SDL3_image, and SDL3_ttf installed in a directory where CMake can find them.