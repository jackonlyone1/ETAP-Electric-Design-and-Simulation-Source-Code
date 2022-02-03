// ETAPDemoView.h : interface of the CETAPDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ETAPDEMOVIEW_H__EA436CD6_578A_44A9_BEE6_FFE7189E3A4C__INCLUDED_)
#define AFX_ETAPDEMOVIEW_H__EA436CD6_578A_44A9_BEE6_FFE7189E3A4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NewCompositeShape.h"

// User message for updating animation display
const int UWM_UPDATE_ANIMATION = WM_APP + 222;

struct TEST_INDEX 
{
	int nIndex;
	CString strCaption;
};

 
//===========================================================================
// Summary:
//      To use a RndGen object, just call the constructor.
//      Rnd Generate
//===========================================================================

class RndGen 
{
 
	// This variable specifies a 32-bit signed integer on 32-bit platforms.  
	int     n;  
 
	// This member maintains a pointer to the object float.  
	float   *oldrand;
	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.

	void    advance_random();
	
public:  
	
	//-----------------------------------------------------------------------
	// Summary:
	// Rnd Generate, Constructs a RndGen object.
	//		Returns A  value.
	RndGen() { oldrand = 0; }
	
	//-----------------------------------------------------------------------
	// Summary:
	// Rnd Generate, Destructor of class RndGen
	//		Returns A  value.
	~RndGen();
	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	//		Returns a float value.
	float   randm();        
	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	// Parameters:
	//		randomseed---Specifies A float value.
	void    init_random(const float randomseed = 0.1f);
};

class CThreadTimer;
 
//===========================================================================
// Summary:
//     The CETAPDemoView class derived from CFOTabPageView
//      E T A P Demo View
//===========================================================================

class CETAPDemoView : public CFOTabPageView
{
protected: // create from serialization only
	
	//-----------------------------------------------------------------------
	// Summary:
	// E T A P Demo View, Constructs a CETAPDemoView object.
	//		Returns A  value.
	CETAPDemoView();
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ D Y N C R E A T E, None Description.
	//		Returns A  value.  
	// Parameters:
	//		CETAPDemoView---E T A P Demo View, Specifies a CETAPDemoView object.
	DECLARE_DYNCREATE(CETAPDemoView)

// Attributes
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Document, Returns the specified value.
	//		Returns a pointer to the object CETAPDemoDoc,or NULL if the call failed
	CETAPDemoDoc* GetDocument();

public:

	
	//-----------------------------------------------------------------------
	// Summary:
	// Select New Shape, Call this function to select the given item.
	// Parameters:
	//		*pShape---*pShape, A pointer to the CFODrawShape  or NULL if the call failed.
	void SelectNewShape(CFODrawShape *pShape);

	// Do model change.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Change Model, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pModel---*pModel, A pointer to the CFODataModel  or NULL if the call failed.
	virtual void	DoChangeModel(
		// Pointer of model.
		CFODataModel *pModel);
 
public:
	CFOCompositeShape *m_pTrackDraw;
	// Select File, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString strCurSelectFile;
	
	//
	CString strCurSelectShape;

	CFOCompositeShape* CreateTrackShape(const int &nType);
	CFOCompositeShape* CreateTrackShapeFile(const CString &strType);
// Operations
public:

	// End print preview mode.
	
	//-----------------------------------------------------------------------
	// Summary:
	// On End Print Preview, Called when a print job ends; override to deallocate GDI resources.
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.  
	//		pInfo---pInfo, A pointer to the CPrintInfo or NULL if the call failed.  
	//		pt---Specifies a POINT pt object.  
	//		pView---pView, A pointer to the CPreviewView or NULL if the call failed.
	void OnEndPrintPreview(CDC* pDC, CPrintInfo* pInfo,POINT pt, CPreviewView* pView);

	// Hit Test Shape
	
	//-----------------------------------------------------------------------
	// Summary:
	// Pick In Shape, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		nFlags---nFlags, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		point---Specifies A CPoint type value.  
	//		nButton---nButton, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.
	virtual BOOL	PickInShape(
		// Mouse key flags.
		UINT nFlags,
		// Mouse hit point.
		CPoint point, UINT nButton = VK_LBUTTON);
	
