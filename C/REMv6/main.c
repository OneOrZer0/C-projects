#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <conio.h>

//Wykonal Marek Snigurowicz i dodal niesamowita, oszamialajaca funkcje "sortowanie" - "polecam" *Magda Gesler*

char nazwa[] = "MarkoSoft ",wersja[] = "REMv5",dane_bazy[1000],odp,*n,napis[200];

int przejscie, istnieje, numer, przejscie_del, numer_wiersza, on, liczba_wierszy; //numer - liczba znakow w bazie

void Start()
{
    fflush(stdin);

    int nrz = 0;

    system("cls");

    if(on == 0)
    {

        if(nazwa[0]!=0)
        {
            Sleep(100);
            printf("%c",nazwa[nrz]);

            nrz++;

            while(nazwa[nrz]!=0)
            {
                Sleep(100);
                printf("%c",nazwa[nrz]);
                nrz++;
            }
        }

        nrz = 0;

        if(wersja[0]!=0)
        {
            Sleep(100);
            printf("%c",wersja[nrz]);

            nrz++;

            while(wersja[nrz]!=0)
            {
                Sleep(100);
                printf("%c",wersja[nrz]);
                nrz++;
            }
        }

        printf("\n===============\n\n");

        on = 1;
    }
    else
    {
        system("cls");
        printf("MarkoSoft %s\n",wersja);
        printf("===============\n\n");
    }
}

void Sprawdzanie()
{
    //Wykona³ Marek Œnigurowicz

    istnieje = 0;

    FILE * plik;

    if((plik = fopen("MarkoSoft.txt","r"))==NULL)
    {
        printf("%s > Plik nie istnieje\n\a",wersja);
    }
    else
    {
        //printf("%s > Plik istnieje\n\n",wersja);
        istnieje = 1;

    }

    fclose(plik);
}

void Tworzenie()
{
    numer_wiersza = 1;

    istnieje = 0;

    FILE * plik;

    if((plik = fopen("MarkoSoft.txt","w"))==NULL)
    {
        printf("%s > Nie udalo sie stworzyc czystej bazy!\n\a",wersja);
        fclose(plik);
        getchar();
        exit(0);
    }
    else
    {
       // fprintf(plik,"%d.",numer_wiersza);
        fprintf(plik,"%s","============ [ Baza MarkoSoft REMv3 ] ============\n");
    //    printf("%s > Baza stworzona pomyslnie\n\n",wersja);
        istnieje = 1;
    }

    fclose(plik);


}

void Podglad()
{
    numer_wiersza = 0;

    char znak;

    numer = 0;

    for(int i=0;i<=200;i++) // czyszczenie tablicy
    {
        dane_bazy[i] = 0;
    }

    FILE * plik;

    if((plik = fopen("MarkoSoft.txt","r"))==NULL)
    {
        printf("%s > Nie udalo sie otworzyc pliku!\n\n\a",wersja);
        fclose(plik);
        getchar();
        exit(0);
    }
    else
    {
        znak = getc(plik);

        while(znak != EOF)
        {
            dane_bazy[numer] = znak;
            znak = getc(plik);
            numer++;
        }

        //printf("%s > Plik otwarty i zaladowany pomyslnie!\n\n\a",wersja);
        printf("----------------------------------------------------\n");
        printf("Podglad: \n");
        printf("----------------------------------------------------\n\n");

        if(numer > 0) // numerowanie wierszy w czasie rzeczywistym
        {
            numer_wiersza++;
            printf("%d.",numer_wiersza);
        }

        for(int i=0; i<numer ;i++) // zminilem <= na <
        {
            printf("%c",dane_bazy[i]);
            if((dane_bazy[i]==10)&&(i < numer-1))
            {
                numer_wiersza++;
                printf("%d.",numer_wiersza);
            }
        }
    }

    liczba_wierszy = numer_wiersza;

    fclose(plik);
}

