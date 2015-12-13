#pragma once

#include "Object.h"
#include "Lit.h"
#include "Canape.h"

typedef enum : unsigned char{
    OBJECT_BED = 'a',
    OBJECT_SOFA = 'b',
    OBJECT_TOILET = 'c',
    OBJECT_TABLE = 'd',
    OBJECT_OVEN = 'e',
    OBJECT_FRIDGE = 'f'
} object_id;

Object * createObject(object_id id, int x, int y, sf::Texture const * texture);
