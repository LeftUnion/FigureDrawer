#ifndef DRAW_FIGURE_HPP
#define DRAW_FIGURE_HPP

#include <Figure.hpp>

#include <QGraphicsScene>
#include <QGraphicsView>

#include <memory>
#include <vector>

class FigureDrawer
{
    public:
        static void drawFigure(std::shared_ptr<QGraphicsScene> scene,
                           std::vector<Geometry::Point>   vertexes);
};

#endif // DRAW_FIGURE_HPP
