#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , m , t;
    cin >> n >> m >> t;
    int a[1000][1000]= {};
    
    for (int i = 0 ; i < t; i++){
        int x , y , val;
        cin >> x >> y >> val;
        a[x][y] = val;
    }
    // for (int i = 0 ; i < n ; i++){
    //     for (int j = 0 ; j < m ;j++)
    //         cout << a[i][j] << " ";
    //         cout << endl;
    // }
    
    int initial_row , initial_col;
    cin >> initial_row >> initial_col;
    
    if ((initial_row == 0 && initial_col == 0) && (n != 2 || m != 2)){
        int count = 0;
    
            int ul = 0 , dl = n-1 , rl = m-1 , ll = 1; 
            
        while (count < n*m) {
            for (int i = ul  ; i <= dl ; i++){
                count++;
                if (a[i][ll-1] != 0)
                    cout << i << " " << ll-1 << " " << a[i][ll-1] << " 1" << endl;
                
            }
            dl--;
            
            if (count == n*m)
                break;
        
            for (int i = ll ; i <= rl ; i++){
                count++;
                if (a[dl+1][i] != 0)
                    cout << dl+1 << " " << i << " " << a[dl+1][i] << " 2" << endl;
            }
            rl--;
            if (count == n*m)
                break;
             
            
            for (int i = dl ; i >= ul ; i--){
                count++;
                if (a[i][rl+1] != 0)
                    cout << i << " " << rl+1 << " " << a[i][rl+1] << " 3" << endl; 
            }
            ul++;
            if (count == n*m)
                break;
            
            for (int i = rl ; i >= ll ; i--){
                count++;
                if (a[ul-1][i] != 0)
                    cout << ul-1 << " " << i << " " << a[ul-1][i] << " 4" << endl;
            }
            ll++;
            if (count == n*m)
                break;
            // cout << dl << " " << ul << " " << ll << " " << rl << " " << count << endl;
            // break; 
            
        }
        
    }
    else {
    
    int count = 3;
    
    int iu = initial_row , il = initial_col , ir , id , r , c;
    
    
    
    if (a[iu][il] != 0)
        cout << iu << " " << il << " " << a[iu][il] << " 1" << endl;
    
    //  id
    id = initial_row + 1;
    if (a[id][il] != 0)
        cout << id << " " << il << " " << a[id][il] << " 1"<< endl;
    // if Print
    
     // ir
    ir = initial_col + 1;
    if (a[id][ir] != 0)
        cout << id << " " << ir << " " << a[id][ir] << " 2" << endl;
    // if Print
    
    r = id ;
    c = ir;
    
    // cout << iu << " " << ir << " " << id << " " << il << endl;
    
    
    int up , left , down , right;
    
    //cout << r << c << endl;
    
    while ( count < n*m ){
        
        for ( up = r - 1  ; up >= 0 ; up-- ){
            count++;
            if ( a[up][c] != 0 )
                cout << up << " " << c << " " << a[up][c] << " 3" << endl;
                
        
            if (up == iu - 1)
                break;
        }
        // count--;
        iu = up;
        r = iu;
        // cout << r << " " << c << " " << count << endl;
        //break;
        
        if (count == n*m )
            break;
            
        for ( left = c-1 ; left >= 0; left-- ){
            count++;
            if ( a[r][left] != 0 )
                cout << r << " " << left << " " << a[r][left] << " 4" << endl;
        
            if ( left == il - 1)
                break;
        }
        // count--;
        c = left;
        il = c;
        
        //cout << r << " " << c << " " << count << endl;
        // break;
        
        if (count == n*m)
            break;
        
        for ( down = r+1 ; down < n ; down++){
            count++;
            if ( a[down][c] != 0 )
                cout << down << " " << c << " " << a[down][c] << " 1"  << endl;
        
            if ( down == id+1 )
                break;
        }
        // count--;
        r = down;
        id = r;
        //cout << r << " " << c << " " << count << endl;
        //break;
        
        if (count == n*m)
            break;
        
        for ( right = c+1 ; right <= m ; right++ ){
            count++;
            if (a[r][right] != 0 )
                cout << r << " " << right << " " << a[r][right] << " 2" << endl;
        
            if ( right == ir+1 )
                break;
                
        }
        // count--;
        c = right;
        ir = c;
        // cout << r << " " << c << " " << count << endl;
        //break;
        
    }
    }
    
    
    
    
    
    
}