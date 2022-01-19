#include <stdio.h>
void insertion_sort(int arr[], int len) 
{
	int i, j, key;
	for (i = 1; i < len; i++) 
	{
		key = arr[i];
		j = i - 1;
		while ((j >= 0) && (arr[j] > key)) // 小的放前边
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
int main() {
	int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
	int len = (int) sizeof(arr) / sizeof(*arr);
	insertion_sort(arr, len);
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	return 0;
}