#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
        static int student_count;
        string name;
        int sNo;
        //생성자
        Student(const string& name_, int sNo_){
            //학생의 수 증가
            student_count++;
            name = name_;
            sNo = sNo_;
        }
        ~Student(){
            //학생의 수 감소
            student_count--;
        }

        static void PrintStdCount(){
            cout << "Student 객체 수" << student_count << endl;
        }
};
int Student::student_count = 0;
void Func(){
            Student std1("Bill", 342);
            Student std2("James", 214);

            Student::PrintStdCount();
}

int main()
{
    Student::PrintStdCount();

    Student std("Jeffrey", 123);
    
    Student::PrintStdCount();

    Func();

    Student::PrintStdCount();

    return 0;
}


