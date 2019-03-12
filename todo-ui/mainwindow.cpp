#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QInputDialog>
#include <controller/tasklocalcontroller.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      _taskcontroller(new TaskLocalController()) {

  ui->setupUi(this);

  QObject::connect(ui->pbtAdd, &QPushButton::clicked, this,
                   &MainWindow::onAddClicked);

  ui->cbxDoneUndone->setCheckState(Qt::CheckState::Checked);
  for (auto task : _taskcontroller->find()) {
    if (task->status() == TaskStatus::TODO) {
      ui->cbxDoneUndone->setCheckState(Qt::CheckState::Unchecked);
    }
    addTask(task);
  }

  QObject::connect(ui->cbxDoneUndone, &QCheckBox::stateChanged, this,
                   &MainWindow::onDoneUndoneStateChanged);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::addTask(TaskModel *task) {
  TaskWidget *widget = new TaskWidget(task);
  connect(widget, &TaskWidget::edited, this, &MainWindow::onEdited);
  connect(widget, &TaskWidget::removed, this, &MainWindow::onRemoved);
  ui->vblTasks->addWidget(widget);
}

void MainWindow::onAddClicked() {
  QString name =
      QInputDialog::getText(this, "Add task", "Name", QLineEdit::Normal, "");

  qDebug() << name;

  if (!name.isEmpty()) {
    TaskModel *task = new TaskModel(name);
    _taskcontroller->add(task);
    addTask(task);
  }
}

void MainWindow::onDoneUndoneStateChanged(int state) {
  QVector<TaskModel *> tasks = {};
  QList<TaskWidget *> widgets = this->findChildren<TaskWidget *>();
  for (auto widget : widgets) {
    widget->task()->setStatus(TaskStatus(state));
    tasks.append(widget->task());
  }
  _taskcontroller->edit(tasks);
}

void MainWindow::onEdited(TaskWidget *widget) {
  _taskcontroller->edit(widget->task());
}

void MainWindow::onRemoved(TaskWidget *widget) {
  _taskcontroller->remove(widget->task()->id());
  ui->vblTasks->removeWidget(widget);
}
