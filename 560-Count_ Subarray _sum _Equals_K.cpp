#include <bits/stdc++.h>
using namespace std;

//better solution
/*int subarraySum(vector<int>& nums, int k) {
        
    int ans = 0;
    int n = nums.size();
    int sum = 0;

    for(int i = 0; i < n; i++){
        sum = nums[i];
        if(sum == k) {
            ans++;
        }
        for(int j = i + 1; j < n; j++){
            sum += nums[j];
            if(sum == k){
                ans++;
            }
        }
    }

    return ans;
}*/

//optimal solution
//logic -- prefix sum algo
//subArray = sum_till_i_index - previous_sums
int subarraySum(vector<int>& nums, int k){
    
    int preSum = 0, ans = 0;
    map<int,int> mpp;
    mpp[0] = 1;
    
    for(int i = 0; i < nums.size(); i++){
        preSum += nums[i];
        int reMove = preSum - k;
        ans += mpp[reMove];
        mpp[preSum] += 1;
    }
    
    return ans;
}

int main(){
    
    vector<int> arr = {1,1,1,};
    int k = 2;
    
    cout<<subarraySum(arr, k);
    
    return 0;
}
