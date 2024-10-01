import java.util.*;
public class Product {
 int pcode;
 String pname;
 int price;
 public static void main(String[] args) {
 int smallest;
 Product p1 = new Product();
 Product p2 = new Product();
 Product p3 = new Product();
 p1.pcode=1001;
 p1.pname="RAM";
 p1.price=7000;
 p2.pcode=1002;
 p2.pname="Processor";
 p2.price=37000;
 p3.pcode=1003;
 p3.pname="SSD";
 p3.price=16700;
 if(p1.price<p2.price) {
 if(p3.price<p1.price) {
 smallest = p3.price;
System.out.println(p3.pname+ " is the cheapest.");
 } else {
 smallest = p1.price;
System.out.println(p1.pname+ " is the cheapest.");
 }
 } else {
 if(p2.price<p3.price) {
 smallest = p2.price;
System.out.println(p2.pname+ " is the cheapest.");
 } else {
 smallest = p3.price;
System.out.println(p3.pname+ " is the cheapest.");
 }
 }
 }
 }
