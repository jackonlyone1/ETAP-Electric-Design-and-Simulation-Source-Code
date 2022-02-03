// ETAPDemoView.cpp : implementation of the CETAPDemoView class
//

#include "stdafx.h"
#include "ETAPDemo.h"

#include "ETAPDemoDoc.h"
#include "ETAPDemoView.h"
#include "ChildFrm.h"
#include "FOMatherLineShape.h"
#include "NewLinkShape.h"
#include "FOVertMatherLineShape.h"
#include "MainFrm.h"
#include "FOMatherDotShape.h"
#include "BPMActTaskShape.h"
//E-XD++ Library add lines.
#include "ETAPDemoDoc.h"
#include "ETAPDemoView.h"
#include "ChildFrm.h"
#include "HMITrsOpenPageDlg.h"
#include "MATRelinkDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const int nExpSize = 200;
/////////////////////////////////////////////////////////////////////////////
// CETAPDemoView

// E-XD++ Clipboard format (list of station objects)
CLIPFORMAT CETAPDemoView::m_foCfStation = (CLIPFORMAT)::RegisterClipboardFormat(_T("E-XD++ Stations"));

IMPLEMENT_DYNCREATE(CETAPDemoView, CFOTabPageView)
BEGIN_MESSAGE_MAP(CETAPDemoView,CFOTabPageView)
	//{{AFX_MSG_MAP(CETAPDemoView)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, OnFilePrintPreview)
	ON_COMMAND(ID_DRAW_C_100_1, OnDrawC1001)
	ON_UPDATE_COMMAND_UI(ID_DRAW_C_100_1, OnUpdateDrawC1001)
	ON_COMMAND(ID_DRAW_C_100_2, OnDrawC1002)
	ON_UPDATE_COMMAND_UI(ID_DRAW_C_100_2, OnUpdateDrawC1002)
	ON_COMMAND(ID_DRAW_1001, OnDraw1001)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1001, OnUpdateDraw1001)
	ON_COMMAND(ID_DRAW_1002, OnDraw1002)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1002, OnUpdateDraw1002)
	ON_COMMAND(ID_ROTATE_900, OnRotate900)
	ON_UPDATE_COMMAND_UI(ID_ROTATE_900, OnUpdateRotate900)
	ON_COMMAND(ID_ROTATE_1800, OnRotate1800)
	ON_UPDATE_COMMAND_UI(ID_ROTATE_1800, OnUpdateRotate1800)
	ON_COMMAND(ID_ROTATE_2700, OnRotate2700)
	ON_UPDATE_COMMAND_UI(ID_ROTATE_2700, OnUpdateRotate2700)
	ON_COMMAND(ID_DRAW_1003, OnDraw1003)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1003, OnUpdateDraw1003)
	ON_COMMAND(ID_DRAW_1004, OnDraw1004)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1004, OnUpdateDraw1004)
	ON_COMMAND(ID_DRAW_1005, OnDraw1005)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1005, OnUpdateDraw1005)
	ON_COMMAND(ID_DRAW_1006, OnDraw1006)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1006, OnUpdateDraw1006)
	ON_COMMAND(ID_DRAW_1007, OnDraw1007)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1007, OnUpdateDraw1007)
	ON_COMMAND(ID_DRAW_1008, OnDraw1008)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1008, OnUpdateDraw1008)
	ON_COMMAND(ID_DRAW_1009, OnDraw1009)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1009, OnUpdateDraw1009)
	ON_COMMAND(ID_DRAW_1010, OnDraw1010)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1010, OnUpdateDraw1010)
	ON_COMMAND(ID_DRAW_1011, OnDraw1011)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1011, OnUpdateDraw1011)
	ON_COMMAND(ID_DRAW_1012, OnDraw1012)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1012, OnUpdateDraw1012)
	ON_COMMAND(ID_DRAW_1013, OnDraw1013)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1013, OnUpdateDraw1013)
	ON_COMMAND(ID_DRAW_1014, OnDraw1014)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1014, OnUpdateDraw1014)
	ON_COMMAND(ID_DRAW_1015, OnDraw1015)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1015, OnUpdateDraw1015)
	ON_COMMAND(ID_DRAW_1016, OnDraw1016)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1016, OnUpdateDraw1016)
	ON_COMMAND(ID_DRAW_1017, OnDraw1017)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1017, OnUpdateDraw1017)
	ON_COMMAND(ID_DRAW_1018, OnDraw1018)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1018, OnUpdateDraw1018)
	ON_COMMAND(ID_DRAW_1019, OnDraw1019)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1019, OnUpdateDraw1019)
	ON_COMMAND(ID_DRAW_1020, OnDraw1020)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1020, OnUpdateDraw1020)
	ON_WM_SIZE()
	ON_COMMAND(ID_BUTTON_EXPORT_CANVAS, OnButtonExportCanvas)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_EXPORT_CANVAS, OnUpdateButtonExportCanvas)
	ON_WM_DESTROY()
	ON_COMMAND(ID_SHOW_OR_HIDE_BOX, OnShowOrHideBox)
	ON_UPDATE_COMMAND_UI(ID_SHOW_OR_HIDE_BOX, OnUpdateShowOrHideBox)
	ON_COMMAND(ID_MATHER_DOT, OnMatherDot)
	ON_UPDATE_COMMAND_UI(ID_MATHER_DOT, OnUpdateMatherDot)
	ON_COMMAND(ID_DRAW_SUB_GRAPH, OnDrawSubGraph)
	ON_UPDATE_COMMAND_UI(ID_DRAW_SUB_GRAPH, OnUpdateDrawSubGraph)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_RUN, OnRun)
	ON_UPDATE_COMMAND_UI(ID_RUN, OnUpdateRun)
	ON_COMMAND(ID_HIDE_ALL_SNAP, OnHideAllSnap)
	ON_UPDATE_COMMAND_UI(ID_HIDE_ALL_SNAP, OnUpdateHideAllSnap)
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DRAW_OPEN_SYM, OnDrawOpenSym)
	ON_UPDATE_COMMAND_UI(ID_DRAW_OPEN_SYM, OnUpdateDrawOpenSym)
	ON_COMMAND(ID_DRAW_SHORT_H, OnDrawShortH)
	ON_UPDATE_COMMAND_UI(ID_DRAW_SHORT_H, OnUpdateDrawShortH)
	ON_COMMAND(ID_DRAW_SHORT_V, OnDrawShortV)
	ON_UPDATE_COMMAND_UI(ID_DRAW_SHORT_V, OnUpdateDrawShortV)
	ON_COMMAND(ID_DRAW_DOUBLE_H, OnDrawDoubleH)
	ON_UPDATE_COMMAND_UI(ID_DRAW_DOUBLE_H, OnUpdateDrawDoubleH)
	ON_COMMAND(ID_DRAW_DOUBLE_V, OnDrawDoubleV)
	ON_UPDATE_COMMAND_UI(ID_DRAW_DOUBLE_V, OnUpdateDrawDoubleV)
	ON_COMMAND(ID_DRAW_3_H, OnDraw3H)
	ON_UPDATE_COMMAND_UI(ID_DRAW_3_H, OnUpdateDraw3H)
	ON_COMMAND(ID_DRAW_3_V, OnDraw3V)
	ON_UPDATE_COMMAND_UI(ID_DRAW_3_V, OnUpdateDraw3V)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_DRAW_1030, OnDraw1030)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1030, OnUpdateDraw1030)
	ON_COMMAND(ID_DRAW_1031, OnDraw1031)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1031, OnUpdateDraw1031)
	ON_COMMAND(ID_DRAW_1032, OnDraw1032)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1032, OnUpdateDraw1032)
	ON_COMMAND(ID_DRAW_1033, OnDraw1033)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1033, OnUpdateDraw1033)
	ON_COMMAND(ID_DRAW_1034, OnDraw1034)
	ON_UPDATE_COMMAND_UI(ID_DRAW_1034, OnUpdateDraw1034)
	ON_COMMAND(ID_INSERT_SHAPE, OnInsertShape)
	ON_UPDATE_COMMAND_UI(ID_INSERT_SHAPE, OnUpdateInsertShape)
	ON_COMMAND(ID_DRAW_SHAPE, OnDrawShape)
	ON_UPDATE_COMMAND_UI(ID_DRAW_SHAPE, OnUpdateDrawShape)
	ON_COMMAND(ID_RELINK_PAGE, OnRelinkPage)
	ON_UPDATE_COMMAND_UI(ID_RELINK_PAGE, OnUpdateRelinkPage)
	//}}AFX_MSG_MAP
#if _MFC_VER >= 0x0421
	ON_WM_MOUSEWHEEL()
#endif
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
	ON_MESSAGE(UWM_UPDATE_ANIMATION, UpdateAnimation)
	ON_CBN_SELCHANGE(IDC_COMBO_ZOOMVALUE, OnFontScaleChange)
	ON_COMMAND(ID_FILE_PRINT, CFOTabPageView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFOTabPageView::OnFilePrint)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CETAPDemoView construction/destruction

CETAPDemoView::CETAPDemoView()
{
	// TODO: add construction code here
	m_bWithRulers = FALSE;
	m_bWithAdvanceOpt		 = FALSE;
	Rn.init_random();
	m_bCenter = FALSE;
	m_pTrackDraw = NULL;
	strCurSelectFile = _T("");
	strCurSelectShape = _T("");
}

CETAPDemoView::~CETAPDemoView()
{
	if(m_pTrackDraw != NULL)
	{
		m_pTrackDraw->Release();
		m_pTrackDraw = NULL;
		
	}

}

BOOL CETAPDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREAFOAPPWIZARDRUCT cs
	return CFOTabPageView::PreCreateWindow(cs);

}

/////////////////////////////////////////////////////////////////////////////
// CETAPDemoView drawing

void CETAPDemoView::OnDraw(CDC* pDC)
{
	CETAPDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	Draw(pDC);
	// TODO: add draw code for native data here
}

void CETAPDemoView::InitLinkShape()
{
	m_drawshape = MY_LINK_SHAPE;
	m_bUpRightMode = FALSE;
	SetCurrentDrawingCursor(IDC_FO_DRAWLINK_CURSOR);
	m_nNumberArrow			=	0;
}

void CETAPDemoView::DoChangeModel(CFODataModel * pModel)
{
	CFOTabPageView::DoChangeModel(pModel);
	// Adding your data model init codes here..

}

CFOSizePortAction*	CETAPDemoView::DoSizePortAction(CFOPortShape *pPortHit)
{
	return NULL;
}

BOOL CETAPDemoView::PickShapeCursor(UINT nFlags, CPoint ptLog)
{
	nFlags;	// Not used
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		return FALSE;
	}
	
	if (m_action_state == State_SelectNone)
	{
		CFODrawShapeList m_TempList;
		if(!m_bMirrorFreeMode && 
			!m_bShearFreeMode &&
			!m_bBendFreeMode &&
			(m_listSelectComp.GetCount() <= 1) && GetCurrentModel()->IsAllowHoleLink())
		{
			CFOPortShape* pPortHit = GetCurrentModel()->HitTestPortExt(ptLog,m_TempList, FALSE);

			if(pPortHit != NULL)
			{
				CFODrawShape *pR = pPortHit->GetParentComp();
				if(pR->IsKindOf(RUNTIME_CLASS(CFOMatherLineShape)) || 
					pR->IsKindOf(RUNTIME_CLASS(CFOVertMatherLineShape)))
				{
					pPortHit = NULL;
				}
			}

			if(pPortHit != NULL)
			{
				CFODrawShape *pR = pPortHit->GetParentComp();
				if(!pR->IsKindOf(RUNTIME_CLASS(CFOMatherLineShape)) &&
					!pR->IsKindOf(RUNTIME_CLASS(CFOVertMatherLineShape)))
				{
					int nCount = pPortHit->GetLinkCount();
					if(nCount >= 1)
					{
						pPortHit = NULL;
					}
				}
				
			}

			BOOL bLarge = TRUE;
			int nType = 0;
			if(pPortHit != NULL)
			{
				pPortHit->GetPropIntValue(nType, P_ID_PORT_CONNECT_TYPE);
				if(!pPortHit->CanAddMoreLink())
				{
					nType = 1;
				}
				CFODrawShape *pParent = pPortHit->GetParentComp();
				if(pParent != NULL)
				{
					CSize szSize = pParent->GetSnapRect().Size();
					if(szSize.cx < 20 && szSize.cy < 20)
					{
						bLarge = FALSE;
					}
				}
			}

			if(nType == 1)
			{
				pPortHit = NULL;
			}
			
			if(pPortHit != NULL && bLarge &&
					(m_action_state != State_PortStart) &&
					(m_action_state != State_PortStart_Begin))
			{
				SetCurrentDrawingCursor(IDC_FO_HAND);
				return TRUE;
			}
		}

		m_pCurHitShape = NULL;
		CFODrawShape *pSaveOld = m_pInFocusShape;
		int nLength = FOPMax(m_pCurDataModel->m_nOutLength,1);
		int nAdd = nLength;

		if(m_TempList.GetCount() <= 0)
		{
			m_pCurHitShape = (CFODrawShape *)GetCurrentModel()->HitTest(ptLog);
		}
		else
		{
			m_pCurHitShape = (CFODrawShape *)GetCurrentModel()->HitTest2(m_TempList, ptLog);
		}
		if(pSaveOld != NULL)
		{
			FOPRect rcBound = pSaveOld->GetBoundRect();
			rcBound.InflateRect(nAdd/2,nAdd/2,nAdd,nAdd);
			if(!rcBound.PtInRect(ptLog))
			{
				if(m_pCurHitShape == NULL)
				{
					ClearAllAdditionalHandle();
					pSaveOld->SetFocusMode(FALSE);
					FOPRect rcUp = pSaveOld->GetBoundRect();
					rcUp.InflateRect(nAdd,nAdd,nAdd,nAdd);
					InvalidateRectExtend(rcUp);
					m_pInFocusShape = NULL;
					
				}
				else
				{
					if(m_pCurHitShape != pSaveOld)
					{
						ClearAllAdditionalHandle();
						pSaveOld->SetFocusMode(FALSE);
						FOPRect rcUp = pSaveOld->GetBoundRect();
						rcUp.InflateRect(nAdd,nAdd,nAdd,nAdd);
						InvalidateRectExtend(rcUp);

						if(1)//!m_pCurHitShape->IsShapeSelected())
						{
							m_pInFocusShape = m_pCurHitShape;
							
							
							DoGenInitItems(m_pInFocusShape);
						 
							m_pInFocusShape->SetFocusMode(TRUE);
							rcUp = m_pInFocusShape->GetBoundRect();
							rcUp.InflateRect(nAdd,nAdd,nAdd,nAdd);
							InvalidateRectExtend(rcUp);
						 
						}
 
					}
					else
					{
						if(m_SelectItems.GetHandleCount() == 0)
						{
							ClearAllAdditionalHandle();
							DoGenInitItems(pSaveOld);
							m_pInFocusShape->SetFocusMode(TRUE);
							FOPRect rcUp = pSaveOld->GetBoundRect();
							rcUp.InflateRect(nAdd,nAdd,nAdd,nAdd);
							InvalidateRectExtend(rcUp);
						}
					}
				}
				
			}
			else
			{
				if(m_pCurHitShape != NULL)
				{
					if(m_pCurHitShape == pSaveOld)
					{
						 
						if(m_SelectItems.GetHandleCount() == 0)
						{
							ClearAllAdditionalHandle();
							DoGenInitItems(m_pInFocusShape);
							m_pInFocusShape->SetFocusMode(TRUE);
							FOPRect rcUp = m_pInFocusShape->GetBoundRect();
							rcUp.InflateRect(nAdd,nAdd,nAdd,nAdd);
							InvalidateRectExtend(rcUp);
						}
					}
					else
					{
						if(m_SelectItems.GetHandleCount() > 0)
						{
							FOPRect rcBound1 = m_SelectItems.GetHandle(0)->GetItemRect();
							CFOWndDC dc(this);
							CPoint local = ptLog;
						 
							dc.LPtoDP(&local);
							CSize sizeHandles(20,20);
							CPoint ptSpot2 = rcBound1.Center();
							
							FOPRect rcHandle = FOPRect(ptSpot2.x - 20, ptSpot2.y - 12, ptSpot2.x + 12, ptSpot2.y + 40);
						 
							if(!PtInSpecifyRect(local, rcHandle))
							{
								ClearAllAdditionalHandle();
								pSaveOld->SetFocusMode(FALSE);
								FOPRect rcUp = pSaveOld->GetBoundRect();
								rcUp.InflateRect(nAdd,nAdd,nAdd,nAdd);
								InvalidateRectExtend(rcUp);
								
								if(1)//!m_pCurHitShape->IsShapeSelected())
								{
									m_pInFocusShape = m_pCurHitShape;
									
									
									DoGenInitItems(m_pInFocusShape);
									
									m_pInFocusShape->SetFocusMode(TRUE);
									rcUp = m_pInFocusShape->GetBoundRect();
									rcUp.InflateRect(nAdd,nAdd,nAdd,nAdd);
									InvalidateRectExtend(rcUp);
									
								}
							}
 
						}
 
					}
				}
			}
		}
		else // pSaveOld is null;
		{
			if(m_pCurHitShape != NULL)
			{
				
				m_pInFocusShape = m_pCurHitShape;
				ClearAllAdditionalHandle();
				DoGenInitItems(m_pInFocusShape);
				m_pInFocusShape->SetFocusMode(TRUE);
				FOPRect rcUp = m_pInFocusShape->GetBoundRect();
				rcUp.InflateRect(nAdd,nAdd,nAdd,nAdd);
				InvalidateRectExtend(rcUp);
				
				
			}
			else
			{
				if(m_SelectItems.GetHandleCount() != 0)
				{
					ClearAllAdditionalHandle();
				 
				}
			}
		}
	 
		if (m_pCurHitShape)
		{
			if(!m_pCurHitShape->IsMoveProtect())
			{
				if(m_bMultiSelect)
				{
					FOSetCursor(IDC_FO_MULTI_SELECT);
				}
				else
				{
#ifdef _FOP_E_SOLUTION	
					if(HAS_BASE(m_pCurHitShape,CFOPNewGridShape))
					{
						CFOPNewGridShape *pGrid = static_cast<CFOPNewGridShape *>(m_pCurHitShape);
						if(!PickInGridShapeCursor(pGrid,nFlags,ptLog,0))
						{
							FOSetCursor(IDC_FO_CUROSR_IN);
						}

						return TRUE;
					}
#endif	
#ifdef _FOP_TABLE_SOLUTION
					if(HAS_BASE(m_pCurHitShape,CFOPTableShape))
					{
						int nIndex = -1;
						CFOPTableShape *pGrid = static_cast<CFOPTableShape *>(m_pCurHitShape);
						if(pGrid->HitTestColumn(ptLog,nIndex))
						{
							FOSetCursor(IDC_FO_HSPLITBAR);
						}
						else if(pGrid->HitTestRow(ptLog,nIndex))
						{
							FOSetCursor(IDC_FO_VSPLITBAR);
						}
						else if(pGrid->HitTestRowHeader(ptLog,nIndex))
						{
							FOSetCursor(IDC_FO_TABLE_ROW);
						}
						else if(pGrid->HitTestColumnHeader(ptLog,nIndex))
						{
							FOSetCursor(IDC_FO_TABLE_COL);
						}
						else if(pGrid->GetInsideRect().PtInRect(ptLog))
						{
							FOSetSystemCursor(IDC_ARROW);
						}
						else
						{
							FOSetCursor(IDC_FO_CUROSR_IN);
						}
						return TRUE;
					}
					else if(HAS_BASE(m_pCurHitShape,FOXNewTableShape))
					{
						int nIndex = -1;
						FOXNewTableShape *pGrid = static_cast<FOXNewTableShape *>(m_pCurHitShape);
						if(pGrid->HitTestColumn(ptLog,nIndex))
						{
							FOSetCursor(IDC_FO_HSPLITBAR);
						}
						else if(pGrid->HitTestRow(ptLog,nIndex))
						{
							FOSetCursor(IDC_FO_VSPLITBAR);
						}
						else if(pGrid->HitTestRowHeader(ptLog,nIndex))
						{
							FOSetCursor(IDC_FO_TABLE_ROW);
						}
						else if(pGrid->HitTestColumnHeader(ptLog,nIndex))
						{
							FOSetCursor(IDC_FO_TABLE_COL);
						}
						else if(pGrid->GetInsideRect().PtInRect(ptLog))
						{
							FOSetSystemCursor(IDC_ARROW);
						}
						else
						{
							FOSetCursor(IDC_FO_CUROSR_IN);
						}
						return TRUE;
					}
#endif
					if(HAS_BASE(m_pCurHitShape,CFOPSubGraphShape))
					{
						CFOPSubGraphShape *pGrid = static_cast<CFOPSubGraphShape *>(m_pCurHitShape);
						if(pGrid->HitTestExpandButtonNew(ptLog))
						{
							FOSetCursor(IDC_FO_HAND);
						}
						else
						{
							FOSetCursor(IDC_FO_CUROSR_IN);
						}
					}
					else if(HAS_BASE(m_pCurHitShape,CFOListCtrlShape))
					{
						CFOListCtrlShape *pGrid = static_cast<CFOListCtrlShape *>(m_pCurHitShape);
						if(pGrid->HitTestUpButton(ptLog) || pGrid->HitTestDownButton(ptLog))
						{
							FOSetCursor(IDC_FO_HAND);
						}
						else
						{
							FOSetCursor(IDC_FO_CUROSR_IN);
						}
					}
					else
					{
						FOSetCursor(IDC_FO_CUROSR_IN);
					}
				}
				return TRUE;
			}
			else
			{
				if(m_bMultiSelect)
				{
					FOSetCursor(IDC_FO_MULTI_SELECT);
				}
				else
				{
					FOSetCursor(IDC_FO_CUROSR_IN);
				}
			}
		}
	}
	else
	{
		m_pCurHitShape = (CFODrawShape *)GetCurrentModel()->HitTest(ptLog);
		
		if (m_pCurHitShape)
		{
			if(!m_pCurHitShape->IsRotateProtect())
			{
				FOSetSystemCursor(IDC_ARROW);// IDC_FO_ROTATE_START);
				return TRUE;
			}
			else
			{
				FOSetSystemCursor(IDC_ARROW);
			}
		}
	}
	
	return FALSE;
}

