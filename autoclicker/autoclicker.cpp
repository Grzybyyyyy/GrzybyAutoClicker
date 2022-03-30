// BIBLIOTEKI
#include <iostream>
#include <windows.h>
#include <conio.h> 

using namespace std;

// ZMIENNE
int x, y, mode, mcps, cps;
bool MV = true, TM = false, blc = true, brc = true, LC = false, RC = false, debugmode = false, NB = true, darkmode = false;

static void td()
{
    cout << "#   ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "<Debug Mode>";
    if (darkmode)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    }
    cout << "   #" << endl;
}

static void menu()
{
    system("cls");
    // COLOR
    if (darkmode)
    {
        system("color 8");
    }
    else
    {
        system("color a");
    }
    // MENU GLOWNE
    cout << "####################" << endl;
    cout << "#A.C. BY GRZYBYYYYY#" << endl;
    if (debugmode)
    {
        td();
        if (mcps <= 99)
        {
            cout << "# Millisecond = " << mcps << " #" << endl;
        }
        else
        {
            cout << "# Millisecond = " << mcps << "#" << endl;
        }
    }
    if (cps >= 10)
    {
        cout << "#     CPS = " << cps << "     #" << endl;
    }
    else
    {
        cout << "#     CPS = " << cps << "      #" << endl;
    }
    cout << "#  Toggle Mode = " << TM << " #" << endl;
    cout << "####################" << endl;
    if (blc)
    {
        cout << "#[MOUSE5]# L.CLICK #" << endl;
    }
    else
    {
        cout << "#[NUMP_5]# L.CLICK #" << endl;
    }
    if (brc)
    {
        cout << "#[MOUSE4]# R.CLICK #" << endl;
    }
    else
    {
        cout << "#[NUMP_4]# R.CLICK #" << endl;
    }
    cout << "#[F6]#   CONFIG    #" << endl;
    cout << "####################" << endl;
    cout << "#[INS]# HIDE/SHOW  #" << endl;
    cout << "####################" << endl;
}

static void bind()
{
    // MENU BINDOWANIA
    system("cls");
    ShowWindow(GetConsoleWindow(), SW_SHOW);
    cout << "####################" << endl;
    cout << "#A.C. BY GRZYBYYYYY#" << endl;
    td();
    if (NB)
    {
        cout << "#   BIND L.CLICK   #" << endl;
    }
    else
    {
        cout << "#   BIND R.CLICK   #" << endl;
    }
    cout << "####################" << endl;
    if (NB)
    {
        cout << "#[1]#    MOUSE5    #" << endl;
        cout << "#[2]#    NUMP_5    #" << endl;
    }
    else
    {
        cout << "#[1]#    MOUSE4    #" << endl;
        cout << "#[2]#    NUMP_4    #" << endl;
    }
    cout << "#[3]#     BACK     #" << endl;
    cout << "####################" << endl;
    cout << "Wybierz opcje(1-3): "; cin >> mode;
    // WYBUR OPCJI
    switch (mode)
    {
    case 1:
        if (NB)
        {
            blc = true;
        }
        else
        {
            brc = true;
        }
        break;
    case 2:
        if (NB)
        {
            blc = false;
        }
        else
        {
            brc = false;
        }
        break;
    case 3:

        break;
    default: cout << "Nie ma takiej opcji :/"; Sleep(250);
    }
}

static void scps()
{
    cout << "Podaj liczbe CPS: "; cin >> cps;
    // OBLICZANIE CPS
    if ((cps >= 1) && (cps <= 40))
    {
        if ((cps >= 1) && (cps <= 32))
        {
            mcps = (1000 / cps) - 5;
        }
        if ((cps >= 33) && (cps <= 40))
        {
            mcps = (1000 / cps) - 10;
        }
    }
    else
    {
        cout << "CPS nie moze byc wiekszy od 40 i mniejszy od 1" << endl;
        scps();
    }
}

