#pragma once
#ifndef _SYSTEMCLASS_H_
#define _SYSTEMCLASS_H_
//Pre-pocessing directives
#define WIN32_LEAN_AND_MEAN
//includes
#include <Windows.h>
//MY CLASSES
#include "inputclass.h"
#include "applicationclass.h"

class SystemClass
{
public:
	SystemClass();
	SystemClass(const SystemClass& instance);
	~SystemClass();
	bool Initialize();
	void Shutdown();
	void Run();
	LRESULT CALLBACK MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam);
private:
	bool Frame();
	void InitializeWindows(int& val, int& init);
	void ShutdownWindows();
	
	LPCWSTR m_applicationName;
	HINSTANCE m_hinstance;
	HWND m_hwnd;
	//custom classes
	InputClass* m_input;
	ApplicationClass* m_application;
};
//GLOBALS
static LRESULT CALLBACK WndProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam);

static SystemClass* ApplicationHandle = 0;
#endif
