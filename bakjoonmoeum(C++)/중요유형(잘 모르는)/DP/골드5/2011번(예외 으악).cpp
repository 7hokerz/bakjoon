#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <tuple>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef tuple<int,int,int> t3; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
typedef tuple<int,int,int,int,int,int> t6;
#define INF 0x7f7f7f7f7f7f7
#define printmap(row, col, map)      \
    for (int i = 0; i < (row); i++){   \
        for (int j = 0; j < (col); j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

char num[5002];
int dp[5001];

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i = 1;
    while(cin >> num[i]){
        i++;
    }

    dp[0] = dp[1] = 1;

    for(i = 2;num[i] != NULL;i++){
        if((num[i-1] == 48 && num[i] == 48) || num[1] == 48 || (num[i] == 48 && num[i-1] > 50)){
            cout << 0; return 0;
        }
        else if(num[i] == 48){//묶어야만 하는 경우
            dp[i] = dp[i-2] % 1000000;
        }
        else if(num[i] != 48 && num[i-1] != 48 && (num[i-1] < 50 || (num[i-1] == 50 && num[i] < 55))){//둘 다 가능한 경우
            dp[i] = (dp[i-1] + dp[i-2]) % 1000000;
        }
        else{//묶을 수 없는 경우
            dp[i] = dp[i-1] % 1000000;
        }
        //cout << i << ' ' << dp[i] << '\n';
    }
    if(num[1] == 48) dp[i-1] = 0;
    cout << dp[i-1];
}
/*
1 ~ 26
A ~ Z

2,5,1,1,4 

2,5 2
2,5, 25 

2,5,1 2
25,1 2,5,1 

2,5,1,1 4
25,11 25,1,1 2,5,1,1 2,5,11

2,5,1,1,4 6
25,11,4 25,1,14 25,1,1,4 2,5,1,1,4 2,5,1,14 2,5,11,4

1 2 2 4 6

묶을 수 없는 경우

(묶을 수 있는 경우는 피보나치)
dp1[i] = dp1[i-2] + dp[i-1]
(없는 경우는 i-1 그대로)
dp[i] = dp[i-1]

1 1 1 2 3


*/