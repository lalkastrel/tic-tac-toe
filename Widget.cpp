#include "Widget.h"

Widget::Widget(bool gamemode, QWidget *parent)
    : QWidget(parent)//, gameMode(gamemode)
{
    gameMode = gamemode;
    fieldLayout->setSpacing(10);
    for (size_t i = 0; i < 9; i++) {
        Cell* temp = new Cell();
        field.push_back(temp);
    }
    int forField = 0;
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            fieldLayout->addWidget(field[forField], i, j);
            forField++;
        }
    }
    layout->addLayout(fieldLayout);
    this->setLayout(layout);
    if (gameMode == 0) {
        qDebug() << "pvp connect";
        if ( isWin == 0) {
            for (size_t i = 0; i < 9; i++) {
               QObject::connect(field[i], SIGNAL(released()), field[i], SLOT(pvpRound()));
               QObject::connect(field[i], SIGNAL(clicked()), this, SLOT(win()));
            }   
           
        }
        
    }
    if (gameMode == 1) {
        qDebug() << "pve connect";
        for (size_t i = 0; i < 9; i++) {
            QObject::connect(field[i], SIGNAL(pressed()), field[i], SLOT(pveRound()));
            QObject::connect(field[i], SIGNAL(clicked()), this, SLOT(aiTurn()));
           // QObject::connect(field[i], SIGNAL(clicked()), this, SLOT(win()));
        }

    }

    
}

Widget::~Widget()
{}

void Widget::pvpGameMode()
{
    gameMode = 0;
}

void Widget::pveGameMode()
{
    gameMode = 1;
}

void Widget::winConditions(int XorO) {
    if (isWinConditions(XorO)) {
        isWin = 1;
        QVBoxLayout* forWin = new QVBoxLayout;
        QLabel* label = new QLabel;
        if (XorO == 1) {
            label->setText("X wins");
        }
        if (XorO == 2) {
            label->setText("O wins");
        }
        forWin->addWidget(label);
        QDialog* winner = new QDialog;
        winner->setLayout(forWin);
        winner->setVisible(true);
    }
}

bool Widget::isWinConditions(int XorO)
{
    if (field[0]->getValue() == field[1]->getValue() && field[1]->getValue() == field[2]->getValue() && field[2]->getValue() == XorO ||
        field[3]->getValue() == field[4]->getValue() && field[4]->getValue() == field[5]->getValue() && field[5]->getValue() == XorO ||
        field[6]->getValue() == field[7]->getValue() && field[7]->getValue() == field[8]->getValue() && field[8]->getValue() == XorO ||
        field[0]->getValue() == field[3]->getValue() && field[3]->getValue() == field[6]->getValue() && field[6]->getValue() == XorO ||
        field[1]->getValue() == field[4]->getValue() && field[4]->getValue() == field[7]->getValue() && field[7]->getValue() == XorO ||
        field[2]->getValue() == field[5]->getValue() && field[5]->getValue() == field[8]->getValue() && field[8]->getValue() == XorO ||
        field[0]->getValue() == field[4]->getValue() && field[4]->getValue() == field[8]->getValue() && field[8]->getValue() == XorO ||
        field[2]->getValue() == field[4]->getValue() && field[4]->getValue() == field[6]->getValue() && field[6]->getValue() == XorO) {
        return true;
    }
    return false;
}

void Widget::win()
{
    winConditions(1);
    winConditions(2);
    if (isWin == 1) {
        for (size_t i = 0; i < 9; i++)
        {
            QObject::disconnect(field[i], nullptr, nullptr, nullptr);
        }
    }
}

void Widget::aiTurn() {
    win(); 
    if (isWin == 1) {
        return;
    }
    Cell* obj = qobject_cast<Cell*>(sender());
    QObject::disconnect(obj, nullptr, nullptr, nullptr);
    srand(time(NULL));
    for (size_t i = 0; i < 9; i++) {
        if (field[i]->getValue() == 0) {
            field[i]->setValue(2);
            if (isWinConditions(2)) {
                field[i]->setO();
                winConditions(2);
                return;
            }
            field[i]->setValue(0);
        }
    }
    for (size_t i = 0; i < 9; i++) {
        if (field[i]->getValue() == 0) {
            field[i]->setValue(1);
            if (isWinConditions(1)) {
                field[i]->setO();
                win();
                return;
            }
            field[i]->setValue(0);
        }
    }
    int i = 0;
          while (i < 20) {
                Cell* temp = field[rand() % 8];
                i++;
                if (temp->getValue() == 0) {
                    temp->setO();
                    win();
                    return;
                }
          }
   
}
