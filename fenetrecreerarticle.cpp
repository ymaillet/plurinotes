#ifndef FENETRECREERARTICLE_CPP
#define FENETRECREERARTICLE_CPP

#include "FenetreCreerArticle.h"


FenetreCreerArticle::FenetreCreerArticle() : QWidget()
{
    QPushButton *valider =new QPushButton;
    QLineEdit *nom = new QLineEdit;
    QLineEdit *prenom = new QLineEdit;
    QLineEdit *age = new QLineEdit;

    QFormLayout *formulaire = new QFormLayout;          // on crée un layout formualaire pour remplir les champs
    formulaire->addRow("Votre nom", nom);
    formulaire->addRow("Votre prénom", prenom);
    formulaire->addRow("Votre âge", age);

    buttonBox = new QDialogButtonBox;                                       // ici on crée différents voutons qui vont permettre de valider ect
           buttonBox->addButton(tr("Ok"),QDialogButtonBox::AcceptRole);
           buttonBox->addButton(QDialogButtonBox::Reset);

           connect(buttonBox, SIGNAL(accepted()),this, SLOT(accept()));
           connect(buttonBox->button(QDialogButtonBox::Reset),SIGNAL(clicked()), this, SLOT(reset()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addLayout(formulaire);
        mainLayout->addWidget(buttonBox);


    this->setLayout(mainLayout);



}



#endif // FENETRECREERARTICLE_CPP
