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

bool ok(int m,vector<int>a,int  k){
	int ct=1;
	int sum=0;
	for(int i:a){
		if(sum+i>m){
			ct++;
			sum = i;
		}
		else {
			sum += i;
		}
	}
	return ct <=k;
}
int main(){
   int k=3;
   vector<int> a={10,5,20,50,25,45,15};

   int ans=-1;
   int l = *max_element(a.begin(),a.end());




   int r=accumulate(a.begin(),a.end(),0);
   while(l <= r){
   	int m=(l+r)/2;
   	if(ok(m,a,k)){
   		ans=m;
   		r=m-1;
   	}
   	else{
   		l=m+1;
   	}
   }

   cout<<ans<<endl;





return 0;    
}