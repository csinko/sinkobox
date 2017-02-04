#ifndef MAINCONTENT_H
#define MAINCONTENT_H

#include <QGridLayout>
#include <QWidget>
#include <QPushButton>
#include "mainwindow.h"
namespace Ui {
	class MainContent;
}

class MainContent : public QWidget {
	Q_OBJECT
	QGridLayout *layout;
	public:
		explicit MainContent(QWidget *parent);
	private slots:
		void handleMusic();
	private:
		QPushButton *button1, *button2, *button3, *button4, *button5, *button6, *button7, *button8, *button9;
};

#endif // MAINCONTENT_H
