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

int solve(){
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.size();
	int m=s2.size();
	set<int> posn[26];
	fo(i,n){
		posn[s1[i]-'a'].insert(i);
	}

	int ans=1;
	int lastindex=-1;
	fo(i,m){
		int ch = s2[i]-'a';
		if(posn[ch].size()==0){
			return -1;
		}

		auto it= posn[ch].upper_bound(lastindex);
		if(it==posn[ch].end()){
			ans++;
			lastindex=*posn[ch].begin();
			cout<<*posn[ch].begin()<<endl;
		}
		else{
			lastindex= *it;
		}
	}

	return ans;

}
int main(){
   
	cout<<solve();



return 0;    
}