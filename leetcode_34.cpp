#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
        
    int left = 0;
    int right = nums.size() - 1; 
    int check = 0;
    vector<int> ans;

    while(left <= right){
        int mid = (left + right) / 2;
        if(nums[mid] > target){
            right = mid - 1;
        }
        if(nums[mid] < target){
            left = mid + 1;
        }
        if(nums[mid] == target){
            check = 1;
            if(nums.size() == 1){
                ans.push_back(mid);
                ans.push_back(mid);
                break;
            }
            ans.push_back(mid);
            int low = mid - 1;
            int high = mid + 1;
                
            if(low >= 0){
                while(nums[low] == target){
                    ans.push_back(low);
                    low--;
                    if(low < 0) break;
                }
            }
            if(high <= nums.size() - 1){
                while(nums[high] == target){
                    ans.push_back(high);
                    high++;
                    if(high >= nums.size()) break;
                }
            }
            if(ans.size() == 1){
                ans.push_back(ans[0]);
                break;
            }
            sort(ans.begin(), ans.end());
            if(ans.size() > 2){
                vector<int> fin;
                fin.push_back(ans[0]);
                fin.push_back(ans[ans.size() - 1]);
                return fin;
            }
            break;
        }
    }
        
    if(check == 1) return ans;
    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
}

int main(){
    
    vector<int> arr = {1,3};
    int target = 1;
    
    vector<int> res = searchRange(arr, target);
    for(int num : res)
        cout<<num<<" ";
    
    return 0;
}
