#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////
// Find two numbers which only appear once in an array
// Input: data - an array contains two number appearing exactly once,
//               while others appearing exactly twice
//        length - the length of data
// Output: num1 - the first number appearing once in data
//         num2 - the second number appearing once in data
///////////////////////////////////////////////////////////////////////

void firstBit1(int num, int & index)
{
  for(int i = 31; i >= 0; i--)
  {
    if(num & (1 << i)) {
      index = i;
    }
  }
}

bool isBit1(int num, int index)
{
  num = num >> index;
  return num & 1;
}

void findNumsAppearOnce(int data[], int length, int &num1, int &num2)
{
  int resultExclusiveOR = 0;
  for (int i = 0; i < length; ++i)
  {
    resultExclusiveOR ^= data[i];
  }

  int first1Index;
  firstBit1(resultExclusiveOR, first1Index);

  for (int j = 0; j < length; ++j)
  {
    if(isBit1(data[j], first1Index)) {
      num1 ^= data[j];
    } else {
      num2 ^= data[j];
    }
  }
}

int main()
{
  int data[6] = {1, 4, 2, 1, 2, 6};
  int num1, num2;
  findNumsAppearOnce(data, 6, num1, num2);
  cout << num1 << '\t' << num2;
  return 0;
}