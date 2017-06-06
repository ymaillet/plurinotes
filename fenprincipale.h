#ifndef HEADER_FENPRINCIPALE
#define HEADER_FENPRINCIPALE

#include <QtWidgets>

class FenetrePrincipale : public QMainWindow
{
    Q_OBJECT
    public:
        FenetrePrincipale();

    public slots:
        void afficherCreerNotes();

    private:
        QPushButton *m_creer_note;
        QPushButton *m_creer_note2;

};

#endif
