//
// Created by zxzx on 2020/10/25.
//

#ifndef ZZZ_STRING_TEST_H
#define ZZZ_STRING_TEST_H

#include <iostream>

using namespace std;

class String{
public:
    String(void);
    String(const char *chars=NULL); //普通构造函数
    String(const String& str); //拷贝构造函数
    String& operator=(const String& str);
    ~String(void); //析构
private:
    char* m_chars;  //这里需要说明的是，m_chars不能被声明为数组类型，char[] m_chars，因为数组名无法被赋值。
};


String::String(){
    cout << "default constructor" << endl;
    m_chars = new char[1];
    *m_chars = '\0'; //非数组不能使用[]运算符，只能使用指针赋值
}

String::String(const char* chars){
    cout << "char pointer constructor" << endl;
    if(chars == NULL){
        m_chars = new char[1];
        *m_chars = '\0'; //非数组不能使用[]运算符，只能使用指针赋值
    }else{
        m_chars = new char[strlen(chars)+1];
        strcpy(m_chars, chars);
    }

}

String::String(const String &str){ //在拷贝构造函数里，可以访问私有属性,这点记住
    cout << "copy constructor" << endl;
    m_chars = new char[strlen(str.m_chars)+1];
    strcpy(m_chars, str.m_chars);
}

String::~String() {
    cout << "deconstructor" << endl;
    if(m_chars != NULL){ // 防止重复释放同一个内存导致系统崩溃,因为存在赋值和拷贝
        delete m_chars; //先释放原有原有内存，归还操作系统
        m_chars = NULL; //再把指针指向NULL，防止野指针
    }
}

String & String::operator=(const String &str) { // 赋值函数也可以访问私有属性，所以务必给赋值函数参数加上const
    cout << "operator= " << endl;
    if( &str == this) return *this; //是指向同一个内存，直接释放
    else{
        delete m_chars; //先释放原有原有内存，归还操作系统
    }
    m_chars = new char[strlen(str.m_chars)+1];
    strcpy(m_chars, str.m_chars);
    return *this; // 即便返回引用类型，我们只需要返回对象的本体即可，编译器会做处理，我们不用返回引用
}

void test_str_len(){
    char c[3];
    char cc[3] = "ab";
    strcpy(c, cc); // C 的库函数，需要学习一下
    cout << c << endl;
}

void test_String_f1(){
    String a = "abc";
    {
        String b = a;
        // delete b; delete无法操作普通对象，只能操作指针
        String *c = &a;
        // delete c; 注意！delete只能释放堆内存，不能释放栈内存，释放栈内存会报错：pointer being freed was not allocated

        String null_str(NULL);
    }
    String d = "aefg";
    a = d;
    // 打印结果
    // char pointer constructor
    //copy constructor
    //char pointer constructor
    //deconstructor
    //char pointer constructor
    //operator=
    //deconstructor
    //deconstructor
    //deconstructor
}

void test_String_f2(){
    String a = "abc";
}

void default_null(char * chars=NULL){
    cout << "call" << endl;
}

void test_default_null(){
    default_null();
}
#endif //ZZZ_STRING_TEST_H
