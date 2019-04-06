#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_abb.h"
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>

class abb : public QMainWindow
{
	Q_OBJECT

public:
	abb(QWidget *parent = Q_NULLPTR);
	void createFields();
	bool fields[64];
	int numer;

private:
	Ui::abbClass ui;

	cv::VideoCapture capWebcam;
	cv::Mat matOriginal;
	cv::Mat matProcessed;

	QImage qimgOriginal;
	QImage qimgProcessed;
	std::vector<cv::Vec3f > vecCircles;
	std::vector<cv::Vec3f>::iterator itrCircles;

	QTimer* tmrTimer;

private slots:
	void on_btnPauseOrResume_clicked(bool);

public slots:
	bool processFrameAndUpdateGUI();
	void cameraopen();
};
