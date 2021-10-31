#pragma once

#ifdef STORY_WINDOWS
#ifdef STORY_LIB
#define STORY_API  __declspec(dllexport)
#else 
#define STORY_API  __declspec(dllimport)
#endif
#else 
#define STORY_API
#endif

