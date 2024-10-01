// N chess queens on an NÃ—N chessboard so that no two queens attack each other

//By Soumyadeep Pal
#include <iostream>
using namespace std;

//For counting total possible soln
static int count;

// Queen's position Printing in grid style
void print_Grid_style(int userRows, int **arr)
{
    int userColumns = userRows;
    cout << "\n";
    cout << " ";
    int i, j;
    cout << "\n";
    for (i = 0; i <= 2 * userRows; i++)
    {
        if (i % 2 != 0)
            cout << " ";
        for (j = 0; j <= 2 * userColumns; j++)
        {
            if (i % 2 == 0)
            {
                if (j == 0)
                    cout << " ";
                if (j % 2 == 0)
                    cout << " ";
                else
                    cout << "---";
            }
            else
            {
                if (j % 2 == 0)
                    cout << "|";
                else
                {
                    cout << " ";
                    if (arr[i / 2][j / 2] == 1)
                        cout << "Q"; //just replace Q to 1 &
                    else
                        cout << " "; // replace space to 0 if u want to print in 0-1 format
                    cout << " ";
                }
            }
        }
        cout << "\n";
    }
}

bool check_pos(int **arr, int x, int y, int n)
{
    for (int row = 0; row < n; row++)
    {
        if (arr[row][y] == 1)
        {
            return false;
        }
    }

    //for upper left diagonal
    int row = x, col = y;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--, col--;
    }

    //for upper right diagonal
    row = x, col = y;
    while (row >= 0 && col < n) //coz queen can't be placed outside
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--, col++;
    }
    return true;
}
bool nqueen(int **arr, int x, int n) //not required to pass y & prev column coz we already placed our queen on the next row
{
    //Base case:
    if (x >= n)
    {
        print_Grid_style(n, arr);
        count++;
    }

    for (int col = 0; col < n; col++)
    {
        if (check_pos(arr, x, col, n))
        {
            arr[x][col] = 1;

            if (nqueen(arr, x + 1, n))
            {
                return true;
            }
            //If placed queen clashes with already placed queens then remove queen from board and put 0 in those position
            arr[x][col] = 0;
        }
    }
    return false;
}

int main()
{
    cout << "Enter the number of Queens: ";
    int n;
    cin >> n;
    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {

        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            arr[i][j] = 0;
        }
    }
    if (n > 3)
    {
        nqueen(arr, 0, n);
    }
    cout << "\nPossible solutions exist for an " << n << "-queen problem: " << count << "\n";
    return 0;
}
