//
//  StateSession.cpp
//  FlameDragonX
//
//  Created by SuiYi on 9/4/16.
//
//

#include "StateSession.hpp"

StateSession * StateSession::newSession()
{
    StateSession * sess = new StateSession();
    
    sess->autorelease();
    return sess;
}
StateSession::StateSession()
{
    _selectedCreatureId = -1;
    _selectedItemIndex = -1;
    _selectedMagicIndex = -1;
    _lastPosition = Vec2(0, 0);
    _scopeResolver = nullptr;
}

StateSession::~StateSession()
{
    if (_scopeResolver != nullptr)
    {
        _scopeResolver->release();
    }
}

void StateSession::setSelectedCreatureId(int val)
{
    _selectedCreatureId = val;
}

void StateSession::setSelectedItemIndex(int val)
{
    _selectedItemIndex = val;
}

void StateSession::setSelectedMagicIndex(int val)
{
    _selectedMagicIndex = val;
}

void StateSession::setLastPosition(Vec2 position)
{
    _lastPosition = position;
}

void StateSession::setMoveScopeResolver(MoveScopeResolver * resolver)
{
    _scopeResolver = resolver;
    _scopeResolver->retain();
}

int StateSession::selectedCreatureId()
{
    return _selectedCreatureId;
}

int StateSession::selectedItemIndex()
{
    return _selectedItemIndex;
}

int StateSession::selectedMagicIndex()
{
    return _selectedMagicIndex;
}

Vec2 StateSession::lastPosition()
{
    return _lastPosition;
}


MoveScopeResolver * StateSession::getMoveScopeResolver()
{
    return _scopeResolver;
}