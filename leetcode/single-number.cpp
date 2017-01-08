#include <iostream>

using namespace std;

int singleNumber(int data[], int length) {
  int result = 0;
  for(int i = 0; i < length; ++i) {
      result ^= data[i];
  }
  return result;
}

int main()
{
  int data[] = {1, 2, 3, 1, 2};
  int num;
  int result = singleNumber(data, 5);
  cout << result;
  return 0;
}