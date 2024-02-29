#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>


using namespace std;

string logo="MarkWare-MarkoBook",napis="Hej",nazwa_pc,czat[1000],nick;

char slesz=92,cudz=34;

int nr,ods,pusc=0;

void wpisz()
{
    fstream w_danych;

    w_danych.open("w_dane.bat",ios::out);

    w_danych << "@echo off" << endl;
    w_danych << "echo "<<nick<<": "<<napis<<" >> "<<slesz<<slesz<<nazwa_pc<<slesz<<"msbook"<<slesz<<"rozmowa.txt"<<endl;
    w_danych << "exit" <<endl;

    w_danych.clear();
    w_danych.close();

    system("start niew_w.vbs");
}

void poczatek()
{

    char odp;
    int opusc=0;

            while(opusc<1)
            {
                system("cls");
                cout << "Czy wygenerowac skrypt serwera rozmowy?" << endl;
                cout << "t/n" << endl;
                cin >> odp;
                switch(odp)
                {
                    case't':
                    {
                        cout << "PAMIERAJ URUCHOM Z PRAWAMI ADMINISTRATORA!!!" << endl;

                        fstream start_s;

                        start_s.open("start_s.bat",ios::out);

                        start_s << "@echo off" << endl;
                        start_s << "mkdir c:"<<slesz<<"msbook"<<endl;
                        start_s << "net share msbook=c:"<<slesz<<"msbook"<<"/GRANT:wszyscy,FULL"<<endl;
                        start_s << "exit" << endl;

                        start_s.clear();
                        start_s.close();
                        opusc=1;

                        Sleep(2000);

                        system("cls");
                    }
                    break;

                    case'n':
                    {
                        cout << "OK" << endl;
                        Sleep(1000);
                        system("cls");
                        opusc=1;
                    }
                    break;

                    default: break;


                }
            }


            fstream w_laduje;

            w_laduje.open("niew_w.vbs",ios::out);

            w_laduje << "Set WshShell = CreateObject("<<cudz<<"WScript.Shell"<<cudz<<")"<< endl;
            w_laduje << "WshShell.Run chr(34) & "<<cudz<<"w_dane.bat"<<cudz<<" & Chr(34), 0"<< endl;
            w_laduje << "Set WshShell = Nothing" << endl;

            w_laduje.clear();
            w_laduje.close();

            fstream v_laduje;

            v_laduje.open("niew_l.vbs",ios::out);

            v_laduje << "Set WshShell = CreateObject("<<cudz<<"WScript.Shell"<<cudz<<")"<< endl;
            v_laduje << "WshShell.Run chr(34) & "<<cudz<<"l_skrypt.bat"<<cudz<<" & Chr(34), 0"<< endl;
            v_laduje << "Set WshShell = Nothing" << endl;

            v_laduje.clear();
            v_laduje.close();


}

void laduje()
{
    fstream l_laduje;

    ods++;

    //cout << "generuje" << endl;
    //cout << "laduje"<< ods << endl;

    l_laduje.open("l_skrypt.bat",ios::out);

    l_laduje << "@echo off" << endl;
    l_laduje << "xcopy /Y "<<slesz<<slesz<<nazwa_pc<<slesz<<"msbook"<<slesz<<"rozmowa.txt " << endl;
    l_laduje << "exit" << endl;

    l_laduje.clear();
    l_laduje.close();

    system("start niew_l.vbs");

    Sleep(2000);

    fstream l_dane;
    string linia;
    int nr_lini=0;

    l_dane.open("rozmowa.txt",ios::in);

    if(l_dane.good()==false)
    {
        cout << "Nie dziala kurwa" << endl;
    }

    while(getline(l_dane,linia))
    {
        czat[nr_lini]=linia;
        nr_lini++;
    }

    nr=nr_lini;

    l_dane.clear();
    l_dane.close();


}
void wyswietla()
{
    for(int i=0;i<nr;i++)
    {
        cout << czat[i] << endl;
    }
}

int main()
{
    poczatek();
    for(int i=0;i<18;i++)
    {
        cout << logo[i];
        Sleep(100);
    }
    cout << endl;
    for(int i=0;i<19;i++)
    {
        cout << "=";
        Sleep(100);
    }
    cout << endl;
    cout << "Podaj nazwe komputera glownego: ";
    cin >> nazwa_pc;
    cout << "A jak sie zwiesz smialku : ";
    cin >> nick;
    cout << "Pamietaj o kulturze cipo!";
    getline(cin,napis);
    Sleep(2000);
    for(;;)
    {

        laduje();
        system("cls");
        wyswietla();
        Sleep(2000);
        //if(GetAsyncKeyState(VK_SHIFT))
        if(GetAsyncKeyState(VK_CONTROL))
        {
            cout << "Ty: ";
            getline(cin,napis);
           // {
               wpisz();
           // }
          //  else
            //{

           // }
           // pusc=1;
        }

    }
    return 0;
}
