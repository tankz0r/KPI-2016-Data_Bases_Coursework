/****************************************************************************
*
*  Copyright (C) 2002-2013 Helta Kft. / NociSoft Software Solutions
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
#ifndef NCREPORTTABLEITEM_H
#define NCREPORTTABLEITEM_H

#ifndef NCREPORT_NO_ITEM_VIEW

#include "ncreportitem.h"
#include "ncreport_global.h"

#include <QModelIndex>

class NCReportDataSource;
class NCReportDirector;
class NCReportTableItemData;

QT_BEGIN_NAMESPACE
class QAbstractItemModel;
class QAbstractItemView;
QT_END_NAMESPACE

class NCREPORTSHARED_EXPORT NCReportTableItem : public NCReportItem
{
public:
    NCReportTableItem( NCReportDef* rdef, QGraphicsItem * parent=0 );
    ~NCReportTableItem();

    enum RowType { HeaderRow=0, DataRow };
    enum CellType { CornerCell=0x0, HorizontalHeaderCell, VerticalHeaderCell, DataCell };
    enum ImageType { None=0x0, Pixmap, Icon };

    bool read( NCReportXMLReader* reader );
    bool write( NCReportXMLWriter* writer);
    void setDefaultForEditor();
    void paint( NCReportOutput* output, const QPointF& painterPosMM );
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void dummyPaint( NCReportOutput* output, const QPointF& point);

    void setDataSource( NCReportDataSource* );
    void setDataSourceByID( const QString& id );
    NCReportDataSource* dataSource() const;
    QRectF boundingRect() const;

    qreal tableSpacingMM() const;

    void setTableSpacingMM( qreal value );

    qreal cellPaddingMM() const;
    void setCellPaddingMM( qreal value );

    qreal leftMarginMM() const;
    void setLeftMarginMM( qreal value );
    qreal rightMarginMM() const;
    void setRightMarginMM( qreal value );
    qreal topMarginMM() const;
    void setTopMarginMM( qreal value );
    qreal bottomMarginMM() const;
    void setBottomMarginMM( qreal value );

    qreal cellSpacing() const;
    void setCellSpacing( qreal value );

    bool isElidedMode() const;
    void setElidedMode( bool set );

    bool isHorizontalHeaderVisible() const;
    void setHorizontalHeaderVisible( bool set );

    bool isVerticalHeaderVisible() const;
    void setVerticalHeaderVisible( bool set );

    bool isForcedAspectRatio() const;
    void setForcedAspectRatio( bool set );

    bool showBorderAndBG() const;
    void setshowBorderAndBG( bool set );

    void setModelID( const QString& modelID );
    QString modelID() const;

    void setTableViewID( const QString& viewID );
    QString tableViewID() const;

    void setHiddenRows( const QList<int>& rows );
    void setHiddenRows( const QString& list );
    QString hiddenRowsList() const;
    void setHiddenColumns( const QList<int>& columns );
    void setHiddenColumns( const QString& list );
    QString hiddenColumnsList() const;

    int columnCount() const;
    int rowCount() const;

//    qreal columnWidthMM( int column ) const;
//    qreal rowHeightMM( int row ) const;
    qreal columnWidthPixel( int column ) const;
    qreal rowHeightPixel(RowType type , const QModelIndex &index) const;
    int calculateSourceTableWidth() const;

    QAbstractItemModel *model() const;
    QAbstractItemView *view() const;

    bool isTableView() const;
    bool isTreeView() const;

    bool viewIsRowHidden(int row, const QModelIndex& parent = QModelIndex()) const;
    bool viewIsColumnHidden(int column) const;
    int viewHorizontalHeaderHeight() const;
    int viewVerticalHeaderWidth() const;
    int viewRowHeight(const QModelIndex &index) const;
    int viewColumnWidth(int column) const;
    bool viewVerticalHeaderIsVisible() const;
    int logicalColumnIndex( int visibleColumn ) const;
private:

    NCReportTableItemData* m_d;

    qreal m_rate;
    qreal m_deviceRate;
    qreal m_tableWidth;
    qreal m_calculatedTableHeight;
    qreal m_tableSpacing;
    qreal m_cellSpacingTr;
    qreal m_indentionPixelWidth;
    QSizeF m_defaultIconSize;
    QRectF m_itemRect;

private:
    void adjustSize();
    void adjustSize(NCReportOutput* o);
    void adjustHeight(NCReportOutput* o);

    void paintTableRows( NCReportOutput* output, QPointF &topLeft );
    void paintTreeRows(NCReportOutput* output, QPointF &topLeft, const QModelIndex &parent, int indentionLevel);
    void paintRow(NCReportOutput* output, QPointF &topLeft, RowType rowType, const QModelIndexList &indexList , int indentionLevel);
    void paintCell(NCReportOutput* output, const QRectF &cellRect, CellType cellType, const QModelIndex& index , int headerRow, int headerColumn, int indentionLevel);
    ImageType paintCellImage( NCReportOutput* output, const QRectF &cellRect, const QVariant& imageData ) const;
    void paintIndentationImage( NCReportOutput* output, const QRectF &cellRect, int dimension );
    void paintElitedText( QPainter *painter, const QString& text, const QRectF& cellRect,  Qt::Alignment alignment );

    qreal spaceToBottom( NCReportOutput* output, const QRectF& rect) const;
    void indentation( int role, int& dimension, bool& hasChildren );
};

#endif

#endif // NCREPORTTABLEITEM_H
