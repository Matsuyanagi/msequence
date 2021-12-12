#include "lfsr.h"

std::vector<LfsrParams> lfsr_params = {
	{3, {0,1}},
	{4, {0,1}},
	{5, {0,2}},
	{6, {0,1}},
	{7, {0,1}},
	{8, {0,2,3,4}},
	{9, {0,4}},
	{10, {0,3}},
	{11, {0,2}},
	{12, {0,1,4,6}},
	{13, {0,1,3,4}},
	{14, {0,1,3,5}},
	{15, {0,1}},
	{16, {0,2,3,5}},
	{20, {0,3}},
	{31, {0,3}},
	{32, {0,2,6,7}},
};

/**
 * 適切な lfsr_param を探す
 */
LfsrParams find_lfsr_param(int32_t bit_size)
{
	for (auto& lfsr_param : lfsr_params) {
		if (lfsr_param.bit_size == bit_size) {
			return lfsr_param;
		}
	}
	return LfsrParams{};
}


uint64_t mseq( uint64_t mnumber, int32_t bit_size, const std::vector<uint32_t> &taps )
{
	uint64_t bit = 0;
	for (auto &&tap : taps)
	{
		bit ^= (mnumber >> tap);
	}
	bit &= 1;
	mnumber = (mnumber >> 1) | (bit << (bit_size - 1));
	return mnumber;
}
