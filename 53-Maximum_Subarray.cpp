#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxi = 0;
    int len = nums.size();
    if(len == 1) return nums[0];
    for(int i = 0; i < len; i++){
        int sum = nums[i];
        for(int j = i + 1; j < len; j++){
            sum += nums[j];
            maxi = max(maxi, sum);
        }
        maxi = max(maxi, sum);
    }
    return maxi;
}

int main(){
    vector<int> nums = {-2,1};
    cout<<"Maximum Sum: "<<maxSubArray(nums)<<endl;

    return 0;
}