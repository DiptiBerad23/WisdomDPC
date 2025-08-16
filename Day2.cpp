/*Problem : Find the Missing Number
You are given an array arr containing n-1 distinct integers.
The array consists of integers taken from the range 1 to n,
meaning one integer is missing from this sequence. 
Your task is to find the missing integer.*/


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout<<"Enter value of n:";
    cin >> n;

    vector<int> arr(n - 1);
    long long sum = 0;
    cout<<"Enter array elements:";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    long long total = 1LL * n * (n + 1) / 2;
    cout <<"Missing number is: "<<(total - sum);
    return 0;
}
