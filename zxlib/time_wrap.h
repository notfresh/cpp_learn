//
// Created by zxzx on 2021/1/9.
//

#ifndef CPP_LEARN_TIME_WRAP_H
#define CPP_LEARN_TIME_WRAP_H

# include <ctime>
# include <zxlib/print.h>
void time_wrap(std::function<void()> f){
	clock_t c1 = clock(); // @clock @time
	f();
	clock_t c2 = clock();
	print(double(c2-c1)/CLOCKS_PER_SEC);
}

#endif //CPP_LEARN_TIME_WRAP_H


