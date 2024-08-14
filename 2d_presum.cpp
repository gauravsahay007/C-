#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;

        vector<vector<long long>>ar(n+1,vector<long long>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>ar[i][j];
            }
        }

        vector<vector<long long>>pre(n+1,vector<long long>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+ar[i][j];
            }
        }

        if(pre[n][m]<k+1){
            cout<< -1 << "\n";
            continue;
        }

        int low=0;
        int high=max(n,m);
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;

            bool ok=false;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                if(ar[i][j]==0) continue;

                int a=max(1,i-mid);
                int b=max(1,j-mid);
                int A=min(n,i+mid);
                int B=min(m,j+mid);

                long long val=pre[A][B]-pre[a-1][B]-pre[A][b-1]+pre[a-1][b-1];
                if(val>=k+1){
                    ok=true;
                }
            }
            }
            

             if(ok){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

       

        cout<< ans << "\n";


    }
   




return 0;    
}