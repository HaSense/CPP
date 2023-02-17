#include <iostream>
#include "sample.h"

using namespace std;

int main()
{
    Sample s1(100);
    cout << s1.getValue() << endl;
    
    return 0;
}

/*
    컴파일 옵션 :
    g++ -o run main.cpp sample.cpp

*/
