#include <random>
#include <fstream>
#include <sstream>
#include "ImageTree.h"

const int RGB_HIST_10_DIMENSION = 10;
const int HSV_HIST_10_DIMENSION = 10;

int main() {
    std::ios::sync_with_stdio(false);
    std::ifstream nameFile("data/images.txt");
    std::vector<std::string> names(5613);
    int k = 0;
    while (std::getline(nameFile, names[k++]));
    nameFile.close();
    auto rgbHist10Tree = ImageTree<double, RGB_HIST_10_DIMENSION>::fromFile("data/RGB_Hist_10.txt");
    auto hsvHist10Tree = ImageTree<double, HSV_HIST_10_DIMENSION>::fromFile("data/HSV_Hist_10.txt");
    std::ifstream rgbHist10File("data/RGB_Hist_10.txt");
    std::ifstream hsvHist10File("data/HSV_Hist_10.txt");
    long rgbHist10Sum = 0;
    long hsvHist10Sum = 0;
    std::vector<std::string> rgbHist10Lines(5613);
    std::vector<std::string> hsvHist10Lines(5613);
    for (int i = 0; i < 5613; ++i) {
        std::getline(rgbHist10File, rgbHist10Lines[i]);
        std::getline(hsvHist10File, hsvHist10Lines[i]);
        std::stringstream rgbHist10Sline(rgbHist10Lines[i]);
        std::stringstream hsvHist10Sline(hsvHist10Lines[i]);
        std::array<double, RGB_HIST_10_DIMENSION> rgbHist10Data;
        std::array<double, HSV_HIST_10_DIMENSION> hsvHist10Data;
        for (int j = 0; j < RGB_HIST_10_DIMENSION; ++j) {
            rgbHist10Sline >> rgbHist10Data[j];
        }

        for (int j = 0; j < RGB_HIST_10_DIMENSION; ++j) {
            hsvHist10Sline >> hsvHist10Data[j];
        }

        Image<double, RGB_HIST_10_DIMENSION> rgbHist10Img(names[i], rgbHist10Data);
        Image<double, HSV_HIST_10_DIMENSION> hsvHist10Img(names[i], hsvHist10Data);

        rgbHist10Tree.search(rgbHist10Data);
        std::vector<Image<double, RGB_HIST_10_DIMENSION>> rgbHist10Results = rgbHist10Tree.getResults();
        rgbHist10Sum += std::count(rgbHist10Results.begin(), rgbHist10Results.end(), rgbHist10Img);

        hsvHist10Tree.search(hsvHist10Data);
        std::vector<Image<double, HSV_HIST_10_DIMENSION>> hsvHist10Results = hsvHist10Tree.getResults();
        hsvHist10Sum += std::count(hsvHist10Results.begin(), hsvHist10Results.end(), hsvHist10Img);
    }

    std::cout << (double)rgbHist10Sum / 56130 << std::endl;
    std::cout << (double)hsvHist10Sum / 56130 << std::endl;

    rgbHist10File.close();
    hsvHist10File.close();
}