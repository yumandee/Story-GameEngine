#pragma once
#include "StoryUtils.h"
#include "GameWindow.h"

#define FRAMES_PER_SECOND 30
namespace Story {
    class STORY_API StoryApp
    {
    public:
        void Run(); //starts the game
        virtual void OnUpdate();
        virtual void OnKeyPressed(KeyPressedEvent &event);
        int GetGameWindowWidth() const;
        int GetGameWindowHeight() const; 
    protected:
        StoryApp();

    private:
        GameWindow mGameWindow;
        
        std::chrono::steady_clock::time_point mTimeOfNextFrame;
        std::chrono::milliseconds mFrameDuration { 1000/FRAMES_PER_SECOND };
    };
}