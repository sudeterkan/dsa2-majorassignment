#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int first;
    int second;
};

bool comparePairs(const Pair& a, const Pair& b) {
    return a.first < b.first;
}

int maxChainLen(vector<Pair>& pairs) {
    int n = pairs.size();
    if (n <= 1) return n;

    sort(pairs.begin(), pairs.end(), comparePairs);

    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (pairs[i].first > pairs[j].second && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<Pair> pairs1 = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    cout << "Longest chain length: " << maxChainLen(pairs1) << endl;

    vector<Pair> pairs2 = { {5, 10}, {1, 11} };
    cout << "Longest chain length: " << maxChainLen(pairs2) << endl;

    return 0;
}