static void config()
{
    // MENU CONFIGU
    system("cls");
    ShowWindow(GetConsoleWindow(), SW_SHOW);
    if (debugmode)
    {
        cout << "####################" << endl;
        cout << "#A.C. BY GRZYBYYYYY#" << endl;
        td();
        cout << "#      CONFIG      #" << endl;
        cout << "####################" << endl;
        cout << "#[1]# BIND L.CLICK #" << endl;
        cout << "#[2]# BIND R.CLICK #" << endl;
        cout << "#[3]# Toggle mode  #" << endl;
        cout << "#[4]#   SET CPS    #" << endl;
        cout << "#[5]#  SET 65 CPS  #" << endl;
        cout << "#[6]#  Debug Mode  #" << endl;
        cout << "#[7]#  Dark  Mode  #" << endl;
        cout << "#[8]#     BACK     #" << endl;
        cout << "####################" << endl;
        cout << "Wybiesz opcje (1-8): "; cin >> mode;
        // WYBUR OPCJI
        switch (mode)
        {
        case 1:
            NB = true;
            bind();
            Sleep(300);
            break;
        case 2:
            NB = false;
            bind();
            Sleep(300);
            break;
        case 3:
            TM = !TM;
            Sleep(300);
            break;
        case 4:
            scps();
            Sleep(300);
            break;
        case 5:
            cps = 65;
            mcps = 12;
            Sleep(300);
            break;
        case 6:
            if (!debugmode)
            {
                debugmode = !debugmode;
            }
            else
            {
                debugmode = !debugmode;
                system("cls");
                system("color f");
                scps();
            }
            break;
        case 7:
            darkmode = !darkmode;
            break;
        case 8:
            menu();
            break;
        default: cout << "Nawet ja nie znam takiej opcji :/"; Sleep(300); config();
        }
    }
    else
    {
        cout << "####################" << endl;
        cout << "#A.C. BY GRZYBYYYYY#" << endl;
        cout << "#      CONFIG      #" << endl;
        cout << "####################" << endl;
        cout << "#[1]# Toggle mode  #" << endl;
        cout << "#[2]#   SET CPS    #" << endl;
        cout << "#[3]#  Debug Mode  #" << endl;
        cout << "#[4]#  Dark  Mode  #" << endl;
        cout << "#[5]#     BACK     #" << endl;
        cout << "####################" << endl;
        cout << "Wybiesz opcje (1-5): "; cin >> mode;
        // WYBUR OPCJI
        switch (mode)
        {
        case 1:
            TM = !TM;
            Sleep(300);
            break;
        case 2:
            scps();
            Sleep(300);
            break;
        case 3:
            if (!debugmode)
            {
                debugmode = !debugmode;
            }
            else
            {
                debugmode = !debugmode;
                system("cls");
                system("color f");
                scps();
            }
            break;
        case 4:
            darkmode = !darkmode;
            break;
        case 5:
            menu();
            break;
        default: cout << "Nawet ja nie znam takiej opcji :/"; Sleep(300); config();
        }
    }
    menu();
}

int main()
{
    // USTAWIANIE WIELKOSCI OKNA
    HWND hwnd = GetConsoleWindow();
    if (hwnd != NULL)
    {
        MoveWindow(hwnd, 200, 200, 250, 300, TRUE);
    }
    // MENU
    scps();
    menu();

    for (;;)
    {
        // HIDE/SHOW MENU
        if (GetAsyncKeyState(VK_INSERT))
        {
            MV = !MV;
            // SHOW
            if (MV)
            {
                ShowWindow(GetConsoleWindow(), SW_SHOW);
            }
            // HIDE
            if (!MV)
            {
                ShowWindow(GetConsoleWindow(), SW_HIDE);
            }
            Sleep(500);
        }
        // SET CONFIG
        if (GetAsyncKeyState(VK_F6))
        {
            config();
            Sleep(500);
        }
        // TOGGLE OFF
        // LEFT BUTTON
        if ((GetAsyncKeyState(VK_XBUTTON2)) && (blc) && (!TM))
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
            Sleep(mcps);
        }
        if ((GetAsyncKeyState(VK_NUMPAD5)) && (!blc) && (!TM))
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
            Sleep(mcps);
        }
        // RIGHT BUTTON
        if ((GetAsyncKeyState(VK_XBUTTON1)) && (brc) && (!TM))
        {
            mouse_event(MOUSEEVENTF_RIGHTDOWN, x, y, 0, 0);
            mouse_event(MOUSEEVENTF_RIGHTUP, x, y, 0, 0);
            Sleep(mcps);
        }
        if ((GetAsyncKeyState(VK_NUMPAD4)) && (!brc) && (!TM))
        {
            mouse_event(MOUSEEVENTF_RIGHTDOWN, x, y, 0, 0);
            mouse_event(MOUSEEVENTF_RIGHTUP, x, y, 0, 0);
            Sleep(mcps);
        }
        // TOGGLE ON
        // LEFT BUTTON
        if ((TM) && (GetAsyncKeyState(VK_XBUTTON2)) || (GetAsyncKeyState(VK_NUMPAD5)))
        {
            LC = !LC;
            menu();
            Sleep(300);
        }
        if ((TM) && (LC))
        {
            if (GetAsyncKeyState(VK_XBUTTON2))
            {
                LC = !LC;
                menu();
                Sleep(300);
            }
            Sleep(mcps); 
            mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
        }
        // RIGHT BUTTON
        if ((TM) && (GetAsyncKeyState(VK_XBUTTON1)))
        {
            RC = !RC;
            menu();
            Sleep(300);
        }
        if ((TM) && (RC))
        {
            if (GetAsyncKeyState(VK_XBUTTON1))
            {
                RC = !RC;
                menu();
                Sleep(300);
            }
            Sleep(mcps);
            mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
        }
    }
}