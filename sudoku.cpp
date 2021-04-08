/*
    Author: Artin Zamani
    Jan 2016
    Description: A simple console Sudoku solver.
*/

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int TABLE_LEN = 9;
const int BLOCK_LEN = 3;

bool isLegit(int table[TABLE_LEN][TABLE_LEN], int x, int y, int value);
bool isSolvable(int table[TABLE_LEN][TABLE_LEN], string status[TABLE_LEN][TABLE_LEN]);
void printTable(int table[TABLE_LEN][TABLE_LEN]);

int main()
{
    int table[TABLE_LEN][TABLE_LEN];
    string status[TABLE_LEN][TABLE_LEN];

    for (int y = 0; y < TABLE_LEN; y++)
    {
        for (int x = 0; x < TABLE_LEN; x++)
        {
            table[x][y] = 0;
            status[x][y] = "undecided";
        }
    }

    int givens;
    char temp[10];
    int tempX;
    int tempY;
    int val;
    cin >> givens;
    getchar();

    for (int index = 0; index < givens; index++)
    {
        fgets(temp, 7, stdin);
        tempY = temp[0] - '0' - 1;
        tempX = temp[2] - '0' - 1;
        val = temp[4] - '0';

        table[tempX][tempY] = val;
        status[tempX][tempY] = "fixed";
    }

    isSolvable(table, status);
    printTable(table);

    return 0;
}

bool isLegit(int table[TABLE_LEN][TABLE_LEN], int x, int y, int value)
{
    for (int xPrime = 0; xPrime < TABLE_LEN; xPrime++)
    {
        if (value == table[xPrime][y])
            return false;
    }

    for (int yPrime = 0; yPrime < TABLE_LEN; yPrime++)
    {
        if (value == table[x][yPrime])
            return false;
    }

    for (int xPrime = 0; xPrime < BLOCK_LEN; xPrime++)
    {
        for (int yPrime = 0; yPrime < BLOCK_LEN; yPrime++)
        {
            if (x == x - x % BLOCK_LEN + xPrime && y == y - y % BLOCK_LEN + yPrime)
                continue;
            if (value == table[x - x % BLOCK_LEN + xPrime][y - y % BLOCK_LEN + yPrime])
                return false;
        }
    }

    return true;
}

bool isSolvable(int table[TABLE_LEN][TABLE_LEN], string status[TABLE_LEN][TABLE_LEN])
{
    for (int y = 0; y < TABLE_LEN; y++)
    {
        for (int x = 0; x < TABLE_LEN; x++)
        {
            if (status[x][y] == "undecided")
            {
                bool isDeadEnd = true;
                for (int val = 1; val <= TABLE_LEN; val++)
                {
                    if (!isLegit(table, x, y, val))
                        continue;
                    else
                    {
                        table[x][y] = val;
                        status[x][y] = "decided";
                        if (!isSolvable(table, status))
                        {
                            status[x][y] = "undecided";
                            table[x][y] = 0;
                            continue;
                        }
                        else
                            isDeadEnd = false;
                    }
                }
                if (isDeadEnd)
                    return false;
            }
        }
    }
    return true;
}

void printTable(int table[TABLE_LEN][TABLE_LEN])
{
    cout << " ";
    for (int y = 0; y < TABLE_LEN; y++)
    {
        if (y % BLOCK_LEN == 0)
        {
            for (int x = 0; x < TABLE_LEN + BLOCK_LEN; x++)
            {
                cout << "--";
            }
            cout << "-" << endl << " ";
        }
        for (int x = 0; x < TABLE_LEN; x++)
        {
            if (x % BLOCK_LEN == 0)
            {
                cout << "| ";
            }
            if (table[x][y] == 0)
            {
                cout << "  ";
            }
            else
            {
                cout << table[x][y] << " ";
            }
            if (x == TABLE_LEN - 1)
            {
                cout << "| ";
            }
        }
        cout << endl << " ";
        if (y == TABLE_LEN - 1)
        {
            for (int x = 0; x < TABLE_LEN + BLOCK_LEN; x++)
            {
                cout << "--";
            }
            cout << "-" << endl;
        }
    }
}
