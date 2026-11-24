# Containers

Containers lay out and position their children.

## VerticalContainer

```cpp
VerticalContainer(std::vector<Component *> children)
```

Draws children one below another. Width is the widest child, height is the sum of the children's heights.

## HorizontalContainer

```cpp
HorizontalContainer(std::vector<Component *> children)
```

Draws children left to right. Width is the sum of the children's widths, height is the tallest child.

## CenteredContainer

```cpp
CenteredContainer(std::vector<Component *> children)
```

Stacks children vertically and centers them in both directions. Pin the size with `resize()` to center a group in the window, otherwise the container is only as large as its children and there is nothing to center into.

```cpp
CenteredContainer({
    Text("A centered card", font, WHITE),
    Button(click, WHITE, {Text("OK", font, BLACK)}),
})->resize({WINDOW_WIDTH, WINDOW_HEIGHT});
```

## CenteredVerticalContainer

```cpp
CenteredVerticalContainer(std::vector<Component *> children)
```

Stacks children vertically and centers each one horizontally. Use `WINDOW_WIDTH` to center a column on screen.

```cpp
CenteredVerticalContainer({
    Text("Centered heading", font, WHITE),
    Text("Centered subtitle", font, WHITE),
})->resize({WINDOW_WIDTH, NO_CHANGE});
```

## CenteredHorizontalContainer

```cpp
CenteredHorizontalContainer(std::vector<Component *> children)
```

Places children in a row and centers each one vertically. Use `WINDOW_WIDTH` to center a row on screen.

```cpp
CenteredHorizontalContainer({
    Text("Text on the left ", font, WHITE),
    Image("cat.png", {75, 75}),
    Text(" and on the right", font, WHITE),
})->resize({WINDOW_WIDTH, NO_CHANGE});
```

## MarginContainer

```cpp
MarginContainer(int margin, std::vector<Component *> children)
```

A `VerticalContainer` with `margin` pixels of padding on every side.

```cpp
MarginContainer(10, {
    Button(save, GREEN, {Text("Save", font, BLACK)}),
});
```

## ScrollContainer

```cpp
ScrollContainer(std::vector<Component *> children)
```

A `VerticalContainer` that moves with the mouse wheel. Scroll is clamped between the top and bottom of the content.

## Panel

```cpp
Panel(Color color, std::vector<Component *> children)
```

A `VerticalContainer` that fills its area with a solid color before drawing its children.
