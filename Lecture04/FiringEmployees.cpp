#include <iostream>
#include <vector>

using namespace std;


vector<bool> SieveOfEratosthenes( int n ){
    vector<bool> result(n+1,true);
    result[0]=result[1]=false;

    //for each element marked as prime detect his multiples
    for (int p = 2; p*p <= n; p++ ){
        if (result[p]){
            for (int r = p*p; r <= n; r +=p ){
                result[r] = false;
            }
        }
    }
    return result;
}

int getNumberOfManagers(vector<pair<int, int>> &employees, int i) {
        if (employees[i].first == 0 and employees[i].second == -1){
            employees[i].second = 0;
        }
        if (employees[i].second == -1) {
            employees[i].second = getNumberOfManagers(employees, employees[i].first - 1) + 1;
        }
    return employees[i].second;
}

vector<int> firingEmployees(vector<pair<int,int>> &employees){

    int n = employees.size();
    vector<bool> primeNumbers = SieveOfEratosthenes(n*2);
    vector<int> result;
    result.reserve(n/2);

    for (int i = 0; i < employees.size(); i++){
        if (employees[i].second == -1){
            employees[i].second = getNumberOfManagers(employees, i);
        }

        int sum = i + employees[i].second +1 ;
        if (primeNumbers[sum] && employees[i].first != 0 )
            result.push_back(i);
    }
    return result;
}



int main(){

    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        int rank;
        cin >> n;
        // The first value represent the rank of direct manager
        // The second one represent the number of total manager
        vector<pair<int, int>> employees (n, make_pair(-1, -1));
        for (int j = 0; j < n; j++){
            cin >> rank;
            employees[j].first =rank;
        }
        vector<int> firingemp = firingEmployees(employees);
        cout << firingemp.size() << std::endl;
        firingemp.clear();
    }
    return 0;
}