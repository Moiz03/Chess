#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <cstring>
#include <cmath>
#include <conio.h>
using namespace std;

void gotoxy(int xpos, int ypos, int col, char ch)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos;
    scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(screen, col);
    DWORD useless;
    WriteConsole(screen, &ch, 1, (LPDWORD)&useless, NULL);
    SetConsoleTextAttribute(screen, 15);
    SMALL_RECT windowSize = {0, 0, 100, 100};
    SetConsoleWindowInfo(screen, TRUE, &windowSize);
}

void welcome()
{
    cout << "********************************************************************************" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*            ******     **                                                     *" << endl;
    cout << "*          **********   **                                                     *" << endl;
    cout << "*        ***            **                                                     *" << endl;
    cout << "*       ***             **            ****       ****        ****              *" << endl;
    cout << "*       ***             **          ********   ***  ***    ***  ***            *" << endl;
    cout << "*       ***             ** ****    ***    *** ***         ***                  *" << endl;
    cout << "*       ***             ****  **   **********   ******      ******             *" << endl;
    cout << "*        ***            ***    **  ***             *****       *****           *" << endl;
    cout << "*          **********   **     **   ****       ***   **    ***   **            *" << endl;
    cout << "*           *******     **     **     ****       *****       *****             *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                        WELCOME TO CHESS GAME                                 *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                      press any key to continue.                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "********************************************************************************" << endl
         << endl;
}

void name_piece(int i)
{
    if (i == 80 || i == 112)
    {
        cout << "PAWN";
    }
    if (i == 66 || i == 98)
    {
        cout << "BISHOP";
    }
    if (i == 78 || i == 110)
    {
        cout << "KNIGHT";
    }
    if (i == 82 || i == 114)
    {
        cout << "ROOK";
    }
    if (i == 81 || i == 113)
    {
        cout << "QUEEN";
    }
    if (i == 75 || i == 107)
    {
        cout << "KING";
    }
}

void print_board(char board[][8])
{
    cout << "   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << i << " ";
        for (int j = 0; j < 8; j++)
        {
            cout << " | " << board[i][j] << " ";
        }

        cout << "|" << endl;
        cout << "    _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;

        cout << endl;
    }
    cout << "     a    b    c    d    e    f    g    h ";
    cout << endl
         << endl;
}

void promtion_helper(char board[][8], int a, int b, int player)
{
    int p = 0;
    if (player == 1)
    {
        while (p == 0)
        {
            char i = 0;
            cout << "WHAT PROMOTION YOU WANT TO GIVE TO YOUR PAWN?" << endl
                 << endl;
            cout << "if you want to make it  'QUEEN'       ENTER 1" << endl;
            cout << "if you want to make it  'KNIGHT'      ENTER 2" << endl;
            cout << "if you want to make it  'ROOK'        ENTER 3" << endl;
            cout << "if you want to make it  'BISHOP'      ENTER 4" << endl;

            cin >> i;

            if (i == '1')
            {
                board[a][b] = 'q';
                p++;
            }
            if (i == '2')
            {
                board[a][b] = 'n';
                p++;
            }
            if (i == '3')
            {
                board[a][b] = 'r';
                p++;
            }
            if (i == '4')
            {
                board[a][b] = 'b';
                p++;
            }
            if (p == 0)
            {
                cout << endl
                     << endl;
                cout << "INVALID VALUE!!!  ENTER AGAIN" << endl;
                Sleep(1000);
                system("cls");
            }
        }
    }

    if (player == 2)
    {
        while (p == 0)
        {
            char i = 0;
            cout << "WHAT PROMOTION YOU WANT TO GIVE TO YOUR PAWN?" << endl
                 << endl;
            cout << "if you want to make it  'QUEEN'       ENTER 1" << endl;
            cout << "if you want to make it  'KNIGHT'      ENTER 2" << endl;
            cout << "if you want to make it  'ROOK'        ENTER 3" << endl;
            cout << "if you want to make it  'BISHOP'      ENTER 4" << endl;

            cin >> i;

            if (i == '1')
            {
                board[a][b] = 'Q';
                p++;
            }
            if (i == '2')
            {
                board[a][b] = 'N';
                p++;
            }
            if (i == '3')
            {
                board[a][b] = 'R';
                p++;
            }
            if (i == '4')
            {
                board[a][b] = 'B';
                p++;
            }
            if (p == 0)
            {
                cout << endl
                     << endl;
                cout << "INVALID VALUE!!!  ENTER AGAIN" << endl;
                Sleep(1000);
                system("cls");
            }
        }
    }
}

void swap_it(char board[][8], int a, int b, int c, int d)
{
    board[c][d] = board[a][b];
    board[a][b] = ' ';

    print_board(board);
}

void swap_only(char board[][8], int a, int b, int c, int d)
{
    board[c][d] = board[a][b];
    board[a][b] = ' ';
}

bool valid_turn(char board[][8], int i, int j, int p)
{
    int yo = (int)board[i][j];
    if (p == 1)
    {
        if (yo >= 65 && yo <= 90)
        {
            cout << "=============================" << endl;
            cout << "That's not your piece, bro!!!" << endl;
            cout << "=============================" << endl
                 << endl;
            return false;
        }
    }
    if (p == 2)
    {
        if (yo >= 97 && yo <= 122)
        {
            cout << "=============================" << endl;
            cout << "That's not your piece, bro!!!" << endl;
            cout << "=============================" << endl
                 << endl;
            return false;
        }
    }
    return true;
}

bool valid_piece(char board[][8], int i, int j, int x, int y, int p)
{
    int xo = (int)board[i][j];
    int zo = (int)board[x][y];
    if (p == 1)
    {
        if ((zo >= 97 && zo <= 122) && (xo >= 97 && xo <= 122))
        {
            cout << "===============================" << endl;
            cout << "You already have a piece there." << endl;
            cout << "===============================" << endl
                 << endl;
            return false;
        }
    }
    else if (p == 2)
    {
        if ((zo >= 65 && zo <= 90) && (xo >= 65 && xo <= 90))
        {
            cout << "===============================" << endl;
            cout << "You already have a piece there." << endl;
            cout << "===============================" << endl
                 << endl;
            return false;
        }
    }
    return true;
}

bool valid_place(char board[][8], int i, int j)
{
    if (board[i][j] == ' ')
    {
        cout << "=============================================" << endl;
        cout << "There's no piece at the specified location!!!" << endl;
        cout << "=============================================" << endl
             << endl;
        return false;
    }
    return true;
}

bool checkmate_helper(char board[][8], int i, int j, int x, int y, int p)
{
    int xo = (int)board[i][j];
    int zo = (int)board[x][y];
    if (p == 1)
    {
        if ((zo >= 97 && zo <= 122) && (xo >= 97 && xo <= 122))
        {
            return false;
        }
    }
    else if (p == 2)
    {
        if ((zo >= 65 && zo <= 90) && (xo >= 65 && xo <= 90))
        {
            return false;
        }
    }
    return true;
}

