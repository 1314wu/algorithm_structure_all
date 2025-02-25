#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}
void min_heapify(int arr[], int start, int end) {
	int dad = start;
	int son = dad * 2 + 1;
	for (son = dad * 2 + 1; son <= end; son = son * 2 + 1) {
		if (son + 1 <= end && arr[son] > arr[son + 1]) {
			son++;
		}
		if (arr[dad] < arr[son]) {
			return;
		}
		else {
			//子节点比父节点小
			swap(&arr[dad], &arr[son]);
			dad = son;
		}
	}
}
void heap_sort_min(int arr[], int len) {
	int id;
	for (id = len / 2 - 1; id >= 0; id--) {
		min_heapify(arr, id, len-1);
	}
	for (id = len - 1; id >= 0; id--) {
		swap(&arr[0], &arr[id]);
		min_heapify(arr, 0, id - 1);
	}
	printf("Min Order: ");
	for (id = 0; id < len; id++) {
		printf("%d ", arr[id]);
	}
	printf("\n");
}
void max_heapify(int arr[], int start, int end) {

	int dad = start;
	int son = dad * 2 + 1;
	
	for (son = dad * 2 + 1; son <= end; son = son * 2 +1) {
		if (son + 1 <= end && arr[son] < arr[son + 1])
			son++;
		if (arr[dad] > arr[son])
			return;
		else {
			// 子结点值比父结点值大，进行调整
			swap(&arr[dad], &arr[son]);
			dad = son; //交换值后，再判断子结点的值与其下层子结点大小
		}
	}

	//for (int i = start; i < end; i++)
	//	printf("%d ", arr[i]);
	//printf("\n");

}
void output_info(int arr[], int len) {
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void heap_sort(int arr[], int len) {
	int i;
	// 建立堆，非叶子结点之前的都是未调整堆，叶子结点都是堆
	for (i = len / 2 - 1; i >= 0; i--)
		max_heapify(arr, i, len - 1);
	// 上述步骤后，已经建立了一个大根堆，堆顶的元素是所有中的最大值

	
	// 先将堆顶[0]最大值放入最后。再用最后一个节点调整堆，使调整后的堆是大根堆
	for (i = len - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]);
		max_heapify(arr, 0, i - 1);
		printf("%d\n", i);
		output_info(arr, len);
	}
}

int main() {
	//int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
	int arr[] = { 49,38,65,97,76,13,27,49 };
	//int arr[] = { 2,1 };
	int len = (int) sizeof(arr) / sizeof(*arr);
	heap_sort(arr, len);
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	int arr2[] = { 49,38,65,97,76,13,27,49 };
	heap_sort_min(arr2, len);
	
	for (i = 0; i < len; i++)
		printf("%d ", arr2[i]);
	printf("\n");
	return 0;
}