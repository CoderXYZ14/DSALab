#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void randomArray(int arr[],int n){
    for(int i=0;i<n;i++){
       arr[i]=rand()%100;
    }
}
void bubbleSort(int arr[],int n){
	bool check=false;
	for(int i=0;i<n-1;i++){
	    for(int j=0;j<n-i-1;j++){
	        if(arr[j]>arr[j+1]){
	            int temp=arr[j];
	            arr[j]=arr[j+1];
	            arr[j+1]=temp;
	            check=true;
	        }
	    }
	    if(check==false)
	    break;
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
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
    return 0;
}
