#include "pch.h"
#include "GCPlugin.h"


BAKKESMOD_PLUGIN(GCPlugin, "become GC", plugin_version, PLUGINTYPE_FREEPLAY)

float scale = 1.0;
float xLoc = 0.0;
float yLoc = 0.0;
bool enabled = false;

void GCPlugin::onLoad()
{
	testImage = std::make_shared<ImageWrapper>("./bakkesmod/data/watermark.png", true);

	// Loads it so it can be used in the canvas
	if (testImage->LoadForCanvas()) {
		cvarManager->log("image loaded for canvas");
	}

	cvarManager->log("Plugin loaded!");
	gameWrapper->RegisterDrawable(
		std::bind(&GCPlugin::render, this, std::placeholders::_1));

	cvarManager->registerCvar("watermark_scale", "1.0", "scale of watermark image")
		.addOnValueChanged([this](auto, CVarWrapper cvar) { scale = cvar.getFloatValue(); });
	cvarManager->registerCvar("watermark_x", "0.0", "x location of watermark image")
		.addOnValueChanged([this](auto, CVarWrapper cvar) { xLoc = cvar.getFloatValue(); });
	cvarManager->registerCvar("watermark_y", "0.0", "y location of watermark image")
		.addOnValueChanged([this](auto, CVarWrapper cvar) { yLoc = cvar.getFloatValue(); });
	cvarManager->registerCvar("watermark_enabled", "0", "enable watermark plugin")
		.addOnValueChanged([this](auto, CVarWrapper cvar) { enabled = cvar.getBoolValue(); });
}

void GCPlugin::render(CanvasWrapper canvas) {
	if (enabled && testImage->IsLoadedForCanvas()) {
		auto canSize = canvas.GetSize();
		canvas.SetPosition(Vector2({ (int)(xLoc * canSize.X), (int) (yLoc * canSize.Y) }));
		//canvas.SetPosition(Vector2({ 0, 0 }));
		canvas.DrawTexture(testImage.get(), scale);
	}
}

void GCPlugin::onUnload()
{
}