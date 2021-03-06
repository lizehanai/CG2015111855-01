
// CG2015111855李泽汗01View.cpp: CCG2015111855李泽汗01View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CG2015111855李泽汗01.h"
#endif

#include "CG2015111855李泽汗01Doc.h"
#include "CG2015111855李泽汗01View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCG2015111855李泽汗01View

IMPLEMENT_DYNCREATE(CCG2015111855李泽汗01View, CView)

BEGIN_MESSAGE_MAP(CCG2015111855李泽汗01View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCG2015111855李泽汗01View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CCG2015111855李泽汗01View 构造/析构

CCG2015111855李泽汗01View::CCG2015111855李泽汗01View()
{
	// TODO: 在此处添加构造代码

}

CCG2015111855李泽汗01View::~CCG2015111855李泽汗01View()
{
}

BOOL CCG2015111855李泽汗01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CCG2015111855李泽汗01View 绘图

void CCG2015111855李泽汗01View::OnDraw(CDC* pDC)
{
	CCG2015111855李泽汗01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//任务1-6
	//myDraw(pDC);
	//任务7
	DrawPicture(pDC);
}


// CCG2015111855李泽汗01View 打印


void CCG2015111855李泽汗01View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCG2015111855李泽汗01View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCG2015111855李泽汗01View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CCG2015111855李泽汗01View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CCG2015111855李泽汗01View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCG2015111855李泽汗01View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCG2015111855李泽汗01View 诊断

#ifdef _DEBUG
void CCG2015111855李泽汗01View::AssertValid() const
{
	CView::AssertValid();
}

void CCG2015111855李泽汗01View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCG2015111855李泽汗01Doc* CCG2015111855李泽汗01View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCG2015111855李泽汗01Doc)));
	return (CCG2015111855李泽汗01Doc*)m_pDocument;
}
#endif //_DEBUG


// CCG2015111855李泽汗01View 消息处理程序


