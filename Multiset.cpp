#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9+7
#define pb            push_back
#define all(var)      var.begin(), var.end()
#define fo(i, n)      for (int i = 0; i < n; i++)
#define foi(i,k,n)      for (int i = k; i < n; i++)
#define sqrt(x)       sqrtl(x)
#define endl          "\n"
#define YES                          cout << "YES\n";
#define NO                           cout << "NO\n";
#define Yes                          cout << "Yes\n";
#define No                           cout << "No\n";
#define int long long


signed main(){
  cin.tie(NULL); 
   int t;
   cin>>t;
   while(t--){
    int n,k;
    cin>>n>>k;
    multiset<int>s;
    fo(i,n) {
      int x;
      cin>>x;
      s.insert(x);
    }

    int h=1;
    int left = k;
    while(!s.empty()){
      auto it = s.upper_bound(left);
      if(it==s.begin()){
        left=k;
        h++;
      }
      else{
        it--;
        int val = *it;
        left-=val;
        s.erase(it);
      }
      }
      cout<<h<<endl;
   }

   




return 0;    
}