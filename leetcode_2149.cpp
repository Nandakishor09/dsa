#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
        
    int n = nums.size();
    vector<int> ans(n);

    int positive = 0;
    int negative = 1;

    for(int i = 0; i < n; i++){
        if(nums[i] > 0){
            ans[positive] = nums[i];
            positive += 2;
        }
        else if(nums[i] < 0){
            ans[negative] = nums[i];
            negative += 2;
        }
    }

    return ans;
}

int main(){
    
    vector<int> arr = {3,1,-2,-5,2,-4};
    
    vector<int> ans = rearrangeArray(arr);
    
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}
