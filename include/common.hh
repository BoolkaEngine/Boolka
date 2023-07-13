#pragma once

#ifndef API_EXPORT

#if defined(PLATFORM_EXPORT) && defined(PLATFORM_WINDOWS)
#define API_EXPORT __declspec(dllexport)
#else
#define API_EXPORT __declspec(dllimport)
#endif

#endif

using AppEntry = void (*)();
