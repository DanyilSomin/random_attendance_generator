#ifndef PERSONS_H
#define PERSONS_H

#include "enumerators.h"
//#define M_PI 3.14
#include <cmath>
#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>

#include <random>

class PersonCounts
{
private:
    PersonCounts();

    int ***m_currentRandomData;
    int **m_personsCount;
    int **m_personsDisp;
    double *m_daytypesCoefs;
public:
    PersonCounts(int winterAdult, int winterAdultDisp,
                 int springAdult, int springAdultDisp,
                 int summerAdult, int summerAdultDisp,
                 int autumnAdult, int autumnAdultDisp,
                 int winterChild, int winterChildDisp,
                 int springChild, int springChildDisp,
                 int summerChild, int summerChildDisp,
                 int autumnChild, int autumnChildDisp,
                 int winterBen, int winterBenDisp,
                 int springBen, int springBenDisp,
                 int summerBen, int summerBenDisp,
                 int autumnBen, int autumnBenDisp,
                 double weekdayCoef, double weekendCoef,
                 double holidayCoef);

    int getPersonCount(SEASONS season, DAYTYPE daytype, PERSONTYPE persontype);
    void generateNewRandomData(RANDOM_GENERATOR_TYPE generatorType);

    void setDataToDB(QString tablename);
};

#endif // PERSONS_H
