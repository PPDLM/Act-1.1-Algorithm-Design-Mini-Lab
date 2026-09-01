/*
Problem A — “Inversion Counter for Quality Control”

You are given an array A of n integers. A pair (i, j) is an inversion if i < j and A[i] > A[j].

Task: Compute the number of inversions in the array.

Input:

An integer n

A list of n integers

Output:

A single integer: the inversion count

Constraints (suggested):

1 ≤ n ≤ 2 * 10^5

Values fit in 32-bit signed int

Output may exceed 32-bit; use 64-bit integer.

Example

Input: A = [2, 4, 1, 3, 5]

Output: 3
(inversions: (2,1), (4,1), (4,3))

Notes

A direct O(n^2) approach will be too slow for the upper constraints.

Your algorithm should scale to large n.
*/

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll mergesortandcount(vector<long long>& arr, vector<long long>& temp, int left, int right) {
    ll inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inv_count += mergesortandcount(arr, temp, left, mid);
        inv_count += mergesortandcount(arr, temp, mid + 1, right);
        inv_count += mergeandcount(arr, temp, left, mid, right);
    };
    return inv_count;
};

ll mergeandcount(vector<long long>& arr, vector<long long>& temp, int left, int mid, int right) {
    int i = left;
    int j = mid +1;
    int k = left;
    ll inv_count = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]){

        } else if (arr[i] > arr[j]) {

        }
    };
};
/* if (left >= right){
return 0;
}*/