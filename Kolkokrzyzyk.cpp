

#include <iostream>
using namespace std;



void PokarzPalete(int Tabele[3][3]) //Show board
{
    cout << endl;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "|";

            if (Tabele[j][i] == 1)
            {
                cout << "X";
            }
            if (Tabele[j][i] == 2)
            {
                cout << "O";
            }
            if (Tabele[j][i] == 0)
            {
                cout << "_";
            }
        }
        cout << "|" << endl;
    }

    cout << endl;
}


char zmianasymbolu(int plansze) //symbol change
{
    if (plansze == 1)
        return 'O';
    if (plansze == 2)
        return 'X';
    else
        return '_';
}

void Pokawygranego(char wygrany[33], char wygrany2[33], int plansze) //show winner
{

    if (plansze == 1)
    {
        cout << "Wygral " << wygrany << "!!";
    }
    else
    {
        cout << "Wygral " << wygrany2 << "!!";
    }
}


int main()
{

    char imie1[33]; //first player
    char imie2[33];  //second player
    //int Plansza[3][3] = {};
    int Plansze[3][3] = //board
    {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    bool isEnd = false;

    cout << "Witaj w grze ";
    cout << endl << endl;

    cout << "Podaj imie pierwszego gracza X : ";

    cin >> imie1;
    cout << endl;

    cout << "Podaj imie drugiego gracza O : ";
    cin >> imie2;
    cout << endl;

    bool isFirstPlayer = false;


    int w;
    int k;


    while (isEnd == false)
    {
        cout << endl;
        for (int j = 0; j < 3; j++)
        {
            for (int i = 0; i < 3; i++)
            {
                cout << "|";

                cout << zmianasymbolu(Plansze[j][i]);
            }
            cout << "|"<< endl;
        }

        cout << endl;

        if (Plansze[0][0] > 0 && Plansze[0][1] > 0 && Plansze[0][2] > 0 && Plansze[1][0] > 0 && Plansze[1][1] > 0 && Plansze[1][2] > 0 && Plansze[2][0] > 0 && Plansze[2][1] > 0 && Plansze[2][2] > 0)
        {
            cout << endl;
            cout << "Remis!";
            cout << endl;
            break;
        }

        if (!isEnd)
        {
            int w;
            int k;
            if (isFirstPlayer)
            {
                cout << "Wybierz wiersz: ";
                cin >> w;
                cout << "Wybierz kolumne: ";
                cin >> k;

                if ((w <= 3 && w >= 1) && (k <= 3 && k >= 1))
                {
                    //jest dobrze
                }
                else
                {
                    if (w > 3)
                    {
                        w = 3;
                    }

                    if (w < 1)
                    {
                        w = 1;
                    }

                    if (k > 3)
                    {
                        k = 3;
                    }

                    if (k < 1)
                    {
                        k = 1;
                    }

                }
                if (Plansze[w-1][k-1] == 0)
                {

                    Plansze[w-1][k-1] = 1;


                    if (Plansze[w-1][0] == 1 && Plansze[w-1][1] == 1 && Plansze[w-1][2] == 1)
                    {
                        PokarzPalete(Plansze);
                        cout << endl;
                        Pokawygranego(imie1, imie2, Plansze[w - 1][k - 1]);
                        cout << endl;
                        break;
                    }
                    if (Plansze[0][k - 1] == 1 && Plansze[1][k - 1] == 1 && Plansze[2][k - 1] == 1)
                    {
                        PokarzPalete(Plansze);
                        cout << endl;
                        Pokawygranego(imie1, imie2, Plansze[w - 1][k - 1]);
                        cout << endl;
                        break;
                    }
                    if (Plansze[0][0] == 1 && Plansze[1][1] == 1 && Plansze[2][2] == 1)
                    {
                        PokarzPalete(Plansze);
                        cout << endl;
                        Pokawygranego(imie1, imie2, Plansze[w - 1][k - 1]);
                        cout << endl;
                        break;
                    }
                    if (Plansze[0][2] == 1 && Plansze[1][1] == 1 && Plansze[2][0] == 1)
                    {
                        PokarzPalete(Plansze);
                        cout << endl;
                        Pokawygranego(imie1, imie2, Plansze[w - 1][k - 1]);
                        cout << endl;
                        break;
                    }

                    isFirstPlayer = false;

                    continue;
                }
                else
                {
                    cout << endl;
                    cout << "Kratka zaznaczona, wybierz inna ";
                    cout << endl;
                    continue;
                }

            }
            else
            {
                if(isFirstPlayer==false)
                {
                    cout << "Wybierz wiersz: ";
                    cin >> w;
                    cout << "Wybierz kolumne: ";
                    cin >> k;

                    if ((w <= 3 && w >= 1) && (k <= 3 && k >= 1))
                    {
                        //jest dobrze
                    }
                    else
                    {
                        if (w > 3)
                        {
                            w = 3;
                        }

                        if (w < 1)
                        {
                            w = 1;
                        }

                        if (k > 3)
                        {
                            k = 3;
                        }

                        if (k < 1)
                        {
                            k = 1;
                        }

                    }

                    if (Plansze[w - 1][k - 1] == 0)
                    {

                        Plansze[w - 1][k - 1] = 2;



                        if (Plansze[w - 1][0] == 2 && Plansze[w - 1][1] == 2 && Plansze[w - 1][2] == 2)
                        {
                            PokarzPalete(Plansze);
                            cout << endl;
                            Pokawygranego(imie1, imie2, Plansze[w - 1][k - 1]);
                            cout << endl;
                            break;
                        }
                        if (Plansze[0][k - 1] == 2 && Plansze[1][k - 1] == 2 && Plansze[2][k - 1] == 2)
                        {
                            PokarzPalete(Plansze);
                            cout << endl;
                            Pokawygranego(imie1, imie2, Plansze[w - 1][k - 1]);
                            cout << endl;
                            break;
                        }


                        isFirstPlayer = true;

                        continue;
                    }
                    else
                    {
                        cout << endl;
                        cout << "Kratka zaznaczona, wybierz inna ";
                        cout << endl;
                        continue;
                    }


                }
            }
        }


    }














}



