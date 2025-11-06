#include<opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace std;
int main(){

    cv::Mat image= cv::imread("../images/test.jpg");
    int height=image.rows;
    int width=image.cols;
    
    cout << "图片高度(rows):" << height << " 像素" << endl;
    cout << "图片宽度(cols):" << width << " 像素" << endl;

    cv::imshow("test",image);
    cv::waitKey(0);
    return 0;
}