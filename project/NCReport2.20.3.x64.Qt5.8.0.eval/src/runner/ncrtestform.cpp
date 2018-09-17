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
#include "ncrtestform.h"
#include "ncreport.h"
#include "ncreportprinteroutput.h"
#include "ncreportpdfoutput.h"
#include "ncreportpreviewoutput.h"
#include "info.h"
#include "ncreportpreviewwindow.h"
#include "ncreportutils.h"

#include <QTableWidget>
#include <QHeaderView>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSettings>
#include <QFileDialog>
#include <QFileInfo>
#include <QApplication>
#include <QSqlError>
#include <QCloseEvent>
#include <QProgressDialog>

#define NCRTESTER_SETTINGS_ORG	"NociSoft"
#define NCRTESTER_SETTINGS_APP	"NCReportTester"

NCRTestForm::NCRTestForm(QWidget* parent) : QWidget( parent ), Ui::NCRTestFormUI(),
  report(0), progress(0), m_renderer(0)
{
    setupUi(this);
    buttonBox->button(QDialogButtonBox::Ok)->setText(tr("Run report"));
    tableParams->setAlternatingRowColors( true );
    tableParams->setColumnWidth(0,200);
    tableParams->setColumnWidth(1,350);
    //tableParams->verticalHeader()->setDefaultSectionSize( 21 );
    setWindowTitle( tr( "NCReport Tester v%1" ).arg( NCREPORTAPP_VERSION ) );

    connect( cbUseDBConnect, SIGNAL(toggled(bool)), this, SLOT(setDbPanelEnabled(bool)) );
    connect( buttonBox->button(QDialogButtonBox::Ok), SIGNAL( clicked() ), this, SLOT( run() ) );
    connect( buttonBox->button(QDialogButtonBox::Close), SIGNAL( clicked() ), this, SLOT( close() ) );
    connect( btnAdd, SIGNAL( clicked() ), this, SLOT( addParam() ) );
    connect( btnRemove, SIGNAL( clicked() ), this, SLOT( removeParam() ) );
    connect( btnSelectFile, SIGNAL( clicked() ), this, SLOT( selectFiles() ) );

    loadDefaults();
}

NCRTestForm::~NCRTestForm()
{
}

/*$SPECIALIZATION$*/
void NCRTestForm::setReport(NCReport *r )
{
    Q_UNUSED(r)
}

void NCRTestForm::setDbPanelEnabled( bool enable )
{
    comboDriver->setEnabled(enable);
    leHost->setEnabled(enable);
    leDB->setEnabled(enable);
    leUser->setEnabled(enable);
    lePassw->setEnabled(enable);
    leConnID->setEnabled(enable);
}

void NCRTestForm::selectFiles()
{
    QFileInfo fi( teReportFiles->toPlainText() );
    filelist = QFileDialog::getOpenFileNames( this, tr("Select report file(s)"), fi.absoluteFilePath(), tr("Reports (*.xml *.ncr)") );
    if ( filelist.isEmpty() )
        return;

    QString filenames;
    for (int i=0; i<filelist.size(); ++i ) {
        filenames += filelist.at(i) +";";
    }
    filenames.truncate( filenames.length()-1 );
    setReportFile(filenames);
}

void NCRTestForm::addParam()
{
    addParam("","");
    int rows = tableParams->rowCount();
    if ( rows>0 )
        tableParams->setCurrentCell( rows-1, 0 );
    tableParams->setFocus();
}


void NCRTestForm::addParam( const QString& name, const QString& value )
{
    int rows = tableParams->rowCount();
    tableParams->setRowCount( rows+1 );

    QTableWidgetItem *newItem;

    newItem = new QTableWidgetItem(name);
    tableParams->setItem(rows, 0, newItem);

    newItem = new QTableWidgetItem(value);
    tableParams->setItem(rows, 1, newItem);
}

void NCRTestForm::setRenderer(NCReportGraphRenderer *renderer)
{
    m_renderer = renderer;
}

QString NCRTestForm::reportFile() const
{
    return teReportFiles->toPlainText();
}

