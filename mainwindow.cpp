#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QTimer>
#include <vector>
#include <QDebug>
#include <string>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int X =20;
    int Width = 20;
    int Height = 0;

    Data_Elements = new int[Total_Number_Of_Elements];

    for(int i=0; i < Total_Number_Of_Elements; i++)
    {
        Height = Random.bounded(0, height());

        QLabel *lbl_ele = new QLabel();
        lbl_ele->setStyleSheet("QLabel{background-color:rgb(0,0,0);}");
        lbl_ele->setMinimumSize(Width, Height);
        lbl_ele->setMaximumSize(Width, Height);

        lbl_ele->setGeometry(X, (height()-Height), Width, Height);

        lbl_ele->setObjectName("Lbl_Elements_" + QString::number(i+1));
        lbl_ele->setWordWrap(true);
        lbl_ele->setFrameShape(QFrame::Panel);
        lbl_ele->setParent(this);
        lbl_ele->setVisible(true);

        Lbl_Elements.append(lbl_ele);

        Data_Elements[i]= Height;

        X = X + Width + 5;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Bubble_Sort(int *elements, int sizeofthearray)
{
    for (int i=0; i <sizeofthearray -1; i++)
    {
        for (int j=0; j < sizeofthearray -i -1; j++)
        {
            if (elements[j] > elements[j+1])
            {
                std::swap(elements[j], elements[j+1]);

                Update_UI(j, (j+1));
            }

        }

    }

}

void MainWindow::Selection_Sort(int *elements, int sizeofthearray){

    for (int i=0; i < sizeofthearray -1; ++i){
        int min_index=i;                  //min position

        for (int j=i + 1; j < sizeofthearray; ++j){
            if (elements[j] < elements[min_index]){
                min_index = j;
            }
        }
        std::swap(elements[i], elements[min_index]);
        Update_UI(i, min_index);
    }
}

void MainWindow::Insertion_Sort(int *elements, int sizeofthearray){

    int i, j, hold;
    for (i=1; i < sizeofthearray; i++){
        hold = elements[i];
        j= i -1;

        //Move elements that are greater than hold to the position ahead of current position

        while (j >=0 && elements[j] > hold){
            elements[j+1] = elements[j];
            Update_UI((j+1),j);
            j = j-1;
        }
        elements[j+1] =  hold;
    }
}

void MainWindow::Merge(int *elements, int p, int q, int r){

    int n1=q-p+1;                          //vector size left half
    int n2= r-q;                           //vector size right half

    //Use std::vector to dynamically allocate arrays
    vector<int> L(n1);
    vector<int> M(n2);



    for (int i=0; i<n1; i++){
        L[i] = elements[p+i];
    }

    for (int j=0; j<n2; j++){
        M[j] = elements[q+1+j];
    }

    //Maintain current index of sub-arrays and main array
    int i =0, j=0, k=p;

    //Place in correct position of original array as L and M approach its last element
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j]){
            elements[k] = L[i];
            i++;
        }else
        {
            elements[k] = M[j];
            j++;
        }
        k++;
    }

    //Put remaining elements in original array
    while (i <n1){
        elements[k] = L[i];    
        i++;
        k++;
    }

    while (j<n2){
        elements[k] = M[j]; 
        j++;
        k++;
    }

    vector<int> swapArray;
    //copy current array
    for (int b=0; b < k; b++){
        swapArray.push_back(elements[b]);
    }

    Update_Merge_Elements(k,swapArray);
}

void MainWindow::Merge_Sort(int *elements, int l, int r)
{    
    if (l < r ){
        int m = l + (r-l)/2;

        Merge_Sort(elements,0,m);
        Merge_Sort(elements, m+1,r);
        //Merge
        Merge(elements,l,m,r);
    }

}

void MainWindow::Quick_Swap(int *elements, int pos1, int pos2){
    int temp;
    temp=elements[pos1];
    elements[pos1]=elements[pos2];
    Update_UI(pos1, pos2);
    elements[pos2]=temp;
}


void MainWindow::Quick_Sort(int *elements, int low, int high){
    if(low<high){
        int pivot = elements[high];
        int pos = Partition(elements, low, high, pivot);

        Quick_Sort(elements, low, pos-1);
        Quick_Sort(elements, pos+1,high);
    }
}


int MainWindow::Partition(int *elements, int low, int high, int pivot){
    int i =low;
    int j= low;

    while (i <=high){
        if (elements[i] > pivot){
            i++;
        }
        else{
            Quick_Swap(elements,i,j);
            i++;
            j++;
        }
    }
    return j-1;

};

