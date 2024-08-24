#include <iostream>
#include <stack>
using namespace std;
/*
보면 line과 plat을 입력받고 
line변수만을 이용해 어떤 스택에 넣을지 조작하는 모습이다.
잘 확인하고 써먹도록 하자.
*/
int main(){
    int cnt=0;
    int N, P;
    cin>> N >> P;
    stack<int>guitar[6];

    for(int i=0; i < N; i++){
        int line, plat;
        cin >> line >> plat;

        if(guitar[line-1].empty()){
            guitar[line-1].push(plat);
            cnt++;
        }
        else if (guitar[line-1].top() <plat){
                cnt ++;
                guitar[line-1].push(plat);
        }
        else  if(guitar[line-1].top() == plat ){
            continue;
        }
        else if(guitar[line-1].top() > plat){
            while(!guitar[line-1].empty() && guitar[line-1].top() > plat){
                guitar[line-1].pop();
                cnt ++;
            }

            if(!guitar[line-1].empty() && guitar[line-1].top() == plat ){
                continue;
            }
            else{
                guitar[line-1].push(plat);
                cnt++;
            }
        }
    }
    cout << cnt;
    exit(0);
}
