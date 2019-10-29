#ifndef PERSONS_H
#define PEPSONS_H

#include "persons.h"

PersonCounts::PersonCounts(int winterAdult, int winterAdultEps,
                           int springAdult, int springAdultEps,
                           int summerAdult, int summerAdultEps,
                           int autumnAdult, int autumnAdultEps,
                           int winterChild, int winterChildEps,
                           int springChild, int springChildEps,
                           int summerChild, int summerChildEps,
                           int autumnChild, int autumnChildEps,
                           int winterBen  , int winterBenEps  ,
                           int springBen  , int springBenEps  ,
                           int summerBen  , int summerBenEps  ,
                           int autumnBen  , int autumnBenEps  ,
                           double weekdayCoef, double weekendCoef,
                           double holidayCoef)
{
    m_personsCount = new int*[SEASONS_COUNT];
    m_personsDisp = new int*[SEASONS_COUNT];
    m_currentRandomData = new int**[SEASONS_COUNT];
    m_daytypesCoefs = new double[DAYTYPES_COUNT];

    for (int i = 0; i < SEASONS_COUNT; ++i)
    {
        m_currentRandomData[i] = new int*[PERSONTYPES_COUNT];
        m_personsCount[i] = new int[PERSONTYPES_COUNT];
        m_personsDisp[i] = new int[PERSONTYPES_COUNT];
    }

    for (int i = 0; i < SEASONS_COUNT; ++ i)
    {
        for (int j = 0; j < PERSONTYPES_COUNT; ++j)
        {
            m_currentRandomData[i][j] = new int[DAYTYPES_COUNT];
        }
    }

    m_personsCount[WINTER][ADULT] = winterAdult;
    m_personsCount[SPRING][ADULT] = springAdult;
    m_personsCount[SUMMER][ADULT] = summerAdult;
    m_personsCount[AUTUMN][ADULT] = autumnAdult;
    m_personsCount[WINTER][CHILD] = winterChild;
    m_personsCount[SPRING][CHILD] = springChild;
    m_personsCount[SUMMER][CHILD] = summerChild;
    m_personsCount[AUTUMN][CHILD] = autumnChild;
    m_personsCount[WINTER][BEN]   =   winterBen;
    m_personsCount[SPRING][BEN]   =   springBen;
    m_personsCount[SUMMER][BEN]   =   summerBen;
    m_personsCount[AUTUMN][BEN]   =   autumnBen;

    m_personsDisp[WINTER][ADULT] = winterAdultEps;
    m_personsDisp[SPRING][ADULT] = springAdultEps;
    m_personsDisp[SUMMER][ADULT] = summerAdultEps;
    m_personsDisp[AUTUMN][ADULT] = autumnAdultEps;
    m_personsDisp[WINTER][CHILD] = winterChildEps;
    m_personsDisp[SPRING][CHILD] = springChildEps;
    m_personsDisp[SUMMER][CHILD] = summerChildEps;
    m_personsDisp[AUTUMN][CHILD] = autumnChildEps;
    m_personsDisp[WINTER][BEN]   =   winterBenEps;
    m_personsDisp[SPRING][BEN]   =   springBenEps;
    m_personsDisp[SUMMER][BEN]   =   summerBenEps;
    m_personsDisp[AUTUMN][BEN]   =   autumnBenEps;

    m_daytypesCoefs[WEEKDAY] = weekdayCoef;
    m_daytypesCoefs[WEEKEND] = weekendCoef;
    m_daytypesCoefs[HOLIDAY] = holidayCoef;

    generateNewRandomData(NORMAL);
}

int PersonCounts::getPersonCount(SEASONS season, DAYTYPE daytype, PERSONTYPE persontype)
{
    return m_currentRandomData[season][persontype][daytype];
}

void PersonCounts::generateNewRandomData(RANDOM_GENERATOR_TYPE generatorType)
{
    std::random_device random_device;
    std::mt19937 random_engine(random_device());


    for (int season = 0; season < SEASONS_COUNT; ++season)
    {
        for (int persontype = 0; persontype < PERSONTYPES_COUNT; ++persontype)
        {
            for (int daytype = 0; daytype < DAYTYPES_COUNT; ++daytype)
            {
                if (generatorType == LINEAR)
                {
                int high = static_cast<int>(m_personsCount[season][persontype] *
                                            m_daytypesCoefs[daytype] +
                                            m_personsDisp[season][persontype] *
                                            m_daytypesCoefs[daytype]);
                int low  = static_cast<int>(m_personsCount[season][persontype] *
                                            m_daytypesCoefs[daytype] -
                                            m_personsDisp[season][persontype] *
                                            m_daytypesCoefs[daytype]);
                std::uniform_int_distribution<int> distribution(low, high);

                m_currentRandomData[season][persontype][daytype] = distribution(random_engine);
                }
                else if (generatorType == NORMAL)
                {
                    std::normal_distribution<double> distribution(m_personsCount[season][persontype] *
                                                               m_daytypesCoefs[daytype],
                                                               m_personsDisp[season][persontype] *
                                                               m_daytypesCoefs[daytype]);
                    distribution.reset();
                    m_currentRandomData[season][persontype][daytype] =
                            static_cast<int>(distribution(random_engine));
                }

                if (m_currentRandomData[season][persontype][daytype] < 0)
                {
                    m_currentRandomData[season][persontype][daytype] = 0;
                }
            }
        }
    }
}

void PersonCounts::setDataToDB(QString tablename)
{
    for (int i = 0; i < SEASONS_COUNT * PERSONTYPES_COUNT; ++i)
    {
        QSqlQuery query;
        query.prepare(QString("UPDATE ") + tablename +
                      QString(" SET Value = :value, Dispersion = :dispersion "
                              "WHERE _id = :id;"));
        query.bindValue(":value"     , m_personsCount[i % SEASONS_COUNT][i / SEASONS_COUNT]);
        query.bindValue(":dispersion", m_personsDisp [i % SEASONS_COUNT][i / SEASONS_COUNT]);
        query.bindValue(":id"        , i + 1                                               );

        if(!query.exec())
        {
            qDebug() << "Problem query.exec() to " << tablename << " table!";
        }
    }

    QSqlQuery query;
    query.prepare("UPDATE enteranceCoefs "
                  "SET Weekday = :weekday, Weekend = :weekend, Holiday = :holiday "
                  "WHERE RowName = 'Values';");
    query.bindValue(":weekday", m_daytypesCoefs[WEEKDAY]);
    query.bindValue(":weekend", m_daytypesCoefs[WEEKEND]);
    query.bindValue(":holiday", m_daytypesCoefs[HOLIDAY]);
    if(!query.exec())
    {
        qDebug() << "Problem query.exec() to enteranceCoefs table!";
    }
}

#endif //PERSONS_H