void MainWindow::Update_UI(int i, int j)
{

    Swap_Elements(i,j);

    std::swap(Lbl_Elements[i], Lbl_Elements[j]);

    QEventLoop loop;
    QTimer::singleShot(150,&loop, &QEventLoop::quit);
    loop.exec();

    Rearrange_Elements();

}

void MainWindow::Update_UI2(int i)
{

    animate_Elements(i);

    QEventLoop loop;
    QTimer::singleShot(15,&loop, &QEventLoop::quit);
    loop.exec();

    Rearrange_Elements();

}

void MainWindow::animate_Elements(int i)
{
    QPoint pos_1 = Lbl_Elements[i]->pos();

    Lbl_Elements[i]->setStyleSheet("QLabel{background-color:rgb(0,255,0);}");

    QPropertyAnimation *Animation_1 = new QPropertyAnimation(Lbl_Elements[i], "pos");
    Animation_1->setStartValue(pos_1);
    Animation_1->setEndValue(pos_1);
    Animation_1->setDuration(100);
}

void MainWindow::Swap_Elements(int i, int j)
{
    QPoint pos_1 = Lbl_Elements[i]->pos();
    QPoint pos_2 = Lbl_Elements[j]->pos();

    Lbl_Elements[i]->setStyleSheet("QLabel{background-color:rgb(0,255,0);}");
    Lbl_Elements[j]->setStyleSheet("QLabel{background-color:rgb(255,255,0);}");

    QPropertyAnimation *Animation_1 = new QPropertyAnimation(Lbl_Elements[i], "pos");
    Animation_1->setStartValue(pos_1);
    Animation_1->setEndValue(pos_2);
    Animation_1->setDuration(100);

    QPropertyAnimation *Animation_2 = new QPropertyAnimation(Lbl_Elements[j], "pos");
    Animation_2->setStartValue(pos_2);
    Animation_2->setEndValue(pos_1);
    Animation_2->setDuration(100);

    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
    group->addAnimation(Animation_1);
    group->addAnimation(Animation_2);
    group->start(QAbstractAnimation::DeleteWhenStopped);

}

void MainWindow::Rearrange_Elements()
{
    for (int i=0; i < Total_Number_Of_Elements; i++)
    {
        QRect Geo = Lbl_Elements[i] ->geometry();
        Lbl_Elements[i]->setStyleSheet("QLabel{background-color:rgb(0,0,0);}");
        Lbl_Elements[i]->setGeometry(Geo.x(), (height() - Geo.height()), Geo.width(), Geo.height());
    }
}

void MainWindow::Update_Lbl_Elements()
{
    // Loop through all Lbl_Elements
    for (int i = 0; i < Total_Number_Of_Elements; ++i) {
        // Update the value of the Data_Elements array (e.g., new height or value)
        int newHeight = Random.bounded(0, height());  // Random height for demonstration, or some new value

        // Update Data_Elements array
        Data_Elements[i] = newHeight;

        // Get the corresponding QLabel
        QLabel* lbl = Lbl_Elements[i];

        // Update the height (or any other property)
        lbl->setFixedHeight(newHeight);

        // Update the text of the label (show the height or value)
        lbl->setText(QString::number(newHeight));

        // Optionally, set a new color for the label to show it was updated
        lbl->setStyleSheet("QLabel { background-color: rgb(0, 255, 0); }");

        // If needed, you can use animations here to visually update the height, like in your previous examples.

        // Re-position the label if necessary (to ensure it stays at the correct position based on new height)
        int xPos = 20 + i * (lbl->width() + 5);  // Example X position logic
        lbl->setGeometry(xPos, height() - newHeight, lbl->width(), newHeight);  // Update position and size

    }
}

//Qt runs too many unnecessary operations that are not ran in VisualStudio for example so I will implement a comparison to minimize the operations

int check_k=0;

