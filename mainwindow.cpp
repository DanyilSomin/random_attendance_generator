#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand( time(0) );

    m_attendanse = nullptr;
    m_attendansePrices = nullptr;

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("ShevchenkivGaj.db");
    db.open();

    setUpUIValues();
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

void MainWindow::readData()
{
    m_attendanse = new PersonCounts(ui->amountToEnterAdultWinterSpinBox->value(),
                                       ui->epsToEnterAdultWinterSpinBox->value(),
                                    ui->amountToEnterAdultSpringSpinBox->value(),
                                       ui->epsToEnterAdultSpringSpinBox->value(),
                                    ui->amountToEnterAdultSummerSpinBox->value(),
                                       ui->epsToEnterAdultSummerSpinBox->value(),
                                    ui->amountToEnterAdultSpringSpinBox->value(),
                                       ui->epsToEnterAdultSpringSpinBox->value(),
                                    ui->amountToEnterChildWinterSpinBox->value(),
                                       ui->epsToEnterChildWinterSpinBox->value(),
                                    ui->amountToEnterChildSpringSpinBox->value(),
                                       ui->epsToEnterChildSpringSpinBox->value(),
                                    ui->amountToEnterChildSummerSpinBox->value(),
                                       ui->epsToEnterChildSummerSpinBox->value(),
                                    ui->amountToEnterChildSpringSpinBox->value(),
                                       ui->epsToEnterChildSpringSpinBox->value(),
                                    ui->amountToEnterBenWinterSpinBox->value(),
                                       ui->epsToEnterBenWinterSpinBox->value(),
                                    ui->amountToEnterBenSpringSpinBox->value(),
                                       ui->epsToEnterBenSpringSpinBox->value(),
                                    ui->amountToEnterBenSummerSpinBox->value(),
                                       ui->epsToEnterBenSummerSpinBox->value(),
                                    ui->amountToEnterBenSpringSpinBox->value(),
                                       ui->epsToEnterBenSpringSpinBox->value(),
                                    ui->attendanceWeekdayCoefDoubleSpinBox->value(),
                                    ui->attendanceWeekendCoefDoubleSpinBox->value(),
                                    ui->attendanceHolidayCoefDoubleSpinBox->value() );

    m_attendansePrices = new Prices(ui->priceToEnterAdultWeekdaysSpinBox->value(),
                                    ui->priceToEnterAdultWeekendsSpinBox->value(),
                                    ui->priceToEnterAdultHolidaysSpinBox->value(),
                                    ui->priceToEnterChildWeekdaysSpinBox->value(),
                                    ui->priceToEnterChildWeekendsSpinBox->value(),
                                    ui->priceToEnterChildHolidaysSpinBox->value(),
                                    ui->priceToEnterBenWeekdaysSpinBox->value(),
                                    ui->priceToEnterBenWeekendsSpinBox->value(),
                                    ui->priceToEnterBenHolidaysSpinBox->value());

    m_excursion = new PersonCounts (ui->amountToExcursionAdultWinterSpinBox->value(),
                                       ui->epsToExcursionAdultWinterSpinBox->value(),
                                    ui->amountToExcursionAdultSpringSpinBox->value(),
                                       ui->epsToExcursionAdultSpringSpinBox->value(),
                                    ui->amountToExcursionAdultSummerSpinBox->value(),
                                       ui->epsToExcursionAdultSummerSpinBox->value(),
                                    ui->amountToExcursionAdultSpringSpinBox->value(),
                                       ui->epsToExcursionAdultSpringSpinBox->value(),
                                    ui->amountToExcursionChildWinterSpinBox->value(),
                                       ui->epsToExcursionChildWinterSpinBox->value(),
                                    ui->amountToExcursionChildSpringSpinBox->value(),
                                       ui->epsToExcursionChildSpringSpinBox->value(),
                                    ui->amountToExcursionChildSummerSpinBox->value(),
                                       ui->epsToExcursionChildSummerSpinBox->value(),
                                    ui->amountToExcursionChildSpringSpinBox->value(),
                                       ui->epsToExcursionChildSpringSpinBox->value(),
                                    ui->amountToExcursionBenWinterSpinBox->value(),
                                       ui->epsToExcursionBenWinterSpinBox->value(),
                                    ui->amountToExcursionBenSpringSpinBox->value(),
                                       ui->epsToExcursionBenSpringSpinBox->value(),
                                    ui->amountToExcursionBenSummerSpinBox->value(),
                                       ui->epsToExcursionBenSummerSpinBox->value(),
                                    ui->amountToExcursionBenSpringSpinBox->value(),
                                       ui->epsToExcursionBenSpringSpinBox->value(),
                                    ui->attendanceWeekdayCoefDoubleSpinBox->value(),
                                    ui->attendanceWeekendCoefDoubleSpinBox->value(),
                                    ui->attendanceHolidayCoefDoubleSpinBox->value() );

    m_excursionPrices = new Prices (ui->priceToExcursionAdultWeekdaysSpinBox->value(),
                                    ui->priceToExcursionAdultWeekendsSpinBox->value(),
                                    ui->priceToExcursionAdultHolidaysSpinBox->value(),
                                    ui->priceToExcursionChildWeekdaysSpinBox->value(),
                                    ui->priceToExcursionChildWeekendsSpinBox->value(),
                                    ui->priceToExcursionChildHolidaysSpinBox->value(),
                                    ui->priceToExcursionBenWeekdaysSpinBox->value(),
                                    ui->priceToExcursionBenWeekendsSpinBox->value(),
                                    ui->priceToExcursionBenHolidaysSpinBox->value());

    m_photography = new PersonCounts (ui->amountToTakePhotoAdultWinterSpinBox->value(),
                                         ui->epsToTakePhotoAdultWinterSpinBox->value(),
                                      ui->amountToTakePhotoAdultSpringSpinBox->value(),
                                         ui->epsToTakePhotoAdultSpringSpinBox->value(),
                                      ui->amountToTakePhotoAdultSummerSpinBox->value(),
                                         ui->epsToTakePhotoAdultSummerSpinBox->value(),
                                      ui->amountToTakePhotoAdultSpringSpinBox->value(),
                                         ui->epsToTakePhotoAdultSpringSpinBox->value(),
                                      ui->amountToTakePhotoChildWinterSpinBox->value(),
                                         ui->epsToTakePhotoChildWinterSpinBox->value(),
                                      ui->amountToTakePhotoChildSpringSpinBox->value(),
                                         ui->epsToTakePhotoChildSpringSpinBox->value(),
                                      ui->amountToTakePhotoChildSummerSpinBox->value(),
                                         ui->epsToTakePhotoChildSummerSpinBox->value(),
                                      ui->amountToTakePhotoChildSpringSpinBox->value(),
                                         ui->epsToTakePhotoChildSpringSpinBox->value(),
                                      ui->amountToTakePhotoBenWinterSpinBox->value(),
                                         ui->epsToTakePhotoBenWinterSpinBox->value(),
                                      ui->amountToTakePhotoBenSpringSpinBox->value(),
                                         ui->epsToTakePhotoBenSpringSpinBox->value(),
                                      ui->amountToTakePhotoBenSummerSpinBox->value(),
                                         ui->epsToTakePhotoBenSummerSpinBox->value(),
                                      ui->amountToTakePhotoBenSpringSpinBox->value(),
                                         ui->epsToTakePhotoBenSpringSpinBox->value(),
                                      ui->attendanceWeekdayCoefDoubleSpinBox->value(),
                                      ui->attendanceWeekendCoefDoubleSpinBox->value(),
                                      ui->attendanceHolidayCoefDoubleSpinBox->value() );

    m_photographyPrices = new Prices (ui->priceToTakePhotoAdultWeekdaysSpinBox->value(),
                                      ui->priceToTakePhotoAdultWeekendsSpinBox->value(),
                                      ui->priceToTakePhotoAdultHolidaysSpinBox->value(),
                                      ui->priceToTakePhotoChildWeekdaysSpinBox->value(),
                                      ui->priceToTakePhotoChildWeekendsSpinBox->value(),
                                      ui->priceToTakePhotoChildHolidaysSpinBox->value(),
                                      ui->priceToTakePhotoBenWeekdaysSpinBox->value(),
                                      ui->priceToTakePhotoBenWeekendsSpinBox->value(),
                                      ui->priceToTakePhotoBenHolidaysSpinBox->value());

    m_horseRiding = new PersonCounts (ui->amountToHorseRidingAdultWinterSpinBox->value(),
                                         ui->epsToHorseRidingAdultWinterSpinBox->value(),
                                      ui->amountToHorseRidingAdultSpringSpinBox->value(),
                                         ui->epsToHorseRidingAdultSpringSpinBox->value(),
                                      ui->amountToHorseRidingAdultSummerSpinBox->value(),
                                         ui->epsToHorseRidingAdultSummerSpinBox->value(),
                                      ui->amountToHorseRidingAdultSpringSpinBox->value(),
                                         ui->epsToHorseRidingAdultSpringSpinBox->value(),
                                      ui->amountToHorseRidingChildWinterSpinBox->value(),
                                         ui->epsToHorseRidingChildWinterSpinBox->value(),
                                      ui->amountToHorseRidingChildSpringSpinBox->value(),
                                         ui->epsToHorseRidingChildSpringSpinBox->value(),
                                      ui->amountToHorseRidingChildSummerSpinBox->value(),
                                         ui->epsToHorseRidingChildSummerSpinBox->value(),
                                      ui->amountToHorseRidingChildSpringSpinBox->value(),
                                         ui->epsToHorseRidingChildSpringSpinBox->value(),
                                      ui->amountToHorseRidingBenWinterSpinBox->value(),
                                         ui->epsToHorseRidingBenWinterSpinBox->value(),
                                      ui->amountToHorseRidingBenSpringSpinBox->value(),
                                         ui->epsToHorseRidingBenSpringSpinBox->value(),
                                      ui->amountToHorseRidingBenSummerSpinBox->value(),
                                         ui->epsToHorseRidingBenSummerSpinBox->value(),
                                      ui->amountToHorseRidingBenSpringSpinBox->value(),
                                         ui->epsToHorseRidingBenSpringSpinBox->value(),
                                      ui->attendanceWeekdayCoefDoubleSpinBox->value(),
                                      ui->attendanceWeekendCoefDoubleSpinBox->value(),
                                      ui->attendanceHolidayCoefDoubleSpinBox->value() );

    m_horseRidingPrices = new Prices (ui->priceToHorseRidingAdultWeekdaysSpinBox->value(),
                                      ui->priceToHorseRidingAdultWeekendsSpinBox->value(),
                                      ui->priceToHorseRidingAdultHolidaysSpinBox->value(),
                                      ui->priceToHorseRidingChildWeekdaysSpinBox->value(),
                                      ui->priceToHorseRidingChildWeekendsSpinBox->value(),
                                      ui->priceToHorseRidingChildHolidaysSpinBox->value(),
                                      ui->priceToHorseRidingBenWeekdaysSpinBox->value()  ,
                                      ui->priceToHorseRidingBenWeekendsSpinBox->value()  ,
                                      ui->priceToHorseRidingBenHolidaysSpinBox->value()   );


}

