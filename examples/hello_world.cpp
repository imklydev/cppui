#include "app.h"

App Application()
{
    debug("hello world!");

    Font font16 = GetFont("JetBrainsMono.ttf", 16.0f);
    Font font64 = GetFont("JetBrainsMono.ttf", 64.0f);

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
    });
}