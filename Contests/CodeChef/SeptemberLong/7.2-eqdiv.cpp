// Problem
// AC LMAOOOOOO

#include <bits/stdc++.h>
using namespace std;



#if defined(_USE_MATH_DEFINES) && !defined(_MATH_DEFINES_DEFINED)
#define _MATH_DEFINES_DEFINED

#define M_E        2.71828182845904523536
#define M_LOG2E    1.44269504088896340736
#define M_LOG10E   0.434294481903251827651
#define M_LN2      0.693147180559945309417
#define M_LN10     2.30258509299404568402
#define M_PI       3.14159265358979323846
#define M_PI_2     1.57079632679489661923
#define M_PI_4     0.785398163397448309616
#define M_1_PI     0.318309886183790671538
#define M_2_PI     0.636619772367581343076
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2    1.41421356237309504880
#define M_SQRT1_2  0.707106781186547524401

#endif  /* _USE_MATH_DEFINES */


#define pb push_back
#define mp make_pair
#define lb lower_bound
#define bs binary_search
#define fs first
#define sn second
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define N 1e5
#define INF 1e9+5

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

int ng=0;
string strs[40]={};
int nii=0;
string addn[5]={"","1001","01101001","1001011001101001","01101001100101101001011001101001"};
map <int,int> m1;
// A utility function that returns
// maximum of two integers
string display(vi p)
{
  string s="";
  int ans[nii]={};
  for(auto x: p) ans[x-1]=1;
  for(auto x: ans)
  {
    if(x) s+='1';
    else s+='0';
  }
  return s;
  // cout << endl;
}
int max(int a, int b)
{
	return (a > b) ? a : b;
}
int K[35][(int)1e6]={};
// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;

	// Build table K[][] in bottom up manner
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(
					val[i - 1] + K[i - 1][w - wt[i - 1]],
					K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	return K[n][W];
}

string knaparr(int wt[], int n, int w, vi p)
{
  string s;
  // vshow1d(p);
  if(n==0)
  {
    // for(int i=0;i<p.size();i++) cout << p[i] << endl;
    s=display(p);
    return s;
  }
  // else if(!K[n][w]) return 0;
  int next=0;
  for(int i =n;i>=0;i--)
  {
    if(K[n][w]==K[i][w]) continue;
    p.push_back(i+1);
    next=i;
    break;
  }
  s=knaparr(wt,next,w-wt[next],p);
  return s;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("input.txt","r",stdin);
  // freopen("myans.txt","w",stdout);
  int k; cin >> k;
  int md = 1<<(k+1);
  // cnl("MD: "<<md);
  if(k<4)
  {
    ng=31;
    int arr[ng]={};
    int st[ng+1]={};
    frr(i,1,ng)
    {
      int j = 1;
      fr(rndv,0,k) j*=i;
      arr[i-1]=j;
      st[i]=st[i-1]+j;
    }
    int st2 = st[ng]/2;
    knapSack(st2,arr,arr,ng);
    frr(i,1,ng)
    {
      nii=i;
      int sum = st[i]/2;
      vi p;
      knaparr(arr,i,sum,p);
      int val = K[i][sum];
    }
    test(t)
    {
      int n; cin >> n;
      vi p;
      if(n<32)
      {
        nii=n;
        int sum = st[n]/2;
        int val = st[n] - 2 * K[n][sum];
        cnl(val);
        cnl(knaparr(arr,n,sum,p));
      }
      else
      {
        int div = n/md;
        int r = n%md;
        int val1 = st[r] - 2 * K[r][st[r]/2];
        if(val1<2)
        {
          nii=r;
          string s =  knaparr(arr,r,st[r]/2,p);
          fr(ano,0,div) s+=addn[k];
          cnl(val1);
          cnl(s);
        }
        else
        {
          int r2 = r+md;
          nii=r2;
          int val2 = st[r2] - 2*K[r2][st[r2]/2];
          string s = knaparr(arr,r2,st[r2]/2,p);
          fr(ano,0,div-1) s+=addn[k];
          cnl(val2);
          cnl(s);
        }
      }
    }
  }
  else
  {
    string ans0[40]={"","0","10","110","1110","11110","111110","1111110","11010001","111110001",
    "1010110110","11111010110","110010101001","1101001010110","11111110000101","100001110101001",
    "0000111000001110","10000111111101010","111111001011110001","1000010010110111100",
    "00001010110111011100","111111111011011011100","0101001111011111110100","00001000100110111101100",
    "000010011110110111110100","1000110101011101111111000","11101011111011101111001010",
    "001111000000011110111111000","0001011111000101111011111000","11101111111011001110111010001",
    "100010010001010111111111011000","1101100001110111011111111101000",
    "00010000010110101111111111110000","110101011100010111011111111110000",
    "1010101110111111111011101111101000","01000111001011010111111101111110000",
    "100101010100011101111111111011110000","1111111010111011111110111111111000100",
    "10010100100101011111110111111101110000","000000100100010111110111111111111010000"};
    string ans1[22]={"","","","","","","","","000101101110110111110100",
    "0000001011000101111110100",    "","110001000011101111011111000",
    "0011010001000011111011111000",    "","000101011111011101111111011000",
    "0100001111101101111101110111000","","","1111101011101111101010101011111000",
    "","","1011111111101010101011101110111100100"};
    int dp0[40]={0,1,15,64,158,271,317,126,34,253,13,92,30,47,
      31,2,0,1,13,0,0,9,1,0,0,1,5,0,0,5,1,0,0,1,1,0,0,1,1,0};
    test(t)
    {
      int n; cin >> n;
      if(n<40)
      {
        cnl(dp0[n]);
        cnl(ans0[n]);
        continue;
      }
      int div = n/32;
      int r=n%32;
      if(dp0[r]<2)
      {
        cnl(dp0[r]);
        string s = ans0[r];
        fr(ano,0,div) s+=addn[4];
        cnl(s);
        continue;
      }
      if(r<8)
      {
        int r2=r+32;
        cnl(dp0[r2]);
        string s = ans0[r2];
        fr(ano,0,div-1) s+=addn[4];
        cnl(s);
        continue;
      }
      if(r<22 && ans1[r]!="")
      {
        if(r%4==1 || r%4==2) cnl(1);
        else cnl(0);
        string s = ans1[r];
        s+=addn[3];
        fr(ano,0,div-1) s+=addn[4];
        cnl(s);
        continue;
      }
      if(r==10)
      {
        cnl(1);
        string s = "1110101110101011111011110010101010";
        s+=addn[2];
        fr(ano,0,div-1) s+=addn[4];
        cnl(s);
        continue;
      }
      if(r==13)
      {
        cnl(1);
        string s = "1011101010101010101110111010101111000";
        s+=addn[2];
        fr(ano,0,div-1) s+=addn[4];
        cnl(s);
        continue;
      }
      if(r==26)
      {
        cnl(1);
        string s = "1111111111111111110011101010101010";
        s+=addn[2];
        s+=addn[3];
        fr(ano,0,div-1) s+=addn[4];
        cnl(s);
        continue;
      }
      if(r==29)
      {
        cnl(1);
        string s = "0010111010111011111111111110101010100";
        s+=addn[2];
        s+=addn[3];
        fr(ano,0,div-1) s+=addn[4];
        cnl(s);
        continue;
      }
      else cnl("ERROR");
    }
  }
}
