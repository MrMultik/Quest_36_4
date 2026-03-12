#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>
#include <QPainter>
#include <QPixmap>
#include <QBitmap>

class ColorfulCircle : public QWidget
{
public:
    ColorfulCircle(QWidget *parent = nullptr) : QWidget(parent)
    {
        mGreenCircle.load("green.png");
        mYellowCircle.load("yellow.png");
        mRedCircle.load("red.png");

        mCurrentCircle = mGreenCircle;

        setFixedSize(200, 200);

        // Создаем маску круга, чтобы виджет стал круглым
        QBitmap mask(width(), height());
        mask.fill(Qt::color0);
        QPainter p(&mask);
        p.setBrush(Qt::color1);
        p.setRenderHint(QPainter::Antialiasing);
        p.drawEllipse(0, 0, width(), height());
        setMask(mask);
    }

    QSize minimumSizeHint() const override { return QSize(100, 100); }

    void setGreen() { mCurrentCircle = mGreenCircle; update(); }
    void setYellow() { mCurrentCircle = mYellowCircle; update(); }
    void setRed() { mCurrentCircle = mRedCircle; update(); }

protected:
    void paintEvent(QPaintEvent *) override
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
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
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(10);

    ColorfulCircle *circle = new ColorfulCircle;

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);

    layout->addWidget(circle, 0, Qt::AlignCenter);
    layout->addWidget(slider);

    QObject::connect(slider, &QSlider::valueChanged, [circle](int value){
        if (value <= 33) circle->setGreen();
        else if (value <= 66) circle->setYellow();
        else circle->setRed();
    });

    window.show();
    return app.exec();
}
