#include<stdio.h>
#define MAX 20
float arr[MAX][3];
float profit;

void Knapsack(int n,int size){
	int i,j,k;

	//sorting according to the ratio
	for(i=0;i<n-1;i++) for(j=0;j<n-i-1;j++) for(k=0;k<3;k++) if(arr[j][2]<arr[j+1][2])
	arr[j+1][k] = arr[j][k] + arr[j+1][k] - ( arr[j][k] = arr[j+1][k] );
	
	//calculate total profit
	for(i=0;i<n;i++){
		if(arr[i][0]>size){
			profit+=(size/arr[i][0])*arr[i][1];
			return;
		}
		profit+=arr[i][1];
		size-=arr[i][0];
	}
	
}

 int main(){
 	int n,i,j=0,cap;
 	printf("Enter the nuber of objects = ");
 	scanf("%d",&n);

 	for(i=0;i<n;i++){
 		printf("Enter the %d object's weight = ",i+1);
 		scanf("%f",&arr[i][j++]);
 		printf("Enter the %d object's profit = ",i+1);
 		scanf("%f",&arr[i][j++]);
 		arr[i][j]=arr[i][1]/arr[i][0];
 		j=0;
 	}

 	printf("Enter the capacity of Knapshak = ");
 	scanf("%d",&cap);

 	Knapsack(n,cap);

 	printf("Total Profit = %f",profit);
 }
