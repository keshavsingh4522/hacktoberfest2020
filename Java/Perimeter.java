class Perimeter
{
float p;
public Perimeter(int l, int b)
{
int ll=l; int bb=b;
System.out.println("cons. 1 called");
}
public Perimeter(int r)
{
int rr=r;
System.out.println("cons. 2 called");
}
public Perimeter(int a, int b, int c)
{
int aa=a; int bb=b; int cc=c;
System.out.println("cons. 3 called");
}
public void peri(int l, int b)
{
p=2*(l+b);
 
System.out.println("Perimeter of rectangle="+p);
}
public void peri(int r)
{
p=(float)(2*3.14*r); System.out.println("Perimeter of circle="+p);
}
public void peri(int a, int b, int c)
{
p=a+b+c;
System.out.println("Perimeter of triangle="+p);
}
public static void main(String args[])
{
Perimeter obj=new Perimeter(2,3); Perimeter obj1=new Perimeter(4); Perimeter obj2=new Perimeter(6,2,3); obj.peri(4,6);
obj.peri(8); obj.peri(2,3,5);
}
}

