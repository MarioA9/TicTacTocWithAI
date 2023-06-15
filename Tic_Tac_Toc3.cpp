#include <iostream>
#include <vector>

using namespace std;

void game1(char turno, int fila, int columna, int jugadas, char tablero[3][3], int winner);
void game2(char turno, int fila, int columna, int jugadas, char tablero[3][3], int winner);

int main()
{

    char tablero[3][3];
    char player;
    char option;
    char AI;   
    char turno=1;
    int fila = 0;
    int columna = 0;
    int jugadas = 0;
    int winner = 0;

    do {
        system("cls");
        cout << "bienvenido a TicTacToc, vamos a jugar" << endl;
        cout << "quieres empezar tu?" << endl << "y" << endl << "n" << endl;
        cin >> option;
    } while (option != 'y' && option != 'n');
    switch (option)
    {
    case 'y':
        player = 'x';
        AI = 'o';
        cout << "jugador es " << player << " y la computadora es " << AI << endl;
        game1(turno, fila, columna, jugadas, tablero, winner);
        break;

    case 'n':
        player = 'o';
        AI = 'x';
        cout << "jugador es " << player << " y la computadora es " << AI << endl;
        game2(turno, fila, columna, jugadas, tablero, winner);
        break;
    }
   
}

void game1(char turno, int fila, int columna, int jugadas, char tablero[3][3], int winner)
{
    do {
        if (turno % 2 == 1)
        {
            do {
                cout << "Jugador" << endl;
                cout << "write number file" << endl;
                cin >> fila;
                cout << "write number column" << endl;
                cin >> columna;
                jugadas++;

                if (tablero[fila][columna] == 'X' || tablero[fila][columna] == '0' || fila > 2 || columna > 2)
                {
                    cout << "Its busy or not valid, try again" << endl;
                }
            } while (tablero[fila][columna] == 'X' || tablero[fila][columna] == '0' || fila > 2 || columna > 2);
            tablero[fila][columna] = 'X';

            system("cls");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << "[" << tablero[i][j] << "]";
                }
                cout << "\n";
            }
            turno++;
        }
        else if (turno % 2 == 0)
        {
            do {
                cout << "AI" << endl;
                srand((int)time(NULL));
                fila = rand() % 2;
                columna = rand() % 2;
                jugadas++;

                if (tablero[fila][columna] == 'X' || tablero[fila][columna] == '0' || fila > 2 || columna > 2)
                {
                    
                }
            } while (tablero[fila][columna] == 'X' || tablero[fila][columna] == '0' || fila > 2 || columna > 2);
            tablero[fila][columna] = '0';

            system("cls");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << "[" << tablero[i][j] << "]";
                }
                cout << "\n";
            }
            turno++;
        }
        if (tablero[0][0] == 'X' && tablero[0][0] == tablero[0][1] && tablero[0][0] == tablero[0][2] ||
            tablero[1][0] == 'X' && tablero[1][0] == tablero[1][1] && tablero[1][0] == tablero[1][2] ||
            tablero[2][0] == 'X' && tablero[2][0] == tablero[2][1] && tablero[2][0] == tablero[2][2] ||
            tablero[0][0] == 'X' && tablero[0][0] == tablero[1][0] && tablero[0][0] == tablero[2][0] ||
            tablero[0][1] == 'X' && tablero[0][1] == tablero[0][1] && tablero[1][1] == tablero[2][1] ||
            tablero[0][2] == 'X' && tablero[0][2] == tablero[1][2] && tablero[0][2] == tablero[2][2] ||
            tablero[0][0] == 'X' && tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2] ||
            tablero[0][2] == 'X' && tablero[0][2] == tablero[1][1] && tablero[0][0] == tablero[2][0])
        {
            winner++;
            cout << "congatulation player, you win!!!... " << endl;
        }


        if (tablero[0][0] == '0' && tablero[0][1] == '0' && tablero[0][2] == '0' ||//horizontal
            tablero[1][0] == '0' && tablero[1][1] == '0' && tablero[1][2] == '0' ||//horizontal
            tablero[2][0] == '0' && tablero[2][1] == '0' && tablero[2][2] == '0' ||//horizontal
            tablero[0][0] == '0' && tablero[1][0] == '0' && tablero[2][0] == '0' ||//vertical
            tablero[0][1] == '0' && tablero[1][1] == '0' && tablero[2][1] == '0' ||//vertical
            tablero[0][2] == '0' && tablero[1][2] == '0' && tablero[2][2] == '0' ||//vertical
            tablero[0][0] == '0' && tablero[1][1] == '0' && tablero[2][2] == '0' ||//diagonal
            tablero[0][2] == '0' && tablero[1][1] == '0' && tablero[2][0] == '0')//diagonal
        {
            winner++;
            cout << "congatulation AI, you win!!!... Better the next time player" << endl;
        }

        if (jugadas == 9)
        {
            winner++;
            cout << "its a draw, LOSERS!!!" << endl;
        }
    } while (winner != 1);
}

