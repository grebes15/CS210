/**
 * Simulation of the multiplication algorithm in Figure 3-5, page
 * 232 of Patterson & Hennessy, with one change--this multiplies
 * 16-bit integers to get a 32-bit result; the algorithm in P&H
 * multiplies 32-bit integers to get a 64-bit result. (The constant
 * MAXBITS can be changed, of course.) 
 */

import java.util.*;

public class Fig3_5 {
    public static final int MAXBITS = 32;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // for user input

        System.out.print("Multiplicand? ");
        long mcand = in.nextInt();

        System.out.print("Multiplier? ");
        long mpier = in.nextInt();

        int max = (1 << (MAXBITS/2)) - 1;

        if (mcand > max || mpier > max) {
            System.out.println("Operands must not exceed " + max + "; quitting");
            System.exit(1);
        }

        System.out.println("\nKeep hitting the 'Enter' or 'Return' key:");
        long product = 0;

        in.nextLine(); // "dummy" read to get past end of line

        // Main loop in the flowchart:
        for (int i = 0; i < MAXBITS/2; i++) {  
            System.out.println("\ni = " + i + " (hit enter):"); // step through
            in.nextLine();

            display("Multiplier",mpier);
            display("Multiplicand",mcand);
            display("Product",product);

            // Flowchart: "1. Test Multiplier0"
            if (mpier % 2 == 1) {
                // "1a: ..."
                System.out.println("Multiplier0 == 1: add multiplicand to product:");
                product += mcand;
                display("Product",product);
            }
            mcand <<= 1; // "2. Shift multiplicand register left 1 bit"
            mpier >>= 1; // "3. Shift multiplier register right 1 bit"
        }
        System.out.println("\nFinal register contents:");
        display("Multiplier",mpier);
        display("Multiplicand",mcand);
        display("Product",product);
    }

    /**
     * This just prints out the contents of a register in both binary
     * and decimal.
     */
    public static void display(String label, long value)
    {
        String binary = "";
        long v = value;
        for (int i = 0; i < MAXBITS; i++) {
            if (v == 0 && i > 0)
                binary = "."+binary;
            else if (v % 2 == 0)
                binary = "0"+binary;
            else
                binary = "1"+binary;
            v /= 2;
        }
        System.out.println(label + ":\t" + binary + "   ("+ value + ")");
    }
}
