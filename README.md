# cppui - A C++ framework for creating performant, cross-platform desktop apps

## Code example
```cpp
#include "app.h"

Font font = GetFont("JetBrainsMono.ttf", 16.0f);

int number = 0;

void increment_number()
{
    number++;

    app.GetChild("counter")->ChangeText("The button was pressed " + std::to_string(number) + " times");
}

App Application()
{
    debug("hello world!");

    return App({
        HorizontalContainer({
            VerticalContainer({
                Text("hello world!", font, WHITE),
                Text("The button was pressed 0 times", font, WHITE)->setID("counter"),
                Button(increment_number, WHITE, {
                    Text("Click me!", font, BLACK),
                }),
            }),
            Image("cat.png", {80, 80}),
        })
    });
}
```

## A simple calculator app made with cppui in about 300 lines of code
![example calculator app made with cppui](readme_images/calculator.png)

## What is cppui?
cppui is a small project that can help developers to create simple and performant apps in C++, with a component-based React-like feel.

## Third-Party libraries used
- [SDL](https://www.libsdl.org/): the rendering backend cppui uses
- [SDL_ttf](https://github.com/libsdl-org/SDL_ttf): for font loading and text rendering
- [SDL_image](https://github.com/libsdl-org/SDL_image): for rendering image files

## Building cppui from source
cppui uses CMake, alongside a custom python build system to merge SDL static libraries to create a standalone library.

To build cppui, run: 
```bash
python build.py
```
alongside any other arguments you want to be forwarded to CMake. For example:
```bash
python build.py -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=...
```

You will need CMake, ninja or make, and SDL3, SDL3_image, and SDL3_ttf installed in a directory where CMake can find them.
