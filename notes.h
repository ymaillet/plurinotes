#ifndef NOTES_H
#define NOTES_H

#include <QString>
#include <QDateTime>
#include <QDate>
#include <iostream>
#include <QString>
#include <QtWidgets>
#include <QMovie>
//#include <QSound>
#include <QImage>

class Notes
{
private :
    QString id;
    QString titre;
    QDateTime dateModif;
    QDateTime dateCrea;
public:

    Notes(const QString i, const QString t) : id(i), titre(t),
         dateCrea(QDate::currentDate()), dateModif(QDate::currentDate()){}




    virtual ~Notes(){}
    virtual void afficher()=0;


    const QString& getId() const { return id; }
    const QString& getTitre() const { return titre; }
    const QDateTime& getModif() const { return dateModif; }
    const QDateTime& getCrea() const { return dateCrea; }
    void setTitre(const QString& s ) { titre=s;}
    void setModif(const QDateTime& d) { dateModif=d;}
    void setCrea(const QDateTime& d ) { dateCrea=d;}

    bool operator==(const Notes& n);



};



class Article : public Notes {
    private :
        QString texte;

    public :
        const QString& getText() const { return texte; }
        void setTexte(const QString& s ) { texte=s;}

        Article(const QString i, const QString titr, const QString text) : Notes(i,titr), texte(text)  {}

        void afficher();


};

enum Statut {enAttente,enCours,terminee};

class Tache : public Notes {
    private :
        QString action;
        int priorite;
        QDate dateEcheance;
        Statut statut;

    public :
        const QString& getAction() const { return action; }
        void setAction(const QString& a ) { action=a;}

        const int& getPriorite() const { return priorite; }
        void setPrio(const int p ) { priorite=p;}

        const QDate& getEcheance() const { return dateEcheance; }
        void setEcheance(const QDate& d ) { dateEcheance=d;}

        const Statut& getStatut() const { return statut; }
        void setStatut(const Statut& s ) { statut=s;}


        Tache(const QString i, const QString titr, const QString act, Statut stat=enAttente) : Notes(i,titr), action(act), statut(stat){}
        Tache(const QString i, const QString titr, const QString act, const int prio, Statut stat=enAttente) : Notes(i,titr), action(act), priorite(prio), statut(stat){}
        Tache(const QString i, const QString titr, const QString act, const int prio, const QDate& d, Statut stat=enAttente) : Notes(i,titr), action(act), priorite(prio), statut(stat), dateEcheance(d){}


        void afficher();

};

//gérer multimedia

class Multimedia : public Notes {
    private :
        QString description;
        QString fichierImage;

    public :
        Multimedia(const QString& i, const QString& t, const QString& d, const QString& f)    //Constructeur qui prend id, titre, description et fichier image
                :Notes(i,t),description(d),fichierImage(f){}
            ~Multimedia(){}

        //Accesseur en ecriture
            void setDescription(const QString& str) {description = str;}
            void setFichier(const QString& str) {fichierImage = str;}

        //Accesseur en lecture constante
            const QString& getDescription() const {return description;}
            const QString& getFichier() const {return fichierImage;}


        //Accesseurs en lecture non const
            QString& getDescription() {return description;}
            QString& getFichier() {return fichierImage;}

};


class Video : public Multimedia {
    private :
        QMovie* fichierVideo;
        Video(const QString& i, const QString& t, const QString& D, const QString& F)
                :Multimedia(i,t,D,F){}
    public :

        void afficher();
        ~Video(){}
};

class Audio : public Multimedia {
    private :
       // QSound* fichierAudio;
        Audio(const QString& i, const QString& t, const QString& D, const QString& F)
                :Multimedia(i,t,D,F){}
    public :
        void afficher();
        ~Audio(){}
};


class Image : public Multimedia {
private :
        QImage* fichierImage;
        Image(const QString& i, const QString& t, const QString& D, const QString& F)
                :Multimedia(i,t,D,F){}

public :
        void afficher();
        ~Image(){}
};




#endif // NOTES_H
