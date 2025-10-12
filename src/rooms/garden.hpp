#pragma once
#include <Geode/Geode.hpp>
#include <Geode/binding/FMODAudioEngine.hpp>
#include "../funcs.hpp"
using namespace geode::prelude;

namespace rooms {
    class garden_stuff : public cocos2d::CCNode {
    public:
        cocos2d::CCLayer* parent = nullptr;
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

    inline cocos2d::CCMenu* thegarden(cocos2d::CCLayer* parent = nullptr) {
        auto win = CCDirector::get()->getWinSize();
        auto things = new garden_stuff();
        things->parent = parent;
        devlin::set_emotion(parent, "excited.gif"_spr, 3.0f, 0.7f, 0.2f);

        auto p = CCSprite::create("pet_peashooter.png"_spr);
        p->setScale(1.1f);
        auto peashooter = CCMenuItemSpriteExtra::create(p, nullptr, things, menu_selector(livingroom_stuff::peashooter));
        peashooter->setPosition({win.width / 4.f, win.height / 2.f});
        peashooter->setID("peashooter"_spr);

        auto menu = CCMenu::create();
        menu->setPosition({0,0});
        menu->addChild(peashooter);
        menu->setID("room-menu"_spr);
        return menu;
    }
}