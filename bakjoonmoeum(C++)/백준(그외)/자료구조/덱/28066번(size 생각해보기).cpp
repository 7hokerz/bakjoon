#include <iostream>
#include <deque>
using namespace std;
/*
첫 번째 청설모 제외한 K번째까지 제거되고, 첫번째만 산다.(단, K마리보다 적었을 경우에는 첫번째 청설모를 제외한 모두 제거됨)
제거된 후 남아있는 게 2마리 이상이면 첫 번째의 오른쪽이 첫번째 청설모가 되고, 과정이 반복됨.
마지막 남는 청설모의 번호 출력
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    deque <int> dq;
    int N, K;//청설모의 수, 첫 번째 부터 K번째까지 선택되는 수
    int first;//첫 번째 청설모
    cin >> N >> K;

    for(int i = 1;i<N+1;i++){//삽입
        dq.push_back(i);
    }

    first = 1;
    while(dq.size() != 1){
        for(int i = 0;i<K;i++){//k마리 제거
            dq.pop_front();
            if(dq.size() == 0) break;
        }
        dq.push_back(first);
        first = dq.front();//첫번째 청설모 초기화

        if(dq.size() < K){//사이즈가 K보다 작으면 제거 후 한 마리만 남게 되므로
            
            for(int i = 0;i<K;i++){//k마리 제거
                dq.pop_front();
                if(dq.size() == 0) break;
            }
            cout << first << '\n';
            break;
        }
    }
}
//size가 1이 아니고 0이어야 하는 이유?
//추측으로 원래 제거되어야 할 요소가 size==1로 인해 제거가 안되어 생긴 문제이지 않을까?라고 생각 중...자세한 건 모르겠다.