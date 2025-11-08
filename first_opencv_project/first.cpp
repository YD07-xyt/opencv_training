#include<opencv2/opencv.hpp>
#include <iostream>
using namespace std;

int main(){
    // 读取图片
    cv::Mat image= cv::imread("../images/test.jpg");
    int height=image.rows;
    int width=image.cols;
    
    cout << "图片高度(rows):" << height << " 像素" << endl;
    cout << "图片宽度(cols):" << width << " 像素" << endl;
    // 打印图片
    cv::imshow("test",image);
    // 等待
    cv::waitKey(0);
    return 0;
}