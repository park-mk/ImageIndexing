#include <iostream>
#include "ImageTree.h"

using std::cout;
using std::endl;

int main() {
    std::ios::sync_with_stdio(false);
    auto tree = ImageTree<float, 10>::fromFile("data/RGB_Hist_HSV_8.txt");
    std::array<float, 10> data = {2.0e-02,1.544e-01,1.245e-01,1.085e-01,8.064e-01,3.004e-01,3.058e-01,4.803e+01,12.938e-01,1.448e+01};
    tree.search(data);
    return 0;
}
