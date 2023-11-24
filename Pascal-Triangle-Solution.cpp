******************************************************************************  Question  ************************************************************************************************************************************

Given a positive integer N, return the Nth row of pascal's triangle.
Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.
The elements can be large so return it modulo 109 + 7.

File:PascalTriangleAnimated2.gif

Example 1:

Input:
N = 4
Output: 
1 3 3 1
Explanation: 
4th row of pascal's triangle is 1 3 3 1.
Example 2:

Input:
N = 5
Output: 
1 4 6 4 1
Explanation: 
5th row of pascal's triangle is 1 4 6 4 1.
Your Task:
Complete the function nthRowOfPascalTriangle() which takes n, as input parameters and returns an array representing the answer. You don't to print answer or take inputs.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N2)

Constraints:
1 ≤ N ≤ 103



********************************************************************************  Solution  **********************************************************************************************************************************

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{

public:
   vector<long long> ans;
   int mod=1e9+7;
void solve(int n,int i){
    if(i>=n)return;
    vector<long long>temp(i+1);
    temp[0]=1;
    temp[i]=1;
    
     for(int j=1;j<i;j++){
         temp[j]=(ans[j-1]+ans[j])%mod;
     }
     ans=temp;
    solve(n,i+1);
}
    vector<long long> nthRowOfPascalTriangle(int n) {
       ans={1};
        solve(n,1);
        return ans;
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends

