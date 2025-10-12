#pragma once
#include <Geode/Geode.hpp>
#include <Geode/binding/FMODAudioEngine.hpp>
#include "../funcs.hpp"
using namespace geode::prelude;

namespace rooms {
    class mcdonalds_stuff : public cocos2d::CCNode {
    public:
        cocos2d::CCLayer* parent = nullptr;
        void cheeseburger(CCObject*) {
            auto win = CCDirector::get()->getWinSize();
            if (parent) {
                FMODAudioEngine::sharedEngine()->playMusic("romance.mp3"_spr, true, 1.0f, 0);
                devlin::set_emotion(parent, "happy.gif"_spr, 3.0f, 0.75f, 0.2f);
            }
        }

        void ronald(CCObject*) {
            auto win = CCDirector::get()->getWinSize();
            if (parent) {
                FMODAudioEngine::sharedEngine()->playEffect("ronald.mp3"_spr);
            }
        }
    };

    inline cocos2d::CCMenu* themcdonalds(cocos2d::CCLayer* parent = nullptr) {
        auto win = CCDirector::get()->getWinSize();
        auto things = new mcdonalds_stuff();
        things->parent = parent;
        devlin::set_emotion(parent, "food.gif"_spr, 3.0f, 0.75f, 0.2f);

        auto cheeseburger = CCMenuItemSpriteExtra::create(CCSprite::create("cheeseburger.png"_spr), nullptr, things, menu_selector(mcdonalds_stuff::cheeseburger));
        cheeseburger->setPosition({win.width / 2.f + 25.f, win.height / 4.f});
        cheeseburger->setID("cheeseburger"_spr);

        auto ron = CCSprite::create("ronald.png"_spr);
        ron->setScale(2.0f);
        auto ronald = CCMenuItemSpriteExtra::create(ron, nullptr, things, menu_selector(mcdonalds_stuff::ronald));
        ronald->setPosition({win.width * 0.33f, win.height / 6.f});
        ronald->setID("ronald"_spr);

        auto menu = CCMenu::create();
        menu->setPosition({0,0});
        menu->addChild(cheeseburger);
        menu->addChild(ronald);
        menu->setID("room-menu"_spr);
        return menu;
    }
}