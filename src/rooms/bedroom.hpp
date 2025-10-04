#pragma once
#include <Geode/Geode.hpp>
#include <Geode/binding/FMODAudioEngine.hpp>
#include "../funcs.hpp"
using namespace geode::prelude;

namespace rooms {
    class bedroom_stuff : public cocos2d::CCNode {
    public:
        cocos2d::CCLayer* parent = nullptr;
        void sleep(CCObject*) {
            if (parent) {
                devlin::set_emotion(parent, "angry.gif"_spr, 3.0f, 0.7f, 0.5f);
                FMODAudioEngine::sharedEngine()->playEffect("pou_no.mp3"_spr);
            }
        }

        void mirror(CCObject*) {
            if (parent) {
                devlin::set_emotion(parent, "taylor.png"_spr, 3.0f, 0.7f, 0.5f);
                FMODAudioEngine::sharedEngine()->playEffect("twinkle.mp3"_spr);
            }
        }

        void lightsOff(CCObject*) {
            if (parent) {
                auto bg = parent->getChildByID("roomBg"_spr);
                if (bg) {
                    bg->setVisible(false);
                }
                auto r = parent->getChildByID("room-menu"_spr);
                if (r) {
                    r->setVisible(false);
                }
                
                devlin::set_emotion(parent, "sad.gif"_spr, 3.0f, 0.7f, 0.5f);
                FMODAudioEngine::sharedEngine()->playMusic("fnaf.mp3"_spr, false, 1.0f, 0);
            }
        }
    };

    inline cocos2d::CCMenu* thebedroom(cocos2d::CCLayer* parent = nullptr) {
        auto win = CCDirector::get()->getWinSize();
        auto things = new bedroom_stuff();
        things->parent = parent;
        devlin::set_emotion(parent, "excited.gif"_spr, 3.0f, 0.7f, 0.5f);

        auto sleep = CCMenuItemSpriteExtra::create(CCSprite::create("sleep.png"_spr), nullptr, things, menu_selector(bedroom_stuff::sleep));
        sleep->setPosition({win.width - 260.f, win.height / 2.f});
        sleep->setID("sleep"_spr);

        auto mirror = CCMenuItemSpriteExtra::create(CCSprite::create("mirror.png"_spr), nullptr, things, menu_selector(bedroom_stuff::mirror));
        mirror->setPosition({win.width - 480.f, win.height / 2.f});
        mirror->setID("mirror"_spr);

        auto lights = CCMenuItemSpriteExtra::create(CCSprite::create("lights.png"_spr), nullptr, things, menu_selector(bedroom_stuff::lightsOff));
        lights->setPosition({win.width - 12.f, win.height / 2.f});
        lights->setID("lights"_spr);

        auto menu = CCMenu::create();
        menu->setPosition({0,0});
        menu->addChild(sleep);
        menu->addChild(mirror);
        menu->addChild(lights);
        menu->addChild(things);
        menu->setID("room-menu"_spr);
        return menu;
    }
}