#include<iostream>
using namespace std;

//求最大位数
int max_bit(int arr[], int len)
{
	int max = arr[0];
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	int bit = 0;
	while (max > 0)
	{
		bit++;
		max /= 10;
	}
	return bit;
}

void radix_sort(int arr[], int len)
{
	int* count = new int[10];	//计数器
	int* temp = new int[len];	//临时数组
	int bit = max_bit(arr, len);	//得到数组的最大位数
	int radix = 1;
	for (int i = 0; i < bit; i++)	//基数排序：有多少位执行多少次就ok了
	{
		//每次排序之前都要清空
		memset(count, 0, 10 * sizeof(int));

		//对各个基数总数目进行计数
		for (int j = 0; j < len; j++)
			count[(arr[j] / radix) % 10]++;

		for (int j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j];// <=基数j的元素个数					
		for (int j = len - 1; j >= 0; j--)
		{
			int k = (arr[j] / radix) % 10;  // 求arr[j]的基数k
			temp[count[k] - 1] = arr[j];    // 按照上一步求出来的基数，放入temp的对应区间段内
			count[k]--; //基数k的元素数目减一
		}

		//把临时数组的元素赋值到目标数组
		for (int j = 0; j < len; j++) {
			arr[j] = temp[j];
			printf("%d ", temp[j]);
		}
		printf("\n");
			

		radix *= 10;
	}
	delete[] temp;
	delete[] count;
}


int main() {

	int a[] = { 2,9,0,1,100,62,54,21,18,32,73,92,542 };
	radix_sort(a, sizeof(a) / sizeof(int));
	for (auto it : a)
	{
		cout << it << " ";

	}
	cout << endl;
	system("pause");
	return 0;
}