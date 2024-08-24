#include <iostream>
#include <deque>
#include <algorithm>
#include <tuple>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    deque <pair<int, int>> q1;
    deque <tuple<int, int, int>> q2;
    int N, T, W, px, tx, M, cx, count = 0;
    /*
    N:대기인원, T:은행원이 일을 한 번 처리하는 최대 시간,
    W:총 반복 시간, px:손님의 id, tx:업무를 처리하는 데
    걸리는 시간
    M:영업 시작 1초 이후에 들어오는 고객수
    cx:영업 시작 이후 은행에 들어오는 시각
    */
    cin >> N >> T >> W;

    for(int i = 0;i<N;i++){
        cin >> px >> tx;
        q1.push_back({px, tx});
    }
    cin >> M;
    for(int i = 0;i<M;i++){
        cin >> px >> tx >> cx;
        q2.push_back(make_tuple(cx, px, tx));
    }

    sort(q2.begin(), q2.end());

    for(int i = 0;i<W;i++){//시간 == i
        if(q1.front().second > 0){//1초 차감
            cout << q1.front().first << '\n';
            q1.front().second--;
            count++;
        }
        if(q1.front().second == 0){//업무를 마친 고객의 id 출력
            q1.pop_front();
            count = 0;
        }
        if(get<0>(q2.front()) == i+1){
                q1.push_back({get<1>(q2.front()), get<2>(q2.front())});
                q2.pop_front();
        }
        if(count == T){//5초 카운트가 되었으면 끝마치지 못한 고객 맨 뒤로 보내기
            q1.push_back({q1.front().first, q1.front().second});
            q1.pop_front();
            count = 0;
        }
    }
}
/*
은행원은 T초 동안 일을 처리한다.

cx는 영업 시작 후 몇 초 후에 들어왔는지를 알려준다.

즉 cx를 검사하면서 time==cx가 되는 순간 q1에 대입하면 된다.

1. 업무를 진행하면서 count++한다.(5초 제한)
2. 업무를 마친 고객의 id를 출력하고 pop한다.
3. 새로운 손님이 영업중 들어올 시간이 되면
q1에 삽입시킨다.
4. 5초 제한에 걸리면 고객을 맨 뒤로 보낸다.

내 방법으로 시간초과가 걸린 이유:
입력값은 정렬되지 않은 상태인데,
1초 반복마다 i+1에 해당하는 
영업 시간 이후 들어오는 고객을 찾는 방법을 사용했다.
즉, 매번 있는지 없는지 검사하는거다.
이러면 시간복잡도가 매우 커지는 것은 확실하긴 했다.

인터넷을 찾다가 여러 방법이 있었는데
우선순위 큐 등 아직 배우지 않은 것들은 제외하고
sort 함수를 사용하는 코드를 보았다.
기존에는 큐 자료구조를 사용하였으나
소트 함수는 큐에서 사용할 수 없어
덱으로 변경하였다.

그래서 수정된 방법은
요소를 덱에 받고 cx가 작은 순서대로 
시작부터 끝까지 sort함수를 이용해 정렬하도록 했다.
그 후 기존과 다르게 front에 i+1초에 해당하는 게
있는지만 검사하는 조건문을 써서 시복도를
매우 줄일 수 있었다.

sort함수의 시간복잡도가 크지 않을까 우려했지만
놀랍게도 통과...!
sort함수는 nlogn의 시간복잡도를 가진다.

이 문제 자체를 보면 라운드로빈 알고리즘이 숨어있다.

기억해야할 것: 덱 자료구조로 소트 함수를 이용하면
정렬은 고민 노우!
*/