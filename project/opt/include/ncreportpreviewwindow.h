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
#ifndef NCREPORTPREVIEWWINDOW_H
#define NCREPORTPREVIEWWINDOW_H

#include "ncreportpageoption.h"
#include "ncreportpreviewpagecontainer.h"
#include "ncreport_global.h"

#include <QMainWindow>
#include <QCloseEvent>
#include <QScrollArea>

class NCReportPreviewPageContainer;
class NCReportPreviewOutput;
class NCReportPreviewScrollArea;
class NCReportPreviewWindowPrivate;

QT_BEGIN_NAMESPACE
class QWidget;
class QAction;
class QActionGroup;
class QComboBox;
class QMenu;
class QTextEdit;
class QSpinBox;
class QProgressDialog;
class QSettings;
class QPrinter;
QT_END_NAMESPACE

/*!
Main window class for Print preview. Represents the contents of an NCReportPreviewOutput object
 */
class NCREPORTSHARED_EXPORT NCReportPreviewWindow : public QMainWindow
{
      Q_OBJECT
public:
    NCReportPreviewWindow(QWidget *parent = 0, Qt::WindowFlags flags=0, const QString &orgName = QString(), const QString &appName = QString() );
    ~NCReportPreviewWindow();

    enum PagePosition { Top, Bottom, Off };

    void setOutput( NCReportPreviewOutput* );
    void setReport( NCReport* );
    NCReport* report() const;
    void setDefaultOutputDir( const QString& dir );
    QString defaultOutputDir() const;

    void setPrinterName( const QString& printer );
    QString printerName() const;
    void setUsePrintDialog( bool set );
    bool usePrintDialog() const;

    //bool setPageIMFData(QIODevice *device, const QString& imfdata);
    int pageCount() const;
    int reportCount() const;
    NCReportPreviewPageContainer::ShowType showType() const;
    void setCurrentPage( int pageno, NCReportPreviewPageContainer::ShowType type = NCReportPreviewPageContainer::Single );

    QAction* actionPrint() const;
    QAction* actionPdf() const;
    QAction* actionSvg() const;
    QAction* actionXls() const;

    QAction* actionClose() const;

    QAction* actionFirstPage() const;
    QAction* actionNextPage() const;
    QAction* actionPreviousPage() const;
    QAction* actionLastPage() const;
    QAction* actionGoToPage() const;
    QAction* actionZoomIn() const;
    QAction* actionZoomOut() const;
    QAction* actionZoomOff() const;
    QAction* actionNextReport() const;
    QAction* actionPreviousReport() const;
    QAction* actionViewSingleMode() const;
    QAction* actionViewDoubleMode() const;
    QAction* actionViewContinousMode() const;
    bool donePrint() const;
    bool donePDF() const;
    bool doneSVG() const;
    bool doneXLS() const;

    QToolBar *toolBarFile();
    QToolBar *toolBarView();
    QToolBar *toolBarNavigation();

    void exec();

    void setDefaultOutputFileName( const QString& fileName );
    QString defaultOutputFileName() const;

    void setSettingsData( const QString& orgName, const QString& appName );

signals:
    void runPrinterDone();
    void runPdfDone();
    void runSvgDone();
    void runXlsDone();

public slots:
    virtual void nextPage( const PagePosition = Top );
    virtual void prevPage( const PagePosition = Top );
    virtual void firstPage( const PagePosition = Top );
    virtual void lastPage( const PagePosition = Top );

    virtual void open();
    virtual bool save();
    virtual bool saveAs();
    virtual void about();
    virtual void documentWasModified();
    virtual void activatePrint();
    virtual void activatePdf();
    virtual void activateSvg();
    virtual void activateXls();

    virtual void zoomChanged( const QString & s);
    virtual void zoomChanged();
    virtual void zoomChanged( int scaleFactor );
    virtual void zoomPlus();
    virtual void zoomMinus();
    virtual void zoom1();

    virtual void gotoPage();
    virtual void gotoPage( int pageno );

    virtual void nextReport();
    virtual void prevReport();
    virtual void sliderMoved(int value);

protected slots:
    virtual void loadPage( int pageno );
    virtual void setViewSingle();
    virtual void setViewDouble();
    virtual void setViewContinous();
    virtual void viewChange(QAction*);

    //TESTS
    virtual void testPrint1();
    virtual void testPrint2();
    virtual void addTestItems();
    virtual void clearPage();

protected:
    virtual void closeEvent(QCloseEvent *event);
    virtual void loadPagePrivate( int pageno, const PagePosition );

private:
    Q_DECLARE_PRIVATE(NCReportPreviewWindow)
    QScopedPointer<NCReportPreviewWindowPrivate> const d_ptr;

private:
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();

    void readSettings();
    void readSettings( QSettings* settings );
    void writeSettings();
    void writeSettings( QSettings* settings );
    bool maybeSave();
    void loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void refreshActions();
    void updateZoomInfo();
    void showEvent(QShowEvent *event);
    void initPrinter( QPrinter* );
    void initProgress( QProgressDialog* );
    void printPicturePages( QPrinter* );
    void zoom( qreal );

    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);
    QString genOutputFileName(const QString &extension) const;
};


class NCReportPreviewScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    NCReportPreviewScrollArea( NCReportPreviewWindow * parent = 0 );
    ~NCReportPreviewScrollArea();

protected:
    void keyPressEvent( QKeyEvent* );

private:
    NCReportPreviewWindow* pWindow;
};


#endif
