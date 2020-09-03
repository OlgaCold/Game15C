#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QAbstractListModel>
#include "block.h"

#define GRID_SIZE 4

class GameModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(qint32 gridSize MEMBER gridSize NOTIFY gridSizeChanged)

public:
    explicit GameModel(QObject *parent = nullptr);

    enum {
            DisplayRole,
            IsVoidRole = Qt::UserRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    /*bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;*/

    //Qt::ItemFlags flags(const QModelIndex& index) const override;

    // Add data:
    //bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    //bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    virtual QHash<int, QByteArray> roleNames() const override;
signals:
    void gridSizeChanged();
private:
    int gridSize;
    QList<Block*> m_data;
    QHash<int, QByteArray> m_roleNames;
};

#endif // GAMEMODEL_H