void MainWindow::updateData()
{
    if (ui->winterRadioBtn->isChecked())
    {
        m_curSeason = WINTER;
    }
    else if (ui->springRadioBtn->isChecked())
    {
        m_curSeason = SPRING;
    }
    else if (ui->summerRadioBtn->isChecked())
    {
        m_curSeason = SUMMER;
    }
    else if (ui->autumnRadioBtn->isChecked())
    {
        m_curSeason = AUTUMN;
    }

    if (ui->weekdayRadioBtn->isChecked())
    {
        m_curDaytype = WEEKDAY;
    }
    else if (ui->weekendRadioBtn->isChecked())
    {
        m_curDaytype = WEEKEND;
    }
    else if (ui->holidayRadioBtn->isChecked())
    {
        m_curDaytype = HOLIDAY;
    }
    if (ui->normalTypeRadioButton->isChecked())
    {
        m_curRandomGeneratorType = NORMAL;
    }
    else if (ui->linearTypeRadioButton->isChecked())
    {
        m_curRandomGeneratorType = LINEAR;
    }

    int attendanseSum = 0;
    int excursionSum = 0;
    int otherSum = 0;
    int personCount = 0;
    int cost = 0;

    for (int i = 0; i < PERSONTYPES_COUNT; ++i)
    {
        personCount = m_attendanse->getPersonCount(m_curSeason, m_curDaytype, static_cast<PERSONTYPE>(i));
        cost = m_attendansePrices->getPrice(m_curDaytype, static_cast<PERSONTYPE>(i));
        attendanseSum += personCount * cost;

        personCount = m_excursion->getPersonCount(m_curSeason, m_curDaytype, static_cast<PERSONTYPE>(i));
        cost = m_excursionPrices->getPrice(m_curDaytype, static_cast<PERSONTYPE>(i));
        excursionSum += personCount * cost;

        personCount = m_photography->getPersonCount(m_curSeason, m_curDaytype, static_cast<PERSONTYPE>(i));
        cost = m_photographyPrices->getPrice(m_curDaytype, static_cast<PERSONTYPE>(i));
        otherSum += personCount * cost;
        personCount = m_horseRiding->getPersonCount(m_curSeason, m_curDaytype, static_cast<PERSONTYPE>(i));
        cost = m_horseRidingPrices->getPrice(m_curDaytype, static_cast<PERSONTYPE>(i));
        otherSum += personCount * cost;
    }

    ui->admissionSumSpinBox->setValue(attendanseSum);
    ui->excursionServicesSpinBox->setValue(excursionSum);
    ui->anotherServicesSpinBox->setValue(otherSum);

    ui->finalEarningsSpinBox->setValue(ui->admissionSumSpinBox->value()      +
                                       ui->excursionServicesSpinBox->value() +
                                       ui->anotherServicesSpinBox->value()    );

    if (ui->admissionRadioButton->isChecked())
    {
        updateAdmissionTable();
    }
    else if (ui->enteranceRadioButton->isChecked())
    {
        updateEnteranceTable();
    }
}

