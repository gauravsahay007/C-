#include <bits/stdc++.h>
using namespace std;
#define ll long long 

#define pb            push_back
#define all(var)      var.begin(), var.end()
#define fo(i, n)      for (ll i = 0; i < n; i++)
#define sqrt(x)       sqrtl(x)
#define endl          "\n"
#define YES                          cout << "YES\n";
#define NO                           cout << "NO\n";
#define Yes                          cout << "Yes\n";

#define ll long long 
ll mod = 1e9+7;
ll pow(ll base, ll power){
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

ll geoSeries(ll base, ll power){
    ll numerator = (pow(base,power+1)-1+mod)%mod;
    ll denominatorInverse = pow(base-1,mod-2);
    return (numerator*denominatorInverse)%mod;
}

signed main(){
   ll t;
   cin>>t;
   ll sum = 1;
   ll product = 1;
   ll ct = 1;
   while(t--){
    ll x,p;
    cin>>x>>p;
    ct *= 1 + p;
    sum = sum*geoSeries(x,p);
  
    if(p%2==1){
        ll outerExponent = 1;
        outerExponent = (outerExponent*(p+1)/2)%(mod-1);
        else outerExponent = (outerExponent*(p+1))%(mod-1);
    }

    product = product*(pow(x,p*outerExponent)%(mod-1))%mod;
   }
   cout<<ct<<endl<<sum<<endl<<product<<endl;




return 0;    
}