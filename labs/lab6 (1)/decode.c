/* Decoding an R-type MIPS instruction using bit masks 
 * Each mask picks out one group of bits. For instance, the
 * "opmask" sets the leftmost 6 bits to 1--"FC"--and leaves
 * the rest zero.
 *
 * Each piece of the instruction is shifted to the right 
 * so it can be printed as a decimal integer. Note that we 
 * use unsigned integers throughout.
 */

#include <stdio.h>

main()
{
    unsigned instr;                /* a one-word R-type MIPS instruction */

    unsigned opmask = 0xFC000000;  /* mask for opcode (31-26) */
    unsigned rsmask = 0x03E00000;  /* mask for rs (25-21) */
    unsigned rtmask = 0x001F0000;  /* mask for rt (20-16) */
    unsigned rdmask = 0x0000F800;  /* mask for rd (15-11) */
    unsigned shmask = 0x000007C0;  /* mask for shamt (10-6) */
    unsigned fumask = 0x0000003F;  /* mask for funct (5-0) */

    printf("Enter the hexadecimal code of an R-type MIPS instruction: ");
    scanf("%x",&instr);
    printf("opcode: %d\n",(instr & opmask)>>26); /* select bits and shift right*/
    printf("rs: %d\n",(instr & rsmask)>>21);
    printf("rt: %d\n",(instr & rtmask)>>16);
    printf("rd: %d\n",(instr & rdmask)>>11);
    printf("shamt: %d\n",(instr & shmask)>>6);
    printf("funct: %d\n",(instr & fumask));
}

