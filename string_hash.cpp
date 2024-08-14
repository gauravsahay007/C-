#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

// if h = 1e9 then h*31 > int so long long taken
long long get_hash(string s){
     long long h=0;
     for(char c: s) h = (h * 31 +  (c - 'a' + 1)) % MOD;
     return h;
}

int main(){
     cout<<get_hash("ab")<<endl;
     cout<< (get_hash("ab") == get_hash("sab"));
     return 0;
     }

     // dbc
     // h = 0
     // h = 0*31 + 4 = 4;
     // h = 4*31 +2 = 126;
     // h = 126*31 + 3;