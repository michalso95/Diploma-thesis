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

abb::abb(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	cameraopen();
	processFrameAndUpdateGUI();
		bool zmien[64];
	for (int i = 0; i < 64; i++)
	{
		zmien[i] = fields[i];
	}
	on_btnPauseOrResume_clicked(zmien[64]);
}

