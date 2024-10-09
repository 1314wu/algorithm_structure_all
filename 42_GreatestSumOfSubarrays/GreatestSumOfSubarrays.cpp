/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 
// 
//==================================================================

// 42：连续子数组的最大和
// 题目：输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整
// 数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。

#include <cstdio>
#include <iostream>
#include <algorithm>
bool g_InvalidInput = false;

//int FindGreateSumOfSubArray_2(int* pData, int nLength, int i) {
//    if ((pData == nullptr) || (nLength <= 0))
//    {
//        g_InvalidInput = true;
//        return 0;
//    }
//    for (int j = i; j >=0 ; j--) {
//        if (j == 0) {
//            return pData[0];
//        }
//        int prev = FindGreateSumOfSubArray_2(pData, nLength, j - 1);
//        if (prev < 0) {
//            return std::max(prev,pData[j]);
//        }
//        int sum = prev + pData[j];
//        if (j == nLength - 1)
//            return pData[j] > 0 ? sum : prev;        
//        return std::max(sum, pData[j]);
//    }
//    
//}
int FindGreateSumOfSubArray_2(int* pData, int nLength, int i) {
    if ((pData == nullptr) || (nLength <= 0))
    {
        g_InvalidInput = true;
        return 0;
    }
    if (i == 0) {
        return pData[0];
    }
    int prev = FindGreateSumOfSubArray_2(pData, nLength, i - 1);
    if (prev < 0) {
        return std::max(pData[i],prev);
    }
    if (pData[i] < 0 && i == nLength - 1)
        return prev;
    else
        return std::max(prev + pData[i], pData[i]);

}
int FindGreatestSumOfSubArray(int *pData, int nLength)
{
    if((pData == nullptr) || (nLength <= 0))
    {
        g_InvalidInput = true;
        return 0;
    }

    g_InvalidInput = false;

    int nCurSum = 0;
    int nGreatestSum = 0x80000000;
    for(int i = 0; i < nLength; ++i)
    {
        if(nCurSum <= 0)
            nCurSum = pData[i];
        else
            nCurSum += pData[i];

        if(nCurSum > nGreatestSum)
            nGreatestSum = nCurSum;
    }

    return nGreatestSum;
} 

// ====================测试代码====================
void Test(char* testName, int* pData, int nLength, int expected, bool expectedFlag)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    int result = FindGreatestSumOfSubArray(pData, nLength);
    if(result == expected && expectedFlag == g_InvalidInput)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    int result2 = FindGreateSumOfSubArray_2(pData, nLength, nLength-1);
    if (result2 == expected && expectedFlag == g_InvalidInput)
        printf("method2 Passed.\n");
    else
        printf("method2 Failed.\n");

}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
    int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
    Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
}

// 所有数字都是负数
// -2, -8, -1, -5, -9
void Test2()
{
    int data[] = {-2, -8, -1, -5, -9};
    Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// 所有数字都是正数
// 2, 8, 1, 5, 9
void Test3()
{
    int data[] = {2, 8, 1, 5, 9};
    Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

// 无效输入
void Test4()
{
    Test("Test4", nullptr, 0, 0, true);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}

