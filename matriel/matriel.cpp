#include "matriel.h"
#include<QSqlQuery>
#include<QString>
#include<QDate>
#include<QVariant>


matriel::matriel()
{

   ref=0;
   quan=0;
   nom="";


}


matriel::matriel(int ref,int quan,QString nom,QDate date_achat)
{
    this->ref=ref;
    this->quan=quan;
    this->nom=nom;
    this->date_achat=date_achat;
}

bool matriel::ajouter_matriel()
{
    QSqlQuery query;
    QString res=QString::number(ref);
    QString res1=QString::number(quan);


          query.prepare("INSERT INTO matriel (ref,quan,nom,date_achat) "
                        "VALUES (:ref,:quan,:nom,:date_achat)");
          query.bindValue(":ref", res);
          query.bindValue(":quan", res1);
          query.bindValue(":nom", nom);
          query.bindValue(":date_achat", date_achat);


          return  query.exec();
}

QSqlQueryModel * matriel::afficher_matriel()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from matriel");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("quan"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date_achat "));
    return model;
}

bool matriel::supprimer_matriel(int ref1)
{
QSqlQuery query;
QString res= QString::number(ref1);
query.prepare("Delete from matriel where ref = :ref ");
query.bindValue(":ref", res);
return    query.exec();
}

bool matriel::rech(int ref){
    QSqlQuery query;
    QString res=QString::number(ref);
    query.prepare("select * from matriel where ref = :ref");
    query.bindValue(":ref", res);
    return query.exec();
}

bool matriel::modifier(int ref){
    QSqlQuery query,Query,query1;
    QString res=QString::number(ref);
    QString rez=QString::number(quan);
    query.prepare(  "UPDATE Abonnee SET quan= :quan where ref= :ref ");
    query.bindValue(":ref", res);
    query.bindValue(":quan", rez);
     Query.prepare("update matriel set date_achat=:date_achat where ref = :ref");
     Query.bindValue(":ref", res);
     Query.bindValue(":date_achat", date_achat);
     query1.prepare(  "UPDATE Abonnee SET nom= :nom where ref= :ref ");
     query1.bindValue(":ref", res);
     query1.bindValue(":nom", nom);
    return Query.exec() && query.exec() && query1.exec();
}




QSqlQueryModel * matriel::triermatriel_ref()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from matriel ORDER BY ref");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("quan"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date_achat"));
        return model;
}



QSqlQueryModel * matriel::afficher_matriel_ch(int ref)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    QString res=QString::number(ref);
    model->setQuery("select ref,nom,quan,Date_achat from matriel WHERE regexp_like(ref,:ref)");
    query.bindValue(":ref", res);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("quan"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date_achat"));
        return model;
}

bool matriel::rech_matriel(int ref){
    QSqlQuery query;
    QString res=QString::number(ref);
    query.prepare("select * from matriel where regexp_like(ref,:ref)");
    query.bindValue(":ref", res);

    return query.exec();
}
