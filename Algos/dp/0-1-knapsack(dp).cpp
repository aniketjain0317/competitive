// Self-written
//

int dp[N][N]={};
// dp[n+1][w+1]={};


void knapsack(int n, int w, int wt[], int val[])
{
  frr(i,1,n)
  {
    int wi = wt[i-1];
    int vali = val[i-1];
    frr(j,1,w)
    {
      // a : object i is not selected
      // b : object i is selected, and added to the max val of j-wt[i]
      int a=0,b=0;
      a=dp[i-1][j];
      if(j>=wi) b = dp[i-1][j-wi]+vali;
      dp[i][j]=max(a,b);
    }
  }
}
