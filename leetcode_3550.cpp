#include <bits/stdc++.h>
using namespace std;

int smallestIndex(vector<int>& nums) {
    vector<int> ans;
    for(int i = 0; i < nums.size(); i++){
        int num = nums[i];
        int sum = 0;
        while(num != 0){
            int mod = num % 10;
            sum += mod;
            num = num / 10;
        }
        if(sum == i){
            ans.push_back(i);
        }
    }
    if(ans.empty()){
        return -1;
    }
    return ans[0];
}

int main(){
    vector<int> arr = {1, 2, 3};
    cout<<smallestIndex(arr);

    return 0;
}