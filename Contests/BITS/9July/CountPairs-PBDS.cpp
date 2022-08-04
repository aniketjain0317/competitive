#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
typedef tree< int, null_type,less_equal< int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
void myerase(pbds &t, int v){
    int rank = t.order_of_key(v);//Number of elements that are less than v in t
   pbds::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
    t.erase(it);
}
signed main() {
     ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);

   int t;
    cin>>t;
    while(t--)
    {

	pbds h;
        int n,c,d;
        cin>>n>>c>>d;
        vector<int>a(n);vector<int>b(n);
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(int j=0;j<n;j++)
        cin>>b[j];
        map<int,int>helper;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            h.insert(a[i]-b[i]);
        }
        for(int i=n-1;i>=0;i--)
        {
            int v1=a[i]-b[i];
            myerase(h,v1);
            ans+=h.order_of_key(v1+d-c+1);
            int req=v1+c-d;
        }
        cout<<ans<<endl;
    }
}
