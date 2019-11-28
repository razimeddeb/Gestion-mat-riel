#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matriel.h"
#include "fournisseur.h"
#include <QMessageBox>
#include<QDate>
#include<QDateEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->le_nom->setInputMask("aaaaaaaaaaaaaaaaa");
     ui->le_nom2->setInputMask("aaaaaaaaaaaaaaaaa");
     ui->le_nom_3->setInputMask("aaaaaaaaaaaaaaaaa");
    ui->le_nom_2->setInputMask("aaaaaaaaaaaaaaaaa");
    ui->le_type->setInputMask("aaaaaaaaaaaaaaaa");
    ui->le_type_2->setInputMask("aaaaaaaaaaaaaaaaa");
    ui->le_ref_2->setValidator( new QIntValidator(0, 999999999, this) );
    ui->le_quan_2->setValidator( new QIntValidator(0, 999999999, this) );
    ui->quan_2->setValidator( new QIntValidator(0, 999999999, this) );
    ui->le_ref->setValidator( new QIntValidator(0, 999999999, this) );
    ui->le_ref_3->setValidator( new QIntValidator(0, 999999999, this) );
    ui->le_cin->setValidator( new QIntValidator(0, 99999999, this) );
    ui->le_telephone->setValidator( new QIntValidator(0, 99999999, this) );
    ui->le_telephone_2->setValidator( new QIntValidator(0, 99999999, this) );
    ui->le_cin_5->setValidator( new QIntValidator(0, 99999999, this) );
    ui->ancien_cin->setValidator( new QIntValidator(0, 99999999, this) );
    ui->tabfournisseur->setModel(tmpfournisseur.afficher());
    ui->tabmatriel->setModel(tmpmatriel.afficher_matriel());
    ui->tabfournisseurtrier->setModel(tmpfournisseur.afficher());
    ui->tabmatrieltrier->setModel(tmpmatriel.afficher_matriel());
    ui->tabrecherchematriel->setModel(tmpmatriel.afficher_matriel());


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouterfournisseur_clicked()
{

    long cin = ui->le_cin->text().toLong();
    long tel = ui->le_telephone->text().toLong();
    QString nom= ui->le_nom->text();
    QString type= ui->le_type->text();
  fournisseur c(cin,tel,nom,type);
  bool test=c.ajouter();
  if(test)
{ui->tabfournisseur->setModel(tmpfournisseur.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                  QObject::tr("fournisseur ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_supprimerfournisseur_clicked()
{
    long cin=ui->le_cin_5->text().toLong();
    bool test=tmpfournisseur.supprimer(cin);
    if(test)
    {ui->tabfournisseur->setModel(tmpfournisseur.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
                    QObject::tr("fournisseur supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_ajoutermatriel_clicked()
{
    long ref = ui->le_ref_2->text().toInt();
    int quan = ui->le_quan_2->text().toInt();
    QString nom= ui->le_nom2->text();


    QDate date_achat= ui->le_date->date();
  matriel ct(ref,quan,nom,date_achat);
  bool test=ct.ajouter_matriel();
  if(test)
{ui->tabmatriel->setModel(tmpmatriel.afficher_matriel());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une matriel"),
                  QObject::tr("matriel ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une matriel"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supprimermatriel_clicked()
{
    long ref =ui->le_ref_3->text().toInt();

    bool test=tmpmatriel.supprimer_matriel(ref);
    if(test)
    {ui->tabmatriel->setModel(tmpmatriel.afficher_matriel());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un matriel"),
                    QObject::tr("matriel supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un matriel"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_modifierfournisseur_clicked()
{
    long cin=ui->ancien_cin->text().toInt();
        long tel = ui->le_telephone_2->text().toLong();
        QString nom= ui->le_nom_2->text();
        QString type= ui->le_type_2->text();
        fournisseur c1;

            if(c1.rech(cin)){
                bool test = c1.modifier(cin,tel,nom,type);
                if(test){
                    ui->tabfournisseur->setModel(tmpfournisseur.afficher());
                    QMessageBox::information(nullptr, QObject::tr("Modifier un matriel"),
                                QObject::tr("matriel modifié.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("Modifier un matriel"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
            }

}

void MainWindow::on_modifiermatriel_clicked()
{
    int ref=ui->le_ref->text().toInt();
    long quan = ui->quan_2->text().toLong();
    QString nom= ui->le_nom_3->text();


    QDate date_achat= ui->date_achat->date();

        matriel ct;

            if(ct.rech(ref)){
                bool test = ct.modifier(ref);
                if(test){
                    ui->tabmatriel->setModel(tmpmatriel.afficher_matriel());
                    QMessageBox::information(nullptr, QObject::tr("Modifier une matriel"),
                                QObject::tr("matriel modifiée.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("Modifier une matriel"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
            }
}
void MainWindow::on_trierfournisseur_clicked()
{
    bool test=true;
        if(test){
                   if(ui->cin->isChecked())
               { ui->tabfournisseurtrier->setModel(tmpfournisseur.trier_cin());
                QMessageBox::information(nullptr, QObject::tr("trier fournisseur"),
                            QObject::tr("fournisseur trier.\n"
                                        "Voulez-vous enregistrer les modifications ?"),
                                   QMessageBox::Save
                                   | QMessageBox::Cancel,
                                  QMessageBox::Save);
}

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("trier fournisseur"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_triermatriel_clicked()
{
    bool test=true;

        if(test){
                if(ui->ref->isChecked())
                {ui->tabmatrieltrier->setModel(tmpmatriel.triermatriel_ref());
                QMessageBox::information(nullptr, QObject::tr("trier matriel"),
                            QObject::tr("matriel triée.\n"
                                        "Voulez-vous enregistrer les modifications ?"),
                                   QMessageBox::Save
                                   | QMessageBox::Cancel,
                                  QMessageBox::Save);}



}}


