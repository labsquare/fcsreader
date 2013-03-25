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

#ifndef PROPERTYWIDGETCONTAINER_H
#define PROPERTYWIDGETCONTAINER_H

#include <QWidget>
#include <QtGui>
class PropertyWidgetContainer : public QWidget
{
    Q_OBJECT
public:
    explicit PropertyWidgetContainer(QWidget *parent = 0);
    

public slots:
    void setTitle(const QString& title);
    void setIcon(const QIcon& icon);
    void setWidget(QWidget * widget);
    void expand(bool expand = true);
    void collapse(bool collapse = true);



private:
    QWidget * mContent;
    QLabel * mTitleLabel;
    QLabel * mIconLabel;
    QToolButton * mToolButton;
    
};

#endif // PROPERTYWIDGETCONTAINER_H
