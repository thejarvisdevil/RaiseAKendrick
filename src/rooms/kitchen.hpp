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
                devlin::set_emotion(parent, "food.gif"_spr, 3.0f, 0.3f, 0.2f);
                FMODAudioEngine::sharedEngine()->playEffect("airhorn.mp3"_spr);
            }
        }

        void brocco(CCObject*) {
            auto win = CCDirector::get()->getWinSize();
            if (parent) {
                devlin::set_emotion(parent, "disgust.gif"_spr, 3.0f, 0.3f, 0.2f);
                FMODAudioEngine::sharedEngine()->playEffect("disgusting.mp3"_spr);
            }
        }

        void waterr(CCObject*) {
            auto win = CCDirector::get()->getWinSize();
            if (parent) {
                devlin::set_emotion(parent, "disgust.gif"_spr, 3.0f, 0.3f, 0.2f);
                FMODAudioEngine::sharedEngine()->playEffect("disgusting.mp3"_spr);
            }
        }

        void knife(CCObject*) {
            auto win = CCDirector::get()->getWinSize();
            if (parent) {
                devlin::set_emotion(parent, "sad.gif"_spr, 3.0f, 0.3f, 0.2f);
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

        void mustard(CCObject*) {
            auto win = CCDirector::get()->getWinSize();
            if (parent) {
                devlin::set_emotion(parent, "food.gif"_spr, 3.0f, 0.3f, 0.2f);
                FMODAudioEngine::sharedEngine()->playEffect("airhorn.mp3"_spr);
            }
        }

        void fridge(CCObject*) {
            auto win = CCDirector::get()->getWinSize();
            if (parent) {
                devlin::set_emotion(parent, "disgust.gif"_spr, 3.0f, 0.3f, 0.2f);
                FMODAudioEngine::sharedEngine()->playEffect("disgusting.mp3"_spr);
                FLAlertLayer::create("The Fridge", "You open the door and see a fridge full of <cr>rotting food, bugs, dead mice, spiders and every single horror you can imagine.</c> <co>It reminded you what happened back on July of 1999.</c>", "run")->show();
            }
        }

        void macncheese(CCObject*) {
            auto win = CCDirector::get()->getWinSize();
            if (parent) {
                if (auto macnchese = parent->getChildByID("macnchese"_spr)) { macnchese->removeFromParent(); }

                auto macnchese = CCSprite::create("macandcheese.jpg"_spr);
                macnchese->setID("macnchese"_spr);
                macnchese->setPosition({win.width / 2, win.height / 2});
                macnchese->setScale(0.0f);
                parent->addChild(macnchese, 4);
                macnchese->runAction(cocos2d::CCSequence::create(
                    cocos2d::CCScaleTo::create(0.5f, 1.0f),
                    cocos2d::CCDelayTime::create(2.0f),
                    cocos2d::CCFadeOut::create(1.0f),
                    nullptr
                ));

                FMODAudioEngine::sharedEngine()->playEffect("confetti.mp3"_spr);
            }
        }
    };

    inline cocos2d::CCMenu* thekitchen(cocos2d::CCLayer* parent = nullptr) {
        auto win = CCDirector::get()->getWinSize();
        auto things = new kitchen_stuff();
        things->parent = parent;
        devlin::set_emotion(parent, "excited.gif"_spr, 3.0f, 0.3f, 0.2f);

        auto mango = CCMenuItemSpriteExtra::create(CCSprite::create("mango.png"_spr), nullptr, things, menu_selector(kitchen_stuff::mango));
        mango->setPosition({win.width * 0.7f, win.height / 2.2f});
        mango->setID("mango"_spr);

        auto brocco = CCMenuItemSpriteExtra::create(CCSprite::create("brocco.png"_spr), nullptr, things, menu_selector(kitchen_stuff::brocco));
        brocco->setPosition({win.width * 0.6f, win.height / 2.2f});
        brocco->setID("brocco"_spr);

        auto knife = CCMenuItemSpriteExtra::create(CCSprite::create("knife.png"_spr), nullptr, things, menu_selector(kitchen_stuff::knife));
        knife->setPosition({win.width * 0.5f, win.height / 2.2f});
        knife->setID("knife"_spr);

        auto mustard = CCMenuItemSpriteExtra::create(CCSprite::create("mustard.png"_spr), nullptr, things, menu_selector(kitchen_stuff::mustard));
        mustard->setPosition({win.width * 0.4f, win.height / 2.2f});
        mustard->setID("mustard"_spr);

        auto mcdonalds = CCMenuItemSpriteExtra::create(CCSprite::create("mcdonalds.png"_spr), nullptr, things, menu_selector(kitchen_stuff::mcdonalds));
        mcdonalds->setPosition({30.f, win.height / 2.f});
        mcdonalds->setID("mcdonalds"_spr);

        auto fridge = CCMenuItemSpriteExtra::create(CCSprite::create("fridge.png"_spr), nullptr, things, menu_selector(kitchen_stuff::fridge));
        fridge->setPosition({win.width / 1.15f, win.height / 2.f});
        fridge->setID("fridge"_spr);

        auto macncheese = CCMenuItemSpriteExtra::create(CCSprite::create("mac.png"_spr), nullptr, things, menu_selector(kitchen_stuff::macncheese));
        macncheese->setPosition({win.width * 0.7f, win.height / 2.2f - 60.f});
        macncheese->setID("macncheese"_spr);

        auto waterr = CCMenuItemSpriteExtra::create(CCSprite::create("water.png"_spr), nullptr, things, menu_selector(kitchen_stuff::waterr));
        waterr->setPosition({win.width * 0.5f, win.height / 2.2f - 60.f});
        waterr->setID("waterr"_spr);

        auto menu = CCMenu::create();
        menu->setPosition({0,0});
        menu->addChild(mango);
        menu->addChild(brocco);
        menu->addChild(knife);
        menu->addChild(mcdonalds);
        menu->addChild(mustard);
        menu->addChild(fridge);
        menu->addChild(macncheese);
        menu->addChild(waterr);
        menu->addChild(things);
        menu->setID("room-menu"_spr);
        return menu;
    }
}