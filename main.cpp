#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include "notes.h"
#include "noteediteur.h"
#include "histonotes.h"
#include "mainwindow.h"
#include "relation.h"

int main(int argc, char *argv[]) {
QApplication app(argc, argv);

MainWindow w;

Article a=Article("id_a","titreee", "salut tout le monde");
Article b=Article("id_a","change","coucoucoucou");
Tache t=Tache("id_t","tache1","fais ca");

HistoNotes<Article> ha;
ha.addVersion(&a);
ha.addVersion(&b);

Couple c1=Couple(a,b,"lab");
Couple c2=Couple(a,b,"brr");



Relation r1=Relation("implication","quand un autre");

r1.addCouple(&c1);


HistoNoteManager& m=HistoNoteManager::getInstance();
m.addHistoArticle(&ha);
Article* a2=m.getHistoArticle()->getLastVersion();

ArticleEditeur fenetre(*a2);
w.show();

return app.exec();

}
