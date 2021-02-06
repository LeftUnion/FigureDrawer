#include <DrawField.hpp>
#include <FigureDrawer.hpp>

#include <QMouseEvent>

DrawField::DrawField(QWidget *parent) : QGraphicsView(parent)
{
    resize(parent->width(), parent->height());
    setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
}

void DrawField::mousePressEvent(QMouseEvent *event)
{
    static int i = 3;
    Geometry::Figure figure({(size_t)event->x(), (size_t)event->y()}, i);
    mFigures.push_back({{(size_t)event->x(), (size_t)event->y()}, *figure.getPoints()});
    refreshAll();
    i++;
}

void DrawField::refreshAll()
{
    mScene.reset(new QGraphicsScene(0, 0, width(), height()));
    for(auto figure : mFigures)
    {
        FigureDrawer::drawFigure(mScene, figure.second);
    }

    setScene(mScene.get());
}
//std::vector<std::pair<Geometry::Point, std::vector<Geometry::Point>>> figures;