BOOL CETAPDemoView::PickInShape(UINT nFlags, CPoint point, UINT nButton)
{
	CPoint ptSave = CPoint(0,0);
	m_bDoubleClicked = FALSE;
	int nSelTotal = m_listSelectComp.GetCount();
    BOOL bNeedMore = FALSE;
	if(nSelTotal <= 0)
	{
		bNeedMore = TRUE;
	}
	else
	{
		ptSave = m_ptRotating;
	}

	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		return FALSE;
	}

	m_pPrevHitShape			= NULL;
	if(nSelTotal == 1)
	{
		m_pPrevHitShape = (CFODrawShape *)GetCurrentSelectShape();
	}

	BOOL bReturn = FALSE;
	CFODrawShapeList lstUpdate;
	CFODrawShapeList m_TempList;
	if (nButton == VK_LBUTTON)
	{
		if (m_action_state == State_SelectNone)
		{
			if(!m_bMirrorFreeMode && 
				!m_bShearFreeMode &&
				!m_bBendFreeMode && 
				(m_listSelectComp.GetCount() <= 1))
			{
				CFOPortShape* pPortHit = GetCurrentModel()->HitTestPortExt(point,m_TempList, FALSE);

				if(pPortHit != NULL)
				{
					CFODrawShape *pR = pPortHit->GetParentComp();
					if(pR->IsKindOf(RUNTIME_CLASS(CFOMatherLineShape)) ||
						pR->IsKindOf(RUNTIME_CLASS(CFOVertMatherLineShape)))
					{
						pPortHit = NULL;
					}
				}

				if(pPortHit != NULL)
				{
					CFODrawShape *pR = pPortHit->GetParentComp();
					if(!pR->IsKindOf(RUNTIME_CLASS(CFOMatherLineShape)) &&
						!pR->IsKindOf(RUNTIME_CLASS(CFOVertMatherLineShape)))
					{
						int nCount = pPortHit->GetLinkCount();
						if(nCount >= 1)
						{
							pPortHit = NULL;
						}
					}
					
				}

				BOOL bLarge = TRUE;
				int nType = 0;
				if(pPortHit != NULL)
				{
					
					pPortHit->GetPropIntValue(nType, P_ID_PORT_CONNECT_TYPE);

					if(!pPortHit->CanAddMoreLink())
					{
						nType = 1;
					}

					CFODrawShape *pParent = pPortHit->GetParentComp();
					if(pParent != NULL)
					{
						CSize szSize = pParent->GetSnapRect().Size();
						if(szSize.cx < 20 && szSize.cy < 20)
						{
							bLarge = FALSE;
						}
					}
				}

				if(nType == 1)
				{
					pPortHit = NULL;
				}
				
				if(pPortHit != NULL && bLarge && GetCurrentModel()->IsAllowHoleLink() && DoStartLinkEvent(pPortHit) &&
					(m_action_state != State_PortStart) &&
					(m_action_state != State_PortStart_Begin) )
				{
 
					CFOLinkShape* pLinkComp = DoGenHoleLinkShape();
					if(pLinkComp != NULL)
					{
						pLinkComp->AddRef();
						
						CPoint ptPoints[2];
						ptPoints[0] = CPoint(0,0);
						ptPoints[1] = CPoint(0,0);
						pLinkComp->Create(ptPoints,2);
						
						if (m_pCurLinkShape != NULL)
						{
							m_pCurLinkShape->Release();
						}
						
						if (pLinkComp != NULL)
						{
							pLinkComp->AddRef();
						}
						
						m_pCurLinkShape = pLinkComp;
						
						m_pStartLinkPort = NULL;
						m_pEndLinkPort = NULL;
						m_pCurrentMovePort = pLinkComp->GetToPort();
						m_arPointsPolygon.RemoveAll();
						
						pLinkComp->Release();
						InitLinkShape();
						m_pStartLinkPort = pPortHit;
						m_pEndLinkPort = NULL;
						
						m_pCurHitShape = pPortHit->GetParentComp();
						CPoint ptCenter = pPortHit->GetLinkPoint();
						
						m_arPointsPolygon.RemoveAll();
						m_arPointsPolygon.Add(ptCenter);
						
						FOLPtoDP(&ptCenter,1);
						
						OnDrawTrackLinkLine(ptCenter,m_drawshape);
						
						pLinkComp->SetToPort(pPortHit);
						
						m_pCurrentMovePort = pLinkComp->GetFromPort();
						
						m_action_state = State_DrawLink;
						PrepareMouseCapture();
						
						bReturn = TRUE;
					}
				}
			}
		}
	}

	if(!bReturn)
	{
		CFODrawShape *pShapePick = NULL;
		if(m_TempList.GetCount() <= 0)
		{
			pShapePick = (CFODrawShape *)GetCurrentModel()->HitTest(point);
		}
		else
		{
			pShapePick = (CFODrawShape *)GetCurrentModel()->HitTest2(m_TempList, point);
		}
		if(pShapePick != NULL)
		{
			CFODrawShape *pPickChild = NULL;
			if(m_pPrevHitShape != NULL)
			{
				CFODrawShape *pParent = m_pPrevHitShape->GetMainShape();
				if(pParent == pShapePick)
				{
					if(pParent->IsKindOf(RUNTIME_CLASS(CFOCompositeShape)) && 
						!pParent->IsKindOf(RUNTIME_CLASS(CFOPSubGraphShape)) &&
						!pParent->IsKindOf(RUNTIME_CLASS(CFOGroupShape)))
					pPickChild = m_pPrevHitShape;
				}
			}

			if(HAS_BASE(pShapePick,CFOPSubGraphShape))
			{
				CRect rcOld = pShapePick->GetBoundRect();
				CFOPSubGraphShape *pGrid = static_cast<CFOPSubGraphShape *>(pShapePick);
				CFOPSubGraphShape *pHitSub = pGrid->HitExpandClickButton(point,nFlags);
				if(pHitSub != NULL)
				{
					pGrid = pHitSub;
					FinishAllBox();

					DoExpandOrCollectShape(pGrid,nFlags);
					m_ptCurrentLog = point;
					
					CRect rcSelect = GetTotalSelectBoundRect();
					RemoveAllFromSelection(FALSE);

					AddToSelection(pGrid);
					CheckSelectionChange();

					CRect rcNew = pShapePick->GetBoundRect();
					rcNew = CFODrawHelper::GetMaxRectExt(rcNew,rcOld);
					rcNew = CFODrawHelper::GetMaxRectExt(rcNew,rcSelect);
					CFODrawShapeList m_links;
					pGrid->GetAllLinks(m_links);
					if(m_links.GetCount() > 0)
					{
						CRect rc = GetCurrentModel()->GetMaxBoundsRect(m_links);
						rcNew = CFODrawHelper::GetMaxRectExt(rcNew,rc);
					}
					InvalidateRectExtend(rcNew);

					return TRUE;
				}
				else
				{
					CFODrawShape* pTextComp = (CFODrawShape*) pGrid->HitTestChild(point);
					if(pTextComp != NULL)
					{
						pShapePick = pTextComp;
					}
				}
			}

			if(HAS_BASE(pShapePick,CFOListCtrlShape))
			{
				CRect rcOld = pShapePick->GetBoundRect();
				CFOListCtrlShape *pGrid = static_cast<CFOListCtrlShape *>(pShapePick);
				if(pGrid->HitTestUpButton(point))
				{
					FinishAllBox();

					pGrid->ScrollUp();
					
					m_ptCurrentLog = point;
					
					CRect rcSelect = GetTotalSelectBoundRect();
					RemoveAllFromSelection(FALSE);

					AddToSelection(pGrid);
					CheckSelectionChange();

					CRect rcNew = pShapePick->GetBoundRect();
					rcNew = CFODrawHelper::GetMaxRectExt(rcNew,rcOld);
					rcNew = CFODrawHelper::GetMaxRectExt(rcNew,rcSelect);

					CFODrawShapeList m_links;
					pGrid->GetAllLinks(m_links);
					if(m_links.GetCount() > 0)
					{
						CRect rc = GetCurrentModel()->GetMaxBoundsRect(m_links);
						rcNew = CFODrawHelper::GetMaxRectExt(rcNew,rc);
					}
					InvalidateRectExtend(rcNew);

					return TRUE;
				}
				else if(pGrid->HitTestDownButton(point))
				{
					FinishAllBox();

					pGrid->ScrollDown();
					
					m_ptCurrentLog = point;
					
					CRect rcSelect = GetTotalSelectBoundRect();
					RemoveAllFromSelection(FALSE);

					AddToSelection(pGrid);
					CheckSelectionChange();

					CRect rcNew = pShapePick->GetBoundRect();
					rcNew = CFODrawHelper::GetMaxRectExt(rcNew,rcOld);
					rcNew = CFODrawHelper::GetMaxRectExt(rcNew,rcSelect);
					CFODrawShapeList m_links;
					pGrid->GetAllLinks(m_links);
					if(m_links.GetCount() > 0)
					{
						CRect rc = GetCurrentModel()->GetMaxBoundsRect(m_links);
						rcNew = CFODrawHelper::GetMaxRectExt(rcNew,rc);
					}
					InvalidateRectExtend(rcNew);

					return TRUE;
				}
			}
			
#ifdef _FOP_E_SOLUTION
			if(HAS_BASE(pShapePick,CFOPNewGridShape))
			{
				CFOPNewGridShape *pGrid = static_cast<CFOPNewGridShape *>(pShapePick);
				if(PickInNewGrid(pGrid,nFlags,point,nButton))
				{
					m_action_state = State_EditNewGrid;
					m_ptCurrentLog = point;

					CRect rcSelect = GetTotalSelectBoundRect();

					RemoveAllFromSelection(FALSE);
					AddToSelection(pGrid);
					CheckSelectionChange();

					CRect rcNew = pShapePick->GetBoundRect();
					rcNew = CFODrawHelper::GetMaxRectExt(rcSelect,rcNew);
					InvalidateRectExtend(rcNew);

					ClearSelectionHandles();
					return TRUE;
				}
			}
#endif

#ifdef _FOP_TABLE_SOLUTION
			if(HAS_BASE(pShapePick,CFOPTableShape))
			{
				m_pCurHitShape = pShapePick;
				CFOPTableShape *pGrid = static_cast<CFOPTableShape *>(pShapePick);
				int nCurIndex = -1;
				if(pGrid->HitTestColumn(point,nCurIndex))
				{
					m_action_state = State_ResizeColBegin;
					m_ptCurrentLog = point;

					m_rowColResized = nCurIndex;
                    m_previousTableSize = pGrid->GetColumnSize( m_rowColResized );

					ClearSelectionHandles();
					return TRUE;
				}
				else if(pGrid->HitTestRow(point,nCurIndex))
				{
					m_action_state = State_ResizeRowBegin;
					m_ptCurrentLog = point;

					m_rowColResized = nCurIndex;
                    m_previousTableSize = pGrid->GetRowSize( m_rowColResized );

					ClearSelectionHandles();
					return TRUE;
				}
				else if(pGrid->HitTestColumnHeader(point,nCurIndex))
				{
					CRect rcSelect = GetTotalSelectBoundRect();

					RemoveAllFromSelection(FALSE);
					AddToSelection(pGrid);
					CheckSelectionChange();

					pGrid->SelectOneColumn(nCurIndex);

					CRect rcNew = pShapePick->GetBoundRect();
					rcNew = CFODrawHelper::GetMaxRectExt(rcSelect,rcNew);
					InvalidateRectExtend(rcNew);

					ClearSelectionHandles();
					return TRUE;
				}
				else if(pGrid->HitTestRowHeader(point,nCurIndex))
				{

					CRect rcSelect = GetTotalSelectBoundRect();

					RemoveAllFromSelection(FALSE);
					AddToSelection(pGrid);
					CheckSelectionChange();

					pGrid->SelectOneRow(nCurIndex);

					CRect rcNew = pShapePick->GetBoundRect();
					rcNew = CFODrawHelper::GetMaxRectExt(rcSelect,rcNew);
					InvalidateRectExtend(rcNew);

					ClearSelectionHandles();
					return TRUE;
				}

				if (nButton == VK_LBUTTON)
				{
					CFOPTableCell *cellx = pGrid->HitTestGrid(point);
					
					if(cellx != NULL)
					{
						CRect rcSelect = GetTotalSelectBoundRect();
						
						RemoveAllFromSelection(FALSE);
						AddToSelection(pGrid);
						CheckSelectionChange();
						
						pGrid->ResetAllSelection();
						cellx->bSelect = TRUE;
						
						m_action_state = State_SelectTableBegin;
						
						CRect rcNew = pShapePick->GetBoundRect();
						rcNew = CFODrawHelper::GetMaxRectExt(rcSelect,rcNew);
						InvalidateRectExtend(rcNew);
						
						ClearSelectionHandles();
						return TRUE;
					}
				}
			}
			else if(HAS_BASE(pShapePick,FOXNewTableShape))
			{
				m_pCurHitShape = pShapePick;
				FOXNewTableShape *pGrid = static_cast<FOXNewTableShape *>(pShapePick);
				int nCurIndex = -1;
				if(pGrid->HitTestColumn(point,nCurIndex))
				{
					m_action_state = State_ResizeColBegin;
					m_ptCurrentLog = point;
					
					m_rowColResized = nCurIndex;
					//   m_previousTableSize = pGrid->GetColumnSize( m_rowColResized ); //sdr
					m_listSelectComp.SetPropsDirty();
					ClearSelectionHandles();
					return TRUE;
				}
				else if(pGrid->HitTestRow(point,nCurIndex))
				{
					m_action_state = State_ResizeRowBegin;
					m_ptCurrentLog = point;
					
					m_rowColResized = nCurIndex;
					// m_previousTableSize = pGrid->GetRowSize( m_rowColResized ); //sdr
					m_listSelectComp.SetPropsDirty();
					ClearSelectionHandles();
					return TRUE;
				}
				else if(pGrid->HitTestColumnHeader(point,nCurIndex))
				{
					CRect rcSelect = GetTotalSelectBoundRect();
					
					if(m_pPrevHitShape != pGrid)
					{
						RemoveAllFromSelection(FALSE);
						AddToSelection(pGrid);
					}
					CheckSelectionChange();
					
					pGrid->selectColumn(nCurIndex);
					
					CRect rcNew = pShapePick->GetBoundRect();
					rcNew = CFODrawHelper::GetMaxRectExt(rcSelect,rcNew);
					InvalidateRectExtend(rcNew);
					m_listSelectComp.SetPropsDirty();
					ClearSelectionHandles();
					return TRUE;
				}
				else if(pGrid->HitTestRowHeader(point,nCurIndex))
				{
					
					CRect rcSelect = GetTotalSelectBoundRect();
					
					if(m_pPrevHitShape != pGrid)
					{
						RemoveAllFromSelection(FALSE);
						AddToSelection(pGrid);
					}
					CheckSelectionChange();
					
					pGrid->selectRow(nCurIndex);
					
					CRect rcNew = pShapePick->GetBoundRect();
					rcNew = CFODrawHelper::GetMaxRectExt(rcSelect,rcNew);
					InvalidateRectExtend(rcNew);
					m_listSelectComp.SetPropsDirty();
					ClearSelectionHandles();
					return TRUE;
				}
				
				if (nButton == VK_LBUTTON)
				{
					CFOPNewTableCell *cellx = pGrid->HitTestGrid(point);
					
					if(cellx != NULL)
					{
						CRect rcSelect = GetTotalSelectBoundRect();
						
						if(m_pPrevHitShape != pGrid)
						{
							RemoveAllFromSelection(FALSE);
							AddToSelection(pGrid);
						}
						CheckSelectionChange();
						
						pGrid->ResetAllSelection();
						cellx->bSelect = TRUE;
						
						pGrid->StartSelection(pGrid->maMouseDownPos);
						m_action_state = State_SelectTableBegin;
						
						CRect rcNew = pShapePick->GetBoundRect();
						rcNew = CFODrawHelper::GetMaxRectExt(rcSelect,rcNew);
						InvalidateRectExtend(rcNew);
						m_listSelectComp.SetPropsDirty();
						ClearSelectionHandles();
						return TRUE;
					}
				}
			}
#endif

			if(HAS_BASE(pShapePick,CFOListCtrlShape))
			{
				CRect rcOld = pShapePick->GetBoundRect();
				CFOListCtrlShape *pGrid = static_cast<CFOListCtrlShape *>(pShapePick);
				if(pGrid->HitTestGrid(point) != NULL)
				{
					m_ptCurrentLog = point;
					
					CRect rcSelect = GetTotalSelectBoundRect();

					RemoveAllFromSelection(FALSE);
					AddToSelection(pGrid);
					CheckSelectionChange();

					CRect rcNew = pShapePick->GetBoundRect();
					rcNew = CFODrawHelper::GetMaxRectExt(rcSelect,rcNew);
					InvalidateRectExtend(rcNew);

					return TRUE;
				}
			}
#ifdef _FOP_TABLE_SOLUTION
			if(HAS_BASE(pShapePick,CFOPTableShape) && nButton != VK_RBUTTON)
			{
				CRect rcOld = pShapePick->GetBoundRect();
				CFOPTableShape *pGrid = static_cast<CFOPTableShape *>(pShapePick);
				if(pGrid->HitTestGrid(point) != NULL)
				{
					m_ptCurrentLog = point;
					
					CRect rcSelect = GetTotalSelectBoundRect();

					RemoveAllFromSelection(FALSE);
					AddToSelection(pGrid);
					CheckSelectionChange();

					CRect rcNew = pShapePick->GetBoundRect();
					rcNew = CFODrawHelper::GetMaxRectExt(rcSelect,rcNew);
					InvalidateRectExtend(rcNew);

					return TRUE;
				}
			}
			else if(HAS_BASE(pShapePick,FOXNewTableShape) && nButton != VK_RBUTTON)
			{
				CRect rcOld = pShapePick->GetBoundRect();
				FOXNewTableShape *pGrid = static_cast<FOXNewTableShape *>(pShapePick);
				if(pGrid->HitTestGrid(point) != NULL)
				{
					m_ptCurrentLog = point;
					
					CRect rcSelect = GetTotalSelectBoundRect();
					
					if(m_pPrevHitShape != pGrid)
					{
						RemoveAllFromSelection(FALSE);
						AddToSelection(pGrid);
					}
					CheckSelectionChange();
					
					CRect rcNew = pShapePick->GetBoundRect();
					rcNew = CFODrawHelper::GetMaxRectExt(rcSelect,rcNew);
					InvalidateRectExtend(rcNew);
					
					return TRUE;
				}
			}
#endif
			if(pShapePick->HitTestBreakoutWithDesignMode(point))
			{
				m_ptCurrentLog = point;
				
				CRect rcSelect = GetTotalSelectBoundRect();
				
				RemoveAllFromSelection(FALSE);
				AddToSelection(pShapePick);
				CheckSelectionChange();
				
				CRect rcNew = pShapePick->GetBoundRect();
				rcNew = CFODrawHelper::GetMaxRectExt(rcSelect,rcNew);
				InvalidateRectExtend(rcNew);
				
				return TRUE;
			}

			if(m_listSelectComp.GetCount() <= 0)
			{
				AddToSelection(pShapePick);
				lstUpdate.AddTail(pShapePick);
				pShapePick->SetMainObj(TRUE);
			}
			else
			{
				if(!(nFlags & MK_CONTROL))
				{
					BOOL bParentWithIn = FALSE;
					CFODrawShape *pParentShape = NULL;
					if(HAS_BASE(pShapePick,CFOStaticShape))
					{
						CFOStaticShape *pStatic = static_cast<CFOStaticShape *>(pShapePick);
						pParentShape = pStatic->GetMainShape();
						if(pParentShape != NULL)
						{
							bParentWithIn = TRUE;
							if(!pStatic->IsMoveProtect() && !pStatic->IsLock())
							{
								pShapePick = pStatic;
							}
							else
							{
								pShapePick = pStatic;
							}
						}
					}
				}
				
				if(m_listSelectComp.Find(pShapePick) == NULL)
				{
					if ((nFlags & MK_SHIFT || IsMultiSelectionMode()) || nFlags & MK_CONTROL)
					{
						// Get old anchor shape
						CFODrawShape *pTemp = DoGetAnchorShape();
						if(pTemp != NULL)
						{
							pTemp->SetMainObj(FALSE);
							if(lstUpdate.Find(pTemp) == NULL)
							{
								lstUpdate.AddTail(pTemp);
							}
						}
						
						// Change new anchor shape.
						pShapePick->SetMainObj(TRUE);
						if(lstUpdate.Find(pShapePick) == NULL)
						{
							lstUpdate.AddTail(pShapePick);
						}
						
						AddToSelection(pShapePick);
					}
					else
					{
						if((nSelTotal == 1) && (pPickChild != NULL))
						{
							if(lstUpdate.Find(pShapePick) == NULL)
							{
								lstUpdate.AddTail(pShapePick);
							}

							pShapePick = pPickChild;
						}
						
						lstUpdate.AddTail(&m_listSelectComp);
						
						if(lstUpdate.Find(pShapePick) == NULL)
						{
							lstUpdate.AddTail(pShapePick);
						}
						
						RemoveAllFromSelection(FALSE);

						if(HAS_BASE(pShapePick, CFOCompositeShape))
						{
							CFOCompositeShape *pComposite = static_cast<CFOCompositeShape *>(pShapePick);
							CFODrawShape *pChild = pComposite->HitTestChild(point);

							if(m_pPrevHitShape != NULL && m_pPrevHitShape == pChild)
							{
								pShapePick = pChild;
							}
						}

						AddToSelection(pShapePick);
						
						DoCorrectTabOrder();
					}
				}
				else
				{
					if (nFlags & MK_CONTROL)
					{
						CFODrawShape *pTemp = DoGetAnchorShape();
						if(pTemp != NULL)
						{
							if(pTemp != pShapePick)
							{
								pTemp->SetMainObj(FALSE);
								if(lstUpdate.Find(pTemp) == NULL)
								{
									lstUpdate.AddTail(pTemp);
								}
								
								pShapePick->SetMainObj(TRUE);
								if(lstUpdate.Find(pShapePick) == NULL)
								{
									lstUpdate.AddTail(pShapePick);
								}
							}
						}
						
					}
					else if (nButton != VK_LBUTTON)
					{
						bReturn = TRUE;
					}
					else
					{
						BOOL bRotate = FALSE;
						
						if(m_action_state == State_SelectRotate || 
							m_action_state == State_DoRotate || 
							m_action_state == State_RotateBegin)
						{
							bRotate = TRUE;
						}
						
						if ((nFlags & MK_SHIFT) && m_listSelectComp.GetCount() > 1 && !bRotate)
						{
							CFODrawShape *pTemp1 = DoGetAnchorShape();
							if(pTemp1 != NULL)
							{
								BOOL bNewMain = FALSE;
								if(pShapePick == pTemp1 && m_listSelectComp.GetCount() > 1)
								{
									bNewMain = TRUE;
								}
								
								pShapePick->SetMainObj(FALSE);
								
								// Remove from selection list.
								RemoveFromSelection(pShapePick);
								
								if(lstUpdate.Find(pShapePick) == NULL)
								{
									lstUpdate.AddTail(pShapePick);
								}
								
								if(bNewMain)
								{
									lstUpdate.AddTail(&m_listSelectComp);
									DoCorrectTabOrder();
								}
							}
							ResetToSelectMode();
						}
						else
						{
							m_bResetSelect = TRUE;
						}
					}
				}
		}
		
		if (lstUpdate.GetCount() > 0)
		{
			bReturn = TRUE;
			CheckSelectionChange();
			UpdateShapes(&lstUpdate,ptSave);
			if(m_pCurrentEditShape && m_pCurrentEditShape->GetCurrentControl())
			{
				m_pCurrentEditShape->GetCurrentControl()->RedrawWindow();
			}
			
			if(m_pCurInsideBoxShape != NULL && m_pCurInsideBoxShape->GetCurControl())
			{
				m_pCurInsideBoxShape->GetCurControl()->Refresh();
			}
		}
		
		if (nButton == VK_LBUTTON)
		{
			if (m_action_state == State_SelectNone)
			{
				BOOL bNeedMove = FALSE;
				if(!(nFlags & MK_CONTROL))
				{
					if(HAS_BASE(pShapePick,CFOStaticShape))
					{
						CFOStaticShape *pStatic = static_cast<CFOStaticShape *>(pShapePick);
						if(pStatic->GetMainShape() != NULL)
						{
							bNeedMove = TRUE;
						}
					}
				}
				
				if((!pShapePick->IsMoveProtect() && !pShapePick->IsLock()) || bNeedMove)
				{
					BOOL bAlt = GetKeyState(VK_MENU) & 0x8000;
					if((IsOleSupport() && bAlt) || (IsOleSupport() && m_bAllowDragDropToolBox))
					{
						// FO:Do ole support action.
						CFODrawShapeSet m_listCopy;
						GetCopyingShapes(&m_listCopy);
						
						DoDragDrop(&m_listCopy);
						
						bReturn = TRUE;
					}
					else
					{
//						if(!HAS_BASE(pShapePick, CNewLinkShape))
						{
							m_action_state = State_MoveBegin;
							m_ptCurrentLog = point;
							ClearSelectionHandles();
							
							if(0)//gfxData.m_bWithCADDrawing)
							{
								DoCADMoving(point, nFlags);
							}
							bReturn = TRUE;
							if(GetCurrentModel()->IsFormMode() && GetCurrentModel()->IsFormFreeSize() && bNeedMore)
							{
								CRect rcUpdate = GetCurrentModel()->GetPagePosition();
								rcUpdate.InflateRect(4,4,4,4);
								InvalidateRectExtend(rcUpdate);
							}
						}
						
					}
				}
				else
				{
					m_action_state = State_HitLocked;
				}
			}
			else
			{
				if(!pShapePick->IsRotateProtect() && !m_bTextEditing)
				{
					m_action_state = State_RotateBegin;
					bReturn = TRUE;
				}
			}
		}
	}
	else if(m_bMultiSelect)
	{
		CFODrawShapeList lstUpdatex;
		POSITION pos = m_listSelectComp.GetHeadPosition();
		while(pos !=NULL)
		{
			lstUpdatex.AddTail(m_listSelectComp.GetNext(pos));
		}
		
		RemoveAllFromSelection(FALSE);
		
		UpdateShapes(&lstUpdatex);
	}
	}

	if(GetCurrentModel()->IsFormMode())
	{
		CRect rcWnd = GetFormRect();
		InvalidateRectExtend(rcWnd);
	}

	return bReturn;
}

