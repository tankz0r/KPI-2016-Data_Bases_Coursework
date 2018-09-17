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
#ifndef NCRTESTFORM_H
#define NCRTESTFORM_H

#include <QWidget>
#include "ui_ncrtestform.h"

class NCReport;
class QProgressDialog;
class NCReportGraphRenderer;

/*!
Report runner/tester form for demostrating purpuses.\n
This class demonstrates how to use NCReport class from a Qt application.
*/
class NCRTestForm : public QWidget, private Ui::NCRTestFormUI
{
  Q_OBJECT

public:
    NCRTestForm(QWidget* parent = 0 );
    ~NCRTestForm();

    void setReport( NCReport* );
    void setReportFile( const QString& fname );
    void addParam(const QString& name, const QString& value);
    void setRenderer(NCReportGraphRenderer *renderer);

    QString reportFile() const;

public slots:
    virtual void run();
    virtual void selectFiles();
    virtual void saveDefaults();
    virtual void loadDefaults();

protected:
    virtual void closeEvent( QCloseEvent* );
    virtual bool connectToDatabase();

protected slots:
    void addParam();
    void removeParam();
    void setDbPanelEnabled( bool enable );
    void showReportProgressDialog();
    void hideReportProgressDialog();

private:
    NCReport *report;
    QProgressDialog *progress;
    NCReportGraphRenderer *m_renderer;
    QStringList filelist;
};

#endif

