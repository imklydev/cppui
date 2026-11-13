#include "app.h"

App Application()
{
    debug("hello world!");

    return App({
        Text("hellooo world!", GetFont("JetBrainsMono.ttf", 16.0f), WHITE),
        Text("this is such a cool desktop app, isn't it?", GetFont("JetBrainsMono.ttf", 16.0f), WHITE),
        Text("WOAH BIG TEXT", GetFont("JetBrainsMono.ttf", 64.0f), WHITE),
        Panel(BLUE,
              {
                  Text("woahh background is blue now", GetFont("JetBrainsMono.ttf", 16.0f), BLACK),
                  Text("kinda cool if you ask me", GetFont("JetBrainsMono.ttf", 16.0f), WHITE),
              }),
    });
}