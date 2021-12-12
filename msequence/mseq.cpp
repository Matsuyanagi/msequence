#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "lfsr.h"

/* 
	M系列

	x64\Debug\msequence.exe 3
	1001011100
	x64\Debug\msequence.exe 4
	1000100110101111000
	x64\Debug\msequence.exe 5
	100001001011001111100011011101010000
	x64\Debug\msequence.exe 6
	100000100001100010100111101000111001001011011101100110101011111100000
	x64\Debug\msequence.exe 7
	10000001000001100001010001111001000101100111010100111110100001110001001001101101011011110110001101001011101110011001010101111111000000
	x64\Debug\msequence.exe 8
	10000000100011100010010111000000110010010011011100100000101011011010110010110000111110110111101011101000100001101100011110011100110001011010010001010010101001110111011001111011111101001100110101000110000011101010101111100101000010011111111000010111100011010000000

 */

int main(int argc, char *argv[])
{
	int32_t bit_size = 3;
	if ( argc > 1 )
	{
		bit_size = atoi(argv[1]);
	}
	
	LfsrParams lfsr_param = find_lfsr_param( bit_size );
	if (lfsr_param.bit_size == 0)
	{
		printf("Error: LFSR Param not found\n");
		return -1;
	}
	uint64_t mnumber = 1;
	uint64_t mseq_bit_length = 1LL << bit_size;

	for (uint64_t i = 0; i < mseq_bit_length; i++)
	{
		putc( (mnumber & 1) + '0', stdout );
		mnumber = mseq( mnumber, bit_size, lfsr_param.taps );
	}

	for (size_t i = 0; i < bit_size-1; i++)
	{
		putc( (mnumber & 1) + '0', stdout );
		mnumber >>= 1;
	}
	puts("");
	
	return 0;
}


