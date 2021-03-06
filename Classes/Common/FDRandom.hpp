//
//  FDRandom.hpp
//  FlameDragonX
//
//  Created by SuiYi on 9/20/16.
//
//

#ifndef FDRandom_hpp
#define FDRandom_hpp

#include "cocos2d.h"
#include "FDRange.hpp"

class FDRandom : public cocos2d::Ref
{
public:
    
    static int valueFromRange(int min, int max);
    static int valueFromRange(FDRange * range);
    static bool hitWithRate(int rate);
    
};

#endif /* FDRandom_hpp */
