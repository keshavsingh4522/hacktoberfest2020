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
public class Country {

private String name, language, iso;
private int area, population;

public Country(String name, String iso, String language, int area, int population) {
    this.name = name;
    this.language = language;
    this.iso = iso;
    this.area = area;
    this.population = population;
}

@Override
public String toString() {
    return ("[" + name + "," + iso + "," + language + "," + area + "," + population + "]");
}

public String getValue(String key) {
    //mechanism to find the country with this key
    return ("[" + name + "," + iso + "," + language + "," + area + "," + population + "]");
}

public static void main(String[] args) {
    Country pak = new Country("Pakistan", "PK", "Urdu", 333333, 3333333);
    Country bang = new Country("Bangladesh", "BN", "Bengali", 4444, 44444);
    Country ind = new Country("India", "IN", "Hindi", 555555, 555555);

    System.out.println("Pakistan: " + pak);
    System.out.println("Bangladesh: " + bang);
    System.out.println("India: " + ind);
}
}
