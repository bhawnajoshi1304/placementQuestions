// Count the subarrays having product less than k
// https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/#
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k){
        long long p = 1;
        int start = 0, end = 0, ans = 0;
        for (; end < n; end += 1){
            p *= a[end];
            while (start < end && p >= k){
                p /= a[start];
                start += 1;
            }
            if (p < k){
                ans += (end - start + 1);
            }
        }
        return ans;
    }
};
int main(){
    int t;
    cin >> t;
    while (t--){
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}