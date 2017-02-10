#ifndef INFOCONTENT_H
#define INFOCONTENT_H

#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QScrollArea>
#include <QScroller>
#include <QFrame>
#include <QLabel>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <QHBoxLayout>
#include <string>
#include <sys/types.h>
#include <ifaddrs.h>


namespace Ui {
	class InfoContent;
}

class InfoContent : public QWidget {
	Q_OBJECT
		//Container Pieces
		QVBoxLayout *layout;
		QHBoxLayout *wrapper;
		QWidget *container;
		QScroller *scroller;
		QScrollArea *scrollArea;
		
		//Base Sections
		QVBoxLayout *mainLayout, *musicLayout, *gpsLayout, *soundboardLayout;
		
		//Main Section
		QHBoxLayout *hostnameLayout;
		char hostname[HOST_NAME_MAX];
		QLabel *hostnameLabel, *hostnameData;

		QHBoxLayout *ipLayout;
		QLabel *ipLabel, *ipData;

	
	public:
		explicit InfoContent(QWidget *parent = 0);
		QFrame* createSeparator(QWidget *parent = 0);
};
#endif //INFOCONTENT_H
