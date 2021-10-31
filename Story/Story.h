#pragma once
#include "StoryApp.h"
#include "StoryUtils.h"
#include "GameWindow.h"

#define START_BUBBLE_GAME(classname) \
int main() {\
	classname _story_game;\
	_story_game.Run();\
}
