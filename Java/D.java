import java.util.*;
class Q{
int n;
booleanstatusFlag=false;
synchronized void put(int n){
try{
while(statusFlag){
wait();
}}
catch(InterruptedException e){}
this.n=n;
System.out.println("Put :"+n);
statusFlag=true;
notify();
}
synchronized int get(){
try{
while(!statusFlag){
wait();
}}
catch(InterruptedException e){}
statusFlag=false;
System.out.println("Got :"+n);
notify();
return n;
}}
class Producer implements Runnable{
Q q;
Producer(Q q){
this.q=q;
new Thread(this, "Producer").start();
}
public void run(){
int i=0;
while(true){
q.put(i++);
}}}
class Consumer implements Runnable
{Q q;
Consumer(Q q){
this.q=q;
new Thread(this,"Consumer").start();
}
public void run(){
while(true){
q.get();
}}}
public class D{
public static void main(String[] args){
Q q=new Q();
Producer p=new Producer(q);
Consumer c=new Consumer(q);
}}
