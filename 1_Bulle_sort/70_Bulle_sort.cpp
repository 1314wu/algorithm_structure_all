// bullesort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// 输出方式：递增
int bubble_inc_sort(int const* array_list, int length, int* output_list) {
    if (array_list == nullptr || length == 0) {
        return 0;
    }

    int flag = true;
    for (int i = 0; i < length && flag; i++) {
        for (int j = 1; j < length - i; j++) {
            flag = false;
            if (output_list[j - 1] > output_list[j]) {
                flag = true;
                swap(&output_list[j - 1], &output_list[j]);
            }
        }
    }

    return 1;
}

// 输出方式：递减
int bulle_dec_sort(int const* array_list, int length, int* output_list) {
    int flag = 1;
    for (int i = 0; i < length; i++) {
        for (int j = 1; j < length - i; j++) {
            if (output_list[j - 1] < output_list[j]) {
                flag = true;
                int temp = output_list[j - 1];
                output_list[j - 1] = output_list[j];
                output_list[j] = temp;
            }
        }
    }
    return 1;

}
void output_result(int* input_array, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << input_array[i] << " ";
    }
    std::cout << std::endl;
}
int main()
{
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int lenght = sizeof(arr) / sizeof(int);
    int* output_list = new int[lenght];

    memcpy(output_list, arr, sizeof(int) * lenght);
    bubble_inc_sort(arr, lenght, output_list);
    output_result(output_list, lenght);

    memset(output_list, 0, sizeof(int) * lenght);
    memcpy(output_list, arr, sizeof(int) * lenght);
    bulle_dec_sort(arr, lenght, output_list);
    output_result(output_list, lenght);


    delete[] output_list;

}


