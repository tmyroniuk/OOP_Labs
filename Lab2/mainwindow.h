#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "improvisedmodel.h"
#include "timernotification.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * Application's main window.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * Creates main window and update timer event.
     * Also creates model.
     *
     * @param parent parent object.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * Saves model.
     */
    ~MainWindow();
protected:
    /**
     * Updates timer each second.
     */
    void timerEvent (QTimerEvent*);

private slots:
    /**
     * Triggers timer creation dialog.
     */
    void on_add_timer_button_clicked();

    /**
     * Triggers alarm creation dialog.
     */
    void on_add_alarm_button_clicked();

    /**
     * Shows description and tim on newly selected timer.
     * @param currentRow
     */
    void on_listWidget_currentRowChanged(int currentRow);

    /**
     * Starts local update timer event.
     */
    void timer_start();

    /**
     * Triggers timer filter on combo box change.
     *
     * @param index index of new timer type.
     */
    void on_comboBox_currentIndexChanged(int index);

    /**
     * Creates sound and visual notification about timer timeout.
     *
     * @param timer the timer finished.
     */
    void timerNotify(Timer* timer);
    void on_pushButton_clicked();

private:
    ImprovisedModel *_model;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
