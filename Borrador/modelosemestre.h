#ifndef MODELOSEMESTRE_H
#define MODELOSEMESTRE_H

#include <QAbstractItemModel>
#include <semestre.h>
class ModeloSemestre : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit ModeloSemestre(Semestre * semestre,QObject *parent = 0);
    Qt::ItemFlags flags( const QModelIndex &index ) const;
    QVariant data( const QModelIndex &index, int role = Qt::DisplayRole ) const;
    QVariant headerData( int section, Qt::Orientation orientation,int role = Qt::DisplayRole ) const;
    int rowCount( const QModelIndex &parent = QModelIndex() ) const;
    int columnCount( const QModelIndex &parent = QModelIndex() ) const;
    QModelIndex index(int row, int column,
                          const QModelIndex &parent = QModelIndex()) const;

    QModelIndex parent(const QModelIndex &child) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    ~ModeloSemestre();
signals:

public slots:
private:
    Semestre * m_semestre;
    int m_rows;
    int m_columns;

};

#endif // MODELOSEMESTRE_H
