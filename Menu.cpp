#include "Menu.h"
Menu::Menu(QWidget* parent) : QWidget(parent)
{
	game.setFixedSize(590, 590);
	game1->setFixedSize(590, 590);
	pvp->setText("player vs player");
	pve->setText("player vs enemy");
	layout->addWidget(pvp);
	layout->addWidget(pve);
	this->setLayout(layout);
	QObject::connect(pvp, SIGNAL(clicked()), this, SLOT(pvpClick()));
	QObject::connect(pve, SIGNAL(clicked()), this, SLOT(pveClick()));
}

Menu::~Menu()
{
}

void Menu::pvpClick() {
	qDebug() << "pvp started";
	game.pvpGameMode();
	game.show();
	this->hide();
	
}

void Menu::pveClick() {
	qDebug() << "pve started";
	game1->pveGameMode();
	game1->show();
	this->hide();
}