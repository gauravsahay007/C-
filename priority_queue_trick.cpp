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

int main(){
   vector<pair<int,int>>v={{2,4},{3,1},{8,3},{20,10},{5,5}};

   fo(i,v.size()) v[i].second*=-1;

   sort(v.begin(),v.end());

    fo(i,v.size()) v[i].second*=-1;

    

    fo(i,v.size()) cout<<v[i].first<<" "<<v[i].second<<endl;






return 0;    
}