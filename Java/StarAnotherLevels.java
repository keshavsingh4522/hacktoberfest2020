package latihanfor;
import java.util.Scanner; /** ** @author Everything Sans*/
public class Looping {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        intpil, x = 1;
        String pil2;
        while (x <= 1) {
            System.out.println(“PROGRAM KUMPULAN BENTUK - BENTUK BINTANG”);
            System.out.println(“ === === === === === === === === === === === === == ”);
            System.out.println(“1. Tipebintang 1”);
            System.out.println(“2. Tipebintang 2”);
            System.out.println(“3. Tipebintang 3”);
            System.out.println(“4. Tipebintang 4”);
            System.out.println(“5. Tipebintang 5”);
            System.out.println(“6. Tipebintang 6”);
            System.out.println(“7. Tipebintang 7”);
            System.out.println(“8. Tipebintang 8”);
            System.out.println(“9. Tipebintang 9”);
            System.out.println(“10. Tipebintang 10”);
            System.out.println(“11. Tipebintang 11”);
            System.out.println(“12. Tipebintang 12”);
            System.out.println(“13. Tipebintang 13”);
            System.out.println(“14. Tipebintang 14”);
            System.out.println(“15. Tipebintang 15”);
            System.out.println(“16. Tipebintang 16”);
            System.out.println(“0. exit”);
            System.out.print(“Masukkanpilihan(0 - 16): “);
            pil = input.nextInt();
            System.out.println(“ === === === === === === === === === === === === == ”);
            switch (pil) {
                case 1:
                    System.out.println(“Tipebintang 1: ”);
                    for (inti = 1; i <= 3; i++) {
                        for (int j = 1; j <= 3; j++) {
                            System.out.print(“ * ”);
                        }
                        System.out.println(”“);
                    }
                    break;
                case 2:
                    System.out.println(“Tipebintang 2: ”);
                    for (inti = 1; i <= 1; i++) {
                        for (int j = 1; j <= 5; j++) {
                            System.out.print(“ * ”);
                        }
                        System.out.println();
                    }
                    for (int k = 1; k <= 3; k++) {
                        for (int l = 1; l < 2; l++) {
                            System.out.print(“ * ”);
                        }
                        for (int m = 1; m < 2; m++) {
                            System.out.print(” * ”);
                        }
                        System.out.println();
                    }
                    for (int o = 1; o <= 1; o++) {
                        for (int p = 1; p <= 5; p++) {
                            System.out.print(“ * ”);
                        }
                        System.out.println();
                    }
                    break;
                case 3:
                    System.out.println(“Tipebintang 3: ”);
                    for (inti = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                            if (i == j || i + j == 5– 1) {
                                System.out.print(“ * ”);
                            } else {
                                System.out.print(”“);
                            }
                        }
                        System.out.println(“”);
                    }
                    break;
                case 4:
                    System.out.println(“Tipebintang 4: ”);
                    for (inti = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                            if (i == j || i + j == 5– 1) {
                                System.out.print(”“);
                            } else {
                                System.out.print(“ * ”);
                            }
                        }
                        System.out.println(“”);
                    }
                    break;
                case 5:
                    System.out.println(“Tipebintang 5: ”);
                    for (inti = 1; i <= 4; i++) {
                        for (int j = i; j >= 1; j–) {
                            System.out.print(”“);
                        }
                        for (int k = 1; k <= 5; k++) {
                            System.out.print(“ * ”);
                        }
                        System.out.println();
                    }
                    break;

