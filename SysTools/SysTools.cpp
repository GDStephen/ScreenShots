// SysTools.cpp : ���� DLL Ӧ�ó���ĵ���������
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


// Ψһ��Ӧ�ó������

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// ��ʼ�� MFC ����ʧ��ʱ��ʾ����
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: ���Ĵ�������Է���������Ҫ
			_tprintf(_T("����: MFC ��ʼ��ʧ��\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: �ڴ˴�ΪӦ�ó������Ϊ��д���롣
		}
	}
	else
	{
		// TODO: ���Ĵ�������Է���������Ҫ
		_tprintf(_T("����: GetModuleHandle ʧ��\n"));
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
// 		// ��ʼ�� MFC ����ʧ��ʱ��ʾ����
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
