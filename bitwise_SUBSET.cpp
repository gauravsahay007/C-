#include <bits/stdc++.h>
using namespace std;

int main(){
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   bool p=false;
   for(int i=0;i<(1<<n);i++){
    int sum=0;
    for(int j=0;j<n;j++){
        if(i&(1<<j)){
            sum+=a[j];
        }
        else{
            sum-=a[j];
        }
    }
    if(sum%360==0){
        p=true;
        break;
    }

   }
   if(p==true) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;




return 0;    
}