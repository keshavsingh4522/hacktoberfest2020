import java.util.ArrayList;
// show using String ArrayList
public class ArrayListString {

    public static void main(String[] args) {

        // define and instantiating an object
        ArrayList<String> listaString = new ArrayList<>();

        // adding elements
        listaString.add("Elemento 1");
        listaString.add("Elemento 2");
        listaString.add("Elemento 3");

        // show list objects
        System.out.println(listaString.get(0));
        System.out.println(listaString.get(1));
        System.out.println(listaString.get(2));

        // adding element an specific position
        listaString.add(1, "Elemento 1.5");

        // show result of list
        for (String obj : listaString) {
            System.out.println(obj);
        }

        // get list size
        System.out.println("O tamanho da lista é:" + listaString.size());

        // find an value in list
        if (listaString.contains("Elemento 1")) {
            System.out.println("Elemento encontrado");
        } else {
            System.out.println("Elemento não encontrado ");
        }

        // find element indice
        int indice = listaString.indexOf("Elemento 1");
        System.out.println("Indice: " + indice);

        // adding a new element
        listaString.add("Elemento 4");

        // get list size
        System.out.println("O tamanho da lista é:" + listaString.size());

        // remove an element from list
        listaString.remove("Elemento 1.5");
        for (String obj : listaString) {
            System.out.println(obj);
        }

        // get list size
        System.out.println("O tamanho da lista é:" + listaString.size());

    }
}