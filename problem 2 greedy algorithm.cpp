//PROBLEM 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool compareJobs(const Job& a, const Job& b) {
    return a.profit > b.profit; // Sort in non-increasing order of profit
}

vector<int> JobScheduling(int N, vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compareJobs);

    vector<bool> slot(N, false);
    int count = 0, profit = 0;

    for (int i = 0; i < jobs.size(); i++) {
        for (int j = min(N, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                count++;
                profit += jobs[i].profit;
                slot[j] = true;
                break;
            }
        }
    }

    return { count, profit };
}

int main() {
    vector<Job> jobs1 = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
    vector<int> result1 = JobScheduling(4, jobs1);
    cout << "Number of jobs done: " << result1[0] << ", Maximum profit: " << result1[1] << endl;

    vector<Job> jobs2 = { {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15} };
    vector<int> result2 = JobScheduling(5, jobs2);
    cout << "Number of jobs done: " << result2[0] << ", Maximum profit: " << result2[1] << endl;

    return 0;
}