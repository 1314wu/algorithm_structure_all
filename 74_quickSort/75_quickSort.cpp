#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include <stack>
typedef struct _Range {
	int start, end;
} Range;
void output_info(int const* input_list, int len);
int partition(int arr[], int low, int high);
Range new_Range(int s, int e) {
	Range r;
	r.start = s;
	r.end = e;
	return r;
}

void swap(int *x, int *y) {
	int t = *x;
	*x = *y;
	*y = t;
}

//非递归实现快速排序
void quick_sort_1(int arr[], const int len) {
	if (len <= 0)
		return;	
	for (int i = 0; i < len; i++) {
		printf("%d\t", i);
	}
	printf("\n");
	std::stack<Range> r;
	
	int p = 0;
	r.push(new_Range(0, len - 1));
	
	while (!r.empty()) {
		Range range = r.top();
		r.pop();
		if (range.start >= range.end)
			continue;
		if (range.start < range.end) {
			int pivot = partition(arr, range.start, range.end);
			output_info(arr, len);
			if (pivot > range.start)
				r.push( new_Range(range.start, pivot - 1));
			if (pivot < range.end)
				r.push( new_Range(pivot + 1, range.end));
		}
	}
}

int partition(int arr[], int low, int high) {
	int key_value = arr[low];
	while (low < high) {
		while (low < high && arr[high] >= key_value)
			high--;
		if (low < high)
			arr[low] = arr[high];
		while (low < high && arr[low] < key_value)
			low++;
		if (low <high)
			arr[high] = arr[low];
	}
	arr[low] = key_value;
	return low;
}
void qsort_recursive(int arr[], int low, int high) {
	int pivotLoc;
	if (low < high) {
		pivotLoc = partition(arr, low, high);
		qsort_recursive(arr, low, pivotLoc - 1);
		qsort_recursive(arr, pivotLoc + 1, high);
	}
}
void output_info(int const* input_list, int len) {
	int i;
	for (i = 0; i < len; i++) {
		printf("%d\t", input_list[i]);
	}
	printf("\n");
}
int main() {
//	int arr[] = { 22, 34, 3, 32, 82, 55, 89,45, 50, 37, 5, 64, 35, 9, 70 };
	int arr[] = { 4,5,4 };
	//int arr[] = { 3,2,3 };
	int len = (int) sizeof(arr) / sizeof(*arr);
	int* input_list = new int[len];
	memcpy(input_list, arr, sizeof(int) * len);
	qsort_recursive(input_list, 0, len - 1);
	output_info(input_list, len);
	
	memcpy(input_list, arr, sizeof(int) * len);
	quick_sort_1(input_list, len);
	output_info(input_list, len);
	//quick_sort_2(arr, len);

	return 0;
}