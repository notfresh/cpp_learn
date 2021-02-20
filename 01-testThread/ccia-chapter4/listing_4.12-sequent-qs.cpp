#include <list>
#include <zxlib/print.h>
#include <future>

using namespace std;

template<typename T>
list<T> sequential_quick_sort(list<T> input)
{
    if(input.empty())
    {
        return input;
    }
    list<T> result;
    
    // copy one value to result
    result.splice(result.begin(),input,input.begin());
    T const& pivot=*result.begin();    

    auto divide_point=partition(input.begin(),input.end(),
        [&](T const& t){return t<pivot;});
    
    list<T> lower_part;
    lower_part.splice(lower_part.end(),input,input.begin(),
        divide_point);
    
    // 先开启一个线程
    auto new_higher =  async(&sequential_quick_sort<T>, move(input));    
    auto new_lower = sequential_quick_sort(move(lower_part));   

    result.splice(result.begin(),new_lower);    
    result.splice(result.end(),new_higher.get());
    // Using synchronization of operations to simplify code
        
    return result;
}


int main(){
    list<int> ls{9,8,1,2,3,4,11};
    list<int> ls2 = sequential_quick_sort(ls);
    print(ls2);
    for(int i: ls2) print(i);
}

