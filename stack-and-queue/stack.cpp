#include <iostream>
using namespace std;

class Stack
{
  private:
    int * _stackList;
    int _max;

  public:
    int top;

    Stack(int max);
    int pop();
    int push(int element);
    bool isEmpty();
    bool isFull();
};

Stack::Stack(int max)
{
  if(max > 0) {
    _stackList = new int[max];
    top = 0;
    _max = max;
  }
}

int Stack::push(int element)
{
  if(isFull()) {
    return -1;
  }
  top += 1;
  _stackList[top] = element;
  return element;
}

int Stack::pop()
{
  if(isEmpty()) {
    return -1;
  }
  top -= 1;
  return _stackList[top + 1];
}

bool Stack::isEmpty()
{
  return top <= 0 ? true : false;
}

bool Stack::isFull()
{
  return top >= _max ? true : false;
}

int main()
{
  Stack s(3);
  int a, b, c, d;
  int result;
  cout << "Input: " << endl;
  cin >> a >> b >> c >> d;
  result = s.push(a);
  printf("%d \n",result);
  result = s.push(b);
  printf("%d \n",result);
  result = s.push(c);
  printf("%d \n",result);
  result = s.pop();
  printf("%d \n",result);
  result = s.push(d);
  printf("%d \n",result);
  return 0;
}