#include <bits/stdc++.h> 
using namespace std;

// Job Id should be put just before its deadline(as last as possible)…
// 1. Sort the jobs according to profit in decreasing order.
// 2. Iterate on jobs in decreasing order of profit.
// 3. For each job, do the following :
//    a. Find a time slot i, such that slot is empty and i < deadline and i is greatest.
//    b. Put the job in this slot and mark this slot filled.
// 4. For each slot occupied, print the job id in sorted order.
// Time -> O(n^2)
// Space -> O(n)

bool comp(vector<int> a, vector<int> b) { 
    return a[1] > b[1]; 
}
int jobScheduling(vector<vector<int>> &jobs) {
    // Sort in decreasing order:
    sort(jobs.begin(), jobs.end(), comp);
    int n = jobs.size();

    // Finding Maximum Deadline
    int maxdead = INT_MIN;
    for (int i = 0; i < n; i++)
        maxdead = max(jobs[i][0], maxdead);
    
    int profit = 0;
    int countJobs = 0;
    // initialize to -1
    vector<int> ans(maxdead + 1, -1); // why maxdead +1 soze is needed  ans 1 indexing is used
    for (int i = 0; i < n; i++) {
        int currdead = jobs[i][0];
        int currprofit = jobs[i][1];
        for (int k = currdead; k > 0; k--) {
            if (ans[k] == -1) {
                profit += currprofit;
                ans[k] = 1;
                countJobs++;
                break;
            }
        }
    }
    return profit;
}
// Time -> O(nlogn) + O(n^2)
// Space -> O(n)

//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    bool comp(Job a, Job b) { 
        return (a.profit > b.profit); 
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // Sort in decreasing order:
        sort(arr, arr+n, comp);
    
        // Finding Maximum Deadline
        int maxdead = INT_MIN;
        for (int i = 0; i < n; i++)
            maxdead = max(arr[i].dead, maxdead);
        
        int profit = 0;
        int countJobs = 0;
        // initialize to -1
        vector<int> ans(maxdead + 1, -1); // why maxdead +1 soze is needed  ans 1 indexing is used
        for (int i = 0; i < n; i++) {
            int currdead = arr[i].dead;
            int currprofit = arr[i].profit;
            for (int k = currdead; k > 0; k--) {
                if (ans[k] == -1) {
                    profit += currprofit;
                    ans[k] = 1;
                    countJobs++;
                    break;
                }
            }
        }
        return {countJobs, profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
// int main() 
// { 
//     int t;
//     //testcases
//     cin >> t;
    
//     while(t--){
//         int n;
        
//         //size of array
//         cin >> n;
//         Job arr[n];
        
//         //adding id, deadline, profit
//         for(int i = 0;i<n;i++){
//                 int x, y, z;
//                 cin >> x >> y >> z;
//                 arr[i].id = x;
//                 arr[i].dead = y;
//                 arr[i].profit = z;
//         }
//         Solution ob;
//         //function call
//         vector<int> ans = ob.JobScheduling(arr, n);
//         cout<<ans[0]<<" "<<ans[1]<<endl;
//     }
// 	return 0; 
// }



// // } Driver Code Ends