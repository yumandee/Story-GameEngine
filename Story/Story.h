#pragma once
#include "StoryApp.h"
#include "StoryUtils.h"
#include "GameWindow.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"
#include "Events.h"
#include "KeyCodes.h"

#define START_STORY_GAME(classname) \
int main() {\
	classname _story_game;\
	_story_game.Run();\
}
