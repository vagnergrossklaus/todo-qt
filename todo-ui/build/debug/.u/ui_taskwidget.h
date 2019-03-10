/********************************************************************************
** Form generated from reading UI file 'taskwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKWIDGET_H
#define UI_TASKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QCheckBox *cbxName;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbtEdit;
    QPushButton *pbtRemove;

    void setupUi(QWidget *TaskWidget)
    {
        if (TaskWidget->objectName().isEmpty())
            TaskWidget->setObjectName(QStringLiteral("TaskWidget"));
        TaskWidget->resize(293, 45);
        horizontalLayout = new QHBoxLayout(TaskWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cbxName = new QCheckBox(TaskWidget);
        cbxName->setObjectName(QStringLiteral("cbxName"));

        horizontalLayout->addWidget(cbxName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pbtEdit = new QPushButton(TaskWidget);
        pbtEdit->setObjectName(QStringLiteral("pbtEdit"));

        horizontalLayout->addWidget(pbtEdit);

        pbtRemove = new QPushButton(TaskWidget);
        pbtRemove->setObjectName(QStringLiteral("pbtRemove"));

        horizontalLayout->addWidget(pbtRemove);


        retranslateUi(TaskWidget);

        QMetaObject::connectSlotsByName(TaskWidget);
    } // setupUi

    void retranslateUi(QWidget *TaskWidget)
    {
        TaskWidget->setWindowTitle(QApplication::translate("TaskWidget", "Form", nullptr));
        cbxName->setText(QApplication::translate("TaskWidget", "Task", nullptr));
        pbtEdit->setText(QApplication::translate("TaskWidget", "Edit", nullptr));
        pbtRemove->setText(QApplication::translate("TaskWidget", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskWidget: public Ui_TaskWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKWIDGET_H
