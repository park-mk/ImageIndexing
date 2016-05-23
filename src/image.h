//
// Created by ZhuangTianYi on 5/23/16.
//

#ifndef IMAGEINDEXING_IMAGE_H
#define IMAGEINDEXING_IMAGE_H
#include <string>
#include <vector>
#include <array>


template <typename ELEM_T, int DIMENSION = 10>
struct Image {
    std::string name;
    std::array<ELEM_T, DIMENSION> data;
    double dist;

    Image(std::string name, std::array<ELEM_T, DIMENSION> data) : name(name), data(data), dist(0) { }

    bool operator == (const Image<ELEM_T, DIMENSION>& image2) {
        auto prefix = [](std::string name) {
            return name.substr(0, name.find('_'));
        };

        std::string prefix1 = prefix(name);
        std::string prefix2 = prefix(image2.name);
        return prefix1 == prefix2;
    }
};


#endif //IMAGEINDEXING_IMAGE_H
