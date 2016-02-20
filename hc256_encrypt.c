#include "hc256.h"

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main( int argc, char* argv[] ) {
    uint32 keystream[16]; // the random keystream
    uint32 i;
	uint32	c[16];
	static uint32 key[8] = {'M','I','C','H','A','E','L','1'};
	static uint32 iv[8]  = {'1','8','6','7','5','3','0','9'};
	uint32 *msg = malloc( sizeof(uint32) * 64 );
	char *mys = calloc( 4096, sizeof(char) );

    FILE *infile = fopen( argv[1], "r" );
    if( infile == NULL ) {          
        printf( "Error: Could not open file %s.\n", argv[1] );
        return(1);
    }       

    int n=0;    
    while( !feof( infile) && n < 4096 ) {
		mys[n] = fgetc( infile );
        ++n;
    } 
    fclose( infile );

//	printf( "Got %i characters.\n", n );
//	printf( "plaintext:\n====\n%s\n====\n", mys );

    //key and iv setup
    initialization(key,iv);

	int bits = strlen( &mys[0] ) * 8;
	int t=0;

	while( bits > 0 ) {
		memcpy( msg, &mys[t*64], 64 );
		bits -=512;

    	//generate and print the first 512-bit keystream
    	for (i = 0; i < 16; i++) { keystream[i]=0; }
		encrypt(keystream);
		for (i = 0; i < 16; i++) {
			c[i] = msg[i] ^ keystream[i];
			printf( "%u ", c[i] );
		}
		t+=1;
	}
	printf( "\n" );
	return (0);
}
