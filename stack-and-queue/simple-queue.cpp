#include <iostream>
using namespace std;

class Queue
{
  private:
    int * _queueList;
    int _length;

  public:
    Queue(int length);

    int * _head;
    int * _tail;

    int _headIndex;
    int _tailIndex;

    int enqueue(int element);
    int dequeue();
};

Queue::Queue(int length)
{
  if(length > 0) {
    _length = length;
    _queueList = new int[this->_length];
    _head = &_queueList[0];
    _tail = &_queueList[0];
    _tailIndex = 0;
    _headIndex = 0;
  }
}

int Queue::enqueue(int element)
{
  if(_headIndex == _tailIndex + 1 || (_headIndex == 0 && _tailIndex == _length)) {
    return -1;
  }

  *_tail = element;

  if(_tailIndex < _length) {
    _tail ++;
    _tailIndex ++;
  } else {
    // 卷绕
    if(_headIndex != 0) {
      _tail = &_queueList[0];
      _tailIndex = 0;
    }
  }

  return 0;
}

int Queue::dequeue()
{
  if(_headIndex == _tailIndex) {
    return -1;
  }

  int element;
  element = *_head;

  if(_headIndex < _length) {
    _head ++;
    _headIndex ++;
  } else {
    _headIndex = 0;
    _head = &_queueList[0];
  }
  return element;
}

int main()
{
  Queue q(10);
  cout << "In" << endl;
  for(int i = 0; i < 10; i++) 
  {
    cout << q.enqueue(i) << endl;
  }
  cout << q.dequeue() << endl;
  cout << q.enqueue(10) << endl;
  cout << q.dequeue() << endl;
  cout << q.enqueue(11) << endl;
  cout << "Out" << endl;
  for (int i = 0; i < 10; i++)
  {
    cout << q.dequeue() << endl;
  }
  return 0;
}