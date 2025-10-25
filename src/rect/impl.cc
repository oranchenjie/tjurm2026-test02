#include "impls.h"
#include <opencv2/opencv.hpp>
using namespace cv;

std::pair<cv::Rect, cv::RotatedRect> get_rect_by_contours(const cv::Mat& input) {
    /**
     * 要求：
     * 使用findCountours函数找出输入图像（彩色图像）中的矩形轮廓，并且返回它的外接矩形，以及
     * 最小面积外接矩形。所需要的函数自行查找。
     * 
     * 通过条件：
     * 运行测试点，你找到的矩形跟答案一样就行。
    */
    std::pair<cv::Rect, cv::RotatedRect> res;
    // IMPLEMENT YOUR CODE HERE
    if(input.empty()){
        return res;
    }
    Mat gray, bin;
    cvtColor(input, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, gray, Size(5, 5), 0); // 去噪声
    threshold(gray,bin,0,255,THRESH_BINARY_INV|THRESH_OTSU); 
    Mat core = getStructuringElement(MORPH_RECT, Size(3, 3)); 
    morphologyEx(bin, bin, MORPH_CLOSE, core); 
    std::vector<std::vector<Point>> cvv;
    std::vector<Vec4i> hierarchy;
    findContours(bin,cvv, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    int target_idx = -1;
    double min_area = 100; 
    for (int i = 0; i < cvv.size();  ++i) {
        double area = contourArea(cvv[i]);
        if (area < min_area) continue;
        std::vector<Point> approx;
        approxPolyDP(cvv[i], approx, arcLength(cvv[i], true) * 0.02, true);
        if (approx.size()  == 4 && isContourConvex(approx)) {
            target_idx = i;
            break;
        }
    }
    if (target_idx == -1) return res;
    std::vector<Point> target_contour = cvv[target_idx];
    std::vector<Point> approx;
    approxPolyDP(target_contour,approx,arcLength(target_contour,true)*0.02, true);
    res.first=boundingRect(approx);
    res.second=minAreaRect(approx);
    return res;
}