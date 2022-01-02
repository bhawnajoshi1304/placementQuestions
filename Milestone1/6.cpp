// Given two strings str1 and str2. We say that str2 divides str1 if it's possible to concatenate multiple str2 to get str1. For example, ab divides abab. If str2 does not divide str1, return -1. Otherwise, return the smallest string str3 such that str3 divides both str1 and str2.
// https://leetcode.com/problems/greatest-common-divisor-of-strings/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1==str2) return str1;
        if(str1.size()==str2.size()) return "";
        else if(str1.size()>str2.size()){
            if(str1.substr(0,str2.size())==str2)
                return gcdOfStrings(str2,str1.substr(str2.size()));
            else return "";
        }else{
            if(str2.substr(0,str1.size())==str1)
                return gcdOfStrings(str1,str2.substr(str1.size()));
            else return "";
        }
        return "";
    }
};
int main(){
    int T;
    cin>>T;
    Solution s;
    while(T--){
        string s1,s2;
        cin>>s1>>s2;
        cout<<s.gcdOfStrings(s1,s2)<<"\n";
    }
}