#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    queue <int> q;
    int N, K, input, countK = 0, res = -1;
    cin >> N >> K;

    for(int i = 0;i<N;i++){
        cin >> input;
        if(input == 1) countK++;
        q.push(input);

        if(countK == K){
            while(q.front() != 1) q.pop();
            if(res < 0 || res > q.size()) res = q.size();
            countK--;
            q.pop();
            while(q.front() != 1) q.pop();
        }
    }
    if(res == -1) cout << -1;
    else cout << res;
}
/*

1이라는 숫자가 K개 이상 있는 집합 중 가장 작은 총 개수
큐로 풀어도 될려나
countK로 K개 이상 되면 큐 사이즈를 저장
만약 countK가 K개 이상 된 적이 없으면 -1을 출력

10 3
1 2 2 2 1 2 1 2 2 1 6

예외 처리 확인 실력이 아직 부족한 나...
(귀찮아서도 있음 ㅋㅋ)
*/