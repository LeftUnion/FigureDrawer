#ifndef DRAW_FIELD_HPP
#define DRAW_FIELD_HPP

#include <QGraphicsView>

#include <Figure.hpp>
#include <vector>

/*!
 * \brief The DrawField class - класс, определяющий поле для рисования
 */
class DrawField : public QGraphicsView
{
    public:
        /*!
         * \brief DrawField - конструктор, устанавливающий поле для рисования.
         * \param parent - родитель, на который накладывается поле.
         */
        DrawField(QWidget* parent);

    protected slots:
        /*!
         * \brief mousePressEvent - обрабает нажатия мыши
         * \param event - клик мышки
         */
        void mousePressEvent(QMouseEvent *event) override final;

        /*!
         * \brief keyPressEvent - обрабатывет нажатия на кнопки клавиатуры
         * \param event - нажатие на кнопку клавиатуры
         */
        void keyPressEvent(QKeyEvent *event) override final;

    private:
        /*!
         * \brief refreshAll - обновляет поле для рисования
         */
        void refreshAll();

    private:
        /*!
         * \brief mFigures - вектор, хранящий объекты класса Figure
         */
        std::vector<Geometry::Figure> mFigures;

        /*!
         * \brief mScene - указатель на поле для рисования
         */
        std::shared_ptr<QGraphicsScene> mScene;

};

#endif // DRAW_FIELD_HPP
