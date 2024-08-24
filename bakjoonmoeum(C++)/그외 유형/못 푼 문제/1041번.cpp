#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, input;
    long long a, b, c, min1, min2, max1;
    int dice[6];
    cin >> N;
    for(int i = 0;i<6;i++){
        cin >> input;
        dice[i] = input*1LL;
    }
    a = min(dice[0], dice[5]);
    b = min(dice[1], dice[4]);
    c = min(dice[2], dice[3]);
    min1 = min(a,min(b,c));
    max1 = max(a,max(b,c));
    min2 = (a!=min1&&a!=max1)?a:(b!=min1&&b!=max1)?b:c;
    
    if(N==1) cout << min2*2+min1*2+max1;
    else if(N==2) cout << (min1+min2)*4+(min1+min2+max1)*4;
    else 
        cout << ((min1+min2)*4+(min1)*(N*4-8))*(N-1)+(min1+min2+max1)*4+(min1+min2)*(N*4-8)+(min1)*(N-2)*(N-2);
}
/*
  3
4 0 1 5
  2

  4
5 1 2 6
  3

가장 위에 있는 걸 제외한 나머지는

2개의 면만 보이게 된다.
그렇다면 가장 작게 가능한 경우?
1 2는 붙어있으므로 가능하다.
그러면 3

가장 위에 있는 것은
총 3개의 면이 보이게 된다.
가장 작게 가능한 경우?
1 2 3이 가능하다.

N=2라고 하면

위를 제외한 합 (1+2)*4=12
위에 있는 합: (1+2+3)*4=24

N=3일때
(1+2)*4+1*4=16
N-1개 즉 2개이므로 16*2=32
윗면은 (1+2+3)*4+(1+2)*4
+1*1=37
총 69

N>2부터는

위를 제외한 곳에는 꼭짓점 부근은 2면,
나머지는 1면만 보인다.
위의 경우는 꼭짓점은 3면, 가장자리는 2면
나머지는 1면만 보인다.

공식:
상단 제외 합:
((a+b)*4+a(N*4-8))*(N-1)

((a+b)*4+(a)*(N*4-8))*(N-1)
상단 합:
(a+b+c)*4+(a+b)*(N*4-8)+(a)*(N-2)*(N-2)


*/