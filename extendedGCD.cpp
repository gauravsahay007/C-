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

int gcd(int a,int b,int &x,int &y){
	if(a==0){
		x=0;
		y=1;
		return b;
	}
	int x1 , y1;
	int g = gcd( b%a , a , x1 , y1 );
	x = y1 - (b/a)*x1;
	y = x1;
	return g;
}
signed main(){
   int a,b;
   cin>>a>>b;
   int x,y;
   cout<<gcd(a,b,x,y)<<endl;
   cout<<x<<" "<<y<<endl;




return 0;    
}