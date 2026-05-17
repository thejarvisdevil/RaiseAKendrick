#pragma once
#include <Geode/Geode.hpp>
#include <Geode/binding/FMODAudioEngine.hpp>
#include "../funcs.hpp"
using namespace geode::prelude;

namespace rooms {
    class christmas_stuff : public cocos2d::CCNode {
    public:
        cocos2d::CCLayer* parent = nullptr;

        void sphere(CCObject*) {
            auto win = CCDirector::get()->getWinSize();
            FMODAudioEngine::sharedEngine()->playEffect("boing.mp3"_spr);

            if (parent) {
                for (int i = 0; i < 10; i++) {
                    auto ms = CCSprite::create("michealsphere.png"_spr);
                    ms->setID("holymoly"_spr);
                    ms->setZOrder(-9);
                    ms->setScale(0.01f);
                    ms->setPosition({win.width / 2, win.height / 2});
                    parent->addChild(ms);

                    auto resize = cocos2d::CCScaleTo::create(0.4f, 0.25f);
                    ms->runAction(resize);

                    auto moveIt = cocos2d::CCMoveTo::create(1.0f, {
                        static_cast<float>(rand() % static_cast<int>(win.width)),
                        static_cast<float>(rand() % static_cast<int>(win.height))
                    });
                    ms->runAction(moveIt);
                }
            }
        }
    };

    inline cocos2d::CCMenu* thechristmas(cocos2d::CCLayer* parent = nullptr) {
        auto win = CCDirector::get()->getWinSize();
        auto things = new christmas_stuff();
        things->parent = parent;
        devlin::set_emotion(parent, "excited.gif"_spr, 3.0f, 0.8f, 0.3f);

        auto ms = CCSprite::create("michealsphere.png"_spr);
        ms->setScale(0.4f);
        auto micheal = CCMenuItemSpriteExtra::create(ms, nullptr, things, menu_selector(christmas_stuff::sphere));
        micheal->setPosition({win.width / 5, win.height / 7});
        micheal->setID("micheal"_spr);

        auto menu = CCMenu::create();
        menu->setPosition({0,0});
        menu->addChild(micheal);
        menu->addChild(things);
        menu->setID("room-menu"_spr);
        return menu;
    }
}