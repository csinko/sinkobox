#include "maincontent.h"
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>
#include "mainwindow.h"

MainContent::MainContent(QWidget *parent)
	: QWidget(parent) {
			
		button1 = new QPushButton("Settings");
		button2 = new QPushButton("Console");
		button3 = new QPushButton("Info");
		button4 = new QPushButton("Soundboard");
		button5 = new QPushButton("Music");
		button6 = new QPushButton("Games");
		button7 = new QPushButton("");
		button8 = new QPushButton("GPS");
		button9 = new QPushButton("");

		button1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
		button2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
		button3->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
		button4->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
		button5->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
		button6->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
		button7->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
		button8->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
		button9->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
		
		connect(button1, SIGNAL (released()), parent, SLOT (handleSettings()));
		connect(button5, SIGNAL (released()), this, SLOT (handleMusic()));
	
		layout = new QGridLayout();	

		layout->addWidget(button1, 0, 0);
		layout->addWidget(button2, 0, 1);
		layout->addWidget(button3, 0, 2);
		layout->addWidget(button4, 1, 0);
		layout->addWidget(button5, 1, 1);
		layout->addWidget(button6, 1, 2);
		layout->addWidget(button7, 2, 0);
		layout->addWidget(button8, 2, 1);
		layout->addWidget(button9, 2, 2);

		this->setLayout(layout);
}

void MainContent::handleMusic() {
}
