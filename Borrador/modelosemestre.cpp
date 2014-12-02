#include "modelosemestre.h"

ModeloSemestre::ModeloSemestre(Semestre * semestre,QObject *parent) :
    QAbstractItemModel(parent),m_semestre(semestre)
{
    m_rows=m_semestre->getCantidadMaterias();
    m_columns=1;
    qDebug() << "cantidad de materias" << m_rows;
}
ModeloSemestre::~ModeloSemestre()
{
    delete m_semestre;
}

QModelIndex ModeloSemestre::index(int row, int column, const QModelIndex &parent) const
{
    //static int lal=0;
    if(!hasIndex(row,column,parent))
    {
        //lal++;
        //qDebug()<< lal << "cantidad de veces que entre";
        return QModelIndex();
    }
    //qDebug()<< "He sido llamado con "<< row << column;
    if(parent.isValid())//Si tiene padre
    {
        //qDebug() << "Tiene padre";
        //qDebug() << parent.row() <<"row";
        //qDebug() << m_semestre->getMaterias()[parent.row()]->getCalificaciones()[row]->getNombre() << "nombre calificacion";
        return createIndex(row,column,m_semestre->getMaterias()[parent.row()]->getCalificaciones()[row]);
    }
    else//Si no tiene padre,materia
    {
        //qDebug() << "Materia";
        //qDebug() << &m_semestre->getMaterias()[row];
        //qDebug()<< m_semestre->getMaterias()[row]->getNombre()<< (m_semestre->getMaterias()[row]) <<"nombre";
        //qDebug()<< m_semestre->getMaterias()[row]->getCalificaciones().size() <<"Tamaño";
        return createIndex(row,column,m_semestre->getMaterias()[row]);
    }
}
QVariant ModeloSemestre::data( const QModelIndex &index, int role) const
{
    //qDebug()<< index.row();
    if(!index.isValid() )
    {
        return QVariant();
    }
    switch( role ){
        case Qt::DisplayRole:
          if(index.parent()==QModelIndex())
            {
                return ((Materia *)index.internalPointer())->getNombre();
            }
          else
            {
              //qDebug()<<index.row() << rowCount(index);
               //qDebug() << m_semestre->getMaterias()[(index.parent()).row()]->getCalificaciones()[index.row()]->getNombre();
              Calificacion * temp = ((Calificacion *)index.internalPointer());
              //qDebug() << temp->getNombre()+QString(" %0 %1").arg(temp->getNotaReal()).arg(temp->getNotaEstimada());
              QVariant display=temp->getNombre()+QString("\t%0\t%1").arg(temp->getNotaReal()).arg(temp->getNotaEstimada());
              return display;
            }
          //return QVariant();
          //qDebug()<< QModelIndex().row();
          break;
        default:
          return QVariant();
      }
}
int ModeloSemestre::rowCount( const QModelIndex &parent ) const{
    if(parent.isValid())
    {
        //qDebug () <<((Materia *) parent.internalPointer())->getNombre();
        if(parent.parent().isValid())
        {
            //qDebug()<< "Mi padre es valido";
            return 0;
        }
        //qDebug()<< "Mi padre es invalido"<< ((Materia *)parent.internalPointer())->getCalificaciones().size();
        //qDebug() << ((Materia *)parent.internalPointer())->getCalificaciones().size() << "tamano lista ";

        return ((Materia *)parent.internalPointer())->getCalificaciones().size();
    }
    else
    {

    return m_rows;
    }
}

int ModeloSemestre::columnCount( const QModelIndex &parent ) const{
  return m_columns;
}
QVariant ModeloSemestre::headerData( int section,Qt::Orientation orientation, int role ) const{
  if( role != Qt::DisplayRole )
    return QVariant();
  return section+1;
}
Qt::ItemFlags ModeloSemestre::flags( const QModelIndex &index ) const{
  if(!index.isValid())
    return Qt::ItemIsEnabled;
  return Qt::ItemIsSelectable | Qt::ItemIsEnabled ;//| Qt::ItemIsEditable;
}
QModelIndex ModeloSemestre::parent(const QModelIndex &child) const
{
    if(child.isValid())
    {
        if(m_semestre->getMaterias().contains((Materia *)child.internalPointer()))
        {
            return QModelIndex();
        }
        else
        {
           //qDebug() << ((Calificacion *)child.internalPointer())->getNombre() << "nombre calificacion";
           return index(m_semestre->getMaterias().indexOf(((Calificacion *)child.internalPointer())->getMateria()),0,QModelIndex());
        }
        return QModelIndex();
    }
    return QModelIndex();
}
bool ModeloSemestre::setData(const QModelIndex &index, const QVariant &value, int role)
{

    QModelIndex topLeft = ModeloSemestre::index(0,0);
    QModelIndex bottomRight = ModeloSemestre::index(rowCount()-1, columnCount()-1);
    if(!index.isValid())
    {
        qDebug()<<"Agrego materiap";
        m_rows=m_semestre->getCantidadMaterias();
        emit layoutChanged();
        return true;
    }
    if(index.parent().isValid())
    {
        emit layoutChanged();
        qDebug () << "No hago nada";
        return false;
    }
    else//Si no es una materia lo que se va a agregar
    {
        qDebug()<< "agrege calificacion";
        QList<QVariant> lista=value.toList();
        qDebug() << lista[0].toString();
        Calificacion * calificacion = new Calificacion(lista.at(0).toString(),lista.at(2).toInt(),lista.at(1).toDouble(),(enum DIFICULTAD)lista.at(3).toInt());
        ((Materia *)index.internalPointer())->addCalificacion(calificacion);
        emit layoutChanged();
        return true;
    }
}