void MainWindow::updateAdmissionTable()
{
    QBarSet *set0 = new QBarSet("Дорослі");
    QBarSet *set1 = new QBarSet("Діти");
    QBarSet *set2 = new QBarSet("Пільговики");

    *set0 << m_attendanse->getPersonCount(m_curSeason, m_curDaytype, ADULT) *
             m_attendansePrices->getPrice(m_curDaytype, ADULT)
          << m_excursion->getPersonCount(m_curSeason, m_curDaytype, ADULT) *
             m_excursionPrices->getPrice(m_curDaytype, ADULT)
          << m_photography->getPersonCount(m_curSeason, m_curDaytype, ADULT) *
             m_photographyPrices->getPrice(m_curDaytype, ADULT)
          << m_horseRiding->getPersonCount(m_curSeason, m_curDaytype, ADULT) *
             m_horseRidingPrices->getPrice(m_curDaytype, ADULT)               ;

    *set1 << m_attendanse->getPersonCount(m_curSeason, m_curDaytype, CHILD) *
             m_attendansePrices->getPrice(m_curDaytype, CHILD)
          << m_excursion->getPersonCount(m_curSeason, m_curDaytype, CHILD) *
             m_excursionPrices->getPrice(m_curDaytype, CHILD)
          << m_photography->getPersonCount(m_curSeason, m_curDaytype, CHILD) *
             m_photographyPrices->getPrice(m_curDaytype, CHILD)
          << m_horseRiding->getPersonCount(m_curSeason, m_curDaytype, CHILD) *
             m_horseRidingPrices->getPrice(m_curDaytype, CHILD)               ;

    *set2 << m_attendanse->getPersonCount(m_curSeason, m_curDaytype, BEN) *
             m_attendansePrices->getPrice(m_curDaytype, BEN)
          << m_excursion->getPersonCount(m_curSeason, m_curDaytype, BEN) *
             m_excursionPrices->getPrice(m_curDaytype, BEN)
          << m_photography->getPersonCount(m_curSeason, m_curDaytype, BEN) *
             m_photographyPrices->getPrice(m_curDaytype, BEN)
          << m_horseRiding->getPersonCount(m_curSeason, m_curDaytype, BEN) *
             m_horseRidingPrices->getPrice(m_curDaytype, BEN)               ;

    QStackedBarSeries *series = new QStackedBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);

    QChart *chart = new QChart();

    chart->addSeries(series);

    // Set title
    chart->setTitle("Прибуток");

    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Вхід" << "Екскурсії" << "Фотографування" << "Катання на коні";

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    ui->admissionChartGraphicsView->setChart(chart);
    ui->admissionChartGraphicsView->setRenderHint(QPainter::Antialiasing);
}

