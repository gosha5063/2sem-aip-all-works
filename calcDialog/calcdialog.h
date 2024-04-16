#ifndef CALCDIALOG_H
#define CALCDIALOG_H

#include <QDialog>
#include <QDialog>
#include <QLineEdit>
#include <QSignalMapper>

QT_BEGIN_NAMESPACE
namespace Ui {
class CalcDialog;
}
QT_END_NAMESPACE

class CalcDialog : public QDialog
{
    Q_OBJECT

public:
    CalcDialog(QWidget *parent = nullptr);
    ~CalcDialog();

private:
    Ui::CalcDialog *ui;
protected:
    QSignalMapper * m_pSignalMapper;
    QLineEdit * m_pLineEdit;
    double m_Val; ///< Значение, с которым будет выполнена операция
    int m_Op; ///< Код нажатой операции
    bool m_bPerf;///< Операция была выполнена. Надо очистить поле ввода
    void initNum();///< Инициализировать переменные, связанные с вычислениями
    double getNumEdit(); ///< Получить число из m_pLineEdit
    void setNumEdit( double ); ///< Отобразить число в m_pLineEdit
    /// Вычислить предыдущую операцию
    ///(в бинарных операциях был введен второй операнд)
    void calcPrevOp( int curOp );
    void calcTrig( int curOp );
    /// Проверить, была ли выполнена операция при нажатии на цифровую клавишу
    /// Если операция выполнена, значит m_pLineEdit необходимо очистить
    void checkOpPerf();
private slots:
    /// Слот для обработки нажатий всех кнопок
    void clicked(int id);
};
#endif // CALCDIALOG_H
