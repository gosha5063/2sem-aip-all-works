#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QResizeEvent>
#include <QGraphicsTextItem>
#include <QPen>

class HistogramView : public QGraphicsView {
    Q_OBJECT

public:
    explicit HistogramView(QWidget* parent = nullptr) : QGraphicsView(parent) {
        scene = new QGraphicsScene(this);
        setScene(scene);
    }

    // Обновленный метод setData для работы с дополнительной информацией, такой как подписи.
    void setData(const QVector<double>& dataValues, const QVector<QString>& labels) {
        scene->clear(); // Очистка сцены перед добавлением новых элементов

        Q_ASSERT(dataValues.size() == labels.size()); // Убедитесь, что каждому значению соответствует подпись

        double maxValue = *std::max_element(dataValues.begin(), dataValues.end()); // Поиск максимального значения

        int numBars = dataValues.size();
        double width = scene->width() / numBars - 5; // 5 пикселей для отступа между столбцами

        for (int i = 0; i < numBars; ++i) {
            double value = dataValues.at(i);
            double height = (value / maxValue) * (scene->height() - 30); // 30 пикселей отступа внизу для подписей

            // Создание и позиционирование столбца гистограммы
            QGraphicsRectItem* rect = scene->addRect(0, 0, width, height, QPen(), QBrush(Qt::blue));
            rect->setPos(i * (width + 5), scene->height() - height - 30);

            // Добавление подписи к столбцу
            QGraphicsTextItem* label = scene->addText(labels.at(i));
            label->setPos(i * (width + 5) + (width / 2) - (label->boundingRect().width() / 2),
                          scene->height() - 25); // Выравниваем по центру относительно столбца
        }
    }

protected:
    void resizeEvent(QResizeEvent* event) override {
        QGraphicsView::resizeEvent(event);
        scene->setSceneRect(QRect(QPoint(0, 0), event->size()));

        // Опционально, можно вызвать setData здесь с последними данными, чтобы перестроить гистограмму
        // на основе нового размера. Необходимо хранить последние данные в классе.
    }

private:
    QGraphicsScene* scene;
};
