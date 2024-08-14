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

vector<int> find(Node* root,int val){
	if(!root) return {};
	if(!root->right && !root->left){
		vector<int>ans;
		if(root->val == val){
			ans.push_back(root->val);
		}
		return ans;
	}

	vector<int>left = find(root->left,val);
	if(left.size()>0){
		left.push_back(root->val);
		return left;
	}

	vector<int>right = find(root->right,val);
	if(right.size()>0){
		right.push_back(root->val);
		return right;
	}

	vector<int>list;
	if(root->val==val) list.push_back(root->val);

	return list;
}

bool find(Node* root,int val){
	if(!root) return false;
	if(root->val == val){
		path.push_back(root->val);
		return true;
	}

	bool left = find(root,val);
	if(left){
		path.push_back(root->val);
		return true;
	}

	bool right = find(root,val);
	if(right){
		path.push_back(root->val);
		return true;
	}

	return false;
}
signed main(){
	cin.tie(NULL); 
   




return 0;    
}