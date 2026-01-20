#ifndef OPCODE8080_H
#define OPCODE8080_H

extern int print0x(unsigned char *code);
extern int print1x(unsigned char *code);
extern int print2x(unsigned char *code);
extern int print3x(unsigned char *code);
extern int print4x(unsigned char *code);
extern int print5x(unsigned char *code);
extern int print6x(unsigned char *code);
extern int print7x(unsigned char *code);
extern int print8x(unsigned char *code);
extern int print9x(unsigned char *code);
extern int printax(unsigned char *code);
extern int printbx(unsigned char *code);
extern int printcx(unsigned char *code);
extern int printdx(unsigned char *code);
extern int printex(unsigned char *code);
extern int printfx(unsigned char *code);

#endif // OPCODE8080_H