#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

int N, M, K, input, maxnum = -1'000'000'1;
vector <int> vt;//선택한 값을 담을 벡터
int map[11][11];
bool visited[11][11];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0 ,-1};

void dfs(int y){//**x좌표가 필요없음. 아래의 이유 때문
    if(vt.size() == K){//개수가 채워지면 합을 계산하여 리턴
        int sum = 0;
        for(int i = 0;i<vt.size();i++){
            sum += vt[i];
            //cout << vt[i] << ' ';
        }
        //cout << sum << '\n';
        if(!vt.empty()) maxnum = max(sum, maxnum);
        return;
    }
    //**j=x하면 항상 x의 값만 들어가 1부터 반복되지 않는 오류 발생
    for(int i = y;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            int ab = 1;
            for(int k = 0;k<4;k++){//4방향에 선택된 요소가 있는지 검사
                int nx = j + dx[k];
                int ny = i + dy[k];

                if(nx < 1 || nx > M) continue;
                if(ny < 1 || ny > N) continue;
                ab = ab && !visited[ny][nx];//1번만 인접해도 불가능
            }
            //현재 요소가 선택된 적 없고 인접한 게 없으면
            if(!visited[i][j] && ab){
                visited[i][j] = !visited[i][j];
                vt.push_back(map[i][j]);
                //cout << i << ' ' << j << '\n';
                dfs(i);
                vt.pop_back();
                visited[i][j] = !visited[i][j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cin >> input;
            map[i][j] = input;
        }
    }
    dfs(1);
    cout << maxnum;
}
/*
선택된 수 및 그에 대한 인접 영역을 제외하고 다른 수를 선택
해야하는 문제.
간과한 점은 j=x를 넣어서 초과하면 1로 돌아갈것이라는 망상...
j=1을 넣어서 해결했다. 다만 중복 연산이 조금 있는게 아쉬움.

*/