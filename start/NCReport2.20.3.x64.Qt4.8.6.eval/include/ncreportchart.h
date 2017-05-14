/**************************************************************************/
/*! \file
 *  \brief  Declaration of \ref
 *
 *  \author Norbert Szabo
 *
 *  \date   2015.10.20.
 *
 *  \copyright (c) 2015 Helta Ltd - NociSoft Software Solutions
 *  \copyright All rights reserved.
 *
 *  \remark Web: https://www.nocisoft.com
 *  \remark Email: office@nocisoft.com
 **************************************************************************/

#ifndef NCREPORTCHART_H
#define NCREPORTCHART_H

#include "ncreport_global.h"
#include <QRectF>
#include <QPointF>
#include <QLineF>
#include <QString>
#include <QList>
#include <QPen>
#include <QFont>

class QPainter;
class NCReportChart;

class NCREPORTSHARED_EXPORT NCReportChartLegend
{
public:
    enum ChartLegendPosition {
        ChartLegendPositionUpLeft = 0,
        ChartLegendPositionUpCenter,
        ChartLegendPositionUpRight,
        ChartLegendPositionBottomLeft,
        ChartLegendPositionBottomCenter,
        ChartLegendPositionBottomRight
    };

    NCReportChartLegend(NCReportChart* chart);
    void setSize(const QSizeF& size);
    void setPosition(ChartLegendPosition position);
    void setShowLegend(bool show);

    void paint(QPainter* painter);
private:
    NCReportChart* m_chart;
    QSizeF m_size;
    ChartLegendPosition m_position;
    bool m_showLegend;
};

class NCREPORTSHARED_EXPORT NCReportChartAxis
{
public:
    enum ChartAxisDirection {
        ChartAxisDirectionHorizontal = 0,
        ChartAxisDirectionVertical
    };
    enum ChartAxisPosition {
        ChartAxisPositionLeft = 0,
        ChartAxisPositionRight,
        ChartAxisPositionBottom,
        ChartAxisPositionTop,
    };
    enum ChartAxisStyle {
        ChartAxisStyleNone = 0,
        ChartAxisStyleLine,
        ChartAxisStyleTicksSideA,
        ChartAxisStyleTicksSideB,
        ChartAxisStyleTicksBothSides
    };

    NCReportChartAxis(NCReportChart* chart, ChartAxisPosition position);
    void setDirection(ChartAxisDirection direction);
    void setMinorTickResolution(int value);
    int minorTickResolution(void) const;
    void setMajorTickFrequency(int value);
    int majorTickFrequency(void) const;
    void setMinValue(double value);
    double minValue(void) const;
    void setMaxValue(double value);
    double maxValue(void) const;
    void setLength(double value);
    double length(void) const;
    void setMajorTickVisible(bool visible);
    void setMinorTickVisible(bool visible);
    void setStyle(ChartAxisStyle position);
    void setShowLabels(bool show);
    void setStartPoint(const QPointF& startPoint);
    void setTitle(const QString& title);
    void setLineWidth(double width);
    void setLabelHeight(double height);
    void setLabelValueFactor(double factor);
    void setLabelValuePrecision(int precision);
    void setLabelGap(double gap);
    void setTitleDistance(double distance);

    double valuePosition(double value) const;
    //const QList<double>& majorTickPositions() const;
    double minorDistance() const;
    double majorDistance() const;

public:
    void paint( QPainter* painter );

private:
    void drawAxis(const QLineF& axisLine, QPainter* painter);
    void drawTickMarksAndLabels(const QLineF& axisLine, QPainter* painter);
    void drawLabel(const QString &labelText, double axisPos, QPainter* painter);
    void drawLabel(double labelValue, double axisPos, QPainter* painter);
    void drawTitle(QPainter* painter);
private:
    NCReportChart *m_chart;
    ChartAxisDirection m_direction;
    ChartAxisPosition m_position;
    ChartAxisStyle m_tickStyle;
    int m_minorResolution;
    int m_majorFrequency;
    double m_lineWidth;
    double m_labelGap;
    double m_length;
    double m_minValue;
    double m_maxValue;
    double m_labelHeight;
    double m_labelValueFactor;
    double m_titleDistance;
    int m_labelValuePrecision;
    bool m_minorTickVisible;
    bool m_majorTickVisible;
    bool m_showLabels;
    QPointF m_startPoint;

