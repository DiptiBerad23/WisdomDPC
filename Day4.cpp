#include <iostream>
#include <vector>
using namespace std;

int nextGap(int gap) {
    if (gap <= 1) return 0;
    return (gap / 2) + (gap % 2);
}

void mergeArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int gap = m + n;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
        int i, j;
        for (i = 0; i + gap < m; i++) {
            if (arr1[i] > arr1[i + gap]) {
                swap(arr1[i], arr1[i + gap]);
            }
        }
        for (j = (gap > m ? gap - m : 0); i < m && j < n; i++, j++) {
            if (arr1[i] > arr2[j]) {
                swap(arr1[i], arr2[j]);
            }
        }
        if (j < n) {
            for (j = 0; j + gap < n; j++) {
                if (arr2[j] > arr2[j + gap]) {
                    swap(arr2[j], arr2[j + gap]);
                }
            }
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> arr1(m), arr2(n);
    for (int i = 0; i < m; i++) cin >> arr1[i];
    for (int i = 0; i < n; i++) cin >> arr2[i];
    mergeArrays(arr1, arr2, m, n);
    for (int i = 0; i < m; i++) cout << arr1[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << endl;
    return 0;
}
