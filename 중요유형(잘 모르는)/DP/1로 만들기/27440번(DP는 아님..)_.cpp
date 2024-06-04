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
using namespace std;
typedef long long ll; typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,pii> rpii;//오른쪽 pii
typedef pair<pii,int> lpii;//왼쪽 pii
typedef pair<pii,pii> piiii;//더블 pii
typedef pair<ll, ll> pll;//long long pair
#define mod 1'000'000'007 
#define INF 1'999'990
//2차원 map 출력
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

#define printmap3(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j][0] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

ll N;
map <ll, ll> visited;

queue <pll> q;//x,cnt

void bfs(){
    q.push({N, 0});
    visited[N] = 0;
    while(!q.empty()){
        ll x = q.front().first;
        ll cnt = q.front().second;
        //cout << x << '\n';
        q.pop();

        if(x == 1) {
            cout << cnt;
            return;
        }

        if(x % 3 == 0 && !visited[x/3]){
            visited[x/3] = cnt + 1;
            q.push({x/3, cnt + 1});
        }

        if(x % 2 == 0 && !visited[x/2]){
            visited[x/2] = cnt + 1;
            q.push({x/2, cnt + 1});
        }

        if(x - 1 > 0 &&!visited[x-1]){
            visited[x-1] = cnt + 1;
            q.push({x-1, cnt + 1});
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    bfs();
}
/*
1로 만들기 문제처럼 1부터 시작해서 N에 먼저 도달하는 경우를 찾다가 멸망한 문제.

쉬운 방법은 N에서 시작해서 1로 가는 거였는데, 왜 이런거야?

N의 범위가 크므로 단순 배열은 쓸 수 없고 map stl을 이용하여 해결 가능하다.
*/
