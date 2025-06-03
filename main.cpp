#include <iostream>
#include "matrix.h"
#include <vector>

using namespace std;

int main() {
  matrix m1(1,1);

  cout<<"m1 is:\n" << m1;

  int** arr = new int* [3];

  for (int i = 0; i < 3; i++)
    arr[i] = new int[2];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++)
      arr[i][j] = 2 * i + j+1;

  matrix m2(arr, 3, 2);

  cout << "m2 is:\n" << m2;

  vector<vector<int>> vec = { {1,2,3} ,{4,5,6} };

  matrix m3(vec);

  cout << "m3 is:\n" << m3;

  matrix m4 = m2;

  cout << "after constructing m4 of m2, m4 is:\n" <<
m4;

  cout << "m2[2][1] is: " << m2.get_elem(2, 1)<<endl;

  cout << "3th row of m2 is: " << m2.get_row(2)[0]<<" " << m2.get_row(2)[1] << endl;

  cout << "2nd column of m2 is: " << m2.get_column(1)
[0] << " " << m2.get_column(1)[1] <<"" <<m2.get_column(1)[2] << endl;

  vector<int> v = { 7,8,9 };

  m2.set_column(v, 1);

  cout << "m2 is:\n" << m2;

  cout << "but m4(copy of m2) is still:\n" << m4 <<
endl;

  m1 =m1=m2= m3;

  cout << "after m1=m1=m2=m3 m2 is:\n" << m2;

  cout << "m4(2,1) is: " << m4(2, 1) << endl
   << "m4[2] [1] is: " << m4[2][1]<<endl;//emtiazi booda!

  cout << "m1 is" << (m1 == m2 ? " " : " not ") <<
"equal to m2 " << "and m2 is" << (m2 != m4 ? " not " : " ") << "equal to m4."<<endl;

  cout << "(3*m1)/2*4 is:\n" << (3 * m1) / 2 * 4;
  //note: integer divide

  m1 *= 2;

  cout << "after m1*=2 m1 is:\n" << m1;

  cout << "m1+m2 is:\n" << m1 + m2;

  cout << "m2*m4 is:\n" << m2 * m4;

  m2 *= m4*=m1;

  cout << "after m2*=m4*=m1 m2 is:\n" << m2;

  matrix m5(arr, 3, 2);

  m4 = m5;

  cout << "m4++*2 is:\n"<<m4++ * 2 << "and ++m5*2 is:\n" << ++m5*2;

  cout << "now m5 and m4 are equal to:\n" << m5;

  cout << "getting input matrix and assign it to m5 with format(row column a1 a2 ... an):\n";

  cin >> m5;

  cout << "you entered matrix:\n" << m5;

  return 0;
}
