#include <iostream>

int main(int argc,const char* argv[])
{
    std::string str1 = "Hello";
    std::string str2 = "Hello";

    //向访问字符数组那样，将字符串中的第二个字符提取出来显示，如果下标越界，不会报告错误。
    std::cout << str1[8] << std::endl; //不会报错，会出现未定义行为！！！随机打印出一个栈帧

    //使用成员函数来获得字符串中的第6个字符并显示，如果参数越界，函数将抛出异常。
//    std::cout << str1.at(6) << std::endl;

    return 0;
}







