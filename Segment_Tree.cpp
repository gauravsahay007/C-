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

vector<int>seg_tree(4e5+10);
vector<int>a(4e5+1);

void build_tree(int si,int ss,int se){
	if(ss==se) {
		seg_tree[si]=a[ss];
		return ;
	}
	int mid = (ss+se)/2;
	build_tree(2*si,ss,mid);
	build_tree(2*si+1,mid+1,se);

	seg_tree[si]=min(seg_tree[2*si],seg_tree[2*si+1]);
}

int query(int si,int ss,int se,int qs,int qe){
	if(qs>se || qe<ss){
     return INT_MAX;
 }

	if(ss>=qs && se<=qe){
		return seg_tree[si];
	}
	int mid = (ss+se)/2;
	int l = query(2*si,ss,mid,qs,qe);
	int r = query(2*si+1,mid+1,se,qs,qe);

	return min(l,r);
}

void update(int si,int ss,int se,int qi){
    if(ss==se){
        st[si]=a[si];
        return;
    }

    int mid = (ss+se)/2;

    if(qi<=mid){
        update(2*si,ss,mid,qi);
    }
    else update(2*si+1,mid+1,se,qi);

    st[si] = min(st[2*si],st[2*si+1]);
}
					
signed main(){
	cin.tie(NULL);
	int n;
	cin>>n;
	foi(i,1,n+1) cin>>a[i];
	build_tree(1,1,n);
	int t;
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		cout<<query(1,1,n,x+1,y+1)<<endl;
	}


   




return 0;    
}