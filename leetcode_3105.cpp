#include <bits/stdc++.h>
using namespace std;

int longestMonotonicSubarray(vector<int>& nums) {
    int ans = 0, count = 1;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] > nums[i - 1]){
            count++;
        }else{
            ans = max(count, ans);
            count = 1;
        }
    }
    ans = max(count, ans);
    int ans2 = 0, count2 = 1;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] < nums[i - 1]){
            count2++;
        }else{
            ans2 = max(count2, ans2);
            count2 = 1;
        }
    }
    ans2 = max(count2, ans2);

    return max(ans, ans2);
}

int main(){
    vector<int> arr = {3, 2, 1};
    cout<<longestMonotonicSubarray(arr);

    return 0;
}