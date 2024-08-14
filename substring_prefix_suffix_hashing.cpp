#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
#define pb push_back

int f(int ind, vector<int>& b, int p, int x) {
    if (ind == b.size()) {
        if (x != p) return 1;
        else return INT_MIN;
    }

    int a = 1 + f(ind + 1, b, p, x ^ b[ind]);
    int q = f(ind + 1, b, p, x);

    return max(a, q);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n);
        vector<int> b(n);
        set<int> s;
        int p = 0;
        for (int i = 0; i < n; i++) {
            int m;
            cin >> m;
            int x = 0;
            for (int j = 0; j < m; j++) {
                int num;
                cin >> num;
                if (s.find(num) == s.end()) {
                    s.insert(num);
                    p ^= num;
                    x ^= num;
                }
                a[i].push_back(num);
            }
            b[i] = x;
        }

        cout << f(0, b, p, 0) << endl;
    }

    return 0;
}
