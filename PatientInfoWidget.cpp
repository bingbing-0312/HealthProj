#include "PatientInfoWidget.h"

PatientInfoWidget::PatientInfoWidget(QWidget *parent) : QWidget(parent)
{
    this->resize(200,200);
    this->setStyleSheet("background-color: rgb(0, 0, 0)");
//布局
    pwholeLayout->addWidget(ptopWidget);
    pwholeLayout->addWidget(pmiddle1Widget);
    pwholeLayout->addWidget(pmiddle2Widget);
    pwholeLayout->addWidget(pIDnumberWidget);
    pwholeLayout->addWidget(pbottomWidget);

    ptopLayout->addWidget(name,0,Qt::AlignRight|Qt::AlignCenter);
    ptopLayout->addWidget(nameLineEdit,0,Qt::AlignLeft|Qt::AlignCenter);
    ptopWidget->setLayout(ptopLayout);

    pmiddle1Layout->addWidget(sex,0,Qt::AlignRight|Qt::AlignCenter);
    pmiddle1Layout->addWidget(sexLineEdit,0,Qt::AlignLeft|Qt::AlignCenter);
    pmiddle1Widget->setLayout(pmiddle1Layout);

    pmiddle2Layout->addWidget(age,0,Qt::AlignRight|Qt::AlignCenter);
    pmiddle2Layout->addWidget(ageLineEdit,0,Qt::AlignLeft|Qt::AlignCenter);
    pmiddle2Widget->setLayout(pmiddle2Layout);

    pIDnumberLayout->addWidget(IDnumber,0,Qt::AlignRight|Qt::AlignCenter);
    pIDnumberLayout->addWidget(IDnumberLineEdit,0,Qt::AlignLeft|Qt::AlignCenter);
    pIDnumberWidget->setLayout(pIDnumberLayout);

    pbottomLayout->addWidget(update,0,Qt::AlignRight|Qt::AlignCenter);
    pbottomLayout->addWidget(save,0,Qt::AlignCenter);
    pbottomLayout->addWidget(alter,0,Qt::AlignLeft|Qt::AlignCenter);
    pbottomWidget->setLayout(pbottomLayout);

    this->setLayout(pwholeLayout);
//样式
    name->setStyleSheet("color: rgb(0, 255, 255);background-color: rgb(0, 0, 0)");
    sex->setStyleSheet("color: rgb(0, 255, 255);background-color: rgb(0, 0, 0)");
    age->setStyleSheet("color: rgb(0, 255, 255);background-color: rgb(0, 0, 0)");
    IDnumber->setStyleSheet("color: rgb(0, 255, 255);background-color: rgb(0, 0, 0)");
    update->setStyleSheet("color: rgb(0, 255, 255);background-color: rgb(0, 0, 0)");
    alter->setStyleSheet("color: rgb(0, 255, 255);background-color: rgb(0, 0, 0)");
    save->setStyleSheet("color: rgb(0, 255, 255);background-color: rgb(255, 85, 0)");
    nameLineEdit->setStyleSheet("color: rgb(0, 255, 255);background-color: rgb(0, 0, 0)");
    sexLineEdit->setStyleSheet("color: rgb(0, 255, 255);background-color: rgb(0, 0, 0)");
    ageLineEdit->setStyleSheet("color: rgb(0, 255, 255);background-color: rgb(0, 0, 0)");
    IDnumberLineEdit->setStyleSheet("color: rgb(0, 255, 255);background-color: rgb(0, 0, 0)");
//内容
    name->setText("姓名");
    sex->setText("性别");
    age->setText("年龄");
    IDnumber->setText("身份证号");
    update->setText("更新");
    alter->setText("修改");
    save->setText("保存");
    nameLineEdit->setEnabled(false);
    sexLineEdit->setEnabled(false);
    ageLineEdit->setEnabled(false);
    IDnumberLineEdit->setEnabled(false);

    connect(alter, &QPushButton::clicked,
           this, &PatientInfoWidget::alterButton_clicked);
    connect(save, &QPushButton::clicked,
            this, &PatientInfoWidget::savetButton_clicked);

}

void PatientInfoWidget::savetButton_clicked()
{
    nameLineEdit->setEnabled(false);
    sexLineEdit->setEnabled(false);
    ageLineEdit->setEnabled(false);
    IDnumberLineEdit->setEnabled(false);
    save->setStyleSheet("color: rgb(0, 255, 255);background-color: rgb(255, 85, 0)");
    alter->setStyleSheet("color: rgb(0, 255, 255);background-color: rgb(0, 0, 0)");
}

void PatientInfoWidget::alterButton_clicked()
{
    nameLineEdit->setEnabled(true);
    sexLineEdit->setEnabled(true);
    ageLineEdit->setEnabled(true);
    IDnumberLineEdit->setEnabled(true);
    alter->setStyleSheet("color: rgb(0, 255, 255);background-color: rgb(255, 85, 0)");
    save->setStyleSheet("color: rgb(0, 255, 255);background-color: rgb(0, 0, 0)");
}
