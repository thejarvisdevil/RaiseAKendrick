#pragma once
#include <Geode/Geode.hpp>
#include <algorithm>
#include <string>

using namespace geode::prelude;

namespace devlin {
	inline static CCSprite* createSpriteCustom(const char* path) {
		auto sprite = new CCSprite();
		if (sprite->initWithFile(pathToFile)) {
			sprite->autorelease();
			return sprite;
		}
		delete sprite;
		return nullptr;
	}
	inline void set_room(geode::prelude::CCLayer* layer, const std::string& title, const std::string& background) {
		if (!layer) return;
		auto win = CCDirector::get()->getWinSize();

		if (auto bro = typeinfo_cast<CCLabelBMFont*>(layer->getChildByID("roomTitle"_spr))) {
			bro->setString(title.c_str());
		} else {
			auto yay = CCLabelBMFont::create(title.c_str(), "bigFont.fnt");
			yay->setScale(0.75f);
			yay->setPosition({win.width / 2.f, win.height - 30.f});
			yay->setID("roomTitle"_spr);
			layer->addChild(yay, 1);
		}

		if (auto old = typeinfo_cast<CCSprite*>(layer->getChildByID("roomBg"_spr))) {
			layer->removeChild(old, true);
			if (auto bg = CCSprite::create(background.c_str())) {
				auto s = bg->getContentSize();
				auto w = CCDirector::get()->getWinSize().width;
				auto h = CCDirector::get()->getWinSize().height;
				float scaleX = (s.width > 0) ? (w / s.width) : 1.0f;
				float scaleY = (s.height > 0) ? (h / s.height) : 1.0f;
				bg->setScaleX(scaleX);
				bg->setScaleY(scaleY);
				bg->setPosition({win.width / 2.f, win.height / 2.f});
				bg->setID("roomBg"_spr);
				layer->addChild(bg, -10);
			}
		} else {
			if (auto bg = CCSprite::create(background.c_str())) {
				auto s = bg->getContentSize();
				auto w = CCDirector::get()->getWinSize().width;
				auto h = CCDirector::get()->getWinSize().height;
				float scaleX = (s.width > 0) ? (w / s.width) : 1.0f;
				float scaleY = (s.height > 0) ? (h / s.height) : 1.0f;
				bg->setScaleX(scaleX);
				bg->setScaleY(scaleY);
				bg->setPosition({win.width / 2.f, win.height / 2.f});
				bg->setID("roomBg"_spr);
				layer->addChild(bg, -10);
			}
		}
	}

	inline void set_emotion(geode::prelude::CCLayer* layer, const std::string& file, float scale = 1.0f, float x = 0.5f, float y = 0.5f) {
		if (!layer) return;
		using namespace geode::prelude;

		auto win = CCDirector::get()->getWinSize();
		auto old = typeinfo_cast<CCSprite*>(layer->getChildByID("character"_spr));
		CCPoint pos = {0, 0};
		if (old) {
			pos = old->getPosition();
			scale = old->getScale();
		} else {
			pos = CCPoint(win.width * x, win.height * y);
		}

		CCSprite* kendrick = nullptr;
		if (auto gif = devlin::createSpriteCustom(file.c_str())) { kendrick = gif; }
		if (!kendrick) return;

		auto size = kendrick->getContentSize();
		float fixW = (size.width > 0) ? (win.width * 0.45f / size.width) : scale;
		float fixH = (size.height > 0) ? (win.height * 0.45f / size.height) : scale;
		float maxScale = std::min(fixW, fixH);
		float yayayayay = std::min(scale, maxScale);

		kendrick->setPosition(pos);
		kendrick->setScale(yayayayay);
		kendrick->setID("character"_spr);
		layer->addChild(kendrick, -5);

		if (old) layer->removeChild(old, true);
	}
}