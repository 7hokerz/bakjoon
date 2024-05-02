#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, input;
    cin >> n;
    stack <pair <int, pair<int,int>>> st;//넓이<높이,인덱스>
    int area = 0;

    for(int i = 0;i<n;i++){
        cin >> input;
        //스택이 비어있거나, 비어있지 않으면서 인풋의 높이가 더 높은 경우 단순 삽입
        if(st.empty() || (!st.empty() && input > st.top().second.first)){
            st.push({input,{input,i}});

        }//인풋의 높이가 더 낮은 경우
        else if(!st.empty() && input < st.top().second.first){
            int idx;
            //더 높은 높이의 요소의 넓이를 갱신한 후 최댓값과 비교한 후 제거한다. 
            while(!st.empty() && input < st.top().second.first){
                st.top().first = (i - st.top().second.second)*st.top().second.first;
                area = (st.top().first > area)?st.top().first:area; 
                idx = st.top().second.second;
                st.pop();
            }
            //탑의 높이와 인풋의 높이가 같으면 단순히 넓이만 갱신하고 삽입 X
            if(!st.empty() && st.top().second.first == input){
                st.top().first = (i - st.top().second.second+1)*st.top().second.first;
            }
            else if(!st.empty() && st.top().second.first != input){//높이가 같지 않으면 새로운 요소에 대한 정보를 갱신 후 삽입
                st.push({input*(i-idx+1),{input,idx}});
            }
            else{//비어있으면 단순 삽입
                st.push({input,{input,0}});//0을 넣어야 제대로 된 넓이를 찾게 됨.
            }
        }
    }//남아있는 스택의 요소들의 넓이를 갱신한 후 비교
    while(!st.empty()){
        st.top().first = st.top().second.first * (n - st.top().second.second);
        area = (st.top().first > area)?st.top().first:area; 
        st.pop();
    }
    cout << area;
}
/*
위 형식으로 스택을 선언하고 조건에 따라 분류한다.

0. 스택이 비어있다면 스택에 넓이는 높이*1로 두고 스택에 삽입한다.

1. top의 넓이는 다음 인풋의 높이가 더 낮지 않은 경우 계속 증가 가능(만약 새로운 top이 들어오더라도 인덱스의 차이로 연결 가능)

2. 인풋이 top의 높이보다 높다면 넓이는 높이*1로 두고 스택에 삽입한다.(top에 있던 요소는 삭제하지 않는다.)(0과 같은 기능)

3. 만약 인풋의 높이가 top의 높이보다 더 낮은 경우일 동안 요소를 지우고 넓이는 결과 스택으로 보내는데,(결과 스택 대신 변수로?)
인풋을 스택에 넣을 때 마지막으로 제거된 요소의 인덱스를 인풋에 담고 스택에 삽입한다.

3.1 높이가 0이 들어온다면 결국은 스택은 비어야 한다.
*/
