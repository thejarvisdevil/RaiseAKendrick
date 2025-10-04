#pragma once
#include <Geode/Geode.hpp>
#include <Geode/binding/FMODAudioEngine.hpp>
#include "../funcs.hpp"
using namespace geode::prelude;

namespace rooms {
    class bathroom_stuff : public cocos2d::CCNode {
    public:
        cocos2d::CCLayer* parent = nullptr;
        void toilet(CCObject*) {
            if (parent) {
                devlin::set_emotion(parent, "wth.gif"_spr, 2.f, 0.3f, 0.2f);
                FMODAudioEngine::sharedEngine()->playEffect("fart.mp3"_spr);
            }
        }

        void shower(CCObject*) {
            if (parent) {
                devlin::set_emotion(parent, "angry.gif"_spr, 2.f, 0.3f, 0.2f);
                FMODAudioEngine::sharedEngine()->playEffect("pou_no.mp3"_spr);
            }
        }

        void mirror(CCObject*) {
            if (parent) {
                devlin::set_emotion(parent, "taylor.png"_spr, 2.f, 0.3f, 0.2f);
                FMODAudioEngine::sharedEngine()->playEffect("twinkle.mp3"_spr);
            }
        }
    };

    inline cocos2d::CCMenu* thebathroom(cocos2d::CCLayer* parent = nullptr) {
        auto win = CCDirector::get()->getWinSize();
        auto things = new bathroom_stuff();
        things->parent = parent;
        devlin::set_emotion(parent, "excited.gif"_spr, 2.f, 0.3f, 0.2f);

        auto toilet = CCMenuItemSpriteExtra::create(CCSprite::create("toilet.png"_spr), nullptr, things, menu_selector(bathroom_stuff::toilet));
        toilet->setPosition({win.width / 6.5f, win.height / 2.4f});
        toilet->setID("toilet"_spr);

        auto shower = CCMenuItemSpriteExtra::create(CCSprite::create("shower.png"_spr), nullptr, things, menu_selector(bathroom_stuff::shower));
        shower->setPosition({win.width - 150.f, 150.f});
        shower->setID("shower"_spr);

        auto mirror = CCMenuItemSpriteExtra::create(CCSprite::create("mirror.png"_spr), nullptr, things, menu_selector(bathroom_stuff::mirror));
        mirror->setPosition({win.width / 2.f - 60.f, win.height / 1.5f});
        mirror->setID("mirror"_spr);

        auto menu = CCMenu::create();
        menu->setPosition({0,0});
        menu->addChild(toilet);
        menu->addChild(shower);
        menu->addChild(mirror);
        menu->addChild(things);
        menu->setID("room-menu"_spr);
        return menu;
    }
}