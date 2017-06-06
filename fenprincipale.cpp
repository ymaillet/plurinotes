#include "FenPrincipale.h"
#include "FenetreCreerNotes.h"



FenetrePrincipale::FenetrePrincipale()
{

    QMenu *menuFichier = menuBar()->addMenu("&Fichier");

    QAction *actionQuitter = new QAction("&Quitter", this);
    menuFichier->addAction(actionQuitter);
    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    m_creer_note = new QPushButton("Creer une nouvelle note", this);      // creation du bouton
    m_creer_note2 = new QPushButton("It's a trap", this);
    QObject::connect(m_creer_note, SIGNAL(clicked()), this, SLOT(afficherCreerNotes()));  //connection au slot creerNotes


    QWidget *zoneCentrale = new QWidget;    //permet d'afficher notre layout dans la fenetre principale

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(m_creer_note2, 0, 0, 5, 2);
    layout->addWidget(m_creer_note, 0, 10, 5, 2);

    zoneCentrale->setLayout(layout);
    setCentralWidget(zoneCentrale);
}


void FenetrePrincipale::afficherCreerNotes() {                    // permet d'afficher une fenetre de type creerNotes au clic
    FenetreCreerNotes *fenetre = new FenetreCreerNotes;
    fenetre->show();
}
