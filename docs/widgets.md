# Widgets

Widgets are the visible, interactive parts of the UI. They can be placed inside any [container](containers.md).
Widgets have their own factory functions, such as `Text()`, `Image()`, `Button()`, etc. They return pointers to a created component in memory.

## Text

```cpp
Text(std::string text, Font font, Color color)
```

Draws text. Multiple lines work with `\n`. You can load a font with:

```cpp
Font GetFont(std::string path, int fontSize)
```

You can change the text of a Text Component with `ChangeText(std::string newText)`. Example:

```cpp
auto greeting_text = Text("hello", GetFont("JetBrainsMono.ttf", 16), WHITE);

greeting_text->ChangeText("bye");
```

## Button

```cpp
Button(std::function<void()> on_click, Color color, std::vector<Component *> children)
```

A [Panel](containers.md#panel) with a click handler. When the left mouse button is pressed and the cursor is inside the button's last drawn rectangle, `on_click` runs during App's `update()`.

Example:

```cpp
Font font = GetFont("JetBrainsMono.ttf", 16);

App Application()
{
    return App({
        Button([] { debug("lambda clicked"); }, BLUE, {
            HorizontalContainer({
                Text("Click me!", font, WHITE),
                Image("cat.png", {24, 24}),
            }),
        }),
    });
}
```

## Image

```cpp
Image(std::string path, Vector2 size)
```

Loads an image file (PNG/JPG/...) and draws it stretched to `size`. If `size` is `{-1, -1}`, the image will be drawn at its native scale.

```cpp
Image("cat.png", {80, 80})
```