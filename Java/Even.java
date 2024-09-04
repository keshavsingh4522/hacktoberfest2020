import java.util.Scanner;
public class Even {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int jamAwal, menitAwal, detikAwal, jamAkhir, menitAkhir, detikAkhir;

        // Input keberangkatan
        System.out.print("Masukkan jam keberangkatan \t: ");
        jamAwal = sc.nextInt();
        System.out.print("Masukkan menit keberangkatan \t: ");
        menitAwal = sc.nextInt();
        System.out.print("Masukkan detik keberangkatan \t: ");
        detikAwal = sc.nextInt();
        System.out.println(String.format("Waktu keberangkatan adalah pukul %s:%s:%s", jamAwal, menitAwal, detikAwal));

        // Input kedatangan
        System.out.print("\nMasukkan jam kedatangan \t: ");
        jamAkhir = sc.nextInt();
        System.out.print("Masukkan menit kedatangan \t: ");
        menitAkhir = sc.nextInt();
        System.out.print("Masukkan detik kedatangan \t: ");
        detikAkhir = sc.nextInt();
        System.out.println(String.format("Waktu kedatangan adalah pukul %s:%s:%s", jamAkhir, menitAkhir, detikAkhir));

        // Waktu istirahat
        int jamRest = 0, menitRest = 0, detikRest = 0;
        String s;
        System.out.print("\nApakah anda beristirahat selama perjalanan? (Y = Ya, T = Tidak) : ");
        s = sc.next();
        System.out.println();
        while ((s.charAt(0)=='Y') || (s.charAt(0)=='y')) {
            System.out.print("Masukkan jam istirahat \t\t: ");
            jamRest = sc.nextInt();
            System.out.print("Masukkan menit istirahat \t : ");
            menitRest = sc.nextInt();
            System.out.print("Masukkan detik istirahat \t : ");
            detikRest = sc.nextInt();
            System.out.println(String.format("Waktu istirahat anda adalah %s jam %s menit %s detik", jamRest, menitRest, detikRest));
            break;
        }
        
        // Waktu perjalanan
        if (detikAwal > detikAkhir) {
            menitAkhir -= 1;
            detikAkhir += 60;
        }
        if (menitAwal > menitAkhir) {
            jamAkhir -= 1;
            menitAkhir += 60;
        }
        int jamSelisih = jamAkhir - jamAwal;
        int menitSelisih = menitAkhir - menitAwal;
        int detikSelisih = detikAkhir - detikAwal;
        while ((s.charAt(0)=='Y') || (s.charAt(0)=='y')) {
            if (detikRest > detikSelisih) {
                menitSelisih -= 1;
                detikSelisih += 60;
            }
            if (menitRest > menitSelisih) {
                jamSelisih -= 1;
                menitSelisih += 60;
            }
            jamSelisih -= jamRest;
            menitSelisih -= menitRest;
            detikSelisih -= detikRest;
            break;
        }
        System.out.println(String.format("\nWaktu perjalanannya adalah %s jam %s menit %s detik", jamSelisih, menitSelisih, detikSelisih));
    }
}