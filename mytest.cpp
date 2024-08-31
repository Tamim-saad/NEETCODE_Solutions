#include<bits/stdc++.h>
using namespace std;


bool SubsetSumCheck(vector<int>arr, int max_sum)
{
    int i,j,n=arr.size();
    int dp[n+1][max_sum+1];

    //base case
    for( i = 0; i <=n; i++) dp[i][0]=0;
    for( i = 0; i <=max_sum; i++) dp[0][i]=0;


    for( i = 1; i <=n; i++)
    {
        for( j = 1; j <=max_sum; j++)
        {
            int index=j-arr[i-1];     //check if index is positive or not
            int include=dp[i-1][j-arr[i-1]]+arr[i-1];
            int exclude=dp[i-1][j];

            if(index>=0&&include>exclude)
                dp[i][j]=include;    //include condition
            else
                dp[i][j]=exclude;    //exclude condition
        }
    }

    return dp[n][max_sum]==max_sum;  //check given max_sum is possible or not
}
