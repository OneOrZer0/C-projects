#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <fstream>

using namespace std;

char s=92,c=34;

int a=0,ilosc_hostow=0,gh=0,nr_hostu[100];



string lista_A[100],g_l_h[100],ip="192.168.8.120";

void Start()
{
    cout << "Maruni-Serwer 1.0" << endl;
    cout << "-----------------" << endl;

    fstream kopiowanie;

    kopiowanie.open("kopiowanie.bat",ios::out);

    kopiowanie << "@echo off" << endl;
    kopiowanie << "Title Kopiowanie" << endl;
    kopiowanie << "if exist "<<s<<s<<ip<<s<<"Marunia"<<s<<"Dalej.txt goto usun"<< endl;
    kopiowanie << "goto CD" << endl;
    kopiowanie << ":usun" << endl;
    kopiowanie << "del "<<s<<s<<ip<<s<<"Marunia"<<s<<"Dalej.txt"<< endl;
    kopiowanie << ":CD" << endl;
    kopiowanie << "if exist hosty.txt del hosty.txt" << endl;
    kopiowanie << "del "<<s<<s<<ip<<s<<"Marunia"<<s<<"Koniec.txt"<<endl;
    kopiowanie << "xcopy "<<s<<s<<ip<<s<<"Marunia"<<s<<"hosty.txt /Y"<<endl;
    kopiowanie << "exit" << endl;

    kopiowanie.clear();
    kopiowanie.close();

    Sleep(1000);
    system("cls");
}

void lista_hostow()
{
    int p=0;

    while(p==0)
    {
        cout << "==================================" << endl;
        cout << "1.Czytanie listy dostêpnych hostow" << endl;
        cout << "==================================" << endl;

        system("start kopiowanie.bat");

        for(int m=0;m<5;m++)
        {
            Sleep(1000);
            cout << "==";
        }

        cout << endl;

        fstream hosty;

        hosty.open("hosty.txt",ios::in);

        if(hosty.good()==false)
        {
            hosty.clear();
            hosty.close();

            if(a==0) cout << "." << endl;
            if(a==1) cout << ".." << endl;
            if(a==2) cout << "..." << endl;
            if(a==3) cout << "...." << endl;
            if(a==4) cout << "....." << endl;
            a++;
            if(a==5) a=0;
        }
        else
        {
            ilosc_hostow=0;

            while(getline(hosty,lista_A[ilosc_hostow]))
            {
               cout <<  lista_A[ilosc_hostow] << endl;
                ilosc_hostow++;
            }

            hosty.clear();
            hosty.close();

            p++;
        }
        Sleep(1000);
        system("cls");

        fstream usuwanie_h;

        usuwanie_h.open("Usuwanie_h.bat",ios::out);

        usuwanie_h << "@echo off" << endl;
        usuwanie_h << "Title Usuwanie Hostow" << endl;
        usuwanie_h << "del "<<s<<s<<ip<<s<<"Marunia"<<s<<"hosty.txt"<<endl;
        usuwanie_h << "exit" << endl;

        usuwanie_h.clear();
        usuwanie_h.close();

        system("start Usuwanie_h.bat");
    }



}

void kolejka_hostow()
{
    for(int e=0;e<ilosc_hostow;e++)
    {
        nr_hostu[e]=0;
    }

    int nr;

    for(int e=0;e<ilosc_hostow;e++)
    {
        cout << "Maruni-Serwer 1.0" << endl;
        cout << "-----------------" << endl;
        cout << "==============================================" << endl;
        cout << "2.Ukladanie kolejki wykonania"<< endl;
        cout << "==============================================" << endl;

        for(int e=0;e<ilosc_hostow;e++)
            {
                cout << e+1 <<". "<<lista_A[e]<<" Miejsce: "<<nr_hostu[e]<<endl;
            }

        cout << "==============================================" << endl;
        cout << "Podaj numer i numer w kolejce dla danego hosta" << endl;
        cout << "==============================================" << endl;
        cout << "Numer hosta: ";
        cin >> nr;
        if(nr<=0||nr>ilosc_hostow)
        {
            cout << "Nie dozwolona liczba!" << endl;
            Sleep(1000);
        }
        else
        {
            cout << "Miejsce: ";
            cin >> nr_hostu[nr-1];
        }
        system("cls");

    }


}

