#include <bits/stdc++.h>
using namespace std;
int a;
void move(int from, int to, int depth){
    if(depth == 1){
        printf("%d %d\n", from, to);
        return;
    }
    int other = 6 - from - to;
    move(from, other, depth-1);
    printf("%d %d\n", from, to);
    move(other, to, depth-1);
}
int main(){
    scanf("%d", &a);
    printf("%d\n", (1<<a)-1);
    move(1, 3, a);
}
