#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QApplication>
#include <QWidget>
#include <QLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "maincontent.h"
namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow {
	Q_OBJECT
	QWidget *mainWidget;
	QVBoxLayout *layout;	
	QHBoxLayout *menuLayout;
	QWidget *menuWidget;
	QWidget *contentWidget;
	QPushButton *backButton;
	public:
		explicit MainWindow(QWidget *parent = 0);
	public slots:
		void handleSettings();
		void handleBack();
};

#endif // MAINWINDOW _H

