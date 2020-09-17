#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"

constexpr auto plugin_version = "1.0";

class GCPlugin: public BakkesMod::Plugin::BakkesModPlugin
{

	//Boilerplate
	virtual void onLoad();
	virtual void onUnload();

	void render(CanvasWrapper canvas);

	std::shared_ptr<ImageWrapper> testImage;
};

