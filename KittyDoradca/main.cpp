#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <windows.h>

using namespace std;

int scena=0,posx=0,posy=550,up,down,pozt,ruch,wyjscie=0;

SDL_Event zdarzenie;

SDL_Window*okno;
SDL_Surface*ekran;

SDL_Rect ob1;
SDL_Rect ob2;
SDL_Rect ob3;
SDL_Rect ob4;
SDL_Rect ob5;
SDL_Rect ob6;
SDL_Rect ob7;



int main(int argc, char*args[])
{

    SDL_Init(SDL_INIT_EVERYTHING);

    okno = SDL_CreateWindow("XXX",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,600,424,NULL);

    ekran = SDL_GetWindowSurface(okno);

    for(;;)
    {
        //£ADOWANIE OBRAZÓW DO PAMIÊCI RAM

            SDL_Surface*a=IMG_Load("Grafika/Przyciski/1/1.bmp");
            SDL_Surface*b=IMG_Load("Grafika/Przyciski/1/2.bmp");
            SDL_Surface*c=IMG_Load("Grafika/Przyciski/1/3.bmp");
            SDL_Surface*d=IMG_Load("Grafika/Przyciski/1/4.bmp");
            SDL_Surface*e=IMG_Load("Grafika/Przyciski/1/5.bmp");

            SDL_Surface*a1=IMG_Load("Grafika/Przyciski/2/1b.bmp");
            SDL_Surface*b1=IMG_Load("Grafika/Przyciski/2/2b.bmp");
            SDL_Surface*c1=IMG_Load("Grafika/Przyciski/2/3b.bmp");
            SDL_Surface*d1=IMG_Load("Grafika/Przyciski/2/4b.bmp");
            SDL_Surface*e1=IMG_Load("Grafika/Przyciski/2/5b.bmp");

            SDL_Surface*a2=IMG_Load("Grafika/Przyciski/3/1a.bmp");
            SDL_Surface*b2=IMG_Load("Grafika/Przyciski/3/2a.bmp");
            SDL_Surface*c2=IMG_Load("Grafika/Przyciski/3/3a.bmp");
            SDL_Surface*d2=IMG_Load("Grafika/Przyciski/3/4a.bmp");
            SDL_Surface*e2=IMG_Load("Grafika/Przyciski/3/5a.bmp");

            SDL_Surface*obraz_tla=IMG_Load("Grafika/tlo.bmp");
            SDL_Surface*logo=IMG_Load("Grafika/logo.bmp");
            SDL_Surface*logoa=IMG_Load("Grafika/logoa.bmp");
            SDL_Surface*logob=IMG_Load("Grafika/logob.bmp");
            SDL_Surface*logoc=IMG_Load("Grafika/logoc.bmp");

            if(scena==0)
            {
                while(scena==0)
                {

                    while(SDL_PollEvent(&zdarzenie))
                    {
                        if(zdarzenie.type==SDL_QUIT)
                        {
                            exit(0);
                        }
                    }

                    ob1.x = 0;
                    ob1.y = 0;
                    SDL_BlitSurface(obraz_tla,NULL,ekran,&ob1);

                    ob1.x = 0;
                    ob1.y = 0;
                    SDL_BlitSurface(logo,NULL,ekran,&ob1);

                    SDL_UpdateWindowSurface(okno);

                    Sleep(4000);

                    scena=1;

                }

            }

            if(scena==1)
            {
                while(scena==1)
                {

                    SDL_Delay(100);

                    while(SDL_PollEvent(&zdarzenie))
                    {
                        if(zdarzenie.type==SDL_QUIT)
                        {
                            exit(0);
                        }
                    }

                    ob1.x = 0;
                    ob1.y = 0;
                    SDL_BlitSurface(obraz_tla,NULL,ekran,&ob1);

                    ob7.x = 464;
                    ob7.y = 20;
                    SDL_BlitSurface(logoa,NULL,ekran,&ob7);

                    if(GetAsyncKeyState(VK_DOWN))
                    {
                        ruch++;
                        if(ruch>5)
                        {
                            ruch=5;
                        }
                        ob7.x = 464;
                        ob7.y = 20;
                        SDL_BlitSurface(logob,NULL,ekran,&ob7);
                    }

                    if(GetAsyncKeyState(VK_UP))
                    {
                        ruch--;
                        if(ruch<1)
                        {
                            ruch=1;
                        }
                        ob7.x = 464;
                        ob7.y = 20;
                        SDL_BlitSurface(logoc,NULL,ekran,&ob7);
                    }

                    if(ruch!=1)
                    {
                        ob2.y = 20;
                        SDL_BlitSurface(a,NULL,ekran,&ob2);
                    }

                    if(ruch!=2)
                    {
                        ob3.y = 88;
                        SDL_BlitSurface(b,NULL,ekran,&ob3);
                    }

                    if(ruch!=3)
                    {
                        ob4.y = 156;
                        SDL_BlitSurface(c,NULL,ekran,&ob4);
                    }

                    if(ruch!=4)
                    {
                        ob5.y = 224;
                        SDL_BlitSurface(d,NULL,ekran,&ob5);
                    }

                    if(ruch!=5)
                    {
                        ob6.y = 292;
                        SDL_BlitSurface(e,NULL,ekran,&ob6);
                    }

                    //-----------------------kliknięte-----------------------

                    if(ruch==1)
                    {
                        ob2.y = 20;
                        SDL_BlitSurface(a1,NULL,ekran,&ob2);

                        if(GetAsyncKeyState(VK_RETURN))
                        {
                            ruch=ruch+10;
                        }
                    }

                    if(ruch==2)
                    {
                        ob3.y = 88;
                        SDL_BlitSurface(b1,NULL,ekran,&ob3);

                        if(GetAsyncKeyState(VK_RETURN))
                        {
                            ruch=ruch+10;
                        }
                    }

                    if(ruch==3)
                    {
                        ob4.y = 156;
                        SDL_BlitSurface(c1,NULL,ekran,&ob4);

                        if(GetAsyncKeyState(VK_RETURN))
                        {
                            ruch=ruch+10;
                        }
                    }

                    if(ruch==4)
                    {
                        ob5.y = 224;
                        SDL_BlitSurface(d1,NULL,ekran,&ob5);

                        if(GetAsyncKeyState(VK_RETURN))
                        {
                            ruch=ruch+10;
                        }
                    }

                    if(ruch==5)
                    {
                        ob6.y = 292;
                        SDL_BlitSurface(e1,NULL,ekran,&ob6);

                        if(GetAsyncKeyState(VK_RETURN))
                        {
                            ruch=15;
                        }
                    }

                    //-------------------------------klikniecie---------------------

                    if(ruch==11)
                    {
                        ob2.y = 20;
                        SDL_BlitSurface(a2,NULL,ekran,&ob2);

                        ruch=1;

                        SDL_UpdateWindowSurface(okno);
                        Sleep(500);
                        system("start https://allegro.pl/gigabyte-ga-x79-ud3-lga2011-ddr3-warszawa-sklep-i7301394873.html");
                    }

                    if(ruch==12)
                    {
                        ob3.y = 88;
                        SDL_BlitSurface(b2,NULL,ekran,&ob3);

                        ruch=2;

                        SDL_UpdateWindowSurface(okno);
                        Sleep(500);
                        system("start https://www.olx.pl/oferta/plyta-glowna-asus-p9x79-socket-lga-2011-CID99-IDwoZhf.html#1ebe315758");
                    }

                    if(ruch==13)
                    {
                        ob4.y = 156;
                        SDL_BlitSurface(c2,NULL,ekran,&ob4);

                        ruch=3;

                        SDL_UpdateWindowSurface(okno);
                        Sleep(500);
                        system("start https://www.olx.pl/oferta/asus-p9x79-plyta-glowna-lga-2011-CID99-IDwoo4p.html#1ebe315758");
                    }

                    if(ruch==14)
                    {
                        ob5.y = 224;
                        SDL_BlitSurface(d2,NULL,ekran,&ob5);

                        ruch=4;
                    }

                    if(ruch==15)
                    {
                        ob6.y = 292;
                        SDL_BlitSurface(e2,NULL,ekran,&ob6);

                        ruch=5;

                        SDL_UpdateWindowSurface(okno);

                        SDL_FreeSurface(obraz_tla);
                        SDL_FreeSurface(logo);
                        SDL_FreeSurface(logoa);
                        SDL_FreeSurface(logob);
                        SDL_FreeSurface(logoc);
                        SDL_FreeSurface(a);
                        SDL_FreeSurface(b);
                        SDL_FreeSurface(c);
                        SDL_FreeSurface(d);
                        SDL_FreeSurface(e);
                        SDL_FreeSurface(a1);
                        SDL_FreeSurface(b1);
                        SDL_FreeSurface(c1);
                        SDL_FreeSurface(d1);
                        SDL_FreeSurface(e1);
                        SDL_FreeSurface(a2);
                        SDL_FreeSurface(b2);
                        SDL_FreeSurface(c2);
                        SDL_FreeSurface(d2);
                        SDL_FreeSurface(e2);

                        exit(0);
                    }

                    SDL_UpdateWindowSurface(okno);

                }

            }

            //USÓWANIE Z PAMIÊCI RAM OBRAZÓW

            SDL_FreeSurface(obraz_tla);
            SDL_FreeSurface(logo);
            SDL_FreeSurface(logoa);
            SDL_FreeSurface(logob);
            SDL_FreeSurface(logoc);
            SDL_FreeSurface(a);
            SDL_FreeSurface(b);
            SDL_FreeSurface(c);
            SDL_FreeSurface(d);
            SDL_FreeSurface(e);
            SDL_FreeSurface(a1);
            SDL_FreeSurface(b1);
            SDL_FreeSurface(c1);
            SDL_FreeSurface(d1);
            SDL_FreeSurface(e1);
            SDL_FreeSurface(a2);
            SDL_FreeSurface(b2);
            SDL_FreeSurface(c2);
            SDL_FreeSurface(d2);
            SDL_FreeSurface(e2);

    }

    return 0;
}
