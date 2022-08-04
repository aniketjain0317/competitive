// This is an intellectual property of Diablo Escada ,
// So please use it with extreme CAUTION .


//-------We can be heroes , just for one day!!.---------//

    #include <bits/stdc++.h>
    using namespace std;

//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ knowledge $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//

    #define pb push_back
    #define MP make_pair
    #define F first
    #define S second
    #define ll long long
    #define lb lower_bound
    #define ub upper_bound
    #define bs binary_search
    #define int ll

    #define cnl(x) cout << x << endl
    #define csp(x) cout << x << " "
    #define read(x) cin >> x
    #define cinarr(n,arr) fo(i,0,n) read(arr[i]);
    #define cinarr2d(n,m,arr) {fo(i,0,n) {fo(j,0,m) read(arr[i][j]);}}
    #define all(v) v.begin(),v.end()

    #define fo(i,a,b) for(int i=a;i<b;i++)
    #define rfo(i,b,a) for(int i=b;i>=a;i--)
    #define test(t) ll t; cin >> t; fo(tno,1,t+1)

    #define vshow1d(arr) {ll n = arr.size(); fo(i,0,n) {csp(arr[i]);}cout<<endl;}
    #define show1d(n,arr) fo(i,0,n) {csp(arr[i]);}cout<<endl;
    #define vshow2d(arr) {ll n=arr.size();   fo(i,0,n) {ll m = arr[i].size(); fo(j,0,m) csp(arr[i][j]); cout << endl;}}
    #define show2d(n,m,arr) {fo(i,0,n) {fo(j,0,m) csp(arr[i][j]); cout << endl;}}

    #define mem( a, val ) memset(a, val, sizeof( a ) )
    #define deci( x ) cout<<fixed<<setprecision( x )
    #define bitcount( x ) __builtin_popcountll( x )
    // #define endl "\n"


    typedef vector<ll> vi;
    typedef pair<ll,ll> pi;
    typedef vector<pi> vpi;
    typedef vector<vi> vvi;

    const int MOD   = 1000000007 ;
    const int N     = 100005 ;
    const int MAX   = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//

class Contributor {
public:
    string name;
    map<string,int> skill_level;
    // size of this map is no of skills the contributor has;
};

class Project {
public:
    string name;
    ll days;
    int score;
    int best_before;
    vector<pair<string,int>> skill_level_req;
    // size of this map is no. of roles required for prikect;
};

class ans {
public:
    string name;
    vector<string> roles;
};


int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("./inputC.txt", "r", stdin);
    // freopen("./myansC.txt", "w", stdout);


    int nc, np;
    cin>>nc>>np;

    vector<Contributor> contributors(nc);
    vector<Project> projects(np);
    vector<ll> cont_time(nc,0);
    vector<ans> aa;
    fo(i,0,nc) {
        string nam;
        int nn;
        cin>>nam>>nn;

        contributors[i].name = nam;

        fo(j,0,nn) {
            string skl;
            int lvl;
            cin >> skl>> lvl;
            contributors[i].skill_level[skl] = lvl;
        }
    }
    fo(i,0,np) {
        string proj;
        int dd,ss,bb,nn;
        cin>>proj>>dd>>ss>>bb>>nn;
        projects[i].name = proj;
        projects[i].days = dd;
        projects[i].score = ss;
        projects[i].best_before = bb;
        fo(j,0,nn){
            string skl;
            int lvl;
            cin>>skl>>lvl;
            projects[i].skill_level_req.pb({skl,lvl});
        }

    }

    // cout<<projects[999].name<<endl;
    // cout<<"ff"<<endl;
    // fo(i,0,projects[999].skill_level_req.size()) {
    //     cout<<projects[999].skill_level_req[i].first<<endl;
    // }

    vector<Project> sorted(projects);
    // sort(all(sorted), [](auto &a, auto &b) {
    //     if(a.score==b.score) return a.days<b.days;
    //     return a.score>b.score;
    // });

    ll tim = 0;
    sort(all(sorted), [&tim](auto &a, auto &b) {
        return a.score - max(tim+a.days-a.best_before,0LL) > b.score - max(tim+b.days-b.best_before,0LL);
    });
    cnl(sorted.size());
    fo(i,0,np) {
        if(sorted.size() == 0) break;

        // sort(all(sorted), [&tim](auto &a, auto &b) {
        //     return a.score - max(tim+a.days-a.best_before,0LL) > b.score - max(tim+b.days-b.best_before,0LL);
        // });

        ll s2 = sorted.size();

        ll t2 = 1e6;

        fo(j,0,s2) {
            vector<bool> te(nc);
            bool ye2 = 1;
            ans an;
            an.name = sorted[j].name;
            for(auto x : sorted[j].skill_level_req) {
                bool ye = 0;
                fo(k,0,nc) {
                    if(!te[k] && cont_time[k] <= tim && contributors[k].skill_level[x.first] >= x.second) {
                        te[k] = 1;
                        ye = 1;
                        an.roles.pb(contributors[k].name);
                        break;
                    }
                }
                if(!ye) {
                    ye2 = 0;
                    break;
                }
            }
            if(ye2) {


                fo(k,0,nc) {
                    if(te[k]) {
                        cont_time[k] += sorted[j].days;
                    }
                }
                aa.pb(an);
                t2 = min(t2,sorted[j].days);

                sorted.erase(sorted.begin()+j); j--; s2--;
                // cnl(sorted[j].name);
            }
            if((s2-j)==1) break;
        }

        tim += t2;

    }

    cnl(aa.size());

    for(auto x : aa){
        cnl(x.name);
        for(auto r : x.roles){
            cout<<r<<" ";
        }
        cnl("");
    }





    return 0;
}
