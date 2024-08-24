#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    queue <pair<int,int>> left;
    queue <pair<int,int>> right;
    vector <pair<int,int>> resvt;
    int M, t, N, input, cnt = 0, cnt2 = 0;
    string direction;
    cin >> M >> t >> N;
    int resultarr[N][2];
    
    for(int i = 0;i<N;i++){
        cin >> input >> direction;
        if(direction == "left"){
            left.push({input,i});
        }else if(direction == "right"){
            right.push({input,i});
        }
    }

    direction = "left";
    int time = 0;
    while(!left.empty() || !right.empty()){
        int person = 0;
        if((!left.empty() && left.front().first <= time) || (!right.empty() && right.front().first <= time)){//둘 중 하나에 사람이 대기하고 있으면
            if(direction == "left" && !left.empty() && left.front().first <= time){//현 위치가 left이면서 left에 사람이 있을 때
                while(!left.empty() && person < M && left.front().first <= time){
                    resultarr[cnt2][0] = left.front().second;
                    left.pop();
                    person++;
                    cnt2++;
                }
                time += t;
                for(int i = cnt;i<person+cnt;i++){
                    resultarr[i][1] = time;
                }
                cnt += person;
                direction = "right";
            }
            else if(direction == "left" && !right.empty() && right.front().first <= time){//현 위치가 left이면서 right에 사람이 있을 때
                time += t;
                while(!right.empty() && person < M && right.front().first <= time){
                    resultarr[cnt2][0] = right.front().second;
                    right.pop();
                    person++;
                    cnt2++;
                }
                time += t;
                for(int i = cnt;i<person+cnt;i++){
                    resultarr[i][1] = time;
                }
                cnt += person;
                direction = "left";
            }
            else if(direction == "right" && !right.empty() && right.front().first <= time){//현 위치가 right이면서 right에 사람이 있을 때
                while(!right.empty() && person < M && right.front().first <= time){
                    resultarr[cnt2][0] = right.front().second;
                    right.pop();
                    person++;
                    cnt2++;
                }
                time += t;
                for(int i = cnt;i<person+cnt;i++){
                    resultarr[i][1] = time;
                }
                cnt += person;
                direction = "left";
            }
            else if(direction == "right" && !left.empty() && left.front().first <= time){//현 위치가 right이면서 left에 사람이 있을 때
                time += t;
                while(!left.empty() && person < M && left.front().first <= time){
                    resultarr[cnt2][0] = left.front().second;
                    left.pop();
                    person++;
                    cnt2++;
                }
                time += t;
                for(int i = cnt;i<person+cnt;i++){
                    resultarr[i][1] = time;
                }
                cnt += person;
                direction = "right";
            }
        }else{
            time++;
        }
    }
    
    for(int i = 0;i<N;i++){
        resvt.push_back({resultarr[i][0], resultarr[i][1]});
    }
    sort(resvt.begin(), resvt.end(), compare);

    for(int i = 0;i<cnt;i++){
        cout << resvt[i].second << '\n';
    }
}
/*'
어...아이디어 자체를 떠올리는 건 어렵지 않은데 고려해야할 게 엄청 많다.

1. 우선 큐를 2개 둬서 왼쪽 큐 오른쪽 큐로 분리했다. 각각의 방향에 대기하는 사람들을 넣는다.
**1-1. "입력받은 순서대로" 출력해야하므로 pair한 상태로 i도 같이 큐에 넣어준다.

2. 초기 방향은 왼쪽이고, 두 큐가 모두 비어야 종료되는 반복문을 설정한다.

3. 각각의 큐가 비어있지 않고 도착한 사람이 있는지 확인하고, 크게 4가지 조건으로 나눠준다. 
(도착한 사람이 없으면 시간을 1초 증가시킨다.)
1- 배 위치가 left이고 left에 도착한 사람이 존재한다.
2- 배 위치가 left이고 right에 도착한 사람이 존재한다.
3- 배 위치가 right이고 right에 도착한 사람이 존재한다.
4- 배 위치가 right이고 left에 도착한 사람이 존재한다.

3-1. 각각의 조건에서 최대로 태울 수 있는 사람까지 태우는데 결과 배열[0]에 입력 순서를 넣어준다.
(입력 순서대로 출력하기 위함)
현재 시간에 += t 하고 결과 배열[1]에 도착한 시간을 넣어준다.
방향은 도착한 곳으로 바꿔준다.

4. 결과 배열에 모두 저장을 완료했어도 입력 순서대로 출력해야 한다.
이때 단순히 sort 함수를 쓸 순 없다. 1차원 배열이면 가능하나 2차원 배열이면 1차원 배열처럼 똑같이 하는 건 불가능
그래서 찾아본 결과 vector를 이용하는 방법으로 해봤다.
우선 resultarr를 vector에 그대로 옮겨준다. 이때부터 sort 함수를 사용할 수 있다.
대신 정렬 기준을 정해줘야 하므로 인덱스 순서대로 정렬하는 추가적인 함수를 만들어준 후 시행한다.
정렬을 완료했다면 벡터에 저장된 값을 순서대로 출력해주면 완료된다.


3-1번까지는 그래도 어떻게든 했었는데 4번을 떠올리긴 사실상 어려웠다. 
vector가 익숙하지 않고 벡터를 이용한 소트 함수를 작성하는 것도 떠올리긴 더욱 어려웠다.

근데 이럴거면 vector에 먼저 받아도 되지 않았을까? 
그렇지만 내 코드 특성상 불가능할 듯?(다르게 하면 모르겠다만)
왜냐하면 구조상 인덱스 값을 먼저 넣은 후에 시간값을 넣어야 했기 때문이다. 
벡터에는 동시에 넣어야 하는데 그렇게 하기 어려웠다.

기억해야 할 것:
2차원 배열을 sort로 정렬하려하지 마라. 정 하고 싶으면 vector에 옮겨서 해라.
compare 함수를 만드는 법을 기억하자.
한 인덱스에 2개의 요소가 있으면 (const pair<int, int>& a, const pair<int, int>& b)와 같이 매개변수를 작성해야 한다.
그리고 두 요소 중 어느것을 기준으로 정렬할 지 정하면 된다.
*/