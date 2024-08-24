#include <iostream>
using namespace std;
//기호 1번이 혼자 1등이 될 최소 매수 수
//1. 기호 1번을 제외한 사람들은 순서가 상관없으므로 큰 수부터 정렬시킨다.(요소를 바꿀 때 temp 변수 사용 필수!)
//2. 기호 1번에 +1 하고 기호 2번에 -1 한다. 매수해야하는 사람에 +1
//3. 이 과정을 반복해서 기호 1번의 득표수가 max보다 높으면 반복을 중지하고 매수자 최소값을 출력한다.

int main(){
    int N, person = 0;
    cin >> N;
    int cand[N];

    for(int i = 0;i<N;i++){
        cin >> cand[i];
    }
    
    if(N == 1){
        cout << 0;
        return 0;
    }

    while(1){//완벽하게 내림차순 정렬을 실행하는 코드
        int all = 0;
        for(int i = N - 1;i > 1;i--){
            int Temp = cand[i-1];
            cand[i-1] = (cand[i] >= cand[i-1])?cand[i]:cand[i-1];
            if(cand[i-1] != Temp) cand[i] = Temp;
        }
        for(int i = N - 1;i > 1;i--){
            if(cand[i] <= cand[i-1]){//순서가 올바른지 확인
                all++;
            }
        }
        if(all == N - 2){//순서가 올바르면 정렬 종료
            break;
        }
    }
    
    while((cand[0] <= cand[1])){

        cand[0]++;//기호 1번에 +1
        cand[1]--;//그 외 최대 득표자 후보의 득표수 -1
        person++;//매수자 수 +1

        for(int i = N - 1;i > 1;i--){
            int Temp = cand[i-1];
            cand[i-1] = (cand[i] >= cand[i-1])?cand[i]:cand[i-1];
            if(cand[i-1] != Temp) cand[i] = Temp;
        }
    }
    cout << person;
}  

/*5 10 8 7 3
6 9 8 7 3 1
7 8 8 7 3 1
8 7 8 7 3 1
8 8 7 7 3
9 7 7 7 3 1

5 7 7 
6 6 7 1
6 7 6 
7 6 6 1


*/