bool W_Pawn_move(char board[][8], int a, int b, int c, int d, int m, int n)
{
    int xo = (int)board[c][d];

    if (m >= 0)
    {
        cout << "===========================" << endl;
        cout << "Pawns can't move like that." << endl;
        cout << "===========================" << endl
             << endl;
        return false;
    }
    if (n < -1 || n > 1)
    {
        cout << "===========================" << endl;
        cout << "Pawns can't move like that." << endl;
        cout << "===========================" << endl
             << endl;
        return false;
    }
    if (b != d && board[c][d] == ' ' && m == -1)
    {
        cout << "===================================================" << endl;
        cout << "There must be an enemy piece for you to move there." << endl;
        cout << "===================================================" << endl
             << endl;
        return false;
    }
    if (a != 6 && m <= -2)
    {
        cout << "=============================================" << endl;
        cout << "Pawns can move two spaces on first move only." << endl;
        cout << "=============================================" << endl
             << endl;
        return false;
    }
    if (a == 6 && m < -2)
    {
        cout << "=================================================" << endl;
        cout << "Pawns may move 2 spaces forward their first move." << endl;
        cout << "=================================================" << endl
             << endl;
        return false;
    }
    if (m == -1 && board[c][d] != ' ' && n == 0)
    {
        cout << "=====================================" << endl;
        cout << "An enemy piece is blocking your move!" << endl;
        cout << "=====================================" << endl
             << endl;
        return false;
    }
    if (a == 6 && m == -2 && board[c][d] != ' ')
    {
        cout << "==============================================" << endl;
        cout << "There is already a piece at that position!    " << endl;
        cout << "==============================================" << endl
             << endl;
        return false;
    }
    if (b != d && (xo >= 65 && xo <= 90) && m == -1)
    {
        cout << "===================================" << endl;
        cout << "you have taken the enemy's ";
        name_piece(xo);
        cout << " !!!" << endl;
        cout << "===================================" << endl
             << endl;
        Sleep(1000);
        return true;
    }

    return true;
}

bool check_W_pawn(char board[][8], int a, int b)
{
    int c = a - 1;
    int d = b + 1;
    int m = c - a;
    if (c > 0 && c < 8 && d > 0 && d < 8)
    {
        if (b != d && board[c][d] == 'K' && m == -1)
        {
            cout << "===================================================" << endl;
            cout << "You're in CHECK!!!   You have to do something bro  " << endl;
            cout << "===================================================" << endl
                 << endl;
            return false;
        }
    }

    d = b - 1;

    if (c > 0 && c < 8 && d > 0 && d < 8)
    {
        if (b != d && board[c][d] == 'K' && m == -1)
        {
            cout << "===================================================" << endl;
            cout << "You're in CHECK!!!   You have to do something bro  " << endl;
            cout << "===================================================" << endl
                 << endl;
            return false;
        }
    }

    return true;
}

bool B_Pawn_move(char board[][8], int a, int b, int c, int d, int m, int n)
{
    int xo = (int)board[c][d];

    if (m <= 0)
    {
        cout << "======================" << endl;
        cout << "Pawns  move like that." << endl;
        cout << "======================" << endl
             << endl;
        return false;
    }
    if (n < -1 || n > 1)
    {
        cout << "======================" << endl;
        cout << "Pawns  move like that." << endl;
        cout << "======================" << endl
             << endl;
        return false;
    }
    if (b != d && board[c][d] == ' ' && m == 1)
    {
        cout << "===================================================" << endl;
        cout << "There must be an enemy piece for you to move there." << endl;
        cout << "===================================================" << endl
             << endl;
        return false;
    }
    if (a != 1 && m >= 2)
    {
        cout << "=============================================" << endl;
        cout << "Pawns can move two spaces on first move only." << endl;
        cout << "=============================================" << endl
             << endl;
        return false;
    }
    if (a == 1 && m > 2)
    {
        cout << "=================================================" << endl;
        cout << "Pawns may move 2 spaces forward their first move." << endl;
        cout << "=================================================" << endl
             << endl;
        return false;
    }
    if (m == 1 && board[c][d] != ' ' && n == 0)
    {
        cout << "=====================================" << endl;
        cout << "An enemy piece is blocking your move!" << endl;
        cout << "=====================================" << endl
             << endl;
        return false;
    }
    if (a == 1 && m == 2 && board[c][d] != ' ')
    {
        cout << "==============================================" << endl;
        cout << "There is already a piece at that position!    " << endl;
        cout << "==============================================" << endl
             << endl;
        return false;
    }
    if (b != d && (xo >= 97 && xo <= 122) && m == 1)
    {
        cout << "===================================" << endl;
        cout << "you have taken the enemy's ";
        name_piece(xo);
        cout << " !!!" << endl;
        cout << "===================================" << endl
             << endl;
        Sleep(1000);
        return true;
    }

    return true;
}

bool check_B_pawn(char board[][8], int a, int b)
{
    int c = a + 1;
    int d = b + 1;
    int m = c - a;
    if (c > 0 && c < 8 && d > 0 && d < 8)
    {
        if (b != d && board[c][d] == 'k' && m == 1)
        {
            cout << "===================================================" << endl;
            cout << "You're in CHECK!!!   You have to do something bro  " << endl;
            cout << "===================================================" << endl
                 << endl;
            return false;
        }
    }

    d = b - 1;

    if (c > 0 && c < 8 && d > 0 && d < 8)
    {
        if (b != d && board[c][d] == 'k' && m == 1)
        {
            cout << "===================================================" << endl;
            cout << "You're in CHECK!!!   You have to do something bro  " << endl;
            cout << "===================================================" << endl
                 << endl;
            return false;
        }
    }

    return true;
}

