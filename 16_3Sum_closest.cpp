#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int ans = nums[0] + nums[1] + nums[2];

    for(int i = 0; i < nums.size() - 2; i++){

        int left = i + 1;
        int right = nums.size() - 1;

        while(left < right){

            int sum = nums[i] + nums[left] + nums[right];

            if(abs(target - sum) < abs(target - ans)){
                ans = sum;
            }

            if(sum < target){
                left++;
            }
            else if(sum > target){
                right--;
            }
            else{
                return sum;
            }
        }
    }

    return ans;
}

int main(){
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    cout<<"Closest 3: "<<threeSumClosest(nums, target)<<endl;

    return 0;
}