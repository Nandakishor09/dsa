#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;

    for(int i = 0; i < n; i++){
        int start = intervals[i][0];
        int end = intervals[i][1];

        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }

        for(int j = i + 1; j < n; j++){
            if(intervals[j][0] <= end){
                end = max(end, intervals[j][1]);
            }else{
                break;
            }
        }
        ans.push_back({start, end});
    }

    return ans;
}

int main(){
    
    vector<vector<int>> arr = {{1,4},{4,5}};
    
    vector<vector<int>> ans = merge(arr);
    
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
