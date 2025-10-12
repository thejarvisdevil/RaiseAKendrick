#pragma once
#include <Geode/Geode.hpp>
#include <Geode/binding/FMODAudioEngine.hpp>
#include "../funcs.hpp"
using namespace geode::prelude;

namespace rooms {
    class car_stuff : public cocos2d::CCNode {
    public:
        cocos2d::CCLayer* parent = nullptr;
        void wheel(CCObject*) {
            auto win = CCDirector::get()->getWinSize();
            if (parent) {
                FMODAudioEngine::sharedEngine()->playEffect("carcrash.mp3"_spr);
                devlin::set_emotion(parent, "food.gif"_spr, 3.0f, 0.8f, 0.3f);
                FLAlertLayer::create(
                    "Crash!",
                    "<cr>You ran over Drake.</c>",
                    "OK"
                )->show();
            }
        }
    };

    inline cocos2d::CCMenu* thecar(cocos2d::CCLayer* parent = nullptr) {
        auto win = CCDirector::get()->getWinSize();
        auto things = new car_stuff();
        things->parent = parent;
        devlin::set_emotion(parent, "excited.gif"_spr, 3.0f, 0.8f, 0.3f);

        auto wheel = CCMenuItemSpriteExtra::create(CCSprite::create("wheel.png"_spr), nullptr, things, menu_selector(car_stuff::wheel));
        wheel->setPosition({win.width * 0.8f, win.height / 4.20f});
        wheel->setID("wheel"_spr);

        auto menu = CCMenu::create();
        menu->setPosition({0,0});
        menu->addChild(wheel);
        menu->setID("room-menu"_spr);
        return menu;
    }
}