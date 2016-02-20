#include "hc256.h"

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

static uint32 key[8] = {'M','I','C','H','A','E','L','1'};
static uint32 iv[8]  = {'1','8','6','7','5','3','0','9'};

int main( int argc, char* argv[] ) {
	uint32	i,
			c[16],
			keystream[16]; // the random keystream

	uint32 *data = malloc( sizeof( uint32 ) * 4096 );

    FILE *infile = fopen( argv[1], "r" );
    if( infile == NULL ) {          
        printf( "Error: Could not open file %s.\n", argv[1] );
        return(1);
    }       

    int n=0;    
    while( !feof( infile) && n < 4096 ) {
        fscanf( infile, "%u ", &data[n] );
        ++n;
    } 
    fclose( infile );
//	--n;

	printf( "%i records. First number is %u\n", n, data[0] );

    //key and iv setup
    initialization(key,iv);

	for( int counter = 0; counter < n/16; counter++ ) {
    	//generate and print the first 512-bit keystream
    	for (i = 0; i < 16; i++) { keystream[i]=0; }
		encrypt(keystream);
		for (i = 0; i < 16; i++) {
			c[i] = data[(counter*16)+i];
			uint32 val = c[i] ^ keystream[i];
			for( int l = 0; l < 4; l+=1 ) {
				;
				printf( "%c", (val >> l*8 & 0XFF ) );
			}
		}
//		printf( "\n" );
	}
	printf( "\n" );
	return (0);
}
