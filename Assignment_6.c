#include<stdio.h>
#define MAX 20
int arr[MAX][3];
int seq[MAX],mx;
int penalty,profit;

void job_seq(int n){
	int i,j,k;
	
	//Dcending order sorting according to profit
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			for(k=0;k<3;k++)
				if(arr[j][1]<arr[j+1][1])
					arr[j+1][k]=arr[j][k]+arr[j+1][k]-(arr[j][k]=arr[j+1][k]);
	
	//Calculate maximum deadline
	mx=arr[0][2];
	for(i=1;i<n;i++)
		if(arr[i][2]>mx)
			mx=arr[i][2];
	
	//Calculate profit, penalty and store job sequencing in array
	for(i=0;i<n;i++){
		j=arr[i][2];
		if(seq[j]==0){
			seq[j]=arr[i][0];
			profit+=arr[i][1];
		}
		else penalty+=arr[i][1];
	}
	
}

void print(int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d %d %d\n",arr[i][0],arr[i][1],arr[i][2]);
}

int main(){
	int i,j,n;
	printf("Enter the number of Jobs = ");
	scanf("%d",&n);
	
	//Store the Jobs with profits and penalties
	for(i=0;i<n;i++){
		arr[i][0]=i+1;
		printf("Enter the %dth job profit = ",i+1);
		scanf("%d",&arr[i][1]);
		printf("Enter the %dth job deadline = ",i+1);
		scanf("%d",&arr[i][2]);
		
	}
	
	printf("Given Job:\n");
	print(n);
	
	job_seq(n);
	
	printf("After operation:\n");
	print(n);
	
	//Print all the operarion
	printf("The Job sequence is: ");
	for(i=1;i<=mx;i++){
		if(i==mx) printf("%d",seq[i]);
		else printf("%d -> ",seq[i]);
	}
	printf("\nMaximum deadline = %d\n",mx);
	printf("Profit = %d\n",profit);
	printf("Penalty = %d\n",penalty);
	
}
//Code by jay-neo
