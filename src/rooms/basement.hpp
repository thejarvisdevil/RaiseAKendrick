#pragma once
#include <Geode/Geode.hpp>
#include <Geode/binding/FMODAudioEngine.hpp>
#include "../funcs.hpp"
using namespace geode::prelude;

namespace rooms {
    class basement_stuff : public cocos2d::CCNode {
    public:
        cocos2d::CCLayer* parent = nullptr;
        void drake(CCObject*) {
            auto win = CCDirector::get()->getWinSize();
            if (parent) {
                std::vector<std::string> messages = {
                    "I will kill you Kendrick...",
                    "You will pay for what you have done...",
                    "I hate you Kendrick..."
                };
                std::string message = messages[rand() % messages.size()];
                FLAlertLayer::create("Drake", "<cr>" + message + "</c>", "OK")->show();
            }
        }

        void gamble(CCObject*) {
            if (parent) {
                FMODAudioEngine::sharedEngine()->playEffect("ting.mp3"_spr);
                FLAlertLayer::create("LETS GO GAMBLING!", "<cg>YOU WON BIG!!!</c>", "OK")->show();
            }
        }
    };

    inline cocos2d::CCMenu* thebasement(cocos2d::CCLayer* parent = nullptr) {
        auto win = CCDirector::get()->getWinSize();
        auto things = new basement_stuff();
        things->parent = parent;
        devlin::set_emotion(parent, "wth.gif"_spr, 3.0f, 0.3f, 0.2f);

        auto dr = CCSprite::create("drake.png"_spr);
        dr->setScale(2.5f);
        auto drake = CCMenuItemSpriteExtra::create(dr, nullptr, things, menu_selector(basement_stuff::drake));
        drake->setPosition({win.width * 0.65f, win.height / 4.20f});
        drake->setID("drake"_spr);

        auto gamble = CCMenuItemSpriteExtra::create(CCSprite::create("gamble.png"_spr), nullptr, things, menu_selector(basement_stuff::gamble));
        gamble->setPosition({win.width / 2.f, win.height / 1.75f});
        gamble->setID("gamble"_spr);

        auto menu = CCMenu::create();
        menu->setPosition({0,0});
        menu->addChild(drake);
        menu->addChild(gamble);
        menu->setID("room-menu"_spr);
        return menu;
    }
}