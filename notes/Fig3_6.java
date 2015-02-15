/**
 * Simulation of the multiplication algorithm in Figure 3-6, page
 * 233 of Patterson & Hennessy, with one change--this multiplies
 * 16-bit integers to get a 32-bit result; the algorithm in P&H
 * multiplies 32-bit integers to get a 64-bit result. (The constant
 * MAXBITS can be changed, of course.) 
 */

import java.util.*;

public class Fig3_6 {
    public static final int MAXBITS = 32;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // for user input

        System.out.print("Multiplicand? ");
        long mcand = in.nextInt();

        System.out.print("Multiplier? ");
        long product = in.nextInt(); // Multiplier is in lower half of product

        int max = (1 << (MAXBITS/2)) - 1;

        if (mcand > max || product > max) {
            System.out.println("Operands must not exceed " + max + "; quitting");
            System.exit(1);
        }

        mcand <<= MAXBITS/2; // So it will be added to the UPPER half of product

        System.out.println("\nKeep hitting the 'Enter' or 'Return' key:");

        in.nextLine(); // "dummy" read to get past end of line

        // Main loop -- repeat for each bit in the multiplier:
        for (int i = 0; i < MAXBITS/2; i++) {  
            System.out.println("\ni = " + i + " (hit enter):"); // step through
            in.nextLine();

            display("Multiplicand",mcand);
            display("Product",product);

            // Check zero-bit of the multiplier (in right half of product):
            if ((product & 1) != 0) {
                System.out.println("Multiplier0 == 1: add multiplicand to product:");
                product += mcand; // addition takes place in left half of product
                display("Product",product);
            }
            product >>= 1; // shift product register right one bit
        }
        System.out.println("Final register contents:");
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
