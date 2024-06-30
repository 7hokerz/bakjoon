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
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int dx[] = {0, -1, 0, 1}; int dy[] = {1, 0, -1 ,0};

int T, N, M, res = 0;
bool visited[101][101], key[26];//키 유무
char m[101][101];
string keyhave;
vector <pii> door[26], entrance;//도달 가능한 문의 좌표, 입구 좌표
queue <pii> q;

void check(int num){
    while(!door[num].empty()){
        int x = door[num].back().first;
        int y = door[num].back().second;
        
        m[y][x] = '.';
        visited[y][x] = 1;

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N || visited[ny][nx]) q.push({x,y});
        }
        door[num].pop_back();
    }
}

void bfs(){//모든 입구에 대해 큐 삽입
    for(int i = 0;i<entrance.size();i++) q.push(entrance[i]);
    
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        
        q.pop(); 

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N || m[ny][nx] == '*') continue;
            //문서
            if(m[ny][nx] == '$'){
                res++; m[ny][nx] = '.';
            }
            else if(m[ny][nx] >= 97){//열쇠
                key[m[ny][nx] - 97] = 1;
                //열쇠를 찾았을 때 해당 열쇠에 대응하는 문이 존재하는 경우
                if(door[m[ny][nx] - 97].size() != 0) check(m[ny][nx] - 97);
                m[ny][nx] = '.';
            }
            else if(m[ny][nx] >= 65){//문
                if(key[m[ny][nx] - 65]) m[ny][nx] = '.';
                else door[m[ny][nx] - 65].push_back({nx,ny});
                //문에 대한 열쇠가 존재하지 않으면 벡터에 삽입(추후 열쇠 발견 시 해제 예정)
            }
            
            if(!visited[ny][nx] && m[ny][nx] == '.'){
                visited[ny][nx] = 1;
                q.push({nx,ny});
            }
        }
    }
}

void init(int x, int y){
    m[y][x] = '.';
    visited[y][x] = 1;
    entrance.push_back({x,y});
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for(int t = 0;t<T;t++){
        cin >> N >> M;
        for(int i = 1;i<N+1;i++){
            for(int j = 1;j<M+1;j++){
                cin >> m[i][j];
                if(i == 1 || j == 1 || i == N || j == M){
                    if(m[i][j] >= 97) key[m[i][j] - 97] = 1;//열쇠
                    if(m[i][j] == '$') res++;
                }   
            }
        }

        cin >> keyhave;
        for(int i = 0;i<keyhave.length();i++){
            if(keyhave[i] == '0') break;
            key[keyhave[i] - 97] = 1;
        }

        for(int i = 1;i<N+1;i++){
            for(int j = 1;j<M+1;j++){
                if((i == 1 || j == 1 || i == N || j == M) && m[i][j] != '*'){//미리 뚫어놓고 기록
                    if(m[i][j] == '.' || m[i][j] == '$' || m[i][j] >= 97){
                        init(j,i);//빈 공간, 문서, 열쇠는 모두 이동 가능하므로
                    }
                    else if(m[i][j] >= 65){//문
                        if(key[m[i][j] - 65]) init(j,i);
                        else door[m[i][j] - 65].push_back({j,i});
                    }
                }
            }
        }
        bfs();
        cout << res << '\n'; res = 0;
        fill(visited[0], visited[101], 0); fill(key, key + 26, 0);
        vector<pii>().swap(entrance);
        for(int i = 0;i<26;i++) vector<pii>().swap(door[i]);
        //printmap(N,M,m);
    }
}
/*
최단거리를 구하는 문제가 아닌 최대로 가질 수 있는 것의 개수를 구하는 문제이다.

함수의 기능
init: 가장자리에서 구할 때 .으로 초기화 및 방문처리와 입구 벡터에 삽입
check: 어떤 문의 열쇠를 가지고 있을 때 모두 .으로 처리 후 주변이 가장자리거나 방문 흔적이 있으면 큐에 해당 좌표 삽입

과정:
처음 좌표를 입력받을 때 가장자리의 문서와 열쇠는 모두 전처리한다.
그리고 다음 가지고 있는 키가 주어지면 key배열의 요소를 1로 만든다.

가장자리 중에서 들어갈 수 있는 모든 곳에 대해 init()
문의 경우는 열쇠 존재 유무에 따라 나뉜다. 존재하지 않으면 벡터에 삽입(추후 키 발견 시 바로 대응하기 위해)

bfs 돌릴 때도 크게 다를 것 없다.
다만 다른 점은
열쇠를 발견하면 해당 대응하는 문이 존재하면 모든 문에 대해 연산해주는 것.
*/