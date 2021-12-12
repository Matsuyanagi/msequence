#pragma once
#include <vector>

class UsingBitRecorder {

public:
	UsingBitRecorder(uint32_t n);

	void Clear();
	void SetBit(uint32_t bit_index);
	void ResetBit(uint32_t bit_index);
	bool TestBit(uint32_t bit_index) const;
	uint32_t GetNumberOfSetBits() const;
	bool IsEmpty() const;
	bool IsAllSet() const;

private:
	uint32_t bit_size;
	uint32_t using_bit_counter;
	std::vector<uint64_t> bit_recorder;

};
