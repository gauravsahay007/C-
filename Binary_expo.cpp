#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll mod=1e9+7;
#define pb            push_back
#define all(var)      var.begin(), var.end()
#define fo(i, n)      for (int i = 0; i < n; i++)
#define sqrt(x)       sqrtl(x)
#define endl          "\n"
#define YES                          cout << "YES\n";
#define NO                           cout << "NO\n";
#define Yes                          cout << "Yes\n";
#define No                           cout << "No\n";


ll binaryexpo(ll base, ll x){
	ll ans = 1;
	while(x){
		if(x%2){
			ans = (ans * base) % mod;
			x = x - 1;
		}
		else{
			base = ( base * base ) % mod;
			x = x/2;
		}
	}
	return ans;
}
signed main(){
   ll b,x;
   cin>>b>>x;
   cout<<binaryexpo(b,x)<<endl;

   int inverse = binaryexpo(b , mod - 2);
   cout<<inverse<<endl;
   cout<<(inverse*b)%mod<<endl;




return 0;    
}