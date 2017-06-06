#ifndef FENETRECREERARTICLE_H
#define FENETRECREERARTICLE_H

#include <QtWidgets>


class FenetreCreerArticle : public QWidget
{
    Q_OBJECT
public:
    FenetreCreerArticle();

private:
    QLineEdit *nom;
    QLineEdit *prenom;
    QLineEdit *age;
    QDialogButtonBox *buttonBox;

signals:


public slots:


};


#endif // FENETRECREERARTICLE_H
