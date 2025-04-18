#define UNICODE
#define _UNICODE
#include <windows.h>

int a = 1;

int TestMessageBoxes() {
    // 使用宽字符版本的 MessageBoxW
    MessageBoxW(NULL, L"开始弹窗", L"Message01", MB_OK | MB_ICONINFORMATION);

    a = 0x8888;

    MessageBoxW(NULL, L"结束弹窗", L"Message02", MB_OK | MB_ICONINFORMATION);

    return 0;
}

int main() {
    TestMessageBoxes();
    return 0;
}