#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/binding/FMODAudioEngine.hpp>
#include <algorithm>
#include "funcs.hpp"
#include "rooms/livingroom.hpp"
#include "rooms/bedroom.hpp"
#include "rooms/bathroom.hpp"
#include "rooms/kitchen.hpp"
#include "rooms/outside.hpp"
using namespace geode::prelude;

// i lost a lot of sleep and brain cells making this mod. i only have 5 hours to sleep every night and now its done and its worth it!

class KendrickLayer : public cocos2d::CCLayer {
public:
	CREATE_FUNC(KendrickLayer);
	std::vector<std::string> rooms = {"livingroom", "bedroom", "bathroom", "kitchen", "outside"};
	int currentRoom = 0;

	bool init() override {
		if (!CCLayer::init()) return false;
		this->setKeypadEnabled(true);
		GameManager::get()->fadeInMusic("bgm.mp3"_spr);
		auto win = CCDirector::get()->getWinSize();

	    auto exitbtn = CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png");
	    exitbtn->setScale(0.5f);
		auto f = CCMenuItemSpriteExtra::create(exitbtn, nullptr, this, menu_selector(KendrickLayer::onBack));
		f->setPosition({win.width - 30.f, win.height - 30.f});
		f->setID("exit-btn"_spr);

		auto menu = CCMenu::create();
		menu->setPosition({0,0});
		menu->addChild(f);
		this->addChild(menu);

		auto leff = CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png");
		auto left = CCMenuItemSpriteExtra::create(leff, nullptr, this, menu_selector(KendrickLayer::prevRoom));
		left->setPosition({30.f, 30.f});
		left->setID("room-left"_spr);

		auto righttttt = CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png");
		righttttt->setFlipX(true);
		auto righty = CCMenuItemSpriteExtra::create(righttttt, nullptr, this, menu_selector(KendrickLayer::nextRoom));
		righty->setPosition({win.width - 30.f, 30.f});
		righty->setID("room-right"_spr);

		auto bazinga = CCMenu::create();
		bazinga->setPosition({0,0});
		bazinga->addChild(left);
		bazinga->addChild(righty);
		this->addChild(bazinga);

		this->applyRoom(this->rooms[this->currentRoom]);

		auto discord = CCSprite::createWithSpriteFrameName("gj_discordIcon_001.png");
		discord->setScale(0.5f);
		auto freepromo = CCMenuItemSpriteExtra::create(discord, nullptr, this, menu_selector(KendrickLayer::freepromo));
		freepromo->setPosition({15.f, win.height - 15.f});
		freepromo->setID("discord-btn"_spr);

		auto suggestions = CCSprite::createWithSpriteFrameName("accountBtn_messages_001.png");
		suggestions->setScale(0.4f);
		auto suggest = CCMenuItemSpriteExtra::create(suggestions, nullptr, this, menu_selector(KendrickLayer::suggest));
		suggest->setPosition({60.f, win.height - 15.f});
		suggest->setID("suggestions-btn"_spr);

		auto yeeeeee = CCMenu::create();
		yeeeeee->setPosition({0,0});
		yeeeeee->addChild(freepromo);
		yeeeeee->addChild(suggest);
		this->addChild(yeeeeee, -2);

		return true;
	}

	void onBack(CCObject*) {
		CCDirector::get()->popScene();
		GameManager::get()->fadeInMenuMusic();
	}

	virtual void keyBackClicked() {
        this->onBack(nullptr);
    }

	void prevRoom(CCObject*) {
		currentRoom = (currentRoom - 1 + (int)rooms.size()) % (int)rooms.size();
		applyRoom(rooms[currentRoom]);
	}

	void nextRoom(CCObject*) {
		currentRoom = (currentRoom + 1) % (int)rooms.size();
		applyRoom(rooms[currentRoom]);
	}

	void freepromo(CCObject*) {
		geode::utils::web::openLinkInBrowser("https://dsc.gg/devlin");
	}

	void suggest(CCObject*) {
		if (auto popup = GJWriteMessagePopup::create(30483751, 257687092)) {
			popup->updateSubject(gd::string("Suggestion For Kendrick"));
			popup->show();
		}
	}

	void KILL() {
		removeChildByID("room-menu"_spr);
		removeChildByID("character"_spr);
		removeChildByID("roomBg"_spr);
		removeChildByID("roomTitle"_spr);
		removeChildByID("ashbaby"_spr);
		removeChildByID("nuke"_spr);
	}

	void applyRoom(const std::string& name) {
		KILL();
		CCMenu* weeeeee = nullptr;
		if (name == "bedroom") {
			devlin::set_room(this, "Bedroom", "bedroom.png"_spr);
 			weeeeee = rooms::thebedroom(this);
		} else if (name == "livingroom") {
			devlin::set_room(this, "Living Room", "livingroom.png"_spr);
 			weeeeee = rooms::thelivingroom(this);
		} else if (name == "bathroom") {
			devlin::set_room(this, "Bathroom", "bathroom.png"_spr);
 			weeeeee = rooms::thebathroom(this);
		} else if (name == "kitchen") {
			devlin::set_room(this, "Kitchen", "kitchen.png"_spr);
 			weeeeee = rooms::thekitchen(this);
		} else if (name == "outside") {
			devlin::set_room(this, "Outside", "outside.png"_spr);
 			weeeeee = rooms::theoutside(this);
		}
		if (weeeeee) {
			addChild(weeeeee);
			weeeeee->setID("room-menu"_spr);
		}
		devlin::set_emotion(this, "excited.webp"_spr, 3.0f, 0.5f, 0.5f);
	}

	static cocos2d::CCScene* scene() {
		auto scene = cocos2d::CCScene::create();
		auto layer = KendrickLayer::create();
		scene->addChild(layer);
		return scene;
	}
};

class $modify(KLMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) { return false; }

		auto bruh = CCSprite::create("button.png"_spr);
		bruh->setScale(3.5f);

		auto lmao = CCMenuItemSpriteExtra::create(
			bruh, this,
			menu_selector(KLMenuLayer::onlmao)
		);

		auto menu = this->getChildByID("bottom-menu");
		menu->addChild(lmao);
		lmao->setID("not-like-us"_spr);
		menu->updateLayout();
		return true;
	}

	void onlmao(CCObject*) {
		// those who know
		if (1 == 1) {
			geode::log::info("tank u 4 usin my Mod :) - jarvisdevil");
		}
		CCDirector::get()->pushScene(CCTransitionFade::create(0.5f, KendrickLayer::scene()));
	}
};