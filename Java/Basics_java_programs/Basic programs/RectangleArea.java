import java.util.Scanner;

public class RectangleArea {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        System.out.print("Enter the width of the rectangle: ");
        float width = input.nextFloat();

        System.out.print("Enter the height of the rectangle: ");
        float height = input.nextFloat();

        float area = 2 * width + 2 * height;
        System.out.println("Area of the rectangle is " + area);

    }
}
