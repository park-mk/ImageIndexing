#include <random>
#include <fstream>
#include <sstream>
#include "ImageTree.h"

const int RGB_HIST_10_DIMENSION = 10;
const int HSV_HIST_10_DIMENSION = 10;
const int RGB_HIST_20_DIMENSION = 20;
const int HSV_HIST_20_DIMENSION = 20;
const int COLOR_MOMENT_DIMENSION = 9;

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
    auto rgbHist10TreeST = ImageTree<double, RGB_HIST_10_DIMENSION>::fromFile("data/RGB_Hist_10_St.txt");
    auto hsvHist10TreeST = ImageTree<double, HSV_HIST_10_DIMENSION>::fromFile("data/HSV_Hist_10_St.txt");
    auto rgbHist20TreeST = ImageTree<double, RGB_HIST_20_DIMENSION>::fromFile("data/RGB_Hist_20_St.txt");
    auto hsvHist20TreeST = ImageTree<double, HSV_HIST_20_DIMENSION>::fromFile("data/HSV_Hist_20_St.txt");
    auto colorMomentTree = ImageTree<double, COLOR_MOMENT_DIMENSION>::fromFile("data/Color_Moment.txt");

    std::ifstream rgbHist10File("data/RGB_Hist_10.txt");
    std::ifstream hsvHist10File("data/HSV_Hist_10.txt");
    std::ifstream rgbHist20File("data/RGB_Hist_20.txt");
    std::ifstream hsvHist20File("data/HSV_Hist_20.txt");
    std::ifstream rgbHist10FileST("data/RGB_Hist_10_St.txt");
    std::ifstream hsvHist10FileST("data/HSV_Hist_10_St.txt");
    std::ifstream rgbHist20FileST("data/RGB_Hist_20_St.txt");
    std::ifstream hsvHist20FileST("data/HSV_Hist_20_St.txt");
    std::ifstream colorMomentFile("data/Color_Moment.txt");

    long rgbHist10Sum = 0;
    long hsvHist10Sum = 0;
    long rgbHist20Sum = 0;
    long hsvHist20Sum = 0;
    long rgbHist10SumST = 0;
    long hsvHist10SumST = 0;
    long rgbHist20SumST = 0;
    long hsvHist20SumST = 0;
    long colorMomentSum = 0;

    std::vector<std::string> rgbHist10Lines(5613);
    std::vector<std::string> hsvHist10Lines(5613);
    std::vector<std::string> rgbHist20Lines(5613);
    std::vector<std::string> hsvHist20Lines(5613);
    std::vector<std::string> rgbHist10LinesST(5613);
    std::vector<std::string> hsvHist10LinesST(5613);
    std::vector<std::string> rgbHist20LinesST(5613);
    std::vector<std::string> hsvHist20LinesST(5613);
    std::vector<std::string> colorMomentLines(5613);

    for (int i = 0; i < 5613; ++i) {
        std::getline(rgbHist10File, rgbHist10Lines[i]);
        std::getline(hsvHist10File, hsvHist10Lines[i]);
        std::getline(rgbHist20File, rgbHist20Lines[i]);
        std::getline(hsvHist20File, hsvHist20Lines[i]);
        std::getline(rgbHist10FileST, rgbHist10LinesST[i]);
        std::getline(hsvHist10FileST, hsvHist10LinesST[i]);
        std::getline(rgbHist20FileST, rgbHist20LinesST[i]);
        std::getline(hsvHist20FileST, hsvHist20LinesST[i]);
        std::getline(colorMomentFile, colorMomentLines[i]);

        std::stringstream rgbHist10Sline(rgbHist10Lines[i]);
        std::stringstream hsvHist10Sline(hsvHist10Lines[i]);
        std::stringstream rgbHist20Sline(rgbHist20Lines[i]);
        std::stringstream hsvHist20Sline(hsvHist20Lines[i]);
        std::stringstream rgbHist10SlineST(rgbHist10LinesST[i]);
        std::stringstream hsvHist10SlineST(hsvHist10LinesST[i]);
        std::stringstream rgbHist20SlineST(rgbHist20LinesST[i]);
        std::stringstream hsvHist20SlineST(hsvHist20LinesST[i]);
        std::stringstream colorMomentSline(colorMomentLines[i]);

        std::array<double, RGB_HIST_10_DIMENSION> rgbHist10Data;
        std::array<double, HSV_HIST_10_DIMENSION> hsvHist10Data;
        std::array<double, RGB_HIST_20_DIMENSION> rgbHist20Data;
        std::array<double, HSV_HIST_20_DIMENSION> hsvHist20Data;
        std::array<double, RGB_HIST_10_DIMENSION> rgbHist10DataST;
        std::array<double, HSV_HIST_10_DIMENSION> hsvHist10DataST;
        std::array<double, RGB_HIST_20_DIMENSION> rgbHist20DataST;
        std::array<double, HSV_HIST_20_DIMENSION> hsvHist20DataST;
        std::array<double, COLOR_MOMENT_DIMENSION> colorMomentData;

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

        for (int j = 0; j < RGB_HIST_10_DIMENSION; ++j) {
            rgbHist10SlineST >> rgbHist10DataST[j];
        }

        for (int j = 0; j < RGB_HIST_10_DIMENSION; ++j) {
            hsvHist10SlineST >> hsvHist10DataST[j];
        }
        for (int j = 0; j < RGB_HIST_20_DIMENSION; ++j) {
            rgbHist20SlineST >> rgbHist20DataST[j];
        }

        for (int j = 0; j < RGB_HIST_20_DIMENSION; ++j) {
            hsvHist20SlineST >> hsvHist20DataST[j];
        }

        for (int j = 0; j < COLOR_MOMENT_DIMENSION; ++j) {
            colorMomentSline >> colorMomentData[j];
        }

        Image<double, RGB_HIST_10_DIMENSION> rgbHist10Img(names[i], rgbHist10Data);
        Image<double, HSV_HIST_10_DIMENSION> hsvHist10Img(names[i], hsvHist10Data);
        Image<double, RGB_HIST_20_DIMENSION> rgbHist20Img(names[i], rgbHist20Data);
        Image<double, HSV_HIST_20_DIMENSION> hsvHist20Img(names[i], hsvHist20Data);
        Image<double, RGB_HIST_10_DIMENSION> rgbHist10ImgST(names[i], rgbHist10DataST);
        Image<double, HSV_HIST_10_DIMENSION> hsvHist10ImgST(names[i], hsvHist10DataST);
        Image<double, RGB_HIST_20_DIMENSION> rgbHist20ImgST(names[i], rgbHist20DataST);
        Image<double, HSV_HIST_20_DIMENSION> hsvHist20ImgST(names[i], hsvHist20DataST);
        Image<double, COLOR_MOMENT_DIMENSION> colorMomentImg(names[i], colorMomentData);

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

        rgbHist10TreeST.search(rgbHist10DataST);
        std::vector<Image<double, RGB_HIST_10_DIMENSION>> rgbHist10ResultsST = rgbHist10TreeST.getResults();
        rgbHist10SumST += std::count(rgbHist10ResultsST.begin(), rgbHist10ResultsST.end(), rgbHist10ImgST);

        hsvHist10TreeST.search(hsvHist10DataST);
        std::vector<Image<double, HSV_HIST_10_DIMENSION>> hsvHist10ResultsST = hsvHist10TreeST.getResults();
        hsvHist10SumST += std::count(hsvHist10ResultsST.begin(), hsvHist10ResultsST.end(), hsvHist10ImgST);

        rgbHist20TreeST.search(rgbHist20DataST);
        std::vector<Image<double, RGB_HIST_20_DIMENSION>> rgbHist20ResultsST = rgbHist20TreeST.getResults();
        rgbHist20SumST += std::count(rgbHist20ResultsST.begin(), rgbHist20ResultsST.end(), rgbHist20ImgST);

        hsvHist20TreeST.search(hsvHist20DataST);
        std::vector<Image<double, HSV_HIST_20_DIMENSION>> hsvHist20ResultsST = hsvHist20TreeST.getResults();
        hsvHist20SumST += std::count(hsvHist20ResultsST.begin(), hsvHist20ResultsST.end(), hsvHist20ImgST);

        colorMomentTree.search(colorMomentData);
        std::vector<Image<double, COLOR_MOMENT_DIMENSION>> colorMomentResults = colorMomentTree.getResults();
        colorMomentSum += std::count(colorMomentResults.begin(), colorMomentResults.end(), colorMomentImg);
    }

    std::cout << "RGB Hist 10d: " << (double)rgbHist10Sum / 56130 << std::endl;
    std::cout << "HSV Hist 10d: " << (double)hsvHist10Sum / 56130 << std::endl;
    std::cout << "RGB Hist 20d: " << (double)rgbHist20Sum / 56130 << std::endl;
    std::cout << "HSV Hist 20d: " << (double)hsvHist20Sum / 56130 << std::endl;
    std::cout << "RGB ST Hist 10d: " << (double)rgbHist10SumST / 56130 << std::endl;
    std::cout << "HSV ST Hist 10d: " << (double)hsvHist10SumST / 56130 << std::endl;
    std::cout << "RGB ST Hist 20d: " << (double)rgbHist20SumST / 56130 << std::endl;
    std::cout << "HSV ST Hist 20d: " << (double)hsvHist20SumST / 56130 << std::endl;
    std::cout << "Color Moment 9d: " << (double)colorMomentSum / 56130 << std::endl;

    rgbHist10File.close();
    hsvHist10File.close();
    rgbHist20File.close();
    hsvHist20File.close();
    rgbHist10FileST.close();
    hsvHist10FileST.close();
    rgbHist20FileST.close();
    hsvHist20FileST.close();
    colorMomentFile.close();
}
