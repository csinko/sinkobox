#include "settingscontent.h"
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QScrollArea>
#include <QScroller>
#include <QLabel>
#include <QRadioButton>

SettingsContent::SettingsContent(QWidget *parent)
	: QWidget(parent) {
		wrapper = new QHBoxLayout();
		scrollArea = new QScrollArea();
		container = new QWidget();
		layout = new QVBoxLayout();
		moveMusicButton = new QPushButton("Move Music");	
		
		container->setAttribute(Qt::WA_TranslucentBackground);
		moveMusicButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
		
		scroller = QScroller::scroller(scrollArea->viewport());	
		QScrollerProperties properties = QScroller::scroller(scroller)->scrollerProperties();
		QVariant overshootPolicy = QVariant::fromValue<QScrollerProperties::OvershootPolicy>(QScrollerProperties::OvershootAlwaysOff);
		properties.setScrollMetric(QScrollerProperties::VerticalOvershootPolicy, overshootPolicy);
		scroller->setScrollerProperties(properties);
		scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		scroller->grabGesture(scrollArea->viewport(),QScroller::LeftMouseButtonGesture);
		
		//Bluetooth Settings
		bluetoothLayout = new QVBoxLayout();
		bluetoothEnabler = new QHBoxLayout();
		bluetoothEnableButton = new QRadioButton("Enabled");
		bluetoothDisableButton = new QRadioButton("Disabled");
		bluetoothEnabler->addWidget(new QLabel("Bluetooth: "));
		bluetoothEnabler->addWidget(bluetoothEnableButton);
		bluetoothEnabler->addWidget(bluetoothDisableButton);
		bluetoothLayout->addLayout(bluetoothEnabler);		

		//Wifi Settings
		wifiLayout = new QVBoxLayout();
		wifiEnabler = new QHBoxLayout();
		wifiAPButton = new QRadioButton("AP");
		wifiClientButton = new QRadioButton("Client");
		wifiEnabler->addWidget(new QLabel("Wifi: "));
		wifiEnabler->addWidget(wifiAPButton);
		wifiEnabler->addWidget(wifiClientButton);
		wifiLayout->addLayout(wifiEnabler);


		//Settings Options
		layout->addWidget(moveMusicButton);
		layout->addSpacing(50);
		layout->addLayout(bluetoothLayout);
		layout->addSpacing(50);
		layout->addLayout(wifiLayout);

		layout->addStretch();

		//Scroll Area and Container
		container->setLayout(layout);	
		scrollArea->setWidget(container);
		scrollArea->repaint();

		//Wrapper (So Somewhat Horizontal Centered)
		wrapper->addStretch();
		wrapper->addWidget(scrollArea);
		wrapper->addStretch();
		
		//
		this->setLayout(wrapper);
}
