#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, input, sum = 0, res = 0;
    cin >> N >> M;
    int nums[N];
    for(int i = 0;i<N;i++){
        cin >> input;
        nums[i] = input;
    }

    for(int i = 0;i<N;i++){
        int j = i;
        while(sum < M){
            sum += nums[j];
            j++;
            if(sum < M && j == N) {
                cout << res;
                return 0;
            }
        }
        if(sum == M) res++;
        sum = 0;
    }
    cout << res;
}
/*
N개의 수로 된 수열 A[1], A[2], …, A[N] 이 있다. 
이 수열의 i번째 수부터 j번째 수까지의 합 A[i] + A[i+1] + … + A[j-1] + A[j]
가 M이 되는 경우의 수를 구하는 프로그램을 작성하시오.

반복문으로 배열에 저장하고, 부분수열의 합이 M인 모든 경우의 수
0부터 시작하여 합을 누적하는데, 합이 M이거나 넘으면 중지.
그리고 모든 수열을 더했음에도 M보다 작으면 그 이후 수열 또한
경우의 수가 없으므로 누적된 경우의 수 출력 및 끝내기

투 포인터: 
(두 개의 점의 위치를 기록하면서 처리하는 알고리즘)

예: 부분연속 수열 찾기
1. 시작점과 끝점이 첫번째 원소의 인덱스를 가리키도록 한다.
2. 현재 부분 합이 M과 같다면 카운트한다.
3. 현재 부분 합이 M보다 작다면 end를 1 증가시킨다.
4. 현재 부분 합이 M보다 크거나 같다면 start를 1 증가시킨다.
5. 모든 경우를 확인할 때까지 2-4번 과정을 반복한다.

위의 코드도 M보다 같거나 크면 중지 후 start + 1하므로 투포인터 구현이라고 볼 수 있음.

4 2
1 1 1 1  3

10 5
1 2 3 4 2 5 3 1 1 2  3
*/