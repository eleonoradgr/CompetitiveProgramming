#include<bits/stdc++.h>

using namespace std;

// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int trappingWater(int arr[], int n) {

    std::vector<int> vMaxl;
    std::vector<int> vMaxr;
    std::vector<int> res;
    vMaxl.reserve(n);
    vMaxr.reserve(n);
    res.reserve(n);
    int max = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            vMaxl[i] = arr[i];
        } else {
            vMaxl[i] = max;
        }
    }
    max = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > max) {
            max = arr[i];
            vMaxr[i] = arr[i];
        } else {
            vMaxr[i] = max;
        }
    }

    for (int i = 0; i < n; i++) {
        sum += ((vMaxl[i] - vMaxr[i] < 0) ? vMaxl[i] : vMaxr[i]) - arr[i];
    }
    return sum;


}

int main() {

    int t;
    //testcases
    cin >> t;

    while (t--) {
        int n;

        //size of array
        cin >> n;

        int a[n];

        //adding elements to the array
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        //calling trappingWater() function
        cout << trappingWater(a, n) << endl;

    }

    return 0;
}