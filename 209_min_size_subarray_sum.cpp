#include <bits/stdc++.h>
using namespace std;

//wont work....

/*int minSubArrayLen(int target, vector<int> nums) {
    int left = 0;
    int right = 1;

    int ans = 0;
    int sum = nums[0];

    if(nums[0] == target )
        return 1;
    while(right < nums.size()){
        if(nums[right] == target)
            return 1;
        if(nums[left] == target)
            return 1;

        sum += nums[right];

        if(sum == target){
            if(ans == 0){
                ans = (right - left) + 1;
            }
            else if((right - left) + 1 < ans){
                ans = (right - left) + 1;
            }
            
            left = right + 1;
            sum = nums[left];
            right = right + 2;
        }
        else if(sum > target){
            sum = sum - nums[left];
            left++;
        }
        else if(sum < target){
            right++;
        }
    }

    return ans;
}*/

int minSubArrayLen(int target, vector<int> nums) {
    int left = 0;
    int sum = 0;
    int mini = INT_MAX;

    for(int right = 0; right < nums.size(); right++){
        sum += nums[right];

        while(sum >= target){
            mini = min(mini, (right - left) + 1);
            sum -= nums[left];
            left++;
        }
    }

    return mini == INT_MAX ? 0 : mini;
}

int main(){
    vector<int> arr = {2, 3, 1, 2, 4, 3};
    int target = 7;

    cout<<minSubArrayLen(target, arr);

    return 0;
}