#include <iostream>
#include <opencv2/opencv.hpp>

int main ()
{
    //创建一个400*600的黑色3通道图像
    cv::Mat image(400,600,CV_8UC3, cv::Scalar(0,0,0));

    //对每个像素设置为绿色
    for (int y = 0; y < image.rows; y++)
    {
        for (int x = 0; x < image.cols; x++)
        {
            image.at<cv::Vec3b>(y,x) = cv::Vec3b(0,255,0);//设置为RGB颜色空间的绿色
        }
    }

    //在窗口中显示图像
    cv::imshow("green",image);
    cv::waitKey(0);

    return 0;
}