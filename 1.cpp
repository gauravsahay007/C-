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
   string s;
   cin>>s;
   int n = s.size();
   vector<int>lps(n,0);
   lps[0] = 0; 
   int i = 1,len = 0;
   while(i<s.size()){
    if(s[i] == s[len]){
        len++;
        lps[i] = len;
        i++;
    }
    else{
        if(len!=0){
            len = lps[len-1];
        }
        else{
            lps[i] = 0;
            i++;
        }
    }
   }

   vector<int>ans;
   int curr = lps[n-1];
   while(curr>0){
    ans.push_back(curr);
    curr = lps[curr-1];
   }

   sort(all(ans));
   fo(i,ans.size()){
    cout<<ans[i]<<" ";
   }
   cout<<endl;






return 0;    
}