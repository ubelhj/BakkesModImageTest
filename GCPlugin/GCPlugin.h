#pragma once
#pragma comment(lib, "pluginsdk.lib")

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"

constexpr auto plugin_version = "1.0";

class GCPlugin: public BakkesMod::Plugin::BakkesModPlugin
{

	//Boilerplate
	virtual void onLoad();
	virtual void onUnload();

	void render(CanvasWrapper canvas);

	std::shared_ptr<ImageWrapper> image;
};

