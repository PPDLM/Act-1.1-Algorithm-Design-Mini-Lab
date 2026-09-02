# Mini-Lab Report

## Problem A: Inversion Counter (Divide & Conquer)
**Problem Summary & Algorithm Idea**
For this problem, the goal is to count how many inversions exist in an array. A brute-force approach would be too slow, so I went with a Divide and Conquer strategy based on Merge Sort. The trick here is that while we merge two sorted halves, if we see an element on the right side that is smaller than one on the left, it means it is also smaller than *all* the remaining elements on that left side. This lets us count a bunch of inversions at once instead of one by one.

**Pseudocode**
```text
MergeSortAndCount(A, left, right):
    if left >= right return 0
    
    mid = (left + right) / 2
    inv = MergeSortAndCount(A, left, mid) + MergeSortAndCount(A, mid+1, right)
    inv += MergeAndCount(A, left, mid, right)
    
    return inv
```

**Correctness Argument**
Because Merge Sort naturally guarantees the two halves are already sorted before we merge them, the logic holds up. The recursive calls handle all the internal inversions within each half, and our custom merge step counts the cross-inversions between the left and right sides without missing or double-counting anything.

**Complexity**
* **Time**: `O(n log n)`. We split the array in half `log n` times, and the merge step takes linear `O(n)` time at each level of the recursion tree.
* **Space**: `O(n)` because we need a temporary array of the same size to hold the elements while merging.

**Example Execution**
* **Input**: `[2, 4, 1, 3, 5]`
* **Trace**: The array breaks down until we merge `[2, 4]` and `[1, 3, 5]`. The `1` drops in before `2` and `4` (adding 2 to our inversion count). Later, the `3` drops in before the `4` (adding 1 more inversion). 
* **Output**: 3

---

## Problem B: Minimum Meeting Rooms (Greedy)
**Problem Summary & Algorithm Idea**
This problem asks us to find the maximum number of overlapping meetings. A greedy "sweep-line" algorithm fits perfectly here. You basically break every meeting down into two separate events: a start time and an end time. If you sort all these events chronologically and just keep a running total of active meetings, the highest number you hit is the minimum number of rooms you need.

**Pseudocode**
```text
MinRooms(meetings):
    events = empty list
    for each (start, end) in meetings:
        add (start, +1) to events
        add (end, -1) to events
    
    sort events chronologically
    
    current_rooms = 0, max_rooms = 0
    for each event in events:
        current_rooms += event.value
        max_rooms = max(max_rooms, current_rooms)
        
    return max_rooms
```

**Correctness Argument**
Sorting the events forces us to process the timeline in order. Adding 1 when a meeting starts and subtracting 1 when it ends perfectly simulates rooms filling up and emptying out. By tracking the highest running total, we are guaranteed to find the peak overlap.

**Complexity**
* **Time**: `O(m log m)`. Generating the events takes `O(m)`, but sorting them is the bottleneck.
* **Space**: `O(m)` since we have to store two events (a start and an end) for every single meeting.

**Example Execution**
* **Input**: `(0, 30), (5, 10), (15, 20)`
* **Trace**: After sorting, the timeline of events looks like this: `(0,+1), (5,+1), (10,-1), (15,+1), (20,-1), (30,-1)`. If we track the running sum over time, we get: 1, 2, 1, 2, 1, 0.
* **Output**: 2

---

## Problem C: Budgeted Study Plan (Dynamic Programming)
**Problem Summary & Algorithm Idea**
This is basically the classic 0/1 Knapsack problem in disguise, where the time cost is our "weight" and the learning benefit is the "value." I used Dynamic Programming to avoid a massive brute-force search. To save memory, I condensed the DP table into a 1D array of size `T+1` and iterated backwards through the time capacities to make sure I didn't accidentally use the same module twice.

**Pseudocode**
```text
SolveKnapsack(n, T, time, value):
    dp = array of size T+1 initialized to 0
    for i from 0 to n - 1:
        for w from T down to time[i]:
            dp[w] = max(dp[w], dp[w - time[i]] + value[i])
            
    return dp[T]
```

**Correctness Argument**
The state `dp[w]` tracks the maximum score we can get with a time budget of `w`. The core recurrence is `dp[w] = max(dp[w], dp[w - time[i]] + value[i])`. Going backwards from `T` down to the current module's time is the key—it ensures we are only building on top of the results from the *previous* modules, strictly enforcing the rule that we can only take a module once.

**Complexity**
* **Time**: `O(n * T)` because we have an outer loop for the `n` modules and an inner loop checking up to `T` time slots.
* **Space**: `O(T)` since we flattened the typical 2D DP matrix into a single 1D array.

**Example Execution**
* **Input**: `n=3, T=10`, Modules: `(3, 4), (4, 5), (7, 10)`
* **Trace**: The DP array updates backwards. Module 1 sets `dp[3] = 4`. Module 2 sets `dp[7] = 9` and updates `dp[4] = 5`. Finally, Module 3 sets `dp[10] = dp[3] + 10 = 14`.
* **Output**: 14