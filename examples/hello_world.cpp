#include "app.h"

Font font16 = GetFont("JetBrainsMono.ttf", 16.0f);
Font font64 = GetFont("JetBrainsMono.ttf", 64.0f);

void button_pressed()
{
    app.AddChild(Text("Hello!", font16, WHITE));

    app.GetChild(5)->AddChild(Text(" new text! ", font16, WHITE));
}

void bad_button_pressed()
{
    // GetChild() out of bounds
    app.GetChild(245)->AddChild(Text(" new text! ", font16, WHITE));
}

App Application()
{
    debug("hello world!");

    return App({
        Text("hellooo world!", font16, WHITE),
        Text("this is such a cool desktop app, isn't it?", font16, WHITE),
        Text("WOAH BIG TEXT", font64, WHITE),
        Panel(BLUE,
              {
                  Text("woahh background is blue now", font16, BLACK),
                  Text("kinda cool if you ask me", font16, WHITE),
              }),
        VerticalContainer({
            Text("red", font16, RED),
            Text("red", font16, RED),
            Text("red", font16, RED),
        }),
        HorizontalContainer({
            Text("green ", font16, GREEN),
            Text("blue ", font16, BLUE),
            Text("pink", font16, PINK),
        }),
        Button(button_pressed, BLUE,
               {
                   Text("click mee!", font16, WHITE),
               }),
        Button(bad_button_pressed, RED,
               {
                   Text("DON'T click me!", font16, WHITE),
               }),
        Image("cat.png", {200, 200}),
    });
}