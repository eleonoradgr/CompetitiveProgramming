#include<bits/stdc++.h>
using namespace std;

// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n){
    int max = std::numeric_limits<int>::min();
    int sum = 0;
    for (int i = 0; i<n; ++i) {

        if (sum >= 0)
            sum += arr[i];
        else
            sum = arr[i];

        if (sum > max)
            max = sum;
    }
    return max;
}

int main()
{
    int t,n;

    cin>>t; //input testcases
    while(t--) //while testcases exist
    {

        cin>>n; //input size of array

        int a[n];

        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array

        cout << maxSubarraySum(a, n) << endl;
    }
}