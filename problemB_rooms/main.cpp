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