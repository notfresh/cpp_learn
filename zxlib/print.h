//
// Created by zxzx on 2021/1/8.
//

#ifndef CPP_LEARN_PRINT_H
#define CPP_LEARN_PRINT_H

#include <iostream>
#include <vector>
// 不能在包头里使用 using namespace std; 这样会给引入的包造成濡染，明白吗！！

template<typename T>
void print(T t){ // @print
	std::cout << t << std::endl;
}

template<typename T, typename... Ts>
void print(T t, Ts... args){
	std::cout << t << ", " ;
	print(args...);
}

template<typename T>
void print(std::vector<T> arr){ // @print
	for(int i=0; i<arr.size(); i++){
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
}

#endif //CPP_LEARN_PRINT_H

