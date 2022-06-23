#include <stdio.h>

int main() {
    // 1. Declare and initialize variables of types char, int, and long.
    char c = 'a';
    int i = 99;
    long l = 100;

    // 2. Print out the addresses of each variable in hex and decimal.
    printf("hex\t c:%p i:%p l:%p\n", &c, &i, &l);
    printf("decimal\t  c:%lu i:%lu l:%lu\n", &c, &i, &l);

    // 3. Declare and initialize pointers for each of your variables.
    char *cp = &c;
    int *ip = &i;
    long *lp = &l;

    // 4. Print out the values of each pointer.
    printf("pointers\t cp:%p ip:%p lp:%p\n", cp, ip, lp);

    // 5. Use the pointers to modify the values of the original variables 
    // and print out the new values.
    *cp += 1;
    *ip += 2;
    *lp -= 1;
    printf("new pointers\t  c:%lu i:%lu l:%lu\n", c, i, l);

    // 6. Declare and initialize an unsigned int variable and 2 pointers that point 
    // to it, one should be an int * and the other should be a char *
    unsigned int ui = 115;
    int *uip = &ui;
    char *ucp = &ui;

    // 7. Print out the value of each pointer (this should be the memory address), 
    // and de-reference each pointer to print out the value each points to.
    printf("ui:\t %p points to %d\n", *uip, ui);
    printf("ui:\t %p points to %c\n", ui, *ucp);

    // 8. Print out your unsigned int in decimal and hex.
    printf("ui in hex:\t %x\t\n", ui);
    printf("ui in decimal:\t %u\t\n", ui);

    // 9. Use the char * to print out each individual byte of your unsigned int
    printf("bytes in hex: %hhx %hhx %hhx %hhx\n", *ucp, *(ucp+1), *(ucp+2), *(ucp+3));
    printf("bytes in decimal: %hhu %hhu %hhu %hhu\n", *ucp, *(ucp+1), *(ucp+2), *(ucp+3));

    // 10. Use the char * to increment each byte of the unsigned int by 1. Print 
    // out the unsigned int in both hex and decimal after each modification. When 
    // done, print out each byte like in step 9. You may need to reset the char * 
    // so that it points to the unsigned int, depending on how you wrote step 4 out.   
    *ucp++; 
    printf("hex: %x ", ui);
    printf("decimal: %u\n", ui);
    (*(ucp+1))++; 
    printf("hex: %x ", ui);
    printf("decimal: %u\n", ui);
    (*(ucp+2))++; 
    printf("hex: %x ", ui);
    printf("decimal: %u\n", ui);
    (*(ucp+3))++; 
    printf("hex: %x ", ui);
    printf("decimal: %u\n", ui); 
    printf("bytes in hex: %hhx %hhx %hhx %hhx\n", *ucp, *(ucp+1), *(ucp+2), *(ucp+3));
    printf("bytes in decimal: %hhu %hhu %hhu %hhu\n", *ucp, *(ucp+1), *(ucp+2), *(ucp+3));

    // 11. Perform the same operation as in step 10, except add 16 to each byte.
    *ucp += 16; 
    printf("hex: %x ", ui);
    printf("decimal: %u\n", ui);
    (*(ucp+1)) += 16; 
    printf("hex: %x ", ui);
    printf("decimal: %u\n", ui);
    (*(ucp+2)) += 16; 
    printf("hex: %x ", ui);
    printf("decimal: %u\n", ui);
    (*(ucp+3)) += 16; 
    printf("hex: %x ", ui);
    printf("decimal: %u\n", ui); 
    printf("bytes in hex: %hhx %hhx %hhx %hhx\n", *ucp, *(ucp+1), *(ucp+2), *(ucp+3));
    printf("bytes in decimal: %hhu %hhu %hhu %hhu\n", *ucp, *(ucp+1), *(ucp+2), *(ucp+3));


}