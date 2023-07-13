#pragma once

#ifndef API_EXPORT

#ifdef PLATFORM_WINDOWS
#ifdef PLATFORM_EXPORT
#define API_EXPORT __declspec(dllexport)
#else
#define API_EXPORT __declspec(dllimport)
#endif
#else
#define API_EXPORT
#endif

#endif

using AppEntry = void (*)();
