// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� SYSTOOLS_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// SYSTOOLS_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef SYSTOOLS_EXPORTS
#define SYSTOOLS_API __declspec(dllexport)
#else
#define SYSTOOLS_API __declspec(dllimport)
#endif


extern "C" SYSTOOLS_API void ShowCaptureWnd(HWND hWnd);
extern "C" SYSTOOLS_API HBITMAP CopyWndRectToBitmap(HWND hWnd);
extern "C" SYSTOOLS_API HBITMAP CopyScreenRectToBitmap(RECT rect);
extern "C" SYSTOOLS_API void SaveBitmapToFile(char* image, HBITMAP hBitmap);