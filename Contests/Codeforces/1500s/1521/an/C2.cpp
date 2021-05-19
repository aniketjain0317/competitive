#include <bits/stdc++.h>
using namespace std;
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);

  int t; cin >> t;
  while(t--)
  {
    int n; cin >> n;
    int p[n]={};

    for(int i =0; i+2<n; i+=3)
    {
      int j=i+1, k=i+2;
      int a;
      cout << "? 1 "; csp(i+1); csp(j+1); cnl(n-1);
      cin >> a;
      if(a==n-1)
      {
        int a2;
        cout << "? 1 "; csp(j+1); csp(i+1); cnl(n-1);
        cin >> a2;
        a = max(a,a2);
      }
      int b;
      cout << "? 2 "; csp(i+1); csp(j+1); cnl(1);
      cin >> b;
      if(b==2)
      {
        int b2;
        cout << "? 2 "; csp(j+1); csp(i+1); cnl(1);
        cin >> b2;
        b = min(b,b2);
      }
      int c;
      cout << "? 1 "; csp(i+1); csp(k+1); cnl(n-1);
      cin >> c;
      if(c==n-1)
      {
        int c2;
        cout << "? 1 "; csp(k+1); csp(i+1); cnl(n-1);
        cin >> c2;
        c = max(c,c2);
      }
      int d;
      cout << "? 2 "; csp(i+1); csp(k+1); cnl(1);
      cin >>d;
      if(d==2)
      {
        int d2;
        cout << "? 2 "; csp(k+1); csp(i+1); cnl(1);
        cin >> d2;
        d = min(d,d2);
      }


      if(a==c) {p[i]=a; p[j]=b; p[k]=d;}
      else if(a==d) {p[i]=a; p[j]=b; p[k]=c;}
      else if(b==c) {p[i]=b; p[j]=a; p[k]=d;}
      else if(b==d) {p[i]=b; p[j]=a; p[k]=c;}
    }

    if(n%3==1)
    {
      int i=0, j=1, k=n-1;
      int a;
      cout << "? 1 "; csp(i+1); csp(j+1); cnl(n-1);
      cin >> a;
      if(a==n-1)
      {
        int a2;
        cout << "? 1 "; csp(j+1); csp(i+1); cnl(n-1);
        cin >> a2;
        a = max(a,a2);
      }
      int b;
      cout << "? 2 "; csp(i+1); csp(j+1); cnl(1);
      cin >> b;
      if(b==2)
      {
        int b2;
        cout << "? 2 "; csp(j+1); csp(i+1); cnl(1);
        cin >> b2;
        b = min(b,b2);
      }
      int c;
      cout << "? 1 "; csp(i+1); csp(k+1); cnl(n-1);
      cin >> c;
      if(c==n-1)
      {
        int c2;
        cout << "? 1 "; csp(k+1); csp(i+1); cnl(n-1);
        cin >> c2;
        c = max(c,c2);
      }
      int d;
      cout << "? 2 "; csp(i+1); csp(k+1); cnl(1);
      cin >>d;
      if(d==2)
      {
        int d2;
        cout << "? 2 "; csp(k+1); csp(i+1); cnl(1);
        cin >> d2;
        d = min(d,d2);
      }


      if(a==c) {p[i]=a; p[j]=b; p[k]=d;}
      else if(a==d) {p[i]=a; p[j]=b; p[k]=c;}
      else if(b==c) {p[i]=b; p[j]=a; p[k]=d;}
      else if(b==d) {p[i]=b; p[j]=a; p[k]=c;}
    }
    else if(n%3==2)
    {
      int i=0, j=n-2, k=n-1;
      int a;
      cout << "? 1 "; csp(i+1); csp(j+1); cnl(n-1);
      cin >> a;
      if(a==n-1)
      {
        int a2;
        cout << "? 1 "; csp(j+1); csp(i+1); cnl(n-1);
        cin >> a2;
        a = max(a,a2);
      }
      int b;
      cout << "? 2 "; csp(i+1); csp(j+1); cnl(1);
      cin >> b;
      if(b==2)
      {
        int b2;
        cout << "? 2 "; csp(j+1); csp(i+1); cnl(1);
        cin >> b2;
        b = min(b,b2);
      }
      int c;
      cout << "? 1 "; csp(i+1); csp(k+1); cnl(n-1);
      cin >> c;
      if(c==n-1)
      {
        int c2;
        cout << "? 1 "; csp(k+1); csp(i+1); cnl(n-1);
        cin >> c2;
        c = max(c,c2);
      }
      int d;
      cout << "? 2 "; csp(i+1); csp(k+1); cnl(1);
      cin >>d;
      if(d==2)
      {
        int d2;
        cout << "? 2 "; csp(k+1); csp(i+1); cnl(1);
        cin >> d2;
        d = min(d,d2);
      }


      if(a==c) {p[i]=a; p[j]=b; p[k]=d;}
      else if(a==d) {p[i]=a; p[j]=b; p[k]=c;}
      else if(b==c) {p[i]=b; p[j]=a; p[k]=d;}
      else if(b==d) {p[i]=b; p[j]=a; p[k]=c;}
    }

    csp("!");
    for(int i=0; i<n; i++) csp(p[i]);
    cout << endl;
  }
}
