#include "infocontent.h"

InfoContent::InfoContent(QWidget *parent)
	: QWidget(parent) {
	
		//Instaniate Controller
		wrapper = new QHBoxLayout();
		scrollArea = new QScrollArea();
		container = new QWidget();
		layout = new QVBoxLayout();
		
		//Scrolling Settings	
		scroller = QScroller::scroller(scrollArea->viewport());
		QScrollerProperties properties = QScroller::scroller(scroller)->scrollerProperties();
		QVariant overshootPolicy = QVariant::fromValue<QScrollerProperties::OvershootPolicy>(QScrollerProperties::OvershootAlwaysOff);
		properties.setScrollMetric(QScrollerProperties::VerticalOvershootPolicy, overshootPolicy);
		scroller->setScrollerProperties(properties);
		scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		scroller->grabGesture(scrollArea->viewport(), QScroller::LeftMouseButtonGesture);

		//BEGIN Main Section
		mainLayout = new QVBoxLayout();
		mainLayout->addWidget(new QLabel("Main"));
		mainLayout->addWidget(createSeparator());

		//Hostname
		hostnameLayout = new QHBoxLayout();	
		gethostname(hostname, HOST_NAME_MAX);
		hostnameLabel = new QLabel("Hostname: ");

		hostnameLabel->setObjectName("detail");
		hostnameData = new QLabel(hostname);
		hostnameData->setObjectName("detail");

		hostnameLayout->addWidget(hostnameLabel);
		hostnameLayout->addWidget(hostnameData);
		mainLayout->addLayout(hostnameLayout);

		
		//IP
		ipLayout = new QHBoxLayout();
		printf(getifaddrs());
		printf("\n Done \n");



		//Music Info
		musicLayout = new QVBoxLayout();
		musicLayout->addWidget(new QLabel("Music"));
		musicLayout->addWidget(createSeparator());

		//GPS Info
		gpsLayout = new QVBoxLayout();
		gpsLayout->addWidget(new QLabel("GPS"));
		gpsLayout->addWidget(createSeparator());

		//Soundboard Layout
		soundboardLayout = new QVBoxLayout();
		soundboardLayout->addWidget(new QLabel("Soundboard"));
		soundboardLayout->addWidget(createSeparator());

		//Add Layouts to Main Layout
		layout->addLayout(mainLayout);
		layout->addSpacing(50);
		layout->addLayout(musicLayout);
		layout->addSpacing(50);
		layout->addLayout(gpsLayout);
		layout->addSpacing(50);
		layout->addLayout(soundboardLayout);

		layout->addStretch();

		//Scroll Area and Container
		container->setLayout(layout);
		scrollArea->setWidget(container);
		scrollArea->repaint();

		//Wrapper (So Somewhat Horizontal Centered)
		wrapper->addStretch();
		wrapper->addWidget(scrollArea);
		wrapper->addStretch();

		this->setLayout(wrapper);
	}


QFrame* InfoContent::createSeparator(QWidget* parent) {
	QFrame *separatorLine = new QFrame(parent);
	separatorLine->setObjectName(QString::fromUtf8("line"));
	separatorLine->setGeometry(QRect(320, 150, 118, 3));
	separatorLine->setFrameShape(QFrame::HLine);
	separatorLine->setFrameShadow(QFrame::Sunken);
	return separatorLine;
}
