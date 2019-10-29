#include "prices.h"

Prices::Prices() {}

Prices::Prices(int weekdayAdult,
               int weekendAdult,
               int holidayAdult,
               int weekdayChild,
               int weekendChild,
               int holidayChild,
               int weekdayBen,
               int weekendBen,
               int holidayBen)
{
    m_prices = new int*[DAYTYPES_COUNT];
    for (int i = 0; i < DAYTYPES_COUNT; ++i)
    {
        m_prices[i] = new int[PERSONTYPES_COUNT];
    }

    m_prices[WEEKDAY][ADULT] = weekdayAdult;
    m_prices[WEEKEND][ADULT] = weekendAdult;
    m_prices[HOLIDAY][ADULT] = holidayAdult;
    m_prices[WEEKDAY][CHILD] = weekdayChild;
    m_prices[WEEKEND][CHILD] = weekendChild;
    m_prices[HOLIDAY][CHILD] = holidayChild;
    m_prices[WEEKDAY][BEN]   = weekdayBen  ;
    m_prices[WEEKEND][BEN]   = weekendBen  ;
    m_prices[HOLIDAY][BEN]   = holidayBen  ;
}

int Prices::getPrice(DAYTYPE daytype, PERSONTYPE persontype)
{
    return m_prices[daytype][persontype];
}

void Prices::setDataToDB(QString tablename)
{
    for (int i = 0; i < SEASONS_COUNT * PERSONTYPES_COUNT; ++i)
    {
        QSqlQuery query;
        query.prepare(QString("UPDATE ") + tablename +
                      QString(" SET Value = :price "
                              "WHERE _id = :id;"));
        query.bindValue(":price", m_prices[i % DAYTYPES_COUNT][i / DAYTYPES_COUNT]);
        query.bindValue(":id"   , i + 1                                           );

        if(!query.exec())
        {
            qDebug() << "Problem query.exec() to " << tablename << " table!";
        }
    }
}