void NCRTestForm::removeParam()
{
    int i = tableParams->currentRow();

    QSettings settings(NCRTESTER_SETTINGS_ORG, NCRTESTER_SETTINGS_APP);
    settings.remove( "ncreporttest/parameters/"+tableParams->item(i,0)->text() );
    tableParams->removeRow(i);
}

void NCRTestForm::saveDefaults( )
{
    QSettings settings(NCRTESTER_SETTINGS_ORG, NCRTESTER_SETTINGS_APP);
    //settings.setPath( "NCReport", "TestForm" );

    settings.setValue( "ncreporttest/usedbconn", cbUseDBConnect->isChecked() );
    settings.setValue( "ncreporttest/connid", leConnID->text() );
    settings.setValue( "ncreporttest/driver", comboDriver->currentIndex() );
    settings.setValue( "ncreporttest/host", leHost->text() );
    settings.setValue( "ncreporttest/DB", leDB->text() );
    settings.setValue( "ncreporttest/user", leUser->text() );
    settings.setValue( "ncreporttest/passw", lePassw->text() );

    settings.setValue( "ncreporttest/reportfile", reportFile() );
    // paramters
    for (int i=0; i<tableParams->rowCount(); ++i )
        settings.setValue( "ncreporttest/parameters/"+tableParams->item(i,0)->text(), tableParams->item(i,1)->text() );
}

void NCRTestForm::loadDefaults( )
{
    QSettings settings(NCRTESTER_SETTINGS_ORG, NCRTESTER_SETTINGS_APP);

    cbUseDBConnect->setChecked(settings.value( "ncreporttest/usedbconn", false ).toBool());
    leConnID->setText(settings.value( "ncreporttest/connid", "" ).toString());
    comboDriver->setCurrentIndex(settings.value( "ncreporttest/driver", "0" ).toInt());
    leHost->setText(settings.value( "ncreporttest/host", "localhost" ).toString());
    leDB->setText(settings.value( "ncreporttest/db", "test" ).toString());
    leUser->setText(settings.value( "ncreporttest/user", "root" ).toString());
    lePassw->setText(settings.value( "ncreporttest/passw", "" ).toString());
    teReportFiles->setPlainText(settings.value( "ncreporttest/reportfile", "" ).toString());
    settings.beginGroup("ncreporttest/parameters");
    QStringList keys = settings.childKeys();

    QStringList::const_iterator it;
    for (it = keys.constBegin(); it != keys.constEnd(); ++it) {
        QString name = *it;
        QString value = settings.value(*it).toString();
        addParam( name, value );
    }

    if ( tableParams->rowCount() == 0 ) {
//        addParam( "documentPK", "10367" );
//        addParam( "prodFilt", "%" );
    }

    settings.endGroup();
    setDbPanelEnabled(cbUseDBConnect->isChecked());
}


void NCRTestForm::closeEvent( QCloseEvent* ce )
{
    saveDefaults();
    ce->accept();
}


bool NCRTestForm::connectToDatabase()
{
    // SQL/DATABASE CONNECTION
    QSqlDatabase defaultDB = QSqlDatabase::addDatabase(comboDriver->currentText(), leConnID->text() );
    if ( !defaultDB.isValid() ) {
            //fprintf( stderr, "Error: Could not load database driver. \n" );
        QApplication::restoreOverrideCursor();
        QMessageBox::warning( this, QObject::tr("NCReport error"), QObject::tr("Could not load database driver.") );
            //delete report;
        return false;
    }
    defaultDB.setHostName( leHost->text() );
    defaultDB.setDatabaseName( leDB->text() );
    defaultDB.setUserName( leUser->text() );
    defaultDB.setPassword( lePassw->text() );

    if ( !defaultDB.open() ) {
            //fprintf( stderr, "Error: Cannot open database. %s\n", qPrintable( defaultDB.lastError().databaseText() ) );
        QApplication::restoreOverrideCursor();
        QMessageBox::warning( this, QObject::tr("NCReport error"), QObject::tr("Cannot open database: ")+defaultDB.lastError().databaseText() );
            //delete report;
        return false;
    }

    return true;
}