bool Bishop_move(char board[][8], int a, int b, int c, int d, int m, int n, int y, int z)
{
    int xo = (int)board[c][d];
    if (abs(m) != abs(n))
    {
        cout << "=============================" << endl;
        cout << "Bishops can't move like that." << endl;
        cout << "=============================" << endl
             << endl;
        return false;
    }
    if (m > 0 && n > 0)
    {
        for (int i = a + 1, j = b + 1; i < c && j < d; i++, j++)
        {
            if (board[i][j] != ' ')
            {
                cout << "===================================" << endl;
                cout << "There's a piece blocking your move!" << endl;
                cout << "===================================" << endl
                     << endl;
                return false;
            }
        }
    }
    if (m < 0 && n < 0)
    {
        for (int i = a - 1, j = b - 1; i > c && j > d; i--, j--)
        {
            if (board[i][j] != ' ')
            {
                cout << "===================================" << endl;
                cout << "There's a piece blocking your move!" << endl;
                cout << "===================================" << endl
                     << endl;
                return false;
            }
        }
    }
    if (m > 0 && n < 0)
    {
        for (int i = a + 1, j = b - 1; i < c && j > d; i++, j--)
        {
            if (board[i][j] != ' ')
            {
                cout << "===================================" << endl;
                cout << "There's a piece blocking your move!" << endl;
                cout << "===================================" << endl
                     << endl;
                return false;
            }
        }
    }
    if (m < 0 && n > 0)
    {
        for (int i = a - 1, j = b + 1; i > c && j < d; i--, j++)
        {
            if (board[i][j] != ' ')
            {
                cout << "===================================" << endl;
                cout << "There's4 a piece blocking your move!" << endl;
                cout << "===================================" << endl
                     << endl;
                return false;
            }
        }
    }
    if (board[c][d] != ' ' && (xo >= y && xo <= z))
    {
        cout << "===================================" << endl;
        cout << "you have taken the enemy's ";
        name_piece(xo);
        cout << " !!!" << endl;
        cout << "===================================" << endl
             << endl;
        Sleep(1000);
        return true;
    }
    return true;
}

