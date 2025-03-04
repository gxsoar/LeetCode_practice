#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> dp(n + 1, 0);
        dp[0] = nums[0]; dp[1] = max(nums[0],nums[1]);
        int ans = max(dp[0],dp[1]);
        for(int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};

int main() {

    return 0;
}