bool util(string &s, string &p, int a, int b, vector<vector<int>> &mp){

    int n=s.size(),m=p.size();
    
    if(a >= n && b >= m) 
        return true;
    else if (b >= m) 
        return false;
    
    if (mp[a][b])
        return mp[a][b] == -1 ? false : true;

    bool match = a < n && (s[a]==p[b] || p[b]=='.');
    
    if(b < m-1 && p[b+1]=='*'){
        bool f = (match && util(s,p,a+1,b,mp)) || util(s,p,a,b+2,mp);
        mp[a][b] = f ? 1 : -1;
        return f;
    }
    
    if(match){
        bool f = util(s,p,a+1,b+1,mp);
        mp[a][b] = f ? 1 : -1;
        return f;
    }
    
    mp[a][b] = -1;
    return false;

}

    
    
bool isMatch(string s, string p) {

    vector<vector<int>> mp(s.size() + 1, vector<int> (p.size() + 1, 0));

    return util(s,p,0,0,mp); 

}