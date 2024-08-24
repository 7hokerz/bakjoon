#include <iostream>
using namespace std;
/*
누적 합을 구하는 공식을 잘 외워두자.
어떤 배열을 모두 0으로 채우고, i=0, j=0부터 시작한다.

공식: map[i+1][j+1] = map[i+1][j] + map[i][j+1] - map[i][j] + input;
어떤 곳의 누적합은 -1열의 누적합 + -1행의 누적합  - 겹치는 누적합 + 실제 값이다.

이렇게 하면 i == 0 || j == 0은 모두 0이고 그 다른 부분부터 내가 알던 누적합이 보임을 알 수 있다.
이게 가능한 이유? 문제를 보면 x,y의 좌표를 인덱스 1부터 시작하기 때문에 가능하다.
물론 인덱스 0으로 시작해도 거기에 +1을 하면 상관은 없을거 같다.
그냥 저기에 input만 안붙이고 실제 값을 넣은 표에 똑같은 과정을 하면 0이 없는 같은 표가 나온다.
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, input;
    cin >> n >> m;
    //배열의 크기를 숫자로 설정하지 않으면 밑의 식으로 해도
    //0으로 초기화되지 않으니 주의
    int map[1025][1025] = {0};
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> input;
            //**i+1 j+1의 구간합 = i+1 j의 구간합 + i j+1의 구간합 - 겹치는 구간 + 값
            //이렇게 하면 x와 y의 좌표가 1부터 시작할 때 유용하다.
            map[i+1][j+1] = map[i+1][j] + map[i][j+1] - map[i][j] + input;
        }
    }
    //누적 합 구하기 
    int x1, y1, x2, y2;
    for(int i = 0;i<m;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = 0;
        if(x1 > 0 && y1 > 0){
            sum += map[x2][y1-1];
            sum += map[x1-1][y2];
            sum -= map[x1-1][y1-1];
        }
        else if(y1 > 0) sum += map[x2][y1-1];
        else if(x1 > 0)sum += map[x1-1][y2];
        
        cout << map[x2][y2] - sum << '\n';
    }
}
/*
1 3 6 10 1,3
3 8 15 24
6 15 27 42
10 24 42 64
4,1

1좌표 2좌표
2,2 3,4 합: 27
4,4의 합: 7

1 3
4 10
1 2 3 4
어떤 식으로 계산할까?
42 - (1,1 3,1의 구간합 + 1,1 1,3의 구간합 - 1,1의 구간합)
42 - (10+6-1) = 27
64 - (1,1 3,4의 구간합 + 1,1 4,3의 구간합 - 1,1 3,3의 구간합)
64 - (42 + 42 - 27) = 7
위의 예시로 보아, 0,0 2좌표의 구간합에서 쓰이지 않은 구간들의 합을 빼주고 
겹치는 부분도 고려해야한다.
*/


