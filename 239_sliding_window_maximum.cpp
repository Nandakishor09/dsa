#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; //stores indices
    vector<int> ans;

    for(int i = 0; i < nums.size(); i++){
        //Remove indices outside the window
        while(!dq.empty() && dq.front() <= i - k){
            dq.pop_front();
        }
        //Remove smaller or equal values
        while(!dq.empty() && nums[dq.back()] <= nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        //Record maximum when window is full
        if(i >= k - 1){
            ans.push_back(nums[dq.front()]);
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(arr, k);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}