void MainWindow::updateEnteranceTable()
{
    // Assign names to the set of bars used
    QBarSet *set0 = new QBarSet("Вхід");
    QBarSet *set1 = new QBarSet("Екскурсії");
    QBarSet *set2 = new QBarSet("Фотографування");
    QBarSet *set3 = new QBarSet("Катання на коні");

    // Assign values for each bar
    *set0 << m_attendanse->getPersonCount(m_curSeason, m_curDaytype, ADULT)
          << m_attendanse->getPersonCount(m_curSeason, m_curDaytype, CHILD)
          << m_attendanse->getPersonCount(m_curSeason, m_curDaytype, BEN  );

    *set1 << m_excursion->getPersonCount(m_curSeason, m_curDaytype, ADULT)
          << m_excursion->getPersonCount(m_curSeason, m_curDaytype, CHILD)
          << m_excursion->getPersonCount(m_curSeason, m_curDaytype, BEN  );

    *set2 << m_photography->getPersonCount(m_curSeason, m_curDaytype, ADULT)
          << m_photography->getPersonCount(m_curSeason, m_curDaytype, CHILD)
          << m_photography->getPersonCount(m_curSeason, m_curDaytype, BEN  );

    *set3 << m_horseRiding->getPersonCount(m_curSeason, m_curDaytype, ADULT)
          << m_horseRiding->getPersonCount(m_curSeason, m_curDaytype, CHILD)
          << m_horseRiding->getPersonCount(m_curSeason, m_curDaytype, BEN  );

    // Add all sets of data to the chart as a whole
    // 1. Bar Chart
    QBarSeries *series = new QBarSeries();

    // 2. Stacked bar chart
    //QStackedBarSeries *series = new QStackedBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);

    // Used to define the bar chart to display, title
    // legend,
    QChart *chart = new QChart();

    // Add the chart
    chart->addSeries(series);

    // Set title
    chart->setTitle("Кількість відвідувачів");

    // Define starting animation
    // NoAnimation, GridAxisAnimations, SeriesAnimations
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Holds the category titles
    QStringList categories;
    categories << "Дорослі" << "Діти" << "Пільговики";

    // Adds categories to the axes
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();

    // 1. Bar chart
    chart->setAxisX(axis, series);

    // 2. Stacked Bar chart
    // chart->setAxisY(axis, series);

    // Define where the legend is displayed
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Used to display the chart
    ui->admissionChartGraphicsView->setChart(chart);
    ui->admissionChartGraphicsView->setRenderHint(QPainter::Antialiasing);
}

