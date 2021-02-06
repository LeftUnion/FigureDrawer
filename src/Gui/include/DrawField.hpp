#ifndef DRAW_FIELD_HPP
#define DRAW_FIELD_HPP

#include <QGraphicsView>

#include <Figure.hpp>
#include <vector>

class DrawField : public QGraphicsView
{
    public:
        DrawField(QWidget* parent);

    protected slots:
        void mousePressEvent(QMouseEvent *event);

    private:
        void refreshAll();

    private:
        std::vector<std::pair<Geometry::Point, std::vector<Geometry::Point>>> mFigures;
        std::shared_ptr<QGraphicsScene> mScene;

};

#endif // DRAW_FIELD_HPP
