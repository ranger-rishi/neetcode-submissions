#include <iostream>
class Solution {
public:
    bool isPalindrome(string s) {
        // s=tolower(s);
        string s1="";
        for(int i = 0 ;i<s.size();i++)
        {
            if(iswalnum(s[i])) /// is walnum(ch) checks for alphanumeric characters
            s1+=tolower(s[i]);
        }
        string s2="";
        for(int i=0;i<s1.size();i++)
        {
            s2=s1[i]+s2;
        }
        return s1==s2;
    }
};
