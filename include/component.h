#include <vector>
#include "misc.h"

// The base Component class
class Component;

class Component
{
public:
    std::vector<Component> children;

    virtual void update() {};
    virtual void draw()
    {
        for (Component child : children)
        {
            child.draw();
        }
    };

};