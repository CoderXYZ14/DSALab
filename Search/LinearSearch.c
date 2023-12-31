#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void randomSortedArray(int arr[],int n){
    arr[0]=rand()%10;
    for(int i=1;i<n;){
        int t=rand()%(20*i);
       if(t>arr[i-1]){
           arr[i]=t;
           i++;
       }
    }
}
int linearSearch(int arr[],int n,int x){
	for(int i=0;i<n;i++){
	    if(arr[i]==x)
	    return i;
	}
	return -1;
}
int main(){
    printf("Enter the length of array:");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Sorted random array:");
    randomSortedArray(arr,n);
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
    printf("\nEnter the no. to be searched:");
    int x;
    scanf("%d",&x);
    int position=linearSearch(arr,n,x);
    if(position==-1)
    printf("Element not found");
    else
    printf("%d found at position %d ",x,(position+1));
}
