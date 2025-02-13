#include "stdafx.h"
#include "Settings/UISettings.h"
#include "DarkModeUtils.h"

BOOL CPartialGroupBox::Attach(HWND hWnd)
{
	ATLASSUME(m_hWnd == nullptr);
	ATLASSERT(::IsWindow(hWnd));

	// Allocate the thunk structure here, where we can fail gracefully

	BOOL result = m_thunk.Init(GetWindowProc(), this);
	if (result == FALSE)
	{
		return FALSE;
	}
	WNDPROC pProc = m_thunk.GetWNDPROC();
	WNDPROC pfnWndProc = (WNDPROC)::SetWindowLongPtr(hWnd, GWLP_WNDPROC, (LONG_PTR)pProc);
	if (pfnWndProc == nullptr)
		return FALSE;
	m_pfnSuperWindowProc = pfnWndProc;
	m_hWnd = hWnd;
	return TRUE;
}

BOOL CPartialGroupBox::AttachToDlgItem(HWND parent, UINT dlgID)
{
	return Attach(::GetDlgItem(parent, dlgID));
}

void CPartialGroupBox::Draw3dLine(CPaintDC& dc, LPCRECT lpRect, COLORREF clrTopLeft, COLORREF /*clrBottomRight*/)
{
	int x = lpRect->left;
	int y = lpRect->top;
	int cx = lpRect->right - lpRect->left;
	//int cy = lpRect->bottom - lpRect->top;

	dc.FillSolidRect(x, y, cx - 1, 1, clrTopLeft);
	//dc.FillSolidRect(x, y, 1, cy - 1, clrTopLeft);
	//dc.FillSolidRect(x + cx, y, -1, cy, clrBottomRight);
	//dc.FillSolidRect(x, y + cy, cx, -1, clrBottomRight);
}

void CPartialGroupBox::OnPaint(HDC /*hDC*/)
{
	CPaintDC dc(m_hWnd);

	// Paint group box manually
	CRect controlrect;
	GetClientRect(controlrect);
	//::MapWindowPoints(HWND_DESKTOP, GetParent(), (LPPOINT)(LPRECT)controlrect, (sizeof(RECT)/sizeof(POINT)));

	CFontHandle font = GetFont();

	dc.SelectFont(font);
	dc.SetMapMode(MM_TEXT);
	if (g_Settings->LoadBool((SettingID)Setting_DarkTheme)) {
		dc.SelectBrush(load_config()->menubaritem_bgbrush);
	}
	else {
		dc.SelectBrush(GetSysColorBrush(COLOR_BTNFACE));
	}

	stdstr grptext = GetCWindowText(m_hWnd);
	CRect fontsizerect(0, 0, 0, 0);
	if (g_Settings->LoadBool((SettingID)Setting_DarkTheme)) {
		dc.SetTextColor(load_config()->menubar_textcolor);
	}
	dc.DrawText(grptext.ToUTF16().c_str(), -1, fontsizerect, DT_SINGLELINE | DT_LEFT | DT_CALCRECT);

	CRect framerect(controlrect);
	framerect.top += (fontsizerect.Height()) / 2;
	long Style = GetStyle();

	if ((Style & 0xF000) == BS_FLAT)
	{
		if (g_Settings->LoadBool((SettingID)Setting_DarkTheme)) {
			dc.Draw3dRect(framerect, load_config()->menubar_textcolor, load_config()->menubar_textcolor);
			framerect.DeflateRect(1, 1);
			dc.Draw3dRect(framerect, load_config()->menubar_bgcolor, load_config()->menubar_bgcolor);
		}
		else {
			dc.Draw3dRect(framerect, RGB(0, 0, 0), RGB(0, 0, 0));
			framerect.DeflateRect(1, 1);
			dc.Draw3dRect(framerect, RGB(255, 255, 255), RGB(255, 255, 255));
		}
	}
	else
	{
		Draw3dLine(dc, framerect, GetSysColor(COLOR_3DSHADOW), GetSysColor(COLOR_3DHILIGHT));
		framerect.DeflateRect(1, 1);
		Draw3dLine(dc, framerect, GetSysColor(COLOR_3DHILIGHT), GetSysColor(COLOR_3DSHADOW));
	}

	if (!grptext.empty())
	{
		CRect fontrect(controlrect);
		fontrect.bottom = controlrect.top + fontsizerect.Height();

		if ((Style & 0xF00) == BS_RIGHT)
		{
			fontrect.right -= 6;
			fontrect.left = fontrect.right - fontsizerect.Width();
		}
		else if ((Style & 0xF00) == BS_CENTER)
		{
			fontrect.left += (controlrect.Width() - fontsizerect.Width()) / 2;
			fontrect.right = fontrect.left + fontsizerect.Width();
		}
		else //BS_LEFT or default
		{
			fontrect.left += 6;
			fontrect.right = fontrect.left + fontsizerect.Width();
		}

		fontrect.InflateRect(2, 0);
		if (g_Settings->LoadBool((SettingID)Setting_DarkTheme)) {
			dc.FillRect(fontrect, load_config()->menubaritem_bgcolor);
		}
		else {
		    dc.FillRect(fontrect, GetSysColor(COLOR_BTNFACE));
		}
		fontrect.DeflateRect(2, 0);

		// Draw caption
		dc.SetBkMode(OPAQUE);

		if (g_Settings->LoadBool((SettingID)Setting_DarkTheme)) {
			dc.SetTextColor(load_config()->menubar_textcolor);
			dc.SetBkColor(load_config()->menubar_bgcolor);
		}
		else {
			dc.SetBkColor(GetSysColor(COLOR_BTNFACE));
		}
		dc.DrawText(grptext.ToUTF16().c_str(), -1, fontrect, DT_SINGLELINE | DT_LEFT);
	}
}