void Nowa()
{
    //Wymyœlone i napisane przez mini korporacje MarkoSoft (wszelkie prawa zastrzezone) Prezes i glowny(jedyny) programista: Marek Œnigurowicz

    FILE * plik;

    if((plik = fopen("MarkoSoft.txt","w"))==NULL)
    {
        printf("%s > Nie mozna stworzyc czystej bazy!",wersja);
    }
    else
    {

    }
}

void Opcje()
{
    int t=25;

    printf("\n----------------------------------------------------\n");
    Sleep(t);
    printf("Z[%d] Opcje:\n",numer);
    Sleep(t);
    printf("----------------------------------------------------\n\n");
    Sleep(t);
    printf("N. Nowa baza\n");
    Sleep(t);
    printf("D. Dodaj wpis\n");
    Sleep(t);
    printf("U. Usun wpis\n");
    Sleep(t);
    printf("M. Modyfikuj\n");
    Sleep(t);
    printf("S. Sortowanie\n");
    Sleep(t);
    printf("W. Wyjscie\n");
}

void Dodaj()
{
    FILE * plik;

    if((plik = fopen("MarkoSoft.txt","a"))==NULL)
    {
        printf("\n%s > Nie dualo sie otworzyc pliku MarkoSoft.txt",wersja);
        fclose(plik);
        getchar();
        exit(0);
    }
    else
    {
        fprintf(plik,"%s\n",n);
    }

    fclose(plik);
}

void Usuwanie()
{
    int gdzie_n[100],gdzie_n_b[100],numer_n = 0,wiersz_do_usuniecia = 0;

    char nowe_dane_bazy[1000];

    przejscie_del = 0;

    for(int i=0;i<1000;i++)
    {
        nowe_dane_bazy[i] = 0;
    }

    if(numer_wiersza == 0)
    {
        printf("%s > Za malo wierszy w bazie!\n\a",wersja);
        getchar();
    }
    else
    {
        printf("\n----------------------------------------------------\n");
        printf("Wybierz wiersz do usuniecia:\n");
        printf("----------------------------------------------------\n\n");

        printf("Numer wiersza: ");
        scanf("%d",&wiersz_do_usuniecia);

        if(wiersz_do_usuniecia < 1)
        {
            printf("\n%s > Numer wierszu jest za maly!\n",wersja);
            getchar();
        }
        else if(wiersz_do_usuniecia > numer_wiersza)
        {
            printf("\n%s > Numer wierszu jest za duzy!\n",wersja);
            getchar();
        }
        else
        {
            for(int i=0;i<=100;i++) // czyszczenie tablicy
            {
                gdzie_n[i] = 0;
            }

            for(int i=0;i<=numer;i++) // wklada do tablicy ilosc znakow kazdego wiersza
            {
                if(dane_bazy[i]==10)
                {
                    gdzie_n[numer_n] = i;
                    numer_n++;
                }
            }

            numer_n = 0;

            for(int i=0;i<=numer;i++) // wklada do tablicy ilosc znakow kazdego wiersza
            {
                if(dane_bazy[i]==10)
                {
                    if(numer_n > 0)
                    {
                        gdzie_n_b[numer_n] = i - gdzie_n[numer_n-1];
                    }
                    else
                    {
                        gdzie_n_b[numer_n] = i;   //Prawdziwa liczba znakow jednej lini
                    }
                    numer_n++;
                }
            }

            if(wiersz_do_usuniecia == 1)
            {
                for(int i=0;i<=numer - gdzie_n[0];i++)
                {
                    nowe_dane_bazy[i] = dane_bazy[i+gdzie_n[0]];
                }

                for(int i=0;i<=numer - gdzie_n[0];i++) // pokazuje to co w nowej edytowanej tablicy
                {
                    printf("%c",nowe_dane_bazy[i]);
                }

                FILE * plik;

                if((plik = fopen("MarkoSoft.txt","w"))==NULL)
                {
                    printf("%s > Nie mozna otworzyc pliku!\n\a",wersja);
                    fclose(plik);
                    getchar();
                    exit(0);
                }
                else
                {
                    for(int i=1;i<=numer - gdzie_n[0]-1;i++) // ostatnie modyfikacje
                    {
                        fprintf(plik,"%c",nowe_dane_bazy[i]);
                    }
                }
                fclose(plik);

            }
            else if(wiersz_do_usuniecia > 1) // Juz dziala!!!
            {

                int numer_nowego_znaku = 0;

                for(int i=0;i<=numer-gdzie_n_b[wiersz_do_usuniecia-1];i++) //  domyslnie wiersz do usuniecia to 2
                {
                    nowe_dane_bazy[i] = dane_bazy[numer_nowego_znaku];

                    if(i==gdzie_n[wiersz_do_usuniecia-2])
                    {
                        numer_nowego_znaku += gdzie_n_b[wiersz_do_usuniecia-1];
                    }

                    numer_nowego_znaku++;

                }

                FILE * plik;

                if((plik = fopen("MarkoSoft.txt","w"))==NULL)
                {
                    printf("%s > Nie moge zmienic pliku!!!\n\a",wersja);
                    fclose(plik);
                    getchar();
                    exit(0);
                }
                else
                {
                    for(int i=0;i<numer-gdzie_n_b[wiersz_do_usuniecia-1];i++)
                    {
                        fprintf(plik,"%c",nowe_dane_bazy[i]);
                    }
                }

                fclose(plik);

            }

        }//else w ifie ostatni warunek

    }
    przejscie_del = 1;
}

