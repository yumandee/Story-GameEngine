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

#ifdef STORY_DEBUG
#define STORY_LOG(x) std::cout << x << std::endl;
#else
#define STORY_LOG(x)
#endif