CFOCompositeShape* CETAPDemoView::CreateTrackShapeFile(const CString &strType)
{
	if(m_pTrackDraw != NULL)
	{
		m_pTrackDraw->Release();
		m_pTrackDraw = NULL;
		
	}
	
	CFOCompositeShape *pReturn = NULL;
	FOPRect rc = FOPRect(0,0, 100,100);
	CPoint ptTrackX = rc.CenterPoint();
	
	pReturn = new CFOCompositeShape;
	pReturn->AddRef();
	pReturn->Create(rc,_T(""));
	pReturn->SetType(IDR_D_SYM_FILE);
	
	{
		pReturn->LoadFromFile(strType);
	}
	
	rc.NormalizeRect();
	
	FOPRect rcShape = pReturn->GetSnapRect();
	
	CSize sz = CSize(rcShape.Width(), rcShape.Height());
	rc.CreateFromCenter(ptTrackX, sz);
	
	
	if(rcShape.Width()<=10 && rcShape.Height()<20)
	{
		rc = CRect(ptTrackX.x-70,ptTrackX.y-70,ptTrackX.x+70,ptTrackX.y+70);
	}
	
	pReturn->PositionShape(rc);
	return pReturn;
		
}

void CETAPDemoView::FindAllModels(CFODrawShapeSet *pShapeList, CFODataModelList *pModelList)
{
	CExtTabModel *pTabModel = (CExtTabModel *)GetCurrentModel();
	CExtTabModelManager *pMgr = (CExtTabModelManager *)pTabModel->GetManager();
	CFODrawShape *pShape = NULL;
	int xy = 0;
	for(xy = 0; xy < pShapeList->Count(); xy ++)
	{
		pShape = (CFODrawShape *)pShapeList->GetObject(xy);
		if(HAS_BASE(pShape, CBPMActTaskShape))
		{
			CBPMActTaskShape *pSubsystemCopy = static_cast<CBPMActTaskShape *>(pShape);
			CString strMethod = _T("");
			pSubsystemCopy->GetPropStringValue(strMethod, P_ID_EXT_CONNECT_FORM);
			
			if(!strMethod.IsEmpty())
			{
				CExtTabModel *pClonePage = (CExtTabModel *)pMgr->FindOnly(strMethod);
				
				if(pClonePage != NULL)
				{
					pModelList->AddTail(pClonePage);
				}
				
			}
		}
		
	}
}

void CETAPDemoView::DoSerializeStation(CFODrawShape *pObj)
{
	CExtTabModel *pTabModel = (CExtTabModel *)GetCurrentModel();
	CExtTabModelManager *pMgr = (CExtTabModelManager *)pTabModel->GetManager();
	if(pObj->IsKindOf(RUNTIME_CLASS(CBPMActTaskShape)))
	{
		CBPMActTaskShape *pSubsystemCopy = static_cast<CBPMActTaskShape *> (pObj);
		
		CString strMethod = _T("");
		pSubsystemCopy->GetPropStringValue(strMethod, P_ID_EXT_CONNECT_FORM);
		
		if(!strMethod.IsEmpty())
		{
			CExtTabModel *pClonePage = (CExtTabModel *)pMgr->FindOnly(strMethod);
			
			if(pClonePage != NULL)
			{
				DoSerializeSpecData(pSubsystemCopy, pClonePage, m_foCfStation);
			}
		
		}
	//	CString strCaption = pTabModel->GetUniqueName3(pSubsystemCopy->GetType(), &m_listSelectComp);
		
		
	}
}

BOOL CETAPDemoView::IsExchangeFormatSupported(UINT nFormat) const
{
    return( CF_UNICODETEXT == nFormat ||
		CF_TEXT == nFormat ||
		CF_OEMTEXT == nFormat ||
		GetXDClipboardFormat() == nFormat ||
		GetXDClipboardTable() == nFormat || 
		GetXDClipboardStation() == nFormat || 
		CF_BITMAP == nFormat ||
		CF_ENHMETAFILE == nFormat);
}

CLIPFORMAT CETAPDemoView::GetXDClipboardStation() const
{
	return m_foCfStation;
}

CFOCompositeShape* CETAPDemoView::CreateTrackShape(const int &nType)
{
	if(m_pTrackDraw != NULL)
	{
		m_pTrackDraw->Release();
		m_pTrackDraw = NULL;

	}

	CFOCompositeShape *pReturn = NULL;
	FOPRect rc = FOPRect(0,0, 100,100);
	CPoint ptTrackX = rc.CenterPoint();

	pReturn = new CFOCompositeShape;
	pReturn->AddRef();
	pReturn->Create(rc,_T(""));
	pReturn->SetType(nType);
	
	{
		pReturn->LoadFromResource(nType);
	}

	rc.NormalizeRect();
	
	FOPRect rcShape = pReturn->GetSnapRect();
	
	CSize sz = CSize(rcShape.Width(), rcShape.Height());
	rc.CreateFromCenter(ptTrackX, sz);
	
	
	if(rcShape.Width()<=10 && rcShape.Height()<20)
	{
		rc = CRect(ptTrackX.x-70,ptTrackX.y-70,ptTrackX.x+70,ptTrackX.y+70);
	}
	
	pReturn->PositionShape(rc);
	return pReturn;
		
}