    QString m_title;
    //QList<double> m_majorPositions;
};

class NCREPORTSHARED_EXPORT NCReportChartSeries
{
public:
    NCReportChartSeries();

    QList<double>& xAxisValues() { return m_xAxisValues; }
    QStringList&   xAxisLabels() { return m_xAxisLabels; }
    QList<double>& yAxisValues() { return m_yAxisValues; }
    QStringList&   yAxisLabels() { return m_yAxisLabels; }

    QPen pen() const;
    void setPen( const QPen& pen);
    void setTitle( const QString& title);
    QString title() const;
    QPair<double,double> minMax(const QList<double>& list) const;
private:
    QList<double> m_xAxisValues;
    QStringList   m_xAxisLabels;
    QList<double> m_yAxisValues;
    QStringList   m_yAxisLabels;
    QPen          m_pen;
    QString       m_title;
};

class NCREPORTSHARED_EXPORT NCReportChart
{
public:
    NCReportChart();
    NCReportChart(const QRectF& rect);

    virtual ~NCReportChart();
    void setRect(const QRectF& rect);
//    void setScaleFactor( double factor);
//    double scaleFactor() const;

    void setLeftMargin(double margin);
    void setRightMargin(double margin);
    void setBottomMargin(double margin);
    void setTopMargin(double margin);

    void setTitle(const QString& title);
    void setShowVerticalGrid(bool show);
    void setShowHorizontalGrid(bool show);

    void setMajorTickLength(double length);
    void setMinorTickLength(double length);
    void setGridLineWidth(double lineWidth);

    void setAxisLabelHeight(double height);
    void setAxisLineWidth(double lineWidth);
    void setAxisTitleFont(const QFont& font, QPaintDevice* paintDevice);
    void setTitleFont(const QFont& font, QPaintDevice* paintDevice);

    void addSeries(const NCReportChartSeries& series);

    QFont axisTitleFont(void) const;
    QFont titleFont(void) const;
    double axisTitleHeight() const;
    double titleHeight() const;
    double minorTickLength() const;
    double majorTickLength() const;
    double axisLineWidth() const;
    double gridLineWidth() const;
    double leftMargin() const;
    double rightMargin() const;
    double bottomMargin() const;
    double topMargin() const;

    NCReportChartAxis* leftAxis();
    NCReportChartAxis* rightAxis();
    NCReportChartAxis* bottomAxis();
    NCReportChartAxis* topAxis();

    NCReportChartLegend* legend();

    QRectF rect() const;
    QRectF chartRect() const;

    const QList<NCReportChartSeries>& series(void) const;
public:
    void paint(QPainter* painter);

private:
    void init();
    void drawChartAreaGrid(QPainter* painter);
    void drawSeries(QPainter* painter);
    void drawTitle(QPainter* painter);
    void update();
private:
    QRectF m_rect;
    double m_leftMargin;
    double m_rightMargin;
    double m_bottomMargin;
    double m_topMargin;

    double m_minorTickLength;
    double m_majorTickLength;
    double m_axisLineWidth;
    double m_axisTitleHeight;
    double m_titleHeight;
    double m_gridLineWidth;

    bool m_horizontalGrid;
    bool m_verticalGrid;
    QString m_title;
    NCReportChartAxis* m_leftAxis;
    NCReportChartAxis* m_rightAxis;
    NCReportChartAxis* m_bottomAxis;
    NCReportChartAxis* m_topAxis;
    NCReportChartLegend* m_legend;

    QFont m_titleFont;
    QFont m_axisTitleFont;
    QList<NCReportChartSeries> m_series;
};

#endif // NCREPORTCHART_H
