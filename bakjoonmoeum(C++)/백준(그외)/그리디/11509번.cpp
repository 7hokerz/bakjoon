#include <iostream>
using namespace std;

int check[1000001]={0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, input, maxnum = 0;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> input;
        maxnum = (input>maxnum)?input:maxnum;
        check[input]++;
        if(check[input+1]) check[input+1]--;
    }
    int sum = 0;
    for(int i = 0;i<maxnum+1;i++){
        if(check[i]>0) sum += check[i];
    }
    cout << sum;
}
/* 
처음에는 스택 등을 이용하여 요소를 없애는 방식으로 풀려고 했으나 O(N^2)이라 시간초과가 나게 되어 풀지 못했다.
그러다가...생각난 풀이가 이 방법이다.

check배열: 풍선의 개수를 저장하는 배열이다.
input값이 들어오면 해당 인덱스 값을 +1한다.
이때 input+1의 값이 1이상이면 연속으로 터트릴 수 있으므로 -1을 해준다.
이런 과정을 반복하고나서 배열에서 0이상인 요소들의 합이 바로 필요한 화살의 개수가 된다.
*/