#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <int> st;
    stack <pair<int,int>> st2;
    int N, input;
    long long cnt = 0*1LL;
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> input;
        while(!st.empty() && st.top() < input){
            st.pop();
            cnt++;
        }
        while(!st2.empty() && st2.top().first < input){
            cnt += st2.top().second;
            st2.pop();
        }

        if(!st.empty() && st.top() == input){
            if(!st2.empty() && st2.top().first == st.top()){//st.top이 1개 이상 누적된 경우
                st2.top().second++;
                if(st.size() == 1) cnt += st2.top().second;
                else if(st.size() > 1) cnt += st2.top().second + 1;
            }else{//st.top이 누적된 적 없는 경우(중복이 아니었던 경우)
                st2.push({st.top(),1});
                if(st.size() == 1) cnt += st2.top().second;
                else if(st.size() > 1) cnt += st2.top().second + 1;
            }
        }
        else if(!st.empty() && st.top() > input){ 
            cnt++;
            st.push(input);
        }
        else{
            st.push(input);
        }
    }
    cout << cnt;
}
/*
진짜 진짜...어려웠다. 여러 요건들이 있는데 신경써줘야할 것이 너무 많았다.
진짜 스트레스 엄청 받았던 문제. 그래도 하루 걸려서 풀었다. 지금도 이걸 어케했냐 싶다.

고려해줘야 했던 것(아래에도 비슷하게 있음)(아래 2가지는 필수로 신경써줘야 한다.)
****1. 10 9 5 5같은 경우 10은 5 5를 볼 수 없음을 유의해야 한다.
****2. 9 9 5 5같은 경우도 마찬가지이다.
**3. 최대 cnt값은 int형을 넘게되므로 long long으로 처리해줘야 한다.

결국은 input과 top이 같은 경우를 잘 처리해줘야 한다. 
나는 새로운 스택에 st.top과 같은 중복된 값이 들어올 때마다 cnt를 증가시키고 st2.top 값을 더하거나 새로 삽입시켰다.
(st2스택은 중복된 값을 추가로 저장하는 스택이다. 즉, st에서 연속된 요소의 개수가 2개 이상일 때를 말한다.)

10 9 5 5나
9 9 5 5 같이 
두 가지 경우는 다른 방식으로 10, 9를 배제시켜야 한다.

1. 스택이 없을 경우에는 요소를 삽입

2. st.top < input이면 while(st.top<input) st.pop cnt++ 한다.(input보다 같거나 큰 사람이 나올때까지)
이때 만약 st2.top.first < input이면 while(st.top.first < input) cnt += st2.top.second st2.pop해준다.
(second에는 누적된 값이 들어가 있음)

**3. st.top > input이면 top요소를 하나만 남기고 전부 st2에 누적 형태로 넣어준다. 그리고 input을 st2에 삽입시킨다.
만약 같은 top요소가 1개뿐이었으면 단순히 input을 st2에 삽입시키기만 한다.

4. st.top == input이면 
if(st2.top() == st.top()) 이면 
if(st.size() == 1) cnt += st2.top().second + 1;
else if(st.size() > 1) cnt += st2.top().second + 2;  
st2.top().second++; 하고 input을 삽입시키진 않는다.

else(st2에 input이 없는 경우는) 
st2.push({st.top(),1});
if(st.size() == 1) cnt += st2.top().second;
else if(st.size() > 1) cnt += st2.top().second + 1;
input을 삽입시키진 않음.
*/
