#include <iostream>
#include <opencv2/opencv.hpp>

int main ()
{
    //创建一个400*600的单通道图像
    cv::Mat image(400,600,CV_8U);

    //对每个像素值设置颜色
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            //计算当前像素在横向上的位置比例
            float x = (float)j / image.cols;
            //根据比例计算当前像素的值
            uchar value = (uchar)(255 * (1-x));
            //设置当前像素的值
            image.at<uchar>(i,j) = value;
        }
    }

    //在窗口中显示图像
    cv::imshow("image",image);
    cv::waitKey(0);

    return 0;
}