	// Close this frame.
	void CloseFrame();
	
	// Activate this frame
	void Activate();

	// Create context menu.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Create Context Menu, You construct a CETAPDemoView object in two steps. First call the constructor, then call Create, which creates the object.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CMenu,or NULL if the call failed
	virtual CMenu* CreateContextMenu();

	// Get component Cursor
	
	//-----------------------------------------------------------------------
	// Summary:
	// Pick Shape Cursor, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		nFlags---nFlags, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		point---Specifies A CPoint type value.
	virtual BOOL PickShapeCursor(UINT nFlags, CPoint point);

	// Init link shape.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Initial Link Shape, Call InitLinkShape after creating a new object.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void InitLinkShape();

	// Draw Track Rectangle
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Draw Track Only Drop, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		point---Specifies A CPoint type value.
	virtual void OnDrawTrackOnlyDrop(CPoint point);

	// Do Remove a list of Shapes.
	// pShapeList -- the list of shapes for removing.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Delete Action, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CFORemoveCompsAction,or NULL if the call failed  
	// Parameters:
	//		pShapeList---Shape List, A pointer to the CFODrawShapeList or NULL if the call failed.
	virtual CFORemoveCompsAction*	DoDeleteAction(CFODrawShapeList* pShapeList);
	
	
	// Do Size port Action
	// pPortHit -- pointer of the port that hitted.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Size Port Action, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CFOSizePortAction,or NULL if the call failed  
	// Parameters:
	//		*pPortHit---Port Hit, A pointer to the CFOPortShape  or NULL if the call failed.
	virtual CFOSizePortAction*		DoSizePortAction(CFOPortShape *pPortHit);

	// Hit Test Control Handle
	
	//-----------------------------------------------------------------------
	// Summary:
	// Pick Multiple Shapes Resize Handle, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		ptHit---ptHit, Specifies A CPoint type value.  
	//		nIndex---nIndex, Specifies A integer value.
	virtual BOOL PickMultiShapesResizeHandle(
		// Mouse hit point
		CPoint ptHit, 
		// Control handle index.
		int& nIndex);

	// Get shapes for copying.
	// pShapeList -- Result list of shapes that can be copied.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Copying Shapes, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pShapeList---Shape List, A pointer to the CFODrawShapeSet or NULL if the call failed.
	virtual void GetCopyingShapes(CFODrawShapeSet* pShapeList);

	// Draw  Shapes Selected
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Draw Select Shapes, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pDC---D C, A pointer to the CDC  or NULL if the call failed.  
	//		&rcView---&rcView, Specifies A CRect type value.
	virtual void DoDrawSelectShapes(CDC *pDC,const CRect &rcView);

	// Draw Track Hot spot
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Draw Link Hotspot, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pShape---*pShape, A pointer to the CFODrawShape  or NULL if the call failed.  
	//		&nShapeType---Shape Type, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.
	virtual void OnDrawLinkHotspot(CFODrawShape *pShape,const UINT &nShapeType);

	// Reset select mode.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Reset To Select Mode, Called this function to empty a previously initialized CFOPCanvasCore object.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void ResetToSelectMode();

