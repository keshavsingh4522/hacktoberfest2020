// Problem: K-means clustering

#include<bits/stdc++.h> 
using namespace std;
#define F first
#define pii pair<int,int>
#define S second
#define endl "\n"
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a/gcd(a,b)*b
#define mem(z,i) memset(z,i,sizeof(z))
#define eps 1e-7
#define I (int)
#define mod 1000000007 
#define pb push_back
#define mp make_pair
const long long INF = 1000000000000000000LL;
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
template <typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
    for (auto val : vec)
        out << val << " ";
    return out;
}
typedef long long int ll;
typedef pair<double,double> row;
typedef vector<row> matrix;

int compute(matrix c,row point)
{
	double min = DBL_MAX;
	int cluster = -1;
	for(int i=0;i<2;i++)
	{
		double dist = sqrt(pow(point.F-c[i].F,2)+pow(point.S - c[i].S,2));
		cout<<dist<<"\n";
		if(dist < min)
		{
			min = dist;
			cluster = i;
		}
	}
	return cluster;
}
void update_centroids(matrix p,matrix &m,vector<int>cluster,int n)
{
	vector<int>count(2,0);
	for(int i=0;i<2;i++)
		{m[i].F = 0.0;m[i].S=0.0;}


	for(int i=0;i<n;i++)
	{
		count[cluster[i]]++;
		 m[cluster[i]].F += p[i].F;
		 m[cluster[i]].S += p[i].S;
	}


	for(int i=0;i<2;i++)
		{
			m[i].F = m[i].F/count[i];
			m[i].S /= count[i];}

}

signed main() 
{ 
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 
 freopen("input.txt", "r", stdin); 
 freopen("error.txt", "w", stderr); 
 //freopen("output.txt", "w", stdout); 
 const int k = 2;
 matrix centroids(k);

 int iter = 2;
 int n;
 cin>>n;
 vector<int>clusters(n);
 matrix mat(n);
 for(int i=0;i<n;i++)
 {
 	double c1,c2;
 	cin>>c1>>c2;
 	mat[i] = mp(c1,c2);
 }
 //initially we take task 1 and task 4 as initial centroids
centroids[0] = mat[0];
centroids[1] = mat[3];
while(iter--)
{
	for(int i=0;i<n;i++)
	{
		clusters[i] = compute(centroids,mat[i]);
	}
	//cout<<"At iteration "<<iter<<" : "<<clusters<<endl;
	update_centroids(mat,centroids,clusters,n);
	// for(int i=0;i<2;i++)
	// 	cout<<centroids[i].F<<" "<<centroids[i].S<<"\n";
}
cout<<clusters;
 return 0; 
} 
