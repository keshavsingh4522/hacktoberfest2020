interface speaker

{
public void speak( );
}
class politician implements speaker{
public void speak()
{
System.out.println("talk politics");
}
}
class priest implements speaker{
public void speak()
{
System.out.println("religious talks");
}
}
class lecturer implements speaker{
public void speak()
{
System.out.println("talks object oriented design and programming");
}
}
class interfacedemo
{
public static void main(String args[])
{
speaker s;
s=new politician();
s.speak();
s=new priest();
s.speak();
s=new lecturer();
s.speak();
}
}

