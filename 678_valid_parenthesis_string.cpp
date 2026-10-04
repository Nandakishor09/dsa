#include <bits/stdc++.h>
using namespace std;

/*bool checkValidString(string s) {
    int open = 0;
    int closed = 0;
    int star = 0;

    for(char ch : s){
        if(ch == '(')
            open++;
        else if(ch == ')')
            closed++;
        else
            star++;
    }
    cout<<open<<" "<<closed<<" "<<star<<endl;
    if(open == closed)
        return true;
    else if(open < closed){
        open += star;
        if(open >= closed){
            return true;
        }else{
            return false;
        }
    }
    else if(closed < open){
        closed += star;
        if(closed >= open){
            return true;
        }
    }
    
    return false;
}*/

/*bool checkValidString(string s){
    stack<char> st;
    int count = 0;
    int len = s.size();

    for(char ch : s){
        if(ch == '('){
            st.push(ch);
            count++;
        }
        else if(ch == ')'){
            st.pop();
        }else{
            count++;
            int mid = len - count;
            if(mid >= count){
                st.push('(');
            }
        }
    }
    if(st.empty())
        return true;
    return false;
}*/

//Correct Solution...
bool checkValidString(string s){
    stack<int> open;
    stack<int> star;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            open.push(i);
        }
        else if(s[i] == '*') {
            star.push(i);
        }
        else {
            if(!open.empty()) {
                open.pop();
            }
            else if(!star.empty()) {
                star.pop();
            }
            else {
                return false;
            }
        }
    }

    while(!open.empty() && !star.empty()) {
        if(open.top() > star.top())
            return false;

        open.pop();
        star.pop();
    }

    return open.empty();
}

int main(){
    string s = "(((((()*)(*)*))())())(()())())))((**)))))(()())()";

    cout<<checkValidString(s);

    return 0;
}