#include <iostream>
#include <deque>
#include <vector>
using namespace std;
//범위 내에서의 최댓값과 최솟값(슬라이딩 윈도우)
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,input;//요소의 개수, 범위
    deque <int> dq[2];//값이 아닌 인덱스를 저장
    vector <int> vt, max, min;//값을 저장, 범위 내의 최댓값, 최솟값의 인덱스를 저장
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        cin >> input;
        vt.push_back(input);
    }
    for(int i = 0;i<vt.size();i++){//최댓값을 항상 front에 배치시킨다.O(2N)
        while(!dq[0].empty() && vt[dq[0].back()] <= vt[i]){//맨 앞의 인덱스가 최댓값이 되려면 dq.back의 요소가 더 작으면 지우면 된다.
            dq[0].pop_back();
        }
        dq[0].push_back(i);

        if(dq[0].front() == i-m){//최댓값이 윈도우 밖에 있는 경우 제거
            dq[0].pop_front();
        }
        if(i >= m-1){//수의 개수가 m이 되어야 유효하므로
            max.push_back(dq[0].front());
        }
    }
    for(int i = 0;i<vt.size();i++){//최솟값을 항상 front에 배치시킨다.
        while(!dq[1].empty() && vt[dq[1].back()] >= vt[i]){//맨 앞의 인덱스가 최솟값이 되려면 dq.back의 요소가 더 크면 지우면 된다.
            dq[1].pop_back();
        }
        dq[1].push_back(i);

        if(dq[1].front() == i-m){//최솟값이 윈도우 밖에 있는 경우 제거
            dq[1].pop_front();
        }
        if(i >= m-1){//수의 개수가 m이 되어야 유효하므로
            min.push_back(dq[1].front());
        }
    }

    for(int i = 0;i<max.size();i++){
        cout << vt[max[i]] << ' ' << vt[min[i]] << ' ';
    }
}
/*
슬라이딩 윈도우를 통한 덱을 이용한 최대 최소 값 구하기 알고리즘
슬라이딩 윈도우란 배열의 어느 범위 안에서 한 칸씩 이동하면서 부분의 값을 이용하는 것

보통 배열 내에서 최대 최소 값을 구할 땐 단순하게 떠오르는 건 (브루트포스) 이중 반복문이다. 시간 복잡도는 O(N^2)
구현은 간단하지만 많은 값을 연산할 경우 시간초과되기 딱 좋다.

대신 덱을 이용한 알고리즘으로 시간을 획기적으로 줄일 수 있다. 시간복잡도 O(2N) 사실상 그냥 O(N)

살펴보기
1. i는 반복 시 1씩 증가한다. 이때 덱에 인덱스가 있으면 가장 최근에 삽입된 인덱스와(back()) vt[i]를 비교하여 
vt[i]가 크거나 같을 동안 지워준다. 이렇게 하면 구간이 변하여도 최대값을 항상 구할 수 있게 된다.

2. 매 반복 때 i(인덱스를) 덱에 삽입한다.

3. i-m 조건문은 최대값의 인덱스가 윈도우 범위를 벗어났을 때 해당 요소를 제거하는 명령이다.
이렇게 하면 다음 최대값이 앞으로 와 구간에 따른 최대값을 알 수 있다.

4. i>=m-1 조건문은 처음 시작 시 윈도우의 크기가 m을 만족할 때부터 최대를 구한다는 조건이다.
*/
