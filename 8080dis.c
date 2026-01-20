#include <stdio.h>
#include <stdlib.h>
#include "opcode8080.h"

/*
 * codebuffer is a valid pointer to 8080 assembly code
 pc is the current offset into the code

 return the number of bytes of the cp
*/
int Disassemble8080Op(unsigned char *codebuffer, int pc) {
    unsigned char *code = &codebuffer[pc];  // equivalent to codebuffer + pc
    int opbytes = 1;

    printf("%04x ", pc);

    if (0x00 <= *code && *code <= 0x0f) {
        opbytes = print0x(code);
    }
    else if (0x10 <= *code && *code <= 0x1f) {
        opbytes = print1x(code);
    }
    else if (0x20 <= *code && *code <= 0x2f) {
        opbytes = print2x(code);
    }
    else if (0x30 <= *code && *code <= 0x3f) {
        opbytes = print3x(code);
    }
    else if (0x40 <= *code && *code <= 0x4f) {
        opbytes = print4x(code);
    }
    else if (0x50 <= *code && *code <= 0x5f) {
        opbytes = print5x(code);
    }
    else if (0x60 <= *code && *code <= 0x6f) {
        opbytes = print6x(code);
    }
    else if (0x70 <= *code && *code <= 0x7f) {
        opbytes = print7x(code);
    }
    else if (0x80 <= *code && *code <= 0x8f) {
        opbytes = print8x(code);
    }
    else if (0x90 <= *code && *code <= 0x9f) {
        opbytes = print9x(code);
    }
    else if (0xa0 <= *code && *code <= 0xaf) {
        opbytes = printax(code);
    }
    else if (0xb0 <= *code && *code <= 0xbf) {
        opbytes = printbx(code);
    }
    else if (0xc0 <= *code && *code <= 0xcf) {
        opbytes = printcx(code);
    }
    else if (0xd0 <= *code && *code <= 0xdf) {
        opbytes = printdx(code);
    }
    else if (0xe0 <= *code && *code <= 0xef) {
        opbytes = printex(code);
    }
    else if (0xf0 <= *code && *code <= 0xff) {
        opbytes = printfx(code);
    }

    printf("\n");

    return opbytes;
}

int main(int argc, char** argv) {
    FILE *f = fopen(argv[1], "rb");
    if (f == NULL) {
        printf("error: Could not open %s\n", argv[1]);
        exit(1);
    }

    // get the file size and read it into a memory buffer
    fseek(f, 0L, SEEK_END);
    int fsize = ftell(f);
    fseek(f, 0L, SEEK_SET);

    unsigned char *buffer = malloc(fsize);
    
    fread(buffer, 1, fsize, f);
    fclose(f);

    int pc = 0;

    while (pc < fsize) {
        pc += Disassemble8080Op(buffer, pc);
    }
    
    return 0;
}