// 任务1-6：自定义画图函数
int CCG2015111855李泽汗01View::myDraw(CDC *pDC)
{
	//画笔样式
	int nPenStyle[] =
	{
		PS_SOLID, PS_DASH, PS_DOT, PS_DASHDOT, PS_DASHDOTDOT, PS_NULL, PS_INSIDEFRAME
	};
	CPen *pNewPen; 
	CPen *pOldPen;

	//颜色表
	struct tagColor
	{
		int r, g, b;
	} 
	color[7] = {
		{ 255,0,0 },{ 0,255,0 },{ 0,0,255 }, { 255,255,0 },{ 255,0,255 },{ 0,255,255 },{ 0,0,0 }	
	};

	int i;

	//(1)绘制矩形

	//不同颜色
	for (i = 0; i < 7; i++) {
		pNewPen = new CPen;
		if (pNewPen->CreatePen(PS_SOLID, 2, RGB(color[i].r, color[i].g, color[i].b))) {
			pOldPen = pDC->SelectObject(pNewPen);//选择新笔，并保存旧笔
			pDC->Rectangle(20 + i * 50, 20, 60 + 50 * i, 60 + 4 * i);
			// 恢复原有的笔
			pDC->SelectObject(pOldPen);
		}
		else
		{
			//出错提示 
			AfxMessageBox(_T("Draw Rectangles with Different Color Erroe!!"));
		}
		delete pNewPen;
	}

	//不同宽度
	for (i = 0; i < 7; i++) {
		pNewPen = new CPen;
		if (pNewPen->CreatePen(nPenStyle[0], 3*i+1, RGB(0, 0, 0))) {
			pOldPen = pDC->SelectObject(pNewPen);//选择新笔，并保存旧笔
			pDC->Rectangle(420 + i * 80, 20, 460 + 80 * i, 92 + 4 * i);
			// 恢复原有的笔
			pDC->SelectObject(pOldPen);
		}
		else
		{
			//出错提示 
			AfxMessageBox(_T("Draw Rectangles with Different Width Erroe!!"));
		}
		delete pNewPen;
	}

	//不同线型
	for (i = 0; i < 7; i++) {
		pNewPen = new CPen;
		if (pNewPen->CreatePen(nPenStyle[i], 1, RGB(0, 0, 0))) {
			pOldPen = pDC->SelectObject(pNewPen);//选择新笔，并保存旧笔
			pDC->Rectangle(20 + i * 50, 100, 60 + 50 * i, 140 + 4 * i);
			// 恢复原有的笔
			pDC->SelectObject(pOldPen);
		}
		else
		{
			//出错提示 
			AfxMessageBox(_T("Draw Rectangles with Different Line Erroe!!"));
		}
		delete pNewPen;
	}

	//填充模式：阴影
	CBrush *pNewBrush;
	CBrush *pOldBrush;
	CBrush Brush(HS_DIAGCROSS, RGB(255, 255, 255));
	pOldBrush = pDC->SelectObject(&Brush); pDC->SetBkColor(RGB(192, 192, 192));
	pDC->Rectangle(1000, 140, 1200, 200); 
	pDC->SelectObject(pOldBrush);

	

	//不同填充颜色&方式：纯色
	for (i = 0; i < 7; i++) {
		pNewBrush = new CBrush;
		if (pNewBrush->CreateSolidBrush(RGB(color[i].r, color[i].g, color[i].b)))
		{
			//选择新画刷
			pOldBrush = pDC->SelectObject(pNewBrush);
			//绘制矩形
			pDC->Rectangle(420 + i * 80, 140, 460 + 80 * i, 200 + 4 * i);
			//恢复原有画刷
			pDC->SelectObject(pOldBrush);
		}
		delete	pNewBrush;

	}

	//(2)绘制折线

	//定义折线端点
	POINT polylinepoint[11] = { { 120,340 },{ 20,290 },{ 70,490 },{ 50,240 },
		{320,500},{100,540},{300,300},{400,500},{540,540},{560,300},{400,700} };
	DWORD dwPolyPoints1[3] = { 3,2,2 };
	DWORD dwPolyPoints2[4] = { 4,2,4 };
	CPen *pen=new CPen;
	pen->CreatePen(nPenStyle[3], 1, RGB(255, 0, 0));
	pDC->SelectObject(pen);
	pDC->PolyPolyline(polylinepoint, dwPolyPoints1, 3);
	delete pen;
	//定义新的画笔
	pen = new CPen;
	pen->CreatePen(nPenStyle[0], 3, RGB(0, 0, 0));
	pDC->SelectObject(pen);
	pDC->PolyPolyline(polylinepoint, dwPolyPoints2, 3);
	delete pen;


	//(3)绘制椭圆

	//不同颜色
	for (i = 0; i < 7; i++) {
		pNewPen = new CPen;
		if (pNewPen->CreatePen(PS_SOLID, 2, RGB(color[i].r, color[i].g, color[i].b))) {
			pOldPen = pDC->SelectObject(pNewPen);//选择新笔，并保存旧笔
			pDC->Ellipse(20 + i * 50, 620, 60 + 50 * i, 660 + 4 * i);
			// 恢复原有的笔
			pDC->SelectObject(pOldPen);
		}
		else
		{
			//出错提示 
			AfxMessageBox(_T("Draw Ellipses with Different Color Erroe!!"));
		}
		delete pNewPen;
	}

	//不同宽度
	for (i = 0; i < 7; i++) {
		pNewPen = new CPen;
		if (pNewPen->CreatePen(nPenStyle[0], 3 * i + 1, RGB(0, 0, 0))) {
			pOldPen = pDC->SelectObject(pNewPen);//选择新笔，并保存旧笔
			pDC->Ellipse(420 + i * 80, 620, 460 + 80 * i, 692 + 4 * i);
			// 恢复原有的笔
			pDC->SelectObject(pOldPen);
		}
		else
		{
			//出错提示 
			AfxMessageBox(_T("Draw Ellipses with Different Width Erroe!!"));
		}
		delete pNewPen;
	}

	//不同线型
	for (i = 0; i < 7; i++) {
		pNewPen = new CPen;
		if (pNewPen->CreatePen(nPenStyle[i], 1, RGB(0, 0, 0))) {
			pOldPen = pDC->SelectObject(pNewPen);//选择新笔，并保存旧笔
			pDC->Ellipse(20 + i * 50, 700, 60 + 50 * i, 740 + 4 * i);
			// 恢复原有的笔
			pDC->SelectObject(pOldPen);
		}
		else
		{
			//出错提示 
			AfxMessageBox(_T("Draw Ellipses with Different Line Erroe!!"));
		}
		delete pNewPen;
	}

	//填充模式：阴影
	CBrush Brush1(HS_DIAGCROSS, RGB(255, 0, 255));
	pOldBrush = pDC->SelectObject(&Brush1); 
	pDC->SetBkColor(RGB(192, 192, 192));
	pDC->Ellipse(1000, 240, 1200, 400);
	pDC->SelectObject(pOldBrush);



	//不同填充颜色&方式：纯色
	for (i = 0; i < 7; i++) {
		pNewBrush = new CBrush;
		if (pNewBrush->CreateSolidBrush(RGB(color[i].r, color[i].g, color[i].b)))
		{
			//选择新画刷
			pOldBrush = pDC->SelectObject(pNewBrush);
			//绘制矩形
			pDC->Ellipse(420 + i * 80, 740, 460 + 80 * i, 700 + 4 * i);
			//恢复原有画刷
			pDC->SelectObject(pOldBrush);
		}
		delete	pNewBrush;
	}

	return 0;
}



// 任务7：绘制图形（奇数学号）
int CCG2015111855李泽汗01View::DrawPicture(CDC *pDC)
{
	// TODO: 在此处添加实现代码.


	return 0;
}
