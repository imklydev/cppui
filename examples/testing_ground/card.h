#include "app.h"

Component *Card()
{
    return Panel(CYAN, {
                           VerticalContainer({
                               Text("This is a card", GetFont("JetBrainsMono.ttf", 32), BLACK),
                               Text("Very cool card", GetFont("JetBrainsMono.ttf", 16), BLACK),
                           }),
                       });
}