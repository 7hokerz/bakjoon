#include <iostream>
using namespace std;
int dp[11];

int calc(int n){
    if(dp[n] != 0) return dp[n];
    dp[n] = dp[n-1]+dp[n-2]+dp[n-3];
    return dp[n];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t, n;
    cin >> t;
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    for(int i = 0;i<t;i++){
        cin >> n;
        for(int j = 3;j<n;j++){
            calc(j);
        }
        cout<< dp[n-1] << '\n';
    }
}   
/*
n
1 1
2 1+1 2 2
3 1+1+1 1+2 2+1 3 4
4 1+1+1+1 1+1+2 1+2+1 2+1+1 2+2 1+3 3+1 7
5 1+1+1+1+1 1+1+1+2 1+1+2+1 1+2+1+1 2+1+1+1 1+2+2 2+2+1 1+1+3 1+3+1 3+1+1 2+3 3+2 13

결국 방법을 봄.

X가 4일 때 1,2,3을 더한 것
X가 5일 때 2,3,4를 더한 것
n-1 + n-2 + n-3 = n

결국은 n일때의 경우를 나열하고 규칙성을 찾아 점화식을 세워야 한다.
*/