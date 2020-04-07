#include "SparseTableModel.h"
#include "QLocale"

SparseTableModel::SparseTableModel(int rows, int cols, QObject* parent/* = Q_NULLPTR*/) :
	QAbstractTableModel(parent), m_rowCount(rows), m_colCount(cols)
{

}

Q_INVOKABLE int SparseTableModel::rowCount(const QModelIndex& parent /*= QModelIndex()*/) const
{
	return m_rowCount;
}

Q_INVOKABLE int SparseTableModel::columnCount(const QModelIndex& parent /*= QModelIndex()*/) const
{
	return m_colCount;
}

Q_INVOKABLE QVariant SparseTableModel::data(const QModelIndex& index, int role /*= Qt::DisplayRole*/) const
{
	if (!index.isValid())
		return QVariant();
	if (role == Qt::DisplayRole || role == Qt::EditRole) {
		return m_data.value(index, QVariant());
	}
	return QVariant();
}

bool SparseTableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	if (!index.isValid())
		return false;
	if (role == Qt::DisplayRole || role == Qt::EditRole) {
		m_data.insert(index, value);
		emit dataChanged(index, index);
		return true;
	}
	return false;
}

Qt::ItemFlags SparseTableModel::flags(const QModelIndex& index) const
{
	if (!index.isValid())
		return Qt::NoItemFlags;
	return Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

LessonScheduleModel::LessonScheduleModel(int rows, QObject* parent /*= Q_NULLPTR*/) :
	SparseTableModel(rows, 7, parent)
{

}

void LessonScheduleModel::setLesson(int LessonNum, int DayOfWeek, QString course)
{
	/*SparseTableModel::*/setData(/*QAbstractTableModel::*/index(LessonNum - 1, DayOfWeek - 1), course, Qt::EditRole);
}

QVariant LessonScheduleModel::headerData(int section, Qt::Orientation orientation, int role /*= Qt::DisplayRole*/) const
{
	if (role != Qt::DisplayRole)
		return QVariant();
	if (orientation == Qt::Horizontal) {
		return QLocale(QLocale::English).standaloneDayName(section + 1);
	}
	else {
		return QString("Lesson %1").arg(section + 1);
	}

}
