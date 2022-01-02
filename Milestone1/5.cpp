// nth Ugly Number
// https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/
#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
class Solution{
public:
    ull getNthUglyNo(int n){
        if (n == 1)
            return 1;
        vector<ull> ugly(n, 1);
        int i2, i3, i5, i = 1;
        i2 = i3 = i5 = 0;
        while (ugly[n - 1] == 1){
            ugly[i] = min(ugly[i2] * 2, min(ugly[i3] * 3, ugly[i5] * 5));
            if (ugly[i] == ugly[i2] * 2)
                i2 += 1;
            if (ugly[i] == ugly[i3] * 3)
                i3 += 1;
            if (ugly[i] == ugly[i5] * 5)
                i5 += 1;
            i += 1;
        }
        return ugly[n - 1];
    }
};
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}