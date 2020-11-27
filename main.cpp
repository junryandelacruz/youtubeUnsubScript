#include <iostream>
#include <Windows.h>
#include <winuser.h>

using namespace std;


int displayCursorPos();
int clickAndRelease();
int refreshPage();
int tabTabEnter();

int main()
{
    cout << "Press 0 to stop" << endl;

    while(true) {

        if (GetAsyncKeyState(VK_NUMPAD0)) { // Exit
            return 0;
        }

        // Move mouse to subscribed button
        SetCursorPos(3500, 243);
        displayCursorPos();

        // Click subscribed button
        clickAndRelease();

        // Move mouse to confirm unsubscribe button
        //SetCursorPos(2950,613);

        // Tab Tab Enter
        tabTabEnter();

        // Click confirm unsubscribe button
        clickAndRelease();

        // Refresh page
        refreshPage();

        cout << "Unsub successful! Press 0 on num pad to stop program." << endl;

        // Repeat

    }
    return 0;
}

int tabTabEnter() {

    INPUT ip = { 0 };
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;


    // Press the "Tab" key
    ip.ki.wVk = VK_TAB;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "Tab" key
    ip.ki.wVk = VK_TAB;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));

    // Press the "Tab" key
    ip.ki.wVk = VK_TAB;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "Tab" key
    ip.ki.wVk = VK_TAB;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));

    // Press the Enter Key
    ip.ki.wVk = VK_RETURN;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the Enter Key
    ip.ki.wVk = VK_RETURN;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));

    //Sleep(5000);
}

int displayCursorPos(){
    POINT p;
    GetCursorPos(&p);
    //cout << "x-position: " << p.x << " | y-position: " << p.y << endl;
    return 1;
}

int clickAndRelease() {

    INPUT iNPUT = { 0 };

    iNPUT.type = INPUT_MOUSE;
    iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &iNPUT, sizeof(iNPUT));

    ZeroMemory(&iNPUT, sizeof(iNPUT));

    iNPUT.type = INPUT_MOUSE;
    iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &iNPUT, sizeof(iNPUT));
    Sleep(1000);

    return 1;
}

int refreshPage() {

    INPUT ip = { 0 };
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    // Press the "Ctrl" key
    ip.ki.wVk = VK_CONTROL;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Press the "V" key
    ip.ki.wVk = 'R';
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "V" key
    ip.ki.wVk = 'R';
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "Ctrl" key
    ip.ki.wVk = VK_CONTROL;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));

    Sleep(5000); // pause for 1 second



}
