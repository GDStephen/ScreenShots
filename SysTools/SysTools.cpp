// SysTools.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "SysTools.h"
#include <psapi.h>
#pragma comment(lib, "Psapi.lib")
#include "ScreenCapture/CaptureWnd.h"
#include "ScreenCapture/CaptureHelper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// 初始化 MFC 并在失败时显示错误
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: 更改错误代码以符合您的需要
			_tprintf(_T("错误: MFC 初始化失败\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: 在此处为应用程序的行为编写代码。
		}
	}
	else
	{
		// TODO: 更改错误代码以符合您的需要
		_tprintf(_T("错误: GetModuleHandle 失败\n"));
		nRetCode = 1;
	}

	return nRetCode;
}


SYSTOOLS_API void ShowCaptureWnd(HWND hWnd)
{
// 	HMODULE hModule = ::GetModuleHandle(NULL);
// 
// 	if (hModule != NULL)
// 	{
// 		// 初始化 MFC 并在失败时显示错误
// 		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
// 		{
// 			return;
// 		}
// 	}

	CCaptureWnd::GetInstance()->EventRegister(hWnd);
	CCaptureWnd::GetInstance()->ShowWindow(SW_SHOW);
	SetForegroundWindow(CCaptureWnd::GetInstance()->GetSafeHwnd());
}

SYSTOOLS_API HBITMAP CopyWndRectToBitmap(HWND hWnd)
{
	RECT rt; 
	::GetWindowRect( hWnd, &rt );
	return CopyScreenRectToBitmap(&rt);
}

SYSTOOLS_API HBITMAP CopyScreenRectToBitmap(RECT rect)
{
	return CopyScreenRectToBitmap(&rect);
}

SYSTOOLS_API void SaveBitmapToFile( char* image, HBITMAP hBitmap )
{
	SaveFile(image, hBitmap);
}
