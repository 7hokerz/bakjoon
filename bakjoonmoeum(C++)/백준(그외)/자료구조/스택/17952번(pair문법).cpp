#include <iostream>
#include <string>
#include <stack>
using namespace std;

class task{
public:
    int score;
    int time;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack <task> st;
    int N, num, A, T, score = 0;
    cin >> N;

    for(int i = 0;i<N;i++){
        cin >> num;
        if(num == 1){
            cin >> A >> T;
            task task;
            task.score = A;
            task.time = T-1;
            st.push(task);
        }else if(num == 0){
            if(st.empty()){
                continue;
            }
            st.top().time--;
        }
        if(st.top().time == 0){
            score += st.top().score;
            st.pop();
        }
    }
    cout << score;
}
/*
stack <pair<int, int>> st;
pair는 서로 다른 두 데이터를 묶어서 스택에 저장하는 것
쓰는 법: 
cin >> A >> T;
st.push({A, T});
중괄호로 묶어서 표현한다.
*/
