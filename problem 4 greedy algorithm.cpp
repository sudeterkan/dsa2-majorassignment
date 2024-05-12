#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int first;
    int second;
};

bool comparePairs(const Pair& a, const Pair& b) {
    return a.second < b.second;
}

int maxChainLen(vector<Pair>& pairs) {
    int n = pairs.size();
    if (n <= 1) return n;

    sort(pairs.begin(), pairs.end(), comparePairs);

    int maxChainLength = 1;
    int currentEnd = pairs[0].second;

    for (int i = 1; i < n; i++) {
        if (pairs[i].first > currentEnd) {
            maxChainLength++;
            currentEnd = pairs[i].second;
        }
    }

    return maxChainLength;
}

int main() {
    vector<Pair> pairs1 = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    cout << "Longest chain length: " << maxChainLen(pairs1) << endl;

    vector<Pair> pairs2 = { {5, 10}, {1, 11} };
    cout << "Longest chain length: " << maxChainLen(pairs2) << endl;

    return 0;
}