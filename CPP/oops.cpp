#include<bits/stdc++.h>
using namespace std;
//Abstraction ..Hiding complex things
    // Phone button press camera click but its complex to take picture
    // interface similar to abstract class
class AbstractEmp{
    virtual void AskForPromotion()=0;
};
class Employee:AbstractEmp{
    //private default
    // private:
    //     int age;
    //     string name;
    //     string company;
    protected:
        int age;
        string name;
        string company;
    
    public:
    //Encapsulation .. Name is private so no one can modify it and 
    //we add methods to interact with them
    //public getter setter with validations for private var
    void setName(string name){
        if(name.size()>this->name.size())
            this->name=name;
        else
            cout<<"Enter bigger name plz!!";
    }
    string getName(){
        return name;
    }
     
    static int count;
     Employee(){
        count++;
        cout<<"Employee Created!\n";
    }
    Employee(int age,string name,string company):Employee(){
        this->age=age;
        this->name=name;
        this->company=company;
    }
   virtual  void walk(){
        cout<<name<<" is walking.\n";
    }
    void walk(int step){
        cout<<name<<" walked "<<step<<" steps.\n";
    }
    void AskForPromotion(){
        if(age>15)
            cout<<name<<" GOT PROMOTED!\n";
        else
            cout<<name<<" NO PROMOTION!\n";
    }
};
int Employee::count=0;
//Inheritance
class Developer:public Employee{
    public:
    string prg_lang;
    Developer(){
        cout<<"Dev created!\n";
    }
    Developer(int age,string name,string company,string lang):Employee(age,name,company){

        prg_lang=lang;
    }
    void fixbug(){
        cout<<getName()<<" Fixed bug.\n";
    }
    void fixbug2(){
        cout<<name<<" Fixed the bug.\n";
    }
    void walk()
        {
            cout<<"Dev walks.\n";
        }
};
class Teacher:public Employee{
    public:
        string subject;
        Teacher(int age,string name,string company, string subject):Employee(age, name,company){
            this->subject=subject;
        }
        void prp(){
            cout<<name<<" is preparing "<<subject<<"\n";
        }
        void walk()
        {
            cout<<"Teacher walks.\n";
        }
};
int main(){
    Employee *e1=new Employee(18,"Shubham","Google");
    e1->walk();
    e1->walk(2);
    Employee e2=Employee(10,"Shivam","Amazon");
    cout<<e1->count;
    e1->AskForPromotion();
    e2.AskForPromotion();

    Developer *d= new Developer(25,"Ram","Uber","C++");
    d->fixbug();
    d->fixbug2();
    d->AskForPromotion(); // bcoz of public emp dev::public emp   

    Teacher t=Teacher(45,"Jack","GGPS","Maths");
    t.prp();
    t.AskForPromotion();  

    Employee *e3=d;
    Employee *e4=&t;
    e3->walk();
    e4->walk();
    return 0;
}
