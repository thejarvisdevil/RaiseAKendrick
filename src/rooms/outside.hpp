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

        auto menu = CCMenu::create();
        menu->setPosition({0,0});
        menu->addChild(nuke);
        menu->addChild(ball);
        menu->addChild(grass);
        menu->addChild(things);
        menu->setID("room-menu"_spr);
        return menu;
    }
}