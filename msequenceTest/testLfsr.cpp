#include "pch.h"
#include "../msequence/lfsr.h"
#include "../msequence/UsingBitRecorder.h"

TEST( TestLfsr, Test3Bit ) {
	const int bit_num=3;

	LfsrParams lfsr_param = find_lfsr_param( bit_num );

	uint64_t mnumber = 1;
	const uint64_t mseq_bit_length = 1LL << bit_num;

	UsingBitRecorder *recorder = new UsingBitRecorder(1<<bit_num);
	recorder->SetBit(0);

	for (uint64_t i = 0; i < mseq_bit_length-1; i++)
	{
		recorder->SetBit(mnumber);
		mnumber = mseq( mnumber, bit_num, lfsr_param.taps );
	}
	recorder->SetBit(mnumber);
	EXPECT_TRUE(recorder->IsAllSet());
	EXPECT_EQ(recorder->GetNumberOfSetBits(),1<<bit_num);
}

TEST( TestLfsr, Test4Bit ) {
	const int bit_num=4;

	LfsrParams lfsr_param = find_lfsr_param( bit_num );

	uint64_t mnumber = 1;
	const uint64_t mseq_bit_length = 1LL << bit_num;

	UsingBitRecorder *recorder = new UsingBitRecorder(1<<bit_num);
	recorder->SetBit(0);

	for (uint64_t i = 0; i < mseq_bit_length-1; i++)
	{
		recorder->SetBit(mnumber);
		mnumber = mseq( mnumber, bit_num, lfsr_param.taps );
	}
	recorder->SetBit(mnumber);
	EXPECT_TRUE(recorder->IsAllSet());
	EXPECT_EQ(recorder->GetNumberOfSetBits(),1<<bit_num);
}

TEST( TestLfsr, Test8Bit ) {
	const int bit_num=8;

	LfsrParams lfsr_param = find_lfsr_param( bit_num );

	uint64_t mnumber = 1;
	const uint64_t mseq_bit_length = 1LL << bit_num;

	UsingBitRecorder *recorder = new UsingBitRecorder(1<<bit_num);
	recorder->SetBit(0);

	for (uint64_t i = 0; i < mseq_bit_length-1; i++)
	{
		recorder->SetBit(mnumber);
		mnumber = mseq( mnumber, bit_num, lfsr_param.taps );
	}
	recorder->SetBit(mnumber);
	EXPECT_TRUE(recorder->IsAllSet());
	EXPECT_EQ(recorder->GetNumberOfSetBits(),1<<bit_num);
}

TEST( TestLfsr, Test16Bit ) {
	const int bit_num=16;

	LfsrParams lfsr_param = find_lfsr_param( bit_num );

	uint64_t mnumber = 1;
	const uint64_t mseq_bit_length = 1LL << bit_num;

	UsingBitRecorder *recorder = new UsingBitRecorder(1<<bit_num);
	recorder->SetBit(0);

	for (uint64_t i = 0; i < mseq_bit_length-1; i++)
	{
		recorder->SetBit(mnumber);
		mnumber = mseq( mnumber, bit_num, lfsr_param.taps );
	}
	recorder->SetBit(mnumber);
	EXPECT_TRUE(recorder->IsAllSet());
	EXPECT_EQ(recorder->GetNumberOfSetBits(),1<<bit_num);
	delete recorder;
}

TEST( TestLfsr, TestLessEq20Bit ) {

	std::vector<uint64_t> mnumbers = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	for (auto mnumber : mnumbers)
	{
		for (auto const &lfsr_param : lfsr_params)
		{
			int bit_num = lfsr_param.bit_size;
			if (bit_num>20) continue;
			if (mnumber >= (1LL<<bit_num) ) continue;

			LfsrParams lfsr_param = find_lfsr_param( bit_num );

			const uint64_t mseq_bit_length = 1LL << bit_num;

			// テスト用のビットレコーダーを作成
			UsingBitRecorder *recorder = new UsingBitRecorder(1<<bit_num);
			recorder->SetBit(0);

			for (uint64_t i = 0; i < mseq_bit_length-1; i++)
			{
				recorder->SetBit(mnumber);
				mnumber = mseq( mnumber, bit_num, lfsr_param.taps );
			}
			recorder->SetBit(mnumber);
			// 全部の数が現れていることを確認
			EXPECT_TRUE(recorder->IsAllSet());
			EXPECT_EQ(recorder->GetNumberOfSetBits(),1<<bit_num);
			delete recorder;
		}
	}
}

