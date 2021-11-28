#ifndef KOSOSVG_H
#define KOSOSVG_H

#include <QMainWindow>
#include <QThread>

class CanCvns;
class myStatusbar;
class QScrollArea;

namespace Ui {
class KosoSvg;
}

class MySvg : public QMainWindow
{
    Q_OBJECT

public:
    explicit MySvg(QWidget *parent = 0);
    ~MySvg();

private slots:
    void on_line_action_triggered();

    void on_reac_action_triggered();

    void on_circle_action_triggered();

    void on_hexagon_action_triggered();

    void on_triangle_action_triggered();

    void on_text_action_triggered();

    void on_open_action_triggered();

    void on_save_action_triggered();

    void on_pen_action_triggered();

    void on_pencolor_action_triggered();

    void on_backColor_action_triggered();

    void on_fill_action_triggered();

    void on_selector_action_triggered();

    void on_clear_action_triggered();

    void on_new_action_triggered();

private:
    Ui::KosoSvg *ui;
    CanCvns *msv;
    QScrollArea *scroll;
    QThread mCanCvns;
    myStatusbar *mstatusbar;
};

#endif // KOSOSVG_H
