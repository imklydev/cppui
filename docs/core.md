# Core

## App

```cpp
App(std::vector<Component *> children)
```

The root component. It is a `VerticalContainerComponent`, so its children are stacked from top to bottom starting at `{0, 0}`.

You define `App Application()` in your own source file. cppui calls it once at startup and stores the result in the global `app` object. Every frame, `app.update()` runs before `app.draw({0, 0})`.

```cpp
App Application()
{
    return App({
        Text("Hello", font, WHITE),
        Image("cat.png", {80, 80}),
    });
}
```

## Component

```cpp
Component(std::vector<Component *> children = {})
```

The base class of every component. You normally create components with their factory functions instead of instantiating it directly.

Public members:

```cpp
std::string id;                      // set with setID(), searched with GetChild()
std::vector<Component *> children;   // direct children
Vector2 size;                        // measured during the last draw(), in pixels
```

Methods:

```cpp
Component *setID(std::string id)
Component *resize(Vector2 size)
Component *GetChild(int index)
Component *GetChild(std::string id, bool recursive = false)
void AddChild(Component *child)
virtual void ChangeText(std::string text)
```

`setID()` sets an ID for a component, that can later be searched for using `GetChild(std::string id)`

`resize()` sets a new size for the component. See [sizing](#sizing) for more.


### Finding components

`GetChild(int)` returns a direct child by index.

`GetChild(std::string id, bool recursive = false)` returns the first child with that ID, and with `recursive = true` it searches all descendants.

```cpp
Font font = GetFont("JetBrainsMono.ttf", 16.0f);
int presses = 0;

void pressed()
{
    presses++;
    Component *label = app.GetChild("counter", true);
    label->ChangeText("Pressed " + std::to_string(presses) + " times");
}

App Application()
{
    return App({
        Button(pressed, WHITE, {
            Text("Press me", font, BLACK)->setID("counter"),
        }),
    });
}
```

`GetChild()` logs an error and exits the app when no child is found / the index is out of bounds.

### Adding children at runtime

```cpp
void add_component()
{
    app.AddChild(Text("Another line", font, WHITE));
    app.GetChild(0)->AddChild(Text("Nested line", font, WHITE));
}

App Application()
{
    return App({
        Button(add_component, BLUE, {
            Text("Add", font, WHITE)
        }),
    });
}
```

`AddChild()` queues the insertion. The child is added at the end of the next `update()` and appears on the following frame.

## Sizing

Containers normally derive their size from their children. You can change that with `resize()`

```cpp
CenteredVerticalContainer({
    Text("Centered horizontally", font, WHITE),
})->resize({WINDOW_WIDTH, NO_CHANGE});

Panel({
    Text("This is a big panel", font, WHITE),
})->resize({500, 500});
```

- `NO_CHANGE` keeps the size the layout calculated for that axis
- `WINDOW_WIDTH` uses the window width (updated on resize)
- `WINDOW_HEIGHT` uses the window height (updated on resize)


## Color

cppui provides some common colors: `WHITE`, `BLACK`, `RED`, `GREEN`, `BLUE`, `YELLOW`, `CYAN`, `MAGENTA`, `ORANGE`, `PURPLE`, `PINK`. 

You can also write a color literal:
```cpp
Color {31, 78, 92, 255}
```

## Font

```cpp
Font GetFont(std::string path, float font_size);
```

Loads a font file through SDL_ttf, initializing it if needed. Load fonts once at global scope, as in the examples, and reuse the handle.

## Logging

```cpp
debug("message");
error("message");
```

`debug` prints to the console.
`error` prints to the console (in scary red and underlined text) and quits the app.