#include <windows.h>
#include <gdiplus.h>


using namespace Gdiplus;


int activeLight = 0;


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch(msg) {
        case WM_LBUTTONDOWN: {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);

            if (x >= 160 && x <= 240) {
                if (y >= 60 && y <= 140) activeLight = 1;      // Червоний
                else if (y >= 150 && y <= 230) activeLight = 2; // Жовтий
                else if (y >= 240 && y <= 320) activeLight = 3; // Зелений
            }

            InvalidateRect(hwnd, NULL, FALSE);
            return 0;
        }

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            Graphics graphics(hdc);
            graphics.SetSmoothingMode(SmoothingModeAntiAlias);

            // Корпус
            SolidBrush brushBody(Color(255, 50, 50, 50));
            graphics.FillRectangle(&brushBody, 150, 50, 100, 300);

            // Кольори
            Color colorRed    = (activeLight == 1) ? Color(255, 255, 0, 0) : Color(255, 60, 0, 0);
            Color colorYellow = (activeLight == 2) ? Color(255, 255, 255, 0) : Color(255, 60, 60, 0);
            Color colorGreen  = (activeLight == 3) ? Color(255, 0, 255, 0) : Color(255, 0, 60, 0);

            // Малюємо кола
            SolidBrush brushRed(colorRed);
            graphics.FillEllipse(&brushRed, 160, 60, 80, 80);

            SolidBrush brushYellow(colorYellow);
            graphics.FillEllipse(&brushYellow, 160, 150, 80, 80);

            SolidBrush brushGreen(colorGreen);
            graphics.FillEllipse(&brushGreen, 160, 240, 80, 80);

            EndPaint(hwnd, &ps);
            return 0;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);


    const wchar_t CLASS_NAME[] = L"TrafficLightClass";

    WNDCLASSW wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_HAND);


    RegisterClassW(&wc);


    HWND hwnd = CreateWindowExW(
        0,
        CLASS_NAME,
        L"Мій Інтерактивний Світлофор", //
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 450, 600,
        NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL) return 0;

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    GdiplusShutdown(gdiplusToken);
    return 0;
}