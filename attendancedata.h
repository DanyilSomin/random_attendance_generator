#ifndef ATTENDANCEDATA_H
#define ATTENDANCEDATA_H

#include "prices.h"
#include "enumerators.h"

class AttendanceData
{
private:


public:
    Prices m_prises;
    AttendanceData(Prices prices);
};

#endif // ATTENDANCEDATA_H
