#include "createObject.h"

Object * createObject(object_id id, int x, int y, sf::Texture const * texture)
{
    //TODO
    Object * ret = nullptr;
    switch(id)
    {
        case OBJECT_BED:
            ret = new Bed(x, y, texture);
            break;
        case OBJECT_SOFA:
            ret = new Sofa(x, y, texture);
            break;
        case OBJECT_TOILET:
            ret = new Toilet(x, y, texture);
            break;
        case OBJECT_TABLE:
            break;
        case OBJECT_OVEN:
            break;
        case OBJECT_FRIDGE:
            break;
        default:
            break;
    }
    return ret;
}
