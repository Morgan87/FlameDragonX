//
//  ChapterRecord.cpp
//  FlameDragonX
//
//  Created by SuiYi on 8/23/16.
//
//

#include "ChapterRecord.hpp"

ChapterRecord::ChapterRecord(int chapterId)
{
    this->_chapterId = chapterId;
}

ChapterRecord * ChapterRecord::createSample()
{
    ChapterRecord * record = new ChapterRecord(2);
    record->setMoney(500);
    record->getFriendRecordList().pushBack(new CreatureRecord());
    
    return record;
}

ChapterRecord * ChapterRecord::newGame()
{
    ChapterRecord * record = new ChapterRecord(1);
    record->setMoney(0);
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

Vector<CreatureRecord *> ChapterRecord::getFriendRecordList()
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
