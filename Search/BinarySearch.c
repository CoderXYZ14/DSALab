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
int binarySearch(int arr[],int n,int x){
	int low=0,high=n-1;
	if(arr[0]<=x && arr[n-1]>=x){
	    while(low<=high){
	        int mid=(low+high)/2;
	        if(arr[mid]==x)
	        return mid;
	        else if(arr[mid]>x)
	        high=mid-1;
	        else
	        low=mid+1;
	    }
	}
	else
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
    int position=binarySearch(arr,n,x);
    if(position==-1)
    printf("Element not found");
    else
    printf("%d found at position %d ",x,(position+1));
}