                case 6:
                    System.out.println(“Tipebintang 6: ”);
                    int f = 5;
                    for (inti = 5; i >= 1; i–) {
                        for (int j = 1; j <= 6– i; j++) {
                            System.out.print(“ * ”);
                        }
                        System.out.println();
                    }
                    for (int a = 1; a <= 4; a++) {
                        for (int b = 1; b <= 6– f; b++) {
                            System.out.print(”“);
                        }
                        for (int c = 1; c <= 5– a; c++) {
                            System.out.print(“ * ”);
                        }
                        System.out.println();
                        f–;
                    }
                    break;
                case 7:
                    System.out.println(“Tipebintang 7: ”);
                    int g = 1;
                    for (int a = 3; a >= 1; a–) {
                        for (int b = 1; b <= 3 - a; b++) {
                            System.out.print(”“);
                        }
                        for (int c = 1; c <= 6 - g; c++) {
                            System.out.print(“ * ”);
                        }
                        System.out.println();
                        g += 2;
                    }
                    break;
                case 8:
                    System.out.println(“Tipebintang 8: ”);
                    int h = 5;
                    for (int a = 1; a <= 3; a++) {
                        for (int b = 1; b <= 4– a; b++) {
                            System.out.print(”“);
                        }
                        for (int c = 1; c <= 6 - h; c++) {
                            System.out.print(“ * ”);
                        }
                        System.out.println();
                        h -= 2;
                    }
                    break;
                case 9:
                    int k = 1;
                    for (int a = 3; a >= 1; a–) {
                        for (int b = 1; b <= 3 - a; b++) {
                            System.out.print(”“);
                        }
                        for (int c = 1; c <= 6 - k; c++) {
                            System.out.print(“ * ”);
                        }
                        System.out.println();
                        k += 2;
                    }
                    int m = 2;
                    for (int d = 1; d <= 2; d++) {
                        for (int e = d; e <= 1; e++) {
                            System.out.print(”“);
                        }
                        for (int j = 1; j <= 5 - m; j++) {
                            System.out.print(“ * ”);
                        }
                        m -= 2;
                        System.out.println();
                    }
                    break;
                case 10:
                    System.out.println(“Tipebintang 10: ”);
                    int q = 3, r = 1;
                    for (int a = 1; a <= 3; a++) {
                        for (int b = a; b <= 2; b++) {
                            System.out.print(”“);
                        }
                        for (int c = 4– q; c >= 1; c–) {
                            System.out.print(“ * ”);
                        }
                        q -= 2;
                        System.out.println();
                    }
                    for (int d = 1; d <= 2; d++) {
                        for (int e = 1; e <= -2 - q; e++) {
                            System.out.print(”“);
                        }
                        for (inti = 4– r; i >= 1; i–) {
                            System.out.print(“ * ”);
                        }
                        System.out.println();
                        q–;
                        r += 2;
                    }
                    break;
                case 11:
                    System.out.println(“Tipebintang 11: ”);
                    for (int a = 1; a <= 3; a++) {
                        for (int b = 1; b <= a; b++) {
                            System.out.print(“ * ”);
                        }
                        System.out.println();
                    }
                    break;
                case 12:
                    System.out.println(“Tipebintang 12: ”);
                    for (int a = 1; a <= 3; a++) {
                        for (int b = a; b <= 3; b++) {
                            System.out.print(“ * ”);
                        }
                        System.out.println();
                    }
                    break;
                case 13:
                    System.out.println(“Tipebintang 13: ”);
                    for (int a = 1; a <= 3; a++) {
                        for (int b = a; b <= 3; b++) {
                            System.out.print(”“);
                        }
                        for (int c = 1; c <= a; c++) {
                            System.out.print(“ * ”);
                        }
                        System.out.println();
                    }
                    break;
                case 14:
                    System.out.println(“Tipebintang 14: ”);
                    for (int a = 3; a >= 1; a–) {
                        for (int b = a; b <= 3; b++) {
                            System.out.print(”“);
                        }
                        for (int c = 1; c <= a; c++) {
                            System.out.print(“ * ”);
                        }
                        System.out.println(“”);
                    }
                    break;
                case 15:
                    System.out.println(“Tipebintang 15: ”);
                    for (int a = 1; a <= 2; a++) {
                        System.out.print(”“);
                        System.out.print(“ * ”);
                    }
                    System.out.println(“”);
                    System.out.print(”“);
                    for (int b = 1; b <= 2; b++) {
                        System.out.print(”“);
                        System.out.print(“ ** ”);
                    }
                    System.out.println(“”);
                    System.out.print(”“);
                    for (int c = 1; c <= 5; c++) {
                        System.out.print(“”);
                        System.out.print(“ * ”);
                    }
                    System.out.println(“”);
                    System.out.print(”“);
                    for (int d = 1; d <= 2; d++) {
                        System.out.print(”“);
                        System.out.print(“ ** ”);
                    }
                    System.out.println(“”);
                    System.out.print(“”);
                    for (int e = 1; e <= 2; e++) {
                        System.out.print(”“);
                        System.out.print(“ * ”);
                    }
                    System.out.println(“”);
                    break;
                case 16:
                    System.out.println(“Tipebintang 16: ”);
                    int a = 4;
                    for (int b = 1; b <= 1; b++) {
                        for (int c = 1; c <= 5; c++) {
                            System.out.print(“ * ”);
                        }
                        System.out.println();
                    }
                    for (a = 1; a >= 1; a–) {
                        for (int b = 2; b >= 1; b–) {
                            System.out.print(“ * ”);
                        }
                        for (int c = 1; c <= 1; c++) {
                            System.out.print(”“);
                        }
                        for (int d = 1; d <= 2; d++) {
                            System.out.print(“ * ”);
                        }
                        System.out.println();
                    }
                    for (int b = 1; b <= 2; b++) {
                        for (int c = 1– b; c <= 0; c++) {
                            System.out.print(“ * ”);
                        }
                        for (int d = 1; d <= 3– b; d++) {
                            System.out.print(”“);
                        }
                        for (int e = 2– b; e >= 1; e–) {
                            System.out.print(”“);
                        }
                        for (int j = 1; j <= 1– a; j++) {
                            System.out.print(“ * ”);
                        }
                        a–;
                        System.out.println();
                    }
                    for (int b = 1; b <= 1; b++) {
                        for (int c = 1; c <= 5; c++) {
                            System.out.print(“ * ”);
                        }
                        System.out.println();
                    }
                    break;
                case 0:
                    System.out.println(“EXIT”);
                    System.out.println(“TerimaKasih…”);
                    break;
                default:
                    System.out.println(“Pilihansalah”);
            }
            System.out.print(“Ulangi(ya / tidak) ? : ”);
            pil2 = input.next();
            if (pil2.equals(“ya”)) {
                System.out.println();
            } else if (!pil2.equals(“ya”)) {
                System.out.println(“EXIT”);
                System.out.println(“TerimaKasih…”);
                break;
            }
        }
    }
}
