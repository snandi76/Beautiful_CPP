
// SDIServerAppView.cpp : implementation of the CSDIServerAppView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SDIServerApp.h"
#endif

#include "SDIServerAppDoc.h"
#include "SDIServerAppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDIServerAppView

IMPLEMENT_DYNCREATE(CSDIServerAppView, CView)

BEGIN_MESSAGE_MAP(CSDIServerAppView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSDIServerAppView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSDIServerAppView construction/destruction

CSDIServerAppView::CSDIServerAppView()
{
	// TODO: add construction code here

}

CSDIServerAppView::~CSDIServerAppView()
{
}

BOOL CSDIServerAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSDIServerAppView drawing

void CSDIServerAppView::OnDraw(CDC* /*pDC*/)
{
	CSDIServerAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CSDIServerAppView printing


void CSDIServerAppView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSDIServerAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSDIServerAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSDIServerAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CSDIServerAppView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSDIServerAppView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSDIServerAppView diagnostics

#ifdef _DEBUG
void CSDIServerAppView::AssertValid() const
{
	CView::AssertValid();
}

void CSDIServerAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDIServerAppDoc* CSDIServerAppView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIServerAppDoc)));
	return (CSDIServerAppDoc*)m_pDocument;
}
#endif //_DEBUG


// CSDIServerAppView message handlers
