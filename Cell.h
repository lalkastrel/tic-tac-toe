#pragma once
#include "qpushbutton.h"
//#include "Widget.h"
static int turn = 0;

class Cell : public QPushButton
{
	Q_OBJECT
public:
	Cell() : QPushButton(), value(0) {
		this->setFixedSize(180, 180);
	} 
	void setValue(char newValue) 
	{
		value = newValue;
	};
	char getValue() {
		return value;
	}
	void setX() {
		this->setText("X");
		value = 1;
	};
	void setO() {
		this->setText("O");
		value = 2;
	};
private:
	char value; // X = 1, O = 2
public slots:
	void pvpRound() {
		if (value>0) {
			return;
		}
		if (turn % 2 == 0) {
			setX();
		}
		if (turn % 2 == 1) {
			setO();
		}
		turn++;
	}

	void pveRound() {
		if (value>0) {
			return;
		}
		setX();
		turn++;
		turn++;
	}
};

