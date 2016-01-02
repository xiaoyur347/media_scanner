#ifndef DATA_MODEL_H
#define DATA_MODEL_H

#include <QAbstractTableModel>
#include <QAbstractItemDelegate>
#include <QVector>
#include <QString>

class Report
{
public:
    enum VALUE
    {
        VALUE_INVALID = -1,
        VALUE_FALSE,
        VALUE_TRUE
    };
    Report()
        :m_id(0)
    {
        reset();
    }

    ~Report()
    {

    }

    void reset()
    {
        m_ePlay = VALUE_INVALID;
        m_eSeek = VALUE_INVALID;
        m_eAudioPassThrough = VALUE_INVALID;
    }

    static QString convert(VALUE value)
    {
        if (value == VALUE_INVALID)
        {
            return QString();
        }
        else if (value == VALUE_FALSE)
        {
            return "失败";
        }
        else
        {
            return "成功";
        }
    }

    void setID(unsigned id)
    {
        m_id = id;
    }
    unsigned id() const
    {
        return m_id;
    }

    void setUrl(const QString & str)
    {
        m_url = str;
    }
    QString url() const
    {
        return m_url;
    }

    void setPlay(bool value)
    {
        if (value)
        {
            m_ePlay = VALUE_TRUE;
        }
        else
        {
            m_ePlay = VALUE_FALSE;
        }
    }
    VALUE play() const
    {
        return m_ePlay;
    }

    void setSeek(bool value)
    {
        if (value)
        {
            m_eSeek = VALUE_TRUE;
        }
        else
        {
            m_eSeek = VALUE_FALSE;
        }
    }
    VALUE seek() const
    {
        return m_eSeek;
    }

    void setAudioPassThrough(bool value)
    {
        if (value)
        {
            m_eAudioPassThrough = VALUE_TRUE;
        }
        else
        {
            m_eAudioPassThrough = VALUE_FALSE;
        }
    }
    VALUE audioPassThrough() const
    {
        return m_eAudioPassThrough;
    }

private:
    unsigned m_id;
    QString m_url;
    VALUE m_ePlay;
    VALUE m_eSeek;
    VALUE m_eAudioPassThrough;
};

class ReportTable : public QAbstractTableModel
{
    Q_OBJECT

public:
    enum
    {
        COLUMN_ID,
        COLUMN_URL,
        COLUMN_PLAY,
        COLUMN_SEEK,
        COLUMN_AUDIO_PASSTHROUGH,
        COLUMN_MAX
    };
    ReportTable(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

private:
    QVector<Report> m_data;
};

class ReportDelegate : public QAbstractItemDelegate
{
    Q_OBJECT

public:
    ReportDelegate(QObject *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const Q_DECL_OVERRIDE;

    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index ) const Q_DECL_OVERRIDE;

private:
};

#endif // DATA_MODEL_H