	//-----------------------------------------------------------------------
	// Summary:
	// On F O P Update, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pSender---Sender, A pointer to the CView or NULL if the call failed.  
	//		lHint---Hint, Specifies A lparam value.  
	//		pHint---Hint, A pointer to the CObject or NULL if the call failed.
	virtual void OnFOPUpdate(CView* pSender, LPARAM lHint, CObject* pHint);


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CETAPDemoView)
	public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Draw, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Before Create Window, Called before the creation of the Windows window attached to this CWnd object.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		cs---Specifies a CREATESTRUCT& cs object.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Initial Update, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void OnInitialUpdate(); // called first time after construct
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Prepare Printing, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		pInfo---pInfo, A pointer to the CPrintInfo or NULL if the call failed.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Begin Printing, Called when a print job begins; override to allocate graphics device interface (GDI) resources.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.  
	//		pInfo---pInfo, A pointer to the CPrintInfo or NULL if the call failed.
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On End Printing, Called when a print job ends; override to deallocate GDI resources.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.  
	//		pInfo---pInfo, A pointer to the CPrintInfo or NULL if the call failed.
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Print, Called to print or preview a page of the document.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.  
	//		pInfo---pInfo, A pointer to the CPrintInfo or NULL if the call failed.
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update, Called to notify a view that its document has been modified.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pSender---pSender, A pointer to the CView or NULL if the call failed.  
	//		lHint---lHint, Specifies A lparam value.  
	//		pHint---pHint, A pointer to the CObject or NULL if the call failed.
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// C E T A P Demo View, Destructor of class CETAPDemoView
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CETAPDemoView();
#ifdef _DEBUG
	
	//-----------------------------------------------------------------------
	// Summary:
	// Assert Valid, Assert performs a validity check on this object by checking its internal state.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void AssertValid() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Dump, Dumps the contents of your object to a CDumpContext object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		dc---Specifies a CDumpContext& dc object.
	virtual void Dump(CDumpContext& dc) const;
#endif

	// When zoom sacle changed to call this function.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Zoom Scale Changing, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,
	virtual void DoZoomScaleChanging();
 
	// Rn, This member specify RndGen object.  
	RndGen Rn;

	// Do showing cursor with shape dropping.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Show Cursor With Drop, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		&ptHit---&ptHit, Specifies A CPoint type value.
	virtual void DoShowCursorWithDrop(const CPoint &ptHit);

	// Do Remove a list of Shapes.
	// pShapeList -- the list of shapes for removing.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Delete Action, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CFORemoveCompsAction,or NULL if the call failed  
	// Parameters:
	//		pShapeList---Shape List, A pointer to the CFODrawShapeList or NULL if the call failed.
	virtual CFORemoveCompsAction*	DoDeleteActionX(CFODrawShapeList* pShapeList);

	// Is exchange format supported.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Is Exchange Format Supported, Determines if the given value is correct or exist.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns BOOLvalue, TRUE on success; FALSE otherwise.  
	// Parameters:
	//		nFormat---nFormat, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.
	virtual BOOL  IsExchangeFormatSupported(UINT nFormat) const;
	
	
	// Save data to clipboard.
	// pShapeList -- list of shapes
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Serialize Data, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pShapeList---Shape List, A pointer to the CFODrawShapeSet or NULL if the call failed.
	virtual void DoSerializeStation(CFODrawShape *pStation);
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get X D Clipboard Format, Returns the specified value.
	// This member function is a static function.
	//		Returns A CLIPFORMAT value (Object).
	virtual CLIPFORMAT GetXDClipboardStation() const;

	// Find all models.
	void FindAllModels(CFODrawShapeSet *pShapeList, CFODataModelList *pModelList);

	// Save data to clipboard.
	// pShapeList -- list of shapes
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Serialize Data, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pShapeList---Shape List, A pointer to the CFODrawShapeSet or NULL if the call failed.
	virtual void DoSerializeData(CFODrawShapeSet* pShapeList);

	// Do load data.
	virtual void DoSerializeLoadData(COleDataObject &dataObject, CFODrawShapeList* pShapeList, CFODataModelList *pModelList);
	
	// Do something with models.
	virtual void DoWithModels(CFODataModelList *pModelList);
	
	// Add paste shapes to canvas.
	virtual void AddPasteToModel(CFODrawShapeList* pShapeList, CFODataModelList *pModelList);

	CFODataModel *FindInModels(const CString &strName, CFODataModelList *pModelList);

protected:
	// Timer
	// Override this method to handle your own database query.
	
	//-----------------------------------------------------------------------
	// Summary:
	// O Generate Value, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CString type value.
	virtual CString FOGenerateValue(int &nValue);
	
	
	//-----------------------------------------------------------------------
	// Summary:
	// Start Timer, None Description.
	// Parameters:
	//		nID---I D, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		nTime---nTime, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.
	void StartTimer(UINT nID, UINT nTime);
 
	// Initial Script, This member sets TRUE if it is right.  
	BOOL m_bInitScript;
 
	// This member specify CThreadTimer object.  
	CThreadTimer m_timer;
	
	// Cf station, This member specify CLIPFORMAT object.  
	static CLIPFORMAT			m_foCfStation; 
	
	//-----------------------------------------------------------------------
	// Summary:
	// Handle Timer, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		nIDEvent---I D Event, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.
	virtual void HandleTimer(UINT nIDEvent);
protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CETAPDemoView)
	afx_msg void OnFilePrintPreview();
	afx_msg void OnDrawC1001();
	afx_msg void OnUpdateDrawC1001(CCmdUI* pCmdUI);
	afx_msg void OnDrawC1002();
	afx_msg void OnUpdateDrawC1002(CCmdUI* pCmdUI);
	afx_msg void OnDraw1001();
	afx_msg void OnUpdateDraw1001(CCmdUI* pCmdUI);
	afx_msg void OnDraw1002();
	afx_msg void OnUpdateDraw1002(CCmdUI* pCmdUI);
	afx_msg void OnRotate900();
	afx_msg void OnUpdateRotate900(CCmdUI* pCmdUI);
	afx_msg void OnRotate1800();
	afx_msg void OnUpdateRotate1800(CCmdUI* pCmdUI);
	afx_msg void OnRotate2700();
	afx_msg void OnUpdateRotate2700(CCmdUI* pCmdUI);
	afx_msg void OnDraw1003();
	afx_msg void OnUpdateDraw1003(CCmdUI* pCmdUI);
	afx_msg void OnDraw1004();
	afx_msg void OnUpdateDraw1004(CCmdUI* pCmdUI);
	afx_msg void OnDraw1005();
	afx_msg void OnUpdateDraw1005(CCmdUI* pCmdUI);
	afx_msg void OnDraw1006();
	afx_msg void OnUpdateDraw1006(CCmdUI* pCmdUI);
	afx_msg void OnDraw1007();
	afx_msg void OnUpdateDraw1007(CCmdUI* pCmdUI);
	afx_msg void OnDraw1008();
	afx_msg void OnUpdateDraw1008(CCmdUI* pCmdUI);
	afx_msg void OnDraw1009();
	afx_msg void OnUpdateDraw1009(CCmdUI* pCmdUI);
	afx_msg void OnDraw1010();
	afx_msg void OnUpdateDraw1010(CCmdUI* pCmdUI);
	afx_msg void OnDraw1011();
	afx_msg void OnUpdateDraw1011(CCmdUI* pCmdUI);
	afx_msg void OnDraw1012();
	afx_msg void OnUpdateDraw1012(CCmdUI* pCmdUI);
	afx_msg void OnDraw1013();
	afx_msg void OnUpdateDraw1013(CCmdUI* pCmdUI);
	afx_msg void OnDraw1014();
	afx_msg void OnUpdateDraw1014(CCmdUI* pCmdUI);
	afx_msg void OnDraw1015();
	afx_msg void OnUpdateDraw1015(CCmdUI* pCmdUI);
	afx_msg void OnDraw1016();
	afx_msg void OnUpdateDraw1016(CCmdUI* pCmdUI);
	afx_msg void OnDraw1017();
	afx_msg void OnUpdateDraw1017(CCmdUI* pCmdUI);
	afx_msg void OnDraw1018();
	afx_msg void OnUpdateDraw1018(CCmdUI* pCmdUI);
	afx_msg void OnDraw1019();
	afx_msg void OnUpdateDraw1019(CCmdUI* pCmdUI);
	afx_msg void OnDraw1020();
	afx_msg void OnUpdateDraw1020(CCmdUI* pCmdUI);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnButtonExportCanvas();
	afx_msg void OnUpdateButtonExportCanvas(CCmdUI* pCmdUI);
	afx_msg void OnDestroy();
	afx_msg void OnShowOrHideBox();
	afx_msg void OnUpdateShowOrHideBox(CCmdUI* pCmdUI);
	afx_msg void OnMatherDot();
	afx_msg void OnUpdateMatherDot(CCmdUI* pCmdUI);
	afx_msg void OnDrawSubGraph();
	afx_msg void OnUpdateDrawSubGraph(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRun();
	afx_msg void OnUpdateRun(CCmdUI* pCmdUI);
	afx_msg void OnHideAllSnap();
	afx_msg void OnUpdateHideAllSnap(CCmdUI* pCmdUI);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDrawOpenSym();
	afx_msg void OnUpdateDrawOpenSym(CCmdUI* pCmdUI);
	afx_msg void OnDrawShortH();
	afx_msg void OnUpdateDrawShortH(CCmdUI* pCmdUI);
	afx_msg void OnDrawShortV();
	afx_msg void OnUpdateDrawShortV(CCmdUI* pCmdUI);
	afx_msg void OnDrawDoubleH();
	afx_msg void OnUpdateDrawDoubleH(CCmdUI* pCmdUI);
	afx_msg void OnDrawDoubleV();
	afx_msg void OnUpdateDrawDoubleV(CCmdUI* pCmdUI);
	afx_msg void OnDraw3H();
	afx_msg void OnUpdateDraw3H(CCmdUI* pCmdUI);
	afx_msg void OnDraw3V();
	afx_msg void OnUpdateDraw3V(CCmdUI* pCmdUI);
	afx_msg void OnEditCopy();
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnEditCut();
	afx_msg void OnUpdateEditCut(CCmdUI* pCmdUI);
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDraw1030();
	afx_msg void OnUpdateDraw1030(CCmdUI* pCmdUI);
	afx_msg void OnDraw1031();
	afx_msg void OnUpdateDraw1031(CCmdUI* pCmdUI);
	afx_msg void OnDraw1032();
	afx_msg void OnUpdateDraw1032(CCmdUI* pCmdUI);
	afx_msg void OnDraw1033();
	afx_msg void OnUpdateDraw1033(CCmdUI* pCmdUI);
	afx_msg void OnDraw1034();
	afx_msg void OnUpdateDraw1034(CCmdUI* pCmdUI);
	afx_msg void OnInsertShape();
	afx_msg void OnUpdateInsertShape(CCmdUI* pCmdUI);
	afx_msg void OnDrawShape();
	afx_msg void OnUpdateDrawShape(CCmdUI* pCmdUI);
	afx_msg void OnRelinkPage();
	afx_msg void OnUpdateRelinkPage(CCmdUI* pCmdUI);
	//}}AFX_MSG
	//-----------------------------------------------------------------------
	// Summary:
	// On Mouse Leave, This member function is called by the framework to allow your application to handle a Windows message.
	//		Returns A 32-bit LRESULT value returned from a window procedure or callback function.  
	// Parameters:
	//		WPARAM---P A R A M, Provides additional information used in processing the message. The parameter WPARAM value depends on the message.  
	//		LPARAM---P A R A M, Specifies A LPARAM value.
	afx_msg LRESULT OnMouseLeave(WPARAM,LPARAM);
	
	//-----------------------------------------------------------------------
	// Summary:
	// Update Animation, Call this member function to update the object.
	//		Returns A 32-bit value returned from a window procedure or callback function.  
	// Parameters:
	//		wParam---wParam, Provides additional information used in processing the message. The parameter value depends on the message.  
	//		lParam---lParam, Specifies A lparam value.
	afx_msg LRESULT UpdateAnimation(WPARAM wParam, LPARAM lParam);
#if _MFC_VER >= 0x0421
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Mouse Wheel, This member function is called by the framework to allow your application to handle a Windows message.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		nFlags---nFlags, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		zDelta---zDelta, Specifies a short zDelta object.  
	//		pt---Specifies A CPoint type value.
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
#endif
	//-----------------------------------------------------------------------
	// Summary:
	// On Font Scale Change, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFontScaleChange();
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ETAPDemoView.cpp
inline CETAPDemoDoc* CETAPDemoView::GetDocument()
   { return (CETAPDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ETAPDEMOVIEW_H__EA436CD6_578A_44A9_BEE6_FFE7189E3A4C__INCLUDED_)
