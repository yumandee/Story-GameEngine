#pragma once
#include "StoryUtils.h"

namespace Story
{
    class STORY_API KeyPressedEvent
    {
    public:
        KeyPressedEvent(int keyCode);
        int GetKeyCode() const;
    private:
        int mKeyCode{ -1 };
    };
}