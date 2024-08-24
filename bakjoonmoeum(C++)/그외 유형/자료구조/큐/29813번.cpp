#include <iostream>
#include <queue>
using namespace std;

class student{
public:
    string ini;
    int num;
    student(string ini, int num){
        this->ini = ini;
        this->num = num;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    queue <student> q;
    int N, input2;
    string input1;
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> input1;
        cin >> input2;
        student stu(input1, input2);
        q.push(stu);
    }

    while(q.size() > 1){
        student first = q.front();
        q.pop();
        for(int i = 1;i<first.num;i++){
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    
    cout << q.front().ini << '\n';
}
/*
앞에 선 학생의 (학번 - 1)만큼 패스시켜야 한다.
즉 (학번)째에 만난 학생이 팀원이 되어 나간다.

이런 과정으로 하다가 마지막으로 남은 학생 1명의 이니셜을 출력한다.

+(pair를 이용하면 클래스를 만들지 않아도 되는 듯한데, 
pair를 배우지 않았으니 일단은 패스)
*/