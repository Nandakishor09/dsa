#include <bits/stdc++.h>
using namespace std;

/*int findMin(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++){
        if(i == nums.size() - 1){
            break;
        }
        else if(nums[i] > nums[i + 1]){
            return nums[i + 1];
        }
    }
    return nums[0];
}

int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    if(nums.size() == 1)
        return nums[0];
    while(left <= right){
        if(nums[left] > nums[left + 1]){
            return nums[left + 1];
        }
        else if(nums[right] < nums[right - 1]){
            return nums[right];
        }
        left++;
        right--;
    }

    return nums[0];
}*/

int findMin(vector<int> nums) {
    int left = 0;
    int right = nums.size() - 1;

    while(left < right){
        int mid = (right + left) / 2;
        if(nums[mid] > nums[right]){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }

    return nums[left];
}
int main(){
    vector<int> arr = {3, 4, 5, 1, 2};

    cout<<findMin(arr);

    return 0;
}