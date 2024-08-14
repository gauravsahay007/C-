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
   int n;
    cin>>n;
    int num,sum=0,count=0,maxi = INT_MIN;
    for(int i=0;i<n;i++){
        cin>>num;
        if(num==0)sum++;
        else{
            sum--;
            count++;
        }
        
        if(sum>maxi)maxi=sum;
        if(sum<0)sum=0;
    }
    
    cout<<count+maxi<<endl;


return 0;    
}