#pragma once
#include <Geode/Geode.hpp>
#include <Geode/binding/FMODAudioEngine.hpp>
#include "../funcs.hpp"
using namespace geode::prelude;

namespace rooms {

    class snoopland_stuff : public cocos2d::CCNode {
    public:
        cocos2d::CCLayer* parent = nullptr;

        // callback to play music
        void snoopdogg(CCObject*) {
            auto win = CCDirector::get()->getWinSize();
            if (parent) {
                FMODAudioEngine::sharedEngine()->playMusic("snoopdogg.mp3"_spr, true, 1.0f, 0);
            }
        }

        // callback to show alert
        void weed(CCObject*) {
            if (parent) {
                FLAlertLayer::create("no", "dont do drugs", "OK")->show();
            }
        }
    };

    inline cocos2d::CCMenu* thesnoopland(cocos2d::CCLayer* parent = nullptr) {
        auto win = CCDirector::get()->getWinSize();
        auto things = new snoopland_stuff();
        things->parent = parent;
        devlin::set_emotion(parent, "excited.gif"_spr, 3.0f, 0.3f, 0.2f);

        auto snoopdogg = CCMenuItemSpriteExtra::create(
            CCSprite::create("snoopdogg.png"_spr),
            nullptr,
            things,
            menu_selector(snoopland_stuff::snoopdogg)
        );
        snoopdogg->setPosition({win.width * 0.8f, win.height / 4.20f});
        snoopdogg->setID("snoopdogg"_spr);

        auto weedItem = CCMenuItemSpriteExtra::create(
            CCSprite::create("weed.jpg"_spr),
            nullptr,
            things,
            menu_selector(snoopland_stuff::weed)
        );
        weedItem->setPosition({win.width / 12.f, win.height / 2.f});
        weedItem->setID("weed"_spr);

        auto menu = CCMenu::create();
        menu->setPosition({0, 0});
        menu->addChild(snoopdogg);
        menu->addChild(weedItem);
        menu->setID("room-menu"_spr);
        return menu;
    }

}
