/****************************************************************************
*
*  Copyright (C) 2002-2008 Helta Kft. / NociSoft Software Solutions
*  All rights reserved.
*  Author: Norbert Szabo
*  E-mail: nszabo@helta.hu, info@nocisoft.com
*  Web: www.nocisoft.com
*
*  This file is part of the NCReport reporting software
*
*  Licensees holding a valid NCReport License Agreement may use this
*  file in accordance with the rights, responsibilities, and obligations
*  contained therein. Please consult your licensing agreement or contact
*  nszabo@helta.hu if any conditions of this licensing are not clear
*  to you.
*
*  This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
*  WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
****************************************************************************/
#ifndef NCREPORTFIELDITEM_H
#define NCREPORTFIELDITEM_H

#include "ncreportlabelitem.h"
#include "ncreport_global.h"
class NCReportDataSource;
class NCReportFieldData;

/*!
Field item class
 */
class NCREPORTSHARED_EXPORT NCReportFieldItem : public NCReportLabelItem
{
public:
    NCReportFieldItem( NCReportDef* rdef, QGraphicsItem* parent =0 );
    ~NCReportFieldItem();

    enum SwapMode { OriginalValue=0 ,LastValue };

    int precision() const;
    void setPrecision( int prec );
    int fieldWidth() const;
    void setFieldWidth( int fw );
    char format() const;
    void setFormat( char f );
    bool isLocalized() const;
    void setLocalized( bool set );
    bool isNumBlankIfZero() const;
    void setNumBlankIfZero( bool set );
    bool isNumFormat() const;
    void setNumFormat( bool set );
    int numCharacters() const;
    void setNumberOfCharacters( int num );
    QString arg() const;
    void setArg( const QString& arg );
    QString dateFormat() const;
    void setDateFormat( const QString& df );

    NCReportDataSource* dataSource() const;
    void setDataSource( NCReportDataSource* ds );

    int dataColumn() const;
    void setDataColumn( int column );
    int dataRole() const;
    void setDataRole( int role );

    bool read( NCReportXMLReader* reader );
    bool write( NCReportXMLWriter* writer);
    void setDefaultForEditor();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void paint( NCReportOutput* o, const QPointF& mPos );
    void adjustSize();
    void adjustSize(NCReportOutput*output);
    bool isEmpty() const;

    //void swapLastValue( SwapMode );
    void updateValue(NCReportOutput*, NCReportEvaluator *evaluator);
    QList<int> availableSourceTypes() const;

    void setUseDatasourceAppearanceRoles( bool set );
    bool useDataSourceAppearanceRoles() const;

    //void paint( NCReportOutput* );
protected:
    void readProps( NCReportXMLReader* r);
    void writeProps( NCReportXMLWriter* w);
};


#endif
