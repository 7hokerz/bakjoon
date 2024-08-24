#include <iostream>
#include <cmath>
using namespace std;

int dig(int n){
    int cnt = to_string(n).length();
    int sum = 0;
    int num = pow(10,cnt-1);
    while(n > 0){  
        sum += n/num;
        n %= num;
        num /= 10;
    }
    if(sum > 9) sum = dig(sum);
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int i = 0;i<T;i++){
        int K, M, loc = 0, gold = 1, x = 0, y = 0;
        cin >> K >> M;
        for(int i = 0;i<K;i++){
            gold = dig(gold);
            if(loc == 0) y += gold;
            else if(loc == 1) x += gold;
            else if(loc == 2) y -= gold;
            else if(loc == 3) x -= gold;
            loc = (loc+1)%4;
            gold *= M;
        }
        cout << x << ' ' << y  << '\n';
    }  
}
/*
20:124875....
21:1399999...
22:147147...
23:157842...
for(int i = 0;i<cnt;i++){
    cout << arr[i] << ' ';
}

좌표 및 dig함수에서 패턴이 반복되는 부분이 존재한다. 나중에 이걸 어떤 식으로 줄일 지 생각해보자.
dig는 보통 i-1과 i이 같은 경우(간격 1), i와 i-3이 같은 경우(간격 3), i와 i-6이 같은 경우(간격 6)이 존재함.
또한 좌표는 특정 부분부터 같은 4개 또는 12개의 좌표가 반복되는 부분이 존재함.

20:124875....
21:1399999...
22:147147...
23:157842...
for(int i = 0;i<cnt;i++){
    cout << arr[i] << ' ';
}
*/