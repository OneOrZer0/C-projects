#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <windows.h>
#include <fstream>
#include <cstdlib>


using namespace std;

SDL_Rect mar1;
SDL_Rect mar2;
SDL_Rect mar3;
SDL_Rect mar4;
SDL_Rect mar5;
SDL_Rect mar6;

string nazwa_hosta,ip="192.168.0.100";

char s=92,c=34;

int scena=0,opcja;

void Start()
{
    cout << "Marunia-Klient" << endl;
    cout << "==============" << endl;

    int p=0;

    system("start instrukcja.vbs");

    while(p==0)
    {
        fstream czekaj;

        czekaj.open("letsgo.txt",ios::in);

        if(czekaj.good()==true)
        {
            p++;
            czekaj.clear();
            czekaj.close();
            system("del letsgo.txt");
        }
        else
        {
            czekaj.clear();
            czekaj.close();
        }

        Sleep(50);
    }


}

void tworzenie_skryptow_vbs()
{
    fstream VBSa;

    VBSa.open("kopiuj_k.vbs",ios::out);

    VBSa <<  "Set WshShell = CreateObject("<<c<<"WScript.Shell"<<c<<") "<< endl;
    VBSa << "WshShell.Run chr(34) & "<<c<<"kopiuj_k.bat"<<c<<" & Chr(34), 0"<<endl;
    VBSa << "Set WshShell = Nothing" << endl;

    VBSa.clear();
    VBSa.close();

    fstream VBSb;

    VBSb.open("hostn.vbs",ios::out);

    VBSb <<  "Set WshShell = CreateObject("<<c<<"WScript.Shell"<<c<<") "<< endl;
    VBSb << "WshShell.Run chr(34) & "<<c<<"hostn.bat"<<c<<" & Chr(34), 0"<<endl;
    VBSb << "Set WshShell = Nothing" << endl;

    VBSb.clear();
    VBSb.close();

    fstream VBSc;

    VBSc.open("start.vbs",ios::out);

    VBSc <<  "Set WshShell = CreateObject("<<c<<"WScript.Shell"<<c<<") "<< endl;
    VBSc << "WshShell.Run chr(34) & "<<c<<"start.bat"<<c<<" & Chr(34), 0"<<endl;
    VBSc << "Set WshShell = Nothing" << endl;

    VBSc.clear();
    VBSc.close();

    fstream VBSd;

    VBSa.open("instrukcja.vbs",ios::out);

    VBSa <<  "Set WshShell = CreateObject("<<c<<"WScript.Shell"<<c<<") "<< endl;
    VBSa << "WshShell.Run chr(34) & "<<c<<"instrukcja.bat"<<c<<" & Chr(34), 0"<<endl;
    VBSa << "Set WshShell = Nothing" << endl;

    VBSa.clear();
    VBSa.close();

}

