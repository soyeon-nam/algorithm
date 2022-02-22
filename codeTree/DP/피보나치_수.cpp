#include <iostream>

#define MAX_NUM 45

using namespace std;

int     main() {
    int n;
    int dp[MAX_NUM + 1];

    cin >> n;
    
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];

    cout << dp[n];
    return (0);
}



/* DP - Memoization */

// #include <iostream>

// #define MAX_NUM 45
// #define UNUSED -1

// using namespace std;

// int memo[MAX_NUM + 1];

// void InitializeMemo() {
//     for(int i  = 0; i <= MAX_NUM; i++)
//         memo[i] = UNUSED;
// }

// int fib(int n) {
//     if(memo[n] != UNUSED)
//         return memo[n];

//     if(n == 1 || n == 2)
//         return memo[n] = 1;

//     return memo[n] = fib(n - 1) + fib(n - 2);
// }

// int main() {
//     int n;
//     cin >> n;

//     InitializeMemo();

//     cout << fib(n);
//     return 0;
// }