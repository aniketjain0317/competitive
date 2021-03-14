#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t; cin >> t;
  while(t--)
  {
    double h, m; cin >> h >> m;
    double hhand, mhand;
    hhand = (360/12)*h + (360/12)*(m/60);
    if(hhand>360) hhand=hhand-360;
    mhand = (360/60)*m;
    double ang = abs(hhand-mhand);
    if(ang>180) ang=360-ang;
    cout << ang << endl;
  }
}
