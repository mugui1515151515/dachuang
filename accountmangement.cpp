#include "accountmangement.h"
#include "ui_accountmangement.h"
#include <QSqlTableModel>

AccountMangement::AccountMangement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountMangement),
    mNewOrder(nullptr),
    mOrderAndAccount(nullptr)
{
    ui->setupUi(this);
    orderModel = nullptr;
    newOrderButton = ui->newOrderButton;
    orderHistoryButton = ui->orderHistoryButton;
    basicInformationButton = ui->basicInformationButton;
    changePasswordButton = ui->changePasswordButton;
}

AccountMangement::~AccountMangement()
{
    delete ui;
}

void AccountMangement::initPage()
{
    // 初始化界面
    mNewOrder = new NewOrder(this);
    mOrderAndAccount = new OrderAndAccount(this);

    // 添加界面
    ui->stackedWidget->addWidget(mNewOrder);
    ui->stackedWidget->addWidget(mOrderAndAccount);

    // 设定初始界面
    ui->stackedWidget->setCurrentWidget(mNewOrder);
}

void AccountMangement::on_newOrderButton_clicked()
{
    // 确保新订单界面已经被添加到stackedWidget中
    if (!mNewOrder) {
        mNewOrder = new NewOrder(this);
        ui->stackedWidget->addWidget(mNewOrder);
    }

    // 将堆栈窗口的当前页面设置为新订单页面
    ui->stackedWidget->setCurrentWidget(mNewOrder);
}


void AccountMangement::on_orderHistoryButton_clicked()
{
    if (!orderModel) {
        orderModel = new QSqlTableModel(this);
        orderModel->setTable("orders_table"); // 假设数据库中存储订单的表名为orders
        orderModel->select();
    }

    ui->orderHistoryView->setModel(orderModel);
    ui->orderHistoryView->resizeColumnsToContents(); // 根据内容调整列宽
    ui->stackedWidget->setCurrentWidget(ui->history_order_page); // 切换到显示历史订单的页面
}

