#include "impls.h"
using namespace cv;

cv::Mat my_resize(const cv::Mat& input, float scale) {
    /**
     * 要求：
     *      实现resize算法，只能使用基础的语法，比如说for循环，Mat的基本操作。不能
     * 用cv::resize。resize算法的内容自行查找学习，不是很难。
     * 
     * 提示：
     * 无。
     * 
     * 通过条件：
     * 运行测试点，你的结果跟答案长的差不多就行。
     */
    int new_rows = input.rows * scale, new_cols = input.cols * scale;
    // IMPLEMENT YOUR CODE HERE
    Mat out=Mat::zeros(new_rows, new_cols, input.type());
     if (new_rows == 0 || new_cols == 0) return out;
     for (int y=0; y<new_rows; y++) {
        int new_y=static_cast<int>(y/scale+0.5f);
        new_y=std::min(std::max(new_y,0),input.rows-1);
        for (int x=0; x<new_cols; x++) {
        int new_x=static_cast<int>(x/scale+0.5f);
        new_x=std::min(std::max(new_x,0),input.cols-1);
        const uchar* srcp=input.ptr<uchar>(new_y)+new_x*input.elemSize(); 
         uchar* dstp=out.ptr<uchar>(y)+x*out.elemSize(); 
         for(int i=0;i<input.channels();i++){
               dstp[i]=srcp[i];
         }
     }
     }
    return out;
}