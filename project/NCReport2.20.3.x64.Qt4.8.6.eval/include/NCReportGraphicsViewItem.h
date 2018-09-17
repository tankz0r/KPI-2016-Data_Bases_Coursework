/****************************************************************************
*
*  Copyright (C) 2002-2017 Helta Ltd. - NociSoft Software Solutions
*  All rights reserved.
*  Author: Norbert Szabo
*  E-mail: office@nocisoft.com
*  Web: www.nocisoft.com
*  Created at 2017-04-13 
*  File: NCReportGraphicsViewItem.h    
*
*  This file is part of the NCReport reporting software
*
*  Licensees holding a valid NCReport License Agreement may use this
*  file in accordance with the rights, responsibilities, and obligations
*  contained therein. Please consult your licensing agreement or contact
*  office@nocisoft.com if any conditions of this licensing are not clear
*  to you.
*
*  This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
*  WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
****************************************************************************/
#ifndef NCREPORTGRAPHICSVIEWITEM_H
#define NCREPORTGRAPHICSVIEWITEM_H

#include "ncreportitem.h"

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

class NCReportGraphicsViewItemPrivate;
class NCReportDef;
class QGraphicsView;

class NCREPORTSHARED_EXPORT NCReportGraphicsViewItem : public NCReportItem
{
public:
    NCReportGraphicsViewItem( NCReportDef* rdef, QGraphicsItem* parent =0 );
    ~NCReportGraphicsViewItem();

    bool read( NCReportXMLReader* reader );
    bool write( NCReportXMLWriter* writer );
    void setDefaultForEditor();

    void paint( NCReportOutput* output, const QPointF& targetMMPos );
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void paintEditor(QPainter *painter, const QRectF &rect);

    QString classID() const;
    void setClassID( const QString& id );

    void updateValue(NCReportOutput *output, NCReportEvaluator *evaluator);

    bool isDynamic() const;
    bool isValidLocation(int sectionType) const;
    QGraphicsView *graphicsView() const;

private:
    NCReportGraphicsViewItemPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(NCReportGraphicsViewItem)
    Q_DISABLE_COPY(NCReportGraphicsViewItem)
};


#endif

