#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cctype>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    queue <char> cm;
    stack <int> change;
    deque <int> num;
    int T, N, cntR = 0, error=0;
    string com, input, tmp = "";
    cin >> T;
    for(int i = 0;i<T;i++){
        cin >> com >> N >> input;
        for(int j = 0;j<com.length();j++){
            cm.push(com[j]);
        }
        
        for(int j = 1;j<input.length();j++){//덱에 숫자를 삽입
            if(isdigit(input[j])) tmp += input[j];
            else if(input[j] == ',' || j == input.length() - 1){
                if(tmp == "") continue;
                num.push_back(stoi(tmp));
                tmp = "";
            }
        }

        while(!cm.empty()){
            if(cm.front() == 'R'){
                cntR++;
            }else if(cm.front() == 'D'){
                if(num.empty()){
                    cout << "error" << '\n';
                    error++;
                    while(!cm.empty()) cm.pop();
                    while(!num.empty()) num.pop_front();
                    break;
                }else{
                    if(cntR%2 == 0) num.pop_front();
                    else num.pop_back();
                }
            }
            cm.pop();
        }
        
        if(error == 1){
            error--;
            cntR = 0;
            continue;
        }

        if(cntR%2==1){
            while(!num.empty()){
                change.push(num.front());
                num.pop_front();
            }
            while(!change.empty()){
                num.push_back(change.top());
                change.pop();
            }
        }

        cout << '[';
        while(!num.empty()){
            if(num.size() == 1){
                cout << num.front();
            }else{
                cout << num.front() << ',';
            }
            num.pop_front();
        }
        cout << ']' << '\n';
        cntR = 0;
    }
}
/*
R이 들어올 때마다 뒤집는 건 비효율적일
가능성 100% 
cntR 도입으로 해결

중요한 건 예외처리도 예외처리인데, 케이스가 여러개라서
자료구조, 변수 등이 누적되지 않도록 주의해야한다.
(한개라도 초기화 안하면 얄짤없이 틀릴 확률 99.9%)

53211

4
RDD
4
[1,2,3,4]
DD
1
[42]
RRD
6
[1,1,2,3,5,8]
D
0
[]

[2,1]
error
[1,2,3,5,8]
error
*/