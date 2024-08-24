#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);//이것들 써줘야한다!
    cin.tie(NULL);

    deque <int> dq;
    int N, com, input;
    int count = 0;
    cin >> N;

    for(int i = 0;i<N;i++){
        cin.ignore();
        cin >> com;
        if(com == 1){//정수 input을 덱의 앞에 넣기
            cin >> input;
            dq.push_front(input);
            count++;
        }
        else if(com == 2){//정수 input을 덱의 뒤에 넣기
            cin >> input;
            dq.push_back(input);
            count++;
        }
        else if(com == 3){//덱에 정수가 있으면 맨 앞의 정수를 제거 후 출력
            if(count == 0) cout << -1 << '\n';//없으면 -1 출력
            else{
                cout << dq.front() << '\n';
                dq.pop_front();
                count--;
            }
        }
        else if(com == 4){//덱에 정수가 있으면 맨 뒤의 정수를 제거 후 출력
            if(count == 0) cout << -1 << '\n';//없으면 -1 출력
            else{
                cout << dq.back() << '\n';
                dq.pop_back();
                count--;
            }
        }
        else if(com == 5) cout << count << '\n';//사이즈 출력
        else if(com == 6) {
            if(count == 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(com == 7){//제거하지 않고 맨 앞의 정수 출력
            if(count == 0) cout << -1 << '\n';
            else cout << dq.front() << '\n';
        }
        else if(com == 8){//제거하지 않고 맨 뒤의 정수 출력
            if(count == 0) cout << -1 << '\n';
            else cout << dq.back() << '\n';
        }
    }
}