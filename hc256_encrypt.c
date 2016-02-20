#include "hc256.h"

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main( int argc, char* argv[] ) {
    uint32 keystream[16]; // the random keystream
    uint32 i;
	uint32	*msg,
			c[16];
	char*	mys;
	static uint32 key[8] = {'M','I','C','H','A','E','L','1'};
	static uint32 iv[8]  = {'1','8','6','7','5','3','0','9'};
	const char * plaintext = "Cordially convinced did incommode existence put out suffering certainly. Besides another and saw ferrars limited ten say unknown. On at tolerably depending do perceived. Luckily eat joy see own shyness minuter. So before remark at depart. Did son unreserved themselves indulgence its. Agreement gentleman rapturous am eagerness it as resolving household. Direct wicket little of talked lasted formed or it. Sweetness consulted may prevailed for bed out sincerity. M.";

	msg = malloc( 64 );
	mys = malloc( 8*strlen(plaintext) );
	sprintf( mys, "%s", plaintext );

//	uint32 *data = malloc( sizeof( uint32 ) * 4096 );

//    FILE *infile = fopen( argv[1], "r" );
//    if( infile == NULL ) {          
//        printf( "Error: Could not open file %s.\n", argv[1] );
//        return(1);
//    }       
//    int n=0;    
//    while( !feof( infile) && n < 4096 ) {
//		data[n] = malloc( sizeof( unsigned long ) );
 //       fscanf( infile, "%03i %03i %03i %03i ", &data[n] );
//        ++n;
//    } 
//    fclose( infile );
//	--n;

//	printf( "%i records. First number is %li\n", n, data[0] );

    //key and iv setup
    initialization(key,iv);

//	for (i = 0; i < strlen(&mys[0]); i++) { printf( "%c", mys[i] ); }
//	printf( "\n" );

	int bits = strlen( &mys[0] ) * 8;
	int t=0;

	while( bits > 0 ) {
		memcpy( msg, &mys[t*64], 64 );
		bits -=512;

    	//generate and print the first 512-bit keystream
    	for (i = 0; i < 16; i++) { keystream[i]=0; }
		encrypt(keystream);
//		printf( "\nCiphertext is:\n" );
		for (i = 0; i < 16; i++) {
			c[i] = msg[i] ^ keystream[i];
			printf( "%li ", c[i] );
		}
//			uint32 val = c[i];
//			for( int l = 0; l < 4; l+=1 ) {
//				;
//				printf( "%03i ",  val >> l*8 & 0XFF );
//			}
//		}

//		printf( "\nPlaintext is:\n" );
//   	for (i = 0; i < 16; i++) {
//			uint32 val = c[i] ^ keystream[i];
//			for( int l = 0; l < 4; l+=1 ) {
//				printf( "%c",  (val >> l*8 & 0XFF ) );
//			}
//			printf( "\n" );
//		}
		t+=1;
	}
	return (0);
}