void MainWindow::setUpUIValues()
{
    QSqlQuery query;
    if (!query.exec("SELECT Key, Value, Dispersion FROM enterance"))
    {
        qDebug() << "Failed to get data about person count from data base!";
    }
    else
    {
        ui->amountToEnterAdultWinterSpinBox->setValue((query.first(), query.value("Value").toInt()));
           ui->epsToEnterAdultWinterSpinBox->setValue(query.value("Dispersion").toInt());
        ui->amountToEnterAdultSpringSpinBox->setValue((query.next(), query.value("Value").toInt()));
           ui->epsToEnterAdultSpringSpinBox->setValue(query.value("Dispersion").toInt());
        ui->amountToEnterAdultSummerSpinBox->setValue((query.next(), query.value("Value").toInt()));
           ui->epsToEnterAdultSummerSpinBox->setValue(query.value("Dispersion").toInt());
        ui->amountToEnterAdultAutumnSpinBox->setValue((query.next(), query.value("Value").toInt()));
           ui->epsToEnterAdultAutumnSpinBox->setValue(query.value("Dispersion").toInt());
        ui->amountToEnterChildWinterSpinBox->setValue((query.next(), query.value("Value").toInt()));
           ui->epsToEnterChildWinterSpinBox->setValue(query.value("Dispersion").toInt());
        ui->amountToEnterChildSpringSpinBox->setValue((query.next(), query.value("Value").toInt()));
           ui->epsToEnterChildSpringSpinBox->setValue(query.value("Dispersion").toInt());
        ui->amountToEnterChildSummerSpinBox->setValue((query.next(), query.value("Value").toInt()));
           ui->epsToEnterChildSummerSpinBox->setValue(query.value("Dispersion").toInt());
        ui->amountToEnterChildAutumnSpinBox->setValue((query.next(), query.value("Value").toInt()));
           ui->epsToEnterChildAutumnSpinBox->setValue(query.value("Dispersion").toInt());
          ui->amountToEnterBenWinterSpinBox->setValue((query.next(), query.value("Value").toInt()));
             ui->epsToEnterBenWinterSpinBox->setValue(query.value("Dispersion").toInt());
          ui->amountToEnterBenSpringSpinBox->setValue((query.next(), query.value("Value").toInt()));
             ui->epsToEnterBenSpringSpinBox->setValue(query.value("Dispersion").toInt());
          ui->amountToEnterBenSummerSpinBox->setValue((query.next(), query.value("Value").toInt()));
             ui->epsToEnterBenSummerSpinBox->setValue(query.value("Dispersion").toInt());
          ui->amountToEnterBenAutumnSpinBox->setValue((query.next(), query.value("Value").toInt()));
             ui->epsToEnterBenAutumnSpinBox->setValue(query.value("Dispersion").toInt());
    }

    if (!query.exec("SELECT Weekend, Weekday, Holiday FROM enteranceCoefs"))
    {
        qDebug() << "Failed to get data about daytype multipliers count from data base!";
    }
    else
    {
        query.first();
        ui->attendanceWeekdayCoefDoubleSpinBox->setValue(query.value("Weekday").toDouble());
        ui->attendanceWeekendCoefDoubleSpinBox->setValue(query.value("Weekend").toDouble());
        ui->attendanceHolidayCoefDoubleSpinBox->setValue(query.value("Holiday").toDouble());
    }

    if (!query.exec("SELECT Value FROM enterancePrices"))
    {
        qDebug() << "Failed to get data about prices count from data base!";
    }
    else
    {
        ui->priceToEnterAdultWeekdaysSpinBox->setValue((query.first(), query.value("Value").toInt()));
        ui->priceToEnterAdultWeekendsSpinBox->setValue((query.next() , query.value("Value").toInt()));
        ui->priceToEnterAdultHolidaysSpinBox->setValue((query.next() , query.value("Value").toInt()));
        ui->priceToEnterChildWeekdaysSpinBox->setValue((query.next() , query.value("Value").toInt()));
        ui->priceToEnterChildWeekendsSpinBox->setValue((query.next() , query.value("Value").toInt()));
        ui->priceToEnterChildHolidaysSpinBox->setValue((query.next() , query.value("Value").toInt()));
          ui->priceToEnterBenWeekdaysSpinBox->setValue((query.next() , query.value("Value").toInt()));
          ui->priceToEnterBenWeekendsSpinBox->setValue((query.next() , query.value("Value").toInt()));
          ui->priceToEnterBenHolidaysSpinBox->setValue((query.next() , query.value("Value").toInt()));
    }

    if (!query.exec("SELECT Key, Value, Dispersion FROM excursion"))
    {
        qDebug() << "Failed to get data about exursions from data base!";
    }
    else
    {
        ui->amountToExcursionAdultWinterSpinBox->setValue((query.first(), query.value("Value").toInt()));
           ui->epsToExcursionAdultWinterSpinBox->setValue(query.value("Dispersion").toInt());
        ui->amountToExcursionAdultSpringSpinBox->setValue((query.next(), query.value("Value").toInt()));
           ui->epsToExcursionAdultSpringSpinBox->setValue(query.value("Dispersion").toInt());
        ui->amountToExcursionAdultSummerSpinBox->setValue((query.next(), query.value("Value").toInt()));
           ui->epsToExcursionAdultSummerSpinBox->setValue(query.value("Dispersion").toInt());
        ui->amountToExcursionAdultAutumnSpinBox->setValue((query.next(), query.value("Value").toInt()));
           ui->epsToExcursionAdultAutumnSpinBox->setValue(query.value("Dispersion").toInt());
        ui->amountToExcursionChildWinterSpinBox->setValue((query.next(), query.value("Value").toInt()));
           ui->epsToExcursionChildWinterSpinBox->setValue(query.value("Dispersion").toInt());
        ui->amountToExcursionChildSpringSpinBox->setValue((query.next(), query.value("Value").toInt()));
           ui->epsToExcursionChildSpringSpinBox->setValue(query.value("Dispersion").toInt());
        ui->amountToExcursionChildSummerSpinBox->setValue((query.next(), query.value("Value").toInt()));
           ui->epsToExcursionChildSummerSpinBox->setValue(query.value("Dispersion").toInt());
        ui->amountToExcursionChildAutumnSpinBox->setValue((query.next(), query.value("Value").toInt()));
           ui->epsToExcursionChildAutumnSpinBox->setValue(query.value("Dispersion").toInt());
          ui->amountToExcursionBenWinterSpinBox->setValue((query.next(), query.value("Value").toInt()));
             ui->epsToExcursionBenWinterSpinBox->setValue(query.value("Dispersion").toInt());
          ui->amountToExcursionBenSpringSpinBox->setValue((query.next(), query.value("Value").toInt()));
             ui->epsToExcursionBenSpringSpinBox->setValue(query.value("Dispersion").toInt());
          ui->amountToExcursionBenSummerSpinBox->setValue((query.next(), query.value("Value").toInt()));
             ui->epsToExcursionBenSummerSpinBox->setValue(query.value("Dispersion").toInt());
          ui->amountToExcursionBenAutumnSpinBox->setValue((query.next(), query.value("Value").toInt()));
             ui->epsToExcursionBenAutumnSpinBox->setValue(query.value("Dispersion").toInt());
    }

    if (!query.exec("SELECT Value FROM excursionPrices"))
    {
        qDebug() << "Failed to get data about excursion prices count from data base!";
    }
    else
    {
        ui->priceToExcursionAdultWeekdaysSpinBox->setValue((query.first(), query.value("Value").toInt()));
        ui->priceToExcursionAdultWeekendsSpinBox->setValue((query.next() , query.value("Value").toInt()));
        ui->priceToExcursionAdultHolidaysSpinBox->setValue((query.next() , query.value("Value").toInt()));
        ui->priceToExcursionChildWeekdaysSpinBox->setValue((query.next() , query.value("Value").toInt()));
        ui->priceToExcursionChildWeekendsSpinBox->setValue((query.next() , query.value("Value").toInt()));
        ui->priceToExcursionChildHolidaysSpinBox->setValue((query.next() , query.value("Value").toInt()));
          ui->priceToExcursionBenWeekdaysSpinBox->setValue((query.next() , query.value("Value").toInt()));
          ui->priceToExcursionBenWeekendsSpinBox->setValue((query.next() , query.value("Value").toInt()));
          ui->priceToExcursionBenHolidaysSpinBox->setValue((query.next() , query.value("Value").toInt()));
    }

    if (!query.exec("SELECT Key, Value, Dispersion FROM photography"))
    {
        qDebug() << "Failed to get data about horse riding from data base!";
    }
    else
    {
        ui->amountToHorseRidingAdultWinterSpinBox->setValue((query.first(), query.value("Value").toInt()));
           ui->epsToHorseRidingAdultWinterSpinBox->setValue(query.value("Dispersion").toInt());
        ui->amountToHorseRidingAdultSpringSpinBox->setValue((query.next(), query.value("Value").toInt()));
           ui->epsToHorseRidingAdultSpringSpinBox->setValue(query.value("Dispersion").toInt());
        ui->amountToHorseRidingAdultSummerSpinBox->setValue((query.next(), query.value("Value").toInt()));
           ui->epsToHorseRidingAdultSummerSpinBox->setValue(query.value("Dispersion").toInt());
        ui->amountToHorseRidingAdultAutumnSpinBox->setValue((query.next(), query.value("Value").toInt()));
           ui->epsToHorseRidingAdultAutumnSpinBox->setValue(query.value("Dispersion").toInt());
        ui->amountToHorseRidingChildWinterSpinBox->setValue((query.next(), query.value("Value").toInt()));
           ui->epsToHorseRidingChildWinterSpinBox->setValue(query.value("Dispersion").toInt());
        ui->amountToHorseRidingChildSpringSpinBox->setValue((query.next(), query.value("Value").toInt()));
           ui->epsToHorseRidingChildSpringSpinBox->setValue(query.value("Dispersion").toInt());
        ui->amountToHorseRidingChildSummerSpinBox->setValue((query.next(), query.value("Value").toInt()));
           ui->epsToHorseRidingChildSummerSpinBox->setValue(query.value("Dispersion").toInt());
        ui->amountToHorseRidingChildAutumnSpinBox->setValue((query.next(), query.value("Value").toInt()));
           ui->epsToHorseRidingChildAutumnSpinBox->setValue(query.value("Dispersion").toInt());
          ui->amountToHorseRidingBenWinterSpinBox->setValue((query.next(), query.value("Value").toInt()));
             ui->epsToHorseRidingBenWinterSpinBox->setValue(query.value("Dispersion").toInt());
          ui->amountToHorseRidingBenSpringSpinBox->setValue((query.next(), query.value("Value").toInt()));
             ui->epsToHorseRidingBenSpringSpinBox->setValue(query.value("Dispersion").toInt());
          ui->amountToHorseRidingBenSummerSpinBox->setValue((query.next(), query.value("Value").toInt()));
             ui->epsToHorseRidingBenSummerSpinBox->setValue(query.value("Dispersion").toInt());
          ui->amountToHorseRidingBenAutumnSpinBox->setValue((query.next(), query.value("Value").toInt()));
             ui->epsToHorseRidingBenAutumnSpinBox->setValue(query.value("Dispersion").toInt());
    }

    if (!query.exec("SELECT Value FROM photographyPrices"))
    {
        qDebug() << "Failed to get data about photography prices count from data base!";
    }
    else
    {
        ui->priceToHorseRidingAdultWeekdaysSpinBox->setValue((query.first(), query.value("Value").toInt()));
        ui->priceToHorseRidingAdultWeekendsSpinBox->setValue((query.next() , query.value("Value").toInt()));
        ui->priceToHorseRidingAdultHolidaysSpinBox->setValue((query.next() , query.value("Value").toInt()));
        ui->priceToHorseRidingChildWeekdaysSpinBox->setValue((query.next() , query.value("Value").toInt()));
        ui->priceToHorseRidingChildWeekendsSpinBox->setValue((query.next() , query.value("Value").toInt()));
        ui->priceToHorseRidingChildHolidaysSpinBox->setValue((query.next() , query.value("Value").toInt()));
          ui->priceToHorseRidingBenWeekdaysSpinBox->setValue((query.next() , query.value("Value").toInt()));
          ui->priceToHorseRidingBenWeekendsSpinBox->setValue((query.next() , query.value("Value").toInt()));
          ui->priceToHorseRidingBenHolidaysSpinBox->setValue((query.next() , query.value("Value").toInt()));
    }
}

