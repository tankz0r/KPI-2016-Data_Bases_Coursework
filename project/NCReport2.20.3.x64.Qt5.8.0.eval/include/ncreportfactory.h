/****************************************************************************
*
*  Copyright (C) 2002-2016 Helta Ltd. - NociSoft Software Solutions
*  All rights reserved.
*  Author: Norbert Szabo
*  E-mail: office@nocisoft.com
*  Web: www.nocisoft.com
*  Created at 2016. 02. 29.
*  File: ncreportfactory.h
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
#ifndef NCREPORTFACTORY_H
#define NCREPORTFACTORY_H

#include "ncreport_global.h"

class QObject;
class NCReport;

class NCREPORTSHARED_EXPORT NCReportFactory
{
public:
    NCReportFactory();
    virtual ~NCReportFactory();

    virtual NCReport* createReport(QObject *parent);
};

#endif // NCREPORTFACTORY_H
