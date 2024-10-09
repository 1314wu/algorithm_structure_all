#include <stdio.h>
void output_info(int const* input_list, int len) {
	int i;
	for (i = 0; i < len; i++) {
		printf("%d\t", input_list[i]);
	}
	printf("\n");
}

void half_insertion_sort(int arr[], int len) {
	int i, j, key;
	int mid, low, high;
	for (int t = 0; t < len; t++)
		printf("%d\t", t);
	printf("\n");
	output_info(arr, len);
	for (i = 1; i < len; i++) {
		low = 0;
		high = i;
		int temp = arr[i];
		while (low <= high) {
			mid = (low + high) / 2;
			if (arr[mid] > temp)
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (j = i - 1; j >= high+1; j--)  // 终止条件需要是 j>=high+1
			arr[j + 1] = arr[j];
		
		arr[j+1] = temp;
		output_info(arr, len);
	}

}
int main() {
	int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
	int len = (int)sizeof(arr) / sizeof(*arr);
	half_insertion_sort(arr, len);
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	return 0;
}