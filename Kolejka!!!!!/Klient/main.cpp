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

string nazwa_hosta,ip="192.168.8.120";

char s=92,c=34;

int scena=0,p=0;

void Start()
{
    cout << "Marunia-Klient" << endl;
    cout << "==============" << endl;
    Sleep(1000);
}

void tworzenie_skryptow_bat()
{
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

    system("start hostn.bat");

    //koniec tworzenie skryptu

    cout << nazwa_hosta << endl;
}

void oczekiwanie()
{
    p=0;

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

        startA.clear();
        startA.close();
        Sleep(100);

    }
}

int main(int argc, char*args[])
{
    Start();
    tworzenie_skryptow_bat();
  //  tworzenie_skryptow_vbs();
    oczekiwanie();

    if(p>0)
    {
        int x = GetSystemMetrics(SM_CXSCREEN); //pobieranie rozdzielczosci
        int y = GetSystemMetrics(SM_CYSCREEN);
        int c = y-610; //pozycja ciuchci

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

                    int pozx=0,p=0;

                    if(scena==0)
                    {
                        //scena_1

                        SDL_Surface*ciuchcia=IMG_Load("Grafika/scena/ciuchcia.bmp");
                        SDL_Surface*tlo=IMG_Load("Grafika/scena/tlo.bmp");


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

                            mar2.x = pozx;//tlo
                            mar2.y = c;
                            SDL_BlitSurface(ciuchcia,NULL,ekran,&mar2);

                            if((pozx>x-779)&&(p==0))
                            {
                                cout << "Gotowe.txt" << endl;
                                system("echo MarkoSoft > Gotowe.txt");
                                p++;
                                scena++;
                            }

                            while(SDL_PollEvent(&zdarzenie))
                            {
                                if(zdarzenie.type==SDL_QUIT)
                                {
                                    exit(0);
                                }
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

                        system("start Start.bat");
                    }

                return 0;

              }//if
        }//for ciuchci
    }



}
