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

int main(){
   
   auto f = [](double x) -> double {
   	return -x*x + 4*x +5;
   };

   const double EPS = 1e-9;
   double l=0, r = 1e9;
   while(r-l>EPS){
   	double m1=l+(r-l)/3;
   	double m2=r-(r-l)/3;
   	if(f(m1)<f(m2)) l = m1;
   	else r=m2;
   }

   cout << fixed << setprecision(10);
   cout<<f(l);





return 0;    
}