
// MFCServerView.h : interface of the CMFCServerView class
//

#pragma once
#include "MFCServerDoc.h"

class CMFCServerView : public CView
{
public:
	CMFCServerView();
protected: // create from serialization only
	
	DECLARE_DYNCREATE(CMFCServerView)

// Attributes
public:
	CMFCServerDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCServerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	void AddMsg(CString message);
	CStringArray m_msgArray;
};

#ifndef _DEBUG  // debug version in MFCServerView.cpp
inline CMFCServerDoc* CMFCServerView::GetDocument() const
   { return reinterpret_cast<CMFCServerDoc*>(m_pDocument); }
#endif

