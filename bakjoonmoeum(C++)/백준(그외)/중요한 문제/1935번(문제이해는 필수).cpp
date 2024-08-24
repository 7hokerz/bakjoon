#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cctype>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    queue <pair<char, double>> q;
    stack <double> res;
    int N;
    double op, tmp;
    string input;
    cin >> N >> input;

    for(int i = 0;i<N;i++){//1
        cin >> op;
        q.push({'A'+i, op});
    }

    for(int i = 0;i<input.length();i++){
        if(input[i] == q.front().first){//2
            res.push(q.front().second);
        }else if(isalpha(input[i]) && 
        input[i] != q.front().first){
            while(input[i] != q.front().first){
                q.push(q.front());
                q.pop();
            }
            res.push(q.front().second);
        }
        else if(input[i] == '*' || input[i] == '+' || 
        input[i] == '/' || input[i] == '-'){//3
            tmp = res.top();
            res.pop();
            if(input[i] == '*') tmp *= res.top();
            else if(input[i] == '+') tmp += res.top();
            else if(input[i] == '/') tmp = res.top() / tmp;
            else if(input[i] == '-') tmp = res.top() - tmp;
            res.pop();
            res.push(tmp);
        }
    }
    while(!res.empty()){
        printf("%.2lf", res.top());
        res.pop();
    }
}
/*
이번 문제는 이해를 잘못한 부분이 많이 문제가 되었다.

과정:
1. 알파벳에 대응하는 피연산자를 맞추기 위해 pair를 쓰는 큐에 순서대로 집어넣는다.
2. input 문자열을 스캔하면서 알파벳을 찾으면 그와 일치하는 피연산자를
res 스택에 삽입한다.
3. 연산자를 찾으면 상단 2개의 요소를 꺼내어 연산한 후 다시 스택에 삽입한다.
위와 같은 과정을 반복하면 결과값이 출력된다.

주의사항:
1. 실수형 결과이므로 double형을 사용해야 한다.

2. 처음에는 큐에 pair 형태로 넣고, input 스캔 중 맞는 알파벳이 발견되면
큐에서 지우는 형태로 진행하였다.
하지만 간과한 사실은 주어지는 문자열은 알파벳이 항상 사전순대로 나오지는 않기 때문에,
BABA와 같은 문자열을 하는 순간 이상한 값이 출력되게 된다.
(A부터 순서대로 N개의 영대문자만이 사용되며...)
(ㅅㅂ 이거보고 난 문자열도 순서대로인줄 알았지...)
어찌됐든 이 부분을 알고나서 큐에서 pop하는 명령을 지우고
해당 알파벳을 찾을때까지 순환시키는 방식으로 알고리즘을 바꾸었다.


stack pair 형태의 값을 확인하는 방법:
st.top().first: 첫 번째 요소의 값 확인(char)
st.top().second: 두 번째 요소의 값 확인(int)
*/