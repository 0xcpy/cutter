#ifndef RESOURCESWIDGET_H
#define RESOURCESWIDGET_H

#include "cutter.h"

#include <QDockWidget>
#include <QAbstractListModel>
#include <QTreeView>

class ResourcesModel : public QAbstractListModel
{
    Q_OBJECT

private:
    QList<ResourcesDescription> *resources;

public:
    enum Columns { INDEX = 0, NAME, VADDR, TYPE, SIZE, LANG, COUNT };
    explicit ResourcesModel(QList<ResourcesDescription> *resources, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void beginReload();
    void endReload();
};

class ResourcesWidget : public QDockWidget
{
    Q_OBJECT

private:
    ResourcesModel *model;
    QTreeView *view;
    QList<ResourcesDescription> resources;

public:
    ResourcesWidget(QWidget *parent = nullptr);

private slots:
    void refreshResources();
    void onDoubleClicked(const QModelIndex &);
};

#endif // RESOURCESWIDGET_H
