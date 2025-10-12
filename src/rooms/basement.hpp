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
                std::vector<std::pair<std::string, int>> items = {
                    {"Kendrick", 75},
                    {"Mustard", 70},
                    {"Shrek", 60},
                    {"Jack Black", 55},
                    {"Sigma Boy", 50},
                    {"Todd", 45},
                    {"KPop Demon Hunters", 40},
                    {"Drake", 33},
                    {"67 Kid", 30},
                    {"Eminem", 25},
                    {"Snoop Dogg", 20},
                    {"Ronald McDonald", 15},
                    {"Quandale Dingle", 10},
                    {"Tung Tung Tung Sahur", 7},
                    {"Dwayne The Rock Johnson", 5},
                    {"Kanye West", 3},
                    {"Micheal Jackson", 2},
                    {"KSI", 1},
                    {"Jojo Siwa", 0.5},
                    {"Mega Kendrick", 0.33},
                    {"Mac & Cheese", 0.1},
                    {"Shiny Kendrick", 0.01},
                    {"RobTop", 0.001},
                    {"npesta", 0.0001},
                    {"Jesus", 0.00001},
                    {"Skibidi Toilet", 0.000001},
                    {"David Baszucki", 0.0000001},
                    {"Burger", 0.00000001}
                };

                int total = 0;
                for (const auto& item : items) total += item.second;

                if (total == 0) {
                    // Happy Halloween, Charlie Brown!
                    FLAlertLayer::create("Gamble", "<cr>You got a rock.</c>", "OK")->show();
                    return;
                }

                int r = rand() % total, lmao = 0;
                for (const auto& item : items) {
                    lmao += item.second;
                    if (r < lmao) {
                        float chance = 100.0f * item.second / total;
                        char gg[8];
                        snprintf(gg, sizeof(gg), "%.1f", chance);
                        geode::createQuickPopup(
                            "LETS GO GAMBLE!",
                            "<cy>You spent money and:</c>\n<cr>You won a " + item.first + "!</c>\n\n<cb>[Chance " + gg + "%]</c>",
                            "OK", "Chances",
                            [items, total](FLAlertLayer*, bool btn2) {
                                if (btn2) {
                                    int every = 6, c = total, pages = (items.size() + every - 1) / every;
                                    for (int p = 0; p < pages; ++p) {
                                        std::string list;
                                        for (int i = p * every; i < std::min((p + 1) * every, (int)items.size()); ++i) {
                                            float chance = 100.0f * items[i].second / c;
                                            char buf[16]; snprintf(buf, sizeof(buf), "%.5f", chance);
                                            list += "<cb>" + items[i].first + ": " + buf + "%</c>\n";
                                        }
                                        FLAlertLayer::create("Chances", list, "OK")->show();
                                    }
                                }
                            }
                        );
                        break;
                    }
                }
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