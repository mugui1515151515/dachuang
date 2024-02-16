#ifndef ACCOUNTMANGEMENT_H
#define ACCOUNTMANGEMENT_H

#include <QWidget>
#include "neworder.h"
#include "orderandaccount.h"
#include <QPushButton>

namespace Ui {
class AccountMangement;
}

class AccountMangement : public QWidget
{
    Q_OBJECT

public:
    explicit AccountMangement(QWidget *parent = nullptr);
    ~AccountMangement();
    void initPage();

private slots:
    void on_newOrderButton_clicked();

    void on_orderHistoryButton_clicked();

private:
    QSqlTableModel* orderModel;
    Ui::AccountMangement *ui;
    NewOrder *mNewOrder;
    OrderAndAccount *mOrderAndAccount;
    QPushButton *newOrderButton;
    QPushButton *orderHistoryButton;
    QPushButton *basicInformationButton;
    QPushButton *changePasswordButton;

};

#endif // ACCOUNTMANGEMENT_H
