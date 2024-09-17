#include <iostream>
#include <cstdlib>
#include <vector>
#include <bits/stdc++.h>

#ifdef linux
	#define clean system("clear")
#endif
#if defined(_WIN32) || defined(WIN32)
	#define clean system("cls")
#endif
	
using namespace std;
class tic_toc {
private:
    // 3 X 3 grid for positions -
    char grid[3][3] = { {'1', '2', '3'},
                        {'4', '5', '6'},
                        {'7', '8', '9'}
    };
    vector < int >moves = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector < int >::iterator it1, it2;
    char turn = 'X';
    int row = 9, col = 9, draw = 0;
public:
    int type; // variable for storing if the player is 'X' or 'O'
    bool run = true;

    // Function for main menu which is displayed in the beginning -
    int Main_menu (int a) {
        int choice; // variable for storing choice of user -
        clean;

        cout <<
             "\n*******************************************************************************\n";
        cout << "\t\t\t\t Tic Tac Toe by Sidharth Sethi\n";
        cout <<
             "\n*******************************************************************************\n";
        if (a == 0)
            cout << endl << endl << "\t\t1)  Play 2 player Game " << endl <<
                 "\t\t2)  Play vs Computer" << endl << endl <<
                 "\t\tEnter Your Choice : ";
        else
            cout << endl << endl << "\t\t1)  Play 2 player Game " << endl <<
                 "\t\t2)  Play vs Computer" << endl << endl <<
                 "\t\tEnter a Valid Choice : ";
        cin >> choice;
        if (choice == 1 || choice == 2) {
            return choice;
        }
        else {
            a = 1;
            Main_menu (a);
        }
        return 0;
    }

    // Display basic Tic_toc_board_view
    void Tic_toc_board_view () {
        clean;		// to clear previous screen
        cout <<
             "\n*******************************************************************************\n";
        cout << "\t\t\t\t Tic Tac Toe by Sidharth Sethi\n";
        cout <<
             "\n*******************************************************************************\n";
        if (type == 1)
            cout << endl << "\t\t Player 1 is X" << endl << "\t\t Player 2 is O" <<
                 endl;
        else
            cout << endl << "\n\t\tYou are Playing as X" << endl;
            
        cout << "\t\t\t\t     |     |     \n";
        cout << "\t\t\t\t  " << grid[0][0] << "  |  " << grid[0][1] << "  |  " <<
             grid[0][2] << "  \n";
        cout << "\t\t\t\t_____|_____|_____\n";
        cout << "\t\t\t\t     |     |     \n";
        cout << "\t\t\t\t  " << grid[1][0] << "  |  " << grid[1][1] << "  |  " <<
             grid[1][2] << "  \n";
        cout << "\t\t\t\t_____|_____|_____\n";
        cout << "\t\t\t\t     |     |     \n";
        cout << "\t\t\t\t  " << grid[2][0] << "  |  " << grid[2][1] << "  |  " <<
             grid[2][2] << "  \n";
        cout << "\t\t\t\t     |     |     \n";

        if (type == 2)
            cout << "\n\t\t Your Turn : ";
    }

