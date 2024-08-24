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

int r, c, maxnum = 0;
string input;

int map[21][21];
int alpb[26];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0 ,-1};

void dfs(int x, int y, int cnt){
    
    maxnum = max(maxnum, cnt);//최대 개수를 저장

    for(int k = 0;k<4;k++){//4방향 탐색
        int nx = x + dx[k];
        int ny = y + dy[k];

        if(nx < 1 || nx > c || ny < 1 || ny > r) continue;//범위를 벗어난 경우 생략
        //cout << nx << ' ' << ny << '\n';
        if(alpb[map[ny][nx]] == 0){//해당 알파벳이 한번도 등장한 적 없는 경우
            alpb[map[ny][nx]]++;
            dfs(nx,ny,cnt+1);//개수 추가 및 해당 알파벳 좌표로 이동
            alpb[map[ny][nx]]--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    for(int i = 1;i<r+1;i++){
        cin >> input;
        for(int j = 1;j<c+1;j++){
            map[i][j] = input[j-1] - 65;
        }
    }
    alpb[map[1][1]]++;//시작하는 곳은 미리 개수 처리
    dfs(1,1,1);//cnt+1
    cout << maxnum;
}
/*
이 풀이는 다른 블로그를 참고하여 수정한 풀이.
내가 한 풀이는 시간이 너무 길게 나와서 대신함.

중요한 점: 풀이를 간략하게.
*/