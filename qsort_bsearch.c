#include<stdio.h>
#define size 20

void swap(int *a,int *b){
	*b=*a+*b-(*a=*b);
}

int partition(int arr[],int left,int right){
	int pivot,i,l,idx;
	pivot=arr[right];
	idx=left;
	for(i=left;i<right;i++)
		if(pivot>arr[i])
			swap(&arr[i],&arr[idx++]);
	swap(&arr[idx],&arr[right]);
	return idx;
}
void quick_sort(int arr[],int left,int right){
	if(left>=right)
		return;
	int p=partition(arr,left,right);
	quick_sort(arr,left,p-1);
	quick_sort(arr,p+1,right);
}


void binary_search(int arr[],int left,int right,int key){
	int mid=left+(right-left)/2;
	//Base Case:
	if(left>right){
		printf("The searching value not found in given array.\n");
		return;
	}
	if(key==arr[mid]){
		printf("The searching value found at %d position.\n",mid+1);
		return;
	}
	//Recursive Case:
	if(key<arr[mid]) binary_search(arr,left,mid-1,key);
	else if(key>arr[mid]) binary_search(arr,mid+1,right,key);
}


int main(){
	int i,n,key;
	int arr[size];

	printf("Enter the size of array = ");
	scanf("%d",&n);
	printf("Enter the %d element of array:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	printf("Enter the searching value = ");
	scanf("%d",&key);

	quick_sort(arr,0,n-1);

	printf("\nAfter the sorting\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");

	binary_search(arr,0,n-1,key);



}

//code by jay-neo
