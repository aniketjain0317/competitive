// Problem
//

#include <bits/stdc++.h>
using namespace std;




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


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("input.txt","r",stdin);
  // freopen("input.txt","w",stdout);
  int k; cin >> k;
  test(t)
  {
    int n; cin >> n;
    if(k==1)
    {
      if(n%4==0)
      {
        cnl(0);
        fr(i,0,n/4)
        {
          cout << "1001";
        }
        cout << endl;
      }
      if(n%4==3)
      {
        cnl(0);
        cout << "110";
        fr(i,0,n/4)
        {
          cout << "1001";
        }
        cout << endl;
      }
      if(n%4==1)
      {
        cnl(1);
        cout << "1";
        fr(i,0,n/4)
        {
          cout << "1001";
        }
        cout << endl;
      }
      if(n%4==2)
      {
        cnl(1);
        cout << "10";
        fr(i,0,n/4)
        {
          cout << "1001";
        }
        cout << endl;
      }
    }
    if(k==2)
    {
      if(n%8==0)
      {
        cnl(0);
        fr(i,0,n/8) cout << "10010110";
        cout << endl;
      }
      if(n%8==1)
      {
        cnl(1);
        cout << "1";
        fr(i,0,n/8) cout << "10010110";
        cout << endl;
      }
      if(n%8==2)
      {
        if(n>8)
        {
          cnl(1);
          cout << "0100100101";
          fr(i,0,n/8-1) cout << "10010110";
          cout << endl;
        }
        else
        {
          cnl(3);
          cout << "10" << endl;
        }
      }
      if(n%8==3)
      {
        if(n>8)
        {
          cnl(0);
          cout << "01000111010";
          fr(i,0,n/8-1) cout << "10010110";
          cout << endl;
        }
        else
        {
          cnl(4);
          cout << "110" << endl;
        }
      }
      if(n%8==4)
      {
        if(n>8)
        {
          cnl(0);
          cout << "000000001101";
          fr(i,0,n/8-1) cout << "10010110";
          cout << endl;
        }
        else
        {
          cnl(2);
          cout << "1110" << endl;
        }
      }
      if(n%8==5)
      {
        if(n>8)
        {
          cnl(1);
          cout << "0001000010011";
          fr(i,0,n/8-1) cout << "10010110";
          cout << endl;
        }
        else
        {
          cnl(3);
          cout << "10110" << endl;
        }
      }
      if(n%8==6)
      {
        cnl(1);
        cout << "110110";
        fr(i,0,n/8) cout << "10010110";
        cout << endl;
      }
      if(n%8==7)
      {
        cnl(0);
        cout << "1101001";
        fr(i,0,n/8) cout << "10010110";
        cout << endl;
      }
    }
    if(k==3)
    {
      if(n%16==0)
      {
        cnl(0);
        fr(i,0,n/16) cout << "1001011001101001";
        cout << endl;
      }
      if(n%16==1)
      {
        cnl(1);
        cout << "1";
        fr(i,0,n/16) cout << "1001011001101001";
        cout << endl;
      }
      if(n%16==2)
      {
        if(n>16)
        {
          cnl(1);
          // 18 16 13 11 9 7 4 3 1
          cout << "101100101010100101";
          fr(i,0,n/16-1) cout << "1001011001101001";
          cout << endl;
        }
        else
        {
          cnl(7);
          cout << "10" << endl;
        }
      }
      if(n%16==3)
      {
        if(n>16)
        {
          cnl(0);
          cout << "0011001001011000011";
          fr(i,0,n/16-1) cout << "1001011001101001";
          cout << endl;
        }
        else
        {
          cnl(18);
          cout << "110" << endl;
        }
      }
      if(n%16==4)
      {
        if(n>16)
        {
          cnl(0);
          cout << "10100000001000000111";
          fr(i,0,n/16-1) cout << "1001011001101001";
          cout << endl;
        }
        else
        {
          cnl(28);
          cout << "1110" << endl;
        }
      }
      if(n%16==5)
      {
        if(n>16)
        {
          cnl(1);
          // 21 19 18 16 7 6 4 2 1
          cout << "100111111110101101100";
          fr(i,0,n/16-1) cout << "1001011001101001";
          cout << endl;
        }
        else
        {
          cnl(25);
          cout << "11110" << endl;
        }
      }
      if(n%16==6)
      {
        if(n>16)
        {
          cnl(1);
          // 22 21 20 14 10 7 2
          cout << "0100001001000100000111";
          fr(i,0,n/16-1) cout << "1001011001101001";
          cout << endl;
        }
        else
        {
          cnl(7);
          cout << "011110" << endl;
        }
      }
      if(n%16==7)
      {
        if(n>16)
        {
          cnl(0);
          // 22 21 20 19 14 8 4
          cout << "10001111101111110111000";
          fr(i,0,n/16-1) cout << "1001011001101001";
          cout << endl;
        }
        else
        {
          cnl(26);
          cout << "0001110" << endl;
        }
      }
      if(n%16==8)
      {
        if(n>16)
        {
          cnl(0);
          // 24 23 22 18 12 9 4 2
          cout << "101011110110111110111000";
          fr(i,0,n/16-1) cout << "1001011001101001";
          cout << endl;
        }
        else
        {
          cnl(4);
          cout << "00110110" << endl;
        }
      }
      if(n%16==9)
      {
        if(n>16)
        {
          cnl(1);
          // 25 24 23 22 8 3 2 1
          cout << "1110000100000000000001111";
          fr(i,0,n/16-1) cout << "1001011001101001";
          cout << endl;
        }
        else
        {
          cnl(5);
          cout << "011010110" << endl;
        }
      }
      if(n%16==10)
      {
        if(n>16)
        {
          cnl(1);
          // 22 21 20 19 18 17 16 15 14 13 12 10 8 7 4 3 1
          cout << "10110011010111111111110000";
          fr(i,0,n/16-1) cout << "1001011001101001";
          cout << endl;
        }
        else
        {
          cnl(1);
          // 9 7 6 5 4 3 2
          cout << "0111111010" << endl;
        }
      }
      if(n%16==11)
      {
        if(n>16)
        {
          cnl(0);
          // 22 21 20 19 18 17 16 15 14 13 12 10 8 7 4 3 1
          cout << "011101101111111011111110000";
          fr(i,0,n/16-1) cout << "1001011001101001";
          cout << endl;
        }
        else
        {
          cnl(12);
          // 9 7 6 5 4 3 2
          cout << "00001101001" << endl;
        }
      }
      if(n%16==12)
      {
        if(n>16)
        {
          cnl(0);
          // 22 21 20 19 18 17 16 15 14 13 12 10 8 7 4 3 1
          cout << "001011100110";
          fr(i,0,n/16) cout << "1001011001101001";
          cout << endl;
        }
        else
        {
          cnl(0);
          // 9 7 6 5 4 3 2
          cout << "001011100110" << endl;
        }
      }
      if(n%16==13)
      {
        if(n>16)
        {
          cnl(1);
          // 22 21 20 19 18 17 16 15 14 13 12 10 8 7 4 3 1
          cout << "1111101111100";
          fr(i,0,n/16) cout << "1001011001101001";
          cout << endl;
        }
        else
        {
          cnl(1);
          // 9 7 6 5 4 3 2
          cout << "1111101111100" << endl;
        }
      }
      if(n%16==14)
      {
        if(n>16)
        {
          cnl(1);
          // 22 21 20 19 18 17 16 15 14 13 12 10 8 7 4 3 1
          cout << "10100110010110";
          fr(i,0,n/16) cout << "1001011001101001";
          cout << endl;
        }
        else
        {
          cnl(1);
          // 9 7 6 5 4 3 2
          cout << "10100110010110" << endl;
        }
      }
      if(n%16==15)
      {
        if(n>16)
        {
          cnl(0);
          // 22 21 20 19 18 17 16 15 14 13 12 10 8 7 4 3 1
          cout << "001111010111100";
          fr(i,0,n/16) cout << "1001011001101001";
          cout << endl;
        }
        else
        {
          cnl(0);
          // 9 7 6 5 4 3 2
          cout << "001111010111100" << endl;
        }
      }
    }
  }
}
// 17 15 14 12 10 8 6 5 2
