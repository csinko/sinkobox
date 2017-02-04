#ifndef SETTINGSCONTENT_H
#define SETTINGSCONTENT_H

#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QScrollArea>
#include <QScroller>
#include <QRadioButton>
namespace Ui {
	class SettingsContent;
}

class SettingsContent : public QWidget {
	Q_OBJECT
		QVBoxLayout *layout;
		QHBoxLayout *wrapper;
		QWidget *container;
		QScroller *scroller;
		QPushButton *moveMusicButton;
		QScrollArea *scrollArea;
		QVBoxLayout *bluetoothLayout;
		QHBoxLayout *bluetoothEnabler;
		QRadioButton *bluetoothEnableButton;
		QRadioButton *bluetoothDisableButton;
		QVBoxLayout *wifiLayout;
		QHBoxLayout *wifiEnabler;
		QRadioButton *wifiAPButton;
		QRadioButton *wifiClientButton;

	public:
		explicit SettingsContent(QWidget *parent = 0);
	private:
};

#endif //SETTINGSCONTENT_H
