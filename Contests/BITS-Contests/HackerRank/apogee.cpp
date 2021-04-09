// Problem
//

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sn second
#define cnl(x) cout << x << endl
#define read(x) cin >> x;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define test(t) int t; cin << t; while(t--)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define N 100000000

typedef long long int ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

int n,m;
int ans=0;
vi pt(5000,0);
multiset<int> assoc[5000];
void fn(int,vi);
int main()
{
  cin >> n >> m;
  int p[n]; cinp(n,p);
  int as[n]; cinp(n,as);
  ainp(d,l);
  fr(i,0,n) assoc[as[i]-1].insert(p[i]);
  fr(i,0,d)
  {
    int t = l[i]-1;
    int las = as[t]-1;
    auto it = assoc[las].find(p[t]);
    assoc[las].erase(it);
    vi pa;
    pa.assign(5000,0);
    ans=0;
    fn(0,pa);
    cnl(ans);
  }
}
void fn(int k, vi pa)
{
  if(k==m)
  {
    if(pa==pt) return;
    fr (i,1,5000) if(!pa[i]) {ans = max(ans,i); return;}
  }
  if(assoc[k].empty()) fn(k+1,pa);
  for(auto x: assoc[k])
  {
    auto pan = pa;
    pan[x]=1;
    fn(k+1,pan);
  }
}
