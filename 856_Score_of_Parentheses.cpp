#include <bits/stdc++.h>
using namespace std;

int scoreOfParentheses(string s) {
    stack<int> st;
    int score = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            st.push(score);
            score = 0;
        }else{
            score = st.top() + max(score * 2, 1);
            st.pop();
        }
    }

    return score;
}

int main(){
    string s = "(())";
    cout<<scoreOfParentheses(s)<<endl;

    return 0;
}
