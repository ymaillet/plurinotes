#ifndef NOTEEDITEUR_H
#define NOTEEDITEUR_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include "notes.h"



class NoteEditeur : public QWidget
{
    Q_OBJECT
    QLineEdit *id;
    QLineEdit *titre;

    QLabel *id1;
    QLabel *titre1;

    QHBoxLayout *cid;
    QHBoxLayout *ctitre;

    QVBoxLayout *couche;

    Notes *note;

    //gérer affichage date création, date modif

public:
   explicit NoteEditeur(Notes& n, QWidget *parent = 0);
   explicit NoteEditeur(QWidget *parent=0);
   QVBoxLayout* getCouche(){return couche;}


signals:

public slots:
};

class ArticleEditeur : public NoteEditeur
{
    Q_OBJECT

    QTextEdit *text;
    QLabel *text1;
    QHBoxLayout *ctext;

    Article* article;

public:
    explicit ArticleEditeur(Article& art, QWidget *parent=0);

signals:

public slots:
};

class TacheEditeur : public NoteEditeur
{
    Q_OBJECT

    QTextEdit *act;
    QLabel *act1;
    QHBoxLayout *cact;

    //gérer prio, date échéance & statut à afficher

    Tache* tache;


public:
    explicit TacheEditeur(Tache& ta, QWidget *parent=0);

signals:

public slots:
};

#endif // NOTEEDITEUR_H
