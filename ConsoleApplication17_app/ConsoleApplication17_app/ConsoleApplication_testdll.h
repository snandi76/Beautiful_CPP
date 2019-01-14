#pragma once
#ifndef INDLL_H
#define INDLL_H

#ifdef EXPORTING_DLL
#ifdef __cplusplus
extern "C" {
#endif
	extern __declspec(dllexport) void HelloWorld(int *p);
#ifdef __cplusplus
}
#endif
#else
#ifdef __cplusplus
extern "C" {
#endif
	extern __declspec(dllimport) void HelloWorld(int *p);
#ifdef __cplusplus
}
#endif
#endif

#endif