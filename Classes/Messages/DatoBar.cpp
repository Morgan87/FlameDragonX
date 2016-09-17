//
//  DatoBar.cpp
//  FlameDragonX
//
//  Created by SuiYi on 9/13/16.
//
//

#include "DatoBar.hpp"

DatoBar::DatoBar(int creatureAniId)
{
    _baseSprite = Sprite::create("Others/CreatureDato.png");
    
    Sprite * dato = Sprite::create(StringUtils::format("Dato/Dato-%03d-1.png", creatureAniId));
    dato->setAnchorPoint(Vec2(0, 0));
    dato->setPosition(Vec2(1.5f, 1.5f));
    _baseSprite->addChild(dato);
}

Sprite * DatoBar::getSprite()
{
    return _baseSprite;
}
