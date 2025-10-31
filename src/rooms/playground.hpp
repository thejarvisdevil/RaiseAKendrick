#pragma once
#include <Geode/Geode.hpp>
#include <Geode/binding/FMODAudioEngine.hpp>
#include "../funcs.hpp"
using namespace geode::prelude;

namespace rooms {
    class playground_stuff : public cocos2d::CCNode {
    public:
        cocos2d::CCLayer* parent = nullptr;
        void sixseven(CCObject*) {
            auto win = CCDirector::get()->getWinSize();
            if (parent) {
                FMODAudioEngine::sharedEngine()->playEffect("67.mp3"_spr);
            }
        }

        void touchgrass(CCObject*) {
            if (parent) {
                devlin::set_emotion(parent, "angry.gif"_spr, 3.0f, 0.3f, 0.2f);
                FMODAudioEngine::sharedEngine()->playEffect("pou_no.mp3"_spr);
            }
        }

        void trampoline(CCObject*) {
            if (parent) {
                FMODAudioEngine::sharedEngine()->playEffect("boing.mp3"_spr);
            }
        }

        void backflip(CCObject*) {
            if (parent) {
                FMODAudioEngine::sharedEngine()->playEffect("boing.mp3"_spr);
                if (auto kendrick = parent->getChildByID("character"_spr)) {
                    auto rotate = cocos2d::CCRotateBy::create(1.0f, 360.0f);
                    kendrick->runAction(rotate);
                }
            }
        }

        void dingle(CCObject*) {
            if (parent) {
                FMODAudioEngine::sharedEngine()->playEffect("dingle.mp3"_spr);
            }
        }
    };

    inline cocos2d::CCMenu* theplayground(cocos2d::CCLayer* parent = nullptr) {
        auto win = CCDirector::get()->getWinSize();
        auto things = new playground_stuff();
        things->parent = parent;
        devlin::set_emotion(parent, "excited.gif"_spr, 3.0f, 0.3f, 0.2f);

        auto kid = CCSprite::create("67.png"_spr);
        kid->setScale(2.0f);
        auto sixseven = CCMenuItemSpriteExtra::create(kid, nullptr, things, menu_selector(playground_stuff::sixseven));
        sixseven->setPosition({win.width * 0.7f, win.height / 3.0f});
        sixseven->setID("sixseven"_spr);

        auto grass = CCMenuItemSpriteExtra::create(CCSprite::create("touchgrass.png"_spr), nullptr, things, menu_selector(playground_stuff::touchgrass));
        grass->setPosition({win.width / 24.f, win.height / 5.f});
        grass->setID("grass"_spr);

        auto trampoline = CCMenuItemSpriteExtra::create(CCSprite::create("trampoline.png"_spr), nullptr, things, menu_selector(playground_stuff::trampoline));
        trampoline->setPosition({win.width * 0.85f, win.height / 3.0f});
        trampoline->setID("trampoline"_spr);

        auto backflip = CCMenuItemSpriteExtra::create(CCSprite::create("backflip.png"_spr), nullptr, things, menu_selector(playground_stuff::backflip));
        backflip->setPosition({win.width / 2.2f, win.height / 8.0f});
        backflip->setID("backflip"_spr);

        auto dngl = CCSprite::create("dingle.jpg"_spr);
        dngl->setFlipX(true);
        auto dingle = CCMenuItemSpriteExtra::create(dngl, nullptr, things, menu_selector(playground_stuff::dingle));
        dingle->setPosition({win.width / 24.f, win.height / 1.5f});
        dingle->setID("dingle"_spr);

        auto menu = CCMenu::create();
        menu->setPosition({0,0});
        menu->addChild(sixseven);
        menu->addChild(grass);
        menu->addChild(trampoline);
        menu->addChild(backflip);
        menu->addChild(dingle);
        menu->addChild(things);
        menu->setID("room-menu"_spr);
        return menu;
    }
}