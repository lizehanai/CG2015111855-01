
// CG2015111855李泽汗01View.h: CCG2015111855李泽汗01View 类的接口
//

#pragma once


class CCG2015111855李泽汗01View : public CView
{
protected: // 仅从序列化创建
	CCG2015111855李泽汗01View();
	DECLARE_DYNCREATE(CCG2015111855李泽汗01View)

// 特性
public:
	CCG2015111855李泽汗01Doc* GetDocument() const;

	int myDraw(CDC * pDC);

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CCG2015111855李泽汗01View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	// 任务7：绘制图形（奇数学号）
	int DrawPicture(CDC *pDC);
};

#ifndef _DEBUG  // CG2015111855李泽汗01View.cpp 中的调试版本
inline CCG2015111855李泽汗01Doc* CCG2015111855李泽汗01View::GetDocument() const
   { return reinterpret_cast<CCG2015111855李泽汗01Doc*>(m_pDocument); }
#endif

