#include <QtWidgets>
#include "mousefilter.h"

MouseFilter::MouseFilter(QObject* pobj/*=0*/) : QObject(pobj)
{	
}

bool MouseFilter::eventFilter(QObject* pobj, QEvent* pe)
{
	if (pe->type() == QEvent::MouseButtonPress)
	{
		if (static_cast<QMouseEvent*>(pe)->button() == Qt::LeftButton)
		{
			pobj->metaObject();
			return true;
		}
	}
	return false;
}
