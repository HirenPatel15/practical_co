#include <bits/stdc++.h>
using namespace std;

string grid[3][3] = {{"_", "_", "_"}, {"_", "_", "_"}, {"_", "_", "_"}}; //initilizing the grid as empty

string isWin()
{

    // WINNING CONDITIONS //

    if (grid[0][0] == grid[0][1] and grid[0][0] == grid[0][2] and grid[0][0] != "_")
        return grid[0][0];
    if (grid[1][0] == grid[1][1] and grid[1][0] == grid[1][2] and grid[1][0] != "_")
        return grid[1][0];
    if (grid[2][0] == grid[2][1] and grid[2][0] == grid[2][2] and grid[2][0] != "_")
        return grid[2][0];
    if (grid[0][0] == grid[1][0] and grid[0][0] == grid[2][0] and grid[0][0] != "_")
        return grid[0][0];
    if (grid[0][1] == grid[1][1] and grid[0][1] == grid[2][1] and grid[0][1] != "_")
        return grid[0][1];
    if (grid[0][2] == grid[1][2] and grid[0][2] == grid[2][2] and grid[0][2] != "_")
        return grid[0][2];
    if (grid[0][0] == grid[1][1] and grid[0][0] == grid[2][2] and grid[0][0] != "_")
        return grid[0][0];
    if (grid[0][2] == grid[1][1] and grid[0][2] == grid[2][0] and grid[0][2] != "_")
        return grid[0][2];

    else
        return "false";
}

void printGrid()
{
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << grid[i][j] << "  ";
        }
        cout << endl
             << endl;
    }
}

int main()
{
    int position, count = 0;
    cout << endl
         << "Mark for player 1 is : X" << endl
         << "Mark for player 2 is : 0" << endl
         << endl;

    while (count < 9)
    {

        // FOR PLAYER 1

        cout << "Enter position for X(1-9) : ";
        cin >> position;
        position--;
        while (grid[position / 3][position % 3] != "_")
        { 
            cout << "Given position is filled please enter another positon : ";
            cin >> position;
            position--;
        }
        grid[position / 3][position % 3] = "X"; 
        printGrid();
        if (isWin() != "false")
        { 
            cout << "Player 1 Won!!!" << endl;
            return 0;
        }
        count++; 

        // FOR PLAYER 2
        if (count < 9)
        {
            cout << "Enter position for 0(1-9) : ";
            cin >> position;
            position--;
            while (grid[position / 3][position % 3] != "_")
            {

                cout << "Given position is filled please enter another positon : ";
                cin >> position;
                position--;
            }
            grid[position / 3][position % 3] = "0";
            printGrid();
            if (isWin() != "false")
            {
                cout << "Player 2 Won!!!" << endl;
                return 0;
            }
            count++;
        }
    }
    cout << "TIE!" << endl;
    return 0;
}