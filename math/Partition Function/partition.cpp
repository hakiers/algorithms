#include "partition.h"
#include <vector>

long long p(int n) {
    std::vector<long long> dp(n+1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        long long sum = 0;
        for (int k = 1; ; ++k) {
            int pent1 = (3*k - 1) * k / 2;
            if (pent1 > i) break;
            sum += (k&1 ? 1 : -1) * dp[i - pent1];

            int pent2 = (3*k + 1) * k / 2;
            if (pent2 > i) break;
            sum += (k&1 ? 1 : -1) * dp[i - pent2];
        }
        dp[i] = sum;
    }

    return dp[n];
}



