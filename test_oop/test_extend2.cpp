//
// Created by zxzx on 2020/12/29.
//

#include <iostream>
using namespace std;
class MD
{
protected:
    float miles;
public:
    void setDist(float d){miles=d;}
    virtual float getDist(){return miles;}
    float square(){return getDist() * getDist();}
};

class FeetDist: public MD
{
protected:
    float feet;
public:
    void setDist(float);
    float getDist(){return feet;}
    float getMiles(){return miles;}
};

void FeetDist::setDist(float ft)
{
    feet=ft;
    MD::setDist(feet/2);
}

int main()
{
    FeetDist feet;

    feet.setDist(8);
    // 如果 getDist() 不是虚函数，那么结果就是16， 否则的话就是64
    cout<<feet.getDist()<<","<<feet.getMiles()<<","<<feet.square()<<endl;

    return 0;
}