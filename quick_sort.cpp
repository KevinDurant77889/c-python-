#include<iostream>
#include <stdlib.h>
#include <time.h>  

#define num 1000000
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *arr, int front, int end){
    int pivot = arr[end];
    int i = front -1;
    for (int j = front; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return i;
}
void quick_sort(int *arr, int front, int end){
    if (front < end) {
        int pivot = partition(arr, front, end);
        quick_sort(arr, front, pivot - 1);
        quick_sort(arr, pivot + 1, end);
    }
}



int main(){
	double tStart = clock();
	srand(time(NULL));
	int arr[num];
	
	for(int i = 0; i < num; ++i){
			arr[i] = rand()%100+1;
	}
	quick_sort(arr, 0, num-1);
	double tEnd = clock();
	cout << (tEnd - tStart);
}
