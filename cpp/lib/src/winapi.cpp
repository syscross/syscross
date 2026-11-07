
#include "winapi.h"

#ifdef _WIN32
#include <windows.h>
#include <cstdio>

static wstring to_wstring(str s) {
    if (s.empty()) {
        return {};
    }
    int len = MultiByteToWideChar(CP_UTF8, 0, s.data(), static_cast<int>(s.size()), null, 0);
    wstring res(len, L'\0');
    MultiByteToWideChar(CP_UTF8, 0, s.data(), static_cast<int>(s.size()), res.data(), len);
    return res;
}

static LRESULT CALLBACK wnd_proc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    if (msg == WM_DESTROY) {
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd, msg, wp, lp);
}

void create_window(WindowDesc desc) {
    HINSTANCE hinst = GetModuleHandleW(null);
    wstring title = to_wstring(desc.title);
    const wchar* cls_name = L"SysCrossWindow";

    WNDCLASSEXW wc = {
        .cbSize        = sizeof(WNDCLASSEXW),
        .style         = CS_HREDRAW | CS_VREDRAW,
        .lpfnWndProc   = wnd_proc,
        .hInstance     = hinst,
        .hCursor       = LoadCursorW(null, IDC_ARROW),
        .hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1),
        .lpszClassName = cls_name,
    };
    RegisterClassExW(&wc);

    RECT rect = { 0, 0, desc.width, desc.height };
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

    HWND hwnd = CreateWindowExW(
        0,
        cls_name,
        title.c_str(),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        rect.right - rect.left,
        rect.bottom - rect.top,
        null,
        null,
        hinst,
        null
    );

    ShowWindow(hwnd, SW_SHOWDEFAULT);
    UpdateWindow(hwnd);

    MSG msg = {};
    while (GetMessageW(&msg, null, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
}

int APIENTRY WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    if (AttachConsole(ATTACH_PARENT_PROCESS)) {
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
        freopen("CONIN$", "r", stdin);
    }
    return _main();
}
#else
void create_window(WindowDesc) {
}
#endif
