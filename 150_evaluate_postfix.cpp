#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;

    for(int i = 0; i < tokens.size(); i++){
        string ope = tokens[i];
        if(ope == "+" || ope == "-" || ope == "*" || ope == "/"){
            int s1 = st.top();
            st.pop();
            int s2 = st.top();
            st.pop();
            if(ope == "+"){
                st.push(s1 + s2);
            }
            else if(ope == "-"){
                st.push(s2 - s1);
            }
            else if(ope == "*"){
                st.push(s1 * s2);
            }
            else if(ope == "/"){
                st.push(s2 / s1);
            }
        }
        else if(ope != "(" && ope != ")"){
            st.push(stoi(tokens[i]));
        }
    }
    return st.top();
}

int main(){
    vector<string> s = {"2","1","+","3","*"};
    cout<<evalRPN(s)<<endl;

    return 0;
}