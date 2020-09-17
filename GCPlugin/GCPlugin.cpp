#include "pch.h"
#include "GCPlugin.h"


BAKKESMOD_PLUGIN(GCPlugin, "become GC", plugin_version, PLUGINTYPE_FREEPLAY)


void GCPlugin::onLoad()
{
	testImage = std::make_shared<ImageWrapper>("./bakkesmod/data/s4-19.png", true);

	// Loads it so it can be used in the canvas
	if (testImage->LoadForCanvas()) {
		cvarManager->log("image loaded for canvas");
	}

	cvarManager->log("Plugin loaded!");
	gameWrapper->RegisterDrawable(
		std::bind(&GCPlugin::render, this, std::placeholders::_1));
}

void GCPlugin::render(CanvasWrapper canvas) {
	if (testImage->IsLoadedForCanvas()) {
		Vector2 mid = canvas.GetSize() / 2;
		Vector2 imageSize = { testImage->GetSize().width, testImage->GetSize().height };
		Vector2 imageMid = imageSize / 2;

		canvas.SetPosition(mid - imageMid);
		canvas.DrawTexture(testImage.get(), 1);
	}
}

void GCPlugin::onUnload()
{
}