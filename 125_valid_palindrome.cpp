#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;
    int flag = 0;

    if(s[0] == ' ' && s.size() == 1) return true;
    if(s.size() == 1) return true;
    while(left < right){
        char leftChar = tolower(s[left]);
        char rightChar = tolower(s[right]);

        if((leftChar >= 97 && leftChar <= 122 && rightChar >= 97 && rightChar <= 122)
            || (leftChar >= 48 && leftChar <= 57 && rightChar >= 48 && rightChar <= 57)
            || (leftChar >= 97 && leftChar <= 122 && rightChar >= 48 && rightChar <= 57)
            || (leftChar >= 48 && leftChar <= 57 && rightChar >= 97 && rightChar <= 122)){
            flag++;
            if(leftChar == rightChar){
                left++;
                right--;
            }else{
                return false;
            }
        }
        if(!(leftChar >= 97 && leftChar <= 122) && !(leftChar >= 48 && leftChar <= 57))
            left++;
        if(!(rightChar >= 97 && rightChar <= 122) && !(rightChar >= 48 && rightChar <= 57))
            right--;
    }
    if(flag == 0 || flag >= 1)
        return true;

    return false;
}

int main(){
    string s = "A man, a plan, a canal: Panama";
    if(isPalindrome(s))
        cout<<"True";
    else
        cout<<"False";

    return 0;
}