// heap sort
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

void swim(vector<int> &heap, int i) {
    while (i > 1 && heap[i] > heap[i/2]) {
        std::swap(heap[i], heap[i/2]);
        i = i / 2;
    }
}

void sink(vector<int> &heap, int i) {
    int N = (int)heap.size();
    while (2 * i <= N) {
        int j = 2 * i;
        if (j < N && heap[j] < heap[j+1])
            j++;
        if (heap[i] >= heap[j])
            break;
        swap(heap[i], heap[j]);
        i = j;
    }
}

void print(vector<int> &heap) {
    for (auto e = heap.end()-1; e > heap.begin(); e--)
        cout << *e << " ";
    cout << endl;
}
void findKmin(vector<int> &v, int k) {
    int size = (int) v.size();
    
    //init a heap
    vector<int> heap(k+1, 0);
    
    for (int i = 0; i < k; i++) {
        heap[i+1] = v[i];
        swim(heap, i+1);
    }
    
    for (int i = k; i < size; i++) {
        if (v[i] < heap[1]) {
            heap[1] = v[i];
            sink(heap, 1);
        }
    }
    print(heap);
}

int main(int argc, char *argv[]) {
    vector<int> v;
    int n, k;
    cin >> n;
    cin >> k;

    for (int i = 0; i < n; i++)
         v.push_back(std::rand() % n);

    findKmin(v, k);
    
    return 0;
}
