#include<stdio.h>
#include<stdlib.h>
void sortMatrix(int n,int arr[n][n]){
	int temp[n*n];
	int k=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			temp[k++]=arr[i][j];
		}
	}
	for(int i=0;i<n*n-1;i++){
		for(int j=0;j<n*n-i-1;j++){
			if(temp[j]>temp[j+1]){
				int tempVar=temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=tempVar;
			}
		}
	}
	k=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			arr[i][j]=temp[k++];
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
void searchMatrix(int n,int arr[n][n],int key){
	 int i=0;
	 int j=n-1;
	 int c=0;
	 while(i<n && j>=0){
	 	if(arr[i][j]==key){
	 		printf("\nRow:%d Column:%d\n",i,j);
	 		c++;
	 		break;
	 	}
	 	else if(arr[i][j]>key)
	 	j--;
	 	else
	 	i++;
	 }
	 if(c==0)
	 printf("Element not found");
}
int main(){
	int n;
	printf("\nEnter no. of rows and column:");
	scanf("%d",&n);
	printf("\nEnter %d elements of array:\n",(n*n));
	int arr[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			arr[i][j]=rand()%100;
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	printf("\nSOrted array:\n");
	sortMatrix(n,arr);
	printf("Enter element to be searched:");
	int key;
	scanf("%d",&key);
	searchMatrix(n,arr,key);
}
