//=============================================================================
// Copyright (c) 2020-2021 Advanced Micro Devices, Inc. All rights reserved.
/// @author AMD Developer Tools Team
/// @file
/// @brief  Implementation of a custom tooltip comprising of a multiline
/// text string with a color swatch before each line of text.
///
/// Implemented on top of QGraphicsSimpleTextItem and uses the base class
/// setText() to store the text and the custom color data is set in setData().
///
//=============================================================================

#include "views/custom_widgets/rmv_color_swatch_tooltip_item.h"

RMVColorSwatchTooltipItem::RMVColorSwatchTooltipItem(QGraphicsItem* parent)
    : QGraphicsSimpleTextItem(parent)
    , text_height_(0)
    , icon_size_(0)
{
}

RMVColorSwatchTooltipItem::~RMVColorSwatchTooltipItem()
{
}

QRectF RMVColorSwatchTooltipItem::boundingRect() const
{
    QRectF rect  = QGraphicsSimpleTextItem::boundingRect();
    qreal  width = rect.width();
    rect.setWidth(width + icon_size_);
    return rect;
}

void RMVColorSwatchTooltipItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QStringList line_list = text().split("\n");
    int         num_rows  = line_list.size();
    if (num_rows > 0)
    {
        painter->setFont(font());

        text_height_ = boundingRect().height() / num_rows;
        icon_size_   = text_height_ - 2;

        int offset = 0;
        for (auto index = 0; index < line_list.size(); index++)
        {
            QString color = data(index).toString();
            painter->fillRect(0, offset + 1, icon_size_, icon_size_, QColor(color));
            painter->drawText(icon_size_ + 1, icon_size_ + offset, line_list[index]);
            offset += text_height_;
        }
    }
}
