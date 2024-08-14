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

signed main(){
	cin.tie(NULL); 
   // Number of ways to divide set of n numbers into m nonempty sets is called Stirling number
   // S(n,1) = S(n,n) = 1;

	// S(n,k) =  total number of partitions of n elements into k sets
    // S(n+1,k) = k*S(n,k) + S(n,k-1)

	// How does above recursive formula work? 
	// When we add a (n+1)’th element to k partitions, there are two possibilities. 
	// 1) It is added as a single element set to existing partitions, i.e, S(n, k-1) 
	// 2) It is added to all sets of every partition, i.e., k*S(n, k)
	// S(n, k) is called Stirling numbers of the second kind
	// First few Bell numbers are 1, 1, 2, 5, 15, 52, 203, …. 
	int n ;
	cin>>n;
	vector<vector<int>>S(n+1,vector<int>(n+1));

	for(int i=0;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j>i) S[i][j]=0;
			if(j==1) S[i][j]=1;
			else{
				S[i][j] = j*S[i][j] + S[i][j-1];
			}
		}
	}

	int ans = 0;
	for(int i=1;i<=n;i++){
		ans+=S[n][1];
	}

	return ans;




return 0;    
}