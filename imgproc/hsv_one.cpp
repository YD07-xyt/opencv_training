#include<opencv2/opencv.hpp>


int main(){
    cv::Mat img=cv::imread("../images/test.jpg");
    cv::Mat img_hsv,img_hsv01,img_hsv02;
    cv::cvtColor(img,img_hsv,cv::COLOR_BGR2HSV,0);
    cv::inRange(img_hsv,cv::Scalar(0,40,40),cv::Scalar(10,255,255),img_hsv01);
    cv::inRange(img_hsv,cv::Scalar(170,40,40),cv::Scalar(179,255,255),img_hsv02);
    cv::bitwise_and(img_hsv01,img_hsv02,img_hsv);
    cv::Mat kernel=cv::getStructuringElement(cv::MORPH_RECT,cv::Size(3,3));
    //cv::morphologyEx(img_hsv,img_hsv,cv::MORPH_GRADIENT,kernel);
    cv::imshow("test",img_hsv);
    cv::waitKey(0);    
    return 0;
}