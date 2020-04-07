#include "mainwidget.h"
#include "SparseTableModel.h"
#include "ui_mainwidget.h"


mainwidget::mainwidget(QWidget* parent)
	: QMainWindow(parent),
	ui(new Ui::mainwidgetClass)
{
	ui->setupUi(this);

	LessonScheduleModel* model = new LessonScheduleModel(10, this);
	model->setLesson(3, 2, "C++");
	model->setLesson(2, 5, "Algorithm");

	ui->tableView->setModel(model);

	this->adjustTableSize();
	this->resize(ui->tableView->verticalHeader()->width() + ui->tableView->width(),
		10 + ui->tableView->horizontalHeader()->height() + ui->tableView->height() );

	QObject::connect(
		ui->tableView->horizontalHeader(), &QHeaderView::sectionResized/*(int,int,int)*/,
		this, &mainwidget::updateSection);

	QObject::connect(ui->tableView->model(), &QAbstractItemModel::dataChanged/*(QModelIndex, QModelIndex)*/,
		this, &mainwidget::dataChanged/*(QModelIndex, QModelIndex)*/);
}

void mainwidget::adjustTableSize()
{
	int width = 0;
	int height = 0;
	for (int i = 0; i < ui->tableView->model()->columnCount(); ++i) {
		ui->tableView->resizeColumnToContents(i);
		width += ui->tableView->columnWidth(i);
	}
	for (int i = 0; i < ui->tableView->model()->rowCount(); ++i) {
		ui->tableView->resizeRowToContents(i);
		height += ui->tableView->rowHeight(i);
	}
	QRect rect = ui->tableView->geometry();
	rect.setWidth(2 + ui->tableView->verticalHeader()->width() + width);
	rect.setHeight(2 + ui->tableView->horizontalHeader()->height() + height);

	ui->tableView->setGeometry(rect);
}
