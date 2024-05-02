#include <iostream>
#include <stack>
using namespace std;
//요약: 어느 부분 수열에서 최솟값에 따라서 값이 좌지우지 되는 경우 오름차순 모노톤을 이용하자.
//즉 이전 값보다 작은 값이 들어오면 이후의 값은 그 작은 값을 따라가므로 이전 값이 필요없기 때문이다.
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    long long input;
    long long res = 0;
    stack <pair<int,long long>> st;//값, 합
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> input; input *= 1LL;
        if(!st.empty()){
            if(!st.empty() && st.top().first > input){
                long long tmp = st.top().second;//수의 합
                while(!st.empty() && st.top().first > input){
                    long long sum = tmp * st.top().first;//합*최솟값
                    res = (sum>res)?sum:res;
                    st.pop();
                    if(!st.empty() && st.top().first > input) tmp += st.top().second;
                }
                st.push({input,input+tmp});
            }
            else st.push({input,input});
        }
        else st.push({input, input});//값, 수의 합
    }
    while(!st.empty()){
        long long tmp = st.top().second;
        long long sum = tmp * st.top().first;
        res = (sum>res)?sum:res;
        //cout << sum << ' ';
        st.pop();
        if(!st.empty()) st.top().second += tmp;//조건이 일부 빠진 이유? 이때 스택에는 오름차순으로만 정렬되어있기 때문
    }
    cout << res ;
}
/*
히스토그램과 유사한 문제였고, 분명 히스토그램도 풀었는데 이건 모노톤 스택을 떠올리긴 했지만 완벽한 방법이 생각이 안나서
모노톤 스택 부분을 다시 참고하고 복습하여 푼 문제이다.

과정: 히스토그램과 아주 유사하다. 
다만 이번에는 조금 방법이 달라졌다.(솔직히 내가 푼 히스토그램은 코드가 드러워...이게 깔끔해)
스택은 pair<값, 합>으로 구성

1.
스택이 비어있거나, top보다 큰 값이면 단순히 삽입한다.
2.
스택에 새로 들어오는 값이 top보다 작으면 input이 스택에서 작은 값을 찾을 때까지 pop한다.
이때, 합을 누적하고, 곱한 값을 res보다 크면 res에 삽입시킨다.
자세히:
1) 먼저 tmp에 탑의 누적된 합을 저장한다.

2) while에 들어선 후 sum에 탑의 값을 곱해준다. 즉, A[i] + … + A[j]) × min{A[i], …, A[j]}이다.
3) res와 비교하여 더 큰 값을 res에 삽입한다.
4) pop한다.
5+) 만약 반복문이 지속될 것이라면 tmp에 새로운 top에 대한 누적된 합을 더해준다. 그리고 다시 2부터 반복된다.
**5의 조건을 넣은 이유는 반복문 탈출 후에는 새로운 input이 들어오게 되어있는데, 
**이때 top에 input보다 작은 수가 남아있을 수 있다. 그렇게 되면 더해서는 안되는 합을 추가로 더하게 되고, 수가 왜곡된다.

3.
모든 반복이 끝난 후, 스택에 남아있는 수를 대상으로 추가 작업을 진행해준다. 이때도 조금은 다르지만 2~5의 과정을 반복하게된다.
res에는 최대의 값이 저장되어 있다.
*/
