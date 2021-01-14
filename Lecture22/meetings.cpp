//
// Created by eleonora on 14/01/21.
//
#include <bits/stdc++.h>

using namespace std;

int maxMeetings(int *, int *, int);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        int ans = maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}// } Driver Code Ends


struct meet{
    int s;
    int e;
    meet(int start, int end):s(start),e(end){}
};

int maxMeetings(int start[], int end[], int n) {
    std::vector<meet> meetings;
    meetings.reserve(n);
    int result = 0;
    int last = -1;
    for(int i = 0; i<n; ++i){
        meetings.push_back(meet(start[i],end[i]));
    }
    std::sort(meetings.begin(), meetings.end(),[&](meet &i,meet &j){return i.e<j.e;});
    for(int i = 0; i<n; ++i){
        if(meetings[i].s > last){
            result++;
            last = meetings[i].e;
        }
    }
    return result;
}
