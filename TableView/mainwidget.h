#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwidget.h"

class mainwidget : public QMainWindow
{
	Q_OBJECT

public:
	mainwidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::mainwidgetClass* ui;

	void adjustTableSize();

public slots:
	void dataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight)
	{
		adjustTableSize();
	}
	void updateSection(int logicalIndex, int, int newSize)
	{
		adjustTableSize();
	}

};
