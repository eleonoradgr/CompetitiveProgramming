//
// Created by eleonora on 23/11/20.
//
class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for (int i = 0; i<N; ++i){
            sum += arr[i];
        }




        if(sum%2 == 0){
            bool a[N + 1][sum + 1];

            for (int i = 0; i <= N; i++)
                a[i][0] = true;

            for (int i = 1; i <= sum; i++)
                a[0][i] = false;

            for(int i = 1; i <= N; ++i){
                for(int j = 1; j <= sum; ++j){

                    if(arr[i-1] <= j){
                        a[i][j] = a[i-1][j-arr[i-1]] || a[i-1][j];
                    }else{
                        a[i][j] = a[i-1][j];
                    }
                    //std::cout << i<< " " << j <<" " << a[i][j] <<std::endl;
                }

            }
            int half = sum/2;

            if(a[N][half]){
                return 1;
            }else{
                return 0;
            }
        }else{
            return 0;
        }


    }
};