//
// Created by zxzx on 2020/12/10.
//

#ifndef ZZZ_TESTOVERRITE_H_BOOST
#define ZZZ_TESTOVERRITE_H_BOOST

#include <iostream>
#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

void test_boot(){
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::for_each(
            in(std::cin), in(), std::cout << (_1 * 3) << " " );
};

#endif //ZZZ_TESTOVERRITE_H_BOOST
