#pragma once
#include <Geode/Geode.hpp>
#include <algorithm>
#include <Geode/binding/FMODAudioEngine.hpp>
#include "../funcs.hpp"
using namespace geode::prelude;

namespace rooms {
    class outside_stuff : public cocos2d::CCNode {
    public:
        cocos2d::CCLayer* parent = nullptr;
        CCMenuItemSpriteExtra* sigmaballer = nullptr;

        void explosion(CCObject*) {
            if (parent) {
                devlin::set_emotion(parent, "sad.webp"_spr, 3.0f, 0.5f, 0.5f);
                auto win = CCDirector::get()->getWinSize();

                if (auto haha1 = parent->getChildByID("nuke"_spr)) { haha1->removeFromParent(); }
                if (auto haha2 = parent->getChildByID("ashbaby"_spr)) { haha2->removeFromParent(); }

                auto nuke = CCSprite::create("nuke.png"_spr);
                nuke->setID("nuke"_spr);
                nuke->setPosition({win.width / 2, win.height / 2});
                nuke->setScale(0.0f);
                parent->addChild(nuke);
                nuke->runAction(cocos2d::CCSequence::create(
                    cocos2d::CCDelayTime::create(0.5f),
                    cocos2d::CCScaleTo::create(0.5f, 10.0f),
                    cocos2d::CCDelayTime::create(0.5f),
                    nullptr
                ));
                auto ash = CCSprite::create("ashbaby.png"_spr);
                ash->setID("ashbaby"_spr);
                ash->setPosition({win.width / 2, win.height / 2});
                ash->setOpacity(0);
                parent->addChild(ash, -4);
                ash->runAction(cocos2d::CCSequence::create(
                    cocos2d::CCDelayTime::create(1.0f),
                    cocos2d::CCFadeIn::create(0.5f),
                    nullptr
                ));
                nuke->runAction(cocos2d::CCSequence::create(
                    cocos2d::CCDelayTime::create(1.0f),
                    cocos2d::CCFadeOut::create(1.0f),
                    nullptr
                ));
                FMODAudioEngine::sharedEngine()->playEffect("ashbaby.mp3"_spr);
            }
        }

        void balling(CCObject* sender) {
            CCMenuItemSpriteExtra* balls = this->sigmaballer;
            if (!balls && sender) balls = static_cast<CCMenuItemSpriteExtra*>(sender);
            if (!balls) return;

            auto win = CCDirector::get()->getWinSize();
            auto sprite = static_cast<CCSprite*>(balls->getNormalImage());
            float halfW = sprite->getContentSize().width * sprite->getScale() * 0.5f;
            float halfH = sprite->getContentSize().height * sprite->getScale() * 0.5f;

            float x = static_cast<float>(rand()) / RAND_MAX * (win.width - 5 * halfW) + halfW;
            float y = static_cast<float>(rand()) / RAND_MAX * (win.height - 5 * halfH) + halfH;

            cocos2d::CCAction* act = cocos2d::CCMoveTo::create(1.f, CCPoint(x, y));
            balls->runAction(act);
            FMODAudioEngine::sharedEngine()->playEffect("boing.mp3"_spr);
        }

        void touchgrass(CCObject*) {
            if (parent) {
                devlin::set_emotion(parent, "angry.webp"_spr, 2.f, 0.3f, 0.2f);
                FMODAudioEngine::sharedEngine()->playEffect("pou_no.mp3"_spr);
            }
        }

        void jojo(CCObject*) {
            if (parent) {
                std::vector<std::string> messages = {
                    "I need you to rob a bank for me and buy me a new car. I NEED THAT LAMBORGHINI.",
                    "I need you to steal a new iPhone for me. I was on that TikTok grind and I dropped my phone into a woodchipper.",
                    "I need you to get me a new dog. My dog ran after the 22 unsupervised children at the park and never came back.",
                    "I need you to get me free robux. I want Dominus....",
                    "I need you to get me a new laptop. I was hacked by Anonymous and they took all my fortnite skins.",
                    "I need you to get me an Ice Age DVD from Blockbuster. It was so good!",
                    "I need you to kidnap the Nickelodeon CEO, they bein so MEAN!!!",
                    "I need you to steal me 10000000 bow ties...",
                    "I need you to steal me a new Expensive Outfit.. They will LOOK SO GOOD for my next Music Video!",
                    "I need you to kidnap jarvisdevil, he is being very mean to me on twitter.",
                    "I am Jojo."
                };
                std::string message = messages[rand() % messages.size()];
                FLAlertLayer::create("Jojo Siwa", "<cd>Jojo has a bizarre adventure for you:</c>\n\n" + message, "OK")->show();
            }
        }
    };

    inline cocos2d::CCMenu* theoutside(cocos2d::CCLayer* parent = nullptr) {
        auto win = CCDirector::get()->getWinSize();
        auto things = new outside_stuff();
        things->parent = parent;

        auto nuke = CCMenuItemSpriteExtra::create(CCSprite::create("bomb.png"_spr), nullptr, things, menu_selector(outside_stuff::explosion));
        nuke->setPosition({win.width / 4.f, win.height / 2.f});
        nuke->setID("NUKEEE"_spr);

        cocos2d::CCPoint startPos = {win.width / 3.f, win.height / 4.f};
        auto sprite = CCSprite::create("ball.png"_spr);
        sprite->setID("ball"_spr);

        auto ball = CCMenuItemSpriteExtra::create(sprite, nullptr, things, menu_selector(outside_stuff::balling));
        ball->setPosition(startPos);
        things->sigmaballer = ball;

        auto grass = CCMenuItemSpriteExtra::create(CCSprite::create("touchgrass.png"_spr), nullptr, things, menu_selector(outside_stuff::touchgrass));
        grass->setPosition({win.width - 120.f, win.height - 240.f});
        grass->setID("grass"_spr);

        auto jojo = CCMenuItemSpriteExtra::create(CCSprite::create("jojosiwa.png"_spr), nullptr, things, menu_selector(outside_stuff::jojo));
        jojo->setPosition({win.width / 12.f, win.height / 2.f});
        jojo->setID("jojo"_spr);

        auto menu = CCMenu::create();
        menu->setPosition({0,0});
        menu->addChild(nuke);
        menu->addChild(ball);
        menu->addChild(grass);
        menu->addChild(jojo);
        menu->addChild(things);
        menu->setID("room-menu"_spr);
        return menu;
    }
}