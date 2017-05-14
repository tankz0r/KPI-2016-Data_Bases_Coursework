/**************************************************************************/
/*! \file
 *  \brief  Declaration of \ref NCReportPrinter class
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
#ifndef NCREPORTPRINTER_H
#define NCREPORTPRINTER_H

#include <Qt>

#ifndef NCREPORT_NO_QPRINTER
#include <QPrinter>
#endif

#if (QT_VERSION >= 0x050300)
#include <QPageSize>
#endif

class NCReportPrinter
{
public:
    enum PrinterMode { ScreenResolution, PrinterResolution, HighResolution };
    enum Orientation { Portrait, Landscape };

#if (QT_VERSION >= 0x050000)
    enum PageSize {
        // Existing Qt sizes
        A4,
        B5,
        Letter,
        Legal,
        Executive,
        A0,
        A1,
        A2,
        A3,
        A5,
        A6,
        A7,
        A8,
        A9,
        B0,
        B1,
        B10,
        B2,
        B3,
        B4,
        B6,
        B7,
        B8,
        B9,
        C5E,
        Comm10E,
        DLE,
        Folio,
        Ledger,
        Tabloid,
        Custom,

        // New values derived from PPD standard
        A10,
        A3Extra,
        A4Extra,
        A4Plus,
        A4Small,
        A5Extra,
        B5Extra,

        JisB0,
        JisB1,
        JisB2,
        JisB3,
        JisB4,
        JisB5,
        JisB6,
        JisB7,
        JisB8,
        JisB9,
        JisB10,

        // AnsiA = Letter,
        // AnsiB = Ledger,
        AnsiC,
        AnsiD,
        AnsiE,
        LegalExtra,
        LetterExtra,
        LetterPlus,
        LetterSmall,
        TabloidExtra,

        ArchA,
        ArchB,
        ArchC,
        ArchD,
        ArchE,

        Imperial7x9,
        Imperial8x10,
        Imperial9x11,
        Imperial9x12,
        Imperial10x11,
        Imperial10x13,
        Imperial10x14,
        Imperial12x11,
        Imperial15x11,

        ExecutiveStandard,
        Note,
        Quarto,
        Statement,
        SuperA,
        SuperB,
        Postcard,
        DoublePostcard,
        Prc16K,
        Prc32K,
        Prc32KBig,

        FanFoldUS,
        FanFoldGerman,
        FanFoldGermanLegal,

        EnvelopeB4,
        EnvelopeB5,
        EnvelopeB6,
        EnvelopeC0,
        EnvelopeC1,
        EnvelopeC2,
        EnvelopeC3,
        EnvelopeC4,
        // EnvelopeC5 = C5E,
        EnvelopeC6,
        EnvelopeC65,
        EnvelopeC7,
        // EnvelopeDL = DLE,

        Envelope9,
        // Envelope10 = Comm10E,
        Envelope11,
        Envelope12,
        Envelope14,
        EnvelopeMonarch,
        EnvelopePersonal,

        EnvelopeChou3,
        EnvelopeChou4,
        EnvelopeInvite,
        EnvelopeItalian,
        EnvelopeKaku2,
        EnvelopeKaku3,
        EnvelopePrc1,
        EnvelopePrc2,
        EnvelopePrc3,
        EnvelopePrc4,
        EnvelopePrc5,
        EnvelopePrc6,
        EnvelopePrc7,
        EnvelopePrc8,
        EnvelopePrc9,
        EnvelopePrc10,
        EnvelopeYou4,

        // Last item, with commonly used synynoms from QPagedPrintEngine / QPrinter
        LastPageSize = EnvelopeYou4,
        NPageSize = LastPageSize,
        NPaperSize = LastPageSize,

        // Convenience overloads for naming consistency
        AnsiA = Letter,
        AnsiB = Ledger,
        EnvelopeC5 = C5E,
        EnvelopeDL = DLE,
        Envelope10 = Comm10E
    };
#else
    enum PageSize {
        // Existing Qt sizes
        A4,
        B5,
        Letter,
        Legal,
        Executive,
        A0,
        A1,
        A2,
        A3,
        A5,
        A6,
        A7,
        A8,
        A9,
        B0,
        B1,
        B10,
        B2,
        B3,
        B4,
        B6,
        B7,
        B8,
        B9,
        C5E,
        Comm10E,
        DLE,
        Folio,
        Ledger,
        Tabloid,
        Custom
    };
#endif

    typedef PageSize PaperSize;

#if (QT_VERSION >= 0x050000)
    enum OutputFormat { NativeFormat, PdfFormat };
#else
    enum OutputFormat { NativeFormat, PdfFormat, PostScriptFormat };
#endif

    enum PageOrder   { FirstPageFirst,
                       LastPageFirst };

    enum ColorMode   { GrayScale,
                       Color };

    enum PrintRange { AllPages, Selection, PageRange, CurrentPage };

    enum Unit {
        Millimeter,
        Point,
        Inch,
        Pica,
        Didot,
        Cicero,
        DevicePixel
    };

    enum DuplexMode {
        DuplexNone = 0,
        DuplexAuto,
        DuplexLongSide,
        DuplexShortSide
    };


    explicit NCReportPrinter();
    ~NCReportPrinter();

#ifndef NCREPORT_NO_QPRINTER
    static QPrinter::PrinterMode toQtPrinterMode(PrinterMode value);
    static QPrinter::Orientation toQtOrientation(Orientation value);
    static QPrinter::PaperSize toQtPaperSize(PaperSize value);
    static QPrinter::OutputFormat toQtOutputFormat(OutputFormat value);
    static QPrinter::ColorMode toQtColorMode(ColorMode value);
    static QPrinter::PrintRange toQtPrintRange(PrintRange value);
    static QPrinter::Unit toQtUnit(Unit value);
    static QPrinter::DuplexMode toQtDuplexMode(DuplexMode value);

    static NCReportPrinter::Orientation toNcrOrientation(QPrinter::Orientation value);
    static NCReportPrinter::PaperSize toNcrPaperSize(QPrinter::PaperSize value);

#endif

#if (QT_VERSION >= 0x050000)
    static QPageSize pageSize(PaperSize value);
#endif
};


#endif // NCREPORTPRINTER_H

