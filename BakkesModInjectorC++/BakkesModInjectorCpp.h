#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BakkesModInjectorCpp.h"
#include "WindowsUtils.h"
#include "DllInjector.h"
#include "qtimer.h"
#include "BakkesModInstallation.h"
#include "SettingsManager.h"
#include "Updater.h"
enum BakkesModStatus
{
	BOOTING = 0,
	BAKKESMOD_IDLE = 1, //NO RL RUNNING
	WAITING_FOR_RL = 2,
	OUT_OF_DATE = 3,
	OUT_OF_DATE_SAFEMODE_DISABLED = 4,
	CHECKING_FOR_UPDATES = 5,
	START_UPDATING = 6,
	UPDATING_BAKKESMOD = 7,
	UPDATING_INJECTOR = 8
	
};

class BakkesModInjectorCpp : public QMainWindow
{
	Q_OBJECT
private:
	BakkesModStatus bakkesModState = BOOTING;
	BakkesModInstallation installation;
	Updater updater;
	RegisterySettingsManager settingsManager;
	WindowsUtils windowsUtils;
	DllInjector dllInjector;
	QTimer timer;
public:
	BakkesModInjectorCpp(QWidget *parent = Q_NULLPTR);
	void initialize();
public slots:
	void OnOpenBakkesModFolderClicked();
	void OnCheckInjection();
	void TimerTimeout();
private:
	Ui::BakkesModInjectorCppClass ui;
};
