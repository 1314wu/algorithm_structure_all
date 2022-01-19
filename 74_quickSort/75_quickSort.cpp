#include <stdio.h>
#include <malloc.h>
typedef struct _Range {
	int start, end;
} Range;

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

void quick_sort_1(int arr[], const int len) {
	if (len <= 0)
		return; // 避免len等於負值時引發段錯誤（Segment Fault）
	// r[]模擬列表,p為數量,r[p++]為push,r[--p]為pop且取得元素
//	Range r[len];
	Range* r = (Range*)malloc(sizeof(Range)*len);
	int p = 0;
	r[p++] = new_Range(0, len - 1);
	while (p) {
		Range range = r[--p];
		if (range.start >= range.end)
			continue;
		int mid = arr[(range.start + range.end) / 2]; // 選取中間點為基準點
		int left = range.start, right = range.end;
		do {
			while (arr[left] < mid) ++left;   // 檢測基準點左側是否符合要求
			while (arr[right] > mid) --right; //檢測基準點右側是否符合要求
			if (left <= right) {
				swap(&arr[left], &arr[right]);
				left++;
				right--;               // 移動指針以繼續
			}
		} while (left <= right);
		if (range.start < right) r[p++] = new_Range(range.start, right);
		if (range.end > left) r[p++] = new_Range(left, range.end);
	}
}


void quick_sort_recursive(int arr[], int start, int end) {
	if (start >= end)
		return;
	int mid = arr[end];
	int left = start, right = end - 1;
	while (left < right) {
		while (arr[left] < mid && left < right)
			left++;
		while (arr[right] >= mid && left < right)
			right--;
		swap(&arr[left], &arr[right]);
	}
	if (arr[left] >= arr[end])
		swap(&arr[left], &arr[end]);
	else
		left++;
	if (left)
		quick_sort_recursive(arr, start, left - 1);
	quick_sort_recursive(arr, left + 1, end);
}

void quick_sort_2(int arr[], int len) {
	quick_sort_recursive(arr, 0, len - 1);
}
int main() {
	int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
	int len = (int) sizeof(arr) / sizeof(*arr);
	quick_sort_1(arr, len);
	quick_sort_2(arr, len);
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	return 0;
}