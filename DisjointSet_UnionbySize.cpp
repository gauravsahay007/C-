#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
	vector<int> rank, parent, size; //created size and parent vector
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
	void UnionbySize(int u, int v){// to do UNION of u and v
		int ulp_v = findUParent(v); //find the ultimate parent of v
		int ulp_u = findUParent(u); //find the ultimate parent of u
		if(ulp_v==ulp_u) return ; // if parent of u and v same means they are already connected
		if(size[ulp_u]<size[ulp_v]){ // if size of ultimate parent of u is less then connect its ultimate  
		                            // parent to ultimate parent of v
			parent[ulp_u]=ulp_v;
			size[ulp_v]+=size[ulp_u];//size of parent of v = size of parent of u + size of parent of v
		}
		else if(size[ulp_v]<size[ulp_u]){// if size of ultimate parent of v is less 
			                          //then connect its ultimate  
		                            // parent to ultimate parent of u
			parent[ulp_v]=ulp_u;
			size[ulp_u]+=size[ulp_v];//size of parent of u = size of parent of v + size of parent of u
		}
		else{
			parent[ulp_v]=ulp_u; // if size equal you can do either
			size[ulp_u]+=size[ulp_v];;//size of parent of u = size of parent of v + size of parent of u
		}
	}

};
int main(){
	DisjointSet ds(7);
	ds.UnionbySize(1,2);
	ds.UnionbySize(2,3);
	ds.UnionbySize(4,5);
	ds.UnionbySize(6,7);
	ds.UnionbySize(5,6);

	if(ds.findUParent(3)==ds.findUParent(7)){
		cout<<"NOT SAME"<<endl;
	}
	else cout<<"SAME"<<endl;
	ds.UnionbySize(3,7);
	if(ds.findUParent(3)==ds.findUParent(7)){
		cout<<"NOT SAME"<<endl;
	}
	else cout<<"SAME"<<endl;


   




return 0;    
}