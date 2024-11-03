/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *trang;
    QWidget *noidung;
    QTabWidget *tabWidget;
    QWidget *VT;
    QListView *dsvt;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *them;
    QPushButton *xoa;
    QPushButton *hieuchinh;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *mvt;
    QLabel *tvt;
    QLabel *dvt;
    QLabel *slt;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *tdvt;
    QPushButton *nvt;
    QPushButton *ivt;
    QWidget *NV;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *them_2;
    QPushButton *xoa_2;
    QPushButton *hieuchinh_2;
    QListView *dsnv;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *mnv;
    QLabel *ho;
    QLabel *ten;
    QLabel *phai;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_6;
    QLabel *tdnv;
    QPushButton *nnv;
    QPushButton *inv;
    QWidget *HD;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *hdn_2;
    QPushButton *hdx_2;
    QListView *dsnv_2;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_12;
    QLabel *ngay_2;
    QLabel *hoten_2;
    QLabel *loai_2;
    QLabel *tenvattu_2;
    QLabel *soluong_2;
    QLabel *dongia_2;
    QLabel *trigia_2;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *tdhd;
    QPushButton *lhdn;
    QPushButton *lhdx;
    QPushButton *ihd;
    QWidget *TKDT;
    QWidget *layoutWidget_11;
    QHBoxLayout *horizontalLayout_20;
    QLabel *shd;
    QLabel *nl;
    QLabel *lhd;
    QLabel *htnvl;
    QLabel *tghd;
    QListView *dsnv_5;
    QLabel *tieude_2;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label;
    QDateEdit *dateEdit;
    QLabel *label_2;
    QDateEdit *dateEdit_2;
    QWidget *layoutWidget_5;
    QGridLayout *gridLayout_2;
    QLabel *tdtk;
    QPushButton *ttg;
    QWidget *TKTG;
    QWidget *layoutWidget_6;
    QGridLayout *gridLayout_5;
    QLabel *tk_4;
    QPushButton *dt_4;
    QListView *dsnv_6;
    QLabel *thang;
    QLabel *doanhthu;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *tieude_3;
    QLineEdit *lineEdit;
    QLabel *tieude;
    QWidget *widget4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1150, 670);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(100000, 100000));
        MainWindow->setStyleSheet(QString::fromUtf8("#centralwidget {\n"
"	background-color: #606470\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMaximumSize(QSize(1440, 1349));
        trang = new QWidget(centralwidget);
        trang->setObjectName("trang");
        trang->setGeometry(QRect(20, 30, 1111, 571));
        sizePolicy.setHeightForWidth(trang->sizePolicy().hasHeightForWidth());
        trang->setSizePolicy(sizePolicy);
        trang->setMaximumSize(QSize(1440, 1349));
        trang->setStyleSheet(QString::fromUtf8("#trang { \n"
"	background-color: #f5f6fa;\n"
"	border-radius: 7px;\n"
"}\n"
"#dsvt, #dsnv {\n"
"	background-color: #f5f6fa;\n"
"}\n"
"\n"
"#tdvt, #tdnv, #tdhd, #tdtk, #tk_4 {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Lato\";\n"
"	border-radius: 7px\n"
"}\n"
"\n"
"#nvt, #ivt, #ihd, #lhdn, #lhdx, #ttg, #dt, #nnv, #inv, #dt_4 {\n"
"	font: Bold \"Lato\";\n"
"	color: #aab2c8;\n"
"}"));
        noidung = new QWidget(trang);
        noidung->setObjectName("noidung");
        noidung->setGeometry(QRect(170, 0, 941, 571));
        noidung->setStyleSheet(QString::fromUtf8("#noidung {\n"
"	background-color: white;\n"
"}"));
        tabWidget = new QTabWidget(noidung);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 941, 571));
        QFont font;
        font.setBold(true);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("#VT, #NV, #HD, #TKDT, #TKTG { \n"
"	background-color: #ffffff;\n"
"}\n"
"\n"
"#dvt, #mvt, #slt, #tvt, #mnv, #ho, #ten, #phai, #dongia_2, #hoten_2, #ngay_2, #loai_2, #tenvattu_2, #soluong_2, #trigia_2, #shd, #nl, #lhd, #htnvl, #tghd, #thang, #doanhthu{\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}\n"
"\n"
"#them, #xoa, #hieuchinh,#them_2, #xoa_2, #hieuchinh_2, #hdn_2, #hdx_2 {\n"
"	font: Bold \"Lato\";\n"
"	color: #aab2c8;\n"
"}\n"
""));
        tabWidget->setTabPosition(QTabWidget::TabPosition::North);
        tabWidget->setTabShape(QTabWidget::TabShape::Rounded);
        VT = new QWidget();
        VT->setObjectName("VT");
        dsvt = new QListView(VT);
        dsvt->setObjectName("dsvt");
        dsvt->setGeometry(QRect(20, 120, 861, 411));
        layoutWidget = new QWidget(VT);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 50, 295, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        them = new QPushButton(layoutWidget);
        them->setObjectName("them");

        horizontalLayout->addWidget(them);

        xoa = new QPushButton(layoutWidget);
        xoa->setObjectName("xoa");

        horizontalLayout->addWidget(xoa);

        hieuchinh = new QPushButton(layoutWidget);
        hieuchinh->setObjectName("hieuchinh");

        horizontalLayout->addWidget(hieuchinh);

        layoutWidget1 = new QWidget(VT);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(20, 90, 861, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        mvt = new QLabel(layoutWidget1);
        mvt->setObjectName("mvt");
        mvt->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        mvt->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(mvt);

        tvt = new QLabel(layoutWidget1);
        tvt->setObjectName("tvt");
        tvt->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        tvt->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(tvt);

        dvt = new QLabel(layoutWidget1);
        dvt->setObjectName("dvt");
        dvt->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        dvt->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(dvt);

        slt = new QLabel(layoutWidget1);
        slt->setObjectName("slt");
        slt->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        slt->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(slt);

        widget = new QWidget(VT);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(21, 11, 341, 31));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        tdvt = new QLabel(widget);
        tdvt->setObjectName("tdvt");
        tdvt->setStyleSheet(QString::fromUtf8("#vattu {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: \"Lato\";\n"
"	border-radius: 7px\n"
"}"));
        tdvt->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_5->addWidget(tdvt);

        nvt = new QPushButton(widget);
        nvt->setObjectName("nvt");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nvt->sizePolicy().hasHeightForWidth());
        nvt->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(nvt);

        ivt = new QPushButton(widget);
        ivt->setObjectName("ivt");

        horizontalLayout_5->addWidget(ivt);

        tabWidget->addTab(VT, QString());
        NV = new QWidget();
        NV->setObjectName("NV");
        layoutWidget_2 = new QWidget(NV);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(20, 50, 295, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        them_2 = new QPushButton(layoutWidget_2);
        them_2->setObjectName("them_2");

        horizontalLayout_3->addWidget(them_2);

        xoa_2 = new QPushButton(layoutWidget_2);
        xoa_2->setObjectName("xoa_2");

        horizontalLayout_3->addWidget(xoa_2);

        hieuchinh_2 = new QPushButton(layoutWidget_2);
        hieuchinh_2->setObjectName("hieuchinh_2");

        horizontalLayout_3->addWidget(hieuchinh_2);

        dsnv = new QListView(NV);
        dsnv->setObjectName("dsnv");
        dsnv->setGeometry(QRect(20, 120, 851, 411));
        layoutWidget2 = new QWidget(NV);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(20, 90, 851, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        mnv = new QLabel(layoutWidget2);
        mnv->setObjectName("mnv");
        mnv->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        mnv->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(mnv);

        ho = new QLabel(layoutWidget2);
        ho->setObjectName("ho");
        ho->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        ho->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(ho);

        ten = new QLabel(layoutWidget2);
        ten->setObjectName("ten");
        ten->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        ten->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(ten);

        phai = new QLabel(layoutWidget2);
        phai->setObjectName("phai");
        phai->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        phai->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(phai);

        widget1 = new QWidget(NV);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(20, 10, 351, 31));
        horizontalLayout_6 = new QHBoxLayout(widget1);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        tdnv = new QLabel(widget1);
        tdnv->setObjectName("tdnv");
        tdnv->setStyleSheet(QString::fromUtf8("#vattu {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: \"Lato\";\n"
"	border-radius: 7px\n"
"}"));
        tdnv->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_6->addWidget(tdnv);

        nnv = new QPushButton(widget1);
        nnv->setObjectName("nnv");
        sizePolicy1.setHeightForWidth(nnv->sizePolicy().hasHeightForWidth());
        nnv->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(nnv);

        inv = new QPushButton(widget1);
        inv->setObjectName("inv");
        sizePolicy1.setHeightForWidth(inv->sizePolicy().hasHeightForWidth());
        inv->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(inv);

        tabWidget->addTab(NV, QString());
        HD = new QWidget();
        HD->setObjectName("HD");
        layoutWidget_3 = new QWidget(HD);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(19, 50, 362, 31));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        hdn_2 = new QPushButton(layoutWidget_3);
        hdn_2->setObjectName("hdn_2");

        horizontalLayout_11->addWidget(hdn_2);

        hdx_2 = new QPushButton(layoutWidget_3);
        hdx_2->setObjectName("hdx_2");

        horizontalLayout_11->addWidget(hdx_2);

        dsnv_2 = new QListView(HD);
        dsnv_2->setObjectName("dsnv_2");
        dsnv_2->setGeometry(QRect(19, 120, 851, 411));
        layoutWidget_4 = new QWidget(HD);
        layoutWidget_4->setObjectName("layoutWidget_4");
        layoutWidget_4->setGeometry(QRect(20, 90, 851, 31));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        ngay_2 = new QLabel(layoutWidget_4);
        ngay_2->setObjectName("ngay_2");
        ngay_2->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        ngay_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_12->addWidget(ngay_2);

        hoten_2 = new QLabel(layoutWidget_4);
        hoten_2->setObjectName("hoten_2");
        hoten_2->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        hoten_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_12->addWidget(hoten_2);

        loai_2 = new QLabel(layoutWidget_4);
        loai_2->setObjectName("loai_2");
        loai_2->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        loai_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_12->addWidget(loai_2);

        tenvattu_2 = new QLabel(layoutWidget_4);
        tenvattu_2->setObjectName("tenvattu_2");
        tenvattu_2->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        tenvattu_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_12->addWidget(tenvattu_2);

        soluong_2 = new QLabel(layoutWidget_4);
        soluong_2->setObjectName("soluong_2");
        soluong_2->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        soluong_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_12->addWidget(soluong_2);

        dongia_2 = new QLabel(layoutWidget_4);
        dongia_2->setObjectName("dongia_2");
        dongia_2->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        dongia_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_12->addWidget(dongia_2);

        trigia_2 = new QLabel(layoutWidget_4);
        trigia_2->setObjectName("trigia_2");
        trigia_2->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        trigia_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_12->addWidget(trigia_2);

        widget2 = new QWidget(HD);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(20, 10, 521, 31));
        horizontalLayout_7 = new QHBoxLayout(widget2);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        tdhd = new QLabel(widget2);
        tdhd->setObjectName("tdhd");
        tdhd->setStyleSheet(QString::fromUtf8("#vattu {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: \"Lato\";\n"
"	border-radius: 7px\n"
"}"));
        tdhd->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_7->addWidget(tdhd);

        lhdn = new QPushButton(widget2);
        lhdn->setObjectName("lhdn");
        sizePolicy1.setHeightForWidth(lhdn->sizePolicy().hasHeightForWidth());
        lhdn->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(lhdn);

        lhdx = new QPushButton(widget2);
        lhdx->setObjectName("lhdx");
        sizePolicy1.setHeightForWidth(lhdx->sizePolicy().hasHeightForWidth());
        lhdx->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(lhdx);

        ihd = new QPushButton(widget2);
        ihd->setObjectName("ihd");
        sizePolicy1.setHeightForWidth(ihd->sizePolicy().hasHeightForWidth());
        ihd->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(ihd);

        tabWidget->addTab(HD, QString());
        TKDT = new QWidget();
        TKDT->setObjectName("TKDT");
        layoutWidget_11 = new QWidget(TKDT);
        layoutWidget_11->setObjectName("layoutWidget_11");
        layoutWidget_11->setGeometry(QRect(30, 90, 851, 31));
        horizontalLayout_20 = new QHBoxLayout(layoutWidget_11);
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        horizontalLayout_20->setContentsMargins(0, 0, 0, 0);
        shd = new QLabel(layoutWidget_11);
        shd->setObjectName("shd");
        shd->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        shd->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_20->addWidget(shd);

        nl = new QLabel(layoutWidget_11);
        nl->setObjectName("nl");
        nl->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        nl->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_20->addWidget(nl);

        lhd = new QLabel(layoutWidget_11);
        lhd->setObjectName("lhd");
        lhd->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        lhd->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_20->addWidget(lhd);

        htnvl = new QLabel(layoutWidget_11);
        htnvl->setObjectName("htnvl");
        htnvl->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        htnvl->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_20->addWidget(htnvl);

        tghd = new QLabel(layoutWidget_11);
        tghd->setObjectName("tghd");
        tghd->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        tghd->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_20->addWidget(tghd);

        dsnv_5 = new QListView(TKDT);
        dsnv_5->setObjectName("dsnv_5");
        dsnv_5->setGeometry(QRect(30, 120, 851, 411));
        tieude_2 = new QLabel(TKDT);
        tieude_2->setObjectName("tieude_2");
        tieude_2->setGeometry(QRect(130, 10, 671, 31));
        tieude_2->setStyleSheet(QString::fromUtf8("#tieude {\n"
"	font: bold \"Goldman\";\n"
"	color: #ffffff;\n"
"}"));
        layoutWidget3 = new QWidget(TKDT);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(230, 50, 421, 26));
        horizontalLayout_21 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        horizontalLayout_21->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName("label");

        horizontalLayout_21->addWidget(label);

        dateEdit = new QDateEdit(layoutWidget3);
        dateEdit->setObjectName("dateEdit");

        horizontalLayout_21->addWidget(dateEdit);

        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName("label_2");

        horizontalLayout_21->addWidget(label_2);

        dateEdit_2 = new QDateEdit(layoutWidget3);
        dateEdit_2->setObjectName("dateEdit_2");

        horizontalLayout_21->addWidget(dateEdit_2);

        layoutWidget_5 = new QWidget(TKDT);
        layoutWidget_5->setObjectName("layoutWidget_5");
        layoutWidget_5->setGeometry(QRect(30, 10, 131, 71));
        gridLayout_2 = new QGridLayout(layoutWidget_5);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        tdtk = new QLabel(layoutWidget_5);
        tdtk->setObjectName("tdtk");
        tdtk->setStyleSheet(QString::fromUtf8("#vattu {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: \"Lato\";\n"
"	border-radius: 7px\n"
"}"));
        tdtk->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(tdtk, 0, 0, 1, 1);

        ttg = new QPushButton(layoutWidget_5);
        ttg->setObjectName("ttg");
        sizePolicy1.setHeightForWidth(ttg->sizePolicy().hasHeightForWidth());
        ttg->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(ttg, 1, 0, 1, 1);

        tabWidget->addTab(TKDT, QString());
        TKTG = new QWidget();
        TKTG->setObjectName("TKTG");
        layoutWidget_6 = new QWidget(TKTG);
        layoutWidget_6->setObjectName("layoutWidget_6");
        layoutWidget_6->setGeometry(QRect(40, 80, 131, 81));
        gridLayout_5 = new QGridLayout(layoutWidget_6);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        tk_4 = new QLabel(layoutWidget_6);
        tk_4->setObjectName("tk_4");
        tk_4->setStyleSheet(QString::fromUtf8("#vattu {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: \"Lato\";\n"
"	border-radius: 7px\n"
"}"));
        tk_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(tk_4, 0, 0, 1, 1);

        dt_4 = new QPushButton(layoutWidget_6);
        dt_4->setObjectName("dt_4");
        sizePolicy1.setHeightForWidth(dt_4->sizePolicy().hasHeightForWidth());
        dt_4->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(dt_4, 1, 0, 1, 1);

        dsnv_6 = new QListView(TKTG);
        dsnv_6->setObjectName("dsnv_6");
        dsnv_6->setGeometry(QRect(200, 110, 691, 421));
        thang = new QLabel(TKTG);
        thang->setObjectName("thang");
        thang->setGeometry(QRect(200, 80, 191, 31));
        sizePolicy.setHeightForWidth(thang->sizePolicy().hasHeightForWidth());
        thang->setSizePolicy(sizePolicy);
        thang->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        thang->setAlignment(Qt::AlignmentFlag::AlignCenter);
        doanhthu = new QLabel(TKTG);
        doanhthu->setObjectName("doanhthu");
        doanhthu->setGeometry(QRect(400, 80, 491, 31));
        doanhthu->setStyleSheet(QString::fromUtf8("#label {\n"
"	background-color: #00A4E8;\n"
"	color: #ffffff;\n"
"	font: Bold \"Inter\";\n"
"}"));
        doanhthu->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget3 = new QWidget(TKTG);
        widget3->setObjectName("widget3");
        widget3->setGeometry(QRect(290, 30, 421, 28));
        horizontalLayout_8 = new QHBoxLayout(widget3);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        tieude_3 = new QLabel(widget3);
        tieude_3->setObjectName("tieude_3");
        tieude_3->setStyleSheet(QString::fromUtf8("#tieude {\n"
"	font: bold \"Goldman\";\n"
"	color: #ffffff;\n"
"}"));

        horizontalLayout_8->addWidget(tieude_3);

        lineEdit = new QLineEdit(widget3);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_8->addWidget(lineEdit);

        tabWidget->addTab(TKTG, QString());
        tieude = new QLabel(centralwidget);
        tieude->setObjectName("tieude");
        tieude->setGeometry(QRect(190, 0, 351, 31));
        tieude->setStyleSheet(QString::fromUtf8("#tieude {\n"
"	font: bold \"Goldman\";\n"
"	color: #ffffff;\n"
"}"));
        widget4 = new QWidget(centralwidget);
        widget4->setObjectName("widget4");
        widget4->setGeometry(QRect(180, 0, 41, 31));
        widget4->setStyleSheet(QString::fromUtf8("background-color: #f5f6fa;"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1150, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(accessibility)
        tabWidget->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        them->setText(QCoreApplication::translate("MainWindow", "Th\303\252m", nullptr));
        xoa->setText(QCoreApplication::translate("MainWindow", "X\303\263a", nullptr));
        hieuchinh->setText(QCoreApplication::translate("MainWindow", "Hi\341\273\207u ch\341\273\211nh", nullptr));
        mvt->setText(QCoreApplication::translate("MainWindow", "M\303\243 v\341\272\255t t\306\260", nullptr));
        tvt->setText(QCoreApplication::translate("MainWindow", "T\303\252n v\341\272\255t t\306\260", nullptr));
        dvt->setText(QCoreApplication::translate("MainWindow", "\304\220VT", nullptr));
        slt->setText(QCoreApplication::translate("MainWindow", "S\341\273\221 l\306\260\341\273\243ng t\341\273\223n", nullptr));
        tdvt->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p> V\341\272\255t t\306\260</p></body></html>", nullptr));
        nvt->setText(QCoreApplication::translate("MainWindow", "Nh\341\272\255p v\341\272\255t t\306\260", nullptr));
        ivt->setText(QCoreApplication::translate("MainWindow", "In v\341\272\255t t\306\260 t\341\273\223n kho", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(VT), QCoreApplication::translate("MainWindow", "V\341\272\254T T\306\257", nullptr));
        them_2->setText(QCoreApplication::translate("MainWindow", "Th\303\252m", nullptr));
        xoa_2->setText(QCoreApplication::translate("MainWindow", "X\303\263a", nullptr));
        hieuchinh_2->setText(QCoreApplication::translate("MainWindow", "Hi\341\273\207u ch\341\273\211nh", nullptr));
        mnv->setText(QCoreApplication::translate("MainWindow", "M\303\243 nh\303\242n vi\303\252n", nullptr));
        ho->setText(QCoreApplication::translate("MainWindow", "H\341\273\215", nullptr));
        ten->setText(QCoreApplication::translate("MainWindow", "T\303\252n", nullptr));
        phai->setText(QCoreApplication::translate("MainWindow", "Ph\303\241i", nullptr));
        tdnv->setText(QCoreApplication::translate("MainWindow", "Nh\303\242n vi\303\252n", nullptr));
        nnv->setText(QCoreApplication::translate("MainWindow", "Nh\341\272\255p nh\303\242n vi\303\252n", nullptr));
        inv->setText(QCoreApplication::translate("MainWindow", "In nh\303\242n vi\303\252n", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(NV), QCoreApplication::translate("MainWindow", "NH\303\202N VI\303\212N", nullptr));
        hdn_2->setText(QCoreApplication::translate("MainWindow", "L\341\272\255p h\303\263a \304\221\306\241n nh\341\272\255p", nullptr));
        hdx_2->setText(QCoreApplication::translate("MainWindow", "L\341\272\255p h\303\263a \304\221\306\241n xu\341\272\245t", nullptr));
        ngay_2->setText(QCoreApplication::translate("MainWindow", "Ng\303\240y", nullptr));
        hoten_2->setText(QCoreApplication::translate("MainWindow", "H\341\273\215 t\303\252n", nullptr));
        loai_2->setText(QCoreApplication::translate("MainWindow", "Lo\341\272\241i", nullptr));
        tenvattu_2->setText(QCoreApplication::translate("MainWindow", "T\303\252n v\341\272\255t t\306\260", nullptr));
        soluong_2->setText(QCoreApplication::translate("MainWindow", "S\341\273\221 l\306\260\341\273\243ng", nullptr));
        dongia_2->setText(QCoreApplication::translate("MainWindow", "\304\220\306\241n gi\303\241", nullptr));
        trigia_2->setText(QCoreApplication::translate("MainWindow", "Tr\341\273\213 gi\303\241", nullptr));
        tdhd->setText(QCoreApplication::translate("MainWindow", "H\303\263a \304\221\306\241n", nullptr));
        lhdn->setText(QCoreApplication::translate("MainWindow", "L\341\272\255p h\303\263a \304\221\306\241n nh\341\272\255p", nullptr));
        lhdx->setText(QCoreApplication::translate("MainWindow", "L\341\272\255p h\303\263a \304\221\306\241n xu\341\272\245t", nullptr));
        ihd->setText(QCoreApplication::translate("MainWindow", "In h\303\263a \304\221\306\241n", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(HD), QCoreApplication::translate("MainWindow", "H\303\223A \304\220\306\240N", nullptr));
        shd->setText(QCoreApplication::translate("MainWindow", "S\341\273\221 h\303\263a \304\221\306\241n", nullptr));
        nl->setText(QCoreApplication::translate("MainWindow", "Ng\303\240y l\341\272\255p", nullptr));
        lhd->setText(QCoreApplication::translate("MainWindow", "Lo\341\272\241i h\303\263a \304\221\306\241n", nullptr));
        htnvl->setText(QCoreApplication::translate("MainWindow", "H\341\273\215 t\303\252n nh\303\242n vi\303\252n l\341\272\255p", nullptr));
        tghd->setText(QCoreApplication::translate("MainWindow", "Tr\341\273\213 gi\303\241 h\303\263a \304\221\306\241n", nullptr));
        tieude_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-family:'Times New Roman','serif'; font-size:12pt;\">B\341\272\242NG LI\341\273\206T K\303\212 C\303\201C H\303\223A \304\220\306\240N TRONG KHO\341\272\242NG TH\341\273\234I GIAN</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "T\341\273\253 ng\303\240y :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\304\220\341\272\277n ng\303\240y :", nullptr));
        tdtk->setText(QCoreApplication::translate("MainWindow", "Th\341\273\221ng k\303\252", nullptr));
        ttg->setText(QCoreApplication::translate("MainWindow", "Theo th\341\273\235i gian", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(TKDT), QCoreApplication::translate("MainWindow", "TH\341\273\220NG K\303\212 THEO DOANH THU", nullptr));
        tk_4->setText(QCoreApplication::translate("MainWindow", "Th\341\273\221ng k\303\252", nullptr));
        dt_4->setText(QCoreApplication::translate("MainWindow", "Doanh thu", nullptr));
        thang->setText(QCoreApplication::translate("MainWindow", "TH\303\201NG", nullptr));
        doanhthu->setText(QCoreApplication::translate("MainWindow", "DOANH THU", nullptr));
        tieude_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-family:'Times New Roman','serif'; font-size:12pt;\">B\341\272\242NG TH\341\273\220NG K\303\212 DOANH THU N\304\202M</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(TKTG), QCoreApplication::translate("MainWindow", "TH\303\224NG K\303\212 THEO TH\341\273\234I GIAN", nullptr));
        tieude->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">QU\341\272\242N L\303\235 NH\341\272\254P XU\341\272\244T V\341\272\254T T\306\257</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
