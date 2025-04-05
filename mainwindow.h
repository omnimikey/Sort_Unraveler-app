#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include <QLabel>
#include <vector>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_verticalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    QRandomGenerator Random;

    void Bubble_Sort(int *elements, int sizeofthearray);

    void Selection_Sort(int *elements, int sizeofthearray);

    void Insertion_Sort(int *elements, int sizeofthearay);

    void Merge(int *elements, int p, int q, int r);

    void Merge_Sort(int *elements, int l, int r);

    void Update_UI(int i, int j);

    void Swap_Elements(int i, int j);

    void Rearrange_Elements();

    void Show_Height_Values();

    void Update_UI2(int i);

    void animate_Elements(int i);

    void Update_Lbl_Elements();

    void Highlight_Elements_With_Delay(int k);

    void Update_Merge_Elements(int k, std::vector<int> merger);

    void Quick_Sort(int *elements, int low, int high);

    int Partition(int *elements, int low, int high, int pivot);

    void Quick_Swap(int *elements, int pos1, int pos2);

    void Total_Elements_Setter(int num);

    void Initialize_UI();

    QList<QLabel*> Lbl_Elements;


    int Total_Number_Of_Elements = 30;
    int *Data_Elements;
};
#endif // MAINWINDOW_H
