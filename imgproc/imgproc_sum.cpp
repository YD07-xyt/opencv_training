
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace cv;

Mat src, dst;

int morph_elem = 0;
int morph_size = 0;
int morph_operator = 0;
int const max_operator = 4;
int const max_elem = 2;
int const max_kernel_size = 21;

const char *window_name = "形态学变换演示";

void Morphology_Operations(int, void *);

int main(int argc, char **argv) {

  src=imread("../images/test.jpg");
  if (src.empty()) {
    std::cout << "无法打开或找不到图像！\n" << std::endl;
    return EXIT_FAILURE;
  }
  cv::GaussianBlur(src,src,cv::Size(3,3),3);
  namedWindow(window_name, WINDOW_AUTOSIZE); // 创建窗口

  createTrackbar(
      "算子：\n 0:开运算 -- 1:闭运算 \n 2:梯度 -- 3:顶帽 \n 4:底帽",
      window_name, &morph_operator, max_operator, Morphology_Operations);

  createTrackbar("元素：\n 0:矩形 -- 1:十字 -- 2:椭圆", window_name,
                 &morph_elem, max_elem, Morphology_Operations);

  createTrackbar("核尺寸：\n 2n +1", window_name, &morph_size, max_kernel_size,
                 Morphology_Operations);

  Morphology_Operations(0, 0);

  waitKey(0);
  return 0;
}

void Morphology_Operations(int, void *) {
  // 因为 MORPH_X：2,3,4,5 和 6
  int operation = morph_operator + 2;

  Mat element = getStructuringElement(
      morph_elem, Size(2 * morph_size + 1, 2 * morph_size + 1),
      Point(morph_size, morph_size));

  morphologyEx(src, dst, operation, element);
  imshow(window_name, dst);
}