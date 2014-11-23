#include "stdafx.h"
#include "FontObject.h"


_stFontObject::_stFontObject()
	:m_nSize(0),
	m_bBold(false),
	m_bItalic(false),
	m_bUnderline(false),
	m_bStrikeout(false),
	m_IndexName(L""),
	m_FaceName(L""),
	m_hFont(nullptr)
{}

HFONT _stFontObject::GetFont()
{
	if (m_FaceName.empty())
	{
		return 0;
	}

	if (m_hFont)
	{
		return m_hFont;
	}

	LOGFONT lf = { 0 };
	::GetObject(::GetStockObject(DEFAULT_GUI_FONT), sizeof(LOGFONT), &lf);
	_tcscpy(lf.lfFaceName, m_FaceName.c_str());
	lf.lfCharSet = DEFAULT_CHARSET;
	lf.lfHeight = -m_nSize;
	if (m_bBold)
	{
		lf.lfWeight += FW_BOLD;
	}

	if (m_bUnderline)
	{
		lf.lfUnderline = TRUE;
	}

	if (m_bItalic)
	{
		lf.lfItalic = TRUE;
	}

	if (m_bStrikeout)
	{
		lf.lfStrikeOut = TRUE;
	}

	m_hFont = ::CreateFontIndirect(&lf);
	return m_hFont;
}
