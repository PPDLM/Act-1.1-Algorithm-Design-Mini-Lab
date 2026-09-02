# Mini-Lab Report

## Problem A: Inversion Counter (Divide & Conquer)
**Problem Summary & Algorithm Idea**
This problem requires counting inversions in an array. It is solved using *Divide and Conquer* via a modified *Merge Sort*. When merging two sorted halves, if an element on the right is smaller than an element on the left, it is strictly smaller than all remaining elements on the left, allowing us to count multiple inversions in a single step.

**Pseudocode**
```text
MergeSortAndCount(A, left, right):
    if left >= right return 0
    mid = (left + right) / 2
    inv = MergeSortAndCount(left, mid) + MergeSortAndCount(mid+1, right)
    inv += MergeAndCount(A, left, mid, right)
    return inv
```

**Correctness Argument**
The algorithm maintains the invariant that the two halves are sorted at each step. The recursive property ensures internal inversions are counted, and `MergeAndCount` accurately tallies cross-inversions without duplication.

**Complexity**
* **Time**: $\mathcal{O}(n \log n)$. The array is halved $\log n$ times, and merging takes linear time $\mathcal{O}(n)$ at each level.
* **Space**: $\mathcal{O}(n)$. An auxiliary array of size $n$ is required for the merge step.

**Example Execution**
* **Input**: `[2, 4, 1, 3, 5]`
* **Trace**: The array divides until merging `[2, 4]` and `[1, 3, 5]`. The `1` is placed before `2` and `4` (+2 inversions). The `3` is placed before `4` (+1 inversion). 
* **Output**: 3

---

## Problem B: Minimum Meeting Rooms (Greedy)
**Problem Summary & Algorithm Idea**
This problem requires finding the maximum number of overlapping meetings. A **Greedy** sweep-line algorithm is optimal. By separating start and end times into individual events, sorting them, and tracking a running count of active meetings, we find the peak room usage.

**Pseudocode**
```text
MinRooms(meetings):
    events = empty list
    for each (start, end) in meetings:
        add (start, +1) to events
        add (end, -1) to events
    
    sort(events) // ascending order
    
    current_rooms = 0, max_rooms = 0
    for each event in events:
        current_rooms += event.value
        max_rooms = max(max_rooms, current_rooms)
        
    return max_rooms
```

**Correctness Argument**
Sorting events ensures chronological processing. Adding `1` for a start and subtracting `1` for an end precisely simulates active rooms. The maximum observed running sum is exactly the peak concurrency.

**Complexity**
* **Time**: $\mathcal{O}(m \log m)$. Creating $2m$ events is linear, but sorting them dictates the $\mathcal{O}(m \log m)$ time.
* **Space**: $\mathcal{O}(m)$. Space is needed to store the $2m$ start and end events.

**Example Execution**
* **Input**: `(0, 30), (5, 10), (15, 20)`
* **Trace**: Events sorted chronologically: `(0,+1), (5,+1), (10,-1), (15,+1), (20,-1), (30,-1)`. Running sums: 1, 2, 1, 2, 1, 0.
* **Output**: 2

---

## Problem C: Budgeted Study Plan (Dynamic Programming)
**Problem Summary & Algorithm Idea**
This is a 0/1 Knapsack problem where time is the weight and learning benefit is the value. We use **Dynamic Programming** to find the optimal subset. We optimize memory by using a 1D DP array of size $T+1$, iterating backwards through capacities so each module is used at most once.

**Pseudocode**
```text
SolveKnapsack(n, T, time, value):
    dp = array of size T+1 initialized to 0
    for i from 0 to n - 1:
        for w from T down to time[i]:
            dp[w] = max(dp[w], dp[w - time[i]] + value[i])
    return dp[T]
```

**Correctness Argument (Recurrence)**
The state `dp[w]` is the maximum value for budget `w`. Recurrence: `dp[w] = max(dp[w], dp[w - time[i]] + value[i])`. By iterating backwards from $T$, the computation relies strictly on the DP state from the previous item, preventing multiple inclusions.

**Complexity**
* **Time**: $\mathcal{O}(n \cdot T)$. Two nested loops iterating over $n$ items and up to $T$ time slots.
* **Space**: $\mathcal{O}(T)$. The DP table is space-optimized to a 1D array of size $T+1$.

**Example Execution**
* **Input**: $n=3$, $T=10$, Modules: `(3, 4), (4, 5), (7, 10)`
* **Trace**: DP array updates backwards. Module 1 sets `dp[3] = 4`. Module 2 sets `dp[7] = 9` and `dp[4] = 5`. Module 3 sets `dp[10] = dp[3] + 10 = 14`.
* **Output**: 14