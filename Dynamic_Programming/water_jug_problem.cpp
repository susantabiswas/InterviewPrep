#include<iostream>
#include<vector>
#include <climits>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

/*
  For each jug three things can be done:
  Empty, Fill or transfer water.
  We try the 3 operations for each state of two jugs to see if it is possible.
*/
int jugs(int a, int b, int& m, int& n, int& d, vector<vector<int> >& dp,
             set<pair<int, int> >& visited) {
    // base case
    if(a < 0 || b < 0 || a > m || b > n)
        return numeric_limits<int> :: max();

    // if solution has been cached
    if(dp[a][b] != -1)
        return dp[a][b];

    // check if current is visited or not
    if(visited.find(make_pair(a, b)) != visited.end()) {
        return numeric_limits<int> :: max();
    }
    // mark current as visited
    visited.emplace(make_pair(a, b));

    // if solution has been found
    if(a == d || b == d)
        return dp[a][b] = 0;

    // find the min operations 
    int min_op = numeric_limits<int> :: max();

    // try operations on Jug A
    // empty
    if(a != 0) {
        min_op = min(min_op, jugs(0, b, m, n, d, dp, visited));
    }
    // fill
    if(a != m) {
        min_op = min(min_op, jugs(m, b, m, n, d, dp, visited));
    }
    // transfer
    min_op = min(min_op, jugs(a - min(n-b, a), b + min(n-b, a), m, n, d, dp, visited));
    
    // Try operations on Jug B
    // empty
    if(b != 0) {
        min_op = min(min_op, jugs(a, 0, m, n, d, dp, visited));
    }
    // fill
    if(b != m) {
        min_op = min(min_op, jugs(a, n, m, n, d, dp, visited));
    }
    // transfer
    min_op = min(min_op, jugs(a + min(m-a, b), b - min(m-a, b), m, n, d, dp, visited));
    if(min_op != numeric_limits<int> :: max())
        min_op += 1;
    
    return dp[a][b] = min_op;
}

int main()
{   
    int t;
    cin >> t;

    while(t--) {
        int m, n, d;
        cin >> m >> n >> d;

        vector<vector<int> > dp(m+1, vector<int>(n+1, -1));
        set<pair<int, int> > visited;
        int res = jugs(0, 0, m, n, d, dp, visited);
        if(res != numeric_limits<int> :: max())
            cout << res << endl;
        else
            cout << -1 << endl;
    }
	return 0;
}
