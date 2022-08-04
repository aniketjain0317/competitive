// Problem
//

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define lb lower_bound
#define ub upper_bound
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
#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define cp2(x) (__builtin_popcountll(x)==1)
#define lp2(x) (__builtin_ctzll(x))
#define tc(tno) cout << "Case #" << tno << ": "
#define dsp(x) cout << #x << ": " << x << ", "
#define dnl(x) cout << #x << ": " << x << endl
#define cnlret(x) {cnl(x); return;}


template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T>             ostream& operator<<(ostream& os,  set<T>  v)   {os<<"{"; for (auto& i : v) os << i << ','; os<<"}"; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> bool chmin(T& a, U b){if (a > b) {a = b; return true;} return false;}
template<typename T, typename U> bool chmax(T& a, U b){if (a < b) {a = b; return true;} return false;}


#define intt int32_t
#define int long long
// #define endl '\n'

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef map<string,vi> msi;
const ll MOD = 1000000007;
const ll INF = 1LL<<62;
const int N = 100005;

class Contributor {
public:
    string name;
    map<string,int> skill_level;
    int available;
    // size of this map is no of skills the contributor has;
};

class Project {
public:
    string name;
    int id;
    int days;
    int score;
    int best_before;
    vector<pair<string,int>> skill_level_req;
    // size of this map is no. of roles required for prikect;
};

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  freopen("myansE.txt","w",stdout);
  freopen("inputE.txt","r",stdin);
  int C, P; cin >> C >> P;
  vector<Contributor> people(C);
  vector<Project> projects(P);
  map<string, vector<pi>> skilled;
  for(int i = 0; i<C; i++)
  {
    string name; cin >> name;
    people[i].name = name;
    people[i].available = 0;
    int n; cin >> n;
    for(int j = 0; j<n; j++)
    {
      string skill; cin >> skill;
      int level; cin >> level;
      people[i].skill_level[skill] = level;
      skilled[skill].pb({level, i});
    }
  }
  for(int i = 0; i<P; i++)
  {
    string project; cin >> project;
    projects[i].name = project;
    projects[i].id = i;
    int d,s,b,r; cin >> d >> s >> b >> r;
    projects[i].days = d;
    projects[i].score = s;
    projects[i].best_before = b;
    for(int j = 0; j<r; j++)
    {
      string skill; cin >> skill;
      int level; cin >> level;
      projects[i].skill_level_req.pb({skill, level});
    }
  }

  vector<Project> sorted(projects);
  for(auto &[s, v]: skilled) sort(all(v));
  sort(all(sorted), [](auto &a, auto &b) {
    return a.best_before<b.best_before;
    // return a.score>b.score;
  });
  vector<pair<int, vi>> ans;
  for(auto &project: sorted)
  {
    int f = 0;
    set<int> idset;
    // set<pair<int, int>, greater<pi>> ids;
    vi ids;
    int mx = -1;
    // csp(project.name);
    // cnl(project.best_before);
    for(auto &[skill, req]: project.skill_level_req)
    {
      int mn = INF, mnid = -1;
      for(auto it = lb(all(skilled[skill]), make_pair(req, -1LL)); it!=skilled[skill].end(); it++)
      {
        auto &[level, id] = *it;
        if(idset.count(id)) continue;
        if(chmin(mn, people[id].available)) mnid = id;
        if(mn+project.days<=(project.best_before)) break;
      }
      if(mnid==-1) {f=1; break;}
      chmax(mx, mn);
      if((mx+project.days)>(project.best_before+project.score)) {f=1; break;}
      ids.pb(mnid);
      idset.insert(mnid);
    }
    if(f) continue;

    for(auto &id: ids) people[id].available+=project.days;
    ans.pb({project.id, ids});
  }
  cnl(ans.size());
  for(auto &[pid, v]: ans)
  {
    cnl(projects[pid].name);
    for(auto &x: v) csp(people[x].name); cout << endl;
  }
}
