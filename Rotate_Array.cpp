#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to sort based on remainders
vector<int> sortByRemainder(const vector<int>& arr, int X) {
    int n = arr.size();
    vector<pair<int, int>> remainderPairs;
    for (int i = 0; i < n; ++i) {
        remainderPairs.push_back({arr[i] % X, i});
    }
    
    // Custom insertion sort to maintain stability
    for (int i = 1; i < n; ++i) {
        pair<int, int> key = remainderPairs[i];
        int j = i - 1;
        while (j >= 0 && 
            (remainderPairs[j].first > key.first ||
                         (remainderPairs[j].first == key.first && remainderPairs[j].second > key.second))) {
            remainderPairs[j + 1] = remainderPairs[j];
            --j;
        }
        remainderPairs[j + 1] = key;
    }
    
    // Generate the sorted array based on the remainder
    vector<int> sortedArr;
    for (int i = 0; i < n; ++i) {
        sortedArr.push_back(arr[remainderPairs[i].second]);
    }
    
    return sortedArr;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    vector<vector<int>> result;
    for (int i = 1; pow(10, i) <= K; ++i) {
        int X = pow(10, i);
        vector<int> sortedArr = sortByRemainder(arr, X);
        result.push_back(sortedArr);
    }

    for (const auto& sortedArr : result) {
        for (int num : sortedArr) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
