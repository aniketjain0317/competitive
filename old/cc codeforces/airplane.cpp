// Problem 839B - (Contest / 1700)
// WA on test 43 (idek at this point)
#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >>k;
    int arr[k],q[k],r[k];
    int quad=n,c1=0, c2=0, c3=0,duo=2*n;
    for(int i=0;i<k;i++)
    {
        cin >> arr[i];
        q[i]=arr[i]/4;
        if(quad>=q[i])quad-=q[i];
        else duo-=2*q[i];
        r[i]=arr[i]%4;
        if(r[i]==1) c1++;
        if(r[i]==2) c2++;
        if(r[i]==3) c3++;
    }
    int cc,flag=-1;
    if(c1<=c2) {cc=c1; c1=c2-c1;}
    else {cc=(c1+c2)/2; c1=(c1+c2)%2;}
    c3+=cc;

    if(quad)
    {
      if(quad>c3)
      {
        quad-=c3;
        if(2*duo>=(c1-quad)*2) flag=1;
        else flag=0;
      }
      else
      {
        c3-=quad;
        if(2*duo>=4*c3+2*c1) flag=1;
        else flag=0;
      }
    }
    else
    {
      if(2*duo>=4*c3+2*c1) flag=1;
      else flag=0;
    }
    if(flag) cout << "YES\n";
    else cout << "NO\n";
}

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n, k;
//     cin >> n >>k;
//     int arr[k],q[k],r[k];
//     int quad=2*n,c1=0, c2=0, c3=0;
//     for(int i=0;i<k;i++)
//     {
//         cin >> arr[i];
//         q[i]=arr[i]/4;
//         quad-=q[i];
//         r[i]=arr[i]%4;
//         if(r[i]==1) c1++;
//         if(r[i]==2) c2++;
//         if(r[i]==3) c3++;
//     }
//     int cc;
//     if(c1<=c2) {cc=c1; c1=c2-c1;}
//     else {cc=(c1+c2)/2; c1=(c1+c2)%2;}
//     c3+=cc;
//     int f=quad/2;
//     if(quad>=c1+c3) cout << "YES\n";
//     else if(f<=c3&&(4*quad>=(4*c3+2*c1))) cout << "YES\n" ;
//     else if(f>c3&&(4*quad>=(4*f+2*(c1-c3-f)))) cout << "YES\n";
//     else cout << "NO\n";
// }
