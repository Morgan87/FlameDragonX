//
//  SystemMenuState.hpp
//  FlameDragonX
//
//  Created by SuiYi on 9/4/16.
//
//

#ifndef SystemMenuState_hpp
#define SystemMenuState_hpp

#include "cocos2d.h"
#include "ActionState.hpp"
class BattleScene;

class SystemMenuState : public ActionState
{
private:
    
    
public:
    
    static SystemMenuState * create(BattleScene * scene, StateSession * session);
    
    void onEnterState();
    void onExitState();
    
    virtual void handleClickAt(Vec2 position) override;
    
};

#endif /* SystemMenuState_hpp */
