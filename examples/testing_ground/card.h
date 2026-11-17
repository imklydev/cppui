#include "app.h"

class CardComponent : public CustomComponent
{
public:
    Component *body() override
    {
        return Panel(CYAN, {VerticalContainer({
                               Text("This is a card", GetFont("JetBrainsMono.ttf", 32), BLACK),
                               Text("Very cool card", GetFont("JetBrainsMono.ttf", 16), BLACK),
                           })});
    }
};

inline CardComponent *Card()
{
    return new CardComponent();
}