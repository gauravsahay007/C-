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
vector<int>adj[N];
vector<int> Kahns(int n,int m,vector<int>indegree){
	queue<int>q;
	vector<int>ans;
	for(int i=0;i<n;i++){
		if(indegree[i] == 0) q.push(i);
	}
	while(!q.empty()){
		int node = q.front();
		q.pop();
		ans.push_back(node);
		for(auto it:adj[node]){
			indegree[it]--;
			if(indegree[it] == 0){
				q.push(it);
			}
		}
	}
	if(ans.size() < n) cout<<"Cycle Detected"<<endl;
	return ans;
}
signed main(){
	cin.tie(NULL); 
	int n,m;
	cin>>n>>m;
	vector<int>indegree(n,0);
	fo(i,m){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		indegree[y]++;
	} 

	vector<int>topo = Kahns(n,m,indegree);
	for(int i = 0;i<topo.size();i++){
		cout<<topo[i]<<" ";
	}

   




return 0;    
}