void MainWindow::on_calculateBtn_clicked()
{
    readData();

    m_attendanse->generateNewRandomData(m_curRandomGeneratorType);
    m_excursion->generateNewRandomData(m_curRandomGeneratorType);
    m_photography->generateNewRandomData(m_curRandomGeneratorType);
    m_horseRiding->generateNewRandomData(m_curRandomGeneratorType);

    updateData();
}

void MainWindow::on_winterRadioBtn_clicked()
{
    if ((m_attendanse       != nullptr) &&
        (m_attendansePrices != nullptr)   )
    {
        updateData();
    }
}
void MainWindow::on_springRadioBtn_clicked()
{
    if ((m_attendanse       != nullptr) &&
        (m_attendansePrices != nullptr)   )
    {
        updateData();
    }
}


void MainWindow::on_summerRadioBtn_clicked()
{
    if ((m_attendanse       != nullptr) &&
        (m_attendansePrices != nullptr)   )
    {
        updateData();
    }
}

void MainWindow::on_autumnRadioBtn_clicked()
{
    if ((m_attendanse       != nullptr) &&
        (m_attendansePrices != nullptr)   )
    {
        updateData();
    }
}

void MainWindow::on_weekdayRadioBtn_clicked()
{
    if ((m_attendanse       != nullptr) &&
        (m_attendansePrices != nullptr)   )
    {
        updateData();
    }
}

