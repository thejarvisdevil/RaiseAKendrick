#pragma once
#include <Geode/Geode.hpp>
#include <Geode/binding/FMODAudioEngine.hpp>
#include "../funcs.hpp"
using namespace geode::prelude;

namespace rooms {
    class kitchen_stuff : public cocos2d::CCNode {
    public:
        cocos2d::CCLayer* parent = nullptr;
        void mango(CCObject*) {
            auto win = CCDirector::get()->getWinSize();
            if (parent) {
                devlin::set_emotion(parent, "food.webp"_spr, 3.0f, 0.3f, 0.2f);
                FMODAudioEngine::sharedEngine()->playEffect("airhorn.mp3"_spr);
            }
        }

        void brocco(CCObject*) {
            auto win = CCDirector::get()->getWinSize();
            if (parent) {
                devlin::set_emotion(parent, "disgust.webp"_spr, 3.0f, 0.3f, 0.2f);
                FMODAudioEngine::sharedEngine()->playEffect("disgusting.mp3"_spr);
            }
        }

        void knife(CCObject*) {
            auto win = CCDirector::get()->getWinSize();
            if (parent) {
                devlin::set_emotion(parent, "sad.webp"_spr, 3.0f, 0.3f, 0.2f);
                FMODAudioEngine::sharedEngine()->playEffect("marioscreaming.mp3"_spr);
                FLAlertLayer::create("No!", "<cr>pls no ok tank...</c>", "lol")->show();
            }
        }

        void mcdonalds(CCObject*) {
            auto win = CCDirector::get()->getWinSize();
            if (parent) {
                devlin::set_emotion(parent, "avocado.png"_spr, 3.0f, 0.3f, 0.2f);
                FMODAudioEngine::sharedEngine()->playEffect("avocado.mp3"_spr, 1.0f, 1.0f, 2.5f);
            }
        }
    };

    inline cocos2d::CCMenu* thekitchen(cocos2d::CCLayer* parent = nullptr) {
        auto win = CCDirector::get()->getWinSize();
        auto things = new kitchen_stuff();
        things->parent = parent;
        devlin::set_emotion(parent, "excited.webp"_spr, 3.0f, 0.3f, 0.2f);

        auto mango = CCMenuItemSpriteExtra::create(CCSprite::create("mango.png"_spr), nullptr, things, menu_selector(kitchen_stuff::mango));
        mango->setPosition({win.width * 0.7f, win.height / 2.2f});
        mango->setID("mango"_spr);

        auto brocco = CCMenuItemSpriteExtra::create(CCSprite::create("brocco.png"_spr), nullptr, things, menu_selector(kitchen_stuff::brocco));
        brocco->setPosition({win.width * 0.6f, win.height / 2.2f});
        brocco->setID("brocco"_spr);

        auto knife = CCMenuItemSpriteExtra::create(CCSprite::create("knife.png"_spr), nullptr, things, menu_selector(kitchen_stuff::knife));
        knife->setPosition({win.width * 0.5f, win.height / 2.2f});
        knife->setID("knife"_spr);

        auto mcdonalds = CCMenuItemSpriteExtra::create(CCSprite::create("mcdonalds.png"_spr), nullptr, things, menu_selector(kitchen_stuff::mcdonalds));
        mcdonalds->setPosition({30.f, win.height / 2.f});
        mcdonalds->setID("mcdonalds"_spr);

        auto menu = CCMenu::create();
        menu->setPosition({0,0});
        menu->addChild(mango);
        menu->addChild(brocco);
        menu->addChild(knife);
        menu->addChild(mcdonalds);
        menu->addChild(things);
        menu->setID("room-menu"_spr);
        return menu;
    }
}