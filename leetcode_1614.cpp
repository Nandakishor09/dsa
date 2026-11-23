#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
    stack<char> st;
    vector<int> arr;
    int index = 0, ans = 0, count = 0;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            st.push(s[i]);
            count = 0;
        }
        else if(s[i] == ')'){
            st.pop();
            if(!st.empty()){
                count = 0;
            }else{
                arr.push_back(count);
                ans = max(ans, count);
                count = 0;
            }
        }else{
            count++;
        }
    }
    sort(arr.begin(), arr.end());

    return arr[arr.size() - 1];
}

int main(){
    string s = "(1+(2*3)+((8)/4))+1";

    cout<<maxDepth(s)<<endl;

    return 0;
}
