# cppui documentation

A cppui app is a tree of components. You describe the tree in the `Application()` function, and cppui lays it out and draws it every frame.

## Contents

- [Core](core.md): `App`, `Component`, sizing, colors, fonts, logging
- [Containers](containers.md): `VerticalContainer`, `HorizontalContainer`, `CenteredContainer`, `CenteredVerticalContainer`, `CenteredHorizontalContainer`, `MarginContainer`, `ScrollContainer`, `Panel`
- [Widgets](widgets.md): `Text`, `Button`, `Image`

## Minimal app

```cpp
#include "app.h"

Font font = GetFont("JetBrainsMono.ttf", 16.0f);

void click()
{
    app.GetChild("label", true)->ChangeText("Clicked!");
}

App Application()
{
    return App({
        VerticalContainer({
            Text("Hello!", font, WHITE)->setID("label"),
            Button(click, WHITE, {Text("Click me", font, BLACK)}),
        }),
    });
}
```

This builds the following tree:

```
App
└── VerticalContainer
    ├── Text          [id: label]
    └── Button
        └── Text
```
