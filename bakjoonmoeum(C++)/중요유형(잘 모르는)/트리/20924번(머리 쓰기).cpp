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
typedef long long ll; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef pair<int,int> pii; typedef pair<pii,int> lpii; typedef pair<int,pii> rpii;
typedef pair<pii,pii> piiii;//더블 pii
#define mod 1'000'000'009
#define INF 2'000'000'001

int N, R, a, b, d, visited[200001][2], col = 0, mx = 0;
bool chk = false;
vector <pii> gr[200001];

void dfs(int x){
    if(chk && gr[x].size() < 2){
        mx = max(mx, visited[x][1]); return;
    }

    if(!chk && x != R && gr[x].size() != 2){
        col = visited[x][1]; visited[x][1] = 0;
        chk = true;
    }

    for(int i = 0;i<gr[x].size();i++){
        int nx = gr[x][i].first;
        int ncost = gr[x][i].second;

        if(!visited[nx][0]){
            visited[nx][0] = 1;
            visited[nx][1] = visited[x][1] + ncost;
            dfs(nx);
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> R; visited[R][0] = 1;
    for(int i = 0;i<N-1;i++){
        cin >> a >> b >> d;
        gr[a].push_back({b,d});
        gr[b].push_back({a,d});
    }
    
    if(gr[R].size() != 1) chk = true;
    dfs(R);
    cout << col << ' ' << mx;
}
/*                         
루트에서 순회를 시작했을 때 처음으로 자식 노드가 2개 이상인 노드(기가 노드)를 찾아
기둥의 길이를 출력하고,
기가 노드 부터 리프 노드까지의 길이 중 최장 거리를 구해 출력하는 문제.

여러 조건들을 고려해야할 게 있어 조오금 까다로웠던 문제.

과정:
1. 간선을 입력받아 양방향 연결시킨다.
2. 루트를 검사해 간선이 1개가 아니면 chk = true 즉 기둥의 길이를 검사하지 않도록 한다.
3. 루트가 아니면서 최초로 2개 이상의 자식을 가지는 노드를 찾으면 기둥 길이를 저장하고 
길이는 0으로 초기화 시킨다.
4. 기가 노드에서 리프 노드까지의 최장 거리는 리프 노드의 특징이 간선이 1개만 연결되어있으므로,
그 중 큰 값을 mx에 저장한다.
*/