//
//  AnimationLibrary.cpp
//  FlameDragonX
//
//  Created by SuiYi on 8/25/16.
//
//

#include "AnimationLibrary.hpp"
#include "Constants.hpp"

AnimationLibrary * AnimationLibrary::_instance = nullptr;

AnimationLibrary * AnimationLibrary::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new AnimationLibrary();
    }
    
    return _instance;
}

AnimationLibrary::AnimationLibrary()
{
    _slideAnimationDictionary = new Map<std::string, SlideAnimation*>();
    
}

AnimationLibrary::~AnimationLibrary()
{
    _slideAnimationDictionary->clear();
    delete _slideAnimationDictionary;
}

void AnimationLibrary::preloadBattleAnimationsForCreature(int creatureAniId)
{
    this->loadIdleAnimation(creatureAniId);
    
    // Load Walk Animation
    this->loadWalkAnimation(creatureAniId, DirectionLeft);
    this->loadWalkAnimation(creatureAniId, DirectionUp);
    this->loadWalkAnimation(creatureAniId, DirectionRight);
    this->loadWalkAnimation(creatureAniId, DirectionDown);
}

void AnimationLibrary::loadIdleAnimation(int creatureAniId)
{
    // Load Idle Animation
    SlideAnimation *idleAnimation = new SlideAnimation(Constants::TickPerFrame_IdleAnimation, true, true);
    idleAnimation->appendFrame(filenameForBattleFieldAnimation(creatureAniId, 1));
    idleAnimation->appendFrame(filenameForBattleFieldAnimation(creatureAniId, 2));
    idleAnimation->appendFrame(filenameForBattleFieldAnimation(creatureAniId, 3));
    idleAnimation->appendFrame(filenameForBattleFieldAnimation(creatureAniId, 2));
    
    std::string key = StringUtils::format("Idle-%03d", creatureAniId);
    _slideAnimationDictionary->insert(key, idleAnimation);
    idleAnimation->release();
}

void AnimationLibrary::loadWalkAnimation(int creatureAniId, Direction direction)
{
    int centerImageId;
    switch (direction) {
        case DirectionLeft:
            centerImageId = 5;
            break;
        case DirectionUp:
            centerImageId = 8;
            break;
        case DirectionRight:
            centerImageId = 11;
            break;
        case DirectionDown:
            centerImageId = 2;
            break;
            
        default:
            break;
    }
    
    SlideAnimation *walkAnimation = new SlideAnimation(Constants::TickPerFrame_MoveAnimation, true, true);
    walkAnimation->appendFrame(filenameForBattleFieldAnimation(creatureAniId, centerImageId - 1));
    walkAnimation->appendFrame(filenameForBattleFieldAnimation(creatureAniId, centerImageId));
    walkAnimation->appendFrame(filenameForBattleFieldAnimation(creatureAniId, centerImageId + 1));
    walkAnimation->appendFrame(filenameForBattleFieldAnimation(creatureAniId, centerImageId));
    std::string key = StringUtils::format("Walk-%02d-%03d", direction, creatureAniId);
    _slideAnimationDictionary->insert(key, walkAnimation);
    walkAnimation->release();
}

void AnimationLibrary::loadScopeIndicatorAnimation()
{
    std::string key = "ScopeIndicator";
    
    SlideAnimation *animation = new SlideAnimation(Constants::TickPerFrame_IdleAnimation, true, true);
    std::string filename = "Others/WhiteBlock.png";
    
    FDFrame *frame = new FDFrame(filename, 40);
    animation->appendFrame(frame);
    frame->release();
}

SlideAnimation * AnimationLibrary::getIdleAnimation(int creatureAniId)
{
    std::string key = StringUtils::format("Idle-%03d", creatureAniId);
    
    if (_slideAnimationDictionary->at(key) == nullptr)
    {
        this->loadIdleAnimation(creatureAniId);
    }
    
    return _slideAnimationDictionary->at(key);
}

SlideAnimation * AnimationLibrary::getWalkAnimation(int creatureAniId, Direction direction)
{
    std::string key = StringUtils::format("Walk-%02d-%03d", direction, creatureAniId);
    
    if (_slideAnimationDictionary->at(key) == nullptr)
    {
        this->loadWalkAnimation(creatureAniId, direction);
    }

    return _slideAnimationDictionary->at(key);
}

SlideAnimation * AnimationLibrary::getScopeIndicatorAnimation()
{
    std::string key = "ScopeIndicator";
    if (_slideAnimationDictionary->at(key) == nullptr)
    {
        this->loadScopeIndicatorAnimation();
    }
    
    return _slideAnimationDictionary->at(key);
}


std::string AnimationLibrary::filenameForBattleFieldAnimation(int creatureAniId, int index)
{
    return StringUtils::format("Icons/%03d/Icon-%03d-%02d.png", creatureAniId, creatureAniId, index);
}