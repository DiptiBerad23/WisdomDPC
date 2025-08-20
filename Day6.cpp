#include <iostream>
#include <vector>
using namespace std;

vector<int> findLeaders(vector<int>& arr, int n) {
    vector<int> leaders(n);
    int idx = 0;
    int max_from_right = arr[n-1];
    leaders[idx++] = max_from_right;

    for (int i = n-2; i >= 0; i--) {
        if (arr[i] > max_from_right) {
            leaders[idx++] = arr[i];
            max_from_right = arr[i];
        }
    }

    vector<int> result;
    for (int i = idx-1; i >= 0; i--) {
        result.push_back(leaders[i]);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> leaders = findLeaders(arr, n);

    for (int x : leaders) cout << x << " ";
    cout << endl;
    return 0;
}
