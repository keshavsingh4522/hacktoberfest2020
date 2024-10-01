/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package collection;

/**
 *
 * @author Zohaib Hassan Soomro
 */
public class TestMyCollection {

public static void main(String[] args) {
    ArrayCollection collection = new ArrayCollection();
    System.out.println("ArrayCollection:");

    collection.add("Hello!");
    collection.add("boyz");
    collection.add("and");
    collection.add("girlz");
    System.out.println(collection);
    collection.remove("and");
    System.out.println(collection);

    System.out.println("\n\nLinkedCollection:");
    LinkedCollection collection2 = new LinkedCollection();
    collection2.add("Hello!");
    collection2.add("boyz");
    collection2.add("and");
    collection2.add("girlz");
    System.out.println(collection2);
    collection2.remove("and");
    System.out.println(collection2);
    
    System.out.println("Contains: "+collection.contains("boyz"));
    System.out.println("Contains: "+collection2.contains("and"));

}

}
