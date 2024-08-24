#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    deque <int> dq;
    deque <int> dq2;
    int N, M, ele, count1 = 0, count2 = 0, count = 0;
    //뽑으려는 요소, 연산 횟수
    cin >> N >> M;

    for(int i = 1;i<N+1;i++){
        dq.push_back(i);//왼쪽
        dq2.push_back(i);//오른쪽
    }

    for(int i = 0;i<M;i++){
        cin >> ele;
        while(!(dq.front() == ele)){
            dq.push_back(dq.front());
            dq.pop_front();
            count1++;
        }
        dq.pop_front();
        while(!(dq2.front() == ele)){
            dq2.push_front(dq2.back());
            dq2.pop_back();
            count2++;
        }
        dq2.pop_front();
        count += (count1 < count2)?count1:count2;
        count1 = 0, count2 = 0;
    }
    cout << count << '\n';
}
/*
3가지 연산
1. 첫 번째 원소를 뽑아낸다.(즉 front_pop)
2. 왼쪽으로 한 칸 이동 (즉, push_back(front) and pop_front)
3. 오른쪽으로 한 칸 이동 (push_front(back) and pop_back)

뽑아내려고 하는 수의 위치: 사실상 큐에 자연수를 순서대로 넣으면 됨. 그리고 해당 자연수를 뽑는 것으로 가능
수의 위치는 입력값 순서대로 뽑아야 한다.

while(!.front or !.back){
    시프트 연산
}//두 가지 경우를 모두 계산하고 작은 경우로 뽑아내기? 완료

구해야 하는 것: 2번, 3번 연산의 최솟값
*/