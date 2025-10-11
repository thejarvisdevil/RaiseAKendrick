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
                devlin::set_emotion(parent, "sad.webp"_spr, 3.0f, 0.5f, 0.5f);
                FMODAudioEngine::sharedEngine()->playEffect("tungtungtungsahurbeatupman.mp3"_spr);
            }
        }

        void peashooter(CCObject*) {
            if (parent) {
                std::vector<std::string> messages = {
                    "His name is Todd. Say Hi to Todd.",
                    "He is busy killing zombies in yo lawn. Try again later.",
                    "*barks*",
                    "*shoots pea*",
                    "Todd is a good peashooter.",
                    "You should probably water Todd.",
                    "*peashooter noises*",
                    "Todd is the best Peashooter!!",
                    "lol",
                    "peashooter go brrr",
                    "sorry, Todd is busy.",
                    "Todd is just a peashooter",
                    "get rekt zombies said Todd",
                    "beware of todd",
                    "quack quack",
                    "meow",
                    "woof woof",
                    "e"
                };
                std::string message = messages[rand() % messages.size()];
                FLAlertLayer::create("Peashooter", message, "OK")->show();
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

        auto p = CCSprite::create("pet_peashooter.png"_spr);
        p->setScale(0.7f);
        auto peashooter = CCMenuItemSpriteExtra::create(p, nullptr, things, menu_selector(livingroom_stuff::peashooter));
        peashooter->setPosition({win.width - 120.f, 60.f});
        peashooter->setID("peashooter"_spr);

        auto menu = CCMenu::create();
        menu->setPosition({0,0});
        menu->addChild(tele);
        menu->addChild(peashooter);
        menu->addChild(things);
        menu->setID("room-menu"_spr);
        return menu;
    }
}