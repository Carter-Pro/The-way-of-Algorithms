#include <iostream>
using namespace std;
class RemoveElement {
public:
    int removeelement(int arry[], int n, int value) {
        int i = 0;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (arry[i] == value)
                continue;

            arry[j] = arry[i];
            j++;
        }
        return j;
    }
};
int main(void)
{
    RemoveElement test;
    int array[] = {1, 2, 2, 3, 2, 4};
    int result;
    result = test.removeelement(array, 6, 2);
    for (int i = 0; i < result; ++i) {
        cout << array[i] << endl;
    }
    return 0;
}