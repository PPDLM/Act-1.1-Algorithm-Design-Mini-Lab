/*
Problem C — “Budgeted Study Plan (0/1 Knapsack Variant)”

You have n study modules. Each module i requires time[i] hours and yields value[i] points of learning benefit. You have a total available time budget T. Each module can be taken at most once.

Task: Compute the maximum total value achievable without exceeding time T.

Input:

Integers n and T

Then n lines: time value

Output:

Maximum value achievable

Constraints (suggested):

1 ≤ n ≤ 2000

1 ≤ T ≤ 5000

1 ≤ time[i] ≤ T

1 ≤ value[i] ≤ 10^6

Example Modules:
(time=3, value=4), (time=4, value=5), (time=7, value=10) with T=10
Output: 14 (take modules 1 and 3: time 3+7=10, value 4+10=14)

Notes

A brute force subset search is infeasible.

Your solution should handle the full constraints.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll solveKnapsack(int n, int T, const vector<int>& time, const vector<ll>& value) {
    vector<ll> maxScore(T + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int w = T; w >= time[i]; w--) {
            maxScore[w] = max(maxScore[w], maxScore[w - time[i]] + value[i]);
        };
    };
    return maxScore[T];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, T;
    if (!(cin >> n >> T)) return 0;

    vector<int> time(n);
    vector<ll> value(n);
    for (int i = 0; i < n; i++) {
        cin >> time[i] >> value[i];
    }

    cout << solveKnapsack(n, T, time, value) << "\n";

    return 0;
}