#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int r, c, n;
    string input;
    cin >> r >> c >> n;
    
    int map[r][c];
    for(int i = 0;i<r;i++){
        cin >> input;
        for(int j = 0;j<c;j++){
            if(input[j] == 'O') map[i][j] = 3;
            else map[i][j] = -1;
        }
    }

    
    for(int k = 1;k<n+1;k++){
        if(n == 1) break;
        else if(k==1) n = n%4+4;
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(map[i][j] != -1 && map[i][j] != 0) map[i][j]--;
            }
        }

        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){ 
                if(map[i][j] == 0){
                    if(j+1<c && map[i][j+1] != 0) map[i][j+1] = -1;
                    if(j-1>=0 && map[i][j-1] != 0) map[i][j-1] = -1;
                    if(i+1<r && map[i+1][j] != 0) map[i+1][j] = -1;
                    if(i-1>=0 && map[i-1][j] != 0) map[i-1][j] = -1;
                    map[i][j] = -1;
                }
                if(k%2 == 0 && map[i][j] == -1) map[i][j] = 3;
            }
        }
        
    }

    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(map[i][j] == -1) cout << '.';
            else cout << 'O';
        }
        cout << '\n';
    }
}

/*
참...이거 부분 부분 실수한 게 많아서 여러번 틀리고 반례도 못찾아서 틀리고...

1. n의 최댓값이 10^9인데, 이걸 쌩으로 돌리면 100퍼센트 시간초과가 난다.
2. 규칙성이 존재하는데, 바로 4주기 마다 항상 같은 맵이 출력됨을 알 수 있다.
3. 그렇다고 n=n%4를 넣으면 안된다. 0나오는 경우가 존재하기 때문. 그래서 n%4+4를 해줘야 한다.
4. 여기서 또 고려해야할 게 최초 n==2라고 치면 최초 상태이므로 원래는 바뀌지 않고 그대로 출력해줘야 하는데,
조건을 두지 않으면 바뀐 맵이 출력된다. 이 점 주의.
5. 폭탄 카운트 명령과 폭탄이 터진 후 추가 명령을 같이 두면 절대 안된다. 
왜냐하면 아직 시간이 남아있는 부분이 다시 3으로 리셋되는 경우가 존재해버린다.

2     3    4   5   6    7    8    9
모두 터짐 모두 터짐 모두
이런식으로 3초 전에 설치된 폭탄이 터진다.

for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                cout << map[i][j];
            }
            cout << '\n';
        }
*/