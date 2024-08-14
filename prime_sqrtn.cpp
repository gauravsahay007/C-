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

void sqt(int n){
	int ct=0;
	for(int i=1;i*i<n;i++){
		if(n%i==0){
			ct++;
			if(n/i  != i){
				ct++;
			}
		}
	}

	if(ct==2) cout<<"Prime"<<endl;
	else cout<<"Not Prime"<<endl;
}
signed main(){
   int n;
   cin>>n;
   sqt(n);




return 0;    
}