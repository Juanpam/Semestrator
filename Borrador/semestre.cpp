#include "semestre.h"

Semestre::Semestre(QObject *parent,int No,int creditos) :
    QObject(parent),m_numero(No),m_creditos(creditos),m_ponderadoReal(0),m_ponderadoEstimado(0),m_mPerdidas(0)
{}
