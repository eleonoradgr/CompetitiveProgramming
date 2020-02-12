#include <iostream>
#include <vector>
#include <climits>
#include <stack>


using namespace std;

int preorderBST(vector<int> const &v) {
    int root = INT_MIN;
    stack<int> s;

    for (auto elem: v) {

        if (elem < root)
            return 0;

        while (!s.empty()) {
            if (elem < s.top()){
                s.pop();
            }else{
               root = s.top();
               break;
            }
        }

        s.push(elem);
    }

    return 1;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> v;
        v.reserve(n);
        for (int j = 0; j < n; ++j) {
            int aus;
            cin >> aus;
            v.push_back(aus);
        }
        cout << preorderBST(v) << endl;
        v.clear();
    }
    return 0;
}

