#ifndef MATRIEL_H
#define MATRIEL_H

#include<QString>
#include<QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class matriel
{
    int ref,quan;
    QString nom;
     QDate date_achat;
public:
    matriel();
    matriel(int,int,QString,QDate);
    int getref(){return ref;}
    int getquan(){return quan;}
    void setref(int ref){this->ref=ref;}
    void setquan(int quan){this->quan=quan;}
    void setdate_achat(QDate date_achat){this->date_achat=date_achat;}
    bool ajouter_matriel();
    QSqlQueryModel * afficher_matriel();
    bool supprimer_matriel(int);
    bool rech(int);
        bool modifier(int);
        QSqlQueryModel * afficher_matriel_ch(int);
        QSqlQueryModel * triermatriel_ref();
        bool rech_matriel(int ref);

    ~matriel(){}

};

#endif // MATRIEL_H
