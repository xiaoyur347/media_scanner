#include "main_widget.h"

MainWidget::MainWidget(QWidget *parent)
    :QWidget(parent),
      m_bRunning(false)
{
    QLabel *pLabel = NULL;
    QHBoxLayout *pHLayout = NULL;

    setFixedSize(640, 480);
    setWindowTitle("电影听歌工具");

    m_pLayout = new QVBoxLayout();
    setLayout(m_pLayout);
    m_pGridLayout = new QGridLayout();
    for (unsigned i = 0; i < sizeof(m_pHLayout)/sizeof(m_pHLayout[0]);i++)
    {
        m_pHLayout[i] = new QHBoxLayout();
        m_pGridLayout->addLayout(m_pHLayout[i], i, 0);
    }

    m_pBtnImport = new QPushButton();
    m_pBtnImport->setText("导入");
    m_pGridLayout->addWidget(m_pBtnImport, 0, 1);

    m_pBtnRun = new QPushButton();
    m_pBtnRun->setText("开始");
    m_pGridLayout->addWidget(m_pBtnRun, 1, 1);

    m_pBtnNext = new QPushButton();
    m_pBtnNext->setText("切歌");
    m_pGridLayout->addWidget(m_pBtnNext, 2, 1);

    m_pBtnReplay = new QPushButton();
    m_pBtnReplay->setText("重唱");
    m_pGridLayout->addWidget(m_pBtnReplay, 3, 1);

    pHLayout = m_pHLayout[0];
    pLabel = new QLabel();
    pLabel->setText("链接");
    pHLayout->addWidget(pLabel);
    m_pEditUrl = new QLineEdit();
    pHLayout->addWidget(m_pEditUrl);

    pHLayout = m_pHLayout[1];

    //片源
    pLabel = new QLabel();
    pLabel->setText("片源");
    pHLayout->addWidget(pLabel);
    m_pComboSource = new QComboBox();
    m_pComboSource->addItem("默认");
    m_pComboSource->addItem("1905");
    m_pComboSource->setCurrentIndex(0);
    pHLayout->addWidget(m_pComboSource);

    //源码输出
    m_pCheckOriginOutput = new QCheckBox();
    m_pCheckOriginOutput->setText("源码输出");
    pHLayout->addWidget(m_pCheckOriginOutput);

    //循环播放
    m_pCheckLoop = new QCheckBox();
    m_pCheckLoop->setText("循环播放");
    pHLayout->addWidget(m_pCheckLoop);

    //出错停止
    m_pCheckNoError = new QCheckBox();
    m_pCheckNoError->setText("出错停止");
    pHLayout->addWidget(m_pCheckNoError);

    pHLayout->addStretch();

    pHLayout = m_pHLayout[2];

    pLabel = new QLabel();
    pLabel->setText("单曲循环次数");
    pHLayout->addWidget(pLabel);
    m_pEditSingleLoop = new QLineEdit();
    pHLayout->addWidget(m_pEditSingleLoop);

    pLabel = new QLabel();
    pLabel->setText("拖动时长");
    pHLayout->addWidget(pLabel);
    m_pEditSeekTime = new QLineEdit();
    pHLayout->addWidget(m_pEditSeekTime);

    pLabel = new QLabel();
    pLabel->setText("最大播放时长");
    pHLayout->addWidget(pLabel);
    m_pEditMaxTime = new QLineEdit();
    pHLayout->addWidget(m_pEditMaxTime);

    pLabel = new QLabel();
    pLabel->setText("IP范围");
    pHLayout->addWidget(pLabel);
    m_pEditIPRange = new QLineEdit();
    pHLayout->addWidget(m_pEditIPRange);

    pHLayout = m_pHLayout[3];

    m_pLblCurTime = new QLabel();
    m_pLblCurTime->setText("0");
    pHLayout->addWidget(m_pLblCurTime);

    m_pProgress = new QSlider(Qt::Horizontal);
    pHLayout->addWidget(m_pProgress);

    m_pLblTotalTime = new QLabel();
    m_pLblTotalTime->setText("0");
    pHLayout->addWidget(m_pLblTotalTime);

    m_pLayout->addLayout(m_pGridLayout);

    m_pReportView = new QTableView();
    m_pReportData = new ReportTable();
    m_pReportView->setModel(m_pReportData);
    m_pLayout->addWidget(m_pReportView);

    registerButton();

    stop();
}

MainWidget::~MainWidget()
{

}

void MainWidget::registerButton()
{
    connect(m_pBtnImport, SIGNAL(clicked(bool)),
            this, SLOT(onBtnImportClick(bool)));
    connect(m_pBtnRun, SIGNAL(clicked(bool)),
            this, SLOT(onBtnRunClick(bool)));
    connect(m_pBtnNext, SIGNAL(clicked(bool)),
            this, SLOT(onBtnNextClick(bool)));
    connect(m_pBtnReplay, SIGNAL(clicked(bool)),
            this, SLOT(onBtnReplayClick(bool)));
}

void MainWidget::registerWidget()
{
    connect(m_pEditUrl, SIGNAL(editingFinished()),
            this, SLOT(onEditUrlFinished()));
}

void MainWidget::start()
{
    m_pBtnRun->setText("停止");
    m_pBtnImport->setEnabled(false);
    m_pBtnNext->setEnabled(true);
    m_pBtnReplay->setEnabled(true);
    m_bRunning = true;
}

void MainWidget::stop()
{
    m_pBtnRun->setText("开始");
    m_pBtnImport->setEnabled(true);
    m_pBtnNext->setEnabled(false);
    m_pBtnReplay->setEnabled(false);
    m_bRunning = false;
}

void MainWidget::onEditUrlFinished()
{

}

void MainWidget::onBtnImportClick(bool /* checked */)
{

}

void MainWidget::onBtnRunClick(bool /* checked */)
{
    if (m_bRunning)
    {
        stop();
    }
    else
    {
        start();
    }
}

void MainWidget::onBtnNextClick(bool /* checked */)
{

}

void MainWidget::onBtnReplayClick(bool /* checked */)
{

}
