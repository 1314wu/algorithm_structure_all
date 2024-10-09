//[wzq补充]
// 42_3：从数组中找出最长的递增的子序列长度
// 题目：输入一个整型数组，数组里有正数也有负数。
//  从数组中找出最长的递增的子序列长度。要求时间复杂度为O(n)。
//  如输入数组[1,5,2,4,3] ，最长递增子序列是[1,2,3]

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
//耗时较大，
int FindLongSubSeq_incOrder(int* pData, int nLength, int i, int* len);
int FindLongSubSeq_incOrder_output(int* pData, int nLength, int i) {
    int* len = new int[nLength] {0};
    int max_len =  FindLongSubSeq_incOrder(pData, nLength, i, len);
    delete [] len;
    return max_len;
}
int FindLongSubSeq_incOrder(int* pData, int nLength, int i, int* len) {
    if ((pData == nullptr) || (nLength <= 0))
    {
        g_InvalidInput = true;
        return 1;
    }
    if (len[i] != 0) {
        return len[i];
    }
    if (i == nLength - 1) {
        return 1;
    }
    int max_len = 1;
    for (int j = i+1; j < nLength; j++) {
        if (pData[j] > pData[i])
            max_len =  std::max(max_len, FindLongSubSeq_incOrder(pData, nLength, j, len) + 1);
    }
    len[i] = max_len;
    return max_len;

}

int FindLongSubSeq_incOrder2(int* pData, int nLength) {
    int* len = new int[nLength];
    //memset(len, 1, nLength);
    for (int i = 0; i < nLength; i++)
        len[i] = 1;
    int max_len = 1;

    for (int j = nLength - 1; j >= 0; j--) {
        for (int k = j + 1; k < nLength; k++) {
            if (pData[k] > pData[j]) {
                len[j] = std::max(len[j], len[k] + 1);
                
            }
        }
    }
    for (int i = 0; i < nLength; i++) {
        max_len = len[i] > max_len ? len[i] : max_len;
    }
    return  max_len;

}

// ====================测试代码====================
void Test(const char* testName, int* pData, int nLength, int expected, bool expectedFlag)
{
    if (testName != nullptr)
        printf("%s begins: \n", testName);

    int result = FindLongSubSeq_incOrder2(pData, nLength);
    if (result == expected && expectedFlag == g_InvalidInput)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    int result2 = FindLongSubSeq_incOrder_output(pData, nLength, 0);
    if (result2 == expected && expectedFlag == g_InvalidInput)
        printf("method2 Passed.\n");
    else
        printf("method2 Failed.\n");


}

//1, 5,2,4,3
void Test1()
{
    int data[] = { 1, 5,2,4,3 };
    Test("Test1", data, sizeof(data) / sizeof(int), 3, false);
}


int main(int argc, char* argv[])
{
    Test1();


    return 0;
}

