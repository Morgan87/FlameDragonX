//
//  FDScreen.hpp
//  FlameDragonX
//
//  Created by SuiYi on 8/22/16.
//
//

#ifndef FDScreen_hpp
#define FDScreen_hpp


#include "cocos2d.h"

USING_NS_CC;

class FDScreen : public cocos2d::Ref
{
private:
    Layer *_layer;
    int _width;
    int _height;
    bool _keepSameScale;
    float _scaleX;
    float _scaleY;
    float _offsetX;
    float _offsetY;
    
    float _dpi;
    
public:
    
    FDScreen(Layer* layer, int width, int height, bool keepSameScale);
    
    void addChild(Node * node, int x, int y, int zOrder);
    void addChild(Node * node, int x, int y, int displayWidth, int displayHeight, int zOrder);

};

#endif /* FDScreen_hpp */
