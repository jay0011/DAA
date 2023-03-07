#include <stdio.h>
#include <limits.h>
#define MAX 20

int mcm_GPT(int p[], int n) {
	int i,j,k,L,q;
    int m[n][n];

    for(i=1;i<n;i++) m[i][i] = 0;

    for(L=2;L<n;L++){
        for(i=1;i<n-L+1;i++){
            j=i+L-1;
            m[i][j]=INT_MAX;

            for(k=i;k<=j-1;k++){
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j]){
                    m[i][j]=q;
                }
            }
        }
    }

    return m[1][n-1];
}

int mcmT(int arr[],int n){
	int i,j,k,mn;
    int dp[n][n];

    for(i=1;i<n;++i) dp[i][i]=0;
    for(i=n-1;i>=1;--i){
    	for(j=i+1;j<n;++j){
    		mn=INT_MAX;
    		for(k=i;k<j;++k){
    			mn=arr[i-1]*arr[j]*arr[k]+dp[i][k]+dp[k+1][j];
    			if(mn<dp[i][j]) dp[i][j]=mn;
    		}
    	}
    }

    return dp[1][n-1];
}


int main() {
    int i,n,arr[MAX];

    printf("Enter the size of array = ");
    scanf("%d",&n);
    printf("Enter the %d array elements:\n",n);
    for(i=0;i<n;++i) scanf("%d",&arr[i]);

    printf("Minimum number of multiplications is %d", mcmT(arr, n));
	//printf("\nMinimum number of multiplications is %d", mcm_GPT(arr, n));
    return 0;
}
