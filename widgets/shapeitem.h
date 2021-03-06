/***************************************************************************
**                                                                        **
**  FcsViewer, a simple cytometry data viewer made with Qt4 and           **
**  customplot made by Emanuel Eichhammer                                 **
**  Copyright (C) 2013 Sacha Schutz                                       **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author : Sacha Schutz                                        **
**           Website: http://www.labsquare.org                            **
**           Email  : sacha@labsquare.org                                 **
**           Date   : 12.03.12                                            **
****************************************************************************/

#ifndef SHAPEITEM_H
#define SHAPEITEM_H

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include "gate.h"
class ShapeItem : public QGraphicsObject
{
    Q_OBJECT
public:
    enum Mode {ShapeMode, NodeMode};
    ShapeItem(const QPolygon& polygon = QPolygon(),QGraphicsItem * parent = 0);
    ~ShapeItem();
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual QRectF boundingRect() const;
    void setMode(Mode mode);
    void setColor(const QColor& color);
    const QColor& color() const;

    void setPolygon(const QPolygon& polygon);
    const QPolygon& polygon() const;
    Mode mode() {return mCurrentMode;}


    void setGate(Gate * gate);
    Gate * gate() const;
signals:
    void changed();

public slots:
    void change();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

     QPolygon normalize(const QPolygon& poly);


private:
    QPolygon mPolygon;
    QPolygon mEditPolygon;
    QColor mColor;
    bool mIsEditing;
    Mode mCurrentMode;
    int mCurrentPointIndex;
    Gate * mGate;
};

#endif // SHAPEITEM_H
