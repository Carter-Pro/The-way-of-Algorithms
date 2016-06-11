#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Task
{
     int taskID;
     int RO;
     Task(int id, int ro) : taskID(id), RO(ro) {}
     // 升序排列则第一个参数小于第二个参数返回 true
     // 降序排列则第一个参数大于第二个参数返回 true
     // 参数类型一定是 const Type&
     static bool Compare(const Task& t1, const Task& t2) {
          return t1.RO > t2.RO;
     }
};
int main(int argc, char *argv[])
{
     vector<Task> v;
     v.push_back(Task(1, 10 - 5));
     v.push_back(Task(2, 8 - 2));
     std::sort(v.begin(), v.end(), Task::Compare);
     cout << v[0].taskID << endl;
     cout << v[1].taskID << endl;

     // using lambda expression
     std::sort(v.begin(), v.end(), [](const Task& t1, const Task& t2){
               return t1.RO < t2.RO;
          });
     cout << v[0].taskID << endl;
     cout << v[1].taskID << endl;
     return 0;
     
}
