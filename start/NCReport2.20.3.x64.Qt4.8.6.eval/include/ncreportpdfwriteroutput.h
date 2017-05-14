/**************************************************************************/
/*! \file
 *  \brief  Declaration of \ref NCReportPdfWriterOutput class
 *
 *  \author Norbert Szabo
 *
 *  \date   2015.12.08.
 *
 *  \copyright (c) 2015 Helta Ltd - NociSoft Software Solutions
 *  \copyright All rights reserved.
 *
 *  \remark Web: https://www.nocisoft.com
 *  \remark Email: office@nocisoft.com
 **************************************************************************/
#ifndef NCREPORTPDFWRITEROUTPUT_H
#define NCREPORTPDFWRITEROUTPUT_H

#include "ncreportoutput.h"
#include "ncreport_global.h"

#if QT_VERSION >= 0x050000

QT_BEGIN_NAMESPACE
class QPdfWriter;
class QIODevice;
QT_END_NAMESPACE

class NCREPORTSHARED_EXPORT NCReportPdfWriterOutput : public NCReportOutput
{
    Q_OBJECT
public:
    NCReportPdfWriterOutput(const QString &fileName, QObject* parent=0 );
    NCReportPdfWriterOutput(QIODevice* device, QObject* parent=0 );
    ~NCReportPdfWriterOutput();

    void setDpi(int dpi);
    int dpi() const;

    bool setup();
    void cleanup();
    void begin();
    void end();
    void newPage();
    int resolution() const;
    void setResolution( int dpi );
    QPaintDevice* device() const;

private:
    QPdfWriter *m_pdfWriter;
    int m_dpi;
};

#else
class NCREPORTSHARED_EXPORT NCReportPdfWriterOutput : QObject
{
    Q_OBJECT
public:
    NCReportPdfWriterOutput(QObject* parent=0);
    ~NCReportPdfWriterOutput();
};
#endif

#endif // NCREPORTPDFWRITEROUTPUT_H

