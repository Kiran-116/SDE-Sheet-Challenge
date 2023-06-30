#include <bits/stdc++.h>
using namespace std;

// 1. Sort the start and end times of all the trains.
// 2. Create two pointers i and j, and initialize i = 1, j = 0
// 3. Initialize the count of platforms needed as res = 1
// 4. Now run a loop until i is less than the number of trains.
// 5. If the start time of train[i] is greater than the end time of train[j],
//    then we need an extra platform so we increase the count of platforms
//    needed i.e res++ and increment j.
// 6. Else if the start time of train[i] is less than or equal to the end time
//    of train[j], then we will decrease the count of platforms needed i.e res--,
//    and increment i.
// 7. Update the maximum of res and required number of platforms.
// 8. Print the result.

int calculateMinPatforms(int at[], int dt[], int n) {
    // Sort the arrival and departure arrays
    sort(at, at+n);
    sort(dt, dt+n);

    int patform_needed = 1;
    int result = 1;
    int i = 1, j = 0;
    while (i < n && j < n) {
        if (at[i] <= dt[j]) {
            patform_needed++;
            i++;
        }
        else if (at[i] > dt[j]) {
            patform_needed--;
            j++;
        }
        result = max(result, patform_needed);
    }
    return result;
}
// Time -> O(2nlogn) + O(2n)
// Space -> O(1)