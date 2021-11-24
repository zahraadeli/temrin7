#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<chrono>
using namespace std;

char game[3][3] = { {'_','_','_'},
     {'_','_','_'},
     {'_','_','_'} };

void game_board();

bool check_winner(char s) {
    int f = 0, m = 0;
    if (game[0][0] == s && game[0][1] == s && game[0][2] == s)
        f = 1;
    else if (game[1][0] == s && game[1][1] == s && game[1][2] == s)
        f = 1;
    else if (game[2][0] == s && game[2][1] == s && game[2][2] == s)
        f = 1;
    else if (game[0][0] == s && game[1][0] == s && game[2][0] == s)
        f = 1;
    else if (game[0][1] == s && game[1][1] == s && game[2][1] == s)
        f = 1;
    else if (game[0][2] == s && game[1][2] == s && game[2][2] == s)
        f = 1;
    else if (game[0][0] == s && game[1][1] == s && game[2][2] == s)
        f = 1;
    else if (game[0][2] == s && game[1][1] == s && game[2][0] == s)
        f = 1;

    if (f) {
        if (s == 'x')
        {
            cout << "player 1 win." << endl;
        }
        else
        {
            cout << "player 2 win." << endl;
        }
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (game[i][j] != '_')
                m++;
        }

    }
    if (m == 9)
    {
        cout << "mosavi." << endl;
        return true;
    }
    return false;
}

int main()
{
    auto start = chrono::steady_clock::now();
    int row, column, f;
    game_board();
    cout << "baray 2 nafare add 1 v baray 1 nafare add 0 vared konid : ";
    cin >> f;
    while (true) {
        cout << "Player 1 : \n";
        while (true)
        {
            cout << "Enter the row between(0-2): ";
            cin >> row;
            cout << "Enter the column between(0-2): ";
            cin >> column;
            if (0 <= row && row <= 2 && 0 <= column && column <= 2)
            {
                if (game[row][column] == '_')
                {
                    game[row][column] = 'x';
                    break;
                }
                else
                {
                    cout << "is not empty!\n";
                }
            }
            else
            {
                cout << "out of range!\n";
            }
        }
        game_board();
        if (check_winner('x')) {
            break;
        }
        cout << "Player 2 : \n";
        while (true)
        {
            if (f) {
                cout << "Enter the row between(0-2): ";
                cin >> row;
                cout << "Enter the column between(0-2): ";
                cin >> column;
            }
            else {
                srand(time(0));
                do
                {
                    row = rand() % 2;
                    column = rand() % 2;
                    if (game[row][column] == '_')
                        break;
                    for (int i = 0; i < 3; i++)
                    {
                        if (game[row][i] == '_')
                            column = i;
                    }

                } while (game[row][column] != '_');

            }
            if (0 <= row && row <= 2 && 0 <= column && column <= 2)
            {
                if (game[row][column] == '_')
                {
                    game[row][column] = 'o';
                    break;
                }
                else
                {
                    cout << "is not empty!\n";
                }
            }
            else
            {
                cout << "out of range!\n";
            }
        }
        game_board();
        if (check_winner('o')) {
            break;
        }
    }
    auto end = chrono::steady_clock::now();
    cout << "zaman = " << chrono::duration<double, milli>(end - start).count() / 1000 << " s" << endl;
    system("pause");
    return 0;
}

void game_board() {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << game[i][j] << " ";
        }
        cout << endl;
    }