void Modyfikacja()
{
    char nowe_dane_bazy[1000],nowe_slowo[100],znak;

    int wiersz_do_modyfikacji=0, numer_znakow=0, gdzie_n[100],gdzie_n_b[100], numer_n=0,e = 0;

    if(numer_wiersza==0)
    {
        printf("\n%s > Za malo wierszy w bazie!\n\a",wersja);
        getchar();
    }
    else
    {
        printf("\n%s > Ktory wiersz chcesz zmodyfikowac?\n",wersja);
        printf("\nWiersz: ");

        scanf("%d",&wiersz_do_modyfikacji);

        fflush(stdin);

        if(wiersz_do_modyfikacji<1)
        {
            printf("\n%s > Numer wiersza jest za maly!\n\a",wersja);
            getchar();
        }
        else if(wiersz_do_modyfikacji>numer_wiersza)
        {
            printf("\n%s > Numer wiersza jest za duzy!\n\a",wersja);
            getchar();
        }
        else
        {
            printf("\n%s > Co chcesz umiescic w danym wierszu?\n",wersja);
            printf("\nTekst: ");

            n = gets(napis);

            FILE * plik;

            if((plik = fopen("Slowo.txt","w"))==NULL)
            {
                printf("\nNie mozna otworzyc pliku Slowo.txt\n\a");
                fclose(plik);
                exit(0);
            }
            else
            {
                fprintf(plik,"%s",n);
            }
            fclose(plik);

            if((plik = fopen("Slowo.txt","r"))==NULL)
            {
                printf("\nNie mozna otworzyc pliku Slowa.txt\n\a");
                fclose(plik);
                exit(0);
            }
            else
            {

                numer_znakow = 0;

                do
                {
                    znak = getc(plik);
                    nowe_slowo[numer_znakow] = znak;
                    numer_znakow++;
                }
                while(znak!=EOF);

                nowe_slowo[numer_znakow] = 10;

            }
            fclose(plik);

            for(int i=0;i<=numer;i++)
            {
                if(dane_bazy[i]==10)
                {
                    gdzie_n[numer_n] = i;
                    numer_n++;
                }
            }

            numer_n = 0;

            for(int i=0;i<=numer;i++)
            {
                if(numer_n == 0)
                {
                    gdzie_n_b[numer_n] = gdzie_n[numer_n] + 1;
                    numer_n++;
                }
                else
                {
                    gdzie_n_b[numer_n] = gdzie_n[numer_n] - gdzie_n[numer_n-1];
                    numer_n++;
                }
            }

            e=0;

            if(wiersz_do_modyfikacji==1)
            {
                for(int i=0;i<(numer-gdzie_n[wiersz_do_modyfikacji-1])+numer_znakow;i++)
                {
                    if(wiersz_do_modyfikacji==1)
                    {
                        if(i<numer_znakow-1)
                        {
                             nowe_dane_bazy[i] = nowe_slowo[i];
                        }
                        else
                        {
                            nowe_dane_bazy[i] = dane_bazy[(gdzie_n[wiersz_do_modyfikacji-1]-numer_znakow)+i+1];
                        }
                    }
                }

                if(wiersz_do_modyfikacji == 1)
                {
                    FILE * plik4;
                    plik4 = fopen("MarkoSoft.txt","w");

                    for(int i=0;i<(numer-gdzie_n[wiersz_do_modyfikacji-1])+numer_znakow-1;i++)
                    {
                        fprintf(plik4,"%c",nowe_dane_bazy[i]);
                    }
                    fclose(plik4);
                }

            }
            else
            {
                int e = 0, x = 0;

                for(int i=0;i<(numer-gdzie_n_b[wiersz_do_modyfikacji-1])+numer_znakow;i++)
                {
                    if(i<=gdzie_n[wiersz_do_modyfikacji-2])
                    {
                        nowe_dane_bazy[i] = dane_bazy[i];
                    }
                    else
                    {
                        if(e < numer_znakow-1)
                        {
                            nowe_dane_bazy[i] = nowe_slowo[e];
                            e++;
                        }
                        else
                        {
                            nowe_dane_bazy[i] = dane_bazy[(gdzie_n[(wiersz_do_modyfikacji-1)]+x)];
                            x++;
                        }

                    }
                }

                FILE * plik2;

                plik2 = fopen("MarkoSoft.txt","w");

                int h = ((numer-gdzie_n_b[wiersz_do_modyfikacji-1])+numer_znakow);

                for(int i=0;i<h;i++)
                {
                    fprintf(plik2,"%c",nowe_dane_bazy[i]);
                }
                fclose(plik2);

            }

            //getchar();

        }
    }



}

