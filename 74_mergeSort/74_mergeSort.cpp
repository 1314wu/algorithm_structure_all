#include <stdio.h>
#include <malloc.h>
#include <string.h>
int min(int x, int y) {
	return x < y ? x : y;
}
void merge(int R[], int T[], int low, int mid, int high) {
	//将两个有序表R[low..mid] 和R[mid..high]归并为有序表 T[low...high]
	int i, j, k;
	i = low; j = mid + 1; k = low;
	while (i <= mid && j <= high) {
		if (R[i] > R[j])
			T[k++] = R[j++];
		else
			T[k++] = R[i++];
	}
	while (i <= mid) //将剩余的R[low..mid]的放入T[]中
		T[k++] = R[i++];	
	while (j <= high) //将剩余的R[mid+1..high]放入T[]中
		T[k++] = R[j++];
	for (int t = low; t <= high; t++)
		R[t] = T[t];	
}
//归并排序 (1)递归实现
void Msort(int R[], int T[], int low, int high) {
	 //将R[low..high]归并排序好后放入T[low..high]中
	//printf("low:%d high:%d\n", low, high);
	if (low == high) {
		//T[low] = R[low];
		return;
	} else{
		int mid;
		mid = (low + high) / 2;
		Msort(R, T, low, mid);
		Msort(R, T, mid + 1, high);
		merge(R, T, low, mid, high);
	}
}
void MergeSort(int R[], int len) {
	int* T = (int*)malloc(len * sizeof(int));
	Msort(R, T, 0, len - 1);
	free(T);
}
void merge_sort_nonrecv(int input[], int len) {
	int* R = input;
	int* out = (int*)malloc(len * sizeof(int));
	int* T = out;
	int step, low, mid, high,start,k;
	for (step = 1; step < len; step += step) {
		for (start = 0; start < len; start += step*2) {
			low = start, mid = min(start + step, len), high = min(start + step * 2, len);
			k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				T[k++] = R[start1] > R[start2] ? R[start2++] : R[start1++];
			while (start1 < end1)
				T[k++] = R[start1++];			
			while (start2 < end2)
				T[k++] = R[start2++];
		}
		int *temp_list = T;
		T = R;
		R = temp_list;
	}
	if ( R != input) {
		int i;
		for (i = 0; i < len; i++) {
			T[i] = R[i];
		}			
		T = R;
	}
	free(T);
}

void output_info(int* arr, int len) {
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main() {
	int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
	int len = (int) sizeof(arr) / sizeof(*arr);
	
	int* input_list = (int*)malloc(sizeof(int) * len);
	memcpy(input_list, arr, sizeof(int) * len);
	merge_sort_nonrecv(input_list, len);
	output_info(input_list, len);
	
	memcpy(input_list, arr, sizeof(int) * len);
	MergeSort(input_list,len);
	output_info(input_list, len);
	
	free(input_list);
	return 0;
}