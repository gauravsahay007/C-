#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll circularSubarraySum(int arr[],int n){
	ll curr_sum=0;
	ll min_sum=0;
	ll total_sum=0;
	for(ll i=0;i<n;i++){
		total_sum+=arr[i];
		curr_sum+=arr[i];
		min_sum=min(min_sum,curr_sum);
		if(curr_sum>0){
			curr_sum=0;
		}

	}

	curr_sum=0;
	ll max_sum=INT_MIN;
	for(ll i=0;i<n;i++){
		curr_sum+=arr[i];
		max_sum=max(max_sum,curr_sum);
		if(curr_sum<0){
			curr_sum=0;
		}
	}

	if(max_sum<0) return max_sum;

	return max(total_sum-min_sum, max_sum);

}
int main(){
   




return 0;    
}