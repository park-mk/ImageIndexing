#include <iostream>
#include "rtree.h"

using std::cout;
using std::endl;

int main() {
    RTree<int, int, 2> rt;
    cout << rt.Count() << endl;
    return 0;
}