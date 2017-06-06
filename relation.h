#ifndef RELATION_H
#define RELATION_H
#include "notes.h"

class RelationException{
public:
    RelationException(const QString& message):info(message){}
    QString getInfo() const { return info; }
private:
    QString info;
};



class Couple
{
    /*
     * Notes& ok parce que juste besoin identifiant après gérer traitement avec searchiterator dans histonotes
     */

private:
    Notes& x;
    Notes& y;
    QString label;

public:
    Couple(Notes& a, Notes& b, QString l=""):x(a),y(b),label(l){}
    Notes& getPred() const {return x;}
    Notes& getSucc() const {return y;}
    const QString& getLabel() const {return label;}
    void setLabel(const QString& l){label=l;}

    bool operator ==(const Couple& c);



};


class Relation
{
private:
    QString titre;
    QString description;
    bool orientation;
    Couple** couples;
    unsigned int nbCouples;
    unsigned int nbMaxCouples;

public:
    Relation(QString t, QString d,bool o=0):titre(t),description(d),orientation(o),nbCouples(0),nbMaxCouples(0){}
    //gérer orientation pour addCouple...
    void addCouple(Couple* c);
    void addCouple(Notes& n1, Notes& n2, QString l="");
    //void deleteCouple(Couple& c);



    const QString& getTitre() const {return titre;}
    const QString& getDescription() const {return description;}

    void setTitre(const QString& t){titre=t;} //REFERENCE POUR QSTRING OU PAS??
    void setDesc(const QString& d){description=d;}

};


#endif // RELATION_H
