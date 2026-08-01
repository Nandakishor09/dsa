#include <bits/stdc++.h>
using namespace std;

void recurPermute(vector<int> &ds, vector<int> &arr, vector<vector<int>> &ans, int freq[]){
    
    if(ds.size() == arr.size()){
        ans.push_back(ds);
        return;
    }
    
    for(int i = 0; i < arr.size(); i++){
        if(!freq[i]){
            ds.push_back(arr[i]);
            freq[i] = 1;
            recurPermute(ds, arr, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &arr){
    
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[arr.size()] = {0};
    recurPermute(ds, arr, ans, freq);
    return ans;
}
int main(){
    
    vector<int> arr = {1,2,3};
    
    vector<vector<int>> ans = permute(arr);
    
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
