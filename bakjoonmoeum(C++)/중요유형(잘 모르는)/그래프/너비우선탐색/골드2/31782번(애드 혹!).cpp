#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef tuple<int,int,int> t3; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
typedef tuple<int,int,int,int,int,int> t6;
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0, 1};

int N, M, K, visited[2001][2001], res = 0;
char m[2001][2001];

queue <pii> q;

void bfs(){
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());

        q.pop();

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            if(!visited[ny][nx] || visited[ny][nx] == 1){
                visited[ny][nx]++;
                if(visited[ny][nx] == 2){
                    q.push({nx,ny});
                }
            }
        }
    }
}

void check(int x, int y){
    int width = 1;
    int height = 1;
    int nx = x; int ny = y;

    while(1){
        nx += dx[2];
        if(nx < 1 || ny < 1 || nx > M || ny > N || visited[ny][nx] < 2) break;
        width++;
    } nx = x;
    while(1){
        ny += dy[3];
        if(nx < 1 || ny < 1 || nx > M || ny > N || visited[ny][nx] < 2) break;
        height++;
    }
    //cout << width << ' ' << height << '\n';
    if(width > K && height > K){
        res += width * height;
    }
}

int main(){cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M >> K;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cin >> m[i][j];
            if(m[i][j] == 'O'){
                visited[i][j] = 2; q.push({j,i});
            }
        }
    }
    bfs();

    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            if(visited[i][j] == 2 && visited[i-1][j] < 2 && visited[i][j-1] < 2){
                check(j,i);
            }
        }
    }
    //printmap(N,M,visited);
    cout << res;
}
/*
O에 대해서 BFS를 진행한다. 이때 8방향 탐색을 진행하여 방문 표시를 진행하는데 
처음 방문 시 +1, 두 번째로 .에 방문한다면 방문 표시를 추가로 한 후 해당 지점에서 다시 방문 시작한다.

초기 상태에 대한 밤의 상태를 만들고 이때 1,0인 경우 및 2에서 K개를 뽑은 후 모두 방문 배열에 대해 0으로 만들어 놓고

위 bfs를 반복하여 cnt를 확안하자.

어떤 사람과 사방으로 인접한 두 명 이상의 사람이 정상 체온 
>> 세 명 이상의 사람이 저체온증이면 회복 불가

2 2 2 0 0 2 2 
2 2 2 0 0 2 2 
2 2 2 0 0 2 2 
2 2 2 0 0 2 2 
0 0 0 0 0 2 2 

중요한 것은 특수한 경우를 제외하고는 대부분 정사각형 아니면 직사각형이 만들어 질 것이다.(다른 블로그에서 무심코 모양을 봐버렸는데
이게 떠오른 듯? ㅋㅋ 괜히 봤나.)만약 정사각형이나 직사각형이 아니다? 그럼 다음 턴에 없어지므로 사실상 없는 걸로 취급 가능.

즉 어느 도형의 한 변의 길이가 K 이하면 그 도형은 없는 걸로 취급해야 한다. 재밌는 문제
*/