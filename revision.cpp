#include <bits/stdc++.h>
using namespace std;

int main(){
	//***********PRIORITY QUEUE***********
   priority_queue<int>heap;//declaration 
   heap.push(x);//pushing elements
   heap.top();//extracting the top element
   heap.pop();//poping out the last elememt

   
   //To Get the elements in reverse order :
   priority_queue<int,vector<int>,greater<int>>heap; //provide 2 more parameters

   //prioirity queue of pairs:
   priority_queue<pair<int,int>> p;

   //In reverse Order:
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pr;


    //***********BIT MANUPULATION***********

    //Functions:

   int Isodd(int x){
   	if(x&1) return 1;

   	else return 0;
   }

   int getithBit(int x,int i){
   	int mask=1<<i;
   	if(mask&x) return 1;
   	else return 0;
   }

   int setithBit(int x,int i){
   	int mask=1<<i;
   	x=x|mask;
   	return x;
   }

   int clearithBit(int &x,int i){
   	int mask=~(1<<i);
   	x=(x&mask)&x;
   	return xl
   }

   int updateithbit(int &x,int i,int v){
   	clearithBit(x,i);
   	int mask=~(1<<i);
   	x=(x&mask)|(v<<i);
   	return x;
   }

   int clearlastibits(int &x,int i){
   	int mask=(~0)<<i;
   	x=x&mask;
   	return x;
   }

   int clearrangebits(int &x,int i,int j){
   	int a=(2<<i)-1; // 00000111
   	int b=(~0)<<j+1;// 11100000
   	int mask=a|b;   // 11100111
   	x=x&mask;
   	return x;
   }

   
int countsetbits(int x){
        int ct=0;
        int i=0;
        while(x>0){
            
            if(x&1) ct++;
             x=x>>1;
          
        }
      return ct;
   }

int convertTobinary(int x){
	int ans=0;
	int p=1;
	while(x>0){
		ans=ans+(x&1)*p;
		x=x>>1;
		p=p*10;
	}
	return ans;
}

//Subset Generation Using Bit Manupulation:
void overlaynumber(string s,int number){
    int j=0;
    while(number>0){
        if(number&1) cout<<s[j];
        j++;
        number=number>>1;
    }
}

void subset(string s){
    int n=s.size();
    for(int i=0;i<(1<<n);i++){
        overlaynumber(s,i);
        cout<<" ";
    }
}

//Unique 2N+1
int arr[7]={1,2,1,9,2,5,5};
int n=sizeof(arr)/sizeof(arr[0]);
int cxor=arr[0];
for(int i=1;i<n;i++){
	cxor=cxor^arr[i];
}
cout<<cxor<<endl;

//Unique 2N+2
int arr[8]={1,2,1,2,3,3,9};
int n=sizeof(arr)/sizeof(arr[0]);
int cxor=0;;
for(int i=0;i<n;i++){
	cxor=cxor^arr[i];
}
int pos=0;
while((cxor&1)==0){
     pos++;
     cxor>>1;
}

int setA=0;
int setB=0;

for(int i=0;i<n;i++){
	if(arr[i]&(1<<pos)){
		setA=setA^arr[i];
	}
	else{
		setB=setB^arr[i];
	}
}

cout<<setA<<" "<<setB<<endl;

//3N+1
void updateArr(vector<int> &v,int x){
	for(int i=0;i<32;i++){
		int ithbit=x&(1<<i);
		if(ithbit){
			v[i]++;
		}
	}
}

 int numfrombit(vector<int>sumArr){
	int v=0;
	int p=1;
	for(int i=0;i<32;i++){
         v+=sumArr[i]*(1<<i);
         
	}
	return v;
}
int  uniqueno3(vector<int>arr){
	vector<int> sumArr(32,0);

	for(int i=0;i<arr.size();i++){
		updateArr(sumArr,arr[i]);
	}

	for(int i=0;i<32;i++){
		sumArr[i]=sumArr[i]%3;
	}
	return numfrombit(sumArr);
}
return 0;    
}