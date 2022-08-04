#include <bits/stdc++.h>
using namespace std;

#define int long long

// int solve(string a, string b)
// {
//   int n = a.size(), m = b.size();
//   map<char, vector<int>> mp;
//   int ans = 0, prev = 0;
//   for(int i = 0; i<n; i++) mp[a[i]].push_back(i+1);
//   for(auto c: b)
//   {
//     if(mp[c].empty()) return -1;
//     int curr = upper_bound(mp[c].begin(), mp[c].end(), prev) - mp[c].begin();
//     if(curr == mp[c].size()) ans += n-prev+mp[c][0], prev = mp[c][0];
//     else                     ans += curr - prev,     prev = curr;
//   }
//   return ans;
// }
//
// // int to_precision(string number, int num_digits)
// // {
// //   double ans = 0;
// //   bool is_frac = 0;
// //   double frac_coeff = 1;
// //   for(auto &c: number)
// //   {
// //     if(ans == 0 && c==0) continue;
// //     if(c==',') continue;
// //
// //     if('0' <= c && c <= '9')
// //     {
// //       if(!is_frac)
// //       {
// //         if(num_digits>0)
// //         {
// //           ans = 10*ans + (c-'0');
// //         }
// //         else {
// //           frac_coeff /= 10;
// //           ans += frac_coeff * (c-'0');
// //         }
// //       }
// //     }
// //   }
// // }
//
// string to_precision(string number, int num_digits)
// {
//   string ans;
//   for(int i = 0; i <  number.size(); i++)
//   {
//     if(ans.empty() && number[i] == '0') continue;
//     if(number[i] == ',') continue;
//     if(number[i] == '.')
//     {
//       ans+='.';
//       continue;
//     }
//     if(num_digits > 0)
//     {
//       ans += number[i];
//       num_digits--;
//     }
//     else ans += '0';
//   }
//   return ans;
// }
//
//
//
// vector<vector<int>> all_houses_structured(vector<vector<int>> houses, vector<vector<int>> colours)
// {
//   map<int, int> count;
//   map<int, vector<pair<int,int>> freq;
//   for(int i = 0; i<houses.size(); i++)
//   {
//     for(int j = 0; j<houses[i].size(); j++)
//     {
//       count[houses[i][j]]++;
//     }
//   }
//   for(auto i = count.begin(); i != count.end(); i++)
//   {
//     int house_number = i->first;
//
//   }
// }

signed main()
{
  // cout << to_precision("04092540.3627", 8) << endl;
}
