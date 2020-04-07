#pragma once
#include <QObject>
#include <QAbstractTableModel>
#include <QHash>

class SparseTableModel :
	public QAbstractTableModel
{
	Q_OBJECT
public:
	SparseTableModel(int rows, int cols, QObject* parent = Q_NULLPTR);
protected:
	QHash<QModelIndex, QVariant> m_data;

public:

	// override to QAbstractTableModel
	virtual  int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	virtual  int columnCount(const QModelIndex& parent = QModelIndex()) const override;
	virtual  QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	virtual  bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
	virtual  Qt::ItemFlags flags(const QModelIndex& index) const override;

private:
	int m_rowCount = 0;
	int m_colCount = 0;
};


class LessonScheduleModel :public SparseTableModel {
	Q_OBJECT
public:
	LessonScheduleModel(int rows, QObject* parent = Q_NULLPTR);
	void setLesson(int LessonNum, int DayOfWeek, QString course);

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;


};

