#include <stdint.h>
#include <vector>

struct LfsrParams {
	uint32_t bit_size;
	std::vector<uint32_t> taps;
};

extern std::vector<LfsrParams> lfsr_params;


extern LfsrParams find_lfsr_param(int32_t bit_size);
extern uint64_t mseq( uint64_t mnumber, int32_t bit_size, const std::vector<uint32_t> &taps );
