#include <iostream>
using namespace std;

class Deque
{
  private:
    int * _dequeList;
    int _length;

  public:
    Deque(int length);

    int * _head;
    int * _tail;

    int _headIndex;
    int _tailIndex;
    bool _isFull;

    int enqueueHead(int element);
    int enqueueTail(int element);
    int dequeueHead();
    int dequeueTail();
};

Deque::Deque(int length)
{
  if(length > 0) {
    _length = length;
    _dequeList = new int[_length];
    _head = _tail = &_dequeList[0];
    _headIndex = _tailIndex = 0;
  }
}

int Deque::enqueueHead(int element)
{
  if(_headIndex == (_tailIndex + 1) % _length) {
    return -1;
  }

  *_head = element;
  if(_headIndex > 0) {
    _head --;
    _headIndex --;
  } else {
    _headIndex = _length - 1;
    _head = &_dequeList[_headIndex];
  }

  return 0;
}

int Deque::enqueueTail(int element)
{
  if(_headIndex == (_tailIndex + 1) % _length) {
    return -1;
  }

  _dequeList[_tailIndex] = element;
  _tailIndex = (_tailIndex + 1) % _length;

  return 0;
}

int Deque::dequeueHead()
{
  if(_headIndex == _tailIndex) {
    return -1;
  }
  int element = *_head;
  if(_headIndex < _length) {
    _headIndex ++;
    _head ++;
  } else {
    _headIndex = 0;
    _head = &_dequeList[0];
  }

  return element;
}

int Deque::dequeueTail()
{
  if(_headIndex == _tailIndex) {
    return -1;
  }

  int element = *_tail;
  if(_tailIndex > 0) {
    _tailIndex --;
    _tail --;
  } else {
    _tailIndex = _length - 1;
    _tail = &_dequeList[_tailIndex];
  }

  return element;
}

int main()
{
  Deque d(10);

  for(int i = 0; i < 10; i++) {
    int r = d.enqueueTail(i);
    // cout << r << endl;
    // if(rand() % 2 == 0) {
    //   d.enqueueHead(i);
    // } else {
    //   d.enqueueTail(i);
    // }
  }

  for(int j = 0; j < 10; j++) {
    cout << d.dequeueHead() << endl;
  }

  return 0;
}