void game2(char turno, int fila, int columna, int jugadas, char tablero[3][3], int winner)
{
    do {
        if (turno % 2 == 1)
        {
            do {
                cout << "AI" << endl;
                srand((int)time(NULL));
                fila = rand() % 2;
                columna = rand() % 2;                
                jugadas++;

                if (tablero[fila][columna] == 'X' || tablero[fila][columna] == '0' || fila > 2 || columna > 2)
                {
                    
                }
            } while (tablero[fila][columna] == 'X' || tablero[fila][columna] == '0' || fila > 2 || columna > 2);
            tablero[fila][columna] = 'X';

            system("cls");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << "[" << tablero[i][j] << "]";
                }
                cout << "\n";
            }
            turno++;
        }
        else if (turno % 2 == 0)
        {
            do {
                cout << "jugador" << endl;
                cout << "write number file" << endl;
                cin >> fila;
                cout << "write number column" << endl;
                cin >> columna;
                jugadas++;

                if (tablero[fila][columna] == 'X' || tablero[fila][columna] == '0' || fila > 2 || columna > 2)
                {
                    cout << "Its busy or not valid, try again" << endl;
                }
            } while (tablero[fila][columna] == 'X' || tablero[fila][columna] == '0' || fila > 2 || columna > 2);
            tablero[fila][columna] = '0';

            system("cls");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << "[" << tablero[i][j] << "]";
                }
                cout << "\n";
            }
            turno++;
        }
        if (tablero[0][0] == 'X' && tablero[0][0] == tablero[0][1] && tablero[0][0] == tablero[0][2] ||
            tablero[1][0] == 'X' && tablero[1][0] == tablero[1][1] && tablero[1][0] == tablero[1][2] ||
            tablero[2][0] == 'X' && tablero[2][0] == tablero[2][1] && tablero[2][0] == tablero[2][2] ||
            tablero[0][0] == 'X' && tablero[0][0] == tablero[1][0] && tablero[0][0] == tablero[2][0] ||
            tablero[0][1] == 'X' && tablero[0][1] == tablero[0][1] && tablero[1][1] == tablero[2][1] ||
            tablero[0][2] == 'X' && tablero[0][2] == tablero[1][2] && tablero[0][2] == tablero[2][2] ||
            tablero[0][0] == 'X' && tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2] ||
            tablero[0][2] == 'X' && tablero[0][2] == tablero[1][1] && tablero[0][0] == tablero[2][0])
        {
            winner++;
            cout << "congatulation AI, you win!!!... Better the next time player" << endl;
        }


        if (tablero[0][0] == '0' && tablero[0][1] == '0' && tablero[0][2] == '0' ||//horizontal
            tablero[1][0] == '0' && tablero[1][1] == '0' && tablero[1][2] == '0' ||//horizontal
            tablero[2][0] == '0' && tablero[2][1] == '0' && tablero[2][2] == '0' ||//horizontal
            tablero[0][0] == '0' && tablero[1][0] == '0' && tablero[2][0] == '0' ||//vertical
            tablero[0][1] == '0' && tablero[1][1] == '0' && tablero[2][1] == '0' ||//vertical
            tablero[0][2] == '0' && tablero[1][2] == '0' && tablero[2][2] == '0' ||//vertical
            tablero[0][0] == '0' && tablero[1][1] == '0' && tablero[2][2] == '0' ||//diagonal
            tablero[0][2] == '0' && tablero[1][1] == '0' && tablero[2][0] == '0')//diagonal
        {
            winner++;
            cout << "congatulation Player, you win!!!..." << endl;
        }

        if (jugadas == 9)
        {
            winner++;
            cout << "its a draw, LOSERS!!!" << endl;
        }
    } while (winner != 1);
}


