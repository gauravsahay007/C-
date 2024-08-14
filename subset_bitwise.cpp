#include <bits/stdc++.h>
using namespace std;

string overlaynumber(string s,int number){
    int j=0;
    string a="";
	while(number>0){
		if(number&1){
			
			a+=s[j];
		}
		j++;
		number=number>>1;
	}
	return a;
}
void subset(string s){
	int n=s.size();
	for(int i=0;i<(1<<n);i++){
		cout<<overlaynumber(s,i)<<endl;;
		
	}
}
int main(){
	string s="aab";
	subset(s);
	
   




return 0;    
}