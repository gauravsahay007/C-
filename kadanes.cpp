#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int sum=0;
	int mx=INT_MIN;
	for(int i=0;i<n;i++){
		sum+=arr[i];
		mx=max(mx,sum);
		if(sum<0) sum=0;
	}
	cout<<mx<<endl;
}
int main(){
	solve();
   




return 0;    
}