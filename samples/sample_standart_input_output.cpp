#include <iostream>

#include "tbitfield.h"
#include "tset.h"

using namespace std;

int main
{
  int size;
  cout << "Enter Bitfield size: ";
  // Введите к примеру: 5
  cin >> size;
  TBitField bitfield(size);
  cout << "Enter Bitfield content:" << endl;
  // Введите к примеру: 01010
  cin >> bitfield;
  cout << "This is Bitfield content:" << endl;
  cout << bitfield << endl << endl;
  // Вы должны увидеть: 01010

  cout << "Enter Set size: ";
  // Введите к примеру: 10
  cin >> size;
  TSet set(size);
  cout << "Enter Set content:" << endl;
  // Введите к примеру: 1 3 6 ;
  cin >> set;
  cout << "This is Set content:" << endl;
  cout << set << endl;
  // Вы должны увидеть: 1 3 6

  return 0;
}