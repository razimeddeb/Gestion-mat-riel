#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fournisseur.h"
#include "matriel.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouterfournisseur_clicked();


    void on_supprimerfournisseur_clicked();

    void on_ajoutermatriel_clicked();

    void on_supprimermatriel_clicked();


    void on_modifierfournisseur_clicked();

    void on_modifiermatriel_clicked();


    void on_triermatriel_clicked();

    void on_chercher_matriel_clicked();
void on_trierfournisseur_clicked();


private:
    Ui::MainWindow *ui;
    fournisseur tmpfournisseur;
    matriel tmpmatriel;
};
#endif // MAINWINDOW_H