void filtr_listy_hostow()
{

    cout << "Filtr" << endl;
    cout << "=====" << endl;

    fstream kolejka_h;

    kolejka_h.open("kolejka_h.txt",ios::out);

    for(int i=0;i<ilosc_hostow;i++)
    {
        for(int e=0;e<ilosc_hostow;e++)
        {
            if(nr_hostu[e]==i+1)
            {
               // kolejka_h << nr_hostu[e] <<". " <<lista_A[e]<<endl;
                kolejka_h<<lista_A[e]<<endl;
            }
        }
    }

    kolejka_h.clear();
    kolejka_h.close();
}

void gotowa_lista_hostow()
{
    gh=0;

    fstream gotowa_l_h;

    gotowa_l_h.open("kolejka_h.txt",ios::in);

    while(getline(gotowa_l_h,g_l_h[gh]))
    {
        cout << g_l_h[gh] << endl;
        gh++;
    }

    gotowa_l_h.clear();
    gotowa_l_h.close();

    Sleep(4000);
}

void startowanie_hostow()
{
    for(int i=0;i<gh;i++)
    {
        int p=0;

        fstream start_hostu;

        start_hostu.open("start_h.bat",ios::out);

        start_hostu << "@echo off" << endl;
        start_hostu << "Title Start_Hostu" << endl;
      //  start_hostu << "if exist "<<s<<s<<"192.168.0.7"<<s<<"Marunia"<<s<<"Dalej.txt goto utworz"<<endl;
        start_hostu << "echo MarkoSoft > "<<s<<s<<ip<<s<<"Marunia"<<s<<g_l_h[i]<<".txt"<<endl;
        start_hostu << "exit" << endl;
      //  start_hostu << ":utworz" << endl;
      //  start_hostu << "del "<<s<<s<<"192.168.0.7"<<s<<"Marunia"<<s<<"Dalej.txt"<< endl;
      //  start_hostu << "echo MarkoSoft > Dalej.txt"<< endl;
      //  start_hostu << "exit" << endl;

        start_hostu.clear();
        start_hostu.close();

        system("start start_h.bat");

        fstream czekanie;

        czekanie.open("czekanie.bat",ios::out);

        czekanie << "@echo off" << endl;
        czekanie << "Title Czekam na Dalej.txt" << endl;
        czekanie << ":start" << endl;
        czekanie << "if exist "<<s<<s<<ip<<s<<"Marunia"<<s<<"Dalej.txt goto dalej"<< endl;
        czekanie << "goto start" << endl;
        czekanie << ":dalej" << endl;
        czekanie << "del "<<s<<s<<ip<<s<<"Marunia"<<s<<"Dalej.txt"<< endl;
        czekanie << "echo MarkoSoft > Dalej.txt"<< endl;
        czekanie << "exit" << endl;

        czekanie.clear();
        czekanie.close();

        system("start czekanie.bat");

        while(p==0)
        {
            Sleep(1000);
            cout << "I dalej..." << endl;

            fstream kontrola;

            kontrola.open("Dalej.txt",ios::in);

            if(kontrola.good()==false)
            {
                kontrola.clear();
                kontrola.close();
            }
            else
            {
                kontrola.clear();
                kontrola.close();
                system("del Dalej.txt");
                p++;
            }
        }

        cout << g_l_h[i] << endl;
    }

    fstream koniec;

    koniec.open("Koniec.bat",ios::out);

    koniec << "@echo off" << endl;
    koniec << "Title Koniec" << endl;
    koniec << "echo MarkoSoft > "<<s<<s<<ip<<s<<"Marunia"<<s<<"Koniec.txt"<< endl;
    koniec << "exit" << endl;

    koniec.clear();
    koniec.close();

    system("start Koniec.bat");
}

int main()
{
    Start();
  // for(;;)
  //  {
        lista_hostow();
        kolejka_hostow();
        filtr_listy_hostow();
        gotowa_lista_hostow();
        startowanie_hostow();
  //  }


    return 0;
}