void MainWindow::Update_Merge_Elements(int k, vector<int> merger)
{
    if (k > check_k || k == Total_Number_Of_Elements){

        check_k=k;
        QEventLoop loop;

    //Highlight_Elements_With_Delay(k);
    if (k > Total_Number_Of_Elements/2)
    {    qDebug() << "Array values of Data_Element:";
        for (int i = 0; i <k; ++i) {
            qDebug() << merger[i] << "\t"<< " ";
        }}
    // Loop through all Lbl_Elements
    for (int i = 0; i < k; ++i) {
        int newHeight = merger[i];


        // Get the corresponding QLabel
        QLabel* lbl = Lbl_Elements[i];

        // Update the height (or any other property)
        lbl->setFixedHeight(newHeight);

        // Update the text of the label (show the height or value)
        lbl->setText(QString::number(newHeight));

        // Optionally, set a new color for the label to show it was updated
        lbl->setStyleSheet("QLabel { background-color: rgb(0, 255, 0); }");
        int xPos = 20 + i * (lbl->width() + 5);
        lbl->setGeometry(xPos, height() - newHeight, lbl->width(), newHeight);
        // Create animation for label's position
        QPropertyAnimation* animation = new QPropertyAnimation(lbl, "geometry");
        animation->setDuration(20); // Adjust duration if needed
        animation->setStartValue(lbl->geometry());
        animation->setEndValue(QRect(xPos, height() - newHeight, lbl->width(), newHeight));

        // Ensure animation finishes before moving to the next label
        QObject::connect(animation, &QPropertyAnimation::finished, &loop, &QEventLoop::quit);
        animation->start(QAbstractAnimation::DeleteWhenStopped);
        loop.exec();  // Wait until animation finishes
    }

    // Reset styles after all animations are complete
    QTimer::singleShot(500, [this]() {
        for (auto lbl : Lbl_Elements) {
            lbl->setStyleSheet("QLabel { background-color: rgb(0, 0, 0); }");
            lbl->update();
        }
    });

    qDebug() << "Merge elements updated with animations.";
    }
    }

void MainWindow::Show_Height_Values()
{
    qDebug() << "Height values of Data_Elements:";
    for (int i = 0; i < Total_Number_Of_Elements; i++) {
        qDebug() << "Element" << i << ":" << Data_Elements[i];
    }
}

void MainWindow::on_pushButton_clicked()         // Bubble Sort Button
{
    Bubble_Sort(Data_Elements, Total_Number_Of_Elements);
}


void MainWindow::on_pushButton_2_clicked()  //Selection Sort Button
{

    Selection_Sort(Data_Elements, Total_Number_Of_Elements);
    Show_Height_Values();
}


void MainWindow::on_pushButton_3_clicked()   //Insertion Sort Button
{
    Insertion_Sort(Data_Elements, Total_Number_Of_Elements);
}


void MainWindow::on_pushButton_4_clicked() //Merge Sort Button
{
    \
    Merge_Sort(Data_Elements,0 ,Total_Number_Of_Elements-1);
}


void MainWindow::on_pushButton_5_clicked() //Reset Button
{

    // Step 1: Safely delete all QLabel elements in Lbl_Elements
    for (QLabel* lbl : Lbl_Elements) {
        lbl->deleteLater();  // This schedules each QLabel for deletion after the event loop
    }

    // Step 2: Clear the Lbl_Elements list
    Lbl_Elements.clear();

    // Step 3: Reset or clear the Data_Elements array if necessary
    if (Data_Elements != nullptr) {
        delete[] Data_Elements;  // Free the dynamically allocated array
        Data_Elements = nullptr; // Prevent accessing deleted data
    }

    // Step 4: Optionally, reset any other data structures or variables that need to be reset

    // Step 5: Update the UI to reflect changes
    update();  // This triggers a repaint of the window to reflect the removed elements

    // Step 6: (Optional) Add new elements or reinitialize UI after reset
    Initialize_UI();  // You can call another function to reinitialize your UI if needed
    Update_Lbl_Elements();
}


void MainWindow::on_pushButton_6_clicked()  //Quick Sort Button
{
    Quick_Sort(Data_Elements, 0, Total_Number_Of_Elements-1);
}

void MainWindow::Total_Elements_Setter(int num){
    Total_Number_Of_Elements=num;
}

void MainWindow::on_verticalSlider_valueChanged(int value) //Slider
{


    ui->label_Value->setText(QString::number(value));
    Total_Elements_Setter(value);
}

void MainWindow::Initialize_UI()
{
    int X = 20;
    int Width = 20;
    int Height = Random.bounded(0, height());

    // Allocate new Data_Elements array if needed
    Data_Elements = new int[Total_Number_Of_Elements];

    // Create new labels (or other UI elements)
    for (int i = 0; i < Total_Number_Of_Elements; i++) {
        Height = Random.bounded(0, height());

        QLabel* lbl_ele = new QLabel();
        lbl_ele->setStyleSheet("QLabel{background-color:rgb(0,0,0);}");
        lbl_ele->setMinimumSize(Width, Height);
        lbl_ele->setMaximumSize(Width, Height);
        lbl_ele->setGeometry(X, (height() - Height), Width, Height);
        lbl_ele->setObjectName("Lbl_Elements_" + QString::number(i + 1));
        lbl_ele->setParent(this);
        lbl_ele->setVisible(true);

        Lbl_Elements.append(lbl_ele);
        Data_Elements[i] = Height;

        X += Width + 5;
    }

    update();  // Repaint the window after adding new elements
}

