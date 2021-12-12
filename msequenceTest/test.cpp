#include "pch.h"
#include "../msequence/lfsr.h"
#include "../msequence/UsingBitRecorder.h"

TEST( TestUsingBitRecorder, Test1Bit ) {
	UsingBitRecorder *recorder = new UsingBitRecorder(1);
	EXPECT_TRUE(recorder->IsEmpty());
	EXPECT_EQ(recorder->GetNumberOfSetBits(),0);
	recorder->SetBit(0);
	EXPECT_TRUE(recorder->IsAllSet());
	EXPECT_EQ(recorder->GetNumberOfSetBits(),1);
	recorder->ResetBit(0);
	EXPECT_TRUE(recorder->IsEmpty());
	EXPECT_EQ(recorder->GetNumberOfSetBits(),0);
	EXPECT_FALSE(recorder->IsAllSet());
}

TEST( TestUsingBitRecorder, Test2Bit ) {
	UsingBitRecorder *recorder = new UsingBitRecorder(2);
	EXPECT_TRUE(recorder->IsEmpty());
	EXPECT_EQ(recorder->GetNumberOfSetBits(),0);
	recorder->SetBit(0);
	EXPECT_EQ(recorder->GetNumberOfSetBits(),1);
	EXPECT_FALSE(recorder->IsAllSet());
	recorder->SetBit(1);
	EXPECT_TRUE(recorder->IsAllSet());
	EXPECT_EQ(recorder->GetNumberOfSetBits(),2);
}

TEST( TestUsingBitRecorder, Test64Bit ) {
	int bit_num = 64;
	UsingBitRecorder *recorder = new UsingBitRecorder(bit_num);
	EXPECT_TRUE(recorder->IsEmpty());
	EXPECT_EQ(recorder->GetNumberOfSetBits(),0);
	recorder->SetBit(0);
	EXPECT_EQ(recorder->GetNumberOfSetBits(),1);
	EXPECT_FALSE(recorder->IsAllSet());
	recorder->SetBit(1);
	EXPECT_EQ(recorder->GetNumberOfSetBits(),2);
	recorder->SetBit(bit_num-1);
	EXPECT_EQ(recorder->GetNumberOfSetBits(),3);
	recorder->ResetBit(1);
	EXPECT_EQ(recorder->GetNumberOfSetBits(),2);
	
	for (size_t i = 0; i < bit_num; i++) {
		recorder->SetBit(i);
	}
	EXPECT_TRUE(recorder->IsAllSet());
	EXPECT_EQ(recorder->GetNumberOfSetBits(),bit_num);
}

TEST( TestUsingBitRecorder, Test65Bit ) {
	int bit_num = 65;
	UsingBitRecorder *recorder = new UsingBitRecorder(bit_num);
	EXPECT_TRUE(recorder->IsEmpty());
	EXPECT_EQ(recorder->GetNumberOfSetBits(),0);
	recorder->SetBit(0);
	EXPECT_EQ(recorder->GetNumberOfSetBits(),1);
	EXPECT_FALSE(recorder->IsAllSet());
	recorder->SetBit(1);
	EXPECT_FALSE(recorder->IsAllSet());
	recorder->SetBit(bit_num-1);
	EXPECT_EQ(recorder->GetNumberOfSetBits(),3);
	recorder->ResetBit(1);
	EXPECT_EQ(recorder->GetNumberOfSetBits(),2);
	for (size_t i = 0; i < bit_num; i++) {
		recorder->SetBit(i);
	}
	EXPECT_TRUE(recorder->IsAllSet());
	EXPECT_EQ(recorder->GetNumberOfSetBits(),bit_num);
}

TEST( TestUsingBitRecorder, Test128Bit ) {
	int bit_num = 128;
	UsingBitRecorder *recorder = new UsingBitRecorder(bit_num);
	EXPECT_TRUE(recorder->IsEmpty());
	EXPECT_EQ(recorder->GetNumberOfSetBits(),0);
	recorder->SetBit(0);
	EXPECT_EQ(recorder->GetNumberOfSetBits(),1);
	EXPECT_FALSE(recorder->IsAllSet());
	recorder->SetBit(1);
	EXPECT_EQ(recorder->GetNumberOfSetBits(),2);
	recorder->SetBit(bit_num-1);
	EXPECT_EQ(recorder->GetNumberOfSetBits(),3);
	recorder->ResetBit(1);
	EXPECT_EQ(recorder->GetNumberOfSetBits(),2);
	for (size_t i = 0; i < bit_num; i++) {
		recorder->SetBit(i);
	}
	EXPECT_TRUE(recorder->IsAllSet());
	EXPECT_EQ(recorder->GetNumberOfSetBits(),bit_num);
}

TEST( TestUsingBitRecorder, Test1024Bit ) {
	int bit_num = 1024;
	UsingBitRecorder *recorder = new UsingBitRecorder(bit_num);
	EXPECT_TRUE(recorder->IsEmpty());
	EXPECT_EQ(recorder->GetNumberOfSetBits(),0);
	recorder->SetBit(0);
	EXPECT_EQ(recorder->GetNumberOfSetBits(),1);
	EXPECT_FALSE(recorder->IsAllSet());
	recorder->SetBit(1);
	EXPECT_FALSE(recorder->IsAllSet());
	EXPECT_EQ(recorder->GetNumberOfSetBits(),2);
	recorder->SetBit(bit_num-1);
	EXPECT_EQ(recorder->GetNumberOfSetBits(),3);
	recorder->ResetBit(1);
	EXPECT_EQ(recorder->GetNumberOfSetBits(),2);
	for (size_t i = 0; i < bit_num; i++) {
		recorder->SetBit(i);
	}
	EXPECT_TRUE(recorder->IsAllSet());
	EXPECT_EQ(recorder->GetNumberOfSetBits(),bit_num);
}

TEST( TestUsingBitRecorder, Test1025Bit ) {
	int bit_num = 1025;
	UsingBitRecorder *recorder = new UsingBitRecorder(bit_num);
	EXPECT_TRUE(recorder->IsEmpty());
	EXPECT_EQ(recorder->GetNumberOfSetBits(),0);
	recorder->SetBit(0);
	EXPECT_EQ(recorder->GetNumberOfSetBits(),1);
	EXPECT_FALSE(recorder->IsAllSet());
	recorder->SetBit(1);
	EXPECT_FALSE(recorder->IsAllSet());
	EXPECT_EQ(recorder->GetNumberOfSetBits(),2);
	recorder->SetBit(bit_num-1);
	EXPECT_EQ(recorder->GetNumberOfSetBits(),3);
	recorder->ResetBit(1);
	EXPECT_EQ(recorder->GetNumberOfSetBits(),2);

	for (size_t i = 0; i < bit_num; i++) {
		recorder->SetBit(i);
	}
	EXPECT_TRUE(recorder->IsAllSet());
	EXPECT_EQ(recorder->GetNumberOfSetBits(),bit_num);
}

