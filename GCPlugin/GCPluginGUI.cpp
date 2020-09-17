#include "pch.h"
#include "GCPlugin.h"

/*
// Do ImGui rendering here
void GCPlugin::Render()
{
	if (!ImGui::Begin(menuTitle_.c_str(), &isWindowOpen_, ImGuiWindowFlags_None))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}

	ImGui::End();

	if (!isWindowOpen_)
	{
		cvarManager->executeCommand("togglemenu " + GetMenuName());
	}
}

// Name of the menu that is used to toggle the window.
std::string GCPlugin::GetMenuName()
{
	return "GCPlugin";
}

// Title to give the menu
std::string GCPlugin::GetMenuTitle()
{
	return menuTitle_;
}

// Don't call this yourself, BM will call this function with a pointer to the current ImGui context
void GCPlugin::SetImGuiContext(uintptr_t ctx)
{
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

// Should events such as mouse clicks/key inputs be blocked so they won't reach the game
bool GCPlugin::ShouldBlockInput()
{
	return ImGui::GetIO().WantCaptureMouse || ImGui::GetIO().WantCaptureKeyboard;
}

// Return true if window should be interactive
bool GCPlugin::IsActiveOverlay()
{
	return true;
}

// Called when window is opened
void GCPlugin::OnOpen()
{
	isWindowOpen_ = true;
}

// Called when window is closed
void GCPlugin::OnClose()
{
	isWindowOpen_ = false;
}
*/
