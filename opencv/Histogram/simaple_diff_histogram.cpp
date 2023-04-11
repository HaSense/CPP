#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    // 원본 이미지 불러오기
    Mat img = imread("/home/iot/work/opencv/image/histo_test.jpg", IMREAD_GRAYSCALE);

    // 히스토그램 평활화 적용
    Mat equalized;
    equalizeHist(img, equalized);

    // 원본 이미지와 평활화된 이미지에 대한 히스토그램 계산
    int histSize = 256;
    float range[] = {0, 256};
    const float* histRange = {range};
    bool uniform = true, accumulate = false;

    Mat hist, equalizedHist;
    calcHist(&img, 1, 0, Mat(), hist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&equalized, 1, 0, Mat(), equalizedHist, 1, &histSize, &histRange, uniform, accumulate);

    // 히스토그램 그래프 출력을 위한 변수 설정
    int hist_w = 512, hist_h = 400;
    int bin_w = cvRound((double)hist_w/histSize);
    Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(0,0,0));
    Mat equalizedHistImage(hist_h, hist_w, CV_8UC1, Scalar(0,0,0));

    // 히스토그램 그래프 그리기
    normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    normalize(equalizedHist, equalizedHist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

    for (int i = 1; i < histSize; i++) {
        line(histImage, Point(bin_w*(i-1), hist_h-cvRound(hist.at<float>(i-1))),
             Point(bin_w*(i), hist_h-cvRound(hist.at<float>(i))),
             Scalar(255, 255, 255), 2, LINE_AA);
        line(equalizedHistImage, Point(bin_w*(i-1), hist_h-cvRound(equalizedHist.at<float>(i-1))),
             Point(bin_w*(i), hist_h-cvRound(equalizedHist.at<float>(i))),
             Scalar(255, 255, 255), 2, LINE_AA);
    }

    // 이미지와 히스토그램 그래프 출력
    imshow("Original Image", img);
    imshow("Equalized Image", equalized);
    imshow("Original Histogram", histImage);
    imshow("Equalized Histogram", equalizedHistImage);

    waitKey(0);
    return 0;
}
