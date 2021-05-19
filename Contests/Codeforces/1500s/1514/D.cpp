// Problem
//

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
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define intt int32_t
// #define int long long
// #define endl '\n'

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 100005;


int getMid(int s, int e) { return s + (e - s) / 2; }

/*  A recursive function to get the maximum value in
    a given range  of array indexes. The following
    are parameters for this function.

    st    --> Pointer to segment tree
    index --> Index of current node in the segment
              tree. Initially 0 is passed as root is
              always at index 0
    ss & se  --> Starting and ending indexes of the
                 segment represented by current node,
                  i.e., st[index]
    qs & qe  --> Starting and ending indexes of query
                 range */
int RMQUtil(int* st, int ss, int se, int qs, int qe,
                                          int index)
{
    // If segment of this node is a part of given range,
    //  then return the min of the segment
    if (qs <= ss && qe >= se)
        return st[index];

    // If segment of this node is outside the
    // given range
    if (se < qs || ss > qe)
        return 0;

    // If a part of this segment overlaps
    // with the given range
    int mid = getMid(ss, se);
    return max(RMQUtil(st, ss, mid, qs, qe, 2 * index + 1),
               RMQUtil(st, mid + 1, se, qs, qe, 2 * index + 2));
}

// Return minimum of elements in range from
// index qs (query start) to
// qe (query end).  It mainly uses RMQUtil()
int RMQ(int* st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n - 1 || qs > qe) {
        printf("Invalid Input");
        return -1;
    }

    return RMQUtil(st, 0, n - 1, qs, qe, 0);
}

// A recursive function that constructs Segment Tree
// for array[ss..se]. si is index of current node in
// segment tree st
int constructSTUtil(int arr[], int ss, int se, int* st,
                                               int si)
{
    // If there is one element in array, store it in
    //  current node of segment tree and return
    if (ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }

    // If there are more than one elements, then
    // recur for left and right subtrees and store
    // the minimum of two values in this node
    int mid = getMid(ss, se);
    st[si] = max(constructSTUtil(arr, ss, mid, st, si * 2 + 1),
                 constructSTUtil(arr, mid + 1, se, st, si * 2 + 2));
    return st[si];
}

/* Function to construct segment tree from given
   array. This function allocates memory for segment
   tree and calls constructSTUtil() to fill the
   allocated memory */
int* constructST(int arr[], int n)
{
    // Allocate memory for segment tree

    // Height of segment tree
    int x = (int)(ceil(log2(n)));

    // Maximum size of segment tree
    int max_size = 2 * (int)pow(2, x) - 1;

    int* st = new int[max_size];

    // Fill the allocated memory st
    constructSTUtil(arr, 0, n - 1, st, 0);

    // Return the constructed segment tree
    return st;
}

int maximumOccurrence(int arr[], int n, int qs, int qe)
{
    // Declaring a frequency array
    int freq_arr[n + 1];

    // Counting frequencies of all array elements.
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++)
        cnt[arr[i]]++;

    // Creating frequency array by replacing the
    // number in array to the number of times it
    // has appeared in the array
    for (int i = 0; i < n; i++)
        freq_arr[i] = cnt[arr[i]];

    // Build segment tree from this frequency array
    int* st = constructST(freq_arr, n);

    int maxOcc; // to store the answer

    // Case 1: numbers are same at the starting
    // and ending index of the query
    if (arr[qs] == arr[qe])
        maxOcc = (qe - qs + 1);

    // Case 2: numbers are different
    else {
        int leftmost_same = 0, righmost_same = 0;

        // Partial Overlap Case of a number with some
        // occurrences lying inside the leftmost
        //  part of the range and some just before the
        // range starts
        while (qs > 0 && qs <= qe && arr[qs] == arr[qs - 1]) {
            qs++;
            leftmost_same++;
        }

        // Partial Overlap Case of a number with some
        // occurrences lying inside the rightmost part of
        // the range and some just after the range ends
        while (qe >= qs && qe < n - 1 && arr[qe] == arr[qe + 1]) {
            qe--;
            righmost_same++;
        }
        // Taking maximum of all three
        maxOcc = max({leftmost_same, righmost_same,
                                RMQ(st, n, qs, qe)});
    }
    return maxOcc;
}

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  int n, q; cin >> n >> q;
  int arr[n]={};
  fr(i,0,n) cin >> arr[i];
  fr(i,0,q)
  {
    int l,r; cin >> l >> r; l--; r--;
    int sz = l-r+1;
    int x = maximumOccurrence(arr,n,l,r);
    int k = 2*x - sz;
    cnl(x);
  }
}
