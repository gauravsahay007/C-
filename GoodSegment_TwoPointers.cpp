#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9+7
#define pb            push_back
#define all(var)      var.begin(), var.end()
#define fo(i, n)      for (int i = 0; i < n; i++)
#define sqrt(x)       sqrtl(x)
#define endl          "\n"
#define YES                          cout << "YES\n";
#define NO                           cout << "NO\n";
#define Yes                          cout << "Yes\n";
#define No                           cout << "No\n";

signed main(){
   vector<int>a(n);
   int k;
   int ans=0;
   int i=0,j=0;
   while(j<n){
      sum+=a[j];
      while(i<=j && sum>k){
         sum-=a[i];
         i++;
      }

      // 11 12 13 14 15 k=10
      if(sum<=k){
         ans=max(ans,j-i+1);
      }
      j++;
   }




return 0;    
}