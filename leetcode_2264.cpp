#include <bits/stdc++.h>
using namespace std;

string largestGoodInteger(string num) {
    int ans = 0;
    string s = "";
    int len = num.size();

    if(len == 3){
        if(num[0] == num[1] && num[0]== num[2]){
            return num;
        }else{
            return "";
        }
    }
    for(int i = 0; i < len - 2; i++){
        if(num[i] == num[i + 1] && num[i] == num[i + 2]){
            int no = num[i] - 48;
            int n = (no * 100) + (no * 10) + no;
            string temp = "";
            temp += num[i];
            temp += num[i];
            temp += num[i];
            if(n >= ans){
                ans = n;
                s = temp;
            } 
        }
    }
    return s;
}

int main(){
    string s = "6777133339";
    cout<<largestGoodInteger(s)<<endl;

    return 0;
}