//
// Created by eleonora on 24/11/20.
//
int minJumps(int arr[], int n){
    // Your code here
    int b[n] = {0};
    int max = 0;

    for(int i = 0; i < n-1; ++i){
        if (i == 0 || b[i] > 0){
            int j = (max < i+1)? i+1 : max;
            while(j < n && j <= i+arr[i]){
                if (b[j] == 0){
                    b[j] = b[i]+1;
                }else{
                    b[j] = std::min(b[j],b[i]+1);
                }
                max = j;
                ++j;
            }
        }
    }

    int res = (b[n-1] == 0)? -1 : b[n-1];
    return res;
}