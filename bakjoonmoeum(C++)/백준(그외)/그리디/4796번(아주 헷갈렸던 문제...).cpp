#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int L, P, V;
    for(int i = 1;;i++){
        cin >> L >> P >> V;
        if(L == 0 && P == 0 && V == 0) break;
        if((V%P)/L >= 1) cout << "Case " << i << ": "<< V/P*L + L << '\n';
        else cout << "Case " << i << ": "<< V/P*L + (V%P) << '\n';
    }
}
/*
5 8 22
V/P*L
22-16=6

5 8 20

20-16 =4

4%5 = 4

6/5 = 1

V%P/L>=1의 경우 +L을 하고,
V%P/L<1의 경우 +(V%P)%L을 한다.

우선 휴가/P일을 하여 나눌 수 있는 최대 몫을 구한다. (P는 사용가능한 일+ 사용불가능한 일)
그 후, 나머지를 구하면 2가지의 경우가 존재한다. L일 보다 많거나 같거나,  적거나...
많거나 같은 경우는 L일을 다 사용할 수 있으므로 결과에 L일만 추가해주면 된다.
적은 경우는 L일을 다 사용할 수 없는데, 즉 나머지 값인 V%P의 값을 추가해주면 된다.

지금도 생각하지만 1시간 동안 ㅄ같이 헤메다가 운 좋게 딱 들어맞아서 풀렸다...
한 번 꼬이면 ㅄ이 되는 내 특성이 문제다.
*/