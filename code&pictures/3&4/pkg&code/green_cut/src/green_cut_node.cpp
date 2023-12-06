#include<opencv2/opencv.hpp>

using namespace cv;

int main()
{
    //读取图像
    Mat image = imread("/home/lin/Pictures/hm2.png",1);
    //设置阀值
    Scalar lower_green(0,100,0);
    Scalar upper_green(80,255,80);
    //定义掩膜和结果图像
    Mat mask;
    //依据阀值处理原图像，得到目标形状的掩膜
    inRange(image,lower_green,upper_green,mask);
    //灰度图转BGR
    cvtColor(mask,mask,COLOR_GRAY2BGR);
    //把掩膜的颜色变回原图像的颜色
    for(int i=0;i<mask.rows;i++){
        for(int j=0;j<mask.cols;j++){
            if (mask.at<Vec3b>(i,j)[0]==255&&mask.at<Vec3b>(i,j)[1]==255&&mask.at<Vec3b>(i,j)[2]==255){
                mask.at<Vec3b>(i,j)[0]=0;
                mask.at<Vec3b>(i,j)[1]=255;
                mask.at<Vec3b>(i,j)[2]=0;
            }else{
                mask.at<Vec3b>(i,j)[0]=255;
                mask.at<Vec3b>(i,j)[1]=255;
                mask.at<Vec3b>(i,j)[2]=255;
            }
        }
    }
    //显示切割后的图像
    imshow("image",image);

    imshow("mask",mask);

    waitKey(0);

    return 0;
}