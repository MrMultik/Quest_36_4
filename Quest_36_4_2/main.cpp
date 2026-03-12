#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>
#include <QPainter>
#include <QPixmap>

class ColorfulCircle : public QWidget
{
public:
    ColorfulCircle(QWidget *parent = nullptr) : QWidget(parent)
    {
        mGreenCircle.load("green.png");
        mYellowCircle.load("yellow.png");
        mRedCircle.load("red.png");

        mCurrentCircle = mGreenCircle;
    }

    QSize minimumSizeHint() const override
    {
        return QSize(100, 100);
    }

    void setGreen()
    {
        mCurrentCircle = mGreenCircle;
        update();
    }

    void setYellow()
    {
        mCurrentCircle = mYellowCircle;
        update();
    }

    void setRed()
    {
        mCurrentCircle = mRedCircle;
        update();
    }

protected:
    void paintEvent(QPaintEvent *) override
    {
        QPainter painter(this);
        painter.drawPixmap(rect(), mCurrentCircle);
    }

private:
    QPixmap mGreenCircle;
    QPixmap mYellowCircle;
    QPixmap mRedCircle;

    QPixmap mCurrentCircle;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setFixedSize(200, 250);

    QVBoxLayout *layout = new QVBoxLayout(&window);

    ColorfulCircle *circle = new ColorfulCircle;

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);

    layout->addWidget(circle);
    layout->addWidget(slider);

    QObject::connect(slider, &QSlider::valueChanged,
                     [circle](int newValue)
                     {
                         if (newValue <= 33)
                             circle->setGreen();
                         else if (newValue <= 66)
                             circle->setYellow();
                         else
                             circle->setRed();
                     });

    window.show();

    return app.exec();
}
