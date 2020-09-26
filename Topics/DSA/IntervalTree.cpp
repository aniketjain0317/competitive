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

// Structure to represent an interval
struct Interval
{
  int low, high;
};

// Structure to represent a node in Interval Search Tree
struct ITNode
{
  Interval *i;  // 'i' could also be a normal variable
  int max;
  ITNode *left, *right;
};

// A utility function to create a new Interval Search Tree Node
ITNode * newNode(Interval i)
{
  ITNode *temp = new ITNode;
  temp->i = new Interval(i);
  temp->max = i.high;
  temp->left = temp->right = NULL;
  return temp;
};

// A utility function to insert a new Interval Search Tree Node
// This is similar to BST Insert.  Here the low value of interval
// is used tomaintain BST property
ITNode *insert(ITNode *root, Interval i)
{
  // Base case: Tree is empty, new node becomes root
  if (root == NULL)
      return newNode(i);

  // Get low value of interval at root
  int l = root->i->low;

  // If root's low value is smaller, then new interval goes to
  // left subtree
  if (i.low < l)
      root->left = insert(root->left, i);

  // Else, new node goes to right subtree.
  else
      root->right = insert(root->right, i);

  // Update the max value of this ancestor if needed
  if (root->max < i.high)
      root->max = i.high;

  return root;
}

// A utility function to check if given two intervals overlap
bool doOVerlap(Interval i1, Interval i2)
{
  if (i1.low <= i2.high && i2.low <= i1.high)
      return true;
  return false;
}

// The main function that searches a given interval i in a given
// Interval Tree.
Interval *overlapSearch(ITNode *root, Interval i)
{
  // Base Case, tree is empty
  if (root == NULL) return NULL;

  // If given interval overlaps with root
  if (doOVerlap(*(root->i), i))
      return root->i;

  // If left child of root is present and max of left child is
  // greater than or equal to given interval, then i may
  // overlap with an interval is left subtree
  if (root->left != NULL && root->left->max >= i.low)
      return overlapSearch(root->left, i);

  // Else interval can only overlap with right subtree
  return overlapSearch(root->right, i);
}

void inorder(ITNode *root)
{
  if (root == NULL) return;

  inorder(root->left);

  cout << "[" << root->i->low << ", " << root->i->high << "]"
       << " max = " << root->max << endl;

  inorder(root->right);
}

// Driver program to test above functions
int main()
{
  // Let us create interval tree shown in above figure
  Interval ints[] = {{15, 20}, {10, 30}, {17, 19},
      {5, 20}, {12, 15}, {30, 40}
  };
  int n = sizeof(ints)/sizeof(ints[0]);
  ITNode *root = NULL;
  for (int i = 0; i < n; i++)
      root = insert(root, ints[i]);

  cout << "Inorder traversal of constructed Interval Tree is\n";
  inorder(root);

  Interval x = {6, 7};

  cout << "\nSearching for interval [" << x.low << "," << x.high << "]";
  Interval *res = overlapSearch(root, x);
  if (res == NULL)
      cout << "\nNo Overlapping Interval";
  else
      cout << "\nOverlaps with [" << res->low << ", " << res->high << "]";
  return 0;
}
