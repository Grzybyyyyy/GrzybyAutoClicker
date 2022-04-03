// BIBLIOTEKI
#include <iostream>
#include <windows.h>
#include <conio.h> 

using namespace std;

// ZMIENNE
int x, y, mode, mlcps, lcps, mrcps, rcps;
bool MV = true, TM = false, blc = true, brc = true, LC = false, RC = false, betamode = false, NB = true, darkmode = false;

static void td()
{
    cout << "#   ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << " <BetaMode> ";
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
    if (betamode)
    {
        td();
        if (mlcps <= 99)
        {
            cout << "# LMillisecond= " << mlcps << " #" << endl;
        }
        else
        {
            cout << "# LMillisecond= " << mlcps << "#" << endl;
        }
        if (mrcps <= 99)
        {
            cout << "# RMillisecond= " << mrcps << " #" << endl;
        }
        else
        {
            cout << "# RMillisecond= " << mrcps << "#" << endl;
        }
    }
    if (lcps >= 10)
    {
        cout << "#   L.CPS = " << lcps << "     #" << endl;
    }
    else
    {
        cout << "#   L.CPS = " << lcps << "      #" << endl;
    }
    if (rcps >= 10)
    {
        cout << "#   R.CPS = " << rcps << "     #" << endl;
    }
    else
    {
        cout << "#   R.CPS = " << rcps << "      #" << endl;
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
    cout << "Podaj liczbe L. CPS: "; cin >> lcps;
    cout << "Podaj liczbe R. CPS: "; cin >> rcps;
    // OBLICZANIE CPS
    if ((lcps >= 1) && (lcps <= 40) && (rcps >= 1) && (rcps <= 40))
    {
        if ((lcps >= 1) && (lcps <= 32))
        {
            mlcps = (1000 / lcps) - 5;
        }
        if ((lcps >= 33) && (lcps <= 40))
        {
            mlcps = (1000 / lcps) - 10;
        }

        if ((rcps >= 1) && (rcps <= 32))
        {
            mrcps = (1000 / rcps) - 5;
        }
        if ((rcps >= 33) && (rcps <= 40))
        {
            mrcps = (1000 / rcps) - 10;
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
    if (betamode)
    {
        cout << "####################" << endl;
        cout << "#A.C. BY GRZYBYYYYY#" << endl;
        td();
        cout << "#      CONFIG      #" << endl;
        cout << "####################" << endl;
        cout << "#[1]# BIND L.CLICK #" << endl;
        cout << "#[2]# BIND R.CLICK #" << endl;
        cout << "#[3]# SET CPS      #" << endl;
        cout << "#[4]# SET 65 CPS   #" << endl;
        cout << "#[5]# Toggle mode  #" << endl;
        cout << "#[6]# Dark Mode    #" << endl;
        cout << "#[7]# Beta Mode    #" << endl;
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
        case 5:
            TM = !TM;
            break;
        case 3:
            scps();
            Sleep(300);
            break;
        case 4:
            lcps = 65;
            mlcps = 12;
            rcps = 65;
            mrcps = 12;
            Sleep(300);
            break;
        case 7:
            if (!betamode)
            {
                betamode = !betamode;
            }
            else
            {
                betamode = !betamode;
                system("cls");
                system("color f");
                scps();
            }
            break;
        case 6:
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
        cout << "#[1]# SET CPS      #" << endl;
        cout << "#[2]# Toggle Mode  #" << endl;
        cout << "#[3]# Dark Mode    #" << endl;
        cout << "#[4]# Beta Mode    #" << endl;
        cout << "#[5]#     BACK     #" << endl;
        cout << "####################" << endl;
        cout << "Wybiesz opcje (1-5): "; cin >> mode;
        // WYBUR OPCJI
        switch (mode)
        {
        case 1:
            scps();
            Sleep(300);
            break;
        case 2:
                TM = !TM;
            break;
        case 4:
            if (!betamode)
            {
                betamode = !betamode;
            }
            else
            {
                betamode = !betamode;
                system("cls");
                system("color f");
                scps();
            }
            break;
        case 3:
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
            Sleep(mlcps);
        }
        if ((GetAsyncKeyState(VK_NUMPAD5)) && (!blc) && (!TM))
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
            Sleep(mlcps);
        }
        // RIGHT BUTTON
        if ((GetAsyncKeyState(VK_XBUTTON1)) && (brc) && (!TM))
        {
            mouse_event(MOUSEEVENTF_RIGHTDOWN, x, y, 0, 0);
            mouse_event(MOUSEEVENTF_RIGHTUP, x, y, 0, 0);
            Sleep(mrcps);
        }
        if ((GetAsyncKeyState(VK_NUMPAD4)) && (!brc) && (!TM))
        {
            mouse_event(MOUSEEVENTF_RIGHTDOWN, x, y, 0, 0);
            mouse_event(MOUSEEVENTF_RIGHTUP, x, y, 0, 0);
            Sleep(mrcps);
        }
       
        // TOGGLE ON
        // LEFT BUTTON
        if ((TM) && (GetAsyncKeyState(VK_XBUTTON2)))
        {
            LC = !LC;
            menu();
            Sleep(300);
        }
        if ((TM) && (LC))
        {
            Sleep(mlcps); 
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
            Sleep(mrcps);
            mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
        }
        
    }
}
