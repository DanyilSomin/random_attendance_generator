#ifndef PRICES_H
#define PRICES_H

#include "enumerators.h"

#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>

class Prices
{
private:
    Prices();

    int **m_prices;
public:
    Prices(int weekdayAdult,
           int weekendAdult,
           int holidayAdult,
           int weekdayChild,
           int weekendChild,
           int holidayChild,
           int weekdayBen,
           int weekendBen,
           int holidayBen);

    int getPrice(DAYTYPE daytype, PERSONTYPE persontype);

    void setDataToDB(QString tablename);
};

#endif // PRICES_H
