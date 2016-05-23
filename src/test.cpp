#include <random>
#include <fstream>
#include <sstream>
#include "ImageTree.h"

const int RGB_HIST_10_DIMENSION = 10;
const int HSV_HIST_10_DIMENSION = 10;
const int RGB_HIST_20_DIMENSION = 20;
const int HSV_HIST_20_DIMENSION = 20;

int main() {
    std::ios::sync_with_stdio(false);
    std::ifstream nameFile("data/images.txt");
    std::vector<std::string> names(5613);
    int k = 0;
    while (std::getline(nameFile, names[k++]));
    nameFile.close();
    auto rgbHist10Tree = ImageTree<double, RGB_HIST_10_DIMENSION>::fromFile("data/RGB_Hist_10.txt");
    auto hsvHist10Tree = ImageTree<double, HSV_HIST_10_DIMENSION>::fromFile("data/HSV_Hist_10.txt");
    auto rgbHist20Tree = ImageTree<double, RGB_HIST_20_DIMENSION>::fromFile("data/RGB_Hist_20.txt");
    auto hsvHist20Tree = ImageTree<double, HSV_HIST_20_DIMENSION>::fromFile("data/HSV_Hist_20.txt");
    std::ifstream rgbHist10File("data/RGB_Hist_10.txt");
    std::ifstream hsvHist10File("data/HSV_Hist_10.txt");
    std::ifstream rgbHist20File("data/RGB_Hist_20.txt");
    std::ifstream hsvHist20File("data/HSV_Hist_20.txt");
    long rgbHist10Sum = 0;
    long hsvHist10Sum = 0;
    long rgbHist20Sum = 0;
    long hsvHist20Sum = 0;
    std::vector<std::string> rgbHist10Lines(5613);
    std::vector<std::string> hsvHist10Lines(5613);
    std::vector<std::string> rgbHist20Lines(5613);
    std::vector<std::string> hsvHist20Lines(5613);
    for (int i = 0; i < 5613; ++i) {
        std::getline(rgbHist10File, rgbHist10Lines[i]);
        std::getline(hsvHist10File, hsvHist10Lines[i]);
        std::getline(rgbHist20File, rgbHist20Lines[i]);
        std::getline(hsvHist20File, hsvHist20Lines[i]);
        std::stringstream rgbHist10Sline(rgbHist10Lines[i]);
        std::stringstream hsvHist10Sline(hsvHist10Lines[i]);
        std::stringstream rgbHist20Sline(rgbHist20Lines[i]);
        std::stringstream hsvHist20Sline(hsvHist20Lines[i]);
        std::array<double, RGB_HIST_10_DIMENSION> rgbHist10Data;
        std::array<double, HSV_HIST_10_DIMENSION> hsvHist10Data;
        std::array<double, RGB_HIST_20_DIMENSION> rgbHist20Data;
        std::array<double, HSV_HIST_20_DIMENSION> hsvHist20Data;
        for (int j = 0; j < RGB_HIST_10_DIMENSION; ++j) {
            rgbHist10Sline >> rgbHist10Data[j];
        }

        for (int j = 0; j < RGB_HIST_10_DIMENSION; ++j) {
            hsvHist10Sline >> hsvHist10Data[j];
        }
        for (int j = 0; j < RGB_HIST_20_DIMENSION; ++j) {
            rgbHist20Sline >> rgbHist20Data[j];
        }

        for (int j = 0; j < RGB_HIST_20_DIMENSION; ++j) {
            hsvHist20Sline >> hsvHist20Data[j];
        }

        Image<double, RGB_HIST_10_DIMENSION> rgbHist10Img(names[i], rgbHist10Data);
        Image<double, HSV_HIST_10_DIMENSION> hsvHist10Img(names[i], hsvHist10Data);
        Image<double, RGB_HIST_20_DIMENSION> rgbHist20Img(names[i], rgbHist20Data);
        Image<double, HSV_HIST_20_DIMENSION> hsvHist20Img(names[i], hsvHist20Data);

        rgbHist10Tree.search(rgbHist10Data);
        std::vector<Image<double, RGB_HIST_10_DIMENSION>> rgbHist10Results = rgbHist10Tree.getResults();
        rgbHist10Sum += std::count(rgbHist10Results.begin(), rgbHist10Results.end(), rgbHist10Img);

        hsvHist10Tree.search(hsvHist10Data);
        std::vector<Image<double, HSV_HIST_10_DIMENSION>> hsvHist10Results = hsvHist10Tree.getResults();
        hsvHist10Sum += std::count(hsvHist10Results.begin(), hsvHist10Results.end(), hsvHist10Img);

        rgbHist20Tree.search(rgbHist20Data);
        std::vector<Image<double, RGB_HIST_20_DIMENSION>> rgbHist20Results = rgbHist20Tree.getResults();
        rgbHist20Sum += std::count(rgbHist20Results.begin(), rgbHist20Results.end(), rgbHist20Img);

        hsvHist20Tree.search(hsvHist20Data);
        std::vector<Image<double, HSV_HIST_20_DIMENSION>> hsvHist20Results = hsvHist20Tree.getResults();
        hsvHist20Sum += std::count(hsvHist20Results.begin(), hsvHist20Results.end(), hsvHist20Img);
    }

    std::cout << (double)rgbHist10Sum / 56130 << std::endl;
    std::cout << (double)hsvHist10Sum / 56130 << std::endl;
    std::cout << (double)rgbHist20Sum / 56130 << std::endl;
    std::cout << (double)hsvHist20Sum / 56130 << std::endl;

    rgbHist10File.close();
    hsvHist10File.close();
    rgbHist20File.close();
    hsvHist20File.close();
}
