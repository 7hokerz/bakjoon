#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0, 1};

int B, S, x, y, one = 0, two = 0;
int m[3002][3002];

struct info{
    int x, y, cnt;
};

void bfs(){
    queue <info> q;
    q.push({1501,1501,0});
    m[1501][1501] = 1; one++;

    while(!q.empty()){
        auto[x,y,cnt] = q.front();

        q.pop();

        if(cnt == S) continue;

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(m[ny][nx] == -1) continue;

            if(nx < 1 || ny < 1 || nx > 3000 || ny > 3000) {//추가 구현 필요
                /*int val = S - cnt;
                if(val % 2) one++;
                
                one += val / 2;
                two += val / 2;*/
                continue;
            }

            if(!m[ny][nx]){
                if((cnt + 1) % 2){
                    m[ny][nx] = 2;
                    q.push({nx,ny,cnt + 1}); two++;
                }
                else{
                    m[ny][nx] = 1;
                    q.push({nx,ny,cnt + 1}); one++;
                }
            }
        }
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> B >> S;
    for(int i = 0;i<B;i++){
        cin >> x >> y;
        x += 1501; y += 1501;
        m[y][x] = -1;
    }
    bfs();
    cout << one << ' ' << two;
} 
/*
1000,1000에서 시작하는 경우로 생각하자.

한 걸음마다 바뀐다.
1: 9개 
2: 4개

짝수와 홀수 관계 및 제곱 관계?

1 4 9 16 25...

이 방향이 막혀있는가? 

0,0 >> 4개의 BFS -1,0 / 1,0 / 0,-1 / 0,1 

만약 막혀있거나 방문한 적이 있으면 가지 않음. 

장애물의 x, y값의 절댓값은 1000보다 작다고 하자.

그러므로 좌표를 [2001][2001]로 잡고, 나머지는 수학적 연산(?)을 통해 구하도록 하면 된다?

모든 맵의 1과 2의 개수를 먼저 구하고 나머지는 맵 경계에 있는 숫자로 구분하면 된다?

*/