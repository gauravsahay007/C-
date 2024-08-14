#include <bits/stdc++.h>
using namespace std;

void solve(){
   set<pair<int, int>> st;
    string s;
    cin >> s;
 
    string isBad;
    cin >> isBad;
 
    int k;
    cin >> k;
 
    int base[2] = { 53,127 };
    int MOD[2] = { 1000000007,1000000009 };
 
    int n = s.length();
 
    for (int i = 0;i < n;i++)
    {
        int hash[2] = { 0,0 };
        int pw[2] = { 1,1 };
        int nb = 0;
        for (int j = i;j < n;j++)
        {
            if (isBad[s[j] - 'a'] == '0')
                nb++;
            if (nb > k)
                break;
            for (int l = 0;l < 2;l++)
            {
                hash[l] = (hash[l] + s[j] * pw[l]) % MOD[l] ;
                pw[l] = (pw[l] * base[l]) % MOD[l];
            }
           
            st.insert({ hash[0],hash[1] });
        }
    }
    
    cout << st.size() << "\n";
}
int main(){
    solve();
   




return 0;    
}