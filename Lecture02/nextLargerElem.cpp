#include<bits/stdc++.h>

using namespace std;


vector<long long> nextLargerElement(vector<long long> arr, int n) {
    std::vector<long long> result(n);
    std::deque<std::pair<long long, int> > d;
    for (int i = 0; i < n; i++) {
        while (d.size() > 0 && arr[i] > d.back().first) {
            result[d.back().second] = arr[i];
            d.pop_back();
        }
        std::pair<long long, int> p(arr[i], i);
        d.push_back(p);
    }
    while (d.size() > 0) {
        result[d.front().second] = -1;
        d.pop_front();
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];


        vector<long long> res = nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}