CFORemoveCompsAction* CETAPDemoView::DoDeleteActionX(CFODrawShapeList* pShapeList1)
{
	if(pShapeList1->GetCount() <= 0)
	{
		return NULL;
	}

// 	if(pShapeList1->GetCount() == 1)
// 	{
// 		CFODrawShape *pCur = GetCurrentSelectShape();
// 		if(pCur->IsKindOf(RUNTIME_CLASS(CNewLinkShape)))
// 		{
// 			return NULL;
// 		}
// 	}

	BOOL bDone = FALSE;
	CFODrawShapeList myListShape;
//	if(pShapeList1->GetCount() == 1)
	{
		CFODrawShape *pShape = NULL;
		POSITION pos = pShapeList1->GetHeadPosition();
		while(pos != NULL)
		{
			pShape = (CFODrawShape *)pShapeList1->GetNext(pos);
			if(pShape->IsKindOf(RUNTIME_CLASS(CNewLinkShape)))
			{
				CNewLinkShape *pLink1 = static_cast<CNewLinkShape *>(pShape);
				if(myListShape.Find(pLink1) == NULL)
				{
					myListShape.AddTail(pLink1);
				}

// 				CFODrawPortsShape *pNode = pLink1->GetLinkShape();
// 				if(pNode != NULL)
// 				{
// 					myListShape.AddTail(pNode);
// 					CFODrawShapeList m_links;
// 					pNode->GetAllLinks(m_links);
// 					if(m_links.GetCount() > 0)
// 					{
// 						POSITION poslink = m_links.GetHeadPosition();
// 						while(poslink)
// 						{
// 							CFOLinkShape *pLink = (CFOLinkShape *)m_links.GetNext(poslink);
// 							if(pLink->IsKindOf(RUNTIME_CLASS(CNewLinkShape)))
// 							{
// 								if(myListShape.Find(pLink) == NULL)
// 								{
// 									myListShape.AddTail(pLink);
// 								}
// 							}
// 						}
// 					}
// 				}

				bDone = TRUE;
			}
			else if(pShape->IsKindOf(RUNTIME_CLASS(CFODrawPortsShape)))
			{
				CFODrawPortsShape *pNode = static_cast<CFODrawPortsShape *>(pShape);
				if(myListShape.Find(pNode) == NULL)
				{
					myListShape.AddTail(pNode);
				}

				if(pNode != NULL)
				{
					myListShape.AddTail(pNode);
					CFODrawShapeList m_links;
					pNode->GetAllLinks(m_links);
					if(m_links.GetCount() > 0)
					{
						POSITION poslink = m_links.GetHeadPosition();
						while(poslink)
						{
							CFOLinkShape *pLink = (CFOLinkShape *)m_links.GetNext(poslink);
							if(pLink->IsKindOf(RUNTIME_CLASS(CNewLinkShape)))
							{
								if(myListShape.Find(pLink) == NULL)
								{
									myListShape.AddTail(pLink);
								}
							}
						}
					}
				}
				
				bDone = TRUE;
			}
			else
			{
				if(myListShape.Find(pShape) == NULL)
				{
					myListShape.AddTail(pShape);
				}

			}
		}
	}
	
	BOOL bNeedDo = FALSE;
	CFODirectActionMacro *pAction = new CFODirectActionMacro(GetCurrentModel());
	CString strDescri;
	strDescri.LoadString(IDS_CMD_REMOVE_COMP);
	pAction->SetActionDescription(strDescri);
	CFODrawShapeList m_ListTemp;
	CFODrawShapeList m_ListOther;

	CFODrawShape *pShape = NULL;
	POSITION pos = myListShape.GetHeadPosition();
	while(pos != NULL)
	{
		pShape = (CFODrawShape *)myListShape.GetNext(pos);
		if(!pShape->IsDeleteProtect())
		{
			if(pShape->GetMainShape() == NULL)
			{
				m_ListTemp.AddTail((CFODrawShape *)pShape);
			}
			else
			{
				m_ListOther.AddTail((CFODrawShape *)pShape);
			}

			bNeedDo = TRUE;

			if(HAS_BASE(pShape,CFODrawPortsShape))
			{
				CFODrawPortsShape *pShapeTemp = static_cast<CFODrawPortsShape *>(pShape);

				CFODrawShapeList listPorts;
				pShapeTemp->GetAllPorts(listPorts);
				POSITION posport = listPorts.GetHeadPosition();
				CFOPortShape *pPort = NULL;
				while(posport != NULL)
				{
					pPort = (CFOPortShape* )listPorts.GetNext(posport);
					
					CFODrawShapeList *pLinkList = pPort->GetLinksList();
					POSITION poslink = pLinkList->GetHeadPosition();
					CFOLinkShape *pLinkShape = NULL;
					while(poslink != NULL)
					{
						pLinkShape = (CFOLinkShape *)pLinkList->GetNext(poslink);
						if(pLinkShape != NULL && 
							!pLinkShape->IsStartLinkLocked() &&
							!pLinkShape->IsEndLinkLocked())
						{
							BOOL bHeader = TRUE;
							CFOPortShape *pPortHead = pLinkShape->GetFromPort();
							if(pPortHead != NULL)
							{
								if(pPortHead == pPort)
								{
									bHeader = TRUE;
								}
							}
							
							CFOPortShape *pPortTail = pLinkShape->GetToPort();
							if(pPortTail != NULL)
							{
								if(pPortTail == pPort)
								{
									bHeader = FALSE;
								}
							}
					
							CFOBreakLinkAction *pActionTemp = new CFOBreakLinkAction(GetCurrentModel(), pLinkShape,bHeader);
							pActionTemp->SetOldPort(pPort);
							pActionTemp->SetNewPort(NULL);
							pAction->AddAction(pActionTemp);
						}
					}
				}
			}
			else if(HAS_BASE(pShape,CFOLinkShape))
			{
				CFOLinkShape *pLinkShape = static_cast<CFOLinkShape *>(pShape);
				
				CFOPortShape *pPortHead = pLinkShape->GetFromPort();
				if(pPortHead != NULL)
				{
					CFOBreakLinkAction *pActionTemp = new CFOBreakLinkAction(GetCurrentModel(), pLinkShape,TRUE);
					pActionTemp->SetOldPort(pPortHead);
					pActionTemp->SetNewPort(NULL);
					pAction->AddAction(pActionTemp);
				}


				CFOPortShape *pPortTail = pLinkShape->GetToPort();
				if(pPortTail != NULL)
				{
					CFOBreakLinkAction *pActionTemp = new CFOBreakLinkAction(GetCurrentModel(), pLinkShape,FALSE);
					pActionTemp->SetOldPort(pPortTail);
					pActionTemp->SetNewPort(NULL);
					pAction->AddAction(pActionTemp);
				}
			}
		}
	}

	if(m_ListOther.GetCount() > 0)
	{
		CFODrawShape *pOther = NULL;
		POSITION posother = m_ListOther.GetHeadPosition();
		while(posother != NULL)
		{
			pOther = (CFODrawShape *)m_ListOther.GetNext(posother);
			CFODrawShape *pParent = pOther->GetMainShape();
			if(pParent != NULL)
			{
				if(pParent->IsKindOf(RUNTIME_CLASS(CFOCompositeShape)))
				{
					CFOCompositeShape *pComp = static_cast<CFOCompositeShape *>(pParent);
					if(pComp->GetCompCount() <= 1)
					{
						AfxMessageBox(IDS_FOP_COMP_REMOVE,MB_OK|MB_ICONINFORMATION);
					}
					else
					{
						CFORemoveCompAction *pRemoveAction = new CFORemoveCompAction(GetCurrentModel(), pOther);
						pRemoveAction->SetCompShape(pComp);
						pAction->AddAction(pRemoveAction);
					}
				}
			}
		}
	}

	if(m_ListTemp.GetCount() > 0)
	{
		pAction->AddAction(new CExtRemoveCompsAction(GetCurrentModel(), m_ListTemp));
	}

	if(bNeedDo)
	{
		if(!GetCurrentModel()->Do(pAction, TRUE))
		{
			delete pAction;
		}

		ClearSelection();
	}
	else
	{
		delete pAction;
	}
	return NULL;
}

RndGen::~RndGen()
{ 
	if (oldrand)
		free(oldrand); 
}

void RndGen::init_random(const float randomseed)
{
    float new_random  = 1.0e-9f;
    float prev_random = randomseed;        
	
    oldrand		= (float*)calloc(55, sizeof(float));        
    oldrand[54] = randomseed;        
	
    for (int i = 0; i < 53; i ++)        
    {                
		int j = (21 * (i + 1)) % 55;                
        oldrand[j] = new_random;                
        new_random = prev_random - new_random;                
        if (new_random < 0) new_random ++;                
		prev_random = oldrand[j];        
	}        
	
    advance_random();        
    advance_random();        
    advance_random();        
    n = 0;
}

void RndGen::advance_random()
{    
    float   new_random;  
	int i = 0; 
    for (i = 0; i <= 23; i ++)        
    {               
        new_random = oldrand[i] - oldrand[i+31];              
        if (new_random < 0) 
			new_random ++;               
        oldrand[i] = new_random;       
    }               
	
    for (i = 24; i <= 54; i ++) 
    {               
        new_random = oldrand[i] - oldrand[i-24];              
        if (new_random < 0)
			new_random ++;               
        oldrand[i] = new_random;       
    }
}

float RndGen::randm()
{             
	n ++;                
	if (n > 54)         
	{                       
		n = 1;                      
		advance_random();               
	}                               
	
	return oldrand[n];
}       

CString CETAPDemoView::FOGenerateValue(int &nValue)
{
	
	double dValue1 = Rn.randm();
	double dValue2 = Rn.randm();
	double dValue3 = Rn.randm();
	nValue = (int)(dValue1 * 10);
	CString strValue1;
	strValue1.Format("%.2f\t\n", dValue1 * 10);
	
	CString strValue2;
	strValue2.Format("%.2f\t\n", dValue2);
	
	CString strValue3;
	strValue3.Format("%.2f", dValue3);
	
	return strValue1+ strValue2 + strValue3;
	
	//	pObj->dCurValue = dValue;
}

void CETAPDemoView::OnDrawLinkHotspot(CFODrawShape *pShape,const UINT &nShapeType)
{
	nShapeType;
	
	if(pShape != NULL)
	{
		// Prepare dc.
		CFOWndDC dc(this,FALSE);
		PrepareTrackLineDC(&dc);
		
		int nRop = dc.SetROP2(R2_NOTXORPEN);
		
		CPen *pOldPen = (CPen *)dc.SelectObject(GetLinkPen());
		CBrush *pPrevBrush = (CBrush *)dc.SelectStockObject(NULL_BRUSH);
		
		CArray<CPoint, CPoint> m_points;
		pShape->GetPoints(m_points);
		
		int nCount = m_points.GetSize();
		if (nCount > 0)
		{
			CPoint ptDev = m_points.GetAt(0);
			FOLPtoDP(&ptDev, 1);
			dc.MoveTo(ptDev);

			CPoint ptStart = ptDev;
			
			for (int i = 1; i < nCount; i++)
			{
				ptDev = m_points.GetAt(i);
				FOLPtoDP(&ptDev, 1);
				dc.LineTo(ptDev);
			}
	//		dc.LineTo(ptStart);
		}
		
		dc.SetROP2(nRop);
		dc.SelectObject(pPrevBrush);
		dc.SelectObject(pOldPen);
		
		// Clear dc.
		ClearTrackLineDC(&dc);
	}
	
}

void CETAPDemoView::DoShowCursorWithDrop(const CPoint &ptLog)
{
	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	
    CFODrawShape *pObj1 = pModel->HitTestOnBus(ptLog);
	if(pObj1 != NULL)
	{
		HighlitLink(pObj1, ptLog);
		if(HAS_BASE(pObj1, CFOVertMatherLineShape))
		{
			FOSetCursor(IDC_CURSOR_GLUE);
		}
		else if(HAS_BASE(pObj1, CFOMatherLineShape))
		{
			FOSetCursor(IDC_CURSOR_GLUE1);
		}
		else if(HAS_BASE(pObj1, CFOMatherDotShape))
		{
			FOSetCursor(IDC_CURSOR_GLUE1);
		}
		else
		{
			FOSetCursor(IDC_FO_CURSOR_ANCHOR);
		}
	}
	else
	{
		HighlitLink(NULL, ptLog);
		FOSetCursor(m_nCurrentCursor);
	}
}

void CETAPDemoView::OnDrawTrackOnlyDrop(CPoint ptTrackDev)
{
	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	if(m_drawshape == IDR_D_1001 ||
		m_drawshape == IDR_D_1002 ||
		m_drawshape == IDR_D_1004 ||
		m_drawshape == IDR_D_1005 ||
		m_drawshape == IDR_D_1006 ||
		m_drawshape == IDR_D_1007 ||
		m_drawshape == IDR_D_1008 ||
		m_drawshape == IDR_D_1009 ||
		m_drawshape == IDR_D_1010 ||
		m_drawshape == IDR_D_1011 ||
		m_drawshape == IDR_D_1012 ||
		m_drawshape == IDR_D_1013 ||
		m_drawshape == IDR_D_1014 ||
		m_drawshape == IDR_D_1015 ||
		m_drawshape == IDR_D_1016 ||
		m_drawshape == IDR_D_1017 ||
		m_drawshape == IDR_D_1018 ||
		m_drawshape == IDR_D_1019 ||
		m_drawshape == IDR_D_1020 ||
		m_drawshape == IDR_D_1031 ||
		m_drawshape == IDR_D_1032 ||
		m_drawshape == IDR_D_1033 ||
		m_drawshape == IDR_D_1034 ||
		m_drawshape == IDR_D_130  ||
		m_drawshape == IDR_D_1003 ||
		m_drawshape == IDR_D_SYM_FILE ||
		m_drawshape == IDR_SELECT_SHAPE
		)
	{
		
		m_ptMouseDown = ptTrackDev;
		CPoint ptTrack = m_ptMouseDown;
		FODPtoLP(&ptTrack, 1);
		LimitDrawShapeTrackPoint(&m_ptCurrentLog, &ptTrack, 1);
		FOLPtoDP(&ptTrack, 1);
		
		// Prepare dc.
		CFOWndDC dc(this);
		//	PrepareTrackLineDC(&dc);
		CPen penMark(PS_SOLID, 1, RGB(255,0,0));
		CPen* pPrevPen = (CPen*) dc.SelectObject(&penMark);
	
		CBrush *pOldBrush = (CBrush *)dc.SelectStockObject(NULL_BRUSH);
		int nPrevRop2 = dc.SetROP2(R2_NOTXORPEN);
		
		CPoint ptLog = ptTrackDev;
		FODPtoLP(&ptLog);

		FOPRect rc(ptTrack, 20);
		
		rc = CRect(ptTrack.x-30,ptTrack.y-30,ptTrack.x+30,ptTrack.y+30);
		rc.NormalizeRect();
		//	dc.Rectangle(&rc);

		if(m_pTrackDraw != NULL)
		{
			CPoint ptCenter1 = m_pTrackDraw->GetCenterPoint();
//			if(ptCenter1 != rc.Center())
			{
				m_pTrackDraw->MoveCenterTo(ptLog.x, ptLog.y);
				m_pTrackDraw->OnDrawTrack(&dc);
			}
		}
		
		
// 		if(pModel->m_nCurRotateAngle == 0)
// 		{
// 			dc.MoveTo(rc.TopCenter());
// 			dc.LineTo(rc.BottomCenter());
// 			
// 			FOPRect rcArrow;
// 			rcArrow.CreateFromCenter(rc.TopCenter(), CSize(8,8));
// 			CPoint pts[4];
// 			pts[0] = rcArrow.TopCenter();
// 			pts[1] = rcArrow.BottomLeft();
// 			pts[2] = rcArrow.BottomRight();
// 			pts[3] = pts[0];
// 			
// 			dc.Polyline(pts, 4);
// 			
// 		}
// 		else if(pModel->m_nCurRotateAngle == 1)
// 		{
// 			dc.MoveTo(rc.LeftCenter());
// 			dc.LineTo(rc.RightCenter());
// 			
// 			FOPRect rcArrow;
// 			rcArrow.CreateFromCenter(rc.LeftCenter(), CSize(8,8));
// 			CPoint pts[4];
// 			pts[0] = rcArrow.LeftCenter();
// 			pts[1] = rcArrow.TopRight();
// 			pts[2] = rcArrow.BottomRight();
// 			pts[3] = pts[0];
// 			
// 			dc.Polyline(pts, 4);
// 			
// 		}
// 		else if(pModel->m_nCurRotateAngle == 2)
// 		{
// 			dc.MoveTo(rc.TopCenter());
// 			dc.LineTo(rc.BottomCenter());
// 			
// 			FOPRect rcArrow;
// 			rcArrow.CreateFromCenter(rc.BottomCenter(), CSize(8,8));
// 			CPoint pts[4];
// 			pts[0] = rcArrow.BottomCenter();
// 			pts[1] = rcArrow.TopLeft();
// 			pts[2] = rcArrow.TopRight();
// 			pts[3] = pts[0];
// 			
// 			dc.Polyline(pts, 4);
// 			
// 		}
// 		else if(pModel->m_nCurRotateAngle == 3)
// 		{
// 			dc.MoveTo(rc.LeftCenter());
// 			dc.LineTo(rc.RightCenter());
// 			
// 			FOPRect rcArrow;
// 			rcArrow.CreateFromCenter(rc.RightCenter(), CSize(8,8));
// 			CPoint pts[4];
// 			pts[0] = rcArrow.RightCenter();
// 			pts[1] = rcArrow.TopLeft();
// 			pts[2] = rcArrow.BottomLeft();
// 			pts[3] = pts[0];
// 			
// 			dc.Polyline(pts, 4);
// 			
// 		}
		dc.SetROP2(nPrevRop2);
		dc.SelectObject(pPrevPen);
		dc.SelectObject(pOldBrush);
		penMark.DeleteObject();
		
		}

}

void CETAPDemoView::OnInitialUpdate()
{
//	SetCurrentModel(GetDocument()->m_pDataModel);
	CETAPDemoDoc* pDoc = (CETAPDemoDoc*) GetDocument();
	if(!pDoc->bOpenDocument)
	{
		CFOTabPageModel *pModel = (CFOTabPageModel *)pDoc->m_pModelManager->InsertTab();
		
	}
	
	CFOTabPageModel *pModel = GetDocument()->m_pModelManager->GetTabPtr(0);
	if(pModel != NULL)
	{
		SetTabModel(pModel);
	}
	CFOTabPageView::OnInitialUpdate();
	GetCurrentModel()->ShowPort(TRUE);
	GetCurrentModel()->ShowGrid(theApp.m_bGrid);
	GetCurrentModel()->SetHlpLineVisible(theApp.m_bGuide);
	GetCurrentModel()->EnableSnapDynGrid(theApp.m_bNewSnap);
	GetCurrentModel()->EnableSnapToControlHandle(theApp.m_bGlueToShape);
	GetCurrentModel()->EnableSnapToSpot(theApp.m_bGlueToSpot);
	m_b1stPointAsCenter = theApp.m_bDrawingFromCenter;
	GetCurrentModel()->ShowPort(theApp.m_bShowPorts);
	GetCurrentModel()->ShowMargin(theApp.m_bMargin);
	GetCurrentModel()->SetSnapToGrid(theApp.m_bGridSnap);
	EnableFreeFormDrawing(theApp.m_bFreeFormDrawing);
	
	GetCurrentModel()->EnableSnapToHelpLine(theApp.m_bSnapToHelpLine);
	GetCurrentModel()->EnableSnapToIntersectPoint(theApp.m_bSnapToIntersect);
	ShowRulers(theApp.m_bRuler);

	m_timer.Open();
}

/////////////////////////////////////////////////////////////////////////////
// CETAPDemoView printing

BOOL CETAPDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{

	// default preparation
	return CFOTabPageView::OnPreparePrinting(pInfo);

}

void CETAPDemoView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: add extra initialization before printing
	// E-XD++ Library Add line.
	CFOTabPageView::OnBeginPrinting(pDC,pInfo);
}

void CETAPDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CETAPDemoView::OnFilePrintPreview() 
{
	FOPrintPreview(this);
}

void CETAPDemoView::OnEndPrintPreview(CDC* pDC, CPrintInfo* pInfo,
							  POINT pt, CPreviewView* pView) 
{
	CScrollView::OnEndPrintPreview(pDC, pInfo,pt, pView); 

}

/////////////////////////////////////////////////////////////////////////////
// CETAPDemoView diagnostics

#ifdef _DEBUG
void CETAPDemoView::AssertValid() const
{
//E-XD++ Library add lines.
	CFOTabPageView::AssertValid();


	//CView::AssertValid();
}

void CETAPDemoView::Dump(CDumpContext& dc) const
{
//E-XD++ Library add lines.
	CFOTabPageView::Dump(dc);


	//CView::Dump(dc);
}

CETAPDemoDoc* CETAPDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CETAPDemoDoc)));
	return (CETAPDemoDoc*)m_pDocument;
}
#endif //_DEBUG

