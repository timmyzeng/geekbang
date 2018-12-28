// // // // // // 1
//
// 模拟栈
//
// #include <iostream>

// using namespace std;

// class Stack{
// public:
//     Stack(int cap)
//         :_size(0)
//          ,_capacity(cap)
//     {
//         _array = new int[cap];
//     }

//     bool Push(int item){
//         if(_capacity == _size)
//             return false;

//         _array[_size] = item;
//         ++ _size;
//         return true;
//     }

//     bool Pop(){
//         if(_size == 0)
//             return false;
//         -- _size;
//         return true;
//     }

// private:
//     int _size;
//     int _capacity;
//     int* _array;
// };
//
// // // // // // 2
//
// // 实现括号匹配
// #include <iostream>
// #include <stack>
// #include <string>

// using namespace std;

// // ([({<    >})])
// int main(){
//     string str;
//     while(cin >> str){
//         stack<char> s;
//         int index = 0;
//         while(index != (int)str.size()){
//             char tmp = str[index];
//             if(tmp == '[' | tmp == '<' | tmp == '(' | tmp == '{'){
//                 s.push(tmp);
//             }
//             else if(!s.empty() && str[index] == ']'){
//                 if(s.top() == '['){
//                     s.pop();
//                 }
//                 else{
//                     break;
//                 }
//             }
//             else if(!s.empty() && str[index] == '>'){
//                 if(s.top() == '<'){
//                     s.pop();
//                 }
//                 else{
//                     break;
//                 }
//             }
//             else if(!s.empty() && str[index] == ')'){
//                 if(s.top() == '('){
//                     s.pop();
//                 }
//                 else{
//                     break;
//                 }
//             }
//             else if(!s.empty() && str[index] == '}'){
//                 if(s.top() == '{'){
//                     s.pop();
//                 }
//                 else{
//                     break;
//                 }
//             }
//             ++ index;
//         }
//         if(index == (int)str.size() && s.empty()){
//             cout << "right" << endl;
//         }
//         else{
//             cout << "wrong" << endl;
//         }
//     }
//     return 0;
// }
