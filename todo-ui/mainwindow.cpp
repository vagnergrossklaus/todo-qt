#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QInputDialog>
#include <controller/tasklocalcontroller.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      _taskcontroller(TaskLocalController()) {

  ui->setupUi(this);

  QObject::connect(ui->pbtAdd, &QPushButton::clicked, this,
                   &MainWindow::onAddClicked);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::onAddClicked() {
  QString name =
      QInputDialog::getText(this, "Add task", "Name", QLineEdit::Normal, "");

  qDebug() << name;

  if (!name.isEmpty()) {
    TaskModel *task = new TaskModel(name);
    _taskcontroller.add(task);

    TaskWidget *widget = new TaskWidget(task);
    connect(widget, &TaskWidget::removed, this, &MainWindow::onRemoved);
    ui->vblTasks->addWidget(widget);
  }
}

void MainWindow::onRemoved(TaskWidget *widget) {
  ui->vblTasks->removeWidget(widget);
}
