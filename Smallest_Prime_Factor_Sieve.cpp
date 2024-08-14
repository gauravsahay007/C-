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

const int N = 1000000;
int spf[N+1];

void preCompute(){
	for(int i=2; i<=N ; i++){
		spf[i] = i;
	}

	for(int i=2; i*i <=N ;i++){
		if(spf[i]!=i) continue;
		for(int j = i*i ; j<=N ;j+=i){
			if(spf[j] == j){
				spf[j]=i;
			}
		}
	}
	// for(int i=2; i<=100 ;i++){
	// 	cout<< i <<"->"<< spf[i] <<endl;
	// }
}
signed main(){
   preCompute();
   int t;
   cin>>t;
   while(t--){
   	int n;
   	cin>>n;

   	while(n!=1){
   		cout<<spf[n]<<" ";
   		n=n/spf[n];
   	}
   	cout<<endl;
   }




return 0;    
}