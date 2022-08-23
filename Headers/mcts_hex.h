#pragma once

#include <QtWidgets/QWidget>
#include "ui_mcts_hex.h"

class MCTS_HEX : public QWidget
{
    Q_OBJECT

public:
    MCTS_HEX(QWidget *parent = nullptr);
    ~MCTS_HEX();

private:
    Ui::MCTS_HEXClass ui;
};
