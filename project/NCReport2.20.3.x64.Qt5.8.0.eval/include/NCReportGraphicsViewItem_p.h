/****************************************************************************
*
*  Copyright (C) 2002-2017 Helta Ltd. - NociSoft Software Solutions
*  All rights reserved.
*  Author: Norbert Szabo
*  E-mail: office@nocisoft.com
*  Web: www.nocisoft.com
*  Created at 2017-04-13 
*  File: NCReportGraphicsViewItem_p.h    
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
#ifndef NCREPORTGRAPHICSVIEWITEMPRIVATE_H
#define NCREPORTGRAPHICSVIEWITEMPRIVATE_H

#include "NCReportGraphicsViewItem.h"

class NCReportGraphicsViewItemPrivate : public NCReportItemData
{
public:
    NCReportGraphicsViewItemPrivate( NCReportGraphicsViewItem *parent);
    ~NCReportGraphicsViewItemPrivate();

private:
    NCReportGraphicsViewItem * const q_ptr;
    Q_DECLARE_PUBLIC(NCReportGraphicsViewItem)

public:
    QString classID;
};

#endif //NCREPORTGRAPHICSVIEWITEMPRIVATE_H


