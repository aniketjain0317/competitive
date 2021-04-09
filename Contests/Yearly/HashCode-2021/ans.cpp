#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
// #define priority_queue < ll, std::vector<ll>, std::greater<ll> > mnheap;    // mnheap.push(), mnheap.top(), mnheap.pop()
#define REP(i,a,b) for (auto i = a; i != b; i++)
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define pb push_back
#define SQ(a) (a)*(a)


 
using namespace std;
struct Car
{
	vector<int> path;
	int time_left=0;
};

struct edge
{
	// int ID;				// index of this edge in global vector (DONT NEED THIS)
	string name;
	int intersection1;
	int intersection2;
	int time;
	queue<int> cars;	// indices of cars in current street
};

struct Intersection
{
	vector<int> incoming_street_indices;	// indices of incoming edges in global vector
	vector<int> outgoing_street_indices;	// indices of outgoing edges in global vector
	// int ID;				// index of this node in global vector (DONT NEED THIS)
};

int MAX_SIZE = 100000;
vector<edge> edges(MAX_SIZE);
vector<Intersection> nodes(MAX_SIZE);
vector<Car> cars(MAX_SIZE);
map<string, int> edgeID; 	// The key is the street name, the value is the ID of the street in the edges array.
int D,I,S,V,F;
vector<map<int,int>> ans(MAX_SIZE);
vector<int> visited(MAX_SIZE,0);
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;


map<string,pair<int,int>> street_map; // maps street name to source, destination
vector<vector<string>> car_path;
vector<int> construct_path(vector<string> path){
	// recreates the path in terms of intersections
	// IDs rather than the street names
	vector<int> ans;
	// ans.push_back(edges[edgeID[path[0]]].intersection1); // IDK if this is needed
	for(auto s: path)
		ans.push_back(edges[edgeID[s]].intersection2);
	return ans;
}

bool cmp(Car a, Car b)
{
	return a.time_left<b.time_left;
}

// ans[intersection][time]=street;

void dummy_ans()
{
	vector<Car> cs(cars.begin(),cars.end());
	sort(cs.begin(),cs.end(),cmp);
	for(int i=0; i<V; i++)
	{
		auto c = cars[i];
		int id = c.path[0];
		vector<int> v2;
		v2.push_back(edges[id].time);
		v2.push_back(i);
		v2.push_back(1);
		pq.push(v2);
		ans[edges[id].intersection2][1]=id;
		visited[id]=1;
	}
	while(!pq.empty())
	{
		auto v = pq.top();
		pq.pop();
		auto c = cars[v[1]];
		auto eid = c.path[v[2]];
		// cout << "AAAAAAAA " << v[0] << " " << v[1] << " " << v[2] << endl;
		if(eid==c.path.size()) continue;
		if(!visited[eid]) 
		{	
			vector<int> v2;
			visited[eid]=1;
			v2.push_back(v[0]+edges[eid].time);
			v2.push_back(v[1]);
			v2.push_back(v[2]+1);
			pq.push(v2);
			ans[edges[eid].intersection2][v[0]]=eid;
			// cout <<"AAAAAAAAAAAAAA "<<edges[eid].intersection2<<" "<< eid<<" "<< v[0] << endl;
		}
	}

	for(int i=0; i<I; i++) 
		if(ans[i].empty())
			ans[i][0]=nodes[i].incoming_street_indices[0];
	return;
}



int main(){

	freopen("input/d.txt","r",stdin);
	freopen("d.txt","w",stdout);
	cin>>D>>I>>S>>V>>F;
	// D is duration
	// I is number of intersections
	// S number of streets
	// V number of cars
	// F bonus points for each car that reaches before D
	vector<vector<int>> adj(I+1);
	// vector<edge> edges(S);

	for(int i = 0;i<S;i++){
		int t1,t2;
		string name;
		int l;
		cin>>t1>>t2>>name>>l;
		edgeID[name] = i;

		edges[i].intersection1 = t1;
		edges[i].intersection2 = t2;
		edges[i].name = name;
		edges[i].time = l;
		nodes[t2].incoming_street_indices.push_back(i);
		nodes[t1].outgoing_street_indices.push_back(i);

		adj[t1].pb(t2);
	}

	for(int i =0;i<V;i++){
		// take paths of cars input
		int P;
		cin>>P;
		vector<string> string_path(P);
		for(int j = 0;j<P;j++)
			cin>>string_path[j];
		vector<int> id_path = construct_path(string_path);
		// id_path contains path in terms of IDs of intersections
		cars[i].path = id_path;
		for(auto id: id_path) {
			cars[i].time_left += edges[id].time;
        }
        // cout << i << " " << cars[i].time_left << " " << cars[i].path.size() << '\n';
    }

    int cnt[S]={};
    for(int i=0; i<V; i++)
    {
        for(auto e: cars[i].path) cnt[e]++;
    }

    dummy_ans();
    cout<<I<<endl;
    for(int i = 0;i<I;i++){
        cout<<i<<endl;
        cout<<ans[i].size()<<endl;
		pair<int,int> prev(-1,0);
        for(auto p: ans[i])
		{
			// cout << "AAAAAAA "<< p.f << endl;

			if(prev.f==-1) {prev=p; continue;}
			cout << edges[prev.s].name << " " << p.f-prev.f+1 << endl;
			prev=p;
		}
		cout << edges[prev.s].name << " " << 2 << endl;
    }
	return 0;
}