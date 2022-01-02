// Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string.
// eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.(Modified version of question named Cute Monkeys)
// https://practice.geeksforgeeks.org/problems/run-length-encoding/1/
#include <bits/stdc++.h>
using namespace std;
string encode(string src);
int main(){
    int T;
    cin >> T;
    while (T--){
        string str;
        cin >> str;
        cout << encode(str) << "\n";
    }
    return 0;
}
string encode(string src){
    string ans = "";
    int i = 0, c;
    while (i < src.size()){
        c = 1;
        while (i < src.size() - 1 && src[i] == src[i + c])
            c += 1;
        ans += src[i] + to_string(c);
        i += c;
    }
    return ans;
}