void Sortowanie()
{

    //printf("Numer wiersza: %d",liczba_wierszy);

    char znaki_segregacji[1000], znak, litera[]="=AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpRrSsTtUuWwXxYyZz0123456789!@#$%^&*()_+-!";

    int z=0,l=0;

    for(int i=0;i<1000;i++)
    {
        znaki_segregacji[i] = 0;
    }

    FILE * plik;

    if((plik = fopen("MarkoSoft.txt","r"))==NULL)
    {
        printf("%s > Blad odczytu danycj\n",wersja);
        fclose(plik);
        exit(0);
    }
    else
    {

        fclose(plik);

        while(litera[l]!='!')
        {
            if((plik = fopen("MarkoSoft.txt","r"))==NULL)
            {
                printf("%s > Blad odczytu danych\n",wersja);
                fclose(plik);
                exit(0);
            }
            else
            {
                znak = getc(plik);

                for(int i=0;i<liczba_wierszy;i++)
                {

                    //printf("\nLitera: %c",litera[l]);
                    //printf("\nZnak: %c\n",znak);

                    //getchar();

                    if(znak == litera[l])
                    {
                        do // nie wchodzi do while
                        {
                            //printf("%c",znak);
                            znaki_segregacji[z] = znak;
                            z++;
                            znak = getc(plik);

                            if((znak == '\n')||(znak == EOF))
                            {
                                znaki_segregacji[z] = 10;
                                z++;
                            }
                        }
                        while((znak != '\n')&&(znak != EOF)); // jezeli znak jest rozny od \n
                    }
                    else
                    {
                        while((znak!=10)&&(znak!=EOF))
                        {
                            //printf("%c",znak);
                            znak = getc(plik);
                        }
                        //printf("chuj");
                    }
                    znak = getc(plik);
                    //printf("po elese: %c",znak);
                    //getchar();
                }
                //printf("\nwyszlo\n");
                //getchar();
                l++;
                if(litera[l]=='!')
                {
                    znaki_segregacji[z] = EOF;
                    //printf("liczba znakow: %d", z);
                    //printf("Koniec");
                    //getchar();
                }
                fclose(plik);
            }
        }

        if((plik = fopen("MarkoSoft.txt","w"))==NULL)
        {
            printf("\n%s > Nie mozna otworzyc pliku do segregacji!",wersja);
            fclose(plik);
            exit(0);
        }
        else
        {
            for(int i=0;i<z;i++)
            {
                printf("%c",znaki_segregacji[i]);
                fprintf(plik,"%c",znaki_segregacji[i]);
            }
        }
        fclose(plik);

        /*
            while(znak!=EOF) // pobiera i zapisuje pierwszy znak wiersza
            {
                if(znak == '\n')
                {
                    znak = getc(plik);
                    if(znak!='\n')
                    {
                        znaki_segregacji[z] = znak;
                        z++;
                    }
                }
            }//while
            */
    }
    fclose(plik);
        /*
        if((plik2 = fopen("MarkoSoft_seg.txt","w"))==NULL)
        {
            printf("Blad otwarcia pliku!\n");
            fclose(plik2);
            exit(0);
        }
        else
        {
            z = 0,l = 0;

                znak = getc(plik);
                znaki_segregacji[z] = znak;
                z++;

                while(znak!=EOF) // pobiera i zapisuje pierwszy znak wiersza
                {
                    if(znak == '\n')
                    {
                        znak = getc(plik);
                        if(znak!='\n')
                        {
                               znaki_segregacji[z] = znak;
                            z++;
                        }
                    }
                }//while
            //-----------------------------------------

                for(int i=0;i<numer_wiersza;i++)
                {
                    if((znaki_segregacji[z-1] == litera[l])&&(znak!='\n')) // TO WYKORZYTSAJ!!!!!!!!! KURWA tyle ile wierszy sprawdza¿ warunek dla 1 litery np 5 wierszy dla "a"
                    {
                        printf("dziala!\n");
                        fprintf(plik2,"%c",znak);
                    }
                    else
                    {
                        fprintf(plik2,"/n");
                        z++;
                        l++;
                    }
                }

        }
        fclose(plik2);
    }
    fclose(plik);
    */
}

int main()
{
    while(przejscie == 0)
    {
        Start();
        Sprawdzanie();
       // Sortowanie();
        if(istnieje == 0)
        {
            Tworzenie();
        }
        else
        {
            Podglad();
            Opcje();
            odp = getch();

            switch(odp)
            {
                case 'n':
                    Tworzenie();
                break;
                case 'd':
                    printf("\n%s > Co chcesz dopisac? \n\n",wersja);
                    printf("Tekst: ");
                    n = gets(napis);
                    Dodaj();
                break;
                case 'u':
                    do
                    {
                        Start();
                        Podglad();
                        Usuwanie();
                        getchar();
                    }
                    while(przejscie_del == 0);
                break;
                case 'm':
                    {
                        Modyfikacja();
                    }
                break;
                case 's':
                    {
                        Sortowanie();
                    }
                break;
                case 'w':
                    exit(0);
                break;
            }

        }
    }

    return 0;
}

//Wymyœlone i napisane przez mini korporacje MarkoSoft (wszelkie prawa zastrzezone) Prezes i glowny(jedyny) programista: Marek Œnigurowicz
