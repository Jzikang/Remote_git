#include <iostream>
#include <vector>
using namespace std;

int count_b(vector<int>& a, int target) {
    int n = a.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i - 1]) {
                dp[i][j] += dp[i - 1][j - a[i - 1]];
            }
        }
    }

    return dp[n][target];
}

int main() {
    vector<int> a = {1, 1, 1};
    int res = count_b(a, 5);
    cout << "满足条件的数组b的个数为: " << res << endl;

    return 0;
}