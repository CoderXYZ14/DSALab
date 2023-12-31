#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void randomArray(int arr[],int n){
    for(int i=0;i<n;i++){
       arr[i]=rand()%100;
    }
}
void insertionSort(int arr[],int n){
	for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    printf("Enter the length of array:");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Unsorted array:");
    randomArray(arr,n);
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
    printf("\nSorted array:");
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
    return 0;
}
