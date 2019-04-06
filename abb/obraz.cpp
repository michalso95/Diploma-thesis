#include "abb.h"
#include "ui_abb.h"

#include <qlabel.h>
#include <qpixmap.h>
#include <qmessagebox.h>
#include <qtimer.h>

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>

#include <string>
#include <iostream>

using namespace std;
using namespace cv;

void abb::cameraopen() {
	capWebcam.open(0);
	//capWebcam = cv::VideoCapture("C:/Users/michal/desktop/chessvideo.avi");

if (capWebcam.isOpened() == false) {
	ui.txtXYRadius->appendPlainText("error: nie uda³o sie otworzyc kanery");
	return;
}
tmrTimer = new QTimer(this);
connect(tmrTimer, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGUI()));
tmrTimer->start(20);
}

bool abb::processFrameAndUpdateGUI() {
	capWebcam.read(matOriginal);
	cv::resize(matOriginal, matOriginal, Size(450, 450), 0, 0, INTER_CUBIC);
	if (matOriginal.empty() == true);
	//cv::cvtColor(matOriginal, matOriginal, CV_BGR2RGB);
	cv::inRange(matOriginal, cv::Scalar(0, 10, 70), cv::Scalar(255, 50, 255), matProcessed);
	//cv::inRange(matOriginal, cv::Scalar(40, 40, 40), cv::Scalar(70, 255, 255), matProcessed);
	GaussianBlur(matProcessed, matProcessed, cv::Size(5, 5), 1);
	//cv::erode(matProcessed, matProcessed, 5);
	for (int i = 0; i < 64; i++) {
		fields[i] = false;
	}
	HoughCircles(matProcessed, vecCircles, CV_HOUGH_GRADIENT, 5, matProcessed.rows/2, 200, 100, 40, 70);
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			cv::Rect rect(25+i*50, 25+j*50, 50, 50);
			cv::rectangle(matOriginal, rect, cv::Scalar(255, 0, 0));
		}
	}
	
	for (itrCircles = vecCircles.begin(); itrCircles != vecCircles.end(); itrCircles++) {
		ui.txtXYRadius->appendPlainText(QString("ball position: X= ") + QString::number((*itrCircles)[0]).rightJustified(4, ' ') +
			(QString(", y = ") + QString::number((*itrCircles)[1]).rightJustified(4, ' ') + QString(", radius = ") + QString::number((*itrCircles)[2]).rightJustified(7, ' ')));

		/*bool A1 = false;
		if (((int)(*itrCircles)[0] > 25) && ((int)(*itrCircles)[0] < 75) && ((int)(*itrCircles)[1] > 25) && ((int)(*itrCircles)[1] < 75)) {
		A1 = true;
		if (A1 = true) { ui.txtXYRadius->appendPlainText(QString("ZIOMEK na A1")); }
		}*/
		
		for (int i = 0; i<8; i++) {
			for (int j = 0; j < 8; j++) {
				if (((int)(*itrCircles)[0] > 25 + i * 50) && ((int)(*itrCircles)[0] < 75 + i * 50) && ((int)(*itrCircles)[1] > 25 + j * 50) && ((int)(*itrCircles)[1] < 75 + j * 50)) {
					fields[i * 8 + j] = true; 
					numer = (1+(i*8 + j));
					//string number = std::to_string(numer);
					if (fields[i*8+j] = true) { ui.txtXYRadius->appendPlainText(QString::number(numer)); }
				}
				//else fields[i * 8 + j] = false;
			}
		}
		
		cv::circle(matOriginal, cv::Point((int)(*itrCircles)[0], (int)(*itrCircles)[1]), 3, cv::Scalar(0, 255, 0), CV_FILLED);
		cv::circle(matOriginal, cv::Point((int)(*itrCircles)[0], (int)(*itrCircles)[1]), (int)(*itrCircles)[2], cv::Scalar(0, 0, 255), 3);
	}
	
	cv::cvtColor(matOriginal, matOriginal, CV_BGR2RGB);

	QImage qimgOriginal((uchar*)matOriginal.data, matOriginal.cols, matOriginal.rows, matOriginal.step, QImage::Format_RGB888);
	QImage qimgProcessed((uchar*)matProcessed.data, matProcessed.cols, matProcessed.rows, matProcessed.step, QImage::Format_Indexed8);

	ui.lblOriginal->setPixmap(QPixmap::fromImage(qimgOriginal));
	ui.lblProcessed->setPixmap(QPixmap::fromImage(qimgProcessed));

	return fields[64];

}

void abb::on_btnPauseOrResume_clicked(bool)
{
	if (tmrTimer->isActive() == true) {
		tmrTimer->stop();
		ui.btnPauseOrResume->setText("Resume");

		for (int i=0; i<64; i++)
		{
			if (fields[i] == true){ ui.zmienne->appendPlainText(QString::number(i+1) + QString(" jest aktywny")); }
			else ui.zmienne->appendPlainText(QString::number(i+1) + QString(" jest pusty"));
		
		}
	}
	else {
		tmrTimer->start(20);
		ui.btnPauseOrResume->setText("Stop");
	}
};
