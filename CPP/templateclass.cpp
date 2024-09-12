# include<bits/stdc++.h>
using namespace std;
template<typename T,typename U>
class weight{
    private:
    T kg;
    U g;
    public:
    void setData(T x,U g){
        kg=x;
    }
     T getData()
     {
        return kg,g;
     }
};

int main()
{
 ios_base::sync_with_stdio(false);
cin.tie(NULL);
weight <int,int>obj1;
obj1.setData(5,5);
cout<<"Value is : "<<obj1.getData()<<endl;

weight <double,char>obj2;//for same class we declare two different type of object forst type is int another is double
obj1.setData(5.545,3);
cout<<"Value is : "<<obj2.getData()<<endl;

return 0;
}