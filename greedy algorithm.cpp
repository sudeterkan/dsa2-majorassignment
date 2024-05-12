//PROBLEM 1

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

// Define a structure to represent meetings
struct Meeting {
    int start;
    int end;
};

// Function to compare meetings based on their end times
bool compare(const Meeting& a, const Meeting& b) {
    return a.end < b.end;
}

// Function to find the maximum number of meetings that can be accommodated
int maxMeetings(array<int, 10>& start, array<int, 10>& end, int N) {
    // Combine start and end times into pairs and store them in a vector
    array<Meeting, 10> meetings;
    for (int i = 0; i < N; i++) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
    }

    // Sort meetings based on end times
    sort(meetings.begin(), meetings.begin() + N, compare);

    int count = 0;
    int prev_end = 0; // End time of the previous meeting

    for (const Meeting& meeting : meetings) {
        if (meeting.start > prev_end) {
            count++;
            prev_end = meeting.end;
        }
    }

    return count;
}

int main() {
    int N;
    cout << "Enter the number of meetings: ";
    cin >> N;

    array<int, 10> start, end;
    cout << "Enter the start and end times of meetings:\n";
    for (int i = 0; i < N; i++) {
        cout << "Meeting " << i + 1 << ": ";
        cin >> start[i] >> end[i];
    }

    cout << "Maximum number of meetings: " << maxMeetings(start, end, N) << endl;

    return 0;
}