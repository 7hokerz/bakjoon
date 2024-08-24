#include <iostream>
#include <queue>
using namespace std;

class qst{
public:
    queue <int> q;
    deque <int> ele;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;//수열의 수
    int input;
    qst qst;
    queue <int> result;
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> input;
        qst.q.push(input);
    }
    for(int i = 0;i<N;i++){
        cin >> input;
        if(qst.q.front() == 0){
            qst.ele.push_back(input);
            qst.q.pop();
        }else{
            qst.q.pop();
        }
    }
    //결과적으로 ele 덱에는 큐만 담기게 됨.
    cin >> M;
    for(int i = 0;i<M;i++){
        cin >> input;
        qst.ele.push_front(input);
        result.push(qst.ele.back());
        qst.ele.pop_back();
    }

    for(int i = 0;i<M;i++){
        cout << result.front() << ' ';
        result.pop();
    }
}
/*
0(큐), 1(스택)
스택인 부분의 리턴값은 항상 입력값이다.
(즉, 스택 부분은 따질 필요가 없다.)
큐인 부분의 리턴값은 항상 큐에 원래 있던 값이다.
2,4,7

1,4 처음
2,1 >> 4
4,2 >> 1
7,4 >> 2

ele 덱에서 input을 front에 추가하고,
back값을 result 큐에 저장한 후 pop_back한다.
*/