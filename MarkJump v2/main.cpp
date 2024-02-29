#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <time.h>

using namespace std;

int p=0,scena=0,skrzynkax,skrzynkay=786,x=300,y=602,x2=300,y2=602,skok=0,skok2,skok3=0,skok4,tlo1x=0,tlo1y=0,pod1x=0,pod1y=852,pod2x=0,pod2y=720,pod3x=0,pod3y=320,pod4x=0,pod4y=0;
int skrzynka1x,skrzynka1y=786,skrzynka2x,skrzynka2y=786,skrzynka3x,skrzynka3y=786,skrzynka4x,skrzynka4y=786,moneta1x,moneta1y,ods,pos,serca=3,serca1=3,serc,serc1,punkty_prawy,punkty_lewy;

SDL_Rect mar1; //z
SDL_Rect mar2; //z
SDL_Rect mar3; //z
SDL_Rect mar4; //z
SDL_Rect mar5; //z
SDL_Rect mar6;
SDL_Rect mar7;
SDL_Rect mar8;
SDL_Rect mar9;
SDL_Rect mar10;
SDL_Rect mar11;
SDL_Rect mar12;
SDL_Rect mar13;
SDL_Rect mar14;
SDL_Rect mar15;
SDL_Rect mar16;
SDL_Rect mar17;
SDL_Rect mar18;
SDL_Rect mar19;
SDL_Rect mar20;
SDL_Rect mar21;
SDL_Rect mar22;
SDL_Rect mar23;
SDL_Rect mar24;
SDL_Rect mar25;
SDL_Rect mar26;
SDL_Rect mar27;
SDL_Rect mar28;
SDL_Rect mar29;
SDL_Rect mar30;
SDL_Rect mar31;
SDL_Rect mar32;
SDL_Rect mar33;
SDL_Rect mar34;
SDL_Rect mar35;
SDL_Rect mar36;

