#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QCheckBox>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QSlider>
#include <QLabel>
#include <QTableView>
#include "report.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = NULL);
    ~MainWidget();
private slots:
    void onEditUrlFinished();
    void onBtnImportClick(bool checked = false);
    void onBtnRunClick(bool checked = false);
    void onBtnNextClick(bool checked = false);
    void onBtnReplayClick(bool checked = false);
private:
    void registerButton();
    void registerWidget();
    void start();
    void stop();

    QVBoxLayout *m_pLayout;
    QGridLayout *m_pGridLayout;
    QHBoxLayout *m_pHLayout[4];

    QPushButton *m_pBtnImport;    //导入
    QPushButton *m_pBtnRun;       //开始
    QPushButton *m_pBtnNext;      //切歌
    QPushButton *m_pBtnReplay;    //重唱

    QLineEdit *m_pEditUrl;       //打开

    QComboBox *m_pComboSource;    //片源
    QCheckBox *m_pCheckOriginOutput; //源码输出
    QCheckBox *m_pCheckLoop;      //循环播放
    QCheckBox *m_pCheckNoError;   //出错停止
    QLineEdit *m_pEditSingleLoop; //单曲循环次数
    QLineEdit *m_pEditSeekTime;   //拖动时长
    QLineEdit *m_pEditMaxTime;    //最大播放时长
    QLineEdit *m_pEditIPRange;    //IP范围
    QSlider *m_pProgress;         //当前进度
    QLabel *m_pLblCurTime;        //当前时间
    QLabel *m_pLblTotalTime;      //总时间

    QTableView *m_pReportView;     //数据
    ReportTable *m_pReportData;

    bool m_bRunning;
};

#endif // MAIN_WIDGET_H
