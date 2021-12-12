#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "lfsr.h"

/* 
	M系列

	x64\Debug\msequence.exe 3
	100101110
	x64\Debug\msequence.exe 4
	100010011010111100
	x64\Debug\msequence.exe 5
	10000100101100111110001101110101000
	x64\Debug\msequence.exe 6
	10000010000110001010011110100011100100101101110110011010101111110000
	x64\Debug\msequence.exe 7
	1000000100000110000101000111100100010110011101010011111010000111000100100110110101101111011000110100101110111001100101010111111100000
	x64\Debug\msequence.exe 8
	1000000010001110001001011100000011001001001101110010000010101101101011001011000011111011011110101110100010000110110001111001110011000101101001000101001010100111011101100111101111110100110011010100011000001110101010111110010100001001111111100001011110001101000000

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

	for (uint64_t i = 0; i < mseq_bit_length-1; i++)
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


