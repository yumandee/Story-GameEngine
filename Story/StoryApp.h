#pragma once
#include "StoryUtils.h"
#include "GameWindow.h"

namespace Story {
    class STORY_API StoryApp
    {
    public:
        void Run(); //starts the game
        virtual void OnUpdate();

    protected:
        StoryApp();

    private:
        GameWindow mGameWindow;
        
    };
}