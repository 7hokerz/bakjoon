#include <iostream>
#include <deque>
#include <string>
using namespace std;
/*
기술을 써서 나온 결과는 1, 2, 3...N으로 순서대로 이므로 기술을 쓴 순서의 반대로 기술을 읽으면서 결과를 맞춰볼 수 있다.
1. 제일 위의 카드 1장을 바닥에 내려놓는다.
2. 위에서 두 번째 카드를 바닥에 내려놓는다. 카드가 2장 이상일 때만 쓸 수 있다.
3. 제일 밑에 있는 카드를 바닥에 내려놓는다. 카드가 2장 이상일 때만 쓸 수 있다.
*/
int main(){
    int N, teq, temp;
    string result;
    cin >> N;
    deque <int> dq;
    deque <int> dqres;

    for(int i = 0;i<N;i++){//쓴 기술을 순서대로 덱에 저장
        cin >> teq;
        dq.push_back(teq);
    }
    for(int i = 1;i<N+1;i++){//dq의 마지막 요소를 검사를 시작하여 값에 따라 dqres에 넣기
        if(dq.back() == 1){//맨 윗 장을 내려놓은 것이므로 front에 삽입
            dqres.push_front(i);
        }
        else if(dq.back() == 2){//위에서 두 번째 장을 내려놓은 것이므로 front를 제거 후 해당 요소를 삽입하고 제거한 요소를 다시 front에 삽입
            temp = dqres.front();
            dqres.pop_front();
            dqres.push_front(i);
            dqres.push_front(temp);
        }
        else if(dq.back() == 3){//밑에 있는 카드를 내려놓은 것이므로 back에 삽입
            dqres.push_back(i);
        }
        dq.pop_back();
    }
    for(int i = 0;i<N;i++){
        result += to_string(dqres.front());//숫자를 문자열로(**N이 한 자리수가 아니므로 +'0'은 두자리수 이후부터 잘못된 값이 나오게 됨.)
        result += " ";//공백 추가
        dqres.pop_front();//제거해야 front함수로 계속 확인 가능
    }
    cout << result << endl;
}