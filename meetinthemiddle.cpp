#include <bits/stdc++.h>
using namespace std;
//maximum subsequence codeforces proble
// Function to compute all subset sums mod m for a given set
vector<int> compute_subset_sums(const vector<int>& arr, int m) {
    int n = arr.size();
    vector<int> subset_sums;

    // Generate all possible subsets using bitwise representation
    for (int i = 0; i < (1 << n); ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {  // If the j-th bit is set in i, include arr[j]
                sum += arr[j];
                sum %= m;  // Keep the sum mod m
            }
        }
        subset_sums.push_back(sum);
    }

    return subset_sums;
}

int meet_in_the_middle(const vector<int>& arr, int m) {
    int n = arr.size();

    // Split the array into two halves
    vector<int> first_half(arr.begin(), arr.begin() + n / 2);
    vector<int> second_half(arr.begin() + n / 2, arr.end());

    // Compute all subset sums mod m for both halves
    vector<int> subset_sums1 = compute_subset_sums(first_half, m);
    vector<int> subset_sums2 = compute_subset_sums(second_half, m);

    // Sort the second half subset sums to use binary search for optimization
    sort(subset_sums2.begin(), subset_sums2.end());

    int max_sum = 0;  // This will store the maximum possible sum modulo m

    // Now for each subset sum from the first half, find the best complement in the second half
    for (int sum1 : subset_sums1) {
        // We want to maximize (sum1 + sum2) % m
        // Find the best sum2 from the second half such that (sum1 + sum2) % m is maximized
        int best_sum2 = 0;
        for (int sum2 : subset_sums2) {
            int current_sum = (sum1 + sum2) % m;
            max_sum = max(max_sum, current_sum);
        }
    }

    return max_sum;
}

int main() {
    int n, m;

    // Input the number of elements and the modulo value m
    cin >> n >> m;

    vector<int> arr(n);

    // Input the array of integers
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Call the meet in the middle function to compute the maximum subsequence sum modulo m
    int result = meet_in_the_middle(arr, m);

    // Output the result
    cout << result << endl;

    return 0;
}
