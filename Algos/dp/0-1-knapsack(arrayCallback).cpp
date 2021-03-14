void knaparr(int wt[], int n, int w, vi p)
{
  if(n==0) return;
  int next=0;
  for(int i =n;i>=0;i--)
  {
    if(!K[i].count(w)) continue;
    p.push_back(i+1);
    next=i;
    break;
  }
  knaparr(wt,next,w-wt[next],p);
}