int main(int argc, char*args[])
{
    int rozX = GetSystemMetrics(SM_CXSCREEN); //pobieranie rozdzielczosci
    int rozY = GetSystemMetrics(SM_CYSCREEN);

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Event zdarzenie;

    SDL_Window*okno;
    SDL_Surface*ekran;

    okno = SDL_CreateWindow("MarkoJump",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1680,1050,SDL_WINDOW_FULLSCREEN_DESKTOP); //SDL_WINDOW_FULLSCREEN_DESKTOP
    ekran = SDL_GetWindowSurface(okno);

    //LADOWANIE OBRAZOW DO PAMIECI RAM

   // SDL_Surface*tlo=IMG_Load("Grafika/scena/tlo.bmp");

    srand(time(NULL));

    skrzynkax = rand()%500+1+rozX;
    skrzynka1x = rand()%500+1000+rozX;
    skrzynka2x = rand()%500+2000+rozX;
    skrzynka3x = rand()%500+4000+rozX;
    skrzynka4x = rand()%500+8000+rozX;
    moneta1x = rand()%rozX-100;
    moneta1y = rand()%200+320+66;

    moneta1x += 150;

     while(p==0)
        {
                    if(scena==0)
                    {

                        SDL_Surface*tlo=IMG_Load("Grafika/scena/tlo.bmp");
                        SDL_Surface*podloga=IMG_Load("Grafika/scena/podloga.bmp");
                        SDL_Surface*podloga1=IMG_Load("Grafika/scena/podloga1.bmp");
                        SDL_Surface*sciana=IMG_Load("Grafika/scena/sciana.bmp");
                        SDL_Surface*sufit=IMG_Load("Grafika/scena/sufit.bmp");
                        SDL_Surface*moneta=IMG_Load("Grafika/scena/moneta.bmp");

                        SDL_Surface*postac1a=IMG_Load("Grafika/scena/postac1/1.bmp");
                        SDL_Surface*postac1b=IMG_Load("Grafika/scena/postac1/2.bmp");
                        SDL_Surface*postac1c=IMG_Load("Grafika/scena/postac1/3.bmp");

                        SDL_Surface*postac2a=IMG_Load("Grafika/scena/postac2/1.bmp");
                        SDL_Surface*postac2b=IMG_Load("Grafika/scena/postac2/2.bmp");
                        SDL_Surface*postac2c=IMG_Load("Grafika/scena/postac2/3.bmp");
                      //  SDL_Surface*postac2b=IMG_Load("Grafika/scena/postac2/2.bmp");
                      //  SDL_Surface*postac2c=IMG_Load("Grafika/scena/postac2/3.bmp");

                        SDL_Surface*przeszkoda=IMG_Load("Grafika/scena/przeszkoda.bmp");

                        SDL_Surface*serce1a=IMG_Load("Grafika/scena/serca/1.bmp");
                        SDL_Surface*serce1b=IMG_Load("Grafika/scena/serca/2.bmp");
                        SDL_Surface*serce1c=IMG_Load("Grafika/scena/serca/3.bmp");

                        SDL_Surface*serce2a=IMG_Load("Grafika/scena/serca1/1.bmp");
                        SDL_Surface*serce2b=IMG_Load("Grafika/scena/serca1/2.bmp");
                        SDL_Surface*serce2c=IMG_Load("Grafika/scena/serca1/3.bmp");

                        while(scena==0)
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

                            if(GetAsyncKeyState(VK_ESCAPE))
                            {
                                exit(0);
                            }

                        //mar1.x = tlo1x;//tlo
                         //   mar1.y = tlo1y;
                         //   SDL_BlitSurface(tlo,NULL,ekran,&mar1);


                            //TLO-----------------------------------------

                            if(pod3x<-396)
                            {
                                pod3x = 0;
                            }

                            mar17.x = pod3x;//tlo
                            mar17.y = pod3y;
                            SDL_BlitSurface(sciana,NULL,ekran,&mar17);

                            mar18.x = pod3x+396;//tlo
                            mar18.y = pod3y;
                            SDL_BlitSurface(sciana,NULL,ekran,&mar18);

                            mar19.x = pod3x+2*396;//tlo
                            mar19.y = pod3y;
                            SDL_BlitSurface(sciana,NULL,ekran,&mar19);

                            mar20.x = pod3x+3*396;//tlo
                            mar20.y = pod3y;
                            SDL_BlitSurface(sciana,NULL,ekran,&mar20);

                            mar21.x = pod3x+4*396;//tlo
                            mar21.y = pod3y;
                            SDL_BlitSurface(sciana,NULL,ekran,&mar21);

                            mar22.x = pod3x+5*396;//tlo
                            mar22.y = pod3y;
                            SDL_BlitSurface(sciana,NULL,ekran,&mar22);

                            pod3x -=1;


                            //TLO-----------------------------------------

                            //PODLOGI-------------------------------------

                            if(pod2x<-396)
                            {
                                pod2x = 0;
                            }

                            pod4x = pod2x;

                            mar11.x = pod2x;//tlo
                            mar11.y = pod2y;
                            SDL_BlitSurface(podloga1,NULL,ekran,&mar11);

                            mar12.x = pod2x+396;//tlo
                            mar12.y = pod2y;
                            SDL_BlitSurface(podloga1,NULL,ekran,&mar12);

                            mar13.x = pod2x+2*396;//tlo
                            mar13.y = pod2y;
                            SDL_BlitSurface(podloga1,NULL,ekran,&mar13);

                            mar14.x = pod2x+3*396;//tlo
                            mar14.y = pod2y;
                            SDL_BlitSurface(podloga1,NULL,ekran,&mar14);

                            mar15.x = pod2x+4*396;//tlo
                            mar15.y = pod2y;
                            SDL_BlitSurface(podloga1,NULL,ekran,&mar15);

                            mar16.x = pod2x+5*396;//tlo
                            mar16.y = pod2y;
                            SDL_BlitSurface(podloga1,NULL,ekran,&mar16);
                            //====================================================sufit
                            mar23.x = pod4x;//tlo
                            mar23.y = pod4y;
                            SDL_BlitSurface(sufit,NULL,ekran,&mar23);

                            mar24.x = pod4x+396;//tlo
                            mar24.y = pod4y;
                            SDL_BlitSurface(sufit,NULL,ekran,&mar24);

                            mar25.x = pod4x+2*396;//tlo
                            mar25.y = pod4y;
                            SDL_BlitSurface(sufit,NULL,ekran,&mar25);

                            mar26.x = pod4x+3*396;//tlo
                            mar26.y = pod4y;
                            SDL_BlitSurface(sufit,NULL,ekran,&mar26);

                            mar27.x = pod4x+4*396;//tlo
                            mar27.y = pod4y;
                            SDL_BlitSurface(sufit,NULL,ekran,&mar27);

                            mar28.x = pod4x+5*396;//tlo
                            mar28.y = pod4y;
                            SDL_BlitSurface(sufit,NULL,ekran,&mar28);
                            //====================================================sufit

                            pod2x -=2;
                           // pod1y +=5;

                            if(pod1x<-396)
                            {
                                pod1x = 0;
                            }

                            mar5.x = pod1x;//tlo
                            mar5.y = pod1y;
                            SDL_BlitSurface(podloga,NULL,ekran,&mar5);

                            mar6.x = pod1x+396;//tlo
                            mar6.y = pod1y;
                            SDL_BlitSurface(podloga,NULL,ekran,&mar6);

                            mar7.x = pod1x+2*396;//tlo
                            mar7.y = pod1y;
                            SDL_BlitSurface(podloga,NULL,ekran,&mar7);

                            mar8.x = pod1x+3*396;//tlo
                            mar8.y = pod1y;
                            SDL_BlitSurface(podloga,NULL,ekran,&mar8);

                            mar9.x = pod1x+4*396;//tlo
                            mar9.y = pod1y;
                            SDL_BlitSurface(podloga,NULL,ekran,&mar9);

                            mar10.x = pod1x+5*396;//tlo
                            mar10.y = pod1y;
                            SDL_BlitSurface(podloga,NULL,ekran,&mar10);

                            pod1x -=5;

                            //PODLOGI-------------------------------------


                            if(GetAsyncKeyState(0x41)) //strzalki
                            {
                                x -= 7;
                            }
                            if(x<0)
                            {
                                x =  0;
                            }
                            if(GetAsyncKeyState(0x44))
                            {
                                x += 7;
                            }
                            if(x>rozX-100)
                            {
                                x = rozX-100;
                            }

                            if(skok > 0)
                            {
                                if(skok>skok2)
                                {
                                    skok--;
                                    y -= 10;
                                }
                                else
                                {
                                    skok--;
                                    y += 10;
                                }
                            }
                            else
                            {
                                if(GetAsyncKeyState(0x57))
                                {
                                    skok = 30;
                                    skok2 = skok/2;
                                }
                            }

                            if(GetAsyncKeyState(VK_LEFT)) //w a d
                            {
                                x2 -= 7;
                            }
                            if(x2<0)
                            {
                                x2 =  0;
                            }

                            if(GetAsyncKeyState(VK_RIGHT))
                            {
                                x2 += 7;
                            }
                            if(x2>rozX-100)
                            {
                                x2 = rozX-100;
                            }

                            if(skok3 > 0)
                            {
                                if(skok3>skok4)
                                {
                                    skok3--;
                                    y2 -= 10;
                                }
                                else
                                {
                                    skok3--;
                                    y2 += 10;
                                }
                            }
                            else
                            {
                                if(GetAsyncKeyState(VK_UP))
                                {
                                    skok3 = 30;
                                    skok4 = skok3/2;
                                }
                            }


                            //KOLIZJE--------------------------------------
                            if((x+100>=skrzynkax)&&(x+100<=skrzynkax+66)&&(y+250>=skrzynkay)&&(y+250<=skrzynkay+66))
                            {
                                if(serc1==1)
                                {
                                    serca--;
                                    serc1 = 0;
                                }
                                //exit(0);
                            }
                            if((x2+100>=skrzynkax)&&(x2+100<=skrzynkax+66)&&(y2+250>=skrzynkay)&&(y2+250<=skrzynkay+66))
                            {
                                if(serc1==1)
                                {
                                    serca1--;
                                    serc1 = 0;
                                }
                                //exit(0);
                            }

                            if((x+100>=skrzynka1x)&&(x+100<=skrzynka1x+66)&&(y+250>=skrzynka1y)&&(y+250<=skrzynka1y+66))
                            {
                                if(serc1==1)
                                {
                                    serca--;
                                    serc1 = 0;
                                }
                               // exit(0);
                            }
                            if((x2+100>=skrzynka1x)&&(x2+100<=skrzynka1x+66)&&(y2+250>=skrzynka1y)&&(y2+250<=skrzynka1y+66))
                            {
                                if(serc1==1)
                                {
                                    serca1--;
                                    serc1 = 0;
                                }
                                //exit(0);
                            }

                            if((x+100>=skrzynka2x)&&(x+100<=skrzynka2x+66)&&(y+250>=skrzynka2y)&&(y+250<=skrzynka2y+66))
                            {
                                if(serc1==1)
                                {
                                    serca--;
                                    serc1 = 0;
                                }
                                //exit(0);
                            }
                            if((x2+100>=skrzynka2x)&&(x2+100<=skrzynka2x+66)&&(y2+250>=skrzynka2y)&&(y2+250<=skrzynka2y+66))
                            {
                                if(serc1==1)
                                {
                                    serca1--;
                                    serc1 = 0;
                                }
                                //exit(0);
                            }

                            if((x+100>=skrzynka3x)&&(x+100<=skrzynka3x+66)&&(y+250>=skrzynka3y)&&(y+250<=skrzynka3y+66))
                            {
                                if(serc1==1)
                                {
                                    serca--;
                                    serc1 = 0;
                                }
                                //exit(0);
                            }
                            if((x2+100>=skrzynka3x)&&(x2+100<=skrzynka3x+66)&&(y2+250>=skrzynka3y)&&(y2+250<=skrzynka3y+66))
                            {
                                if(serc1==1)
                                {
                                    serca1--;
                                    serc1 = 0;
                                }
                               // exit(0);
                            }

                            if((x+100>=skrzynka4x)&&(x+100<=skrzynka4x+66)&&(y+250>=skrzynka4y)&&(y+250<=skrzynka4y+66))
                            {
                                if(serc1==1)
                                {
                                    serca--;
                                    serc1 = 0;
                                }
                                //exit(0);
                            }
                            if((x2+100>=skrzynka4x)&&(x2+100<=skrzynka4x+66)&&(y2+250>=skrzynka4y)&&(y2+250<=skrzynka4y+66))
                            {
                                if(serc1==1)
                                {
                                    serca1--;
                                    serc1 = 0;
                                }
                                //exit(0);
                            }

                            if(((x+100>=moneta1x)&&(x+100<=moneta1x+66)&&(y>=moneta1y)&&(y<=moneta1y+66))||((x>=moneta1x)&&(x<=moneta1x+66)&&(y+250>=moneta1y)&&(y+250<=moneta1y+66)))
                            {
                                moneta1x = rand()%rozX-100;
                                moneta1x += 150;
                                moneta1y = rand()%200+400;
                                punkty_lewy++;
                            }
                            if((x2+100>=moneta1x)&&(x2+100<=moneta1x+66)&&(y2>=moneta1y)&&(y2<=moneta1y+66))
                            {
                                moneta1x = rand()%rozX-100;
                                moneta1x += 150;
                                moneta1y = rand()%200+400;
                                punkty_prawy++;
                            }


                            //KOLIZJE--------------------------------------

                            //POSTACIE

                            ods++;
                            serc++;
                            if(serc>60)
                            {
                                serc1 = 1;
                                serc = 0;
                            }

                            if(ods>5)
                            {
                                pos++;
                                ods = 0;
                            }
                            if(pos>2)
                            {
                                pos = 0;
                            }
                            switch(pos)
                            {
                                case 0:
                                {
                                    mar2.x = x;//tlo
                                    mar2.y = y;
                                    SDL_BlitSurface(postac1a,NULL,ekran,&mar2);

                                    mar4.x = x2;//tlo
                                    mar4.y = y2;
                                    SDL_BlitSurface(postac2a,NULL,ekran,&mar4);
                                }
                                break;
                                case 1:
                                {
                                    mar2.x = x;//tlo
                                    mar2.y = y;
                                    SDL_BlitSurface(postac1b,NULL,ekran,&mar2);

                                    mar4.x = x2;//tlo
                                    mar4.y = y2;
                                    SDL_BlitSurface(postac2b,NULL,ekran,&mar4);
                                }
                                break;
                                case 2:
                                {
                                    mar2.x = x;//tlo
                                    mar2.y = y;
                                    SDL_BlitSurface(postac1c,NULL,ekran,&mar2);

                                    mar4.x = x2;//tlo
                                    mar4.y = y2;
                                    SDL_BlitSurface(postac2c,NULL,ekran,&mar4);
                                }
                                break;
                            }

                       //     mar2.x = x;//tlo
                       //     mar2.y = y;
                       //     SDL_BlitSurface(postac1a,NULL,ekran,&mar2);

                       //     mar4.x = x2;//tlo
                       //     mar4.y = y2;
                       //     SDL_BlitSurface(postac2a,NULL,ekran,&mar4);
                            //PRZESZKODY-----------------------------------
                            mar29.x = skrzynkax;//tlo
                            mar29.y = skrzynkay;
                            SDL_BlitSurface(przeszkoda,NULL,ekran,&mar29);

                            mar30.x = skrzynka1x;//tlo
                            mar30.y = skrzynka1y;
                            SDL_BlitSurface(przeszkoda,NULL,ekran,&mar30);

                            mar31.x = skrzynka2x;//tlo
                            mar31.y = skrzynka2y;
                            SDL_BlitSurface(przeszkoda,NULL,ekran,&mar31);

                            mar32.x = skrzynka3x;//tlo
                            mar32.y = skrzynka3y;
                            SDL_BlitSurface(przeszkoda,NULL,ekran,&mar32);

                            mar33.x = skrzynka4x;//tlo
                            mar33.y = skrzynka4y;
                            SDL_BlitSurface(przeszkoda,NULL,ekran,&mar33);
                            //----------------------------------------------
                            mar34.x = moneta1x;//tlo
                            mar34.y = moneta1y;
                            SDL_BlitSurface(moneta,NULL,ekran,&mar34);
                            //MONETA---------------------------------------
                            skrzynkax-=5;
                            skrzynka1x-=5;
                            skrzynka2x-=5;
                            skrzynka3x-=5;
                            skrzynka4x-=5;

                            if(skrzynkax<-100)
                            {
                                skrzynkax = rand()%500+1+1680;
                            }
                            if(skrzynka1x<-100)
                            {
                                skrzynka1x = rand()%500+1000+1680;
                            }
                            if(skrzynka2x<-100)
                            {
                                skrzynka2x = rand()%500+2000+1680;
                            }
                            if(skrzynka3x<-100)
                            {
                                skrzynka3x = rand()%500+4000+1680;
                            }
                            if(skrzynka4x<-100)
                            {
                                skrzynka4x = rand()%500+8000+1680;
                            }

                            switch(serca)
                            {
                                case 0:
                                {
                                    fstream punktacja;

                                    punktacja.open("punkty.txt",ios::out);

                                    punktacja << "Punkty gracza lewego(Marko):" << punkty_prawy << endl;
                                    punktacja << "Punkty gracza prawego(Szynko):" << punkty_lewy << endl;

                                    punktacja.clear();
                                    punktacja.close();

;                                   exit(0);
                                }
                                break;
                                case 1:
                                {
                                    mar35.x = 0;//tlo
                                    mar35.y = 0;
                                    SDL_BlitSurface(serce1a,NULL,ekran,&mar35);
                                }
                                break;
                                case 2:
                                {
                                    mar35.x = 0;//tlo
                                    mar35.y = 0;
                                    SDL_BlitSurface(serce1b,NULL,ekran,&mar35);
                                }
                                break;
                                case 3:
                                {
                                    mar35.x = 0;//tlo
                                    mar35.y = 0;
                                    SDL_BlitSurface(serce1c,NULL,ekran,&mar35);
                                }
                                break;
                            }

                            switch(serca1)
                            {
                                case 0:
                                {
                                    fstream punktacja;

                                    punktacja.open("punkty.txt",ios::out);

                                    punktacja << "Punkty gracza lewego(Marko):" << punkty_prawy << endl;
                                    punktacja << "Punkty gracza prawego(Szynko):" << punkty_lewy << endl;

                                    punktacja.clear();
                                    punktacja.close();

                                    exit(0);
                                }
                                break;
                                case 1:
                                {
                                    mar36.x = rozX-196;//tlo
                                    mar36.y = 0;
                                    SDL_BlitSurface(serce2a,NULL,ekran,&mar36);
                                }
                                break;
                                case 2:
                                {
                                    mar36.x = rozX-196;//tlo
                                    mar36.y = 0;
                                    SDL_BlitSurface(serce2b,NULL,ekran,&mar36);
                                }
                                break;
                                case 3:
                                {
                                    mar36.x = rozX-196;//tlo
                                    mar36.y = 0;
                                    SDL_BlitSurface(serce2c,NULL,ekran,&mar36);
                                }
                                break;
                            }
                        }
                    }
        }//while glowna

    return 0;
}









