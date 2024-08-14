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

const int N = 2e5 + 1;
vector<int> segTree(4*N);
vector<int> lazy(4*N);
vector<int> arr(N);

void build_tree(int si, int ss, int se){
    if(ss == se){
        segTree[si] = arr[ss]; 
        return ;
    }

    int mid = (ss + se)/2;
    build_tree(2*si + 1, ss, mid);
    build_tree(2*si + 2, mid + 1, se);
    segTree[si] = segTree[2*si+1] + segTree[2*si + 2];
}

void propogate(int si, int ss, int se){
    if(lazy[si]!=0){
        int dx = lazy[si];
        segTree[si] += dx*(se-ss+1);
        if(ss!=se){
            lazy[2*si + 1] += dx;
            lazy[2*si + 2] += dx;
        }
        lazy[si] = 0;
    }
}

int query(int si,int ss,int se,int pos){
    propogate(si, ss, se);
    if(ss == se) {
        return segTree[si];
    }


    int mid = (ss + se)/2;

    if(pos <= mid) { 
       return query(2*si + 1,ss, mid, pos);
    }
    else return query(2*si + 2,mid + 1, se, pos);
    
}

void update(int si, int ss, int se, int qs, int qe, int val) {
    propogate(si, ss, se);
    if (ss > qe || se < qs) return;
    if (ss >= qs && se <= qe) {
        lazy[si] += val;
        propogate(si, ss, se);
        return;
    }

    int mid = (ss + se) / 2;
    update(2 * si + 1, ss, mid, qs, qe, val);
    update(2 * si + 2, mid + 1, se, qs, qe, val);
    segTree[si] = segTree[2 * si + 1] + segTree[2 * si + 2];
}

signed main(){
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    fo(i,n){
        cin>>arr[i];
    }
    build_tree(0,0,n-1);
    fo(i,q){
        int t;
        cin>>t;
        if(t == 1){
            int a,b,u;
            cin>>a>>b>>u;
            update(0,0,n-1,a-1,b-1,u);
        }
        else{
            int x;
            cin>>x;
            cout<<query(0,0,n-1,x-1)<<endl; 
        }
    }

   




return 0;    
}