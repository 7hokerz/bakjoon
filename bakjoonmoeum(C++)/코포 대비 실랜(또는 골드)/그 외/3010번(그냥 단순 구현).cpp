#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int N, M, ret = 0;
string inp;
char arr[8][8];//맵은 항상 7*7로 주어짐

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    for(int i = 1;i<8;i++){getline(cin, inp);//cin으로 공백을 받을 수 없기 때문에
        for(int j = 1;j<8;j++){
            arr[i][j] = inp[j-1];
        }
    }
    
    //모든 위치에서 가능한 경우를 탐색
    for(int i = 1;i<8;i++){
        for(int j = 1;j<8;j++){
            if(arr[i][j] == 'o'){
                for(int k = 0;k<4;k++){//4방향 탐색(그래프 문제에도 유용)
                    int nx = j + dx[k];
                    int ny = i + dy[k];

                    if(nx < 1 || ny < 1 || nx > 7 || ny > 7 || arr[ny][nx] == ' ') continue;//범위를 벗어난 경우

                    if(arr[ny][nx] == 'o'){//다음 위치가 'o'
                        int nnx = nx + dx[k];
                        int nny = ny + dy[k];

                        if(nnx < 1 || nny < 1 || nnx > 7 || nny > 7 || arr[nny][nnx] == ' ') continue;

                        if(arr[nny][nnx] == '.') ret++;//다음 다음 위치가 '.'
                    }
                }
            }
            
        }
    }

    cout << ret;
}

/*


*/