#include<bits/stdc++.h>
using namespace std;
#define ll long long int
long long factorial[1000001];
#define M 1000000007
int main(){
    int t;
    cin>>t;
    factorial[0]=0;
    factorial[1]=1;
    for(long long i=2;i<1000001;i++){
        factorial[i]=(i*(factorial[i-1])%M)%M;
    }
    
   while(t--){
    ll n;
    cin>>n;
    ll a[n];
    map<ll,ll>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        m[a[i]]++; 
    }
    ll sum=0;

    for(auto it: m){
        sum=(sum+(factorial[it.first]*it.second)%M)%M;
    }
        cout<<sum<<endl;
    }
}

