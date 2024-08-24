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
//int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1}; int dy[] = {0, 1, 0 ,-1, 1, -1, 1, -1};
//int dx[] = {-1, 0, 1, 0}; int dy[] = {0, 1, 0 ,-1};

int visited[101001], N, M, K, input, res = -1;
vector <int> gr[101001];

queue <pair<int,int>> q;//x,cnt

void bfs(){
    q.push({1, 1});
    visited[1] = true;
    while(!q.empty()){
        int x = q.front().first;
        int cnt = q.front().second;
        if(x == N){res = cnt; return;}
        q.pop();

        for(int i = 0;i<gr[x].size();i++){
            if(!visited[gr[x][i]]){
                visited[gr[x][i]] = true;
                if(x > N) q.push({gr[x][i], cnt});//하이퍼튜브 정점
                else q.push({gr[x][i], cnt + 1});//역 정점
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> K >> M;
    for(int i = N+1;i<M+N+1;i++){
        for(int j = 0;j<K;j++){
            cin >> input;
            gr[i].push_back(input);//하이퍼튜브와 연결된 역 정점 입력
            gr[input].push_back(i);//역과 연결된 하이퍼튜브 정점 입력
        }
    }
    bfs();
    cout << res;
}
/*
(질게 봄) 
처음 아이디어: 1~N까지의 정점으로 둔다. 그리고 튜브를 확인해서 일일이 정점 리스트에 삽입한다.
위의 아이디어는 메모리 초과를 유발했음. 너무 많은 정점을 리스트에 삽입하였기 때문.

(중요 아이디어) 
본 아이디어: 1~N까지의 정점으로 둔다. 그리고 하이퍼튜브 또한 N+1~N+K+1으로 정점으로 둬보자.

하이퍼 튜브를 탐색하면서 해당 하이퍼튜브와 연결된 정점을 리스트에 모두 삽입하고,
해당 역 정점의 리스트에는 하이퍼튜브 정점을 삽입시킨다.(아래 예시 참고)

bfs처리를 다르게 해야할 부분:
보통 다른 정점을 방문할 때 항상 카운트는 증가한다. 
하지만 하이퍼튜브 정점은 역이 아니므로 하이퍼튜브 정점을 방문할 때는 cnt를 증가시키지 않아야 함.

보통의 경우 하이퍼 튜브 부분은 정점으로 생각하는 게 아니고 단순히 역의 정점만을 일반적으로 연결시키는 걸 생각했는데,
N의 크기가 충분히 크다면 메모리초과가 난다는 것이다.

요약: 하이퍼튜브는 역 정점과 연결되고, 역 정점은 하이퍼튜브 정점과 연결됨. 역<->역, 튜브<->튜브는 있을 수 없음.

과정:
1. 한 하이퍼튜브가 연결시키는 정점을 튜브 정점에 삽입, 하이퍼튜브가 포함하는 역 정점에 하이퍼튜브 정점을 삽입
2. bfs()호출
3. 시작(1)정점 큐에 삽입, 방문처리, cnt = 1
4. 하이퍼 정점 방문 시 cnt, 역 정점 방문 시 cnt + 1 처리
5. N 정점을 방문하면 cnt 리턴 출력

1 10 11
2 10
3 10 12
4 11
5 11 13
6 12 13 14
7 12 13
8 14
9 14

10 1 2 3
11 1 4 5
12 3 6 7
13 5 6 7
14 6 8 9

1 10
2 10 11
3 11 12 14
4 12 13
5 13 14

1 2 
2 3 
3 4 
4 5 
3 5
*/