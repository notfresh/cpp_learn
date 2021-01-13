//
// Created by zxzx on 2021/1/13.
//
// 单线程版本的
class Singleton{
private:
	Singleton(){};
	static  Singleton *instance;

public:
	static getInstance(){
		if(instance== nullptr){
			instance = new Singleton();
		}
		return instance;
	};
};

Singleton* Singleton::instance = nullptr ;


