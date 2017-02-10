#include <QApplication>
#include <QFont>
#include <QGridLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>
#include <QPalette>
#include <QFile>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
	
	QApplication *app = new QApplication(argc, argv);
	QFile File(QApplication::applicationDirPath() + "/stylesheet.qss");
	File.open(QFile::ReadOnly);
	QString StyleSheet = QLatin1String(File.readAll());
	app->setStyleSheet(StyleSheet);


	MainWindow mainWindow;
	mainWindow.showFullScreen();

	QPalette pal = app->palette();
	pal.setColor(QPalette::Window, Qt::black);
	app->setPalette(pal);

	return app->exec();
}
