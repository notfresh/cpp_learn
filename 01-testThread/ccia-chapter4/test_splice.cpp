// splicing lists
#include <iostream>
#include <list>
#include <zxlib/print.h>

using namespace std;

int main ()
{
  list<int> mylist1, mylist2;
  list<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=4; ++i)
     mylist1.push_back(i);      // mylist1: 1 2 3 4

  for (int i=1; i<=3; ++i)
     mylist2.push_back(i*10);   // mylist2: 10 20 30

  it = mylist1.begin();
  ++it;                         // points to 2

  mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                // mylist2 (empty)
                                // "it" still points to 2 (the 5th element)
  print(mylist1);       
  print(mylist2);      
  print(1);                            
   
//   mylist2.splice (mylist2.begin(),mylist1, it);
//                                 // mylist1: 1 10 20 30 3 4
//                                 // mylist2: 2
//                                 // "it" is now invalid.
//   it = mylist1.begin();
//   advance(it,3);           // "it" points now to 30

//   mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
//                                 // mylist1: 30 3 4 1 10 20

//   cout << "mylist1 contains:";
//   for (it=mylist1.begin(); it!=mylist1.end(); ++it)
//     cout << ' ' << *it;
//   cout << '\n';

//   cout << "mylist2 contains:";
//   for (it=mylist2.begin(); it!=mylist2.end(); ++it)
//     cout << ' ' << *it;
//   cout << '\n';

  return 0;
}