#include <iostream>
#include <deque>
using namespace std;
//13417번
/*
가장 왼쪽에 있는 카드부터 가져오는데, 가장 왼쪽이나 오른쪽에 둘 수 있다.
즉, 사전순으로 앞에있는 알파벳을 왼쪽에, 뒤에있는 알파벳을 오른쪽에 두는 게 좋다.
*/

int main(){
    int T, N;//테스트 데이터, 알파벳의 개수
    char str, Temp;
    string result;
    deque <char> dq;//입력값을 담을 덱
    deque <char> dqres;//결과를 담을 덱

    cin >> T;
    for(int i = 0;i<T;i++){
        cin >> N;
        for(int j = 0;j<N;j++){
            cin >> str;
            dq.push_back(str);
        }
        
        dqres.push_front(dq.front());//첫번째 값은 먼저 덱에 넣기
        dq.pop_front();

        for(int k = 0;k<N-1;k++){
            Temp = dq.front();//왼쪽 값을 확인
            dq.pop_front();//제거

            if(dqres.front() < Temp){//결과덱의 왼쪽값보다 사전순으로 밀리면 항상 오른쪽에 넣고
                dqres.push_back(Temp);
            }else{//사전순으로 같거나 앞서면 왼쪽에 넣는다.
                dqres.push_front(Temp);
            }
        }

        for(int h = 0;h<N;h++){//차례대로 결과스트링에 삽입
            result += dqres.front();
            dqres.pop_front();
        }
        cout << result << endl;

        result = "";
    }
}