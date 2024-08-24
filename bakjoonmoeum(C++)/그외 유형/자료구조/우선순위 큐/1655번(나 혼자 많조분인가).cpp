#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, input;

priority_queue <int> Lpq;//왼 큐(최대 힙)
priority_queue <int, vector<int>, greater<int>> Rpq;//오 큐(최소 힙)

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1;i<N+1;i++){
        int mid;
        cin >> input;
        if(i == 1){ Lpq.push(input); mid = input;}
        else if(i == 2){
            if(Lpq.top() <= input) Rpq.push(input);
            else{
                Rpq.push(Lpq.top()); Lpq.pop(); Lpq.push(input); 
            }
        }
        else{
            if((Lpq.top() < input && input <= Rpq.top()) || (Lpq.top() == input && input == Rpq.top())){
                if(Lpq.size() <= Rpq.size()) Lpq.push(input);
                else Rpq.push(input);
            }
            else if(Lpq.top() > input && Lpq.top() <= Rpq.top()){
                if(Lpq.size() <= Rpq.size()) Lpq.push(input);
                else{
                    Rpq.push(Lpq.top()); Lpq.pop();
                    Lpq.push(input);
                }
            }
            else if(Rpq.top() < input && Lpq.top() <= Rpq.top()){
                if(Lpq.size() >= Rpq.size()) Rpq.push(input);
                else{
                    Lpq.push(Rpq.top()); Rpq.pop();
                    Rpq.push(input);
                }
            }
            else if(Lpq.top() == input && input < Rpq.top()){
                if(Lpq.size() >= Rpq.size()) Rpq.push(input);
                else Lpq.push(input);
            }
        }
        if(i > 1 && i % 2 == 1){//홀수개라면
            if(Lpq.size()>Rpq.size()) mid = Lpq.top();
            else mid = Rpq.top();
        }else if(i > 1){//짝수개라면
            mid = min(Lpq.top(),Rpq.top());
        }
        cout << mid << '\n';
    }
}
/*
나중에 다른 짧은 풀이 참고해보기
7
1 5 2 10 -99 7 5

왼 우큐, 오 우큐 생성(첫 요소는 왼쪽으로)(왼 우큐는 최대 힙, 오 우큐는 최소 힙)
**왼 우큐는 작은 수, 오 우큐는 큰 수가 들어간다.

1.1 왼 < 요소 <= 오  사이즈에 따라 결정. 
1.1.1 왼 사이즈 =< 오 사이즈 >> 왼
1.1.2 왼 사이즈 > 오 사이즈 >> 오

1.2 요소 < 왼 <= 오 
1.2.1 왼 사이즈 =< 오 사이즈 >> 왼
1.2.2 왼 사이즈 > 오 사이즈 >> 왼 우큐 탑을 제거 후 오 우큐로 옮기고, 왼쪽에 요소 삽입

1.3 왼 <= 오 < 요소 
1.3.1 왼 사이즈 => 오 사이즈 >> 오
1.3.2 왼 사이즈 < 오 사이즈 >> 오 우큐 탑을 제거 후 왼 우큐로 옮기고, 오른쪽에 요소 삽입

1.4 왼 == 요소 < 오
1.4.1 왼 사이즈 >= 오 사이즈 >> 오
1.4.2 왼 사이즈 < 오 사이즈 >> 왼

1.5 왼 == 요소 == 오
1.5.1 왼 사이즈 =< 오 사이즈 >> 왼
1.5.2 왼 사이즈 > 오 사이즈 >> 오


처음 두 요소를 삽입할 때 첫 요소는 왼쪽에 넣고 두 번째는 왼쪽의 탑과 비교해서 조작하여 1:1 사이즈로 만든다.
두 요소가 같거나, 왼쪽보다 크면 오른쪽에
왼쪽이 더 크면 왼쪽을 오른쪽에 넣고, 왼쪽에 삽입
1 >> 왼쪽에 삽입 1
5 >> 오른쪽에 삽입 1 , 5

2 >> 1.1.1에 따라 왼쪽 삽입 1 2 , 5
10 >> 1.3.2에 따라 오른쪽 삽입 1 2 , 5 10
-99 >> 1.2.1에 따라 왼쪽 삽입 -99 1 2 , 5 10
7 >> 1.3.2에 따라 오른쪽 삽입 -99 1 2 , 5 7 10
5 >> 1.1.1에 따라 왼쪽 삽입 -99 1 2 5 , 5 7 10

10
5 10 15 20 11 12 11 4 14 11

5 >>5
5,10 >>5
5,10 15 >>10
5 10,15 20 >>10
5 10 11,15 20 >>11
5 10 11,12 15 20>>11
5 10 11,11 12 15 20>>11
4 5 10 11,11 12 15 20>>11
4 5 10 11,11 12 14 15 20>>11
4 5 10 11 11,11 12 14 15 20>>11
*/