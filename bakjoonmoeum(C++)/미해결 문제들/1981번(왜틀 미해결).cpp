#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4;
#define INF 1e9+1
 
int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0, 1};

int N, mnnum = 301;
int m[102][102];
bool visited[102][102][202];

struct info{
    int x, y, mx, mn;
};

int bfs(int canmn){
    int dif = -1;

    if(canmn > m[1][1]) return -1;

    queue <info> q;

    fill_n(&visited[0][0][0], 102*102*202, 0);

    visited[1][1][0] = 1;
    q.push({1,1,m[1][1],m[1][1]});

    while(!q.empty()){
        auto[x,y,mx,mn] = q.front(); 

        q.pop(); //cout << y << ' ' << x << ' ' << mx << ' ' << mn << '\n';

        if(x == N && y == N){
            if(dif == -1) dif = mx - mn;
            else dif = min(dif, mx - mn);
            continue;
        }
        if(dif != -1 && dif <= mx - mn) continue;

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > N || ny > N || m[ny][nx] < canmn) continue;

            int nmx = max(mx, m[ny][nx]);
            int nmn = min(mn, m[ny][nx]);

            if(!visited[ny][nx][nmx - nmn]){
                visited[ny][nx][nmx - nmn] = 1;
                q.push({nx,ny,nmx,nmn});
            }
        }
    }
    return dif;
}

int bisearch(){
    int res = 301, low = 0, mid = 0, high = 200;

    while(low <= high){
        int mid = (low + high) / 2;
        
        int dif = bfs(mid); //cout << mid << ' ' << dif << '\n';

        if(dif != -1){
            if(mnnum < mid) high = mid - 1;
            else low = mid + 1;
            res = min(res, dif);
        }
        else{
            high = mid - 1;
        }
    }
    return res;
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<N+1;j++){
            cin >> m[i][j];
            mnnum = min(mnnum, m[i][j]);
        }
    }    

    cout << bisearch();
}
/*

*/