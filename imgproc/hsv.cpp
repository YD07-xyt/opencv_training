#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>

using namespace cv;

const int max_value_H = 360 / 2;
const int max_value = 255;
const String window_capture_name = "image";
const String window_detection_name = "对象检测";
int low_H = 0, low_S = 0, low_V = 0;
int high_H = max_value_H, high_S = max_value, high_V = max_value;

static void on_low_H_thresh_trackbar(int, void *) {
  low_H = min(high_H - 1, low_H);
  setTrackbarPos("低 H", window_detection_name, low_H);
}

static void on_high_H_thresh_trackbar(int, void *) {
  high_H = max(high_H, low_H + 1);
  setTrackbarPos("高 H", window_detection_name, high_H);
}

static void on_low_S_thresh_trackbar(int, void *) {
  low_S = min(high_S - 1, low_S);
  setTrackbarPos("低 S", window_detection_name, low_S);
}

static void on_high_S_thresh_trackbar(int, void *) {
  high_S = max(high_S, low_S + 1);
  setTrackbarPos("高 S", window_detection_name, high_S);
}

static void on_low_V_thresh_trackbar(int, void *) {
  low_V = min(high_V - 1, low_V);
  setTrackbarPos("低 V", window_detection_name, low_V);
}

static void on_high_V_thresh_trackbar(int, void *) {
  high_V = max(high_V, low_V + 1);
  setTrackbarPos("高 V", window_detection_name, high_V);
}

int main(int argc, char *argv[]) {

  namedWindow(window_capture_name);
  namedWindow(window_detection_name);

  // 滑块设置 HSV 值的阈值
  createTrackbar("低 H", window_detection_name, &low_H, max_value_H,
                 on_low_H_thresh_trackbar);
  createTrackbar("高 H", window_detection_name, &high_H, max_value_H,
                 on_high_H_thresh_trackbar);
  createTrackbar("低 S", window_detection_name, &low_S, max_value,
                 on_low_S_thresh_trackbar);
  createTrackbar("高 S", window_detection_name, &high_S, max_value,
                 on_high_S_thresh_trackbar);
  createTrackbar("低 V", window_detection_name, &low_V, max_value,
                 on_low_V_thresh_trackbar);
  createTrackbar("高 V", window_detection_name, &high_V, max_value,
                 on_high_V_thresh_trackbar);

  Mat img, img_HSV, img_threshold;
  while (true) {
    img = imread("../images/test.jpg"); // 可替换为视频帧读取（如cap >> img）
    if (img.empty())
      break;

    cvtColor(img, img_HSV, COLOR_BGR2HSV);
    inRange(img_HSV, Scalar(low_H, low_S, low_V),
            Scalar(high_H, high_S, high_V), img_threshold);

    imshow(window_capture_name, img);
    imshow(window_detection_name, img_threshold);

    char key = (char)waitKey(30); // 30ms刷新一次
    if (key == 27)
      break; // 按ESC退出
  }
  return 0;
}