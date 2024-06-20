/*
Coin Tower
Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. 
In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?
 
Input format :
The first and the only line of input contains three integer values separated by a single space. They denote the value of N, X and Y, respectively.

Output format :
Prints the name of the winner, either 'Whis' or 'Beerus' (Without the quotes).

Constraints :
1 <= N <= 10 ^ 6
2 <= X <= Y<= 50

Time Limit: 1 sec

Sample Input 1 :
4 2 3

Sample Output 1 :
Whis


Sample Input 2 :
10 2 4

Sample Output 2 :
Beerus
*/

#include<vector>
string findWinner(int n, int x, int y){
	// Write your code here .
    // We make a winner array corresponding to Beerus
    vector<bool> dp(n + 1);
    
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i < n + 1; i++) {
       	int state1 = 0;
        int state2 = 0;
        int state3 = 0;
        
        if(i - 1 >= 0) {
            state1 = dp[i - 1] ^ 1;
        }
        
        if(i - x >= 0) {
            state2 = dp[i - x] ^ 1;
        }
        
        if(i - y >= 0) {
            state3 = dp[i - y] ^ 1;
        }
        
        dp[i] = max(state1, max(state2, state3));
    }
    
    if(dp[n]) {
        return "Beerus";
    } else {
        return "Whis";
    }
}

// Time Complexity : O(n)
// Auxillary Space : O(n)
