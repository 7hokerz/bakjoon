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
#define mod 1'000'000'009
#define INF 2'000'000'001
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int N, M, visited[51][51][(1<<6)], res = -1;//y,x, 방문
char m[51][51];
queue <t4> q;
string input;

void bfs(){
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        int key = get<3>(q.front());//얻은 키

        q.pop();

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            if(m[ny][nx] == '.' && !visited[ny][nx][key]){
                visited[ny][nx][key] = 1;
                q.push(make_tuple(nx,ny,cnt + 1,key));
            }
            else if(m[ny][nx] == '1'){
                res = cnt + 1;
                return;
            }else if(m[ny][nx] != '#' && m[ny][nx] != '.'){
                int nkey = key;
                if(islower(m[ny][nx])){
                    nkey |= (1 << m[ny][nx] - 97);
                    if(!visited[ny][nx][nkey]){
                        visited[ny][nx][nkey] = 1;
                        q.push(make_tuple(nx,ny,cnt + 1,nkey));
                    }
                }
                else{
                    if((nkey & (1 << m[ny][nx] - 65)) && !visited[ny][nx][nkey]){
                        visited[ny][nx][nkey] = 1;
                        q.push(make_tuple(nx,ny,cnt + 1,nkey));
                    }
                }
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){ cin >> input;
        for(int j = 1;j<M+1;j++){
            m[i][j] = input[j-1];
            if(m[i][j] == '0') {
                visited[i][j][0] = 1;
                q.push(make_tuple(j,i,0,0));
                m[i][j] = '.';
            }
        }
    }
    
    bfs();
    cout << res;
}
/*
열쇠는 여러 번 사용 가능.



*/