#include "impls.h"

std::vector<cv::Mat> split(const cv::Mat& rgb_image) {
    /**
     * TODO: 将图像分割为 blue green red 三个通道，具体内容：
     *  1. 将彩色图片 rgb_image 转换为三个通道的 cv::Mat
     *  2. 将三个通道的 cv::Mat 保存到 std::vector<cv::Mat> 中
     * HINT:
     *  1. 使用 cv::split 函数，其参数如下
     *     void cv::split(
     *          InputArray          src,    // 输入的彩色图像
     *          OutputArrayOfArrays mv      // 输出的三个通道图像
     *     )
     * PS: 在 opencv 中，图像的通道顺序是 BGR: Blue Green Red
     * GOAL:
     *  1. 此任务会自动判断你的代码是否正确，通过测试 (打印出 pass ) 即可
     */
    std::vector<cv::Mat> result(3);

    // TODO: 实现代码
     if (rgb_image.empty()) {
        return result;
    }
    result[0] = cv::Mat::zeros(rgb_image.rows,rgb_image.cols,CV_8UC1); 
    result[1] = cv::Mat::zeros(rgb_image.rows,rgb_image.cols, CV_8UC1); 
    result[2] = cv::Mat::zeros(rgb_image.rows,rgb_image.cols, CV_8UC1);
    for (int i= 0; i<rgb_image.rows;  ++i) {
        const cv::Vec3b* ptr_rgb = rgb_image.ptr<cv::Vec3b>(i); 
        uchar* ptr_b = result[0].ptr<uchar>(i);
        uchar* ptr_g = result[1].ptr<uchar>(i);
        uchar* ptr_r = result[2].ptr<uchar>(i);
        for (int j= 0; j<rgb_image.cols;  ++j) {
            ptr_b[j] = ptr_rgb[j][0]; 
            ptr_g[j] = ptr_rgb[j][1]; 
            ptr_r[j] = ptr_rgb[j][2]; 
        }
    }
    return result;
}
