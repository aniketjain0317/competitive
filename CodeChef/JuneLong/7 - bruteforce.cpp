#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
  freopen("correctans.txt","w",stdout);
	long t;
	cin >> t;
	while(t--)
	{
	    long a,b,c,d,e,f;
	    cin >> a >> b >> c;
	    cin >> d >> e >> f;

	    int counta=0;
	    float g,h,i;

	    int p=1;
	    if(a==d&&b==e&&c==f)
	       { cout << p-1 << endl;
	        counta=1;
	       }
	    if(counta==0)
	    {
	        for(int i=-200;i<=200;i++)
	        {
	            if((a==d||a*i==d)&&(b==e||b*i==e)&&(c==f||c*i==f))
	                {
	                    cout << p << endl;
	                    counta=2;
	                    break;
	                }
	                else if((a==d||d+i==a)&&(b==e||e+i==b)&&(c==f||f+i==c))
	                {
	                    cout << p << endl;
	                    counta=2;
	                    break;
	                }


	        }
	    }


	    if(counta==0)
	        {
	            for(int i=-100;i<=100;i++)
	            {
	                for(int j=-100;j<=100;j++)
	                {
	                    if((a+i==d||a==d||a+i+j==d||a+j==d)&&(b+i==e||b==e||b+i+j==e||b+j==e)&&(c+i==f||c==f||c+i+j==f||c+j==f))
	                    {
	                        counta=3;
	                        cout << p+1 << endl;
	                        break;
	                    }
	                    else if(((a+i)*j==d||(a+i)==d||a*j==d||a==d)&&((b+i)*j==e||b+i==e||b*j==e||b==e)&&((c+i)*j==f||c+i==f||c*j==f||c==f))
	                    {
	                        counta=3;
	                        cout << p+1 << endl;
	                        break;
	                    }
	                    else if((a*j==d||a==d||a*i*j==d||a*i==d)&&(b*j==e||b==e||b*i==e||b*i*j==e)&&(c*j==f||c==f||c*i*j==f||c*i==f))
	                    {
	                        counta=3;
	                        cout << p+1 << endl;
	                        break;
	                    }
	                    else if(((a*i)+j==d||(a*i)==d||a+j==d||a==d)&&((b*i)+j==e||b*i==e||b+j==e||b==e)&&((c*i)+j==f||c*i==f||c+j==f||c==f))
	                    {
	                        counta=3;
	                        cout << p+1 << endl;
	                        break;
	                    }

	               }
	                if(counta==3)
	                    break;
	            }
	        }
	         if(counta==0)
	            cout << p+2<<endl;



	}
	return 0;
}
