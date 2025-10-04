#pragma once
#include <Geode/Geode.hpp>
#include <Geode/binding/FMODAudioEngine.hpp>
#include "../funcs.hpp"
using namespace geode::prelude;

namespace rooms {
    class livingroom_stuff : public cocos2d::CCNode {
    public:
        cocos2d::CCLayer* parent = nullptr;
        void tv(CCObject*) {
            if (parent) {
                FMODAudioEngine::sharedEngine()->stopAllMusic(true);
                devlin::set_emotion(parent, "sad.gif"_spr, 3.0f, 0.5f, 0.5f);
                FMODAudioEngine::sharedEngine()->playEffect("tungtungtungsahurbeatupman.mp3"_spr);
            }
        }
    };

    inline cocos2d::CCMenu* thelivingroom(cocos2d::CCLayer* parent = nullptr) {
        auto win = CCDirector::get()->getWinSize();
        auto things = new livingroom_stuff();
        things->parent = parent;

        auto tvscreen = CCSprite::create("breaking_news.png"_spr);
        tvscreen->setScale(0.15f);
        tvscreen->setScaleX(0.15f * 1.2f);
        tvscreen->setScaleY(0.15f * 1.1f);
        auto tele = CCMenuItemSpriteExtra::create(tvscreen, nullptr, things, menu_selector(livingroom_stuff::tv));
        tele->setPosition({win.width / 6.5f, win.height / 2.4f});
        tele->setID("tv"_spr);

        auto menu = CCMenu::create();
        menu->setPosition({0,0});
        menu->addChild(tele);
        menu->addChild(things);
        menu->setID("room-menu"_spr);
        return menu;
    }
}