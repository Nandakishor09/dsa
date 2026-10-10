#include <bits/stdc++.h>
using namespace std;

wrong ans.....
/*long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
    int len = nums1.size();
    vector<long long> diffs;

    for(int i = 0; i < len; i++){
    long long num = nums1[i] - nums2[i];
    if(num < 0)
        num = -num;
        diffs.push_back(num);
    }
    sort(diffs.begin(), diffs.end());
    long long ans = 0;

    long long times = k1 + k2;
    int cnt = 0;
    len--;
    while(len >= 0){
        if(cnt < times){
            diffs[len]--;
            cnt++;
        }
        ans += pow(diffs[len], 2);
        len--;
    }
    return ans;
}
*/
logic still in progress.....
long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
    int len = nums1.size();
    vector<long long> diffs;

    for(int i = 0; i < len; i++){
        long long num = nums1[i] - nums2[i];
        if(num < 0){
            num = -num;
        }
        diffs.push_back(num);
    }
    sort(diffs.begin(), diffs.end());
    for(int i = 0; i < len; i++){
        cout<<diffs[i]<<" ";
    }
    cout<<endl;

    long long ans = 0;
    long long times = k1 + k2;

    int cnt = 0;
    len--;
    while(len >= 0){
        if(diffs[len] == 0){
            continue;
        }
        else if(cnt < times){
            diffs[len]--;
            cnt++;
        }
        ans += pow(diffs[len], 2);
        len--;
    }

    int i = 0;
    int length = diffs.size();
    if(cnt < times){
        
    }
    return ans;
}

int main(){
    vector<int> nums1 = {1,4,10,12};
    vector<int> nums2 = {5,8,6,9};
    int k1 = 10;
    int k2 = 5;

    cout<<minSumSquareDiff(nums1, nums2, k1, k2)<<endl;

    return 0;
}