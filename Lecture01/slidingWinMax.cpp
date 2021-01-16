#include <bits/stdc++.h>

using namespace std;

vector<int> max_of_subarrays(int *arr, int n, int k) {
    std::vector<int> res;
    res.reserve(n - k + 1);
    std::deque<std::pair<int, int> > d;
    for (int i = 0; i < n; i++) {

        if (d.size() > 0) {

            if (i - d.front().second >= k) {
                d.pop_front();
            }
            while (d.size() > 0 && arr[i] > d.back().first) {
                d.pop_back();
            }
        }

        std::pair<int, int> p(arr[i], i);
        d.push_back(p);

        if (i >= k - 1) {
            res.push_back(d.front().first);
        }
    }
    return res;
}

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<int> res = max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;

    }

    return 0;
}