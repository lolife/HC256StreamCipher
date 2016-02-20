all: hc256_encrypt hc256_decrypt	

hc256_encrypt: hc256.c hc256_encrypt.c
	gcc -o hc256_encrypt -Wall hc256.c hc256_encrypt.c -I.

hc256_decrypt: hc256.c hc256_decrypt.c
	gcc -o hc256_decrypt -Wall hc256.c hc256_decrypt.c -I.

clean:
	rm hc256_encrypt
	rm hc256_decrypt
