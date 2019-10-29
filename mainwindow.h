#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>

// Використовується для кругових діаграм
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
QT_CHARTS_USE_NAMESPACE

#include "persons.h"
#include "prices.h"
#include "enumerators.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_calculateBtn_clicked();

    void on_springRadioBtn_clicked();

    void on_winterRadioBtn_clicked();

    void on_summerRadioBtn_clicked();

    void on_autumnRadioBtn_clicked();

    void on_weekdayRadioBtn_clicked();

    void on_weekendRadioBtn_clicked();

    void on_holidayRadioBtn_clicked();

    void on_dataEnterComboBox_currentIndexChanged(int index);

    void on_exitBtn_clicked();

    void on_saveEnteranceDataBtn_clicked();

    void on_admissionRadioButton_clicked();

    void on_enteranceRadioButton_clicked();

    void on_normalTypeRadioButton_clicked();

    void on_linearTypeRadioButton_clicked();

private:
    Ui::MainWindow *ui;

    PersonCounts *m_attendanse;
    Prices *m_attendansePrices;

    PersonCounts *m_excursion;
    Prices *m_excursionPrices;

    PersonCounts *m_photography;
    Prices *m_photographyPrices;

    PersonCounts *m_horseRiding;
    Prices *m_horseRidingPrices;

    QSqlDatabase db;

    SEASONS m_curSeason = WINTER;
    DAYTYPE m_curDaytype = WEEKDAY;
    RANDOM_GENERATOR_TYPE m_curRandomGeneratorType = NORMAL;

    void readData();
    void updateData();
    void updateAdmissionTable();
    void updateEnteranceTable();
    void setUpUIValues();
};

#endif // MAINWINDOW_H
