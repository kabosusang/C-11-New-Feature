#include <iostream>
#include <string>
using namespace std;

// 1.R"(xxx)"  原始字面量 原样输出到终端 也可以R"ooo(xxx)ooo"  其中ooo只是起修饰作用

int main(int argc, char* argv[])
{
    string str1 = R"(C:\windows\123\test.text)";
    cout << str1 << endl;

    string str3 = R"Test(两边的字符串只是起修饰作用 并不会输出)Test";  
    cout << str3 << endl;

    string str2 =R"(<html>
        <head>
        <title>
        海贼王
        </head>
        <body>
        <p>
        hahaha
        </p>
        </body>
        </html>)";
    cout << str2 << endl;
    
}


