#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    queue <int> q[21];//0~20(큐에는 인덱스가 저장됨)
    int n, k;
    long long cnt = 0;
    cin >> n >> k;
    for(int i = 0;i<n;i++){
        string input;
        cin >> input;

        int len = input.length();
        while(!q[len].empty() && i - q[len].front() > k){
            q[len].pop();
        }
        cnt += q[len].size()*1LL;
        q[len].push(i);
    }
    cout << cnt;
}
/*
이것도 못 풀고 결국 다른 사람 껄 봤다.

과정: 큐 배열을 만드는데, 큐 배열 인덱스는 길이를 뜻한다.
그리고 각 큐에는 i(인덱스)가 저장된다. 등수를 비교하기 위해 사용된다.
우선 입력값을 받으면서 길이를 먼저 저장한다.
그 후 해당 길이에 맞는 큐와 비교를 하는데, 큐에 요소가 있으면서 현재 인덱스와 큐의 front에 있는 요소(i)와 비교한다.
즉 k값보다 차이가 크면 front는 조건과 맞지 않으므로 pop을 계속 한다.
반복이 끝나고 큐에 다른 요소가 남아있다면 그 요소는 현재 요소와 조건을 만족하므로 cnt += size 후,
큐에 현재 요소를 push한다.

원래 나는 덱에 넣고 빼고를 반복하면서 하는 방법을 생각하였다. 하지만 넣고 빼고 하는 과정이 문제여서 시간초과가 발생했다.

요약: 큐를 길이에 따라서 나누고(문자열의 길이가 최대 20이라 가능하다.) 각 큐의 요소와 현재 값을 비교하여 k보다 크거나 작거나 같은 경우에 따라
q.front를 지우고 반복하며, 조건을 만족하는 요소들은 카운트하면 된다.(현재 요소를 제외하고)
*/