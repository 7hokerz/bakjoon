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
#define mod 1'000'000'009
#define INF 2'000'000'001

int k, u, v, nodecnt = 0, dp[1<<21][2];

void dfs(int x){
    int nx = x * 2; //left
    if(nx >= nodecnt) return;//OutOfBounds 방지

    dfs(nx);
    int mx = max(dp[nx][0], mx);
    
    nx += 1; dfs(nx);//right
    mx = max(dp[nx][0], mx);
    //x-리프 노드 까지의 거리가 더 긴 값

    dp[x][0] += mx;//x의 부모 노드-리프 노드까지의 거리
    //(노드 1은 부모가 없고 dp[1] = 0이 되므로 dp[1] = x-리프 노드까지의 거리가 됨)

    dp[x][1] = mx;//x-리프 노드까지의 거리

    nx = x * 2; dp[nx][1] = mx - dp[nx][1];
    //가중치 조정: x-Left 간 가중치를 조정
    
    nx += 1; dp[nx][1] = mx - dp[nx][1];
    //가중치 조정: x-Right 간 가중치를 조정

    cout << x << ' ' << dp[x][0] << '\n';
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> k;
    nodecnt = pow(2, k+1);
    for(int i = 1;i<nodecnt;i++) cin >> dp[i + 1][0];//2 ~ nodecnt-1
    
    dfs(1);
    int sum = 0;
    
    for(int i = 2;i<nodecnt;i++) {
        sum += dp[i][1]; //cout << dp[i][1] << ' ';
    }
    cout << sum;
}
/*
어려워...
루프노드에서 모든 리프노드까지의 거리가 같으면서, 모든 간선의 총합이 최솟값을 만족하는 경우를 구해야 함.

1. dp[i][0]에는 주어진 가중치가 저장된다.
2. dfs로 리프노드까지 들어간 후 다시 리턴된다. 
3. 노드 1에는 가중치가 들어가지 않는다.


중요한 것은 위 과정으로부터 최종적으로 정해지는 간선의 가중치를 구해야 하는데,
dp[nx][1] = mx - dp[nx][1];로 구할 수 있다.

과정:
탐색 전에 dp[i][0]에 노드 i에 대한 가중치를 저장해두었는데,

dp[nx][0](라고 하지만 실상은 x-리프 노드까지의 거리)에서 큰 값을 기준으로 mx에 저장한다.
dp[x][0] += mx면 기존 dp[x][0]에는 부모 까지의 가중치가 저장되어 있으므로 위에서 설명한 경우가 된다.

dp[x][1]의 경우 두 dp[nx][0] 중 새롭게 가중치가 조정되어 즉, 둘 중에 최댓값이 저장된다.
그러므로 mx(x-리프 노드까지의 거리) - dp[nx][1] 을 적용하면

x - nx 간의 거리가 결과로 나온다. 사실상 새로운 가중치가 적용된다.

(설명이 어렵네 ㅅㅂ)
*/