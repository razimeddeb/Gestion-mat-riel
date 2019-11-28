#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class fournisseur
{
    long cin,tel;
        QString nom,type;

public:
    fournisseur();
    fournisseur(long,long,QString,QString);
    long getcin(){return cin;}
    void setcin(long cin){this->cin=cin;}
    void settel(long tel){this->tel=tel;}
    void setnom(QString nom){this->nom=nom;}
    void settype(QString type){this->type=type;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(long);
    bool rech(long);
        bool modifier(long,long,QString,QString);
        QSqlQueryModel * afficherfournisseurchercher(long);
        QSqlQueryModel * afficher_fournisseur_ch(int);

        QSqlQueryModel * trier_cin();


    ~fournisseur(){}


};

#endif // PATIENT_H
