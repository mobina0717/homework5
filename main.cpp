//#include "LinkList.h"
#include "LinkList.cpp"
//#include "Nodenode.h"
#include "Nodenode.cpp"
#include <iostream>
using namespace std;

    int main()

    {

        LinkedList lk1;

        LinkedList lk2;

        LinkedList lk3;

        LinkedList lk4;

        LinkedList lk5;

        LinkedList lk6;

        LinkedList lk7;

        lk2 = lk1 + 10;

        lk3 = lk2 + 20;

        lk4 = 0 + lk3;

        lk5 = -20 + lk4 + -10;

        lk6 = lk5 + lk4;

        cout << "lk5: " << lk5 << " lk6: " << lk6 << endl;

        // output:

        // lk5: -20 0 10 20 -10 lk6: -20 0 10 20 -10 0 10 20

        lk7 = lk3 = lk4;

        cout << ++lk3 << " --- " << lk7++ << endl;

        // output:

        // 1 11 21 --- 0 10 20

        if (lk7 == lk3)

        {

            lk7[1] = 22;

            lk3[1] = lk7[1];

            cout << lk3[1]-- << " --- " << --lk7[1] << endl;

            // output:

            // 22 --- 21

            const LinkedList lk8(lk4);

            lk4++;

            // lk8[1]=lk4[1];//error

            cout << lk4[1] << " --- " << lk8[1] << endl;

            // output

            // 11 --- 10

            cout << lk8[999] << " --- " << lk4[-1] << endl;

            // output

            // not in range !

            // 0 --- not in range !

            // 1

        }

        ++ ++lk2;

        cout << lk2[0] << endl;

        // ouput

        // 12

        lk2++ ++;

        cout << lk2[0] << endl;

        // ouput

        // 13

        return 0;

    }