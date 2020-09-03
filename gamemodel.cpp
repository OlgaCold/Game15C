#include "gamemodel.h"

GameModel::GameModel(QObject *parent)
    : QAbstractListModel(parent), gridSize(GRID_SIZE)
{
    //m_roleNames[DisplayRole] = "number";
    //m_roleNames[IsVoidRole] = "isvoid";


    for(int i = 0; i < gridSize*gridSize; i++){
        m_data.append(new Block(i + 1, false));
    }
    m_data.at(gridSize*gridSize - 1)->setState(true);
}

int GameModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return m_data.count();// FIXME: Implement me!
}

QVariant GameModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();

    if (!index.isValid())
        return QVariant();

    switch(role) {
    case DisplayRole:
        return m_data.at(row)->getNumber();
    case IsVoidRole:
        return m_data.at(row)->getState();
    }
    return QVariant();
}

QHash<int, QByteArray> GameModel::roleNames() const
{
    QHash<int, QByteArray> blocks;
    blocks[DisplayRole] = "display";
    blocks[IsVoidRole] = "isvoid";
    return blocks;
}

/*bool GameModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}*/

/*Qt::ItemFlags GameModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}*/

/*bool GameModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endInsertRows();
}

bool GameModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
}*/
