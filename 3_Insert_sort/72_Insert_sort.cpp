#include <stdio.h>
void output_info(int const* input_list, int len) {
	int i;
	for (i = 0; i < len; i++) {
		printf("%d\t", input_list[i]);
	}
	printf("\n");
}
void insertion_sort(int arr[], int len) 
{
	int i, j, key;
	for (i = 1; i < len; i++) 
	{
		key = arr[i];
		for (j = i - 1; arr[j] > key && j >= 0; j--) {
			arr[j+1] = arr[j];
		}
		arr[j+1] = key;
		output_info(arr, len);
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