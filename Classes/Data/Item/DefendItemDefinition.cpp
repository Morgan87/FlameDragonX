//
//  DefendItemDefinition.cpp
//  FlameDragonX
//
//  Created by SuiYi on 8/30/16.
//
//

#include "DefendItemDefinition.hpp"

DefendItemDefinition * DefendItemDefinition::readFromFile(TextFileReader * reader)
{
    DefendItemDefinition * def = new DefendItemDefinition();
    
    def->initFromFile(reader);
    def->autorelease();
    return def;
}

void DefendItemDefinition::initFromFile(TextFileReader * reader)
{
    _definitionId = reader->readInt();
    _itemCategory = reader->readInt();
    
    _price = reader->readInt();
    _sellprice = reader->readInt();
    
    _dp = reader->readInt();
    _ev = reader->readInt();
    
}