/****************************************************************************
*
*  Copyright (C) 2002-2014 Helta Ltd. - NociSoft Software Solutions
*  All rights reserved.
*  Author: Norbert Szabo
*  E-mail: office@nocisoft.com
*  Web: www.nocisoft.com
*
*  This file is part of the NCReport reporting software
*  Created: 2014.07.25. (nocisoft)
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

#ifndef NCREPORTDATASOURCERELATION_H
#define NCREPORTDATASOURCERELATION_H

#include <QList>
#include <QString>
#include <QHash>

class NCReportDataSource;
class NCReportEvaluator;
class NCReportDirector;
class NCReportDataSourceRelationPrivate;

class NCReportDataSourceRelation
{
public:
    //explicit NCReportDataSourceRelation(NCReportDataSourceRelation *parent = 0);
    explicit NCReportDataSourceRelation(NCReportDirector* director, NCReportDataSource *dataSource, NCReportDataSourceRelation *parent = 0);
    ~NCReportDataSourceRelation();

    bool insertDataSources( const QHash<QString, NCReportDataSource*>& dataSources );
    bool insertDataSource( NCReportDataSource* dataSource );
    void appendChild(NCReportDataSourceRelation *child);
    NCReportDataSourceRelation* find(NCReportDataSource* ds );

    NCReportDataSourceRelation *child(int row);
    int childCount() const;
    int currentChildIndex() const;
    int row() const;
    NCReportDataSourceRelation *parent();

    //void setDataSource( NCReportDataSource* dataSource );
    NCReportDataSource *dataSource();

    bool open();
    bool nextRecord( NCReportDataSource* ds);
    bool previousRecord(NCReportDataSource* ds);
    bool firstRecord(NCReportDataSource* ds);
    bool lastRecord(NCReportDataSource* ds);

    QString errorMsg() const;

    bool isValidChildIndex() const;
    QList<NCReportDataSourceRelation*> childItems() const;

private:
    NCReportDataSourceRelationPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(NCReportDataSourceRelation)
    Q_DISABLE_COPY(NCReportDataSourceRelation)
};

#endif // NCREPORTDATASOURCERELATION_H
