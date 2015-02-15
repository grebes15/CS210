/*
  prog2.c -- expression statements like 1 or "hi" do nothing but
  represent their values; integers can be used as boolean expressions
  where 0 is false and nonzero is true; the "comma operator" strings
  several statements together into a single statement.

  This program does nothing.
   
   Compile using:
         gcc prog2.c -o prog2
  
   Execute using:
         ./prog2
  
   (Any name may be used as the executable; by default it is a.out)
 */

main() {
    1;
    "hi";
    ;;;;
    if (0) main();
    while (1 <= 0) {
        42,23,12,0,"hi",7;
    }
}