void tworzenie_skryptow_bat()
{

    fstream instrukcja;

    instrukcja.open("instrukcja.bat",ios::out);

    instrukcja << "@echo off" << endl;
    instrukcja << "Title Instrukcja MW" << endl;
    instrukcja << ":Start" << endl;
    instrukcja << "if exist "<<s<<s<<ip<<s<<"Marunia"<<s<<"kolejka.txt goto kolejka"<<endl;
    instrukcja << "if exist "<<s<<s<<ip<<s<<"Marunia"<<s<<"off_pc.txt goto off_pc"<<endl;
    instrukcja << "timeout /t 1" << endl;
    instrukcja << "goto Start" << endl;
    instrukcja << ":kolejka" << endl;
    instrukcja << "echo MarkoWare > kolejka.txt" << endl;
    instrukcja << "goto exit" << endl;
    instrukcja << ":off_pc" << endl;
    instrukcja << "shutdown /s /t 0" << endl;
    instrukcja << "goto exit" << endl;
    instrukcja << ":exit" << endl;
    instrukcja << "echo DALEJ! > letsgo.txt" << endl;
    instrukcja << "exit" << endl;

    instrukcja.clear();
    instrukcja.close();


    //Skrypt kopiowania konca.txt

    fstream kopiuj_k;

    kopiuj_k.open("kopiuj_k.bat",ios::out);

    kopiuj_k << "@echo off" << endl;
    kopiuj_k << "Title Kopiuje Koniec" << endl;
    kopiuj_k << "xcopy "<<s<<s<<ip<<s<<"Marunia"<<s<<"koniec.txt /Y"<<endl;
    kopiuj_k << "exit" << endl;

    kopiuj_k.clear();
    kopiuj_k.close();

    //koniec skryptu kopiowania konca

    system("hostname > hostn.txt");

    fstream hostname;

    hostname.open("hostn.txt",ios::in);

    getline(hostname,nazwa_hosta);

    hostname.clear();
    hostname.close();

    hostname.open("hostn.bat",ios::out);

    //Tworzenie skryptu

    hostname << "@echo off" << endl;
    hostname << "Title Klient" << endl;
    hostname << "hostname >> "<<s<<s<<ip<<s<<"Marunia"<<s<<"hosty.txt"<< endl;
    hostname << ":Start" << endl;
    hostname << "if exist "<<s<<s<<ip<<s<<"Marunia"<<s<<nazwa_hosta<<".txt goto Istnieje"<< endl;
    hostname << "goto Start" << endl;
    hostname << ":Istnieje" << endl;
    hostname << "del "<<s<<s<<ip<<s<<"Marunia"<<s<<nazwa_hosta<<".txt"<< endl;
    hostname << "echo MarkoSoft > Start.txt"<< endl;
    hostname << ":StartA" << endl;
    hostname << "if exist Gotowe.txt goto Dalej" << endl;
    hostname << "goto StartA" << endl;
    hostname << ":Dalej" << endl;
    hostname << "del Gotowe.txt" << endl;
    hostname << "echo > "<<s<<s<<ip<<s<<"Marunia"<<s<<"Dalej.txt"<< endl;
    hostname << "exit" << endl;

    hostname.clear();
    hostname.close();

    fstream k_start;

    k_start.open("k_start.bat",ios::out);

    k_start << "@echo off" << endl;
    k_start << "Title MarkWare" << endl;
    k_start << "if exist "<<s<<s<<ip<<s<<"Marunia"<<s<<nazwa_hosta<<".txt goto cos"<< endl;
    k_start << "goto exit" << endl;
    k_start << ":cos" << endl;
    k_start << "del "<<s<<s<<ip<<s<<"Marunia"<<s<<nazwa_hosta<<".txt"<< endl;
    k_start << "echo dzialaj > k_start.txt" << endl;
    k_start << ":exit" << endl;
    k_start << "exit" << endl;

    k_start.close();

    system("start hostn.vbs");

    //koniec tworzenie skryptu

    cout << nazwa_hosta << endl;
}

void oczekiwanie()
{
    int p=0;

    cout << "Oczekiwanie" << endl;

    while(p==0)
    {
        cout << "i start..." << endl;

        fstream startA;

        startA.open("Start.txt",ios::in);

        if(startA.good()==false)
        {
            cout << "Nie dziala" << endl;
            startA.clear();
            startA.close();
        }
        else
        {
            cout << "Dziala" << endl;
            startA.clear();
            startA.close();
            system("del Start.txt");
            p++;
        }

    }
}
void wykonaj()
{
    int p2 = 0;

    while(p2==0)
    {
        int p = 0;

        system("start k_start.bat");
        Sleep(1000);

        fstream komp;

        komp.open("k_start.txt",ios::in);

        if(komp.good()==true)
        {
            //system("start instrukcja.bat");
            komp.close();
           // system("del k_start.txt");
            p2++;

            while(p==0)
            {
                system("start instrukcja.bat");
                Sleep(1000);

                fstream akcja;

                akcja.open("kolejka.txt",ios::in);

                if(akcja.good()==true)
                {
                    opcja = 1;
                    akcja.close();
                    p++;
                }
                else
                {
                    akcja.close();
                }

                fstream akcja2;

                akcja2.open("sleep.txt",ios::in);

                if(akcja2.good()==true)
                {
                    opcja = 2;
                    akcja2.close();
                    p++;
                }
                else
                {
                    akcja2.close();
                }
            }//while
        }//if
        else
        {
            komp.close();
        }
    }//while
}