void CETAPDemoView::SelectNewShape(CFODrawShape *pShapeX)
{
	CFODrawShape *pShape = NULL;
	CFODrawShapeList lstUpdate;
	POSITION pos = m_listSelectComp.GetHeadPosition();
	while(pos != NULL)
	{
		pShape = (CFODrawShape *)m_listSelectComp.GetNext(pos);
		lstUpdate.AddTail(pShape);
		pShape->SetSelectedMode(FALSE);
	}
	
	if(pShapeX != NULL && pShapeX->IsKindOf(RUNTIME_CLASS(CFODrawShape)))
	{
		m_listSelectComp.RemoveAll();
		AddToSelection(pShapeX);
		
		if(lstUpdate.Find(pShapeX) == NULL)
		{
			lstUpdate.AddTail(pShapeX);
		}
	}
	
	if(lstUpdate.GetCount() >0)
	{
		DoCorrectTabOrder();
		UpdateShapes(&lstUpdate);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CETAPDemoView message handlers
//E-XD++ Library add line.
void CETAPDemoView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	//CView::OnPrint(pDC, pInfo);
	//E-XD++ Library Add line.
	CFOTabPageView::OnPrint(pDC,pInfo);
}


void CETAPDemoView::OnDrawC1001() 
{
	// TODO: Add your command handler code here
	m_drawshape = MY_MATHER_LINE_SHAPE;
	SetCurrentDrawingCursor(IDC_MATHER_CURSOR);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;
}

void CETAPDemoView::OnUpdateDrawC1001(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CExtTabModel *pModel = (CExtTabModel *)GetCurrentModel();
	
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	
	pCmdUI->SetCheck(m_drawshape == MY_MATHER_LINE_SHAPE && (!m_bUpRightMode) && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));

}

void CETAPDemoView::OnDrawC1002() 
{
	// TODO: Add your command handler code here
	m_drawshape = MY_VERT_MATHER_LINE_SHAPE;
	SetCurrentDrawingCursor(IDC_MATHER_CURSOR1);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;
}

void CETAPDemoView::OnUpdateDrawC1002(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CExtTabModel *pModel = (CExtTabModel *)GetCurrentModel();
	
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	
	pCmdUI->SetCheck(m_drawshape == FOP_BITMAP_SHAPE && (!m_bUpRightMode) && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));

}

void CETAPDemoView::OnDraw1001() 
{
	// TODO: Add your command handler code here
//	ResetToSelectMode();

	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;

	m_drawshape = IDR_D_1001;
	SetCurrentDrawingCursor(IDC_CURSOR_1001);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;
	m_pTrackDraw = CreateTrackShape(m_drawshape);

}

void CETAPDemoView::OnUpdateDraw1001(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1001 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
	else
		pCmdUI->SetCheck(FALSE);
}

void CETAPDemoView::OnDraw1002() 
{
	// TODO: Add your command handler code here
//	ResetToSelectMode();

	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;

	m_drawshape = IDR_D_1002;
	SetCurrentDrawingCursor(IDC_CURSOR_1002);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;


}

void CETAPDemoView::OnUpdateDraw1002(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	
	
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1002 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
	else
		pCmdUI->SetCheck(FALSE);
}

void CETAPDemoView::OnRotate900() 
{
	// TODO: Add your command handler code here
	RestoreActionState();
	
	CFODrawShapeList m_listRotate;
	GetRotatingShapes(&m_listRotate);
	if(m_listRotate.GetCount() >= 1)
	{
		DoRotateShapesActionEx(&m_listRotate,-900 * GetCanvasAxisDirection());
	}
}

void CETAPDemoView::OnUpdateRotate900(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	
	int nAll = m_listSelectComp.GetAllRotated();
	pCmdUI->Enable(nAll > 0);

}

void CETAPDemoView::OnRotate1800() 
{
	// TODO: Add your command handler code here
	RestoreActionState();
	
	CFODrawShapeList m_listRotate;
	GetRotatingShapes(&m_listRotate);
	if(m_listRotate.GetCount() >= 1)
	{
		DoRotateShapesActionEx(&m_listRotate,-1800 * GetCanvasAxisDirection());
	}
}

void CETAPDemoView::OnUpdateRotate1800(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	
	int nAll = m_listSelectComp.GetAllRotated();
	pCmdUI->Enable(nAll > 0);

}

void CETAPDemoView::OnRotate2700() 
{
	// TODO: Add your command handler code here
	RestoreActionState();
	
	CFODrawShapeList m_listRotate;
	GetRotatingShapes(&m_listRotate);
	if(m_listRotate.GetCount() >= 1)
	{
		DoRotateShapesActionEx(&m_listRotate,-2700 * GetCanvasAxisDirection());
	}
}

void CETAPDemoView::OnUpdateRotate2700(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	
	int nAll = m_listSelectComp.GetAllRotated();
	pCmdUI->Enable(nAll > 0);

}

CMenu* CETAPDemoView::CreateContextMenu()
{
	// load the menu resource
	if (m_pContextMenu)
	{
		delete m_pContextMenu;
	}
	
	CMenu* pMenu;
	m_pContextMenu = new CMenu();
	m_pContextMenu->LoadMenu(IDR_NEW_MENU);
	
	if(m_listSelectComp.GetCount() == 1)
	{
		pMenu = m_pContextMenu->GetSubMenu(0);
		AddOleToMenu(pMenu->m_hMenu);
	}
	else
	{
		pMenu = m_pContextMenu->GetSubMenu(0);
	}
	
	ASSERT_VALID(pMenu);
	return pMenu;
}

void CETAPDemoView::OnDraw1003() 
{
	// TODO: Add your command handler code here
//	ResetToSelectMode();

	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;

	m_drawshape = IDR_D_1003;
	SetCurrentDrawingCursor(IDC_CURSOR_1003);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;

	m_pTrackDraw = CreateTrackShape(m_drawshape);

}

void CETAPDemoView::OnUpdateDraw1003(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1003 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
	else
		pCmdUI->SetCheck(FALSE);
}

void CETAPDemoView::OnDraw1004() 
{
	// TODO: Add your command handler code here
//	ResetToSelectMode();

	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;

	m_drawshape = IDR_D_1004;
	SetCurrentDrawingCursor(IDC_CURSOR_1004);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;

	m_pTrackDraw = CreateTrackShape(m_drawshape);

}

