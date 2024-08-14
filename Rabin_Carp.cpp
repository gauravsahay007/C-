#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

// if h = 1e9 then h*31 > int so long long taken
long long get_hash(string s){
     long long h=0;
     for(char c: s) h = ((h * 31 +  (c - 'a' + 1)) % MOD);
     return h;
}

vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 

    // powers of 31 will be used till size of T
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

     for(auto it:p_pow){
      cout<<it<<" ";
     }
     cout<<endl;

    // substring hash for t
    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 

     for(auto it:h){
      cout<<it<<" ";
     }
     cout<<endl;

     // hash for s(small string)
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

     // finding occurences of s in t
    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) { 

      // +m is to avoid negative numbers
        long long cur_h = (h[i+S] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }

  long long cur_h = (h[T]-h[T-1]);
  long long j=(h[2]-h[1])*31*31;
  cout<<j<<" ";
  cout<<cur_h; 
       
    return occurences;
}


int main(){
   string s;
   cin>>s;
   string p;
   cin>>p;
   vector<int>ans=rabin_karp(p,s);
   int ct=ans.size();
   cout<<endl;
   for(auto it:ans){
      cout<<it<<" ";
   }

   cout<<ct<<endl;
   
return 0;    
}