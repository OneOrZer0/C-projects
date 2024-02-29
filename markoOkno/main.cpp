#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <sstream>


using namespace std;

SDL_Rect mar1;
SDL_Rect mar2;
SDL_Rect mar3;
SDL_Rect mar4;
SDL_Rect mar5;
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


char s=92,c=34;

int scena=0,xB,yB,p=0,ko=0,xC,xD,scenaA,scenaB;

string user;

int main(int argc, char*args[])
{
    SDL_Event event;
    bool quit = false;

    int x = GetSystemMetrics(SM_CXSCREEN); //pobieranie rozdzielczosci
    int y = GetSystemMetrics(SM_CYSCREEN);

    float xA = (x - 456)/2;
    float yA = (y - 521)/2;

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Event zdarzenie;

    SDL_Window*okno;
    SDL_Surface*ekran;

    okno = SDL_CreateWindow("markoOkno",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,x,y,SDL_WINDOW_FULLSCREEN_DESKTOP); //SDL_WINDOW_FULLSCREEN_DESKTOP
    ekran = SDL_GetWindowSurface(okno);

    SDL_Surface*tlo=IMG_Load("Grafika/scena/tlo.bmp");
    SDL_Surface*wind=IMG_Load("Grafika/scena/okno.bmp");
    SDL_Surface*userA=IMG_Load("Grafika/scena/userA.bmp");
    SDL_Surface*userB=IMG_Load("Grafika/scena/userB.bmp");
    SDL_Surface*userC=IMG_Load("Grafika/scena/userC.bmp");
    SDL_Surface*userD=IMG_Load("Grafika/scena/userD.bmp");
    SDL_Surface*migacz=IMG_Load("Grafika/scena/migacz.bmp");
    SDL_Surface*kropka=IMG_Load("Grafika/scena/kropka.bmp");
    SDL_Surface*haslo=IMG_Load("Grafika/scena/haslo.bmp");
    SDL_Surface*takA=IMG_Load("Grafika/scena/takA.bmp");
    SDL_Surface*takB=IMG_Load("Grafika/scena/takB.bmp");
    SDL_Surface*takC=IMG_Load("Grafika/scena/takC.bmp");
    SDL_Surface*nieA=IMG_Load("Grafika/scena/nieA.bmp");
    SDL_Surface*nieB=IMG_Load("Grafika/scena/nieB.bmp");
    SDL_Surface*nieC=IMG_Load("Grafika/scena/nieC.bmp");
    SDL_Surface*napisA=IMG_Load("Grafika/scena/napisA.bmp");


    fstream napis;

    napis.open("napis.txt",ios::out);

                    while(scena==0)
                    {
                        SDL_UpdateWindowSurface(okno);
                        SDL_Delay(100);

                        if(GetAsyncKeyState(VK_ESCAPE))
                        {
                            scena++;
                        }

                        mar1.x = 0;//tlo
                        mar1.y = 0;
                        mar1.h = y;
                        mar1.w = x;
                        SDL_BlitScaled(tlo,NULL,ekran,&mar1);

                        mar2.x = xA;//okno(wind)
                        mar2.y = yA;
                        SDL_BlitSurface(wind,NULL,ekran,&mar2);
/*


                        mar4.x = xA;//okno(wind)
                        mar4.y = yA;
                        SDL_BlitSurface(wind,NULL,ekran,&mar4);
*/

                        SDL_WaitEvent(&event);

                        switch (event.type)
                        {
                            case SDL_QUIT:

                                quit = true;

                            break;

                            case SDL_MOUSEMOTION:

                                xB = event.motion.x;
                                yB = event.motion.y;

                                //Jesteœ zajebista Emilcia

                              //  std::stringstream ss;

                              //  ss << "X: " << xB << " Y: " << yB;

                              //  SDL_SetWindowTitle(okno, ss.str().c_str());

                            break;

                        }//switch

                        if((yB > 324 + yA)&&(yB < 356 + yA )&&(xB > 25 + xA )&&(xB < xA + 321))
                        {
                            if(GetAsyncKeyState(VK_LBUTTON))//klik myszki
                            {
                                user = "A";
                            }

                            mar3.x = xA + 25;//userB
                            mar3.y = yA + 324;
                            SDL_BlitSurface(userB,NULL,ekran,&mar3);

                        }
                        else
                        {
                            mar3.x = xA + 25;//userA
                            mar3.y = yA + 324;
                            SDL_BlitSurface(userA,NULL,ekran,&mar3);
                        }

                        if((yB > 368 + yA)&&(yB < 400 + yA )&&(xB > 25 + xA )&&(xB < xA + 321))
                        {
                            if(GetAsyncKeyState(VK_LBUTTON))//klik myszki
                            {
                                user = "B";
                            }

                            mar4.x = xA + 25;//userB
                            mar4.y = yA + 368;
                            SDL_BlitSurface(userB,NULL,ekran,&mar4);

                        }
                        else
                        {
                            mar4.x = xA + 25;//userA
                            mar4.y = yA + 368;
                            SDL_BlitSurface(userA,NULL,ekran,&mar4);
                        }
//klawisze TAK NIE ===================================================================================
                        if((yB > 464 + yA)&&(yB < 498 + yA )&&(xB > 25 + xA )&&(xB < xA + 226)) //TAK
                        {

                            if(GetAsyncKeyState(VK_LBUTTON))//klik myszki
                            {
                                mar22.x = xA + 25;//takA
                                mar22.y = yA + 464;
                                SDL_BlitSurface(takC,NULL,ekran,&mar22);
                                scenaA = 1;
                            }
                            else
                            {
                                if(scenaA == 1)
                                {
                                    scena++;
                                }
                                else
                                {
                                    mar22.x = xA + 25;//takA
                                    mar22.y = yA + 464;
                                    SDL_BlitSurface(takB,NULL,ekran,&mar22);
                                }

                            }

                        }
                        else
                        {
                            scenaA = 0;
                            mar22.x = xA + 25;//takA
                            mar22.y = yA + 464;
                            SDL_BlitSurface(takA,NULL,ekran,&mar22);
                        }

                        if((yB > 464 + yA)&&(yB < 498 + yA )&&(xB > 230 + xA )&&(xB < xA + 431)) //NIE
                        {

                            if(GetAsyncKeyState(VK_LBUTTON))//klik myszki
                            {
                                mar23.x = xA + 230;//nieA
                                mar23.y = yA + 464;
                                SDL_BlitSurface(nieC,NULL,ekran,&mar23);
                                scenaB = 1;
                            }
                            else
                            {
                                if(scenaB == 1)
                                {
                                    scena++;
                                }
                                else
                                {
                                    mar23.x = xA + 230;//nieA
                                    mar23.y = yA + 464;
                                    SDL_BlitSurface(nieB,NULL,ekran,&mar23);
                                }

                            }
                        }
                        else
                        {
                            scenaB = 0;

                            mar23.x = xA + 230;//nieA
                            mar23.y = yA + 464;
                            SDL_BlitSurface(nieA,NULL,ekran,&mar23);
                        }
//klawisze TAK NIE ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                        if(user=="A") // A
                        {
                            mar3.x = xA + 25;//userB
                            mar3.y = yA + 324;
                            SDL_BlitSurface(userC,NULL,ekran,&mar3);
                        }

                        if(user=="B") // B
                        {
                            mar4.x = xA + 25;//userB
                            mar4.y = yA + 368;
                            SDL_BlitSurface(userD,NULL,ekran,&mar4);
                        }

                        //MIGACZE TU BYLY
//============================================================== Napisy
                if(user=="B")
                {
                        if(GetAsyncKeyState(0x41))
                        {
                            napis << "a" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x42))
                        {
                            napis << "b" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x43))
                        {
                            napis << "c" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x44))
                        {
                            napis << "d" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x45))
                        {
                            napis << "e" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x46))
                        {
                            napis << "f" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x47))
                        {
                            napis << "g" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x48))
                        {
                            napis << "h" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x49))
                        {
                            napis << "i" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x4A))
                        {
                            napis << "j" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x4B))
                        {
                            napis << "k" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x4C))
                        {
                            napis << "l" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x4D))
                        {
                            napis << "m" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x4E))
                        {
                            napis << "n" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x4F))
                        {
                            napis << "o" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x50))
                        {
                            napis << "p" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x51))
                        {
                            napis << "q" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x52))
                        {
                            napis << "r" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x53))
                        {
                            napis << "s" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x54))
                        {
                            napis << "t" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x55))
                        {
                            napis << "u" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x56))
                        {
                            napis << "v" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x57))
                        {
                            napis << "w" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x58))
                        {
                            napis << "x" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x59))
                        {
                            napis << "y" ;
                            ko++;
                        }
                        if(GetAsyncKeyState(0x5A))
                        {
                            napis << "z" ;
                            ko++;
                        }

                        if(GetAsyncKeyState(VK_LSHIFT)) napis << " SHIFT " ; //shift

                        if(GetAsyncKeyState(VK_SPACE)) napis << " " ; //space

                        if(GetAsyncKeyState(VK_CAPITAL)) napis << " CapsLock " ; //caps lock

                        if(GetAsyncKeyState(VK_RETURN)) scena++ ; //enter

                        if(GetAsyncKeyState(VK_BACK))
                        {
                            ko--;
                            napis << " BackSpace " ; //caps lock
                        }

                        if(GetAsyncKeyState(VK_OEM_5))
                        {
                            ko++;
                            napis << " Slesz " ;
                        }

                        if(GetAsyncKeyState(0x31))
                        {
                            ko++;
                            napis << "1" ;
                        }
                        if(GetAsyncKeyState(0x32))
                        {
                            ko++;
                            napis << "2" ;
                        }
                        if(GetAsyncKeyState(0x33))
                        {
                            ko++;
                            napis << "3" ;
                        }
                        if(GetAsyncKeyState(0x34))
                        {
                            ko++;
                            napis << "4" ;
                        }
                        if(GetAsyncKeyState(0x35))
                        {
                            ko++;
                            napis << "5" ;
                        }
                        if(GetAsyncKeyState(0x36))
                        {
                            ko++;
                            napis << "6" ;
                        }
                        if(GetAsyncKeyState(0x37))
                        {
                            ko++;
                            napis << "7" ;
                        }
                        if(GetAsyncKeyState(0x38))
                        {
                            ko++;
                            napis << "8" ;
                        }
                        if(GetAsyncKeyState(0x39))
                        {
                            ko++;
                            napis << "9" ;
                        }
                        if(GetAsyncKeyState(0x30))
                        {
                            ko++;
                            napis << "0" ;
                        }
                }
                            xC = xA+34;

                            xD = xA+34;

                            if(ko==0)
                            {
                                mar21.x = xC;
                                mar21.y = yA + 379;
                                SDL_BlitSurface(haslo,NULL,ekran,&mar21);
                            }
                            if(ko>=1)
                            {
                                xD += 9;
                                mar5.x = xC;//kropka
                                mar5.y = yA + 383;
                                SDL_BlitSurface(kropka,NULL,ekran,&mar5);
                            }
                            if(ko>=2)
                            {
                                xD += 9;
                                mar6.x = xC + 9;//kropka
                                mar6.y = yA + 383;
                                SDL_BlitSurface(kropka,NULL,ekran,&mar6);
                            }
                            if(ko>=3)
                            {
                                xD += 9;
                                mar7.x = xC + 9 * 2;//kropka
                                mar7.y = yA + 383;
                                SDL_BlitSurface(kropka,NULL,ekran,&mar7);
                            }
                            if(ko>=4)
                            {
                                xD += 9;
                                mar8.x = xC + 9 * 3;//kropka
                                mar8.y = yA + 383;
                                SDL_BlitSurface(kropka,NULL,ekran,&mar8);
                            }
                            if(ko>=5)
                            {
                                xD += 9;
                                mar9.x = xC + 9 * 4;//kropka
                                mar9.y = yA + 383;
                                SDL_BlitSurface(kropka,NULL,ekran,&mar9);
                            }
                            if(ko>=6)
                            {
                                xD += 9;
                                mar10.x = xC + 9 * 5;//kropka
                                mar10.y = yA + 383;
                                SDL_BlitSurface(kropka,NULL,ekran,&mar10);
                            }
                            if(ko>=7)
                            {
                                xD += 9;
                                mar11.x = xC + 9 * 6;//kropka
                                mar11.y = yA + 383;
                                SDL_BlitSurface(kropka,NULL,ekran,&mar11);
                            }
                            if(ko>=8)
                            {
                                xD += 9;
                                mar12.x = xC + 9 * 7;//kropka
                                mar12.y = yA + 383;
                                SDL_BlitSurface(kropka,NULL,ekran,&mar12);
                            }
                            if(ko>=9)
                            {
                                xD += 9;
                                mar13.x = xC + 9 * 8;//kropka
                                mar13.y = yA + 383;
                                SDL_BlitSurface(kropka,NULL,ekran,&mar13);
                            }
                            if(ko>=10)
                            {
                                xD += 9;
                                mar14.x = xC + 9 * 9;//kropka
                                mar14.y = yA + 383;
                                SDL_BlitSurface(kropka,NULL,ekran,&mar14);
                            }
                            if(ko>=11)
                            {
                                xD += 9;
                                mar15.x = xC + 9 * 10;//kropka
                                mar15.y = yA + 383;
                                SDL_BlitSurface(kropka,NULL,ekran,&mar15);
                            }
                            if(ko>=12)
                            {
                                xD += 9;
                                mar16.x = xC + 9 * 11;//kropka
                                mar16.y = yA + 383;
                                SDL_BlitSurface(kropka,NULL,ekran,&mar16);
                            }
                            if(ko>=13)
                            {
                                xD += 9;
                                mar17.x = xC + 9 * 12;//kropka
                                mar17.y = yA + 383;
                                SDL_BlitSurface(kropka,NULL,ekran,&mar17);
                            }if(ko>=14)
                            {
                                xD += 9;
                                mar18.x = xC + 9 * 13;//kropka
                                mar18.y = yA + 383;
                                SDL_BlitSurface(kropka,NULL,ekran,&mar18);
                            }
                            if(ko>=15)
                            {
                                xD += 9;
                                mar19.x = xC + 9 * 14;//kropka
                                mar19.y = yA + 383;
                                SDL_BlitSurface(kropka,NULL,ekran,&mar19);
                            }
                            if(ko>=16)
                            {
                                xD += 9;
                                mar20.x = xC + 9 * 15;//kropka
                                mar20.y = yA + 383;
                                SDL_BlitSurface(kropka,NULL,ekran,&mar20);
                            }
                            if(ko>16)
                            {
                                ko = 16;
                            }

                            if(user=="A") // kursor userA
                            {

                                mar5.x = xA + 34;//userA
                                mar5.y = yA + 331;
                                SDL_BlitSurface(migacz,NULL,ekran,&mar5);

                            }
                            else if(user=="B") // kursor userB
                            {
                                mar5.x = xD;//xA + 34;//userA
                                mar5.y = yA + 375;
                                SDL_BlitSurface(migacz,NULL,ekran,&mar5);
                            }
                            else
                            {

                            }

                            mar24.x = xA + 34;//napis loginu
                            mar24.y = yA + 336;
                            SDL_BlitSurface(napisA,NULL,ekran,&mar24);


                    }

                    napis.clear();
                    napis.close();

                    SDL_FreeSurface(tlo);
                    SDL_FreeSurface(wind);
                    SDL_FreeSurface(userA);
                    SDL_FreeSurface(userB);
                    SDL_FreeSurface(userC);
                    SDL_FreeSurface(userD);
                    SDL_FreeSurface(migacz);
                    SDL_FreeSurface(kropka);
                    SDL_FreeSurface(haslo);
                    SDL_FreeSurface(takA);
                    SDL_FreeSurface(takB);
                    SDL_FreeSurface(takC);
                    SDL_FreeSurface(nieA);
                    SDL_FreeSurface(nieB);
                    SDL_FreeSurface(nieC);
                    SDL_FreeSurface(napisA);



            return 0;


}

  /*
                        while(SDL_PollEvent(&zdarzenie))
                        {
                            if(zdarzenie.type==SDL_QUIT)
                            {
                                exit(0);
                            }
                            if(zdarzenie.type==SDL_MOUSEMOTION)
                            {
                                xB = event.motion.x;
                                yB = event.motion.y;
                            }
                        }
                        */
