#include<opencv2/opencv.hpp>
using namespace std;

cv::Mat gray,gray_threshold,erode,dilate,dst;

int main(){
    cv::Mat img =cv::imread("../images/test.jpg");

    cv::cvtColor(img,gray,cv::COLOR_BGR2GRAY,0);
    /* 0: Binary
        1: Binary Inverted
        2: Threshold Truncated
        3: Threshold to Zero
        4: Threshold to Zero Inverted
    */
    //cv::threshold(gray,gray_threshold,127,255,cv::THRESH_BINARY | cv::THRESH_OTSU);
    cv::Mat kernel=cv::getStructuringElement(cv::MORPH_RECT,cv::Size(3,3));
    cv::GaussianBlur(gray,gray,cv::Size(3,3),3); 
    //
    //cv::erode(img,erode,kernel,cv::Point(-1,-1),1);
    //cv::dilate(img,dilate,kernel,cv::Point(-1,-1),1);
    //cv::subtract(dilate,erode,dst);
    //

    // 开启: MORPH_OPEN 
    // 关闭: MORPH_CLOSE 
    // 梯度: MORPH_GRADIENT
    // 顶帽: MORPH_TOPHAT
    // 黑帽: MORPH_BLACKHAT
    //击中击不中变换:MORPH_HITMISS
    cv::morphologyEx(gray,dst,cv::MORPH_GRADIENT,kernel);
    
    //cv::namedWindow("test", cv::WINDOW_NORMAL);
    cv::imshow("test",img);
    //cv::imshow("gary",gray_threshold);
    cv::imshow("dst",dst);
    cv::waitKey(0);
    return 0;
}