#include<opencv2/opencv.hpp>

using namespace cv;

int main()
{
    //读取图像
    Mat image = imread("/home/lin/Pictures/hm2.png",1);
    //将图像转换为HSV空间
    Mat hsv_image;
    cvtColor(image,hsv_image,COLOR_BGR2HSV);
    //定义颜色范围
    Scalar lower_brown(0,30,20);
    Scalar upper_brown(30,255,200);
    //定义掩码
    Mat mask;
    //利用阀值把目标图形的掩码切割出来
    inRange(hsv_image,lower_brown,upper_brown,mask);
    //灰度图转RGB
    cvtColor(mask,mask,COLOR_GRAY2BGR);
    //恢复颜色
    for(int i=0;i<mask.rows;i++){
        for(int j=0;j<mask.cols;j++){
            if (mask.at<Vec3b>(i,j)[0]==0&&mask.at<Vec3b>(i,j)[1]==0&&mask.at<Vec3b>(i,j)[2]==0){
                mask.at<Vec3b>(i,j)[0]=255;
                mask.at<Vec3b>(i,j)[1]=255;
                mask.at<Vec3b>(i,j)[2]=255;
            }else{
                mask.at<Vec3b>(i,j)[0]=0;
                mask.at<Vec3b>(i,j)[1]=51;
                mask.at<Vec3b>(i,j)[2]=140;
            }
        }
    }
    //显示图像
    imshow("image",image);
    imshow("hsv_image",hsv_image);
    imshow("mask",mask);
    
    waitKey(0);

    return 0;
}