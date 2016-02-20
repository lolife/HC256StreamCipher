#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>

typedef unsigned int uint32;
typedef unsigned char uint8;
uint32 P[1024],Q[1024];
uint32 X[16],Y[16];
uint32 counter2048; // counter2048 = i mod 2048;

void encrypt(uint32 data[]);
void initialization(uint32 key[], uint32 iv[]);
