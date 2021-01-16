#include <bits/stdc++.h>

using namespace std;

int MissingNumber(vector<int> &array, int n);


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];

        cout << MissingNumber(array, n) << "\n";
    }
    return 0;
}

int MissingNumber(vector<int> &array, int n) {
    unsigned int sum = 1;
    unsigned int result = array[0];
    //xor all the element from 1 to n
    for (int j = 2; j <= n; ++j) {
        sum = sum ^ j;
    }
    //xor all the element of the sequence
    for (int j = 1; j < n - 1; ++j) {
        result = result ^ array[j];
    }
    return (int) result ^ sum;
}