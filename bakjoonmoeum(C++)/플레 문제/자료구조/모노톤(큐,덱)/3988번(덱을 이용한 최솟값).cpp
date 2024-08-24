#include <iostream>
#include <algorithm>
#include <deque>
#include <math.h>
using namespace std;
int N, K, V;
deque <int> input, sub, minnum;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for(int i = 0;i<N;i++){
        cin >> V;
        input.push_back(V);
    }
    sort(input.begin(),input.end());
    
    for(int i = 0;i<N-1;i++) sub.push_back(abs(input[i] - input[i+1]));//두 수의 차이
    
    int range = N - K - 1, res = 10'000'001, sum = 0;
    for(int i = 0;i<sub.size();i++){//덱을 이용한 최솟값 및 합 구하기(중요)
        while(!minnum.empty() && sub[minnum.back()] >= sub[i]){
            minnum.pop_back();//최솟값을 앞에 위치시키기 위함.
        }
        minnum.push_back(i);

        sum += sub[i];//합 구하기
        if(i >= range) sum -= sub[i-range];//슬라이딩 구간이 시작점을 벗어난 시점부터 i-range를 제거한다.

        if(minnum.front() == i-range){//최솟값이 윈도우 밖에 있는 경우 제거
            minnum.pop_front();
        }

        if(i>=range-1){//수의 개수가 range면 삽입
            //cout << sum + sub[minnum.front()] << ' ';
            res = min(res, sum + sub[minnum.front()]);//res = (res>sum + sub[minnum.front()])?sum + sub[minnum.front()]:res;
        }
    }
    cout << res;
}
/*
수를 그리디로 지워서 남은 원소에 대해서 계산하여 직접 구하는 게 아니라
결국 "남은 값의 합 + 최솟값" 이 제일 작은 경우를 구해야 한다.(이 부분을 봄)

최솟값의 경우는 덱, 슬라이딩 윈도우를 이용하여 구할 수 있고, 합은 슬라이딩 윈도우를 통해 구할 수 있다.

수를 n - k - 1만큼 묶어서 탐색(슬라이딩 윈도우)

최소? 덱으로 최솟값

5 2 .4 범위:5-2-1 = 2
0 2 3 9999 10000 //9999 10000제거
2 1 9996 1 최소 1 1 1

4 9998 9998 >> 4가 답

6 3 .6 범위: 6-3-1 = 2
2 2 8 10 17 17 최소 0 2 2 0
0 6 2 7 0 //2 7 0제거
6 10 11 7 >> 6이 답

6 2 .13 범위: 6-2-1 = 3
-5 -1 1 8 10 13
4 2 7 2 3 //4 3 제거
15 13 14 >> 13이 답

5 2 .7
-3 -2 3 6 8
1 5 3 2 //1 5 제거 또는 3 2 제거

7 11 7 >> 7이 답
*/