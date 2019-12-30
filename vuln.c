/****************************
#
# Pranay Garg
#
# Test code for buff_over
#   - Added comments
# adapted from:
# https://samsclass.info/127/proj/ED402.htm
#
*****************************/
#include <stdio.h>
#include <unistd.h>

/*
 * Vulnerable function with an overflow problem.
 */
int vuln() {
    char buf[400];
    int r;
    /* Some assembly code to print the stack start address! */
    register int i asm("rsp");
    printf("Welcome to the Proj 13 Server!\n\n");
    printf("$rsp = %#018x\n\nEnter some text:\n", i);
    r = read(0, buf, 800);
    printf("You said: %s\n", buf);
    return 0;
}

/* A function that's never called! */
int pandu_rocks(){
    printf("We won!\n");
    return 0;
}

int main(int argc, char *argv[]) {
    vuln();
    printf("Bye!\n");
    return 0;
}