void CETAPDemoView::OnUpdateDraw1004(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	 
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1004 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDraw1005() 
{
	// TODO: Add your command handler code here
//	ResetToSelectMode();

	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;

	m_drawshape = IDR_D_1005;
	SetCurrentDrawingCursor(IDC_CURSOR_1005);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;

	m_pTrackDraw = CreateTrackShape(m_drawshape);

}

void CETAPDemoView::OnUpdateDraw1005(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1005 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDraw1006() 
{
	// TODO: Add your command handler code here
//	ResetToSelectMode();

	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;

	m_drawshape = IDR_D_1006;
	SetCurrentDrawingCursor(IDC_CURSOR_1006);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;

	m_pTrackDraw = CreateTrackShape(m_drawshape);

}

void CETAPDemoView::OnUpdateDraw1006(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1006 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDraw1007() 
{
	// TODO: Add your command handler code here
//	ResetToSelectMode();

	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;

	m_drawshape = IDR_D_1007;
	SetCurrentDrawingCursor(IDC_CURSOR_1007);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;

	m_pTrackDraw = CreateTrackShape(m_drawshape);

}

void CETAPDemoView::OnUpdateDraw1007(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1007 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDraw1008() 
{
	// TODO: Add your command handler code here
//	ResetToSelectMode();

	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;

	m_drawshape = IDR_D_1008;
	SetCurrentDrawingCursor(IDC_CURSOR_1008);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;

	m_pTrackDraw = CreateTrackShape(m_drawshape);

}

void CETAPDemoView::OnUpdateDraw1008(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1008 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDraw1009() 
{
	// TODO: Add your command handler code here
//	ResetToSelectMode();

	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;

	m_drawshape = IDR_D_1009;
	SetCurrentDrawingCursor(IDC_CURSOR_1009);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;

	m_pTrackDraw = CreateTrackShape(m_drawshape);

}

void CETAPDemoView::OnUpdateDraw1009(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1009 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDraw1010() 
{
	// TODO: Add your command handler code here

//	ResetToSelectMode();

	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;

	m_drawshape = IDR_D_1010;
	SetCurrentDrawingCursor(IDC_CURSOR_1010);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;

	m_pTrackDraw = CreateTrackShape(m_drawshape);

}

void CETAPDemoView::OnUpdateDraw1010(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1010 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDraw1011() 
{
	// TODO: Add your command handler code here
//	ResetToSelectMode();

	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;

	m_drawshape = IDR_D_1011;
	SetCurrentDrawingCursor(IDC_CURSOR_1011);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;

	m_pTrackDraw = CreateTrackShape(m_drawshape);

}

void CETAPDemoView::OnUpdateDraw1011(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1011 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDraw1012() 
{
	// TODO: Add your command handler code here
//	ResetToSelectMode();

	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;

	m_drawshape = IDR_D_1012;
	SetCurrentDrawingCursor(IDC_CURSOR_1012);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;

	m_pTrackDraw = CreateTrackShape(m_drawshape);

}

void CETAPDemoView::OnUpdateDraw1012(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1012 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDraw1013() 
{
	// TODO: Add your command handler code here

//	ResetToSelectMode();

	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;

	m_drawshape = IDR_D_1013;
	SetCurrentDrawingCursor(IDC_CURSOR_1013);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;

	m_pTrackDraw = CreateTrackShape(m_drawshape);

}

void CETAPDemoView::OnUpdateDraw1013(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1013 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDraw1014() 
{
	// TODO: Add your command handler code here

//	ResetToSelectMode();

	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;

	m_drawshape = IDR_D_1014;
	SetCurrentDrawingCursor(IDC_CURSOR_1014);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;

	m_pTrackDraw = CreateTrackShape(m_drawshape);

}

void CETAPDemoView::OnUpdateDraw1014(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1014 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDraw1015() 
{
	// TODO: Add your command handler code here
//	ResetToSelectMode();

	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;

	m_drawshape = IDR_D_1015;
	SetCurrentDrawingCursor(IDC_CURSOR_1015);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;

	m_pTrackDraw = CreateTrackShape(m_drawshape);

}

void CETAPDemoView::OnUpdateDraw1015(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1015 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDraw1016() 
{
	// TODO: Add your command handler code here

//	ResetToSelectMode();

	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;

	m_drawshape = IDR_D_1016;
	SetCurrentDrawingCursor(IDC_CURSOR_1016);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;

	m_pTrackDraw = CreateTrackShape(m_drawshape);

}

void CETAPDemoView::OnUpdateDraw1016(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1016 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDraw1017() 
{
	// TODO: Add your command handler code here

//	ResetToSelectMode();

	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;

	m_drawshape = IDR_D_1017;
	SetCurrentDrawingCursor(IDC_CURSOR_1017);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;

	m_pTrackDraw = CreateTrackShape(m_drawshape);

}

void CETAPDemoView::OnUpdateDraw1017(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1017 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDraw1018() 
{
	// TODO: Add your command handler code here

//	ResetToSelectMode();

	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;

	m_drawshape = IDR_D_1018;
	SetCurrentDrawingCursor(IDC_CURSOR_1018);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;

	m_pTrackDraw = CreateTrackShape(m_drawshape);

}

void CETAPDemoView::OnUpdateDraw1018(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1018 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDraw1019() 
{
	// TODO: Add your command handler code here

//	ResetToSelectMode();

	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;

	m_drawshape = IDR_D_1019;
	SetCurrentDrawingCursor(IDC_CURSOR_1019);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;

	m_pTrackDraw = CreateTrackShape(m_drawshape);

}

void CETAPDemoView::OnUpdateDraw1019(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1019 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDraw1020() 
{
	// TODO: Add your command handler code here
//	ResetToSelectMode();

	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;

	m_drawshape = IDR_D_1020;
	SetCurrentDrawingCursor(IDC_CURSOR_1020);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;

	m_pTrackDraw = CreateTrackShape(m_drawshape);

}

void CETAPDemoView::Activate()
{
	CFrameWnd* pFrame = GetParentFrame();
	
	if (pFrame != NULL)
		pFrame->ActivateFrame();
	else
		TRACE0("Error: Can not find a frame for document to activate.\n");
	
	CFrameWnd* pAppFrame;
	if (pFrame != (pAppFrame = (CFrameWnd*)AfxGetApp()->m_pMainWnd))
	{
		ASSERT_KINDOF(CFrameWnd, pAppFrame);
		pAppFrame->ActivateFrame();
	}
	
	SetFocus();
}

void CETAPDemoView::CloseFrame()
{
	CFrameWnd* pFrame = GetParentFrame();
	
	if (pFrame != NULL)
		pFrame->SendMessage(WM_CLOSE);
}

void CETAPDemoView::OnUpdateDraw1020(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1020 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnFOPUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	pSender; // Unused.
	lHint;	 // Unused.
	if(pHint && pHint->IsKindOf(RUNTIME_CLASS(CFOAction)))
	{
		CFOAction *pAction = static_cast<CFOAction *>(pHint);
		if(ACTION_ID(pAction) == EXT_ACTION_ADDSHAPE)
		{
			BOOL bNeedMore;
			bNeedMore = FALSE;
			if(m_listSelectComp.GetCount() <= 0)
			{
				bNeedMore = TRUE;
			}
			
			CExtAddCompAction *pDoAction = static_cast<CExtAddCompAction *>(pAction);
			
			CFODrawShape* pShape = pDoAction->GetShape();
			pShape->SetParentWnd(this);
			if(pShape->IsKindOf(RUNTIME_CLASS(CFOWndControlShape)))
			{
				CreateCtrlWnd(static_cast<CFOWndControlShape*>(pShape));
			}
			else if(pShape->IsKindOf(RUNTIME_CLASS(CFOCompositeShape)))
			{
				CreateCompositeCtrlWnd(pShape);
			}
			
			CFODrawShapeList lstUpdate;
			
			BOOL bNeed = FALSE;
			FOPRect rcOldSelect;
			if(m_listSelectComp.GetCount() > 0)
			{
				rcOldSelect = m_listSelectComp.GetAllObjBoundRect();
				bNeed = TRUE;
			}
			
			RemoveAllFromSelection();
			
			if(pShape->IsVisible())
			{
				pShape->UpdateMainArea();
				AddToSelection(pShape);
			}
			
			DoCorrectTabOrder();
			
			lstUpdate.AddTailNoBackup(pShape);
		
			//				GetCurrentModel()->GetAllLinkedShape(lstUpdate, lstUpdate);
			
			FOPRect rcComp;
			rcComp = GetCompsMaxRect(&lstUpdate);
			
			FOPRect rc = pAction->GetSaveUpdateRect();
			
			if(!rc.IsRectEmpty())
			{
				if(!rc.IsIntersection(rcComp))
				{
					m_bNeedExtend = TRUE;
					InvalidateRectExtend(rc);
				}
				else
				{
					rcComp = CFODrawHelper::GetMaxRectExt(rcComp,rc);
				}
			}
			
			if(bNeed)
			{
				if(!rcOldSelect.IsIntersection(rcComp))
				{
					m_bNeedExtend = TRUE;
					InvalidateRectExtend(rcOldSelect);
				}
				else
				{
					rcComp = CFODrawHelper::GetMaxRectExt(rcComp,rcOldSelect);
				}
			}
			
			m_bNeedExtend = TRUE;
			InvalidateRectExtend(rcComp);
			
			lstUpdate.RemoveAll();

		}
		else if(ACTION_ID(pAction) == EXT_ACTION_REMOVESHAPE)
		{
			CFODrawShapeList lstUpdate;
			POSITION posx = m_listSelectComp.GetHeadPosition();
			while(posx != NULL)
			{
				lstUpdate.AddTailNoBackup(m_listSelectComp.GetNext(posx));
			}
			RemoveAllFromSelection();
			CExtRemoveCompAction *pDoAction = static_cast<CExtRemoveCompAction *>(pAction);
			CFODrawShape* pShape = pDoAction->GetShape();
			
			if(pShape->IsKindOf(RUNTIME_CLASS(CFOWndControlShape)))
			{
				DestroyCtrlWnd(static_cast<CFOWndControlShape*>(pShape));
			}
			else if(pShape->IsKindOf(RUNTIME_CLASS(CFOCompositeShape)))
			{
				DestroyCompositeCtrlWnd(pShape);
			}
			
			lstUpdate.AddTailNoBackup(pShape);
			
			CRect rcComp;
			rcComp = GetCompsMaxRect(&lstUpdate);
			
			// Get save need update rect.
			CRect rc = pAction->GetSaveUpdateRect();
			
			// Get max update rect.
			if(!rc.IsRectEmpty())
				rcComp = CFODrawHelper::GetMaxRectExt(rcComp,rc);
			RemoveAllFromSelection(TRUE);
			lstUpdate.RemoveAll();
			BOOL bNeedMore = FALSE;
			if(m_listSelectComp.GetCount() <= 0)
			{
				bNeedMore = TRUE;
			}
			
			if(GetCurrentModel()->IsFormMode() && GetCurrentModel()->IsFormFreeSize() && bNeedMore)
			{
				CRect rcUpdate = GetCurrentModel()->GetPagePosition();
				
				rcUpdate = CFODrawHelper::GetMaxRectExt(rcUpdate, rcComp);
				
				rcUpdate.InflateRect(10,10,10,10);
				InvalidateRectExtend(rcUpdate);
			}
			else
			{
				InvalidateRectExtend(rcComp);
				}
		}
		else if(ACTION_ID(pAction) == EXT_ACTION_ADDSHAPES)
		{
			BOOL bNeedMore = FALSE;
			if(m_listSelectComp.GetCount() <= 0)
			{
				bNeedMore = TRUE;
			}
			
			CFODrawShapeList lstUpdate;
			POSITION posx = m_listSelectComp.GetHeadPosition();
			while(posx != NULL)
			{
				lstUpdate.AddTailNoBackup(m_listSelectComp.GetNext(posx));
			}
			
			RemoveAllFromSelection();
			
			CFODrawShapeList listAdd;
			CExtAddCompsAction *pDoAction = static_cast<CExtAddCompsAction *>(pAction);
			CFODrawShapeList *rList = pDoAction->GetShapeList();
			BOOL bNeedSelect = TRUE;
			for (POSITION pos = rList->GetHeadPosition(); pos != NULL; )
			{
				CFODrawShape *pObj = rList->GetNext(pos);
				// #2015_01_06_001
				//					pObj->UpdateComp();
				pObj->SetParentWnd(this);
				if(pObj->IsKindOf(RUNTIME_CLASS(CFOWndControlShape)))
				{
					CreateCtrlWnd(static_cast<CFOWndControlShape*>(pObj));
				}
				else if(pObj->IsKindOf(RUNTIME_CLASS(CFOCompositeShape)))
				{
					CreateCompositeCtrlWnd(pObj);
				}
				
				if(HAS_BASE(pObj, CFOLinkShape))
				{
					CFOLinkShape *pLink = static_cast<CFOLinkShape *>(pObj);
					if(pLink->GetLayOnLink() != NULL)
					{
						bNeedSelect = FALSE;
					}
				}
				if(pObj->IsVisible())
				{
					pObj->UpdateMainArea();
					listAdd.AddTail(pObj);
					//AddToSelection(pObj);
				}
				
				//if(lstUpdate.Find(pObj) == NULL)
				{
					lstUpdate.AddTailNoBackup(pObj);
				}
				
				if(pObj->GetMainShape() != NULL)
				{
					lstUpdate.AddTailNoBackup(pObj->GetMainShape());
				}
			}
			
			if(listAdd.GetCount() > 0)
			{
				AddToSelection(&listAdd, TRUE);
			}
			
			DoCorrectTabOrder();
			
			BOOL bIsLock = IsLockUpdate();
			LockUpdate(TRUE);
			RemoveAllFromSelection();
			SelectMultiShpaes2(rList, TRUE);
			LockUpdate(bIsLock);
			
			if(GetCurrentModel()->IsFormMode() && GetCurrentModel()->IsFormFreeSize() && bNeedMore)
			{
				UpdateFormBorders();
				UpdateShapes(&lstUpdate);
			}
			else
			{
				UpdateShapes(&lstUpdate);
			}
			
			lstUpdate.RemoveAll();
			
		}
		else if(ACTION_ID(pAction) == EXT_ACTION_REMOVESHAPES)
		{
			CFODrawShapeList lstUpdate;
			POSITION posx = m_listSelectComp.GetHeadPosition();
			while(posx != NULL)
			{
				lstUpdate.AddTailNoBackup(m_listSelectComp.GetNext(posx));
			}
			RemoveAllFromSelection();
			
			CExtRemoveCompsAction *pDoAction = static_cast<CExtRemoveCompsAction *>(pAction);
			CFODrawShapeList* rList = pDoAction->GetShapeList();
			for (POSITION pos = rList->GetHeadPosition(); pos != NULL; )
			{
				CFODrawShape *pObj = (CFODrawShape *)rList->GetNext(pos);
				lstUpdate.AddTailNoBackup(pObj);
				
				if(pObj->GetMainShape() != NULL)
				{
					lstUpdate.AddTailNoBackup(pObj->GetMainShape());
				}
				
				if(pObj->IsKindOf(RUNTIME_CLASS(CFOWndControlShape)))
				{
					DestroyCtrlWnd(static_cast<CFOWndControlShape*>(pObj));
				}
				else if(pObj->IsKindOf(RUNTIME_CLASS(CFOCompositeShape)))
				{
					DestroyCompositeCtrlWnd(pObj);
				}
			}
			CRect rcComp;
			rcComp = GetCompsMaxRect(&lstUpdate);
			
			// Get save need update rect.
			CRect rc = pAction->GetSaveUpdateRect();
			
			// Get max update rect.
			if(!rc.IsRectEmpty())
				rcComp = CFODrawHelper::GetMaxRectExt(rcComp,rc);
			
			m_bNeedExtend = TRUE;
			
			lstUpdate.RemoveAll();
			
			BOOL bNeedMore;
			bNeedMore = FALSE;
			if(m_listSelectComp.GetCount() <= 0)
			{
				bNeedMore = TRUE;
			}
			
			if(GetCurrentModel()->IsFormMode() && GetCurrentModel()->IsFormFreeSize() && bNeedMore)
			{
				UpdateFormBorders();
				InvalidateRectExtend(rcComp);
			}
			else
			{
				InvalidateRectExtend(rcComp);
			}
			
		}
		else
		{
			CFODrawView::OnFOPUpdate(pSender,lHint,pHint);
		}
	}
	else
	{
		CFODrawView::OnFOPUpdate(pSender,lHint,pHint);
	}
}

CFORemoveCompsAction* CETAPDemoView::DoDeleteAction(CFODrawShapeList* pShapeList)
{
	
	return DoDeleteActionX(pShapeList);
}

void CETAPDemoView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	OnFOPUpdate(pSender,lHint,pHint);
	if(m_pCurDataModel == NULL)
	{
		return;
	}
	
	FOPRect rcForm = GetCurrentModel()->GetPagePosition();
	FOPRect rcAll = GetCurrentModel()->GetAllObjBoundRect();
	rcAll.NormalizeRect();
	CSize newSize = CSize(rcAll.right, rcAll.bottom);
	newSize += CSize(nExpSize,nExpSize);
	
	CRect rcClient;
	GetClientRect(&rcClient);
	
	CSize sz = rcClient.Size();
	FODPtoLP(&sz);
	CSize szMax = CSize(fpMax(fpMax(newSize.cx, sz.cx), rcForm.right), fpMax(fpMax(newSize.cy, sz.cy), rcForm.bottom));
	
	CPoint ptLogCenter;
	ptLogCenter.x = szMax.cx - sz.cx/2;
	ptLogCenter.y = szMax.cy - sz.cy/2;
	
	sz += CSize(nExpSize,nExpSize);
	
	CSize szForm = rcForm.Size();
	
	if(szForm.cx < newSize.cx && szForm.cy >= newSize.cy)
	{
		FOPRect rcNew = rcForm;
		rcNew = FOPRect(0,0, szMax.cx, rcForm.bottom);
		GetCurrentModel()->FormSizeChange(rcNew);
		
		
		//		DoMoveView(CPoint(0,0));
		UpdateScrollBarPos();
		UpdateScrollBarSize();
		DoUpdateView();
		UpdateRulerMap();
		//		SetLogCenter(ptLogCenter);
		FOPInvalidate(FALSE, FALSE, TRUE);
	}
	else if(szForm.cx >= newSize.cx && szForm.cy < newSize.cy)
	{
		FOPRect rcNew = rcForm;
		rcNew = FOPRect(0,0, rcForm.right, szMax.cy);
		GetCurrentModel()->FormSizeChange( rcNew);
		
		//		DoMoveView(CPoint(0,0));
		UpdateScrollBarPos();
		UpdateScrollBarSize();
		DoUpdateView();
		UpdateRulerMap();
		//		SetLogCenter(ptLogCenter);
		FOPInvalidate(FALSE, FALSE, TRUE);
	}
	else if(szForm.cx < newSize.cx || szForm.cy < newSize.cy)
	{
		FOPRect rcNew = rcForm;
		rcNew = FOPRect(0,0, szMax.cx, szMax.cy);
		GetCurrentModel()->FormSizeChange(rcNew);
		
		//		DoMoveView(CPoint(0,0));
		UpdateScrollBarPos();
		UpdateScrollBarSize();
		DoUpdateView();
		UpdateRulerMap();
		//		SetLogCenter(ptLogCenter);
		FOPInvalidate(FALSE, FALSE, TRUE);
	}
	// 	else
	// 	{
	// 		FOPRect rcNew = rcForm;
	// 		rcNew = FOPRect(0,0, fpMax(newSize.cx, sz.cx), fpMax(newSize.cy, sz.cy));
	// 		
	// 		if(rcNew.right != rcForm.right && rcNew.bottom != rcForm.bottom)
	// 		{
	// 			GetCurrentModel()->FormSizeChange(GetCurrentModel()->GetSizeFormShape(), rcNew);
	// 			UpdateScrollBarPos();
	// 			UpdateScrollBarSize();
	// 			DoUpdateView();
	// 			FOPInvalidate(FALSE, FALSE, TRUE);
	// 		}
	// 		
	// 	}

	
}

void CETAPDemoView::OnSize(UINT nType, int cx, int cy) 
{
	CFOTabPageView::OnSize(nType, cx, cy);
	
	if(m_pCurDataModel == NULL)
	{
		return;
	}
	
	// TODO: Add your message handler code here
	FOPRect rcForm = GetCurrentModel()->GetPagePosition();
	FOPRect rcAll = GetCurrentModel()->GetAllObjBoundRect();
	rcAll.NormalizeRect();
	CSize newSize = CSize(rcAll.right, rcAll.bottom);
	newSize += CSize(nExpSize,nExpSize);
	
	CRect rcClient;
	GetClientRect(&rcClient);
	
	CSize sz = rcClient.Size();
	FODPtoLP(&sz);
	sz += CSize(nExpSize,nExpSize);
	
	CSize szMax = CSize(fpMax(fpMax(newSize.cx, sz.cx), rcForm.right), fpMax(fpMax(newSize.cy, sz.cy), rcForm.bottom));
	
	CSize szInc = szMax + CSize(nExpSize,nExpSize);
	
	if(szMax.cx < newSize.cx && szMax.cy >= newSize.cy)
	{
		FOPRect rcNew = rcForm;
		rcNew = FOPRect(0,0, fpMax(fpMax(newSize.cx, sz.cx), rcForm.right), fpMax(fpMax(newSize.cy, sz.cy), rcForm.bottom));
		GetCurrentModel()->FormSizeChange( rcNew);
		
		UpdateScrollBarPos();
		UpdateScrollBarSize();
		DoUpdateView();
		FOPInvalidate(FALSE, FALSE, TRUE);
	}
	else
	{
		FOPRect rcNew = rcForm;
		rcNew = FOPRect(0,0, fpMax(newSize.cx, sz.cx), fpMax(newSize.cy, sz.cy));
		
		if(rcNew.right != rcForm.right && rcNew.bottom != rcForm.bottom)
		{
			GetCurrentModel()->FormSizeChange(rcNew);
			
			UpdateScrollBarPos();
			UpdateScrollBarSize();
			DoUpdateView();
			FOPInvalidate(FALSE, FALSE, TRUE);
		}
		
	}
}

void CETAPDemoView::OnButtonExportCanvas() 
{
	// TODO: Add your command handler code here
	m_bUpRightMode = FALSE;
	m_bWithEllipseSelect = FALSE;
	m_drawshape = FO_COMP_NONE;
	m_action_state = State_SelectNone;
	m_bWithExportSelect = TRUE;
	m_bMultiSelect = FALSE;
	FOSetSystemCursor(IDC_ARROW);
}

void CETAPDemoView::OnUpdateButtonExportCanvas(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == FO_COMP_NONE && !m_bMultiSelect && !m_bWithEllipseSelect && m_bWithExportSelect);
	}
}

void CETAPDemoView::OnDestroy() 
{

	theApp.m_bGrid = GetCurrentModel()->IsGrid();
	theApp.m_bGuide = GetCurrentModel()->IsHlpLineVisible();
	theApp.m_bNewSnap = GetCurrentModel()->IsEnableSnapDynGrid();
	theApp.m_bGlueToShape = GetCurrentModel()->IsEnableSnapToControlHandle();
	theApp.m_bGlueToSpot = GetCurrentModel()->IsEnableSnapToSpot();
	
	theApp.m_bDrawingFromCenter =m_b1stPointAsCenter;
	theApp.m_bShowPorts = GetCurrentModel()->IsPortShow();
	theApp.m_bMargin = GetCurrentModel()->HasMargin();
	theApp.m_bGridSnap = GetCurrentModel()->IsSnapToGrid();
	theApp.m_bFreeFormDrawing = m_bAllowFreeForm;
	
	theApp.m_bSnapToHelpLine = GetCurrentModel()->IsEnableSnapToHelpLine();
	theApp.m_bSnapToIntersect = GetCurrentModel()->IsEnableSnapToIntersectPoint();
	theApp.m_bRuler = IsRulerVisible();


	CFOTabPageView::OnDestroy();
	
	// TODO: Add your message handler code here
	m_timer.CancelTimer();
}

void CETAPDemoView::DoZoomScaleChanging()
{
	// Override this function to handle the zoom message.
	CMainFrame *pParent = STATIC_DOWNCAST(CMainFrame,AfxGetMainWnd());
	ASSERT_VALID(pParent);
	CString strText;
	strText.Format(_T("%d"),(int)(GetZoomScale()*100.00));
    
    pParent->pScaleBox->SetWindowText(strText);

	if(m_pCurDataModel == NULL)
	{
		return;
	}
	
	// TODO: Add your message handler code here
	FOPRect rcForm = GetCurrentModel()->GetPagePosition();
	FOPRect rcAll = GetCurrentModel()->GetAllObjBoundRect();
	CSize newSize = CSize(rcAll.right, rcAll.bottom);
	newSize += CSize(20,20);
	CRect rcClient;
	GetClientRect(&rcClient);
	CSize sz = rcClient.Size() + CSize(20,20);
	FODPtoLP(&sz);
	
	if(rcForm.Size().cx < newSize.cx || rcForm.Size().cy < newSize.cy)
	{
		FOPRect rcNew = rcForm;
		rcNew = FOPRect(0,0, FOPMax(FOPMax(newSize.cx, sz.cx), rcForm.right), FOPMax(FOPMax(newSize.cx, sz.cx), rcForm.bottom));
		GetCurrentModel()->FormSizeChange( rcNew);
		
		UpdateScrollBarSize();
		//	FOPInvalidate(FALSE);
	}
	else
	{
		FOPRect rcNew = rcForm;
		rcNew = FOPRect(0,0, FOPMax(newSize.cx, sz.cx), FOPMax(newSize.cy, sz.cy));
		
		if(rcNew.right != rcForm.right && rcNew.bottom != rcForm.bottom)
		{
			GetCurrentModel()->FormSizeChange(rcNew);
			
			UpdateScrollBarSize();
			//	FOPInvalidate(FALSE);
		}
		
	}
}

void CETAPDemoView::OnFontScaleChange()
{
	CMainFrame *pParent = STATIC_DOWNCAST(CMainFrame,AfxGetMainWnd());
	ASSERT_VALID(pParent);
    
    int nSelection = pParent->pScaleBox->GetCurSel();
    int nPercent = 100;
    
    switch (nSelection)
	{
    case 0:
		nPercent = 10;
		break;
    case 1:
		nPercent = 20;
		break;
    case 2:
		nPercent = 40;
		break;
    case 3:
		nPercent = 80;
		break;
    case 4:
		nPercent = 100;
		break;
    case 5:
		nPercent = 200;
		break;
    case 6:
		nPercent = 300;
		break;
    case 7:
		nPercent = 400;
		break;
    case 8:
		nPercent = 600;
		break;
    case 9:
		nPercent = 800;
		break;	
    }
	
    SetZoomScale(nPercent);
}

void CETAPDemoView::OnShowOrHideBox() 
{
	// TODO: Add your command handler code here
	theApp.bWithDotShow = !theApp.bWithDotShow;
	FOPInvalidate(FALSE,FALSE, FALSE);
}

void CETAPDemoView::OnUpdateShowOrHideBox(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(theApp.bWithDotShow);
}


#if _MFC_VER >= 0x0421

BOOL CETAPDemoView::OnMouseWheel(UINT nFlags, short zDelta, CPoint point1)
{
	CPoint pt(point1);
	ScreenToClient(&pt);
	CPoint point = pt;
	
	if (zDelta < 0)
	{
		ZoomOut2(point);
		
		return TRUE;
	}
	else if (zDelta > 0)
	{
		ZoomIn2(point);
		return TRUE;
	}
	return TRUE;
}
#endif

void CETAPDemoView::GetCopyingShapes(CFODrawShapeSet* pShapeList1)
{
	ASSERT(pShapeList1 != NULL);
	CFODrawShapeList listShape;
	
	{
		CFODrawShape *pShape = NULL;
		POSITION pos = m_listSelectComp.GetHeadPosition();
		while(pos != NULL)
		{
			pShape = (CFODrawShape *)m_listSelectComp.GetNext(pos);
			if(!pShape->IsKindOf(RUNTIME_CLASS(CNewLinkShape)))
			{
				listShape.AddTail(pShape);
			}
		}
	}
	
	CFODrawShape *pShape = NULL;
	POSITION pos = listShape.GetHeadPosition();
	while(pos != NULL)
	{
		pShape = (CFODrawShape *)listShape.GetNext(pos);
		if(!pShape->IsCopyProtect())
		{
			pShapeList1->AddTail(pShape);
		}
	}
}

void CETAPDemoView::DoDrawSelectShapes(CDC *pDC,const CRect &rcView)
{
	if (pDC->IsPrinting())
	{
		return;
	}
	
	int nMainSaveDC = pDC->SaveDC();
	
	int nTotalSelect = m_listSelectComp.GetCount();
	
	CArray<CPoint,CPoint> arHandles;
	
	
	BOOL bRotate = FALSE;
	
	if(m_action_state == State_SelectRotate || 
		m_action_state == State_DoRotate || 
		m_action_state == State_RotateBegin)
	{
		bRotate = TRUE;
	}
	CBrush brSecond(gfxData.crUnSelectCompColor);
	if(!m_bShearFreeMode && !m_bBendFreeMode)
	{
		CFODrawShape *pObjTemp = m_pInFocusShape;
		if(pObjTemp != NULL)
		{
			if(BeWithIn(pObjTemp, rcView))
			{
				int nMainSaveDC = pDC->SaveDC();
				
				CPen* pOldPen = (CPen*)pDC->SelectStockObject(BLACK_PEN);
				CBrush* pOldBrush = (CBrush*)pDC->SelectObject(&brSecond);
				//		DoDrawSingleSelectShapes(pDC,rcView, pObjTemp);
				FOPRect rcBound = pObjTemp->GetSnapRect();
				
				CPoint ptTopLeft = CPoint(rcBound.right,rcBound.top);
				
				if(IsMultiSpots(pObjTemp))
				{
					ptTopLeft = pObjTemp->GetPointAt(pObjTemp->GetSpotCount() - 1);
				}
				DoDrawAdditionalItems(pDC,ptTopLeft);
				if(pObjTemp->IsNeedForDB() && m_bShowAll)
				{
					DoDrawDBName(pDC, pObjTemp->GetDBVarName(), rcBound.TopRight());
				}
				
				pDC->SelectObject(pOldPen);
				pDC->SelectObject(pOldBrush);
				pDC->RestoreDC(nMainSaveDC);
			}
		}
	}

	if( nTotalSelect == 1 && (!m_bShearFreeMode && !m_bBendFreeMode))
	{
		// Updated for drawing with selection state.
		CFODrawShape *pCur = GetCurrentSelectShape();
		if(pCur->m_bWithInView)
		{
			DoDrawSingleSelectShapes(pDC,rcView, pCur);
		}
	}
	else if(nTotalSelect >= 1)
	{
		CFODrawShapeList m_listDraw;
		
		CFODrawShape *pObjTemp = NULL;
		POSITION pos = m_listSelectComp.GetHeadPosition();
		while(pos != NULL)
		{
			pObjTemp = m_listSelectComp.GetNext(pos);
			if(BeWithIn(pObjTemp,rcView))
			{
				m_listDraw.AddTail(pObjTemp);
			}
		}

		if(m_listDraw.GetCount() > 0)
		{
			int nMainSaveDC = pDC->SaveDC();
			
			CPen* pOldPen = (CPen*)pDC->SelectStockObject(BLACK_PEN);
			CBrush* pOldBrush = (CBrush*)pDC->SelectObject(GetSecondaryBrush());
			
			DoDrawMultiShapesOrderLine(pDC,&m_listDraw, rcView);
			if(m_bWithAdvanceOpt)
			{
				DoDrawMultiSelectShapes(pDC,rcView);
			}
			
			pDC->SelectObject(pOldPen);
			pDC->SelectObject(pOldBrush);
			pDC->RestoreDC(nMainSaveDC);

// 			BOOL bSave = theApp.bWithDotShow;
// 			theApp.bWithDotShow = FALSE;
// 			int mode = pDC->SetBkMode(TRANSPARENT);
// 			CBrush *pOldBrush = (CBrush *)pDC->SelectStockObject(NULL_BRUSH);
// 			CPen newpen(PS_SOLID, 1, RGB(255,0,0));
// 			CPen *pOldPen = (CPen *)pDC->SelectObject(&newpen);
// 			
// 			CFODrawShape *pObj = NULL;
// 			POSITION posTemp = m_listDraw.GetHeadPosition();
// 			while(posTemp != NULL)
// 			{
// 				pObj = (CFODrawShape *)m_listDraw.GetNext(posTemp);
// 				if(pObj != NULL)
// 				{
// 					if(HAS_BASE(pObj, CFOCompositeShape))
// 					{
// 						DoDrawSingleSelectShapes(pDC,rcView, pObj);
// 					}
// 					else
// 					{
// 						pObj->OnDrawTrack(pDC);
// 					}
// 					
// 				}
// 			}
// 			
// 			pDC->SelectObject(pOldPen);
// 			pDC->SelectObject(pOldBrush);
// 			pDC->SetBkMode(mode);
// 			newpen.DeleteObject();
// 			theApp.bWithDotShow = bSave;
		}

	}
	
    if(m_pCurHilightShape != NULL)
	{
		if(BeWithIn(m_pCurHilightShape,rcView))
		{
			m_pCurHilightShape->OnDrawTrack(pDC);
		}
	}
	
	pDC->RestoreDC(nMainSaveDC);
}

BOOL CETAPDemoView::PickMultiShapesResizeHandle(CPoint ptHit, int& nSpotIndex)
{
//	if(IsAllSelectShapesCannotResized() && !(m_bShearFreeMode || m_bMirrorFreeMode || m_bBendFreeMode))
	{
		return FALSE;
	}
}

void CETAPDemoView::OnMatherDot() 
{
	// TODO: Add your command handler code here
	m_drawshape = MY_MATHER_DOT_SHAPE;
	SetCurrentDrawingCursor(IDC_MATHER_CURSOR);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;
}

void CETAPDemoView::OnUpdateMatherDot(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == MY_MATHER_DOT_SHAPE && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDrawSubGraph() 
{
	// TODO: Add your command handler code here
	m_drawshape = BPM_ACT_TASK_SHAPE;
	SetCurrentDrawingCursor(IDC_FO_DRAWSHAPE_CURSOR);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;
}

void CETAPDemoView::OnUpdateDrawSubGraph(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == 620 && (m_nNumberArrow	== 0) && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}
 
void CETAPDemoView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	
	if(GetCurrentModel()->IsDesignMode())
	{
		if(m_action_state == State_SelectNone)
		{
			CPoint local = point;
			FODPtoLP(&local);
			CFODrawShape *pObjXX = (CFODrawShape *)GetCurrentModel()->HitTest(local);
			CString str;
			if(pObjXX != NULL)
			{
				BOOL bCtl = GetKeyState(VK_CONTROL) < 0;
				if(!bCtl)
				{
					if(HAS_BASE(pObjXX, CFOVertMatherLineShape) ||
						HAS_BASE(pObjXX, CFOMatherLineShape) ||
						HAS_BASE(pObjXX, CFOMatherDotShape)
						)
					{
						CString strMethod = _T("");
						pObjXX->GetPropStringValue(strMethod, P_ID_MATHER_TEXT1);
						
//						return;
						
					}
					else if(pObjXX->IsKindOf(RUNTIME_CLASS(CBPMActTaskShape)))
					{
						CFOPMDIChildWnd* pChildFrame = (CFOPMDIChildWnd *)((CMDIFrameWnd*)::AfxGetMainWnd())->MDIGetActive();
						if (pChildFrame)
						{
							CBPMActTaskShape *pSub = static_cast<CBPMActTaskShape *>(pObjXX);
							CString strMethod = _T("");
							pSub->GetPropStringValue(strMethod, P_ID_EXT_CONNECT_FORM);
							if(strMethod.IsEmpty())
							{
								if(pChildFrame->IsKindOf(RUNTIME_CLASS(CChildFrame)))
								{
									CChildFrame *child = static_cast<CChildFrame *>(pChildFrame);
									CString strPage = child->DoAddNewPage();
									pSub->PutPropStringValue(P_ID_EXT_CONNECT_FORM, strPage);
								}
							}
							else
							{
								if(pChildFrame->IsKindOf(RUNTIME_CLASS(CChildFrame)))
								{
									CChildFrame *child = static_cast<CChildFrame *>(pChildFrame);
									if(!child->IsPageExist(strMethod))
									{
										CExtTabModel*pCurMo = (CExtTabModel*)child->AddNewPage2(strMethod);
										child->ActivatePage(strMethod);
									}
									else
										child->ActivatePage(strMethod);
								}
							}
						}
						return;
						
					}
					else if(!pObjXX->IsKindOf(RUNTIME_CLASS(CNewLinkShape)))
					{
						//						AfxMessageBox(_T("Double clicked on this shape!"), MB_OK|MB_ICONINFORMATION);
						CString strMethod = _T("");
						pObjXX->GetPropStringValue(strMethod, P_ID_CAPTION);
						
	//					return;
						
					}
					else if(pObjXX->IsKindOf(RUNTIME_CLASS(CNewLinkShape)))
					{
						
						CNewLinkShape *pLink = static_cast<CNewLinkShape *>(pObjXX);
						if(!pLink->GetMarkRect().PtInRect(local))
						{	
							//							CFODrawPortsShape *pLinkShape = pLink->GetLinkShape();
							//							CPropLinkDlg dlg;
							//							dlg.DoModal();
							
		//					return;
						}
					}
				}				
			}
		}
		else if(m_action_state == State_DoOnlyDrop ||
			m_action_state == State_OnlyDrop ||
			m_action_state == State_OnlyDropStart)
		{
			OnDrawTrackOnlyDrop(m_ptMouseDown);
			
			m_drawshape = FO_COMP_NONE;
			m_bUpRightMode = FALSE;
			ResetToSelectMode();
			FOSetSystemCursor(IDC_ARROW);

			return;
		}
	}

	CFOTabPageView::OnLButtonDblClk(nFlags, point);
}


void CETAPDemoView::HandleTimer(UINT nIDEvent)
{
	CFODrawShapeList lstUpdate;
	LockUpdate(TRUE);
	CFODrawShape *pShape = NULL;
	int xy = 0;
	for(xy = 0; xy < GetCurrentModel()->GetShapes()->Count(); xy ++)
	{
		int nCurValue = 0;
		pShape = (CFODrawShape *)GetCurrentModel()->GetShapes()->GetObject(xy);
		if(HAS_BASE(pShape, CFOMatherLineShape))
		{
			CFOMatherLineShape *pMather = static_cast<CFOMatherLineShape *>(pShape);
			pMather->strLabel = FOGenerateValue(nCurValue);
			lstUpdate.AddTail(pShape);
		}
		else if(HAS_BASE(pShape, CFOVertMatherLineShape))
		{
			CFOVertMatherLineShape *pMather = static_cast<CFOVertMatherLineShape *>(pShape);
			pMather->strLabel = FOGenerateValue(nCurValue);
			lstUpdate.AddTail(pShape);
		}
		else if(HAS_BASE(pShape, CNewLinkShape))
		{
			CNewLinkShape *pMather = static_cast<CNewLinkShape *>(pShape);
			pMather->strLabel = FOGenerateValue(nCurValue);
			pMather->DoAnimate();
			lstUpdate.AddTail(pShape);
		}
		else if(HAS_BASE(pShape, CFOCompositeShape))
		{
			CFOCompositeShape *pComp = static_cast<CFOCompositeShape *>(pShape);
			int nValue = 0;
			FOGenerateValue(nValue);
			
			if(nValue < 3)
			{
				pComp->SetGroupLineColor(RGB(0,255,0));	
			}
			else if(nValue >8)
			{
				pComp->SetGroupLineColor(RGB(255,255,0));
			}
			else
			{
				pComp->SetGroupLineColor(RGB(255,0,0));
			}
			lstUpdate.AddTail(pShape);
		}
	}
	
	LockUpdate(FALSE);
	
	if(lstUpdate.GetCount() >0)
	{
		UpdateVisibleShapes(&lstUpdate);
	}
}

// Display next cell in animation sequence 
LRESULT CETAPDemoView::UpdateAnimation(WPARAM wParam, LPARAM lParam)
{
    HandleTimer(wParam);
	
    return 0;
}

void TimerFunction(void* obj, UINT idEvent)
{
	CETAPDemoView* dlg = (CETAPDemoView*) obj;
	if(dlg != NULL)
	{
		dlg->PostMessage(UWM_UPDATE_ANIMATION, idEvent);
		//		dlg->HandleTimer(idEvent);
	}
}

void CETAPDemoView::StartTimer(UINT nID, UINT nTime)
{
	m_timer.SetTimer(nID, nTime, TimerFunction, this);
}

void CETAPDemoView::OnRun() 
{
	// TODO: Add your command handler code here
	if(m_timer.IsTimerSet())
	{
		m_timer.CancelTimer();
		GetCurrentModel()->SetDesignMode(TRUE);
		FOPInvalidate();
	}
	else
	{
		StartTimer(1022, 200);
		GetCurrentModel()->SetDesignMode(FALSE);
		FOPInvalidate();
	}
}

void CETAPDemoView::OnUpdateRun(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_timer.IsTimerSet());
}

void CETAPDemoView::OnHideAllSnap() 
{
	// TODO: Add your command handler code here
	gfxData.m_bWithSnap = !gfxData.m_bWithSnap;
}

void CETAPDemoView::OnUpdateHideAllSnap(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(!gfxData.m_bWithSnap);
}

void CETAPDemoView::ResetToSelectMode()
{
	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	if(m_pTrackDraw != NULL)
	{
		m_pTrackDraw->Release();
		m_pTrackDraw = NULL;
		
	}

	pModel->m_nCurRotateAngle = 0;
	m_action_state = State_SelectNone;
	m_bMultiSelect = FALSE;
	m_ptSaveGlue   = CPoint(-3421,-3421);
	m_bAllowDragDropToolBox = FALSE;
	m_drawshape = FO_COMP_NONE;

	FOPInvalidate();
}

void CETAPDemoView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
//	CFOTabPageView::OnRButtonUp(nFlags, point);
	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	CPoint local = point;
	if(m_pluginList.GetCount() > 0)
	{
		BOOL bOK = FALSE;
		
		CPoint ptHit = local;
		FODPtoLP(&ptHit,1);
		POSITION posevent = m_pluginList.GetHeadPosition();
		while (posevent)
		{
			FOPMsgHandleTool* pEvent = (FOPMsgHandleTool*) m_pluginList.GetNext(posevent);
			if(pEvent->OnRButtonUp(nFlags,ptHit))
			{
				bOK = TRUE;
				if(pEvent->IsResetAfterRButtonUp())
				{
					DetachPlugin(pEvent->GetId());
					m_action_state = State_SelectNone;
					FOSetSystemCursor(IDC_ARROW);
				}
			}
		}
		
		if(bOK)
		{
			return;
		}
	}
	
	m_pCurMovingObj			= NULL;
	if(!GetCurrentModel()->IsDesignMode())
	{
		CPoint ptLogi = point;
		FODPtoLP(&ptLogi);
		
		CFODrawShape *pObj = NULL;
		if(m_ptMouseDown == point)
		{
			pObj = m_pSavePrevHitShape;
		}
		else
		{
			BOOL bHas = FALSE;
			if(m_pSavePrevHitShape != NULL)
			{
				FOPRect rc = m_pSavePrevHitShape->GetSnapRect();
				if(rc.PtInRect(ptLogi))
				{
					int dSpace = GetCurrentModel()->fo_DefaultSnapLineSizPix;
					
					CFOArea rgn;
					rgn = m_pSavePrevHitShape->GetShapeArea(); 
					
					if (rgn.PickInArea(ptLogi, (int)dSpace))
					{
						pObj = m_pSavePrevHitShape;
						bHas = TRUE;
					}
				}
			}
			
			if(!bHas)
			{
				pObj = (CFODrawShape *)GetCurrentModel()->HitTestRunTime(ptLogi);
			}
		}
		
		if(DoRButtonUpHitRunTime(pObj, ptLogi, nFlags))
		{
			return;
		}
		
		HitEventWithClick(pObj, ptLogi, nFlags);
		if(pObj != NULL)
		{
			if(pObj->IsKindOf(RUNTIME_CLASS(CFODrawShape)))
			{
				CFODrawShape *pControl = static_cast<CFODrawShape *>(pObj);
				pControl->SetParentWnd(this);
				pControl->OnRButtonUp(nFlags,ptLogi);
			}
		}
		return;
	}

	if(m_action_state == State_DoOnlyDrop)
	{
		if(m_drawshape == BPM_ACT_TASK_SHAPE)
		{
			CFOTabPageView::OnRButtonUp(nFlags, point);
			return;
		}
		OnDrawTrackOnlyDrop(m_ptMouseDown);
		pModel->m_nCurRotateAngle ++;

		if(pModel->m_nCurRotateAngle > 3)
		{
			pModel->m_nCurRotateAngle = 0;
		}

		if(pModel->m_nCurRotateAngle == 0)
		{
			if(m_pTrackDraw != NULL)
			{
				m_pTrackDraw->Release();
				m_pTrackDraw = NULL;
					
			}

			if(m_drawshape == IDR_D_SYM_FILE)
			{
				m_pTrackDraw = (CFOCompositeShape *)CreateTrackShapeFile(pModel->m_strSymFile);
			}
			else if(m_drawshape == IDR_SELECT_SHAPE)
			{
				FOPRect rc = FOPRect(0,0, 100,100);
				CPoint ptTrackX = rc.CenterPoint();
				CFOCompositeShape* pReturn = (CFOCompositeShape *)pModel->m_pCurSelect->Copy(); // First
				
				pReturn->AddRef();
				pReturn->SetType(IDR_SELECT_SHAPE);
				rc.NormalizeRect();
				
				FOPRect rcShape = pReturn->GetSnapRect();
				
				CSize sz = CSize(rcShape.Width(), rcShape.Height());
				rc.CreateFromCenter(ptTrackX, sz);
				
				
				if(rcShape.Width()<=10 && rcShape.Height()<20)
				{
					rc = CRect(ptTrackX.x-70,ptTrackX.y-70,ptTrackX.x+70,ptTrackX.y+70);
				}
				
				pReturn->PositionShape(rc);
				m_pTrackDraw = pReturn;
			}
			else
			{
				m_pTrackDraw = (CFOCompositeShape *)CreateTrackShape(m_drawshape);
			}
	
		}
		else
		{
			if(m_pTrackDraw != NULL)
			{
				m_pTrackDraw->Release();
				m_pTrackDraw = NULL;
				
			}
			if(m_drawshape == IDR_D_SYM_FILE)
			{
				m_pTrackDraw = (CFOCompositeShape *)CreateTrackShapeFile(pModel->m_strSymFile);
			}
			else if(m_drawshape == IDR_SELECT_SHAPE)
			{
				FOPRect rc = FOPRect(0,0, 100,100);
				CPoint ptTrackX = rc.CenterPoint();
				CFOCompositeShape* pReturn = (CFOCompositeShape *)pModel->m_pCurSelect->Copy(); // First
				
				pReturn->AddRef();
				pReturn->SetType(IDR_SELECT_SHAPE);
				rc.NormalizeRect();
				
				FOPRect rcShape = pReturn->GetSnapRect();
				
				CSize sz = CSize(rcShape.Width(), rcShape.Height());
				rc.CreateFromCenter(ptTrackX, sz);
				
				
				if(rcShape.Width()<=10 && rcShape.Height()<20)
				{
					rc = CRect(ptTrackX.x-70,ptTrackX.y-70,ptTrackX.x+70,ptTrackX.y+70);
				}
				
				pReturn->PositionShape(rc);
				m_pTrackDraw = pReturn;
			}
			else
			{
				m_pTrackDraw = (CFOCompositeShape *)CreateTrackShape(m_drawshape);
			}
			CPoint rcnew = m_pTrackDraw->GetSnapRect().CenterPoint();
			
			m_pTrackDraw->RotateShape(-900 * pModel->m_nCurRotateAngle,rcnew.x, rcnew.y);
			
		}

		OnDrawTrackOnlyDrop(m_ptMouseDown);
		return;
	}
	else
	{
		CFOTabPageView::OnRButtonUp(nFlags, point);
	}
}

void CETAPDemoView::OnDrawOpenSym() 
{
	// TODO: Add your command handler code here
	CString strFilter = _T("Symbol files (*.sid)|*.sid|");
	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	CFileDialog dlgFile (TRUE,NULL,NULL,OFN_HIDEREADONLY| OFN_OVERWRITEPROMPT,strFilter,CanvasWnd());
	if(dlgFile.DoModal() == IDOK)
	{
		
	//	ResetToSelectMode();
		
		pModel->m_nCurRotateAngle = 0;
		pModel->m_strSymFile = dlgFile.GetPathName();
		
		m_drawshape = IDR_D_SYM_FILE;
		SetCurrentDrawingCursor(IDC_FO_DROP_CURSOR);
		m_action_state = State_OnlyDrop;
		m_bUpRightMode = FALSE;
		m_pTrackDraw = CreateTrackShapeFile(pModel->m_strSymFile);
	}

}

void CETAPDemoView::OnUpdateDrawOpenSym(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_SYM_FILE && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDrawShortH() 
{
	// TODO: Add your command handler code here
	m_drawshape = MY_MATHER_SHORT_H_SHAPE;
	SetCurrentDrawingCursor(IDC_MATHER_CURSOR);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;
}

void CETAPDemoView::OnUpdateDrawShortH(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CExtTabModel *pModel = (CExtTabModel *)GetCurrentModel();
	
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	pCmdUI->SetCheck(m_drawshape == MY_MATHER_SHORT_H_SHAPE && (!m_bUpRightMode) && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));

}

void CETAPDemoView::OnDrawShortV() 
{
	// TODO: Add your command handler code here
	m_drawshape = MY_MATHER_SHORT_V_SHAPE;
	SetCurrentDrawingCursor(IDC_MATHER_CURSOR1);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;
}

void CETAPDemoView::OnUpdateDrawShortV(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CExtTabModel *pModel = (CExtTabModel *)GetCurrentModel();
	
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	pCmdUI->SetCheck(m_drawshape == MY_MATHER_SHORT_V_SHAPE && (!m_bUpRightMode) && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));

}

void CETAPDemoView::OnDrawDoubleH() 
{
	// TODO: Add your command handler code here
	m_drawshape = MY_MATHER_SHORT_DOUBLE_H_SHAPE;
	SetCurrentDrawingCursor(IDC_MATHER_CURSOR3);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;
}

void CETAPDemoView::OnUpdateDrawDoubleH(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CExtTabModel *pModel = (CExtTabModel *)GetCurrentModel();
	
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	pCmdUI->SetCheck(m_drawshape == MY_MATHER_SHORT_DOUBLE_H_SHAPE && (!m_bUpRightMode) && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));

}

void CETAPDemoView::OnDrawDoubleV() 
{
	// TODO: Add your command handler code here
	m_drawshape = MY_MATHER_SHORT_DOUBLE_V_SHAPE;
	SetCurrentDrawingCursor(IDC_MATHER_CURSOR2);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;
}

void CETAPDemoView::OnUpdateDrawDoubleV(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CExtTabModel *pModel = (CExtTabModel *)GetCurrentModel();
	
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	pCmdUI->SetCheck(m_drawshape == MY_MATHER_SHORT_DOUBLE_V_SHAPE && (!m_bUpRightMode) && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));

}

void CETAPDemoView::OnDraw3H() 
{
	// TODO: Add your command handler code here
	m_drawshape = MY_MATHER_SHORT_3_H_SHAPE;
	SetCurrentDrawingCursor(IDC_MATHER_CURSOR5);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;
}

void CETAPDemoView::OnUpdateDraw3H(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CExtTabModel *pModel = (CExtTabModel *)GetCurrentModel();
	
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	pCmdUI->SetCheck(m_drawshape == MY_MATHER_SHORT_3_H_SHAPE && (!m_bUpRightMode) && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));

}

void CETAPDemoView::OnDraw3V() 
{
	// TODO: Add your command handler code here
	m_drawshape = MY_MATHER_SHORT_3_V_SHAPE;
	SetCurrentDrawingCursor(IDC_MATHER_CURSOR4);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;
}

void CETAPDemoView::OnUpdateDraw3V(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CExtTabModel *pModel = (CExtTabModel *)GetCurrentModel();
	
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	pCmdUI->SetCheck(m_drawshape == MY_MATHER_SHORT_3_V_SHAPE && (!m_bUpRightMode) && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));

}

void CETAPDemoView::DoSerializeData(CFODrawShapeSet* pShapeList)
{
	ASSERT(pShapeList != NULL);
	
	CFODataModelList m_list;
	FindAllModels(pShapeList, &m_list);

	DoSerializeComplexData(pShapeList, &m_list, m_foCfStation);
}

void CETAPDemoView::DoSerializeLoadData(COleDataObject &dataObject, CFODrawShapeList* pShapeList, CFODataModelList *pModelList)
{
	DoLoadComplexData(pShapeList, pModelList, m_foCfStation);
}

void CETAPDemoView::DoWithModels(CFODataModelList *pModelList)
{
	
}

CFODataModel *CETAPDemoView::FindInModels(const CString &strName, CFODataModelList *pModelList)
{
	CExtTabModel *pModel = NULL;
	POSITION pos = pModelList->GetHeadPosition();
	while(pos != NULL)
	{
		pModel = (CExtTabModel *)pModelList->GetNext(pos);
		if(pModel != NULL)
		{
			if(pModel->m_strCaption == strName)
			{
				return pModel;
			}
		}
		
	}

	return NULL;
}

void CETAPDemoView::AddPasteToModel(CFODrawShapeList* pShapeList, CFODataModelList *pModelList)
{
	CFODrawShape *pShape = NULL;
	CExtTabModel *pTabModel = (CExtTabModel *)GetCurrentModel();
	CExtTabModelManager *pMgr = (CExtTabModelManager *)pTabModel->GetManager();
	CFODrawShapeSet m_ListTemp;
	POSITION posShape = pShapeList->GetHeadPosition();
	while(posShape != NULL)
	{
		pShape = (CFODrawShape* )pShapeList->GetNext(posShape);
		
		if(HAS_BASE(pShape, CBPMActTaskShape))
		{
			CBPMActTaskShape *pSubsystemCopy = static_cast<CBPMActTaskShape *>(pShape);
			CString strMethod = _T("");
			pSubsystemCopy->GetPropStringValue(strMethod, P_ID_EXT_CONNECT_FORM);
			
			if(!strMethod.IsEmpty())
			{
				CExtTabModel *pClonePage = (CExtTabModel *)FindInModels(strMethod, pModelList);
				
				if(pClonePage != NULL)
				{
					pClonePage->SetDataManager(pMgr);
					CString strTi = pMgr->GetUniquePageCaption();
					
					pMgr->m_ModelCache.AddTail(pClonePage);
					pClonePage->m_strCaption = strTi;
					pSubsystemCopy->SetObjectCaption(strTi);
					pSubsystemCopy->PutPropStringValue(P_ID_EXT_CONNECT_FORM, strTi);
				}
				
			}
		}
	}
	
	CExtAddCompsAction *pAction = new CExtAddCompsAction(GetCurrentModel(),*pShapeList);
	
	if(!GetCurrentModel()->Do(pAction,TRUE))
	{
		delete pAction;
	}
}

void CETAPDemoView::OnEditCopy() 
{
	// TODO: Add your command handler code here
	OnFOPEditCopy();	
}

void CETAPDemoView::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	OnFOPUpdateEditCopy(pCmdUI);
}

void CETAPDemoView::OnEditCut() 
{
	// TODO: Add your command handler code here
	
	OnFOPEditCut();
}

void CETAPDemoView::OnUpdateEditCut(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	OnFOPUpdateEditCut(pCmdUI);
}

void CETAPDemoView::OnEditPaste() 
{
	// TODO: Add your command handler code here
	
	OnFOPEditPaste();
	GetDocument()->SetModifiedFlag(TRUE);
}

void CETAPDemoView::OnUpdateEditPaste(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	
	COleDataObject dataObject;
	BOOL bEnable = dataObject.AttachClipboard();
	
	BOOL bEnablePaste = FALSE;
	
#ifdef _UNICODE
	bEnablePaste = dataObject.IsDataAvailable(CF_UNICODETEXT);
#else
	bEnablePaste = dataObject.IsDataAvailable(CF_TEXT);
	
	if (!bEnablePaste)
	{
		bEnablePaste = dataObject.IsDataAvailable(CF_OEMTEXT);
	}
	
#endif
	
	bEnable = bEnable &&
		(dataObject.IsDataAvailable(GetXDClipboardFormat()) ||
		dataObject.IsDataAvailable(GetXDClipboardTable()) ||
		dataObject.IsDataAvailable(GetXDClipboardStation()) ||
		bEnablePaste ||
		dataObject.IsDataAvailable(CF_BITMAP) ||
		dataObject.IsDataAvailable(CF_ENHMETAFILE));
	
	if(!bDesign)
	{
		bEnable = FALSE;
	}
	
	if(!bEnable)
	{
		if (m_pCurInsideBoxShape != NULL)
		{
			if(m_pCurInsideBoxShape->GetCurControl() != NULL)
				bEnable = m_pCurInsideBoxShape->GetCurControl()->IsCanPaste();
		}
	}
	
	if(!bEnable)
	{
		if (m_pCurrentEditShape != NULL)
		{
			if(m_pCurrentEditShape->GetCurrentControl() != NULL)
				bEnable = m_pCurrentEditShape->GetCurrentControl()->IsCanPaste();
		}
	}
	
	pCmdUI->Enable(bEnable);
}

LRESULT CETAPDemoView::OnMouseLeave(WPARAM,LPARAM)
{
	
	OnDrawTrackOnlyDrop(m_ptMouseDown);
	return 0;
}

void CETAPDemoView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	if(m_drawshape == IDR_SELECT_SHAPE)
	{
		if(GetCurrentModel()->IsDesignMode() && m_action_state == State_OnlyDropStart)
		{
			CPoint local = point;
			if(m_pCurDataModel != NULL)
				m_pCurDataModel->SetActiveObserver(this);
			
			if(m_pluginList.GetCount() > 0)
			{
				BOOL bOK = FALSE;
				
				CPoint ptHit = local;
				FODPtoLP(&ptHit,1);
				POSITION posevent = m_pluginList.GetHeadPosition();
				while (posevent)
				{
					FOPMsgHandleTool* pEvent = (FOPMsgHandleTool*) m_pluginList.GetNext(posevent);
					if(pEvent->OnLButtonUp(nFlags,ptHit))
					{
						bOK = TRUE;
						if(pEvent->IsResetAfterLButtonUp())
						{
							DetachPlugin(pEvent->GetId());
							ResetToSelectMode();
						}
					}
				}
				
				if(bOK)
				{
					return;
				}
			}
			
			Highlit(NULL);	
			HighlitPort(NULL);
			{
				CPoint ptHit = local;
				FODPtoLP(&ptHit,1);
				HighlitLink(NULL, ptHit);
			}
			
			m_pCurMovingObj			= NULL;
			m_pLastLinkPort			= NULL;
			m_pCurMovingObj			= NULL;
			BOOL bTimerKilled = StopAutoTimer();
			if(bTimerKilled)
			{
				//		DoUpdateRuler();
				//		FOPInvalidate(FALSE, TRUE);
			}
			
			CRect rcDrawTrack = m_rcLastTrackingRect;
			//	DocToClient(rcDrawTrack);
			
			if (m_bEnableRulerTrack)
			{
				if (m_bRedrawTrackRect)
				{
					CFOWndDC dc(this, FALSE);
					DrawRulerShapeRect(&dc, rcDrawTrack);
					m_bRedrawTrackRect = FALSE;
				}
			}
			
			EndTextBoxWithoutUpdate(local);
			
			CPoint ptDev = point;
			CPoint ptLog(ptDev);
			FODPtoLP(&ptLog,1);
			
			BOOL bEnableGridSnap = TRUE;
			if(m_bEnableNearest)
			{
				CPoint ptNear;
				if(GetCurrentModel()->PickNearestPoint(m_listSelectComp,ptNear,ptLog,TRUE))
				{
					ptLog = ptNear;
					ptDev = ptLog;
					FOLPtoDP(&ptDev,1);
					bEnableGridSnap = FALSE;
				}
			}
			
			if(bEnableGridSnap)
			{
				if (GetCurrentModel()->IsGrid() && (nFlags & MK_CONTROL))
				{
					ptLog = FindCloseGridPoint(ptLog);
					ptDev = ptLog;
					FOLPtoDP(&ptDev,1);
				}
			}
			
			FODPtoLP(&ptDev, 1);
			
			StopMouseCapture();
			LimitDrawShapeTrackPoint(&ptDev, &ptDev, 1);
			CRect rcCreate(ptDev, ptDev);
			rcCreate.NormalizeRect();
			
			CFOWndDC dc(this,FALSE);
			PrepareTrackLineDC(&dc);
			
			OnDrawTrackOnlyDrop(m_ptMouseDown);
			
			CFODrawShape *pCurAdd = GetCurrentModel()->AddShapeByType(m_drawshape,rcCreate);
			DoAfterAddShape(pCurAdd);
			if(gfxData.IsContinueEnableDrawing())
			{
				
				OnDrawShape();
				
			}
			else
			{
				m_bAtFirstTime = FALSE;
				m_bUpRightMode = FALSE;
				m_drawshape = FO_COMP_NONE;
				ResetToSelectMode();
				FOSetSystemCursor(IDC_ARROW);
				
			}
			
			if(m_action_state == State_SelectNone)
			{
				m_drawshape = FO_COMP_NONE;
				m_bUpRightMode = FALSE;
			}
			
			if(fo_GlueStart)
			{
				OnDrawTrackGluespot(m_ptSaveGlue);
				fo_GlueStart = FALSE;
				
				fo_saveHorz	= FALSE;
				fo_saveVert	= FALSE;
				fo_saveGetH	= CPoint(0,0);
				fo_saveGetV	= CPoint(0,0);
			}
			
			CheckSelectionChange();
			
			if (m_bEnableRulerTrack)
			{
				if (m_bRedrawTrackRect)
				{
					CFOWndDC dc(this, FALSE);
					DrawRulerShapeRect(&dc, rcDrawTrack);
					m_bRedrawTrackRect = FALSE;
				}
			}
			
			return;
		}
	}
	
	CFOTabPageView::OnLButtonUp(nFlags, point);

	if(m_drawshape == 0)
	{
		if(m_action_state == State_DoOnlyDrop ||
			m_action_state == State_OnlyDrop ||
			m_action_state == State_OnlyDropStart)
		{
			OnDrawTrackOnlyDrop(m_ptMouseDown);
			
			m_drawshape = FO_COMP_NONE;
			m_bUpRightMode = FALSE;
			ResetToSelectMode();
			FOSetSystemCursor(IDC_ARROW);
			
			return;
		}
	}
	
}

void CETAPDemoView::OnDraw1030() 
{
	// TODO: Add your command handler code here
//	ResetToSelectMode();
	
	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;
	
	m_drawshape = IDR_D_130;
	SetCurrentDrawingCursor(IDC_CURSOR_1021);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;
	
	m_pTrackDraw = CreateTrackShape(m_drawshape);
}

void CETAPDemoView::OnUpdateDraw1030(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_130 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDraw1031() 
{
	// TODO: Add your command handler code here
//	ResetToSelectMode();
	
	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;
	
	m_drawshape = IDR_D_1031;
	SetCurrentDrawingCursor(IDC_CURSOR_1022);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;
	
	m_pTrackDraw = CreateTrackShape(m_drawshape);
}

void CETAPDemoView::OnUpdateDraw1031(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1031 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDraw1032() 
{
	// TODO: Add your command handler code here
//	ResetToSelectMode();
	
	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;
	
	m_drawshape = IDR_D_1032;
	SetCurrentDrawingCursor(IDC_CURSOR_1023);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;
	
	m_pTrackDraw = CreateTrackShape(m_drawshape);
}

void CETAPDemoView::OnUpdateDraw1032(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1032 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDraw1033() 
{
	// TODO: Add your command handler code here
//	ResetToSelectMode();
	
	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;
	
	m_drawshape = IDR_D_1033;
	SetCurrentDrawingCursor(IDC_CURSOR_1024);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;
	
	m_pTrackDraw = CreateTrackShape(m_drawshape);
}

void CETAPDemoView::OnUpdateDraw1033(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1033 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnDraw1034() 
{
	// TODO: Add your command handler code here
//	ResetToSelectMode();
	
	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	pModel->m_nCurRotateAngle = 0;
	
	m_drawshape = IDR_D_1034;
	SetCurrentDrawingCursor(IDC_CURSOR_1025);
	m_action_state = State_OnlyDrop;
	m_bUpRightMode = FALSE;
	
	m_pTrackDraw = CreateTrackShape(m_drawshape);
}

void CETAPDemoView::OnUpdateDraw1034(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_D_1034 && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnInsertShape() 
{
	// TODO: Add your command handler code here
	
}

void CETAPDemoView::OnUpdateInsertShape(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CETAPDemoView::OnDrawShape() 
{
	// TODO: Add your command handler code here
	CExtTabModel *pModel = static_cast<CExtTabModel *>(GetCurrentModel());
	CHMITrsOpenPageDlg dlg;
	dlg.strCurSelectFile = strCurSelectFile;
	dlg.strCurSelectShape = strCurSelectShape;
	if(dlg.DoModal() == IDOK)
	{
		if(dlg.bNotChange)
		{
			m_drawshape = IDR_SELECT_SHAPE;
			SetCurrentDrawingCursor(IDC_FO_DROP_CURSOR);
			m_action_state = State_OnlyDrop;
			m_bUpRightMode = FALSE;
			return;
		}
		// ResetToSelectMode();
		strCurSelectFile = dlg.strCurSelectFile;
		strCurSelectShape = dlg.strCurSelectShape;
		pModel->m_nCurRotateAngle = 0;
		if(pModel->m_pCurSelect != NULL)
		{
			delete pModel->m_pCurSelect;
			pModel->m_pCurSelect = NULL;
		}
		FOPRect rc = FOPRect(0,0, 100,100);
		CPoint ptTrackX = rc.CenterPoint();
		pModel->m_pCurSelect = (CFOCompositeShape *)dlg.pCurSelect->GetShape()->Copy(); // Second.

		CFOCompositeShape* pReturn = (CFOCompositeShape *)dlg.pCurSelect->GetShape()->Copy(); // First
		
		pReturn->AddRef();
		pReturn->SetType(IDR_SELECT_SHAPE);
		rc.NormalizeRect();
		
		FOPRect rcShape = pReturn->GetSnapRect();
		
		CSize sz = CSize(rcShape.Width(), rcShape.Height());
		rc.CreateFromCenter(ptTrackX, sz);
		
		
		if(rcShape.Width()<=10 && rcShape.Height()<20)
		{
			rc = CRect(ptTrackX.x-70,ptTrackX.y-70,ptTrackX.x+70,ptTrackX.y+70);
		}
		
		pReturn->PositionShape(rc);

		m_drawshape = IDR_SELECT_SHAPE;
		SetCurrentDrawingCursor(IDC_FO_DROP_CURSOR);
		m_action_state = State_OnlyDrop;
		m_bUpRightMode = FALSE;

		if(m_pTrackDraw != NULL)
		{
			m_pTrackDraw->Release();
			m_pTrackDraw = NULL;
			
		}
		m_pTrackDraw = pReturn;
	//	SetFocus();
	}
	else
	{
		m_bAtFirstTime = FALSE;
		m_bUpRightMode = FALSE;
		m_drawshape = FO_COMP_NONE;
		ResetToSelectMode();
		FOSetSystemCursor(IDC_ARROW);
	}
}

void CETAPDemoView::OnUpdateDrawShape(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bDesign = GetCurrentModel()->IsDesignMode();
	if(!bDesign)
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if(bDesign)
	{
		pCmdUI->SetCheck(m_drawshape == IDR_SELECT_SHAPE && (m_action_state == State_OnlyDrop || m_action_state == State_DoOnlyDrop));
	}
}

void CETAPDemoView::OnRelinkPage() 
{
	// TODO: Add your command handler code here
	if(m_listSelectComp.GetCount() == 1)
	{
		CFODrawShapeList m_ListTemp;
		CFODrawShape *pShape = GetCurrentSelectShape();
		
		if(pShape != NULL)
		{
			if(HAS_BASE(pShape, CBPMActTaskShape))
			{
				CExtTabModel *pModel = (CExtTabModel *)(GetCurrentModel());
				
				CBPMActTaskShape *pTask = static_cast<CBPMActTaskShape *>(pShape);
				
				CString strMethod = _T("");
				pTask->GetPropStringValue(strMethod, P_ID_EXT_CONNECT_FORM);
				
				CMATRelinkDlg dlg;
				dlg.m_strCaption = pTask->GetObjectCaption();
				dlg.m_pModel = (CFOTabPageModel *)pModel;
				
				dlg.m_strCurLink = strMethod;
				if(dlg.DoModal() == IDOK)
				{
					pTask->PutPropStringValue(P_ID_CAPTION, dlg.m_strCaption);
					pTask->PutPropStringValue(P_ID_EXT_CONNECT_FORM, dlg.m_strCurLink);
					
					pTask->UpdateControl();
				}
			}
			
			
		}
	}
}

void CETAPDemoView::OnUpdateRelinkPage(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_listSelectComp.GetCount() == 1);
}
