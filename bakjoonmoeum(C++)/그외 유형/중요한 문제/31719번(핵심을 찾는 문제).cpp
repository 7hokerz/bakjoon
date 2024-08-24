#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N, A;
    cin >> T;
    for(int i = 0;i<T;i++){
        //queue <int> U;//열린 스택
        queue <int> D;
        queue <int> P;
        stack <int> res;
        int errcnt = 0;
        cin >> N;
        for(int j = 0;j<N;j++){
            cin >> A;
            if(errcnt) continue;
            else if(A == 1 || (!res.empty() && A == res.top() + 1)){
                res.push(A);
            }
            else if(P.empty() || (!P.empty() && P.back() + 1 == A)){
                P.push(A);
            }
            else if(D.empty() || (!D.empty() && D.back() + 1 == A)){
                D.push(A);
            }
            else if(!P.empty() && !res.empty() && (P.front() == res.top() + 1)){
                while(!P.empty()){
                    res.push(P.front());
                    P.pop();
                }
                P.push(A);
            }
            else if(!D.empty() && !res.empty() && (D.front() == res.top() + 1)){
                while(!D.empty()){
                    res.push(D.front());
                    D.pop();
                }
                D.push(A);
            }
            else{
                errcnt++;
            }
        }
        if(errcnt) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
}
/*
어쩌다 보니 운 좋게 반례를 찾아서 정답을 맞출 수 있었다.

과정 자체는 간단
1.스택이라고 했지만 바닥이 열린다는 설명이 있어 큐로 구현했다.
2.하나를 항상 비워두는 큐라고 가정하고 2개의 큐만 만들어놨다.
3.1이 아니거나 res.top보다 +1이 아니면 D나 P에 넣는다.
3-1.D가 비어있거나 D의 back보다 +1인 경우에만 큐에 삽입해준다.(P도 똑같다.)
4.만약 두 큐에 들어갈 수 없는 경우도 있다. 이때 두 큐의 front가 res.top + 1인지 확인하여 맞으면 큐를 비운 후 요소를 넣어준다.
5.위 경우가 아니면 불가능으로 간주한다.

처음엔 단순히 두 큐에는 비운다는 생각 없이 back()보다 낮은 수가 오면 불가능하다고 처리했는데, 조건이 부족했다.

그래서 두 번째에는 
만약 front가 res.top + 1 이면 비우는 조건을 추가했지만 틀렸다. 위의 조건을 수정을 안해줘서...

마지막으로 back에는 +1의 수만 오도록 수정했고 결과는 성공적이었다.

설명에 스택이니 뭐니 하는 건 필요가 없었다. 설명에 필요없는 내용이 좀 많음.

1

2 3 
4 5
6이 온다면 가능하다.

1

2 4
3 5
이렇게 되면 안된다. 한꺼번에 빠져나갈 때 오름차순이 성립하지 않는다.
결론은 큐 또한 1차이나는 오름차순이어야 한다.
*/