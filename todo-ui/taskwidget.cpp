#include "taskwidget.h"
#include "ui_taskwidget.h"

#include <QDebug>
#include <QInputDialog>

TaskWidget::TaskWidget(TaskModel *task, QWidget *parent)
    : QWidget(parent), ui(new Ui::TaskWidget), _task(task) {

  ui->setupUi(this);

  ui->cbxName->setText(task->name());
  ui->cbxName->setCheckState(Qt::CheckState(task->status()));
  strikeOut(ui->cbxName->checkState());

  connect(ui->cbxName, &QCheckBox::stateChanged, this,
          &TaskWidget::onStateChanged);
  connect(ui->pbtEdit, &QPushButton::clicked, this, &TaskWidget::onEditClicked);
  connect(ui->pbtRemove, &QPushButton::clicked, this,
          &TaskWidget::onRemoveClicked);
}

TaskWidget::~TaskWidget() { delete ui; }

TaskModel *TaskWidget::task() const { return _task; }

void TaskWidget::strikeOut(Qt::CheckState state) {
  QFont font = ui->cbxName->font();
  font.setStrikeOut(state == Qt::CheckState::Checked);
  ui->cbxName->setFont(font);
}

void TaskWidget::onStateChanged(int state) {
  strikeOut(Qt::CheckState(state));
  _task->setStatus(state);
  emit edited(this);
}

void TaskWidget::onEditClicked() {
  QString name =
      QInputDialog::getText(this, "Edit task", "Name", QLineEdit::Normal, "");

  qDebug() << name;

  if (!name.isEmpty()) {
    ui->cbxName->setText(name);
    _task->setName(name);
  }

  emit edited(this);
}

void TaskWidget::onRemoveClicked() {
  this->setParent(nullptr);
  emit removed(this);
}
