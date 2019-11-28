#include "fournisseur.h"
#include<QSqlQuery>
#include<QString>
#include<QVariant>

fournisseur::fournisseur()
{
    cin=0;
    tel=00;
    nom="";
    type="";
}

fournisseur::fournisseur(long cin,long tel,QString nom,QString type)
{
this->cin=cin;
this->tel=tel;
this->nom=nom;
this->type=type;
}

bool fournisseur::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(cin);
    QString res1=QString::number(tel);
          query.prepare("INSERT INTO fournisseur (cin,tel, nom, type) "
                        "VALUES (:cin, :tel, :nom, :type)");
          query.bindValue(":cin", res);
          query.bindValue(":tel", res1);
          query.bindValue(":nom", nom);
          query.bindValue(":type", type);

          return  query.exec();
}

QSqlQueryModel * fournisseur::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from fournisseur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Telephone"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    return model;
}

bool fournisseur::supprimer(long cin1)
{
QSqlQuery query;
QString res= QString::number(cin1);
query.prepare("Delete from fournisseur where cin = :cin ");
query.bindValue(":cin", res);
return    query.exec();
}


bool fournisseur::modifier(long cin,long tel,QString nom,QString type){
    QSqlQuery query;
    QString res=QString::number(cin);
    QString res1=QString::number(tel);
    query.prepare("update fournisseur set tel=:tel ,nom=:nom ,type=:type  where cin = :cin");
    query.bindValue(":cin", res);
    query.bindValue(":tel", res1);
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    return query.exec();
}

bool fournisseur::rech(long cin){
    QSqlQuery query;
    QString res=QString::number(cin);
    QString res1=QString::number(tel);
    query.prepare("select * from fournisseur where cin = :cin");
    query.bindValue(":cin", res);
    query.bindValue(":tel", res1);
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);

    return query.exec();
}

QSqlQueryModel * fournisseur::afficherfournisseurchercher(long cin)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res=QString::number(cin);
    model->setQuery("select * from fournisseur where Cin= :cin");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("type"));
    return model;
}

QSqlQueryModel * fournisseur::trier_cin()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from fournisseur ORDER BY Cin");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("type"));
        return model;
}






