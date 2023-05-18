#pragma once

#include <QtWidgets/QWidget>
#include "Cell.h"
#include "qvector.h"
#include "qgridlayout.h"
#include <QVBoxLayout>
#include <ctime>
#include <random>
#include <QDialog>
#include <qlabel.h>
#include <qdebug.h>

class Widget : public QWidget
{
    Q_OBJECT
		
public:
    Widget(bool gamemode = 0, QWidget *parent = nullptr);
    ~Widget();
    void pvpGameMode();
    void pveGameMode();
private:
	
    bool gameMode = 0;
 // X = 0, O = 1
    QVBoxLayout* layout = new QVBoxLayout();
    QGridLayout* fieldLayout = new QGridLayout();
    bool isWin = 0;
    void winConditions(int XorO);
    bool isWinConditions(int XorO);
	QVector<Cell*> field;
public slots:
    void win();
    void aiTurn();
};
