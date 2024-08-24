#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    deque <char> dq;
    int N, pos = 0, b = 0, w = 0;
    string input;
    cin >> N;

    for(int i = 0;i<N;i++){
        cin >> input;
        if(input == "push"){
            cin >> input;
            if(input == "b"){
                dq.push_front('b');
                b++;
            }else if(input == "w"){
                dq.push_front('w');
                w++;
            }
        }
        else if(!dq.empty() && input == "pop"){
                if(dq.back() == 'b') b--;
                else if(dq.back() == 'w') w--;
                dq.pop_back();
        }
        else if(input == "count"){
            cin >> input;
            if(input == "b"){
                cout << b << '\n';
            }else if(input == "w"){
                cout << w << '\n';
            }
        }
        else if(input == "rotate"){
            cin >> input;
            if(input == "r"){
                pos = (pos+1)%4;
            }else if(input == "l"){
                pos = (pos+3)%4;
            }
        }
        if(pos % 4 == 1){
            while(!dq.empty() && dq.back() != 'w'){
                dq.pop_back();
                b--;
            }
        }else if(pos % 4 == 3){
            while(!dq.empty() && dq.front() != 'w'){
                dq.pop_front();
                b--;
            }
        }
    }
}
/*
초기 pos = 0
큐를 반시계방향(l)으로 돌리면 pos = (pos+3)%4
시계방향(r)으로 돌리면 pos = (pos+1)%4

실제 큐는 앞 뒤 형태이다.

넣는 거와 빼는 것의 회전 상태에 따라 구분지을 필요는 없다.
큐를 직접 회전시킬 수 없으므로 중력의 방향을 바꾸면서 해야 한다.
**즉, 큐가 회전하는 대신에 중력의 방향이 움직이고 있으므로 앞 뒤 구분 처리를 할 필요가 없어진다.

예: pos = 2에서 중력 방향도 조절하고 또한 큐도 앞, 뒤로 바꼈다고 하자.
잘 보면 결국 pos = 0과 달라진 게 하나도 없다. 
어느 한 조건만 써야하는데 두 개를 다 쓰니까 이상해지는 거다.

pos 0
중력 영향은 없다.
push front, pop back

pos 1
중력은 오른쪽 방향으로 향한다. 중력 영향 pop back
push front, pop back

pos 2
중력 영향은 없다.
push front, pop back

pos 3
중력은 왼쪽 방향으로 향한다. 중력 영향 pop front
push front, pop back


원래 생각했던 거는 실제 그림이랑 반대로 되어있음에도
단순히 뒤를 앞으로 앞을 뒤라 치고 했는데,
실제로는 그렇게 하면 반전이 되어서 논리적 오류가 발생한듯하다.
두번째 생각으로는 직접 머릿속으로 구현하면서 하나하나 해봤는데, 이것도 결국 오류였던듯 하다.
예시에서 설명한 경우 때문에 또 틀리게 되었다.
번외: 이걸 한 번에 푼 놈은 머리가 진짜 좋은거 아닐까??

9
push b
push w
push b
push b
count b
count w
pop
rotate r
count b

3
1
2

13
push b 
rotate r 
count b 0
rotate r
push b 
push w 
rotate r
push b 
push b
count b 
rotate l
push b
count b

0
1
2
*/