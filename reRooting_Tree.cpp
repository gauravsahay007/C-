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
const int N = 1e5 + 1;
vector<int> nodeCount(N,0),res(N,0);
void populate(int node, vector<vector<int>>graph, int p=-1){
	nodeCount[node]=1;
	for(auto it:graph[node]){
		if(it == p) continue;
		populate(it, graph, node);
		nodeCount[node]+=nodeCount[it];
		res[node]+=res[it]+nodeCount[it];
	}
}

void dfs(int node, vector<vector<int>>graph, int p=-1){
	int n = graph.size()-1;
	if(p!=-1){
		res[node]=res[p]-nodeCount[node]+(n-nodeCount[node]);
	}

	for(auto it:graph[node]){
		if(it == p) continue;
		dfs(it,graph,node);
	}
}
signed main(){
	cin.tie(NULL); 
   	int n,m=1;
   	cin>>n>>m;
   	int e = n-1;
   

   	vector<vector<int>> graph(n+1);
   	foi(i,1,e+1){
   		int u,v;
   		cin>>u>>v;
   		graph[u].push_back(v);
   		graph[v].push_back(u);
   	}
   	populate(1,graph);
   	dfs(1,graph);
   	foi(i,1,n+1) cout<<res[i]<<" ";
   	cout<<endl;


return 0;    
}