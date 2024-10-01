class bank
{
public String name;
 bank(String name)
{
this.name=name;
}
public String getbankname()
{
return this.name;
}
}

class employee
{
private String name;

employee(String name)
{
this.name=name;
}
 
public String getemployeename()
{
return this.name;
}
}

class Association
{
public static void main(String args[])
{
bank Bank=new bank("AXIS BANK");
employee emp=new employee("NEHA");

System.out.println(emp.getemployeename()+" is employee of "+Bank.getbankname());
}
} 