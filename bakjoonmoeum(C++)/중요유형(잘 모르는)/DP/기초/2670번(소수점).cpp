#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
double input;
double dp[10001], inp[10001];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1;i<N+1;i++){
        cin >> input;
        inp[i] = input;
    }
    dp[0] = 1.0;
    double res = 0.0;
    for(int i = 1;i<N+1;i++){
        dp[i] = max(dp[i-1] * inp[i], inp[i]);
        res = max(res, dp[i]);
    }
    cout << fixed;
    cout.precision(3);
    cout << res;
}
/*
dp[i] = max(dp[i-1] * inp[i], inp[i]);

1.1 0.77 1.3 1.17 1.638 1.3104 0.91728 1.4

1.1 1.1 1.3 1.3 1.638 ~~~


*/