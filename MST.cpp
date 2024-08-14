#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9+7
#define pb            push_back
#define all(var)      var.begin(), var.end()
#define fo(i, n)      for (int i = 0; i < n; i++)
#define foi(i,k,n)      for (int i = k; i < n; i++)
#define sqrt(x)       sqrtl(x)
#define endl          "\n"
#define YES                          cout << "YES\n";
#define NO                           cout << "NO\n";
#define Yes                          cout << "Yes\n";
#define No                           cout << "No\n";
#define int long long

#define pii pair<int,int>
const int N = 1e5+1;
vector<pair<int,int>>adj[N];

int MST(int n){
	priority_queue<pii,vector<pii>,greater<pii>>pq;
	vector<int>vis(n,0);
	pq.push({0, 0});
	int mst = 0;
	while(!pq.empty()){
		int node = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if(vis[node]) continue;
		else{
			vis[node] = 1;
			mst += cost;
			for(auto it:adj[node]){
				pq.push({it.second,it.first});
			}
		}
	}

	return mst;
}

signed main(){
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	fo(i,m){
		int x,y,z;
		cin>>x>>y>>z;
		adj[x].push_back({y,z});
		adj[y].push_back({x,z});
	} 

	cout<<MST(n)<<endl;

   




return 0;    
}