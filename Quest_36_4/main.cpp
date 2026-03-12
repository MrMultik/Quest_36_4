#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>
#include <QPainter>

class ColorfulCircle : public QWidget
{
public:
    ColorfulCircle(QWidget *parent = nullptr) : QWidget(parent)
    {
        mColor = Qt::green;
    }

    QSize minimumSizeHint() const override
    {
        return QSize(100, 100);
    }

    void setGreen()
    {
        mColor = Qt::green;
        update();
    }

    void setYellow()
    {
        mColor = Qt::yellow;
        update();
    }

    void setRed()
    {
        mColor = Qt::red;
        update();
    }

protected:
    void paintEvent(QPaintEvent *) override
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        painter.setBrush(mColor);
        painter.drawEllipse(rect());
    }

private:
    QColor mColor;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setFixedSize(200, 250);

    QVBoxLayout *layout = new QVBoxLayout(&window);

    ColorfulCircle *circle = new ColorfulCircle;
    QSlider *slider = new QSlider(Qt::Vertical);

    slider->setRange(0, 100);

    layout->addWidget(circle);
    layout->addWidget(slider);

    QObject::connect(slider, &QSlider::valueChanged,
                     [slider, circle](int value)
                     {
                         if (value <= 33)
                             circle->setGreen();
                         else if (value <= 66)
                             circle->setYellow();
                         else
                             circle->setRed();
                     });

    window.show();

    return app.exec();
}
