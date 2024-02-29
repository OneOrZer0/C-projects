#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <windows.h>


using namespace std;

int scena,pozx,pozy=620,poz1y=2000,i=1,petla_l,petla_r,l,r,mlp,poz2x=850,poz2y=618;
char znak_l,znak_r;

void lad()
{

}

void usuwanie_obrazow()
{

}

SDL_Rect mar1;
SDL_Rect mar2;
SDL_Rect mar3;
SDL_Rect mar4;
SDL_Rect mar5;
SDL_Rect mar6;

int main(int argc, char*args[])
{

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Event zdarzenie;

    SDL_Window*okno;
    SDL_Surface*ekran;

    okno = SDL_CreateWindow("Mark",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1680,1050,SDL_WINDOW_FULLSCREEN_DESKTOP); //SDL_WINDOW_FULLSCREEN_DESKTOP
    ekran = SDL_GetWindowSurface(okno);                                        // 1680,1050


    for(;;)
    {
        if(scena==0)
        {
            //scena_1
                SDL_Surface*tlo=IMG_Load("Grafika/scena/tlo.bmp");
                SDL_Surface*podloga=IMG_Load("Grafika/scena/podloga.bmp");
                SDL_Surface*bluescreen=IMG_Load("Grafika/scena/BS.bmp");

            //Marla lewo
                SDL_Surface*m_l_1=IMG_Load("Grafika/Marla_l/1.bmp");
                SDL_Surface*m_l_2=IMG_Load("Grafika/Marla_l/2.bmp");
                SDL_Surface*m_l_3=IMG_Load("Grafika/Marla_l/3.bmp");
                SDL_Surface*m_l_4=IMG_Load("Grafika/Marla_l/4.bmp");
                SDL_Surface*m_l_5=IMG_Load("Grafika/Marla_l/5.bmp");
                SDL_Surface*m_l_6=IMG_Load("Grafika/Marla_l/6.bmp");
                SDL_Surface*m_l_7=IMG_Load("Grafika/Marla_l/7.bmp");
                SDL_Surface*m_l_8=IMG_Load("Grafika/Marla_l/8.bmp");
                SDL_Surface*m_l_9=IMG_Load("Grafika/Marla_l/9.bmp");
                SDL_Surface*m_l_10=IMG_Load("Grafika/Marla_l/10.bmp");
                SDL_Surface*m_l_11=IMG_Load("Grafika/Marla_l/11.bmp");
                SDL_Surface*m_l_12=IMG_Load("Grafika/Marla_l/12.bmp");
                SDL_Surface*m_l_13=IMG_Load("Grafika/Marla_l/13.bmp");

            //Marla prawo
                SDL_Surface*m_r_1=IMG_Load("Grafika/Marla_r/1.bmp");
                SDL_Surface*m_r_2=IMG_Load("Grafika/Marla_r/2.bmp");
                SDL_Surface*m_r_3=IMG_Load("Grafika/Marla_r/3.bmp");
                SDL_Surface*m_r_4=IMG_Load("Grafika/Marla_r/4.bmp");
                SDL_Surface*m_r_5=IMG_Load("Grafika/Marla_r/5.bmp");
                SDL_Surface*m_r_6=IMG_Load("Grafika/Marla_r/6.bmp");
                SDL_Surface*m_r_7=IMG_Load("Grafika/Marla_r/7.bmp");
                SDL_Surface*m_r_8=IMG_Load("Grafika/Marla_r/8.bmp");
                SDL_Surface*m_r_9=IMG_Load("Grafika/Marla_r/9.bmp");
                SDL_Surface*m_r_10=IMG_Load("Grafika/Marla_r/10.bmp");
                SDL_Surface*m_r_11=IMG_Load("Grafika/Marla_r/11.bmp");
                SDL_Surface*m_r_12=IMG_Load("Grafika/Marla_r/12.bmp");
                SDL_Surface*m_r_13=IMG_Load("Grafika/Marla_r/13.bmp");

            //Szynek Mistrz

            //Okno
                SDL_Surface*window_1=IMG_Load("Grafika/scena/window_1.bmp");



            while(scena==0)
            {
                cout << "X: "<< pozx << endl;
                cout << "Y: "<< pozy << endl;
                SDL_UpdateWindowSurface(okno);
                SDL_Delay(16.666666);


                if(GetAsyncKeyState(VK_ESCAPE))
                {
                    exit(0);
                }
                if(GetAsyncKeyState(VK_LEFT))
                {
                    pozx=pozx-5;
                    l=1;
                    mlp=0;
                }
                if(GetAsyncKeyState(VK_RIGHT))
                {
                   pozx=pozx+5;
                   r=1;
                   mlp=1;
                }
                if(GetAsyncKeyState(VK_UP))
                {
                   pozy=pozy-5;
                }
                if(GetAsyncKeyState(VK_DOWN))
                {
                   pozy=pozy+5;
                }

                mar1.x = 0;//tlo
                mar1.y = 0;
                SDL_BlitSurface(tlo,NULL,ekran,&mar1);

                //100;

                if(pozx>840&&pozy>560) // Okno z szynkiem
                {
                    if(poz2y>100)
                    {
                        poz2y=poz2y-20;
                    }

                   // SDL_BlitSurface(window_1,NULL,ekran,&mar4);
                }

                    mar4.x = poz2x;//850;
                    mar4.y = poz2y;
                    SDL_BlitSurface(window_1,NULL,ekran,&mar4);

                if(pozx<840||pozy<560)
                {
                    if(poz2y<618)
                    {
                        poz2y=poz2y+20;
                    }
                   // mar4.x = poz2x;//850;
                   // mar4.y = poz2y;
                   // SDL_BlitSurface(window_1,NULL,ekran,&mar4);
                }

                mar2.x = 0;//podloga
                mar2.y = 618;
                SDL_BlitSurface(podloga,NULL,ekran,&mar2);

                mar3.x = pozx;//postac
                mar3.y = pozy;

                if(l==1)
                {
                    petla_l++;
                    if(petla_l==1) znak_l='l';
                    if(petla_l==1*2) znak_l='k';
                    if(petla_l==1*3) znak_l='j';
                    if(petla_l==1*4) znak_l='i';
                    if(petla_l==1*5) znak_l='h';
                    if(petla_l==1*6) znak_l='g';
                    if(petla_l==1*7) znak_l='f';
                    if(petla_l==1*8) znak_l='e';
                    if(petla_l==1*9) znak_l='d';
                    if(petla_l==1*10) znak_l='c';
                    if(petla_l==1*11) znak_l='b';
                    if(petla_l==1*12) znak_l='a';
                    if(petla_l==12) petla_l=0;

                    switch(znak_l)
                    {
                        case'a':
                        {
                            SDL_BlitSurface(m_l_1,NULL,ekran,&mar3);
                        }
                        break;
                        case'b':
                        {
                            SDL_BlitSurface(m_l_2,NULL,ekran,&mar3);
                        }
                        break;
                        case'c':
                        {
                            SDL_BlitSurface(m_l_3,NULL,ekran,&mar3);
                        }
                        break;
                        case'd':
                        {
                            SDL_BlitSurface(m_l_4,NULL,ekran,&mar3);
                        }
                        break;
                        case'e':
                        {
                            SDL_BlitSurface(m_l_5,NULL,ekran,&mar3);
                        }
                        break;
                        case'f':
                        {
                            SDL_BlitSurface(m_l_6,NULL,ekran,&mar3);
                        }
                        break;
                        case'g':
                        {
                            SDL_BlitSurface(m_l_7,NULL,ekran,&mar3);
                        }
                        break;
                        case'h':
                        {
                            SDL_BlitSurface(m_l_8,NULL,ekran,&mar3);
                        }
                        break;
                        case'i':
                        {
                            SDL_BlitSurface(m_l_9,NULL,ekran,&mar3);
                        }
                        break;
                        case'j':
                        {
                            SDL_BlitSurface(m_l_10,NULL,ekran,&mar3);
                        }
                        break;
                        case'k':
                        {
                            SDL_BlitSurface(m_l_11,NULL,ekran,&mar3);
                        }
                        break;
                        case'l':
                        {
                            SDL_BlitSurface(m_l_12,NULL,ekran,&mar3);
                        }
                        break;
                    }

                }
                else if(r==1)
                {

                    petla_r++;
                    if(petla_r==1) znak_r='l';
                    if(petla_r==1*2) znak_r='k';
                    if(petla_r==1*3) znak_r='j';
                    if(petla_r==1*4) znak_r='i';
                    if(petla_r==1*5) znak_r='h';
                    if(petla_r==1*6) znak_r='g';
                    if(petla_r==1*7) znak_r='f';
                    if(petla_r==1*8) znak_r='e';
                    if(petla_r==1*9) znak_r='d';
                    if(petla_r==1*10) znak_r='c';
                    if(petla_r==1*11) znak_r='b';
                    if(petla_r==1*12) znak_r='a';
                    if(petla_r==12) petla_r=0;

                    switch(znak_r)
                    {
                        case'a':
                        {
                            SDL_BlitSurface(m_r_1,NULL,ekran,&mar3);
                        }
                        break;
                        case'b':
                        {
                            SDL_BlitSurface(m_r_2,NULL,ekran,&mar3);
                        }
                        break;
                        case'c':
                        {
                            SDL_BlitSurface(m_r_3,NULL,ekran,&mar3);
                        }
                        break;
                        case'd':
                        {
                            SDL_BlitSurface(m_r_4,NULL,ekran,&mar3);
                        }
                        break;
                        case'e':
                        {
                            SDL_BlitSurface(m_r_5,NULL,ekran,&mar3);
                        }
                        break;
                        case'f':
                        {
                            SDL_BlitSurface(m_r_6,NULL,ekran,&mar3);
                        }
                        break;
                        case'g':
                        {
                            SDL_BlitSurface(m_r_7,NULL,ekran,&mar3);
                        }
                        break;
                        case'h':
                        {
                            SDL_BlitSurface(m_r_8,NULL,ekran,&mar3);
                        }
                        break;
                        case'i':
                        {
                            SDL_BlitSurface(m_r_9,NULL,ekran,&mar3);
                        }
                        break;
                        case'j':
                        {
                            SDL_BlitSurface(m_r_10,NULL,ekran,&mar3);
                        }
                        break;
                        case'k':
                        {
                            SDL_BlitSurface(m_r_11,NULL,ekran,&mar3);
                        }
                        break;
                        case'l':
                        {
                            SDL_BlitSurface(m_r_12,NULL,ekran,&mar3);
                        }
                        break;
                    }
                }

                if(l==0&&mlp==0)
                {
                    SDL_BlitSurface(m_r_13,NULL,ekran,&mar3);
                }
                else if(r==0&&mlp==1)
                {
                    SDL_BlitSurface(m_l_13,NULL,ekran,&mar3);
                }
                l=0;
                r=0;

                while(SDL_PollEvent(&zdarzenie))
                {
                    if(zdarzenie.type==SDL_QUIT)
                    {
                        exit(0);
                    }
                }
            }

            usuwanie_obrazow();
        }
    }
    return 0;
}
