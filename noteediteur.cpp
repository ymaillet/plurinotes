#include "noteediteur.h"
#include <QApplication>
#include <QString>

#include <QLineEdit>
#include "Notes.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QTextEdit>


NoteEditeur::NoteEditeur(QWidget *parent):QWidget(parent)
{
    id=new QLineEdit(this);
    titre=new QLineEdit(this);

    id1= new QLabel("Identificateur", this);
    titre1=new QLabel("Titre", this);

    cid=new QHBoxLayout;
    cid->addWidget(id1);
    cid->addWidget(id);

    ctitre=new QHBoxLayout;
    ctitre->addWidget(titre1);
    ctitre->addWidget(titre);

    couche= new QVBoxLayout;
    couche->addLayout(cid);
    couche->addLayout(ctitre);

    id->setReadOnly(true);

}

NoteEditeur::NoteEditeur(Notes& n, QWidget *parent):
    QWidget(parent),note(&n)
{
    id=new QLineEdit(this);
    titre=new QLineEdit(this);

    id1= new QLabel("Identificateur", this);
    titre1=new QLabel("Titre", this);

    cid=new QHBoxLayout;
    cid->addWidget(id1);
    cid->addWidget(id);

    ctitre=new QHBoxLayout;
    ctitre->addWidget(titre1);
    ctitre->addWidget(titre);

    couche= new QVBoxLayout;
    couche->addLayout(cid);
    couche->addLayout(ctitre);

    id->setReadOnly(true);

    id->setText(note->getId());
    titre->setText(note->getTitre());

}

ArticleEditeur::ArticleEditeur(Article& art, QWidget *parent):
    NoteEditeur(art,parent), article(&art)
{

    text= new QTextEdit(this);
    text1= new QLabel("Texte", this);
    ctext=new QHBoxLayout;
    ctext->addWidget(text1);
    ctext->addWidget(text);
    QVBoxLayout* c=getCouche();
    c->addLayout(ctext);

    text->setText(article->getText());

    setLayout(c);



}

TacheEditeur::TacheEditeur(Tache& ta, QWidget *parent):
    NoteEditeur(ta,parent), tache(&ta)
{

    act= new QTextEdit(this);
    act1= new QLabel("Texte", this);
    cact=new QHBoxLayout;
    cact->addWidget(act1);
    cact->addWidget(act);
    QVBoxLayout* c=getCouche();
    c->addLayout(cact);

    act->setText(tache->getAction());

    setLayout(c);



}