void NCRTestForm::run()
{
    //-----------------------------
    // INTERNAL DATABASE CONNECTION
    //-----------------------------
    if ( cbUseDBConnect->isChecked() ) {
        if ( !connectToDatabase() )
            return;
    }

    //-----------------------------
    // FILE
    //-----------------------------
    QString fileName;
    if ( rbPdf->isChecked() ) {
        fileName = QFileDialog::getSaveFileName(this, tr("Save PDF File"), "report.pdf", tr("Pdf files (*.pdf)"));
        if ( fileName.isEmpty() )
            return;
    }
    else if ( rbSvg->isChecked() ) {
        fileName = QFileDialog::getSaveFileName(this, tr("Save multiple SVG files"), "svg_output.svg", tr("Svg files (*.svg)"));
        if ( fileName.isEmpty() )
            return;
    }

    report = new NCReport( this );
    connect( report, SIGNAL(reportStarts()), this, SLOT(showReportProgressDialog()) );
    connect( report, SIGNAL(reportEnds()), this, SLOT(hideReportProgressDialog()) );

    //-----------------------------
    // SET THE REPORT SOURCE
    //-----------------------------

    if ( rbSingle->isChecked() ) {
        // normal (single) mode
        report->clearBatch();
        report->setReportSourceType( NCReportSource::File );
        report->setReportFile( teReportFiles->toPlainText() );
    } else {
        // batch mode
        report->clearBatch();
        QStringList reportfiles = reportFile().split(";", QString::SkipEmptyParts);

        for ( int i=0; i<reportfiles.count(); ++i ) {
            //QString reportXML;
            //if ( NCReportUtils::fileToString( reportfiles.at(i), reportXML ) )
            //    report->addReportToBatch( reportXML );
            report->addReportToBatch(reportfiles.at(i));
        }
    }

    //-----------------------------
    // ADD RENDERER
    //-----------------------------
    if (m_renderer)
        report->addGraphItemRenderer(m_renderer);

    //-----------------------------
    // ADD PARAMETERS
    //-----------------------------
    for (int i=0; i<tableParams->rowCount(); ++i )
        report->addParameter( tableParams->item(i,0)->text(), tableParams->item(i,1)->text() );

    //-----------------------------
    // CREATE REPORT OUTPUT
    //-----------------------------

    if ( rbPreview->isChecked() )
        report->runReportToPreview();
    else if ( rbPrinter->isChecked() )
        report->runReportToPrinter();
    else if ( rbQtPreview->isChecked() )
        report->runReportToQtPreview();
    else if ( rbPdf->isChecked() )
        report->runReportToPDF( fileName );
    else if ( rbSvg->isChecked() )
        report->runReportToSVG( fileName );

    bool error = report->hasError();
    QString err = report->lastErrorMsg();

    //-----------------------------
    // ERROR HANDLING
    //-----------------------------
    if ( error )
        QMessageBox::information( 0, tr("Report error"), err );
    else {
        if ( rbPreview->isChecked() ) {
            //-----------------------------
            // PRINT PREVIEW
            //-----------------------------
            NCReportPreviewWindow *pv = new NCReportPreviewWindow();
            pv->setOutput( (NCReportPreviewOutput*)(report->output()) );
            pv->setReport( report );
            pv->setWindowModality(Qt::ApplicationModal );
            pv->setAttribute( Qt::WA_DeleteOnClose );
            pv->exec();
            //pv->show();
        }
    }

    delete report;
    report = NULL;
}

void NCRTestForm::setReportFile(const QString & fname)
{
    teReportFiles->setPlainText( fname );
}

void NCRTestForm::showReportProgressDialog()
{
    progress = new QProgressDialog( this );
    progress->setLabelText( tr("Running report...") );
    progress->setWindowModality(Qt::WindowModal);
    connect( report, SIGNAL(dataRowCount(int)), progress, SLOT(setMaximum(int)) );
    connect( report, SIGNAL(dataRowProgress(int)), progress, SLOT(setValue(int)) );
    connect( report, SIGNAL(pageProgress(QString)), progress, SLOT(setLabelText(QString)) );
    connect( progress, SIGNAL(canceled()), report, SLOT(cancel()) );
}

void NCRTestForm::hideReportProgressDialog()
{
    delete progress;
}

