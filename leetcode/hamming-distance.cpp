#include <iostream>

// 虽然 accepted 了，原理没错，但是对于十进制转二进制的算法还有有问题的
// 对于大数，for 循环的初始值会有问题

using namespace std;

int hammingDistance(int x, int y) {
  int c = x ^ y;
  int distance = 0;
  for(int i = 31; i >= 0; i--)
  {
    if(c & (1 << i)) {
      distance ++;
    }
  }
  return distance;
}

int main()
{
  cout << hammingDistance(1577962638, 1727613287);
  return 0;
}