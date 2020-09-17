/********************************************************************************
** Form generated from reading UI file 'panel.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANEL_H
#define UI_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MultirobotControlForm
{
public:
    QVBoxLayout *verticalLayout_4;
    QGroupBox *group_mode;
    QHBoxLayout *group_activation;
    QPushButton *button_on;
    QPushButton *button_reset;
    QPushButton *button_off;
    QGroupBox *group_mode1;
    QHBoxLayout *group_activation1;
    QLabel *label_id;
    QLineEdit *lineedit_spawn_id;
    QLabel *label_01;
    QLineEdit *lineedit_spawn_xpos;
    QLabel *label_02;
    QLineEdit *lineedit_spawn_ypos;
    QPushButton *button_spawn;
    QGroupBox *group_mode2;
    QHBoxLayout *group_activation2;
    QLabel *label_00;
    QLineEdit *lineedit_destroy_id;
    QPushButton *button_destroy;
    QGroupBox *group_mode3;
    QHBoxLayout *group_activation3;
    QLabel *label_03;
    QLineEdit *lineedit_goal_rbtID;
    QLabel *label_031;
    QLineEdit *lineedit_goal_xpos;
    QLabel *label_04;
    QLineEdit *lineedit_goal_ypos;
    QPushButton *button_setgoal;
    QGroupBox *group_mode4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *button_separate;
    QPushButton *button_align;
    QGroupBox *monitor;
    QFrame *group_status;
    QGridLayout *layout_status;
    QFrame *line_a;
    QFrame *line_b;
    QFrame *line_c;
    QFrame *line_s;
    QLabel *label_status_pos;
    QLabel *rbt1_pos_x;
    QLabel *rbt2_pos_x;
    QLabel *rbt3_pos_x;
    QLabel *rbt4_pos_x;
    QLabel *label_status_cur;
    QLabel *rbt1_pos_y;
    QLabel *rbt2_pos_y;
    QLabel *rbt3_pos_y;
    QLabel *rbt4_pos_y;
    QLabel *label_status_theta;
    QLabel *rbt1_heading;
    QLabel *rbt2_heading;
    QLabel *rbt3_heading;
    QLabel *rbt4_heading;
    QLabel *label;
    QLabel *label_fa;
    QLabel *label_fb;
    QLabel *label_fc;
    QLabel *label_s;

    void setupUi(QWidget *MultirobotControlForm)
    {
        if (MultirobotControlForm->objectName().isEmpty())
            MultirobotControlForm->setObjectName(QStringLiteral("MultirobotControlForm"));
        MultirobotControlForm->resize(400, 368);
        verticalLayout_4 = new QVBoxLayout(MultirobotControlForm);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        group_mode = new QGroupBox(MultirobotControlForm);
        group_mode->setObjectName(QStringLiteral("group_mode"));
        group_activation = new QHBoxLayout(group_mode);
        group_activation->setObjectName(QStringLiteral("group_activation"));
        button_on = new QPushButton(group_mode);
        button_on->setObjectName(QStringLiteral("button_on"));

        group_activation->addWidget(button_on);

        button_reset = new QPushButton(group_mode);
        button_reset->setObjectName(QStringLiteral("button_reset"));

        group_activation->addWidget(button_reset);

        button_off = new QPushButton(group_mode);
        button_off->setObjectName(QStringLiteral("button_off"));

        group_activation->addWidget(button_off);


        verticalLayout_4->addWidget(group_mode);

        group_mode1 = new QGroupBox(MultirobotControlForm);
        group_mode1->setObjectName(QStringLiteral("group_mode1"));
        group_activation1 = new QHBoxLayout(group_mode1);
        group_activation1->setObjectName(QStringLiteral("group_activation1"));
        label_id = new QLabel(group_mode1);
        label_id->setObjectName(QStringLiteral("label_id"));
        label_id->setStyleSheet(QLatin1String("QLabel {\n"
"                                font-weight: bold;\n"
"                                font-size: 14px;\n"
"                            }"));

        group_activation1->addWidget(label_id);

        lineedit_spawn_id = new QLineEdit(group_mode1);
        lineedit_spawn_id->setObjectName(QStringLiteral("lineedit_spawn_id"));

        group_activation1->addWidget(lineedit_spawn_id);

        label_01 = new QLabel(group_mode1);
        label_01->setObjectName(QStringLiteral("label_01"));
        label_01->setStyleSheet(QLatin1String("QLabel {\n"
"                                font-weight: bold;\n"
"                                font-size: 14px;\n"
"                            }"));

        group_activation1->addWidget(label_01);

        lineedit_spawn_xpos = new QLineEdit(group_mode1);
        lineedit_spawn_xpos->setObjectName(QStringLiteral("lineedit_spawn_xpos"));

        group_activation1->addWidget(lineedit_spawn_xpos);

        label_02 = new QLabel(group_mode1);
        label_02->setObjectName(QStringLiteral("label_02"));
        label_02->setStyleSheet(QLatin1String("QLabel {\n"
"                                font-weight: bold;\n"
"                                font-size: 14px;\n"
"                            }"));

        group_activation1->addWidget(label_02);

        lineedit_spawn_ypos = new QLineEdit(group_mode1);
        lineedit_spawn_ypos->setObjectName(QStringLiteral("lineedit_spawn_ypos"));

        group_activation1->addWidget(lineedit_spawn_ypos);

        button_spawn = new QPushButton(group_mode1);
        button_spawn->setObjectName(QStringLiteral("button_spawn"));

        group_activation1->addWidget(button_spawn);


        verticalLayout_4->addWidget(group_mode1);

        group_mode2 = new QGroupBox(MultirobotControlForm);
        group_mode2->setObjectName(QStringLiteral("group_mode2"));
        group_activation2 = new QHBoxLayout(group_mode2);
        group_activation2->setObjectName(QStringLiteral("group_activation2"));
        label_00 = new QLabel(group_mode2);
        label_00->setObjectName(QStringLiteral("label_00"));
        label_00->setStyleSheet(QLatin1String("QLabel {\n"
"                                font-weight: bold;\n"
"                                font-size: 14px;\n"
"                            }"));

        group_activation2->addWidget(label_00);

        lineedit_destroy_id = new QLineEdit(group_mode2);
        lineedit_destroy_id->setObjectName(QStringLiteral("lineedit_destroy_id"));

        group_activation2->addWidget(lineedit_destroy_id);

        button_destroy = new QPushButton(group_mode2);
        button_destroy->setObjectName(QStringLiteral("button_destroy"));

        group_activation2->addWidget(button_destroy);


        verticalLayout_4->addWidget(group_mode2);

        group_mode3 = new QGroupBox(MultirobotControlForm);
        group_mode3->setObjectName(QStringLiteral("group_mode3"));
        group_activation3 = new QHBoxLayout(group_mode3);
        group_activation3->setObjectName(QStringLiteral("group_activation3"));
        label_03 = new QLabel(group_mode3);
        label_03->setObjectName(QStringLiteral("label_03"));
        label_03->setStyleSheet(QLatin1String("QLabel {\n"
"                                font-weight: bold;\n"
"                                font-size: 14px;\n"
"                            }"));

        group_activation3->addWidget(label_03);

        lineedit_goal_rbtID = new QLineEdit(group_mode3);
        lineedit_goal_rbtID->setObjectName(QStringLiteral("lineedit_goal_rbtID"));

        group_activation3->addWidget(lineedit_goal_rbtID);

        label_031 = new QLabel(group_mode3);
        label_031->setObjectName(QStringLiteral("label_031"));
        label_031->setStyleSheet(QLatin1String("QLabel {\n"
"                                font-weight: bold;\n"
"                                font-size: 14px;\n"
"                            }"));

        group_activation3->addWidget(label_031);

        lineedit_goal_xpos = new QLineEdit(group_mode3);
        lineedit_goal_xpos->setObjectName(QStringLiteral("lineedit_goal_xpos"));

        group_activation3->addWidget(lineedit_goal_xpos);

        label_04 = new QLabel(group_mode3);
        label_04->setObjectName(QStringLiteral("label_04"));
        label_04->setStyleSheet(QLatin1String("QLabel {\n"
"                                font-weight: bold;\n"
"                                font-size: 14px;\n"
"                            }"));

        group_activation3->addWidget(label_04);

        lineedit_goal_ypos = new QLineEdit(group_mode3);
        lineedit_goal_ypos->setObjectName(QStringLiteral("lineedit_goal_ypos"));

        group_activation3->addWidget(lineedit_goal_ypos);

        button_setgoal = new QPushButton(group_mode3);
        button_setgoal->setObjectName(QStringLiteral("button_setgoal"));

        group_activation3->addWidget(button_setgoal);


        verticalLayout_4->addWidget(group_mode3);

        group_mode4 = new QGroupBox(MultirobotControlForm);
        group_mode4->setObjectName(QStringLiteral("group_mode4"));
        horizontalLayout_4 = new QHBoxLayout(group_mode4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        button_separate = new QPushButton(group_mode4);
        button_separate->setObjectName(QStringLiteral("button_separate"));

        horizontalLayout_4->addWidget(button_separate);

        button_align = new QPushButton(group_mode4);
        button_align->setObjectName(QStringLiteral("button_align"));

        horizontalLayout_4->addWidget(button_align);


        verticalLayout_4->addWidget(group_mode4);

        monitor = new QGroupBox(MultirobotControlForm);
        monitor->setObjectName(QStringLiteral("monitor"));

        verticalLayout_4->addWidget(monitor);

        group_status = new QFrame(MultirobotControlForm);
        group_status->setObjectName(QStringLiteral("group_status"));
        group_status->setFrameShape(QFrame::Panel);
        group_status->setFrameShadow(QFrame::Plain);
        layout_status = new QGridLayout(group_status);
        layout_status->setObjectName(QStringLiteral("layout_status"));
        line_a = new QFrame(group_status);
        line_a->setObjectName(QStringLiteral("line_a"));
        line_a->setFrameShape(QFrame::HLine);
        line_a->setFrameShadow(QFrame::Sunken);

        layout_status->addWidget(line_a, 1, 1, 1, 1);

        line_b = new QFrame(group_status);
        line_b->setObjectName(QStringLiteral("line_b"));
        line_b->setFrameShape(QFrame::HLine);
        line_b->setFrameShadow(QFrame::Sunken);

        layout_status->addWidget(line_b, 1, 2, 1, 1);

        line_c = new QFrame(group_status);
        line_c->setObjectName(QStringLiteral("line_c"));
        line_c->setFrameShape(QFrame::HLine);
        line_c->setFrameShadow(QFrame::Sunken);

        layout_status->addWidget(line_c, 1, 3, 1, 1);

        line_s = new QFrame(group_status);
        line_s->setObjectName(QStringLiteral("line_s"));
        line_s->setFrameShape(QFrame::HLine);
        line_s->setFrameShadow(QFrame::Sunken);

        layout_status->addWidget(line_s, 1, 4, 1, 1);

        label_status_pos = new QLabel(group_status);
        label_status_pos->setObjectName(QStringLiteral("label_status_pos"));

        layout_status->addWidget(label_status_pos, 2, 0, 1, 1);

        rbt1_pos_x = new QLabel(group_status);
        rbt1_pos_x->setObjectName(QStringLiteral("rbt1_pos_x"));
        rbt1_pos_x->setFrameShape(QFrame::StyledPanel);
        rbt1_pos_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layout_status->addWidget(rbt1_pos_x, 2, 1, 1, 1);

        rbt2_pos_x = new QLabel(group_status);
        rbt2_pos_x->setObjectName(QStringLiteral("rbt2_pos_x"));
        rbt2_pos_x->setFrameShape(QFrame::StyledPanel);
        rbt2_pos_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layout_status->addWidget(rbt2_pos_x, 2, 2, 1, 1);

        rbt3_pos_x = new QLabel(group_status);
        rbt3_pos_x->setObjectName(QStringLiteral("rbt3_pos_x"));
        rbt3_pos_x->setFrameShape(QFrame::StyledPanel);
        rbt3_pos_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layout_status->addWidget(rbt3_pos_x, 2, 3, 1, 1);

        rbt4_pos_x = new QLabel(group_status);
        rbt4_pos_x->setObjectName(QStringLiteral("rbt4_pos_x"));
        rbt4_pos_x->setFrameShape(QFrame::StyledPanel);
        rbt4_pos_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layout_status->addWidget(rbt4_pos_x, 2, 4, 1, 1);

        label_status_cur = new QLabel(group_status);
        label_status_cur->setObjectName(QStringLiteral("label_status_cur"));

        layout_status->addWidget(label_status_cur, 3, 0, 1, 1);

        rbt1_pos_y = new QLabel(group_status);
        rbt1_pos_y->setObjectName(QStringLiteral("rbt1_pos_y"));
        rbt1_pos_y->setFrameShape(QFrame::StyledPanel);
        rbt1_pos_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layout_status->addWidget(rbt1_pos_y, 3, 1, 1, 1);

        rbt2_pos_y = new QLabel(group_status);
        rbt2_pos_y->setObjectName(QStringLiteral("rbt2_pos_y"));
        rbt2_pos_y->setFrameShape(QFrame::StyledPanel);
        rbt2_pos_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layout_status->addWidget(rbt2_pos_y, 3, 2, 1, 1);

        rbt3_pos_y = new QLabel(group_status);
        rbt3_pos_y->setObjectName(QStringLiteral("rbt3_pos_y"));
        rbt3_pos_y->setFrameShape(QFrame::StyledPanel);
        rbt3_pos_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layout_status->addWidget(rbt3_pos_y, 3, 3, 1, 1);

        rbt4_pos_y = new QLabel(group_status);
        rbt4_pos_y->setObjectName(QStringLiteral("rbt4_pos_y"));
        rbt4_pos_y->setFrameShape(QFrame::StyledPanel);
        rbt4_pos_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layout_status->addWidget(rbt4_pos_y, 3, 4, 1, 1);

        label_status_theta = new QLabel(group_status);
        label_status_theta->setObjectName(QStringLiteral("label_status_theta"));

        layout_status->addWidget(label_status_theta, 4, 0, 1, 1);

        rbt1_heading = new QLabel(group_status);
        rbt1_heading->setObjectName(QStringLiteral("rbt1_heading"));
        rbt1_heading->setFrameShape(QFrame::StyledPanel);
        rbt1_heading->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layout_status->addWidget(rbt1_heading, 4, 1, 1, 1);

        rbt2_heading = new QLabel(group_status);
        rbt2_heading->setObjectName(QStringLiteral("rbt2_heading"));
        rbt2_heading->setFrameShape(QFrame::StyledPanel);
        rbt2_heading->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layout_status->addWidget(rbt2_heading, 4, 2, 1, 1);

        rbt3_heading = new QLabel(group_status);
        rbt3_heading->setObjectName(QStringLiteral("rbt3_heading"));
        rbt3_heading->setFrameShape(QFrame::StyledPanel);
        rbt3_heading->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layout_status->addWidget(rbt3_heading, 4, 3, 1, 1);

        rbt4_heading = new QLabel(group_status);
        rbt4_heading->setObjectName(QStringLiteral("rbt4_heading"));
        rbt4_heading->setFrameShape(QFrame::StyledPanel);
        rbt4_heading->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layout_status->addWidget(rbt4_heading, 4, 4, 1, 1);

        label = new QLabel(group_status);
        label->setObjectName(QStringLiteral("label"));

        layout_status->addWidget(label, 0, 0, 1, 1);

        label_fa = new QLabel(group_status);
        label_fa->setObjectName(QStringLiteral("label_fa"));
        label_fa->setAlignment(Qt::AlignCenter);

        layout_status->addWidget(label_fa, 0, 1, 1, 1);

        label_fb = new QLabel(group_status);
        label_fb->setObjectName(QStringLiteral("label_fb"));
        label_fb->setAlignment(Qt::AlignCenter);

        layout_status->addWidget(label_fb, 0, 2, 1, 1);

        label_fc = new QLabel(group_status);
        label_fc->setObjectName(QStringLiteral("label_fc"));
        label_fc->setAlignment(Qt::AlignCenter);

        layout_status->addWidget(label_fc, 0, 3, 1, 1);

        label_s = new QLabel(group_status);
        label_s->setObjectName(QStringLiteral("label_s"));
        label_s->setAlignment(Qt::AlignCenter);

        layout_status->addWidget(label_s, 0, 4, 1, 1);


        verticalLayout_4->addWidget(group_status);


        retranslateUi(MultirobotControlForm);

        QMetaObject::connectSlotsByName(MultirobotControlForm);
    } // setupUi

    void retranslateUi(QWidget *MultirobotControlForm)
    {
        MultirobotControlForm->setWindowTitle(QApplication::translate("MultirobotControlForm", "Form", 0));
        group_mode->setTitle(QApplication::translate("MultirobotControlForm", "Multirobot Main Control", 0));
        button_on->setText(QApplication::translate("MultirobotControlForm", "START", 0));
        button_reset->setText(QApplication::translate("MultirobotControlForm", "RESET", 0));
        button_off->setText(QApplication::translate("MultirobotControlForm", "STOP", 0));
        group_mode1->setTitle(QApplication::translate("MultirobotControlForm", "Robot Spawning", 0));
        label_id->setText(QApplication::translate("MultirobotControlForm", "ID:", 0));
        lineedit_spawn_id->setStyleSheet(QApplication::translate("MultirobotControlForm", "color: black;\n"
"                            border: 1px solid black;\n"
"                            background: white;\n"
"                            selection-background-color: lightgray;", 0));
        label_01->setText(QApplication::translate("MultirobotControlForm", "pos_x:", 0));
        lineedit_spawn_xpos->setStyleSheet(QApplication::translate("MultirobotControlForm", "color: black;\n"
"                            border: 1px solid black;\n"
"                            background: white;\n"
"                            selection-background-color: lightgray;", 0));
        label_02->setText(QApplication::translate("MultirobotControlForm", "pos_y:", 0));
        lineedit_spawn_ypos->setStyleSheet(QApplication::translate("MultirobotControlForm", "color: black;\n"
"                            border: 1px solid black;\n"
"                            background: white;\n"
"                            selection-background-color: lightgray;", 0));
        button_spawn->setText(QApplication::translate("MultirobotControlForm", "Spawn Robot", 0));
        group_mode2->setTitle(QApplication::translate("MultirobotControlForm", "Robot Removing", 0));
        label_00->setText(QApplication::translate("MultirobotControlForm", "Robot ID:", 0));
        lineedit_destroy_id->setStyleSheet(QApplication::translate("MultirobotControlForm", "color: black;\n"
"                            border: 1px solid black;\n"
"                            background: white;\n"
"                            selection-background-color: lightgray;", 0));
        button_destroy->setText(QApplication::translate("MultirobotControlForm", "Remove Robot", 0));
        group_mode3->setTitle(QApplication::translate("MultirobotControlForm", "System destination position", 0));
        label_03->setText(QApplication::translate("MultirobotControlForm", "robot ID:", 0));
        lineedit_goal_rbtID->setStyleSheet(QApplication::translate("MultirobotControlForm", "color: black;\n"
"                            border: 1px solid black;\n"
"                            background: white;\n"
"                            selection-background-color: lightgray;", 0));
        label_031->setText(QApplication::translate("MultirobotControlForm", "pos_x:", 0));
        lineedit_goal_xpos->setStyleSheet(QApplication::translate("MultirobotControlForm", "color: black;\n"
"                            border: 1px solid black;\n"
"                            background: white;\n"
"                            selection-background-color: lightgray;", 0));
        label_04->setText(QApplication::translate("MultirobotControlForm", "pos_y:", 0));
        lineedit_goal_ypos->setStyleSheet(QApplication::translate("MultirobotControlForm", "color: black;\n"
"                            border: 1px solid black;\n"
"                            background: white;\n"
"                            selection-background-color: lightgray;", 0));
        button_setgoal->setText(QApplication::translate("MultirobotControlForm", "Navigate", 0));
        group_mode4->setTitle(QApplication::translate("MultirobotControlForm", "System Cofigurations", 0));
        button_separate->setText(QApplication::translate("MultirobotControlForm", "Separated", 0));
        button_align->setText(QApplication::translate("MultirobotControlForm", "Aligned", 0));
        monitor->setTitle(QApplication::translate("MultirobotControlForm", "Robot Monitor", 0));
        label_status_pos->setText(QApplication::translate("MultirobotControlForm", "Position x (m)", 0));
        rbt1_pos_x->setText(QApplication::translate("MultirobotControlForm", "--", 0));
        rbt2_pos_x->setText(QApplication::translate("MultirobotControlForm", "--", 0));
        rbt3_pos_x->setText(QApplication::translate("MultirobotControlForm", "--", 0));
        rbt4_pos_x->setText(QApplication::translate("MultirobotControlForm", "--", 0));
        label_status_cur->setText(QApplication::translate("MultirobotControlForm", "Position y (m)", 0));
        rbt1_pos_y->setText(QApplication::translate("MultirobotControlForm", "--", 0));
        rbt2_pos_y->setText(QApplication::translate("MultirobotControlForm", "--", 0));
        rbt3_pos_y->setText(QApplication::translate("MultirobotControlForm", "--", 0));
        rbt4_pos_y->setText(QApplication::translate("MultirobotControlForm", "--", 0));
        label_status_theta->setText(QApplication::translate("MultirobotControlForm", "Heading (deg)", 0));
        rbt1_heading->setText(QApplication::translate("MultirobotControlForm", "--", 0));
        rbt2_heading->setText(QApplication::translate("MultirobotControlForm", "--", 0));
        rbt3_heading->setText(QApplication::translate("MultirobotControlForm", "--", 0));
        rbt4_heading->setText(QApplication::translate("MultirobotControlForm", "--", 0));
        label->setText(QApplication::translate("MultirobotControlForm", "Robot ID", 0));
        label_fa->setText(QApplication::translate("MultirobotControlForm", "burger_1", 0));
        label_fb->setText(QApplication::translate("MultirobotControlForm", "burger_2", 0));
        label_fc->setText(QApplication::translate("MultirobotControlForm", "burger_3", 0));
        label_s->setText(QApplication::translate("MultirobotControlForm", "burger_4", 0));
    } // retranslateUi

};

namespace Ui {
    class MultirobotControlForm: public Ui_MultirobotControlForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANEL_H
