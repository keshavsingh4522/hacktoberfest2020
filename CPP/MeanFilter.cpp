#include <iostream>

#include <opencv2/core/core.hpp>

#include <opencv2/opencv.hpp>

#include<opencv2/imgproc/imgproc.hpp>



using namespace cv;

using namespace std;


int main(int argc, char *argv[])

{
	if (argc != 3) {
		printf("Enter exeFileName imageFileName\n");
	}
	Mat image = imread(argv[1], IMREAD_COLOR);

	if (image.empty()) {
		cout << "Error: No Image to load" << endl;
	}
	Mat gr(image.rows, image.cols, CV_8UC1, Scalar(0));
	cvtColor(image, gr, COLOR_BGR2GRAY);
	Mat output = gr.clone();

	int a = atoi(argv[2]);
	int adj = a / 2;
	 int sum = 0;
	 int avg = 0;
	 for (int i = adj; i < gr.rows - adj; i++) {
		 for (int j = adj; j < gr.cols - adj; j++) {
			 sum = 0;
			 for (int g = i - adj; g <= i + adj; g++) {
				 for (int h = j - adj; h <= j + adj; h++) {
					 sum= sum+(int)gr.at<uchar>(g, h);
				 }
			 }
			 avg = sum / (a * a);
			 output.at<uchar>(i, j) = (uchar)avg;
		 }
	 }
	


	namedWindow("Noisy Image", 1);

	imshow("Noisy Image", gr);



	namedWindow("Filtered Image", 1);

	imshow("Filtered Image", output);





	waitKey();

	gr.release();

	output.release();

	return 0;

}