bool check_Bishop(char board[][8], int a, int b, int q)
{
    bool flag = true;
    int p = 0, w = 0;
    if (flag == true && w == 0)
    {
        for (int i = a + 1, j = b + 1; i < 8 && j < 8 && p == 0; i++, j++)
        {
            if (board[i][j] != ' ')
            {
                if ((int)board[i][j] == q && p == 0)
                {
                    cout << "===================================================" << endl;
                    cout << "You're in CHECK!!!   You have to do something bro  " << endl;
                    cout << "===================================================" << endl
                         << endl;
                    flag = false;
                    w++;
                }
                p++;
            }
        }
    }
    p = 0;
    if (flag == true && w == 0)
    {
        for (int i = a - 1, j = b - 1; i >= 0 && j >= 0 && p == 0; i--, j--)
        {
            if (board[i][j] != ' ')
            {
                if ((int)board[i][j] == q && p == 0)
                {
                    cout << "===================================================" << endl;
                    cout << "You're in CHECK!!!   You have to do something bro  " << endl;
                    cout << "===================================================" << endl
                         << endl;
                    flag = false;
                    w++;
                }
                p++;
            }
        }
    }
    p = 0;
    if (flag == true && w == 0)
    {
        for (int i = a + 1, j = b - 1; i < 8 && j >= 0 && p == 0; i++, j--)
        {
            if (board[i][j] != ' ')
            {
                if (int(board[i][j]) == q && p == 0)
                {
                    cout << "===================================================" << endl;
                    cout << "You're in CHECK!!!   You have to do something bro  " << endl;
                    cout << "===================================================" << endl
                         << endl;
                    flag = false;
                    w++;
                }
            }
            p++;
        }
    }
    p = 0;
    if (flag == true && w == 0)
    {
        for (int i = a - 1, j = b + 1; i >= 0 && j < 8 && p == 0; i--, j++)
        {
            if (board[i][j] != ' ')
            {
                if ((int)board[i][j] == q && p == 0)
                {
                    cout << "===================================================" << endl;
                    cout << "You're in CHECK!!!   You have to do something bro  " << endl;
                    cout << "===================================================" << endl
                         << endl;
                    flag = false;
                    w++;
                }
                p++;
            }
        }
    }
    if (flag == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool B_King_move(char board[][8], int a, int b, int c, int d, int m, int n)
{
    int xo = (int)board[c][d];
    if (abs(m) > 1 || abs(n) > 1)
    {
        cout << "========================================" << endl;
        cout << "Kings may only move one space at a time." << endl;
        cout << "========================================" << endl
             << endl;
        return false;
    }
    if (board[c][d] != ' ' && (xo >= 97 && xo <= 122))
    {
        cout << "===================================" << endl;
        cout << "you have taken the enemy's ";
        name_piece(xo);
        cout << " !!!" << endl;
        cout << "===================================" << endl
             << endl;
        Sleep(1000);
        return true;
    }
    return true;
}

bool W_King_move(char board[][8], int a, int b, int c, int d, int m, int n)
{
    int xo = (int)board[c][d];
    if (abs(m) > 1 || abs(n) > 1)
    {
        cout << "========================================" << endl;
        cout << "Kings may only move one space at a time." << endl;
        cout << "========================================" << endl
             << endl;
        return false;
    }
    if (board[c][d] != ' ' && (xo >= 65 && xo <= 90))
    {
        cout << "===================================" << endl;
        cout << "you have taken the enemy's ";
        name_piece(xo);
        cout << " !!!" << endl;
        cout << "===================================" << endl
             << endl;
        Sleep(1000);
        return true;
    }
    return true;
}

bool Queen_move(char board[][8], int a, int b, int c, int d, int m, int n, int y, int z)
{
    int xo = (int)board[c][d];
    if (abs(m) != abs(n) && m != 0 && n != 0)
    {
        cout << "=======================================================" << endl;
        cout << "Queens can do a lot of things, but they can't apparate." << endl;
        cout << "=======================================================" << endl
             << endl;
        return false;
    }

    if (m > 0 && n > 0)
    {
        for (int i = a + 1, j = b + 1; i < c && j < d; i++, j++)
        {
            if (board[i][j] != ' ')
            {
                cout << "===================================" << endl;
                cout << "There's a piece blocking your move!" << endl;
                cout << "===================================" << endl
                     << endl;
                return false;
            }
        }
    }
    if (m < 0 && n < 0)
    {
        for (int i = a - 1, j = b - 1; i > c && j > d; i--, j--)
        {
            if (board[i][j] != ' ')
            {
                cout << "===================================" << endl;
                cout << "There's a piece blocking your move!" << endl;
                cout << "===================================" << endl
                     << endl;
                return false;
            }
        }
    }
    if (m > 0 && n < 0)
    {
        for (int i = a + 1, j = b - 1; i < c && j > d; i++, j--)
        {
            if (board[i][j] != ' ')
            {
                cout << "===================================" << endl;
                cout << "There's a piece blocking your move!" << endl;
                cout << "===================================" << endl
                     << endl;
                return false;
            }
        }
    }
    if (m < 0 && n > 0)
    {
        for (int i = a - 1, j = b + 1; i > c && j < d; i--, j++)
        {
            if (board[i][j] != ' ')
            {
                cout << "===================================" << endl;
                cout << "There's4 a piece blocking your move!" << endl;
                cout << "===================================" << endl
                     << endl;
                return false;
            }
        }
    }
    if (m == 0 && n > 0)
    {
        for (int i = b + 1; i < d; i++)
        {
            if (board[a][i] != ' ')
            {
                cout << "===================================" << endl;
                cout << "There's a piece blocking your move!" << endl;
                cout << "===================================" << endl
                     << endl;
                return false;
            }
        }
    }
    if (m == 0 && n < 0)
    {
        for (int i = b - 1; i > d; i--)
        {
            if (board[a][i] != ' ')
            {
                cout << "===================================" << endl;
                cout << "There's a piece blocking your move!" << endl;
                cout << "===================================" << endl
                     << endl;
                return false;
            }
        }
    }
    if (m > 0 && n == 0)
    {
        for (int i = a + 1; i < c; i++)
        {
            if (board[i][b] != ' ')
            {
                cout << "===================================" << endl;
                cout << "There's a piece blocking your move!" << endl;
                cout << "===================================" << endl
                     << endl;
                return false;
            }
        }
    }
    if (m < 0 && n == 0)
    {
        for (int i = a - 1; i > c; i--)
        {
            if (board[i][b] != ' ')
            {
                cout << "===================================" << endl;
                cout << "There's a piece blocking your move!" << endl;
                cout << "===================================" << endl
                     << endl;
                return false;
            }
        }
    }
    if (board[c][d] != ' ' && (xo >= y && xo <= z))
    {
        cout << "===================================" << endl;
        cout << "you have taken the enemy's ";
        name_piece(xo);
        cout << " !!!" << endl;
        cout << "===================================" << endl
             << endl;
        Sleep(1000);
        return true;
    }
    return true;
}

bool check_Queen(char board[][8], int a, int b, int q)
{
    int p = 0, w = 0;
    bool flag = true;
    if (flag == true && w == 0)
    {
        for (int i = b + 1; i < 8 && p == 0; i++)
        {
            if (board[a][i] != ' ')
            {
                if (int(board[a][i]) == q && p == 0)
                {
                    cout << "===================================================" << endl;
                    cout << "You're in CHECK!!!   You have to do something bro  " << endl;
                    cout << "===================================================" << endl
                         << endl;
                    flag = false;
                    w++;
                }
                p++;
            }
        }
    }
    p = 0;
    if (flag == true && w == 0)
    {
        for (int i = b - 1; i >= 0 && p == 0; i--)
        {
            if (board[a][i] != ' ')
            {
                if (int(board[a][i]) == q && p == 0)
                {
                    cout << "===================================================" << endl;
                    cout << "You're in CHECK!!!   You have to do something bro  " << endl;
                    cout << "===================================================" << endl
                         << endl;
                    flag = false;
                    w++;
                }
                p++;
            }
        }
    }
    p = 0;
    if (flag == true && w == 0)
    {
        for (int i = a + 1; i < 8 && p == 0; i++)
        {
            if (board[i][b] != ' ')
            {
                if ((int)board[i][b] == q && p == 0)
                {
                    cout << "===================================================" << endl;
                    cout << "You're in CHECK!!!   You have to do something bro  " << endl;
                    cout << "===================================================" << endl
                         << endl;
                    flag = false;
                    w++;
                }
                p++;
            }
        }
    }
    p = 0;
    if (flag == true && w == 0)
    {
        for (int i = a - 1; i >= 0 && p == 0; i--)
        {
            if (board[i][b] != ' ')
            {
                if ((int)board[i][b] == q && p == 0)
                {
                    cout << "===================================================" << endl;
                    cout << "You're in CHECK!!!   You have to do something bro  " << endl;
                    cout << "===================================================" << endl
                         << endl;
                    flag = false;
                    w++;
                }
                p++;
            }
        }
    }
    p = 0;
    if (flag == true && w == 0)
    {
        for (int i = a + 1, j = b + 1; i < 8 && j < 8 && p == 0; i++, j++)
        {
            if (board[i][j] != ' ')
            {
                if ((int)board[i][j] == q && p == 0)
                {
                    cout << "===================================================" << endl;
                    cout << "You're in CHECK!!!   You have to do something bro  " << endl;
                    cout << "===================================================" << endl
                         << endl;
                    flag = false;
                    w++;
                }
                p++;
            }
        }
    }
    p = 0;
    if (flag == true && w == 0)
    {
        for (int i = a - 1, j = b - 1; i >= 0 && j >= 0 && p == 0; i--, j--)
        {
            if (board[i][j] != ' ')
            {
                if ((int)board[i][j] == q && p == 0)
                {
                    cout << "===================================================" << endl;
                    cout << "You're in CHECK!!!   You have to do something bro  " << endl;
                    cout << "===================================================" << endl
                         << endl;
                    flag = false;
                    w++;
                }
                p++;
            }
        }
    }
    p = 0;
    if (flag == true && w == 0)
    {
        for (int i = a + 1, j = b - 1; i < 8 && j >= 0 && p == 0; i++, j--)
        {
            if (board[i][j] != ' ')
            {
                if (int(board[i][j]) == q && p == 0)
                {
                    cout << "===================================================" << endl;
                    cout << "You're in CHECK!!!   You have to do something bro  " << endl;
                    cout << "===================================================" << endl
                         << endl;
                    flag = false;
                    w++;
                }
            }
            p++;
        }
    }
    p = 0;
    if (flag == true && w == 0)
    {
        for (int i = a - 1, j = b + 1; i >= 0 && j < 8 && p == 0; i--, j++)
        {
            if (board[i][j] != ' ')
            {
                if ((int)board[i][j] == q && p == 0)
                {
                    cout << "===================================================" << endl;
                    cout << "You're in CHECK!!!   You have to do something bro  " << endl;
                    cout << "===================================================" << endl
                         << endl;
                    flag = false;
                    w++;
                }
                p++;
            }
        }
    }
    if (flag == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Knight_move(char board[][8], int a, int b, int c, int d, int m, int n, int y, int z)
{
    int xo = (int)board[c][d];
    if (abs(m) * abs(n) != 2)
    {
        cout << "=============================" << endl;
        cout << "Knights can't move like that." << endl;
        cout << "=============================" << endl
             << endl;
        return false;
    }
    if (board[c][d] != ' ' && (xo >= y && xo <= z))
    {
        cout << "===================================" << endl;
        cout << "you have taken the enemy's ";
        name_piece(xo);
        cout << " !!!" << endl;
        cout << "===================================" << endl
             << endl;
        Sleep(1000);
        return true;
    }
    return true;
}

bool check_Knight(char board[][8], int a, int b, int q)
{
    bool flag = true;
    if (flag == true)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                int m = i - a;
                int n = j - b;
                if (abs(m) * abs(n) == 2 && int(board[i][j] == q))
                {
                    cout << "===================================================" << endl;
                    cout << "You're in CHECK!!!   You have to do something bro  " << endl;
                    cout << "===================================================" << endl
                         << endl;
                    flag = false;
                }
            }
        }
    }

    if (flag == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Rook_move(char board[][8], int a, int b, int c, int d, int m, int n, int y, int z)
{
    int xo = (int)board[c][d];
    if (m != 0 && n != 0)
    {
        cout << "===========================" << endl;
        cout << "Rooks can't move like that." << endl;
        cout << "===========================" << endl
             << endl;
        return false;
    }
    if (m == 0 && n > 0)
    {
        for (int i = b + 1; i < d; i++)
        {
            if (board[a][i] != ' ')
            {
                cout << "===================================" << endl;
                cout << "There's a piece blocking your move!" << endl;
                cout << "===================================" << endl
                     << endl;
                return false;
            }
        }
    }
    if (m == 0 && n < 0)
    {
        for (int i = b - 1; i > d; i--)
        {
            if (board[a][i] != ' ')
            {
                cout << "===================================" << endl;
                cout << "There's a piece blocking your move!" << endl;
                cout << "===================================" << endl
                     << endl;
                return false;
            }
        }
    }
    if (m > 0 && n == 0)
    {
        for (int i = a + 1; i < c; i++)
        {
            if (board[i][b] != ' ')
            {
                cout << "===================================" << endl;
                cout << "There's a piece blocking your move!" << endl;
                cout << "===================================" << endl
                     << endl;
                return false;
            }
        }
    }
    if (m < 0 && n == 0)
    {
        for (int i = a - 1; i > c; i--)
        {
            if (board[i][b] != ' ')
            {
                cout << "===================================" << endl;
                cout << "There's a piece blocking your move!" << endl;
                cout << "===================================" << endl
                     << endl;
                return false;
            }
        }
    }
    if (board[c][d] != ' ' && (xo >= y && xo <= z))
    {
        cout << "===================================" << endl;
        cout << "you have taken the enemy's ";
        name_piece(xo);
        cout << " !!!" << endl;
        cout << "===================================" << endl
             << endl;
        Sleep(1000);
        return true;
    }
    return true;
}

bool check_Rook(char board[][8], int a, int b, int q)
{
    int p = 0, w = 0;
    bool flag = true;
    if (flag == true && w == 0)
    {
        for (int i = b + 1; i < 8 && p == 0; i++)
        {
            if (board[a][i] != ' ')
            {
                if (int(board[a][i]) == q && p == 0)
                {
                    cout << "===================================================" << endl;
                    cout << "You're in CHECK!!!   You have to do something bro  " << endl;
                    cout << "===================================================" << endl
                         << endl;
                    flag = false;
                    w++;
                }
                p++;
            }
        }
    }
    p = 0;
    if (flag == true && w == 0)
    {
        for (int i = b - 1; i >= 0 && p == 0; i--)
        {
            if (board[a][i] != ' ')
            {
                if (int(board[a][i]) == q && p == 0)
                {
                    cout << "===================================================" << endl;
                    cout << "You're in CHECK!!!   You have to do something bro  " << endl;
                    cout << "===================================================" << endl
                         << endl;
                    flag = false;
                    w++;
                }
                p++;
            }
        }
    }
    p = 0;
    if (flag == true && w == 0)
    {
        for (int i = a + 1; i < 8 && p == 0; i++)
        {
            if (board[i][b] != ' ')
            {
                if ((int)board[i][b] == q && p == 0)
                {
                    cout << "===================================================" << endl;
                    cout << "You're in CHECK!!!   You have to do something bro  " << endl;
                    cout << "===================================================" << endl
                         << endl;
                    flag = false;
                    w++;
                }
                p++;
            }
        }
    }
    p = 0;
    if (flag == true && w == 0)
    {
        for (int i = a - 1; i >= 0 && p == 0; i--)
        {
            if (board[i][b] != ' ')
            {
                if ((int)board[i][b] == q && p == 0)
                {
                    cout << "===================================================" << endl;
                    cout << "You're in CHECK!!!   You have to do something bro  " << endl;
                    cout << "===================================================" << endl
                         << endl;
                    flag = false;
                    w++;
                }
                p++;
            }
        }
    }
    if (flag == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool check_in(char board[][8], int player)
{
    if (player == 1)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j] == 'P')
                {
                    if (check_B_pawn(board, i, j) == false)
                    {
                        return false;
                    }
                }
                if (board[i][j] == 'R')
                {
                    if (check_Rook(board, i, j, 107) == false)
                    {
                        return false;
                    }
                }
                if (board[i][j] == 'N')
                {
                    if (check_Knight(board, i, j, 107) == false)
                    {
                        return false;
                    }
                }
                if (board[i][j] == 'B')
                {
                    if (check_Bishop(board, i, j, 107) == false)
                    {
                        return false;
                    }
                }
                if (board[i][j] == 'Q')
                {
                    if (check_Queen(board, i, j, 107) == false)
                    {
                        return false;
                    }
                }
            }
        }
    }
    if (player == 2)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j] == 'p')
                {
                    if (check_W_pawn(board, i, j) == false)
                    {
                        return false;
                    }
                }
                if (board[i][j] == 'r')
                {
                    if (check_Rook(board, i, j, 75) == false)
                    {
                        return false;
                    }
                }
                if (board[i][j] == 'n')
                {
                    if (check_Knight(board, i, j, 75) == false)
                    {
                        return false;
                    }
                }
                if (board[i][j] == 'b')
                {
                    if (check_Bishop(board, i, j, 75) == false)
                    {
                        return false;
                    }
                }
                if (board[i][j] == 'q')
                {
                    if (check_Queen(board, i, j, 75) == false)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool swap_checkmate(char board[][8], int a, int b, int c, int d, int player)
{
    char temp = board[c][d];
    board[c][d] = board[a][b];
    board[a][b] = ' ';

    if (check_in(board, player) == true)
    {
        board[a][b] = board[c][d];
        board[c][d] = temp;
        return true;
    }
    else
    {
        board[a][b] = board[c][d];
        board[c][d] = temp;
        return false;
    }
}

bool checkmate_W_pawn(char board[][8], int a, int b, int player)
{
    int c = a - 1;
    int d = b + 1;
    int m = c - a;
    if (c > 0 && c < 8 && d > 0 && d < 8)
    {
        if (b != d && board[c][d] != ' ' && m == -1)
        {
            if (checkmate_helper(board, a, b, c, d, player) == true)
            {
                if (swap_checkmate(board, a, b, c, d, player) == true)
                {
                    return true;
                }
            }
        }
    }
    d = b - 1;
    if (c > 0 && c < 8 && d > 0 && d < 8)
    {
        if (b != d && board[c][d] != ' ' && m == -1)
        {
            if (checkmate_helper(board, a, b, c, d, player) == true)
            {
                if (swap_checkmate(board, a, b, c, d, player) == true)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool checkmate_B_pawn(char board[][8], int a, int b, int player)
{
    int c = a + 1;
    int d = b + 1;
    int m = c - a;
    if (c > 0 && c < 8 && d > 0 && d < 8)
    {
        if (b != d && board[c][d] != ' ' && m == -1)
        {
            if (checkmate_helper(board, a, b, c, d, player) == true)
            {
                if (swap_checkmate(board, a, b, c, d, player) == true)
                {
                    return true;
                }
            }
        }
    }
    d = b - 1;
    if (c > 0 && c < 8 && d > 0 && d < 8)
    {
        if (b != d && board[c][d] != ' ' && m == -1)
        {
            if (checkmate_helper(board, a, b, c, d, player) == true)
            {
                if (swap_checkmate(board, a, b, c, d, player) == true)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool checkmate_Knight(char board[][8], int a, int b, int player)
{
    for (int c = 0; c < 8; c++)
    {
        for (int d = 0; d < 8; d++)
        {
            int m = c - a;
            int n = d - b;
            if (abs(m) * abs(n) == 2)
            {
                if (checkmate_helper(board, a, b, c, d, player) == true)
                {
                    if (swap_checkmate(board, a, b, c, d, player) == true)
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool checkmate_Bishop(char board[][8], int a, int b, int player)
{
    bool flag = false;
    int p = 0;
    if (flag == false)
    {
        for (int c = a + 1, d = b + 1; c < 8 && d < 8 && p == 0; c++, d++)
        {
            if (board[c][d] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, c, d, player) == true)
            {
                if (swap_checkmate(board, a, b, c, d, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, c, d, player) == false)
            {
                p++;
            }
            flag = false;
        }
    }
    p = 0;
    if (flag == false)
    {
        for (int c = a - 1, d = b - 1; c >= 0 && d >= 0 && p == 0; c--, d--)
        {
            if (board[c][d] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, c, d, player) == true)
            {
                if (swap_checkmate(board, a, b, c, d, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, c, d, player) == false)
            {
                p++;
            }
            flag = false;
        }
    }
    p = 0;
    if (flag == false)
    {
        for (int c = a + 1, d = b - 1; c < 8 && d >= 0 && p == 0; c++, d--)
        {
            if (board[c][d] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, c, d, player) == true)
            {
                if (swap_checkmate(board, a, b, c, d, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, c, d, player) == false)
            {
                p++;
            }
            flag = false;
        }
    }
    p = 0;
    if (flag == false)
    {
        for (int c = a - 1, d = b + 1; c >= 0 && d < 8 && p == 0; c--, d++)
        {
            if (board[c][d] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, c, d, player) == true)
            {
                if (swap_checkmate(board, a, b, c, d, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, c, d, player) == false)
            {
                p++;
            }
            flag = false;
        }
    }
    if (flag == false)
    {
        return false;
    }
    return true;
}

bool checkmate_Rook(char board[][8], int a, int b, int player)
{
    int p = 0;
    bool flag = false;
    if (flag == false)
    {
        for (int d = b + 1; d < 8 && p == 0; d++)
        {
            if (board[a][d] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, a, d, player) == true)
            {
                if (swap_checkmate(board, a, b, a, d, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, a, d, player) == false)
            {
                p++;
                flag = false;
            }
        }
    }
    p = 0;
    if (flag == false)
    {
        for (int d = b - 1; d >= 0 && p == 0; d--)
        {
            if (board[a][d] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, a, d, player) == true)
            {
                if (swap_checkmate(board, a, b, a, d, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, a, d, player) == false)
            {
                p++;
                flag = false;
            }
        }
    }
    p = 0;
    if (flag == false)
    {
        for (int c = a + 1; c < 8 && p == 0; c++)
        {
            if (board[c][b] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, c, b, player) == true)
            {
                if (swap_checkmate(board, a, b, c, b, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, c, b, player) == false)
            {
                p++;
                flag = false;
            }
        }
    }
    p = 0;
    if (flag == false)
    {
        for (int c = a - 1; c >= 0 && p == 0; c--)
        {
            if (board[c][b] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, c, b, player) == true)
            {
                if (swap_checkmate(board, a, b, c, b, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, c, b, player) == false)
            {
                p++;
                flag = false;
            }
        }
    }
    if (flag == false)
    {
        return false;
    }
    return true;
}

bool checkmate_Queen(char board[][8], int a, int b, int player)
{
    bool flag = false;
    int p = 0;
    if (flag == false)
    {
        for (int c = a + 1, d = b + 1; c < 8 && d < 8 && p == 0; c++, d++)
        {
            if (board[c][d] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, c, d, player) == true)
            {
                if (swap_checkmate(board, a, b, c, d, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, c, d, player) == false)
            {
                p++;
            }
            flag = false;
        }
    }
    p = 0;
    if (flag == false)
    {
        for (int c = a - 1, d = b - 1; c >= 0 && d >= 0 && p == 0; c--, d--)
        {
            if (board[c][d] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, c, d, player) == true)
            {
                if (swap_checkmate(board, a, b, c, d, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, c, d, player) == false)
            {
                p++;
            }
            flag = false;
        }
    }
    p = 0;
    if (flag == false)
    {
        for (int c = a + 1, d = b - 1; c < 8 && d >= 0 && p == 0; c++, d--)
        {
            if (board[c][d] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, c, d, player) == true)
            {
                if (swap_checkmate(board, a, b, c, d, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, c, d, player) == false)
            {
                p++;
            }
            flag = false;
        }
    }
    p = 0;
    if (flag == false)
    {
        for (int c = a - 1, d = b + 1; c >= 0 && d < 8 && p == 0; c--, d++)
        {
            if (board[c][d] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, c, d, player) == true)
            {
                if (swap_checkmate(board, a, b, c, d, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, c, d, player) == false)
            {
                p++;
            }
            flag = false;
        }
    }
    p = 0;
    if (flag == false)
    {
        for (int d = b + 1; d < 8 && p == 0; d++)
        {
            if (board[a][d] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, a, d, player) == true)
            {
                if (swap_checkmate(board, a, b, a, d, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, a, d, player) == false)
            {
                p++;
                flag = false;
            }
        }
    }
    p = 0;
    if (flag == false)
    {
        for (int d = b - 1; d >= 0 && p == 0; d--)
        {
            if (board[a][d] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, a, d, player) == true)
            {
                if (swap_checkmate(board, a, b, a, d, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, a, d, player) == false)
            {
                p++;
                flag = false;
            }
        }
    }
    p = 0;
    if (flag == false)
    {
        for (int c = a + 1; c < 8 && p == 0; c++)
        {
            if (board[c][b] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, c, b, player) == true)
            {
                if (swap_checkmate(board, a, b, c, b, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, c, b, player) == false)
            {
                p++;
                flag = false;
            }
        }
    }
    p = 0;
    if (flag == false)
    {
        for (int c = a - 1; c >= 0 && p == 0; c--)
        {
            if (board[c][b] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, c, b, player) == true)
            {
                if (swap_checkmate(board, a, b, c, b, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, c, b, player) == false)
            {
                p++;
                flag = false;
            }
        }
    }
    if (flag == false)
    {
        return false;
    }
    return true;
}

bool checkmate_King(char board[][8], int a, int b, int player)
{
    bool flag = false;
    int p = 0;
    if (flag == false)
    {
        int c = a + 1;
        int d = b + 1;
        if (c < 8 && d < 8 && p == 0)
        {
            if (board[c][d] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, c, d, player) == true)
            {
                if (swap_checkmate(board, a, b, c, d, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, c, d, player) == false)
            {
                p++;
            }
        }
    }
    p = 0;
    if (flag == false)
    {
        int c = a - 1, d = b - 1;
        if (c >= 0 && d >= 0 && p == 0)
        {
            if (board[c][d] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, c, d, player) == true)
            {
                if (swap_checkmate(board, a, b, c, d, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, c, d, player) == false)
            {
                p++;
            }
        }
    }
    p = 0;
    if (flag == false)
    {
        int c = a + 1, d = b - 1;
        if (c < 8 && d >= 0 && p == 0)
        {
            if (board[c][d] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, c, d, player) == true)
            {
                if (swap_checkmate(board, a, b, c, d, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, c, d, player) == false)
            {
                p++;
            }
        }
    }
    p = 0;
    if (flag == false)
    {
        int c = a - 1, d = b + 1;
        if (c >= 0 && d < 8 && p == 0)
        {
            if (board[c][d] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, c, d, player) == true)
            {
                if (swap_checkmate(board, a, b, c, d, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, c, d, player) == false)
            {
                p++;
            }
        }
    }
    p = 0;
    if (flag == false)
    {
        int d = b + 1;
        if (d < 8 && p == 0)
        {
            if (board[a][d] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, a, d, player) == true)
            {
                if (swap_checkmate(board, a, b, a, d, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, a, d, player) == false)
            {
                p++;
            }
        }
    }
    p = 0;
    if (flag == false)
    {
        int d = b - 1;
        if (d >= 0 && p == 0)
        {
            if (board[a][d] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, a, d, player) == true)
            {
                if (swap_checkmate(board, a, b, a, d, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, a, d, player) == false)
            {
                p++;
            }
        }
    }
    p = 0;
    if (flag == false)
    {
        int c = a + 1;
        if (c < 8 && p == 0)
        {
            if (board[c][b] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, c, b, player) == true)
            {
                if (swap_checkmate(board, a, b, c, b, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, c, b, player) == false)
            {
                p++;
            }
        }
    }
    p = 0;
    if (flag == false)
    {
        int c = a - 1;
        if (c >= 0 && p == 0)
        {
            if (board[c][b] != ' ')
            {
                p++;
            }
            if (checkmate_helper(board, a, b, c, b, player) == true)
            {
                if (swap_checkmate(board, a, b, c, b, player) == true)
                {
                    return true;
                }
            }
            if (checkmate_helper(board, a, b, c, b, player) == false)
            {
                p++;
            }
        }
    }
    if (flag == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool checkmate_implement(char board[][8], int player)
{
    bool flag = false;
    if (player == 2)
    {
        for (int i = 0; i < 8 && flag == false; i++)
        {
            for (int j = 0; j < 8 && flag == false; j++)
            {
                if (board[i][j] == 'P' && flag == false)
                {
                    if (checkmate_B_pawn(board, i, j, player) == true)
                    {
                        flag = true;
                        cout << "p" << endl;
                    }
                    cout << "1" << endl;
                }
                if (board[i][j] == 'R' && flag == false)
                {
                    if (checkmate_Rook(board, i, j, player) == true)
                    {
                        flag = true;
                        cout << "rok" << endl;
                    }
                    cout << "2" << endl;
                }
                if (board[i][j] == 'N' && flag == false)
                {
                    if (checkmate_Knight(board, i, j, player) == true)
                    {
                        flag = true;
                        cout << "ni" << endl;
                    }
                    cout << "3" << endl;
                }
                if (board[i][j] == 'B' && flag == false)
                {
                    if (checkmate_Bishop(board, i, j, player) == true)
                    {
                        flag = true;
                        cout << "bis" << endl;
                    }
                    cout << "4" << endl;
                }
                if (board[i][j] == 'Q' && flag == false)
                {
                    if (checkmate_Queen(board, i, j, player) == true)
                    {
                        flag = true;
                        cout << "qq" << endl;
                    }
                    cout << "5" << endl;
                }
                if (board[i][j] == 'K' && flag == false)
                {
                    if (checkmate_King(board, i, j, player) == true)
                    {
                        flag = true;
                        cout << "king" << endl;
                    }
                    cout << "uiouu" << endl;
                }
            }
        }
    }
    if (player == 1)
    {
        for (int i = 0; i < 8 && flag == false; i++)
        {
            for (int j = 0; j < 8 && flag == false; j++)
            {
                if (board[i][j] == 'p' && flag == false)
                {
                    if (checkmate_W_pawn(board, i, j, player) == true)
                    {
                        flag = true;
                    }
                    cout << "6" << endl;
                }
                if (board[i][j] == 'r')
                {
                    if (checkmate_Rook(board, i, j, player) == true)
                    {
                        flag = true;
                    }
                    cout << "7" << endl;
                }
                if (board[i][j] == 'n' && flag == false)
                {
                    if (checkmate_Knight(board, i, j, player) == true)
                    {
                        flag = true;
                    }
                    cout << "8" << endl;
                }
                if (board[i][j] == 'b' && flag == false)
                {
                    if (checkmate_Bishop(board, i, j, player) == true)
                    {
                        flag = true;
                    }
                    cout << "9" << endl;
                }
                if (board[i][j] == 'q' && flag == false)
                {
                    cout << "10" << endl;
                    if (checkmate_Queen(board, i, j, player) == true)
                    {
                        flag = true;
                    }
                }
                if (board[i][j] == 'k' && flag == false)
                {
                    if (checkmate_King(board, i, j, player) == true)
                    {
                        flag = true;
                        cout << "king c" << endl;
                    }
                }
            }
        }
    }
    if (flag == false)
    {
        return false;
    }
    return true;
}

void checkmate_final(char board[][8], int player)
{
    if (player == 1)
    {
        system("cls");
        cout << "Congratulation 1";
    }

    if (player == 2)
    {
        system("cls");
        cout << "Congratulation 2";
    }
}

void promtion_Pawn(char board[][8], int player)
{
    if (player == 1)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[0][j] == 'p')
            {
                cout << "================================" << endl;
                cout << " Your PAWN got a promotion !!!  " << endl;
                cout << "================================" << endl
                     << endl;
                Sleep(2000);
                system("cls");
                promtion_helper(board, 0, j, 1);
                Sleep(500);
                system("cls");
                print_board(board);
            }
        }
    }

    if (player == 2)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[7][j] == 'P')
            {
                cout << "================================" << endl;
                cout << " Your PAWN got a promotion !!!  " << endl;
                cout << "================================" << endl
                     << endl;
                Sleep(2000);
                system("cls");
                promtion_helper(board, 7, j, 2);
                Sleep(500);
                system("cls");
                print_board(board);
            }
        }
    }
}

int main()
{
    int t = 1;
    welcome();
    while (t == 1)
    {
        if (kbhit())
        {
            system("cls");
            t = 2;
        }
    }

    char board[8][8] =
        {
            {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};

    char name1[100];
    char name2[100];
    gotoxy(40, 10, 15, 0);
    cout << "Enter the name of first player: ";
    cin >> name1;
    gotoxy(40, 12, 15, 0);
    cout << "Enter the name of second player: ";
    cin >> name2;
    Sleep(1000);
    system("cls");
    gotoxy(70, 15, 15, 0);
    cout << "LET's START THE GAME" << endl;
    Sleep(2000);
    system("cls");
    gotoxy(0, 0, 15, 0);
    int currentPlayer = 2;
    print_board(board);
    cout << endl;

    while (true)
    {
        char i, j;
        int a = 0, b = 0, c = 0, d = 0, p = 0, u = 0;

        if (currentPlayer == 1)
        {
            currentPlayer = 2;
        }
        else
        {
            currentPlayer = 1;
        }

        while (p == 0)
        {
            cout << "Input Format should be : Column and Row e.g a1\n\n";

            if (currentPlayer == 1)
            {
                cout << "It's your turn " << name1 << endl;
            }
            else if (currentPlayer == 2)
            {
                cout << "It's your turn " << name2 << endl;
            }

            cout << "Enter the initial place:  ";
            cin >> i >> a; /// coulmn and row
            cout << endl;
            cout << "Enter the final place:  ";
            cin >> j >> c; /// column and row
            cout << endl;
            int x = (int)toupper(i); /// converting into int
            int y = (int)toupper(j);

            if (a > 7 || a < 0 || c > 7 || c < 0 || x > 72 || x < 65 || y > 72 || y < 65)
            {
                cout << "======================================" << endl;
                cout << "INVALID MOVE!!!     Re-enter your move" << endl;
                cout << "======================================" << endl
                     << endl;
            }
            else
            {
                for (int m = 65, n = 0; m <= 72; m++, n++) /// checking the column
                {
                    if (m == x)
                    {
                        b = n;
                    }
                    if (m == y)
                    {
                        d = n;
                    }
                }
                p = 1;
            }
            if (p == 1)
            {
                if (valid_place(board, a, b) == false)
                {
                    p = 0;
                }
                if (board[a][b] != ' ' && (valid_turn(board, a, b, currentPlayer) == false))
                {
                    p = 0;
                }
                if (board[a][b] != ' ' && (valid_piece(board, a, b, c, d, currentPlayer) == false))
                {
                    p = 0;
                }
            }

            int row_diff = c - a;
            int col_diff = d - b;
            if (p == 1)
            {
                if (currentPlayer == 1)
                {
                    if (board[a][b] == 'p')
                    {
                        if (W_Pawn_move(board, a, b, c, d, row_diff, col_diff) == false)
                        {
                            p = 0;
                        }
                    }
                    if (board[a][b] == 'k')
                    {
                        if (W_King_move(board, a, b, c, d, row_diff, col_diff) == false)
                        {
                            p = 0;
                        }
                    }
                    if (board[a][b] == 'q')
                    {
                        if (Queen_move(board, a, b, c, d, row_diff, col_diff, 65, 90) == false)
                        {
                            p = 0;
                        }
                    }
                    if (board[a][b] == 'n')
                    {
                        if (Knight_move(board, a, b, c, d, row_diff, col_diff, 65, 90) == false)
                        {
                            p = 0;
                        }
                    }
                    if (board[a][b] == 'r')
                    {
                        if (Rook_move(board, a, b, c, d, row_diff, col_diff, 65, 90) == false)
                        {
                            p = 0;
                        }
                    }
                    if (board[a][b] == 'b')
                    {
                        if (Bishop_move(board, a, b, c, d, row_diff, col_diff, 65, 90) == false)
                        {
                            p = 0;
                        }
                    }
                }

                if (currentPlayer == 2)
                {
                    if (board[a][b] == 'P')
                    {
                        if (B_Pawn_move(board, a, b, c, d, row_diff, col_diff) == false)
                        {
                            p = 0;
                        }
                    }
                    if (board[a][b] == 'K')
                    {
                        if (B_King_move(board, a, b, c, d, row_diff, col_diff) == false)
                        {
                            p = 0;
                        }
                    }
                    if (board[a][b] == 'Q')
                    {
                        if (Queen_move(board, a, b, c, d, row_diff, col_diff, 97, 122) == false)
                        {
                            p = 0;
                        }
                    }
                    if (board[a][b] == 'N')
                    {
                        if (Knight_move(board, a, b, c, d, row_diff, col_diff, 97, 122) == false)
                        {
                            p = 0;
                        }
                    }
                    if (board[a][b] == 'R')
                    {
                        if (Rook_move(board, a, b, c, d, row_diff, col_diff, 97, 122) == false)
                        {
                            p = 0;
                        }
                    }
                    if (board[a][b] == 'B')
                    {
                        if (Bishop_move(board, a, b, c, d, row_diff, col_diff, 97, 122) == false)
                        {
                            p = 0;
                        }
                    }
                }
            }

            if (p == 1)
            {
                swap_only(board, a, b, c, d);

                if (currentPlayer == 1)
                {
                    if (check_in(board, 1) == false)
                    {
                        if (checkmate_implement(board, currentPlayer) == false)
                        {
                            checkmate_final(board, currentPlayer);
                            cout << "o1ooo" << endl;
                            Sleep(2000);
                            return 0;
                        }
                        Sleep(2000);
                        // system("cls");
                        swap_only(board, c, d, a, b);
                        p = 0;
                    }
                }
                if (currentPlayer == 2)
                {

                    if (check_in(board, 2) == false)
                    {
                        if (checkmate_implement(board, currentPlayer) == false)
                        {
                            checkmate_final(board, currentPlayer);
                            cout << "2oooooo" << endl;
                            Sleep(2000);
                            return 0;
                        }
                        Sleep(2000);
                        // system("cls");
                        swap_only(board, c, d, a, b);
                        p = 0;
                    }
                }
                if (checkmate_implement(board, currentPlayer) == false)
                {
                    checkmate_final(board, currentPlayer);
                    cout << "o1ooo" << endl;
                    Sleep(2000);
                    return 0;
                }
            }
        }
        system("cls");
        print_board(board);

        promtion_Pawn(board, currentPlayer);
    }

    return 0;
}
