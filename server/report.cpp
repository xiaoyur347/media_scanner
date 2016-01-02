#include "report.h"

ReportTable::ReportTable(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int ReportTable::rowCount(const QModelIndex & /* parent */) const
{
    return m_data.size();
}

int ReportTable::columnCount(const QModelIndex & /* parent */) const
{
    return COLUMN_MAX;
}

QVariant ReportTable::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();
    switch (index.column())
    {
    case COLUMN_ID:
        return m_data[index.row()].id();
    case COLUMN_URL:
        return m_data[index.row()].url();
    case COLUMN_PLAY:
        return Report::convert(m_data[index.row()].play());
    case COLUMN_SEEK:
        return Report::convert(m_data[index.row()].seek());
    case COLUMN_AUDIO_PASSTHROUGH:
        return Report::convert(m_data[index.row()].audioPassThrough());
    default:
        return QVariant();
    }
}

QVariant ReportTable::headerData(int section, Qt::Orientation orientation,
                                 int role) const
{
    if (role == Qt::SizeHintRole)
        return QSize(1, 1);
    return QVariant();
}

ReportDelegate::ReportDelegate(QObject *parent)
    : QAbstractItemDelegate(parent)
{

}

void ReportDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
           const QModelIndex &index) const
{

}

QSize ReportDelegate::sizeHint(const QStyleOptionViewItem &option,
               const QModelIndex &index ) const
{

}
