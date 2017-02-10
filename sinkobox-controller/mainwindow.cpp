#include "mainwindow.h"
#include <QCoreApplication>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>
#include <QApplication>
#include "maincontent.h"
#include "settingscontent.h"
#include <QLabel>
#include <string>
#include <stdio.h>
#include "infocontent.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {	
	mainWidget = new QWidget(this);
	this->setCentralWidget(mainWidget);
	
	layout = new QVBoxLayout(mainWidget);

	menuLayout = new QHBoxLayout();
	backButton = new QPushButton("<-");
	backButton->setEnabled(false);
	menuLayout->addWidget(backButton);
	menuLayout->addWidget(new QLabel("Sinkobox"));
	menuLayout->addWidget(new QWidget());
	
	menuWidget = new QWidget(this);
	menuWidget->setLayout(menuLayout);

	contentWidget = new MainContent(this);

	layout->addWidget(menuWidget, 0);
	layout->addWidget(contentWidget, 1);
	mainWidget->setLayout(layout);
	
	connect(backButton, SIGNAL (released()), this, SLOT (handleBack()));

}


void MainWindow::handleSettings() {
	printf("Settings Clicked\n");
	layout->removeWidget(contentWidget);
	delete contentWidget;
	contentWidget = new SettingsContent(this);
	layout->addWidget(contentWidget, 1);
	backButton->setEnabled(true);
	this->repaint();
}

void MainWindow::handleInfo() {
	printf("Info Clicked\n");
	layout->removeWidget(contentWidget);
	delete contentWidget;
	contentWidget = new InfoContent(this);
	layout->addWidget(contentWidget, 1);
	backButton->setEnabled(true);
	this->repaint();
}

void MainWindow::handleBack() {
	printf("Back Clicked\n");
	layout->removeWidget(contentWidget);
	delete contentWidget;
	contentWidget = new MainContent(this);
	layout->addWidget(contentWidget, 1);
	backButton->setEnabled(false);
	
}
