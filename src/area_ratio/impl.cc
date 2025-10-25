#include "impls.h"
#include <opencv2/opencv.hpp> 


float compute_area_ratio(const std::vector<cv::Point>& contour) {
    /**
     * 要求：
     *      计算输入的轮廓的面积与它的最小外接矩形面积的比例。自行查找
     * 获得轮廓面积的函数。这个量可以用来判断一个轮廓到底有多靠近一个矩形。
     * 
     * 提示：
     * 无。
     * 
     * 通过条件:
     * 运行测试点，通过即可。
     */
    double contourArea = cv::contourArea(contour);
    if (contourArea <= 0) return 0.f;
    cv::RotatedRect minRect = cv::minAreaRect(contour);
    float rectArea = minRect.size.width  * minRect.size.height; 
    if (rectArea <= std::numeric_limits<float>::epsilon()) 
        return 0.f;
    return static_cast<float>(contourArea / rectArea);
}