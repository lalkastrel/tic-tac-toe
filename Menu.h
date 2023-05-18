#pragma once
#include "Widget.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QVBoxLayout>
#include "qpushbutton.h"
#include "qdebug.h"
class Menu : public QWidget
{
	Q_OBJECT
public:
	Menu(QWidget* parent = nullptr);
	~Menu();
private:
	QVBoxLayout* layout = new QVBoxLayout;
	QPushButton* pvp = new QPushButton;
	QPushButton* pve = new QPushButton;
	Widget game;
	Widget* game1 = new Widget(true, nullptr);
public slots:
	void pvpClick();
	void pveClick();

};
