#include <iostream>
#include <deque>
#include <math.h>
#include <string>
using namespace std;
/*
1. 소수 번째가 아니고 A의 끝에 B를 추가
2. 소수 번째인 경우에는 A의 마지막 문자가 B면 B를 S로 바꾼 후 마지막에 S를 추가한다.(즉, B--, S += 2)
2-1. A의 마지막 문자가 B가 아니라면 S만 추가한다.(즉, S++)
...
3. B의 개수와 S의 개수를 리턴한다.
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, B = 0, S = 0;//정수 N, 각각 B와 S의 개수
    cin >> N;
    deque <int> dq;
    string A;
    //에라토스테네스의 체를 이용한 소수 구하기(O(Nlog(logN)))(합성수를 false로 만드는 방식)
    //(어떤 수가 소수라면 어떤 수의 배수들은 모두 어떤 수의 약수를 가지고 있으므로 소수가 될 수 없음.)
    //배열을 만들고 true로 채운 뒤 2부터 시작하면 2를 제외한 2의 배수는 false, 3이 되면 3을 제외한 3의 배수들은 false...가 반복된다.
    bool *isPrime = new bool[N+1];
    for(int i = 0;i<=N;i++){
        isPrime[i] = true;
    }
    for(int i = 2;i<=N;i++){
        if(isPrime[i]){
            for(int j = i * 2;j<=N;j += i){
                isPrime[j] = false;
            }
        }
    }

    dq.push_back('B');
    B++;
    for(int i = 2;i<N+1;i++){
        if(isPrime[i]){//소수 번째인 경우
            if(dq.back() == 'B'){//마지막 문자가 B인 경우
                dq.pop_back();
                dq.push_back('S');
                dq.push_back('S');
                B--;
                S += 2;
            }else{//아닌 경우
                dq.push_back('S');
                S++;
            }
        }else{//소수 번쨰가 아닌 경우
            dq.push_back('B');
            B++;
        }
    }
    cout << B << ' ' << S;
    delete [] isPrime;
}