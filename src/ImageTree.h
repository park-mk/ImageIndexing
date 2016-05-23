//
// Created by ZhuangTianYi on 5/21/16.
//

#ifndef IMAGEINDEXING_IMAGETREE_H
#define IMAGEINDEXING_IMAGETREE_H

#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include <functional>

#include "rtree.h"
#include "image.h"

using std::string;
using std::vector;
using std::array;

const double RANGE = 0.001;
const int RESULT_NUM = 10;

std::vector<void*> results;

bool searchCallback(void* img, void*) {
    results.push_back(img);
    return true;
}

template <typename ELEM_T, int DIMENSION = 9>
class ImageTree {
private:
    RTree<Image<ELEM_T, DIMENSION>*, ELEM_T, DIMENSION, double> rtree;
    vector<string> namelist;

public:
    ImageTree() {
        std::ifstream file("data/images.txt");
        string name;

        while (std::getline(file, name)) {
            this->namelist.push_back(name);
        }

        file.close();
    }

    static double distance(std::array<ELEM_T, DIMENSION> v1, std::array<ELEM_T, DIMENSION> v2) {
        double res = 0;

        for (int i = 0; i < DIMENSION; ++i) {
            res += ((v1[i] - v2[i]) * (v1[i] - v2[i]));
        }

        return res;
    }

    static ImageTree<ELEM_T, DIMENSION> fromFile(string filename) {
        auto tree = ImageTree<ELEM_T, DIMENSION>();
        std::ifstream file(filename);

        string line;
        int k = 0;
        while (std::getline(file, line)) {
            array<ELEM_T, DIMENSION> data;
            std::stringstream sline(line);
            for (int i = 0; i < DIMENSION; ++i) {
                sline >> data[i];
            }

            tree.rtree.Insert(data.data(), data.data(), new Image<ELEM_T, DIMENSION>(tree.namelist[k++], data));
        }

        file.close();
        return tree;
    }

    void search(std::array<ELEM_T, DIMENSION> image, int times = 0) {
        results.clear();
        std::array<ELEM_T, DIMENSION> dataMin;
        std::array<ELEM_T, DIMENSION> dataMax;
        for (int i = 0; i < DIMENSION; ++i) {
            dataMax[i] = image[i] + times * RANGE;
            dataMin[i] = image[i] - times * RANGE;
        }

        int result = this->rtree.Search(dataMin.data(), dataMax.data(), searchCallback, this);
        if (result < RESULT_NUM) {
            search(image, times + 1);
        } else {
            for (int i = 0; i < results.size(); ++i) {
                ((Image<ELEM_T, DIMENSION>*)(results[i]))->dist = distance(image, ((Image<ELEM_T, DIMENSION>*)(results[i]))->data);
            }

            std::sort(results.begin(), results.end(), [](void* image1, void* image2) {
                return ((Image<ELEM_T, DIMENSION>*)(image1))->dist < ((Image<ELEM_T, DIMENSION>*)(image2))->dist;
            });

            results.erase(results.begin() + RESULT_NUM, results.end());
        }
    }

    std::vector<Image<ELEM_T, DIMENSION>> getResults() {
        std::vector<Image<ELEM_T, DIMENSION>> imageResults;
        for_each(results.begin(), results.end(), [&](void* ptr) {
            imageResults.push_back(*((Image<ELEM_T, DIMENSION>*)ptr));
        });
        return imageResults;
    }
};

#endif //IMAGEINDEXING_IMAGETREE_H
