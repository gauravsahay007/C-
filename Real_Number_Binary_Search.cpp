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
#define int double
// However, this algorithm also has a problem, it can get stuck. This will happen if the numbers l
//  and r
//  are adjacent in the type double
// . Since double
//  stores numbers not with arbitrary precision, but only a certain number of digits, then if the numbers l
//  and r
//  are adjacent, then the middle between them will not be found and it will be equal to either l
//  or r
//  and the algorithm will run infinitely. This problem appears if the answer is large and the required precision is high enough.

int ok(int x,vector<int>a,int k,int n){
    int sum=0;
    fo(i,n){
        sum+=floor(a[i]/x);
    }
    // cout<<sum<<endl;
    return sum>=k;
}
signed main(){
    int n,k;
    cin>>n>>k;
    int l=0;
    int h=1e17;
    vector<int>a(n);
    fo(i,n){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int eps=1e-6;
    
    int ans;
    
    while(h-l>eps){
        int mid=l+(h-l)/(double)2;
    
        if(ok(mid,a,k,n)){
           
            ans=mid;
            l=mid+eps;
        }
        else h=mid-eps;
 }

    cout<<setprecision(12)<<ans<<endl;

return 0;    
}