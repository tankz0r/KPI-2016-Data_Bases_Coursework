/****************************************************************************
*
*  Copyright (C) 2002-2009 Helta Kft. / NociSoft Software Solutions
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
#ifndef NCREPORTQTPREVIEWOUTPUT_H
#define NCREPORTQTPREVIEWOUTPUT_H

#ifndef NCREPORT_NO_QPRINTER

#include "ncreportprinteroutput.h"

QT_BEGIN_NAMESPACE
class QPrintPreviewDialog;
class QPrintPreviewWidget;
QT_END_NAMESPACE

/*!
Qt Print preview output class
*/
class NCREPORTSHARED_EXPORT NCReportQtPreviewOutput : public NCReportPrinterOutput
{
    Q_OBJECT
public:
    NCReportQtPreviewOutput( bool createPreviewDialog, NCReportPrinter::PrinterMode quality, int dpi=-1, QObject* parent=0);
    NCReportQtPreviewOutput(QObject* parent=0);
    virtual ~NCReportQtPreviewOutput();

    void setPreviewWidget( QPrintPreviewWidget* widget);

    virtual bool setup();
    QPrintPreviewDialog *dialog();
    void setReport( NCReport* report);
    void begin();
    void end();

private slots:
    void printPreview(QPrinter* printer);

private:
    QPrintPreviewDialog *m_previewDialog;
    QPrintPreviewWidget *m_previewWidget;
    NCReport *m_report;
    int m_copies;
    bool m_deleteWidgets;
};

#endif

#endif // NCREPORTQTPREVIEWOUTPUT_H
