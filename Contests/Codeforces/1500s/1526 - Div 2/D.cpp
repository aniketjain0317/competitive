// Problem
//

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define lb lower_bound
#define bs binary_search
#define fs first
#define sn second
#define gri greater<int>
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x
#define all(v) v.begin(),v.end()
#define mxs(m,a) m=max(m,a)
#define mns(m,a) m=min(m,a)
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define frrb(i,a,b) for(int i=a; i>=b;i--)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define ainpl(n,arr) ll n; read(n); ll arr[n]; cinp(n,arr);
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define showVI(arr) {for(auto &xxx: arr) csp(xxx); cout << endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define showVVI(arr) {for(auto &vvv: arr) {for(auto &xxxx: vvv) csp(xxxx); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define intt int32_t
#define int long long
// #define endl '\n'

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 100005;
ll mod = INF;

map<char,int> mp;
map<int, char> mp2;

// ll getAns(string& st,string& str){
//   int n = st.size();
//         // string str = "NNOTA";
// 		int i = 0;
// 		vector<int> fpos(4,mod);
// 		vector<int> lpos(4,mod);
// 		while(i < n){
// 			int z = mp[str[i]];
// 			char x = str[i];
// 			fpos[z] = i;
// 			while(i < n && str[i] == x){
// 				i++;
// 			}
// 			lpos[z] = i-1;
// 		}
// 		ll ans = 0;
// 		for(int i = 0;i<n;i++){
// 			int x = mp[st[i]];
// 			if(fpos[x] == lpos[x]){
// 				for(int j = 0;j<4;j++){
// 					if(fpos[j] < fpos[x]){
// 						fpos[j] += 1;
// 						lpos[j] += 1;
// 					}
// 				}
// 				ans += (fpos[x] - i);
// 				lpos[x] = mod;
// 				fpos[x] = mod;
//
// 			}
// 			else{
// 				for(int i = 0;i<4;i++){
// 					if(fpos[i] < fpos[x]){
// 						fpos[i] += 1;
// 						lpos[i] += 1;
// 					}
// 				}
// 				ans += (fpos[x] - i);
// 				fpos[x] += 1;
// 			}
// 		}
// 		// cout<<ans<<endl;
// 		return ans;
// }

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  test(t)
  {
    string s; cin >> s;
    int n = s.size();

    map<char,int> cnt;
    fr(i,0,n) cnt[mp[s[i]]]++;

    vector<int> v({0,1,2,3});
    sort(all(v));
    string ans;
    int mx = -1;
    do
    {
      string f;
      fr(i,0,4) fr(j,0,cnt[v[i]]) f+=mp2[v[i]];
      int val = getAns(s, f);
      if(val>mx) ans = f, mx=val;
    } while(next_permutation(all(v)));
    cout << ans << endl;
  }
}
