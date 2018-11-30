#include "tset.h"
int main()
{
  int max_count = 0;
  setlocale(LC_ALL, "Russian");
  cout << "Введите количество измерений - ";
  cin  >> max_count;
   clock_t time;
  clock_t average_time;
  for (unsigned size = 10; size < 10000000; size *= 10)
  {
    TSet set1(size);
    TSet set2(size);
     average_time = 0;
    for (unsigned count = 0; count < max_count; count++)
    {
      time = clock();
      set1 = set2;
      average_time += clock() - time;
    }
    average_time /= max_count;
    cout<< "Время: " <<average_time<<endl;
  }
  return 0;
}
