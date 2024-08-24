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

int N, M, input, visited[200001][3];//방문 표시, 최초 루머 믿는 시간, 믿는 주변인의 수
vector <int> gr[200001];

queue <pair<int,int>> q;//x, time

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int time = q.front().second;
        //cout << x << ' ' << visited[x][2] << ' ';
        q.pop();

        for(int i = 0;i<gr[x].size();i++){
            int nx = gr[x][i];
            if(!visited[nx][0]){
                int div = gr[nx].size() / 2;
                int rest = gr[nx].size() % 2;

                visited[nx][2] += 1;//믿는 주변인의 수를 늘려준다.x는 이미 루머를 믿는 노드이기 때문

                if(div < visited[nx][2] || (div == visited[nx][2] && rest == 0)){//절반 이상인지 확인
                    visited[nx][0] = true; visited[nx][1] = time + 1; 
                    q.push({nx, time + 1});
                }
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1;i<N+1;i++){
        while(1){
            cin >> input;
            if(input == 0) break;
            gr[i].push_back(input);
        }
    }
    for(int i = 0;i<N+1;i++) visited[i][1] = -1;//0과 구분하기 위함
    
    cin >> M;
    for(int i = 0;i<M;i++){
        cin >> input;//최초 루머를 퍼뜨리는 노드
        q.push({input,0}); visited[input][0] = true; visited[input][1] = visited[input][2] =  0;
    }
    
    bfs();
    for(int i = 1;i<N+1;i++) cout << visited[i][1] << ' ';
}
/*
int cnt = 0;
    for(int j = 0;j<gr[nx].size();j++){
        if(visited[gr[nx][j]][0] && (visited[x][1] >= visited[gr[nx][j]][1])) {
            cnt++;
        }
    }
    cout << cnt << ' ';
*/



