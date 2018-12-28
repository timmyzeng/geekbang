#include <iostream>

using namespace std;

#if 0
/***************************
 * queue数组形式的基本实现 *
 ***************************/
class ArrayQueue{
public:
    ArrayQueue(int size) 
        :_cap(size)
         ,_head(0)
         ,_tail(0)
    {
        _arr = new int[size];
    }

    // 入队列
    bool enqueue(int item) {
        if (_cap == _tail)
            return false;

        _arr[_tail++] = item;
        return true;
    }

    // 出队列
    bool dequeue() {
        if (_tail == _head)
            return false;

        ++ _head;
        return true;
    }
private:
    // 数组结构
    int* _arr;
    // 数组容量
    int _cap;
    // 头指针
    int _head;
    // 尾指针
    int _tail;
};
#endif

#if 0
/***************************
 * queue数组形式的优化实现 *
 ***************************/
// 因为上述版本中，head和tail会跟随着dequeue和enqueue
// 向后移动，这样会导致head之前的空间浪费，这里使用
// 集中搬移的方式进行一次小优化
// 
// 只需要对enqueue进行优化即可

bool enqueue(int item) {
    if (_tail == _cap) {
        if (_head == 0) 
            return false;
        int i = 0;
        while (_head != _tail) 
            _arr[i++] = _arr[_head++];
        _head = 0;
        _tail = i + 1;
    }
    _arr[_tail++] = item;
    return true;
}
#endif

#if 0
/***********************************
 * Circularqueue数组形式的基本实现 *
 ***********************************/
class CircularQueue{
public:
    CircularQueue(int size) 
        :_cap(size)
         ,_head(0)
         ,_tail(0)
    {
        _arr = new int[size];
    }

    // 入队列
    bool enqueue(int item) {
        if ((_tail+1) % _cap == _head)
            return false;
        _arr[_tail] = item;
        // 两种情况
        // _tail > _head: 正常的情况
        // _tail < _head: 循环的情况
        _tail = (_tail + 1) % _cap;
        return true;
    }


    // 出队列
    bool dequeue() {
        if (_tail == _head)
            return false;

        // 两种情况
        // _tail > _head: 正常的情况
        // _tail < _head: 循环的情况
        _head = (_head + 1) % _cap;
        return true;
    }
private:
    // 数组结构
    int* _arr;
    // 数组容量
    int _cap;
    // 头指针
    int _head;
    // 尾指针
    int _tail;
};
#endif