void MainWindow::on_weekendRadioBtn_clicked()
{
    if ((m_attendanse       != nullptr) &&
        (m_attendansePrices != nullptr)   )
    {
        updateData();
    }
}

void MainWindow::on_holidayRadioBtn_clicked()
{
    if ((m_attendanse       != nullptr) &&
        (m_attendansePrices != nullptr)   )
    {
        updateData();
    }
}

void MainWindow::on_dataEnterComboBox_currentIndexChanged(int index)
{
    ui->dataEnterStackedWidget->setCurrentIndex(index);
}

void MainWindow::on_exitBtn_clicked()
{
    this->close();
}

void MainWindow::on_saveEnteranceDataBtn_clicked()
{
    on_calculateBtn_clicked();
    m_attendanse->setDataToDB(QString("enterance"));
    m_attendansePrices->setDataToDB(QString("enterancePrices"));
    m_excursion->setDataToDB(QString("excursion"));
    m_excursionPrices->setDataToDB(QString("excursionPrices"));
    m_photography->setDataToDB(QString("photography"));
    m_photographyPrices->setDataToDB(QString("photographyPrices"));
    m_horseRiding->setDataToDB(QString("horseRiding"));
    m_horseRidingPrices->setDataToDB(QString("horseRidingPrices"));
}

void MainWindow::on_admissionRadioButton_clicked()
{
    updateData();
}

void MainWindow::on_enteranceRadioButton_clicked()
{
    updateData();
}

void MainWindow::on_normalTypeRadioButton_clicked()
{
    ui->calculateBtn->click();
}

void MainWindow::on_linearTypeRadioButton_clicked()
{
    ui->calculateBtn->click();
}
