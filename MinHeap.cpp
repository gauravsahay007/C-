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

class minHeap{
    int *arr;
    int n;
    int capacity;

public:
    minHeap(int cap){
        n = 0;
        capacity = cap;
        arr = new int[cap];
    }

    int extractMin();
    void deleteKey(int i);
    void decreaseKey(int i,int x);
    void insertKey(int k);
    int parent(int i);
    int left(int i);
    int right(int i);

    void heapify(int i);

    void printHeap(){
        for(int i=0;i<n;i++){
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
};

int minHeap::parent(int i){
    return (i-1)/2;
}

int minHeap::left(int i){
    return (2*i + 1)/2;
}

int minHeap::right(int i){
    return (2*i + 2)/2;
}

void minHeap::insertKey(int k){
    if( n== capacity ) return;
    n++;
    arr[n-1] = k;
    while(i!=0 && arr[parent(i)] > arr[i]){
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }   
}

void heapify(int i){
    int li = left(i);
    int ri = right(i);

    int smallest = i;

    if(li < n && arr[smallest]>arr[li]){
        smallest = li;
    }
    if(ri < n && arr[smallest]>arr[ri]){
        smallest = ri;
    }

    if(smallest != i){
        swap(arr[i],arr[smallest]);
        heapify(smallest);
    }
}

int minHeap::extractMin(){
    if(n == 0) return -1;
    if(n == 1) {
        n--;
        return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[n-1];
    n--;
    heapify(0);
    return root;
}

void minHeap::decreaseKey(int i,int x){
    arr[i] = x;
    while(i!=0 && arr[parent(i)] > arr[i]){
        swap(arr[i],arr[parent(i)]);
        i = parent(i);
    }
}


void minHeap::deleteKey(int i){
    decreaseKey(i,INT_MIN);
    extractMin();
}

signed main(){
    cin.tie(NULL); 
   




return 0;    
}