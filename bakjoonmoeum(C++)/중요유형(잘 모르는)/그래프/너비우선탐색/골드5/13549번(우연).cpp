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
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
//북,동,남,서 총 4 방향 탐색
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0 ,-1};

int N, K, res;
int visited[100001]; 

queue <pair<int,int>> q;

void bfs(int x){
    q.push({x,0});
    visited[x] = 0;

    while(!q.empty()){
        int x = q.front().first;
        int time = q.front().second;
        
        if(x == K){
            res = time; return;
        }
        q.pop();
        
        if((x * 2 >= 0 && x * 2 <= 100000) && (visited[x * 2] == -1 || visited[x * 2] >= time)){//가중치가 0이라고 볼 수 있음.
            visited[x * 2] = time;
            q.push({x * 2, time});
        }
        if((x - 1 >= 0 && x - 1 <= 100000) && (visited[x - 1] == -1 || visited[x - 1] >= time + 1)){//가중치 1
            visited[x - 1] = time + 1;
            q.push({x - 1, time+1});
        } 
        if((x + 1 >= 0 && x + 1 <= 100000) && (visited[x + 1] == -1 || visited[x + 1] >= time + 1)){//가중치 1
            visited[x + 1] = time + 1;
            q.push({x + 1, time+1});
        } 
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    fill(visited, visited+100001, -1);
    cin >> N >> K;
    bfs(N);
    cout << res;
}
/*
처음에 2*x를 맨 뒤에 놓고 풀어서 틀렸는데, 2*x를 앞에 놓고 풀었더니 맞았던..? 황당한 문제

이게 대충 왜 그랬을까가 유추되는 건 0-1너탐태그도 있었고?
0-1너탐이란건 가중치가 0,1만 있는 경우를 말하는데 쉽게 말해 덱을 쓰는 데익스트라
가중치가 0이면 덱 앞에, 가중치가 1이면 덱 뒤에 넣는 것이다.

아무튼 어쩌다 앞으로 옮긴 게 그와 비슷한 효과를 가져서 맞은 듯 하다.

0 5
0 1 2 4 5
0 1 1 1 2

5 17
5 10 9 18 17
0 0 1 1 2
*/