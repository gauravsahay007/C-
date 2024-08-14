#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
	vector<int> rank, parent, size; //created rank and parent vector
public:
	DisjointSet(int n){
		rank.resize(n+1,0);//initialsed rank with n+1 space with 0
		parent.resize(n+1);//initialised parent vector
		size.resize(n+1);
		for(int i=0;i<n+1;i++){
			parent[i] = i;// initially all are self parents
			size[i]=1;
		}
	}	

	int findUParent(int n){ // to find parent
		if(parent[n]==n) return n; // ultimate parent is parent of self
		return parent[n]=findUParent(parent[n]); // path compression + recursion call
	}
     // connect krna means ultimate parent same hojana
	void UnionbyRank(int u, int v){// to do UNION of u and v
		int ulp_v = findUParent(v); //find the ultimate parent of v
		int ulp_u = findUParent(u); //find the ultimate parent of u
		if(ulp_v==ulp_u) return ; // if parent of u and v same means they are already connected
		if(rank[ulp_u]<rank[ulp_v]){ // if rank of ultimate parent of u is less then connect its ultimate  
		                            // parent to ultimate parent of v
			parent[ulp_u]=ulp_v;
		}
		else if(rank[ulp_v]<rank[ulp_u]){// if rank of ultimate parent of v is less 
			                          //then connect its ultimate  
		                            // parent to ultimate parent of u
			parent[ulp_v]=ulp_u;
		}
		else{
			parent[ulp_v]=ulp_u; // if ranks equal you can do either
			rank[ulp_u]++;// increase the rank beacause size increased
		}
	}

};
int main(){
	DisjointSet ds(7);
	ds.UnionbyRank(1,2);
	ds.UnionbyRank(2,3);
	ds.UnionbyRank(4,5);
	ds.UnionbyRank(6,7);
	ds.UnionbyRank(5,6);

	if(ds.findUParent(3)==ds.findUParent(7)){
		cout<<"NOT SAME"<<endl;
	}
	else cout<<"SAME"<<endl;
	ds.UnionbyRank(3,7);
	if(ds.findUParent(3)==ds.findUParent(7)){
		cout<<"NOT SAME"<<endl;
	}
	else cout<<"SAME"<<endl;


   




return 0;    
}