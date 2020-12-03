#include "pch.h"
#include "GCPlugin.h"


BAKKESMOD_PLUGIN(GCPlugin, "Watermark Plugin", plugin_version, PLUGINTYPE_FREEPLAY)

float xScale = 1.0;
float yScale = 1.0;
float xLoc = 0.0;
float yLoc = 0.0;
float xLocBg = 0.0;
float yLocBg = 0.0;
float xEndBg = 0.2;
float yEndBg = 0.2;
LinearColor color;
LinearColor bgColor;
bool enabled = false;
bool bgEnabled = false;

void GCPlugin::onLoad()
{
	std::string imageLoc = gameWrapper->GetDataFolder().string() + "/watermark.png";
	cvarManager->log(imageLoc);
	image = std::make_shared<ImageWrapper>(imageLoc, true);

	// Loads it so it can be used in the canvas
	if (image->LoadForCanvas()) {
		cvarManager->log("image loaded for canvas");
	} else {
		cvarManager->log("image not loaded for canvas");
	}

	cvarManager->log("Plugin loaded!");
	gameWrapper->RegisterDrawable(
		std::bind(&GCPlugin::render, this, std::placeholders::_1));

	cvarManager->registerCvar("watermark_enabled", "0", "enable watermark plugin")
		.addOnValueChanged([this](auto, CVarWrapper cvar) { enabled = cvar.getBoolValue(); });
	cvarManager->registerCvar("watermark_x", "0.0", "x location of watermark image")
		.addOnValueChanged([this](auto, CVarWrapper cvar) { xLoc = cvar.getFloatValue(); });
	cvarManager->registerCvar("watermark_y", "0.0", "y location of watermark image")
		.addOnValueChanged([this](auto, CVarWrapper cvar) { yLoc = cvar.getFloatValue(); });
	cvarManager->registerCvar("watermark_x_scale", "1.0", "x scale of watermark")
		.addOnValueChanged([this](auto, CVarWrapper cvar) { xScale = cvar.getFloatValue(); });
	cvarManager->registerCvar("watermark_y_scale", "1.0", "y scale of watermark")
		.addOnValueChanged([this](auto, CVarWrapper cvar) { yScale = cvar.getFloatValue(); });
	
	cvarManager->registerCvar("watermark_bg_enabled", "0", "enable watermark background")
		.addOnValueChanged([this](auto, CVarWrapper cvar) { bgEnabled = cvar.getBoolValue(); });
	cvarManager->registerCvar("watermark_bg_x", "0.0", "x location of watermark background")
		.addOnValueChanged([this](auto, CVarWrapper cvar) { xLocBg = cvar.getFloatValue(); });
	cvarManager->registerCvar("watermark_bg_y", "0.0", "y location of watermark background")
		.addOnValueChanged([this](auto, CVarWrapper cvar) { yLocBg = cvar.getFloatValue(); });
	cvarManager->registerCvar("watermark_bg_x_end", "0.2", "x end location of watermark background")
		.addOnValueChanged([this](auto, CVarWrapper cvar) { xEndBg = cvar.getFloatValue(); });
	cvarManager->registerCvar("watermark_bg_y_end", "0.2", "y location of watermark background")
		.addOnValueChanged([this](auto, CVarWrapper cvar) { yEndBg = cvar.getFloatValue(); });

	auto bgColorVar = cvarManager->registerCvar("watermark_bg_color", "#000000FF", "color of background");
	bgColor = bgColorVar.getColorValue();
	bgColorVar.addOnValueChanged([this](std::string, CVarWrapper cvar) { bgColor = cvar.getColorValue(); });

	auto colorVar = cvarManager->registerCvar("watermark_color", "#FFFFFFFF", "color of watermark");
	color = colorVar.getColorValue();
	colorVar.addOnValueChanged([this](std::string, CVarWrapper cvar) { color = cvar.getColorValue(); });
}

void GCPlugin::render(CanvasWrapper canvas) {
	auto canSize = canvas.GetSize();

	if (bgEnabled) {
		canvas.SetPosition(Vector2({ (int)(xLocBg * canSize.X), (int)(yLocBg * canSize.Y) }));
		canvas.SetColor(bgColor);
		canvas.FillBox(Vector2({ int(canSize.X * xEndBg), int(canSize.Y * yEndBg) }));
	}

	if (enabled && image->IsLoadedForCanvas()) {
		canvas.SetPosition(Vector2({ (int)(xLoc * canSize.X), (int) (yLoc * canSize.Y) }));
		canvas.SetColor(color);
		//canvas.DrawTexture(testImage.get(), scale);
		auto imgSize = image.get()->GetSize();
		canvas.DrawRect(xScale * imgSize.X, yScale * imgSize.Y, image.get());
	}
}

void GCPlugin::onUnload()
{
}