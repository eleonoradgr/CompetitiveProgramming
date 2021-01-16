#include <bits/stdc++.h>

using namespace std;

vector<int> leaders(int a[], int n) {
    std::vector<int> leaders;
    leaders.reserve(n);
    int max = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] >= max) {
            leaders.emplace_back(a[i]);
            max = a[i];
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    long long t;
    cin >> t;//testcases
    while (t--) {
        long long n;
        cin >> n;//total size of array

        int a[n];

        //inserting elements in the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        //calling leaders() function
        vector<int> v = leaders(a, n);

        //printing elements of the vector
        for (auto it = v.begin(); it != v.end(); it++) {
            cout << *it << " ";
        }

        cout << endl;

    }
}