
// MFCServerView.cpp : implementation of the CMFCServerView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCServer.h"
#endif

#include "MFCServerDoc.h"
#include "MFCServerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCServerView

IMPLEMENT_DYNCREATE(CMFCServerView, CView)

BEGIN_MESSAGE_MAP(CMFCServerView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCServerView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCServerView construction/destruction

CMFCServerView::CMFCServerView()
{
	((CMFCServerApp*)AfxGetApp())->m_pServerView = this;

}

CMFCServerView::~CMFCServerView()
{
}

BOOL CMFCServerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCServerView drawing

void CMFCServerView::OnDraw(CDC* pDC)
{
	int y = 100;
	for (int i = 0; m_msgArray.GetSize(); i++) {

		pDC->TextOut(100, y, m_msgArray.GetAt(i));
		y += 50;
	}
	CMFCServerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCServerView printing


void CMFCServerView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCServerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCServerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCServerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCServerView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCServerView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCServerView diagnostics

#ifdef _DEBUG
void CMFCServerView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCServerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCServerDoc* CMFCServerView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCServerDoc)));
	return (CMFCServerDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCServerView message handlers


void CMFCServerView::AddMsg(CString message)
{
	m_msgArray.Add(message);
	Invalidate();
}