int main(int argc, char*args[])
{
   // HWND kons = FindWindowA( "ConsoleWindowClass", NULL );
   // ShowWindow( kons, SW_HIDE );

    tworzenie_skryptow_vbs();
    tworzenie_skryptow_bat();
  //  Start();
  //  tworzenie_skryptow_vbs();
  //  oczekiwanie(); //nie potrzebne

    //--------------------------------Wybor instrukcji do wykonania-------------------------------

    wykonaj();

    //--------------------------------------------------------------------------------------------

    if(opcja == 1)
    {
        cout << "Go Go power rengers" << endl;
        int x = GetSystemMetrics(SM_CXSCREEN); //pobieranie rozdzielczosci
        int y = GetSystemMetrics(SM_CYSCREEN);
        int ce = y-610; //pozycja ciuchci
        int cw = y-444; //pozycja wagonu

        SDL_Init(SDL_INIT_EVERYTHING);

        SDL_Event zdarzenie;

        SDL_Window*okno;
        SDL_Surface*ekran;

        okno = SDL_CreateWindow("Kolejka",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,x,y,SDL_WINDOW_FULLSCREEN_DESKTOP); //SDL_WINDOW_FULLSCREEN_DESKTOP
        ekran = SDL_GetWindowSurface(okno);

        int p=0;

        cout << "Oczekiwanie" << endl;

        SDL_Surface*tlo2=IMG_Load("Grafika/scena/tlo.bmp");

        while(p==0)
        {

            SDL_UpdateWindowSurface(okno);
            SDL_Delay(16.666666);

            while(SDL_PollEvent(&zdarzenie))
            {
                if(zdarzenie.type==SDL_QUIT)
                {
                    exit(0);
                }
            }

            cout << "i start..." << endl;

            fstream startA;

            startA.open("Start.txt",ios::in);

            if(startA.good()==false)
            {
                mar1.x = 0;//tlo
                mar1.y = 0;
                mar1.h = y;
                mar1.w = x;
                SDL_BlitScaled(tlo2,NULL,ekran,&mar1);

                cout << "Nie dziala" << endl;
                startA.clear();
                startA.close();
            }
            else
            {
                cout << "Dziala" << endl;
                startA.clear();
                startA.close();
                system("del Start.txt");
                SDL_FreeSurface(tlo2);
                p++;
            }

        }

        int d=0;

        for(;;)
        {
            if(d==0)
              {

                    int pozx=-800,p=0;

                    if(scena==0)
                    {
                        //scena_1

                        SDL_Surface*ciuchcia=IMG_Load("Grafika/scena/ciuchcia.bmp");
                        SDL_Surface*tlo=IMG_Load("Grafika/scena/tlo.bmp");
                        SDL_Surface*wagon_a=IMG_Load("Grafika/scena/wagon_a.bmp");
                        SDL_Surface*wagon_b=IMG_Load("Grafika/scena/wagon_b.bmp");
                        SDL_Surface*wagon_c=IMG_Load("Grafika/scena/wagon_c.bmp");
                        SDL_Surface*wagon_d=IMG_Load("Grafika/scena/wagon_d.bmp");


                        while(scena==0)
                        {
                          //  cout << "X: "<< pozx << endl;
                          //  cout << "Y: "<< pozy << endl;
                            SDL_UpdateWindowSurface(okno);
                            SDL_Delay(16.666666);


                            if(GetAsyncKeyState(VK_ESCAPE))
                            {
                                exit(0);
                            }

                            mar1.x = 0;//tlo
                            mar1.y = 0;
                            mar1.h = y;
                            mar1.w = x;
                            SDL_BlitScaled(tlo,NULL,ekran,&mar1);

                            mar2.x = pozx;
                            mar2.y = ce;
                            SDL_BlitSurface(ciuchcia,NULL,ekran,&mar2);
    //-------------------------------------------------------Wagony
                            mar3.x = pozx-774;
                            mar3.y = cw;
                            SDL_BlitSurface(wagon_a,NULL,ekran,&mar3);

                            mar4.x = pozx-774*2;
                            mar4.y = cw;
                            SDL_BlitSurface(wagon_b,NULL,ekran,&mar4);

                            mar5.x = pozx-774*3;
                            mar5.y = cw;
                            SDL_BlitSurface(wagon_c,NULL,ekran,&mar5);

                            mar6.x = pozx-774*4;
                            mar6.y = cw;
                            SDL_BlitSurface(wagon_d,NULL,ekran,&mar6);
    //-------------------------------------------------------Wagony

                            if((pozx>x-779)&&(p==0))
                            {
                                cout << "Gotowe.txt" << endl;
                                system("echo MarkoSoft > Gotowe.txt");
                                p++;
                               // scena++;
                            }
                     //---------------------------------AKTUALNE ZMIANY
                            if((pozx>x)&&(p==1)) // KONIEC CIUCHCI
                            {
                                SDL_FreeSurface(ciuchcia);
                                p++;
                            }
                            if((pozx-774>x)&&(p==2)) // KONIEC Wagonu_a
                            {
                                SDL_FreeSurface(wagon_a);
                                p++;
                            }
                            if((pozx-774*2>x)&&(p==3)) // KONIEC Wagonu_b
                            {
                                SDL_FreeSurface(wagon_b);
                                p++;
                                //scena++;
                            }
                            if((pozx-774*3>x)&&(p==4)) // KONIEC Wagonu_c
                            {
                                SDL_FreeSurface(wagon_c);
                                p++;
                                //scena++;
                            }
                            if((pozx-774*4>x)&&(p==5)) // KONIEC Wagonu_d
                            {
                                SDL_FreeSurface(wagon_d);
                                p++;
                                //scena++;
                            }
                            if(p==6)
                            {
                                while(p==6)
                                {

                                    SDL_UpdateWindowSurface(okno);
                                    SDL_Delay(16.666666);

                                    mar1.x = 0;//tlo
                                    mar1.y = 0;
                                    mar1.h = y;
                                    mar1.w = x;
                                    SDL_BlitScaled(tlo,NULL,ekran,&mar1);



                                    Sleep(500);

                                    system("start kopiuj_k.vbs");

                                    fstream koniec;

                                    koniec.open("koniec.txt",ios::in);

                                    if(koniec.good()==true)
                                    {
                                        p++;
                                        scena++;
                                        koniec.clear();
                                        koniec.close();
                                        system("del koniec.txt");
                                    }
                                    else
                                    {
                                        koniec.clear();
                                        koniec.close();
                                    }
                                }

                                    //otwieranie KONIEC.TXT
                                    //scena++;
                            }
                    //---------------------------------AKTUALNE ZMIANY
                            while(SDL_PollEvent(&zdarzenie))
                            {
                                if(zdarzenie.type==SDL_QUIT)
                                {
                                    exit(0);
                                }
                            }
                            if(GetAsyncKeyState(VK_ESCAPE))
                            {
                                exit(0);
                            }

                            pozx = pozx + 10;
                        }//while

                        SDL_FreeSurface(tlo);
                        SDL_FreeSurface(ciuchcia);

                        fstream starter;

                        starter.open("Start.bat",ios::out);

                        starter << "@echo off" << endl;
                        starter << "Title Starter" << endl;
                        starter << "timeout 5" << endl;
                        starter << "Start Klient.exe" << endl;
                        starter << "exit" << endl;

                        starter.clear();
                        starter.close();

                        system("start Start.vbs");
                    }



              }

              return 0;

        }



    }
    if(opcja == 2)
    {
                  system("shutdown /h /t 0");
    }


    //for ciuchci

}
