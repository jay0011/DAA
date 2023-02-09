#include<stdio.h>
#include <limits.h>
#define size 20

int mx=INT_MIN;
int mn=INT_MAX;

//	এটি একটি ভুল নিয়ম
//	সঠিক নিয়ম coming soon

void max_min(int arr[],int left,int right){
	int mid;
	if(left==right){
		if(mx<arr[left]) mx=arr[left];
		if(mn>arr[left]) mn=arr[left];
	}
	else if(left==right-1){
		if(arr[left]<arr[right]){
			if(mx<arr[right]) mx=arr[right];
			if(mn>arr[left]) mn=arr[left];
		}
		else{
			if(mx<arr[left]) mx=arr[left];
			if(mn>arr[right]) mn=arr[right];
		}
	}
	else{
		mid=left+(right-left)/2;
		max_min(arr,left,mid);
		max_min(arr,mid+1,right);
	}
}

int main(){
	int i,n;
	int arr[size];

	printf("Enter the size of array = ");
	scanf("%d",&n);
	printf("Enter the %d element of array:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	max_min(arr,0,n-1);

	printf("Maximum Element = %d\n",mx);
	printf("Minimum Element = %d",mn);

}

//code by jay-neo
