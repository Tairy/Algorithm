#include <iostream>
using namespace std;

const int FIRST = 1;
const int SECOND = 2;

class Stack
{
  private:
    int * _stackList;
    int _length;

  public:
    int top1;
    int top2;

    Stack(int length);
    int pop(int zone);
    int push(int zone, int element);
    bool isEmpty(int zone);
    bool isFull(int zone);
};

Stack::Stack(int length) 
{
  if(length > 0) {
    this->_length = length;
    this->top1 = 0;
    this->top2 = length - 1;
    this->_stackList = new int[length];
  }
}

int Stack::push(int zone, int element)
{
  if(this->isFull(zone)) {
    return -1;
  }

  if(FIRST == zone) {
    this->top1 += 1;
    this->_stackList[this->top1] = element;
  } else if(SECOND == zone) {
    this->top2 -= 1;
    this->_stackList[this->top2] = element;
  }

  return element;
}

int Stack::pop(int zone)
{
  if(this->isEmpty(zone)) {
    return -1;
  }

  if(FIRST == zone) {
    this->top1 -= 1;
    return this->_stackList[this->top1 + 1];
  } else if (SECOND == zone) {
    this->top2 += 1;
    return this->_stackList[this->top2 - 1];
  }

  return -1;
}

bool Stack::isFull(int zone)
{
  if((FIRST == zone 
    && this->top1 >= this->top2 - 1) || 
    (SECOND == zone 
    && this->top2 <= this->top1 + 1)) {
    return true;
  }

  return false;
}

bool Stack::isEmpty(int zone)
{
  if((FIRST == zone 
    && this->top1 <= 0) || 
    (SECOND == zone 
    && this->top2 >= this->_length)) {
    return true;
  }

  return false;
}

int main()
{
  Stack s(10);
  int a, b, c, d;
  int result;
  cout << "Input: " << endl;
  cin >> a >> b >> c >> d;

  result = s.push(FIRST, a);
  printf("%d \n",result);
  result = s.push(FIRST, b);
  printf("%d \n",result);
  result = s.push(SECOND, c);
  printf("%d \n",result);
  result = s.push(SECOND, d);
  printf("%d \n",result);

  result = s.pop(FIRST);
  printf("%d \n",result);

  result = s.pop(SECOND);
  printf("%d \n",result);

  return 0;
}