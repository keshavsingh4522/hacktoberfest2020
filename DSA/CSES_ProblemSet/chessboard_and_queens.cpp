#include <bits/stdc++.h>
using namespace std;
const int N = 8;
char c;
int a;
bool b[N][N], input[N][N];
bool place(int x, int y){
    bool yes = true;
    for(int i = 0; i < N; i++)
        if(b[x][i] || b[i][y])
            yes = false;
                 for(int i = 0; x-i >= 0 && y-i >= 0; i++)
                          if(b[x-i][y-i])
                                    yes = false;
                                               for(int i = 0; x-i >= 0 && y+i < N; i++)
                                                              if(b[x-i][y+i])
                                                                               yes = false;
                                                                                 return yes;
}

bool check(){
    for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                      if(b[i][j] && input[i][j])
                                  return false;
                                   return true;
}

void dfs(int i){
    if(i == N){
        if(check())
            a++;
        return;
    }
    for(int j = 0; j < N; j++){
        if(place(i, j)){
            b[i][j] = true;
            dfs(i+1);
            b[i][j] = false;
        }
    }
}

int main(){
    for(int i = 0; i < N; i++){
           for(int j = 0; j < N; j++){
               scanf(" %c", &c);
                input[i][j] = (c == '*');
        }
    }
    dfs(0);
    printf("%d\n", a);
}
