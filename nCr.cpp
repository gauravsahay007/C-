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
ll N = 1e6+1;
vector<ll>fact(N+1);
vector<ll>modinv(N+1);

ll power(ll base, ll power){
	if(base<0) return 0;
	ll ans = 1;
	while(power){
		if(power%2==0){
			base = (base*base)%mod;
			power=power/2;
		}
		else{
			ans = (ans * base) % mod;
			power--;
		}
	}

	return ans;
}

ll preCompute(){
	fact[0]=1;
	modinv[0]=1;
	for(ll i = 1; i<=N ; i++){
		fact[i]=(fact[i-1]*i)%mod;
		modinv[i]=power(fact[i],mod-2);
	}
}

ll ncr(ll n, ll r){
	if(r>n) return 0;
	ll numo = fact[n];
	// cout<<r<<" "<<n-r<<endl;
	ll denoinv = (modinv[r]*modinv[n-r])%mod;
	// cout<<modinv[r]<<" "<<modinv[n-r]<<endl;
	// cout<<numo<<" "<<denoinv<<endl;
	ll ans = (numo * denoinv)%mod;
	return ans;
}
signed main(){
preCompute();
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		cout<<ncr(a-1,b-1)<<endl;
	}
 
	
return 0;    
}