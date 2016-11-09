//
//  ChapterRecord.cpp
//  FlameDragonX
//
//  Created by SuiYi on 8/23/16.
//
//

#include "ChapterRecord.hpp"
#include "Creature.hpp"

ChapterRecord::ChapterRecord(int chapterId)
{
    this->_chapterId = chapterId;
}

ChapterRecord * ChapterRecord::createSample()
{
    ChapterRecord * record = new ChapterRecord(2);
    record->setMoney(500);
    
    for (int i = 1; i < 11; i++) {
        record->addCreatureRecord(createSampleCreatureRecord(i));
    }
    
    return record;
}

ChapterRecord * ChapterRecord::newGame()
{
    ChapterRecord * record = new ChapterRecord(1);
    record->setMoney(0);
    return record;
}

CreatureRecord * ChapterRecord::createSampleCreatureRecord(int definitionId)
{
    Creature * c = new Creature(CreatureType_Friend);
    c->initWithDefinition(definitionId, definitionId);
    
    CreatureRecord * record = new CreatureRecord(c);
    c->autorelease();
    record->autorelease();
    return record;
}
                                                 
int ChapterRecord::getChapterId()
{
    return _chapterId;
}

void ChapterRecord::setMoney(int money)
{
    _money = money;
}

int ChapterRecord::getMoney()
{
    return _money;
}

void ChapterRecord::addCreatureRecord(CreatureRecord * record)
{
    _friendRecordList.pushBack(record);
}

Vector<CreatureRecord *> &ChapterRecord::getFriendRecordList()
{
    return _friendRecordList;
}

CreatureRecord * ChapterRecord::getCreatureCarriesItem(int itemId)
{
    for (CreatureRecord * creature : _friendRecordList) {
        // Find the item
    }
    
    return nullptr;
}
