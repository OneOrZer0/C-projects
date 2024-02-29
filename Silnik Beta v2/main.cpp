#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>

using namespace std;

char kierunek;
int pion=0,poziom=0;
string awatar[10];
int nr_linii=0;
int przepustator=0;
int nr_linii_czolg=0;
string czolgaa[30],czolgbb[30],czolgcc[30];
//------------------------------------------------Marla---
string marla[100];
int l_buzia; //l-liczba_linii
int wyjscie=0;


void bot()
{

    int i=0;
    string linia_a;
    fstream bot;
    string Antonina[i];

    bot.open("bot.txt",ios::in);

    while(getline(bot,linia_a))
    {
        Antonina[i]=linia_a;
    }
    i++;
    bot.close();

    for(int e=i;e<i;e++)
    {
        cout << Antonina[e] << endl;
    }
}

void r_czolg()
{

}
/*void czolg()
{
		fstream czolgA;

		czolgA.open("czolgA.txt",ios::in);
		if(czolgA.good()==false)
		{
			cout << "Brak pliku czolgA" << endl;
			exit(0);
		}

		fstream czolgB;

		czolgB.open("czolgB.txt",ios::in);
		if(czolgB.good()==false)
		{
			cout << "Brak pliku czolgB" << endl;
			exit(0);
		}

		fstream czolgC;

		czolgC.open("czolgC.txt",ios::in);
		if(czolgC.good()==false)
		{
			cout << "Brak pliku czolgC" << endl;
			exit(0);
		}

            string liniaA;
        while(getline(czolgA,liniaA))
        {
            czolgaa[nr_linii_czolg]=liniaA;
        }
            nr_linii_czolg=0;
            string liniaB;
        while(getline(czolgB,liniaB))
        {
            czolgbb[nr_linii_czolg]=liniaB;
        }
        nr_linii_czolg=0;
            string liniaC;
        while(getline(czolgC,liniaC))
        {
            czolgcc[nr_linii_czolg]=liniaC;
        }
            czolgA.close();
            czolgB.close();
            czolgC.close();
            r_czolg();
}
*/
poziom_p(int poziom_s)
    {
        if(poziom_s<0)
        {
            return poziom=0;
        }
        else
        return poziom;
    }
pion_p(int pion_s)
    {
        if(pion_s<0)
        {
            return pion=0;
        }
        else

        return pion;
    }
void logo()
    {
        string logo="MarkoSoft Silnik MIS Beta v.2";
        {
            for(int i=0;i<29;i++)
            {
                Sleep(50);
                cout << logo[i];
            }
            Sleep(1000);
        }
        system("cls");
    }
void render(int pi,int po)
    {
        for(int i=0;i<pi;i++)
        {
            cout << endl;
        }
        for(int i=0;i<po;i++)
        {
            cout << " ";//glowa sie przesuwa przez to!!! //przenies render postaci tutaj!
        }


    }
void postac()
    {
        int nr=1;
        string linia;

        fstream postac;

        postac.open("postac.txt",ios::in);

        while(getline(postac,linia))
        {
            switch(nr)
            {
                case 1: awatar[nr_linii]=linia;  break;
            }
            nr_linii++;
        }
        postac.close();

        system("cls");
    }
void sprawdzacz() //sprawdza wczytywane pliki do programu
    {
        fstream postac;

        postac.open("postac.txt",ios::in);

            if(postac.good()==false)
            {
                cout << "Brak pliku z postacia!!!"<<endl;
                postac.close();
                exit(0);
            }
        postac.close();

        fstream bot;

        bot.open("bot.txt",ios::in);

            if(bot.good()==false)
            {
                cout << "Brak pliku Bot.txt!!!" << endl;
                exit(0);
            }
        bot.close();
    }
void postac_r()
{
    for(int i=0;i<nr_linii;i++)
    {
        cout << awatar[i]<<endl;
        for(int e=0;e<poziom;e++)
        {
            cout << " ";
        }

    }
}
void skok()
{
    for(int i=0;i<3;i++)
    {
        system("cls");
        render(pion,poziom);
        postac_r();
        pion--;
        poziom--;
        Sleep(25);
    }
    for(int i=0;i<3;i++)
    {
        system("cls");
        render(pion,poziom);
        postac_r();
        pion++;
        poziom--;
        Sleep(25);
    }
    system("cls");


}
/*misje(int pi,int po);
{
    if((pi==24)||(po==24)
    {
        cout << "No niezle" << endl;
    }
    getchar();getchar();
    main();
}
*/

void markla()
{
    fstream buzia_m;
    string linia;
    int i;

    buzia_m.open("Marla.txt",ios::in);

    if(buzia_m.good()==false)
    {
        cout << "Brak pliku Marla.txt" << endl;
    }
    else
    {
        while(getline(buzia_m,linia))
        {
            marla[i]=linia;
            i++;
        }
        l_buzia=i;

        buzia_m.clear();
        buzia_m.close();
    }

}

buzia_m()
{
    cout << l_buzia <<endl;
    for(int i=0;i<l_buzia;i++)
    {
        cout << marla[i] << endl;
    }
}

int main()
{
    markla();
    buzia_m();

    logo();
    sprawdzacz();
    bot();
    postac();

    for(;;)
    {

        postac_r();
      //  misje(pion,poziom);
      /*  cout << endl;
        cout <<"Pion: " << pion << endl;
        cout << "Poziom: " <<poziom << endl;
        kierunek=getch();
        switch(kierunek)
        {
            case 'w': pion--;   system("cls");      break;
            case 's': pion++;   system("cls");      break;
            case 'd': poziom++; system("cls");      break;
            case 'a': poziom--; system("cls");      break;
            case 'j': skok(); break;
            default: system("cls"); break;
        }*/
        cout<<endl;
        cout <<"Pion: " << pion << endl;
        cout << "Poziom: " <<poziom << endl;
        Sleep(40);
        if(GetAsyncKeyState(VK_LEFT))
        {
            poziom--;
            system("cls");
        }
        if(GetAsyncKeyState(VK_RIGHT))
        {
            poziom++;
            system("cls");
        }
        if(GetAsyncKeyState(VK_UP))
        {
            pion--;
            system("cls");
        }
        if(GetAsyncKeyState(VK_DOWN))
        {
            pion++;
            system("cls");
        }
        if(GetAsyncKeyState(VK_SPACE))
        {
            skok();
        }
        else
        {
            system("cls");
        }
        pion_p(pion);
        poziom_p(poziom);
        render(pion,poziom);

    }


    return 0;
}
