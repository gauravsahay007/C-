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
   int t;
   cin>>t;
   while(t--){
    int n;
    cin>>n;
    vector<int>a(n);
      map<int,int>m;
    fo(i,n) {
        cin>>a[i];
        m[a[i]]=1;
    }
    n = unique(all(a)) - a.begin();
    a.resize(n);
  
    fo(i,n){
        m[a[i]]++;
    }
    m[a[0]]--;
    m[a[n-1]]--;
    int mn=INT_MAX;
    for(auto it:m){
        mn=min(mn,it.second);
    }

    cout<<mn<<endl;
   
    



   }




return 0;    
}