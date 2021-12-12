#include "UsingBitRecorder.h"
#include <algorithm>

UsingBitRecorder::UsingBitRecorder( uint32_t bit_size)
{
	this->bit_size = bit_size;
	this->bit_recorder.resize(bit_size/64 + 1,0);
	this->Clear();
}

// クリア
void UsingBitRecorder::Clear()
{
	std::fill(bit_recorder.begin(), bit_recorder.end(), 0);
	this->using_bit_counter = 0;
}

// ビットを立てる
void UsingBitRecorder::SetBit(uint32_t bit_index)
{
	const uint32_t bit_index_in_recorder = bit_index / 64;
	const uint32_t bit_index_in_recorder_bit = bit_index % 64;
	const uint64_t mask = 1LL << bit_index_in_recorder_bit;
	if ( this->bit_recorder[bit_index_in_recorder] & mask )
	{
		return;
	}
	this->bit_recorder[bit_index_in_recorder] |= mask;
	this->using_bit_counter++;
}

// ビットを消す
void UsingBitRecorder::ResetBit(uint32_t bit_index)
{
	const uint32_t bit_index_in_recorder = bit_index / 64;
	const uint32_t bit_index_in_recorder_bit = bit_index % 64;
	const uint64_t mask = 1LL << bit_index_in_recorder_bit;
	if ( !(this->bit_recorder[bit_index_in_recorder] & mask) )
	{
		return;
	}
	this->bit_recorder[bit_index_in_recorder] &= ~mask;
	this->using_bit_counter--;
}

// ビットが立っているかを返す
bool UsingBitRecorder::TestBit(uint32_t bit_index) const
{
	const uint32_t bit_index_in_recorder = bit_index / 64;
	const uint32_t bit_index_in_recorder_bit = bit_index % 64;
	const uint64_t mask = 1LL << bit_index_in_recorder_bit;
	return (this->bit_recorder[bit_index_in_recorder] & mask) != 0;
} 

// 立っているビット数を返す
uint32_t UsingBitRecorder::GetNumberOfSetBits() const
{
	return this->using_bit_counter;
}

// どれも立っていないかを返す
bool UsingBitRecorder::IsEmpty() const
{
	return this->using_bit_counter == 0;
}

// 全部立っているかを返す
bool UsingBitRecorder::IsAllSet() const
{
	return this->using_bit_counter == this->bit_size;
}
