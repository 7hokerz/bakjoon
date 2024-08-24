#include <iostream>
#include <string>
using namespace std;
//String 클래스를 이용한 문자열 사용

//string 클래스는 문자열의 크기에 맞춰 메모리를 조절하므로 편리함.

//string 클래스의 주요 생성자
//string(): 빈 문자열을 가진 스트링 객체 생성
//string(const string& str): str을 복사한 새로운 스트링 객체 생성
//string(const char* s): C-스트링 s의 문자열을 복사하여 스트링 객체 생성(char 같은거)
//string(const char* s, int n): s에서 n개의 문자를 복사하여 스트링 객체 생성

int main(){
    string str;//빈 문자열 스트링 객체
    string add("서울");//문자열 리터럴로 초기화
    string copadd(add);//add를 copadd에 복사하고 생성

    string *p = new string(add);//동적으로 스트링 객체 생성
    //cout << *p;//서울 출력
    p->append("강서\n");//append는 문자를 연결해주는 메소드(?)
    cout << *p;//서울강서
    delete p;//반환

    //cin >> str;//공백 문자를 포함할 수 없으므로, 이 때는 getline 함수를 이용
    getline(cin, str, '\n');//cin.getline과는 다르다.
    cout << str;
}
