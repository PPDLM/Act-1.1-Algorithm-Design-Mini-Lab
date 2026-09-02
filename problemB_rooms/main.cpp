/*
Problem B — “Minimum Meeting Rooms (Scheduling)”

You are given m meetings, each with a start time and an end time: (s_i, e_i) with s_i < e_i. A room can host only one meeting at a time.

Task: Compute the minimum number of rooms required to schedule all meetings.

Input:

Integer m

Then m lines: start end

Output:

Minimum number of rooms needed

Constraints (suggested):

1 ≤ m ≤ 2 * 10^5

Times are integers (e.g., minutes) in range [0, 10^9]

Example Meetings:
(0, 30), (5, 10), (15, 20)
Output: 2

Clarifications

If one meeting ends at time t and another starts at time t, they do not overlap (same room is allowed).

Notes

Focus on an efficient approach for large m.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int minMeetingRooms(const vector<pair<long long, long long>>& meetings) {
    vector<pair<long long, int>> events;
    events.reserve(2*meetings.size());
    for (size_t i = 0; i < meetings.size(); i++) {
        events.push_back({meetings[i].first, 1});
        events.push_back({meetings[i].second, -1});
    };

    sort(events.begin(), events.end());

    int current_rooms = 0;
    int max_rooms = 0;

    for (const auto& event : events) {
    current_rooms += event.second;
    max_rooms = max(max_rooms, current_rooms);
    };

    return max_rooms;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    if (!(cin >> m)) return 0;

    vector<pair<long long, long long>> meetings(m);
    for (int i = 0; i < m; i++) {
        cin >> meetings[i].first >> meetings[i].second;
    }

    int rooms = minMeetingRooms(meetings);
    cout << rooms << "\n";

    return 0;
}