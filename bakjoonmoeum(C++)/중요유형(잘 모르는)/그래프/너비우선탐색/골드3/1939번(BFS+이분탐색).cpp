#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef tuple<int,int,int> t3; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
typedef tuple<int,int,int,int,int,int> t6;

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int N, M, a, b, c, st, go, high = 0, res = 0;
bool visited[10'001];
vector <pii> gr[10'001];


bool bfs(int w){
    queue <int> q;//아...맞왜틀 왜 했나 했더니 큐를 전역에 놓고 안 비워서...ㅋㅋㅋ 바본가
    visited[st] = 1;
    q.push(st);
    
    while(!q.empty()){
        int x = q.front();

        q.pop();

        if(x == go) return true;

        for(int i = 0;i<gr[x].size();i++){
            int nx = gr[x][i].first;
            int can = gr[x][i].second;

            if(!visited[nx] && w <= can){
                visited[nx] = 1;
                q.push(nx);
            }
        }
    }
    return false;
}

void bisearch(){
    int low = 0, mid = 0;
    
    while(low <= high){
        mid = (low + high) / 2;

        if(bfs(mid)){
            low = mid + 1;
            res = max(res, mid);
        }
        else{
            high = mid - 1;
        }
        fill(visited, visited + 10'001, 0);
    }
}

int main(){cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1;i<M+1;i++){
        cin >> a >> b >> c;
        gr[a].push_back({b,c});
        gr[b].push_back({a,c});
        high = max(high, c);
    }
    cin >> st >> go;
    bisearch();
    cout << res;
}
/*

*/