    // Function which implements the actual functioning of the game - 
    int Game_working () {
        // winning conditions -
        // horizontal
        for (int i = 0; i <= 2; i++)
            if (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2])
                return 0;
        // vertical
        for (int i = 0; i <= 2; i++)
            if (grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i])
                return 0;
        // diagonals
        if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
            return 0;
        if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
            return 0;
        // Game_working running
        for (int i = 0; i <= 2; i++)
            for (int j = 0; j <= 2; j++)
                if (grid[i][j] != 'X' && grid[i][j] != 'O')
                    return 1;
        draw = 1;
        return 0;
    }

    // Function which returns index 
    int getIndex (vector < int >v, int K) {
        auto it = find (v.begin (), v.end (), K);

        // If element was found
        if (it != v.end ()) {
            // calculating the index
            // of K
            int index = it - v.begin ();
            return index;
        }
        return 0;
    }

    // Function which returns if the user wants to continue playing - 
    char Play_again () {
        cout << " \n\t\t Do You want to play again(Y/n) ";
        char again;
        cin >> again;
        return again;
    }

    // Function for 2-player game - 
    void User_turn_i_cal (int type) {
        if (type == 1) {
            if (turn == 'X')
                cout << "\n\t\t Player 1 X turn : ";
            else if (turn == 'O')
                cout << "\n\t\t Player 2 O turn : ";
        }
        int choice, choiceIndex;
        cin >> choice;
        if (type == 2) {
            choiceIndex = getIndex (moves, choice);
            it1 = moves.begin () + (choiceIndex);
            it2 = moves.begin () + (choiceIndex + 1);
            moves.erase (it1, it2);
        }
        Move_calculator (choice);
        /*
           Turn Switch and Prevention of changing other's marking
        */
        if (type == 1) {
            if (turn == 'X' && grid[row][col] != 'X' && grid[row][col] != 'O') {
                grid[row][col] = 'X';
                turn = 'O';
            }
            else if (turn == 'O' && grid[row][col] != 'X'
                     && grid[row][col] != 'O')
            {
                grid[row][col] = 'O';
                turn = 'X';
            }
            else {
                cout << "\n\t\tWrong Input";
                User_turn_i_cal (type);	//Asking for input again here
            }
        }
        else {
            if (grid[row][col] != 'X' && grid[row][col] != 'O') {
                grid[row][col] = 'X';
                turn = 'O';
            }
            else {
                cout << "\n\t\tWrong Input";
                User_turn_i_cal (type);	//Asking for input again here
            }

        }
        Tic_toc_board_view ();
    }

    // Function for game against computer -
    void Computer_AI_for_tic_toc () {
        int choice;
        unsigned long choiceIndex;
        choiceIndex = rand () % moves.size ();
        choice = moves[choiceIndex];

        it1 = moves.begin () + (choiceIndex);
        it2 = moves.begin () + (choiceIndex + 1);
        moves.erase (it1, it2);

        Move_calculator (choice);
        /*
           Turn Switch and Prevention of changing other's marking
        */

        grid[row][col] = 'O';
        turn = 'X';

        //Tic_toc_board_view(type);
    }

    void Move_calculator (int choice) {
        switch (choice)		//Taking Input
        {
            case 1:
                row = 0;
                col = 0;
                break;
            case 2:
                row = 0;
                col = 1;
                break;
            case 3:
                row = 0;
                col = 2;
                break;
            case 4:
                row = 1;
                col = 0;
                break;
            case 5:
                row = 1;
                col = 1;
                break;
            case 6:
                row = 1;
                col = 2;
                break;
            case 7:
                row = 2;
                col = 0;
                break;
            case 8:
                row = 2;
                col = 1;
                break;
            case 9:
                row = 2;
                col = 2;
                break;
            default:
                cout << "\t\tInvalid Choice \n";
        }
    }

    // Function which displays winner/loser after the game -
    void Game_Over () {
        if (type == 1) {
            if (draw == 1)
                cout << "\n\t\t\t\tGame Draw";
            else if (turn == 'X')
                cout << "\n\t\t\t\tPlayer 2 WINS!!!";
            else if (turn == 'O')
                cout << "\n\t\t\t\tPlayer 1 WINS!!!";
            cout << "\n\t\t\t\tGAME OVER TATA";
        }
        else {
            if (draw == 1)
                cout << "\n\t\t\t\tGame Draw";
            else if (turn == 'X')
                cout << "\n\t\t\t\tYou Won !!";
            else if (turn == 'O')
                cout << "\n\t\t\t\tYou Lost :(";
            cout << "\n\t\t\t\tGAME OVER TATA";
        }
    }

};

int main () {

    int choice;
    char ch = 'Y';
    while (ch == 'y' || ch == 'Y') {
		
        tic_toc play;
        int a = 0;
        choice = play.Main_menu (a);
        if (choice == 1) {
            play.type = 1;
            while (play.run) {
                play.Tic_toc_board_view (); // shows board view
                play.User_turn_i_cal (play.type); // interface display for 2-player game
                play.run = play.Game_working (); // working of game 
            }
            play.Game_Over ();
        }
        else {
            play.type = 2;
            while (play.run) {

                play.Tic_toc_board_view (); 
                play.User_turn_i_cal (play.type); 
                play.Computer_AI_for_tic_toc ();
                play.run = play.Game_working ();
            }
            play.Game_Over ();
        }
        ch = play.Play_again ();
        clean;
    }
    return 0;
}
