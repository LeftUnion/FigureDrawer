#ifndef DRAW_FIGURE_HPP
#define DRAW_FIGURE_HPP

#include <Figure.hpp>

#include <QGraphicsScene>
#include <QGraphicsView>

#include <memory>
#include <vector>

/*!
 * \brief The FigureDrawer class - класс, отвечающий за отрисовку фигур
 */
class FigureDrawer
{
    public:
        /*!
         * \brief drawFigure - рисует фигуру по точкам
         * \param scene - указатель на поле для рисвоания
         * \param vertexes - вектор точек фигуры
         */
        static void drawFigure(std::shared_ptr<QGraphicsScene> scene,
                               std::vector<Geometry::Point>    vertexes);
};

#endif // DRAW_FIGURE_HPP
