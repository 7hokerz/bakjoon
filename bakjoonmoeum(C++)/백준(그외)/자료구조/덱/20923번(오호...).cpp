#include <iostream>
#include <deque>
using namespace std;
/*
종을 치는 조건
1. 가장 위에 위치한 카드의 숫자 합이 5(단 카드가 한 개인 경우 제외(5만 나온 경우)) >> 수연
2. 가장 위에 위치한 카드의 숫자가 5 >> 도도

카드를 가져올 때 조건
1. 상대방 카드 더미를 통째로 뒤집어 자신의 덱 아래로 넣기
2. 자신의 그라운드에 있는 카드 더미 또한 뒤집어 자신의 덱 아래로 넣기

이기는 조건
1. 카드 개수가 0이 되면 지는 것
2. M번 진행 후 카드를 더 많이 가진 사람이 승리
3. 카드 개수가 서로 같으면 비긴 것
*/
void size0(int dodo, int suy){
    if(dodo == 0) {
        cout << "su" << '\n';
        exit(0);
    }//둘 중 하나가 먼저 0이 되면 상대방의 승리
    else if(suy == 0){
        cout << "do" << '\n';
        exit(0);
    }
}

int proceed(deque <int> *dodo, deque <int> *suy, deque <int> *grounddo, deque <int> *groundsuy, int *i){
    if((!grounddo->empty() && (grounddo->back() == 5)) || (!groundsuy->empty() && (groundsuy->back() == 5))){//만약 둘 중 하나라도 5가 나오면
        while(!groundsuy->empty()){//그라운드에있는 suy카드를 모두 dodo에게 주고
            dodo->push_front(groundsuy->front());
            groundsuy->pop_front();
        }
        while(!grounddo->empty()){
            dodo->push_front(grounddo->front());//그라운드에있는 dodo카드를 가진다.
            grounddo->pop_front();
        }
    }
    else if(grounddo->empty() || groundsuy->empty()){//grounddo에 아무것도 없는데 back을 확인하려는 경우 오류 발생하므로 넘기기
        (*i)++;
        size0(dodo->size(), suy->size());//사이즈를 확인하여 0인 경우를 찾기
        return 0;
    }
    else if((grounddo->back() + groundsuy->back()) == 5){
        while(!grounddo->empty()){//그라운드에있는 dodo카드를 모두 suy에게 주고
            suy->push_front(grounddo->front());
            grounddo->pop_front();
        }
        while(!groundsuy->empty()){
            suy->push_front(groundsuy->front());//그라운드에있는 suy카드를 가진다.
            groundsuy->pop_front();
        }
    }
    (*i)++;
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    deque <int> dodo;
    deque <int> suy;
    deque <int> grounddo;
    deque <int> groundsuy;
    int Temp1, Temp2;//Temp1은 dodo, Temp2는 suy에서 쓰임
    int N, M;//카드 개수, 게임 진행 횟수
    cin >> N >> M;

    for(int i = 0;i<N;i++){//카드를 각자의 덱에 순서대로 넣어주기
        cin >> Temp1 >> Temp2;
        dodo.push_back(Temp1);
        suy.push_back(Temp2);
    }

    for(int i = 0;i<M;){//게임 시작(게임 진행 수를 i라고 하자)
        if(i%2 == 0){//dodo가 하는 차례
            grounddo.push_back(dodo.back());//dodo가 카드를 그라운드에 놓는다.
            dodo.pop_back();
            size0(dodo.size(), suy.size());//가지고 있는 카드 개수 확인
            proceed(&dodo, &suy, &grounddo, &groundsuy, &i);
        }else{//suy가 하는 차례
            groundsuy.push_back(suy.back());//suy가 카드를 그라운드에 놓는다.
            suy.pop_back();
            size0(dodo.size(), suy.size());//가지고 있는 카드 개수 확인
            proceed(&dodo, &suy, &grounddo, &groundsuy, &i);
        }
        size0(dodo.size(), suy.size());//사이즈를 확인하여 0인 경우를 찾기
    }
    //cout << dodo.size() << suy.size() << ' \n';//사이즈 확인 코드
    if(dodo.size() > suy.size()) cout << "do" << '\n';
    else if(dodo.size() < suy.size()) cout << "su" << '\n';
    else if((dodo.size() == suy.size()) && ((dodo.size() + suy.size()) > 0)) cout << "dosu" <<'\n';
}
/*
1.
2 3>> do 9 su 11 m=2
5>> do 9 su 11 m=3
  1
2 1
2 5 >> do 12 su 8 m=8
2 2
3 >> do 10 su 10 m=11
  1 (end) >> do 10 su 9 m=12 do
3.
1 1
2 2 (end) >> do 1 su 1 m=4 dosu
*/