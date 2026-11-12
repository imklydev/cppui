#include "app.h"
#include "log.h"

App Application()
{
    debug("hello world!");

    return App({
        Text("hellooo", GetFont("JetBrainsMono.ttf", 16.0f), WHITE),
        Text("                    another text here!", GetFont("JetBrainsMono.ttf", 16.0f), WHITE),
    });
}