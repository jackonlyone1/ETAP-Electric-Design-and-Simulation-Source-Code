// ETAPDemoDoc.cpp : implementation of the CETAPDemoDoc class
//

#include "stdafx.h"
#include "ETAPDemo.h"

#include "ETAPDemoDoc.h"
#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CETAPDemoDoc

IMPLEMENT_DYNCREATE(CETAPDemoDoc, COleDocument)

BEGIN_MESSAGE_MAP(CETAPDemoDoc, COleDocument)
	//{{AFX_MSG_MAP(CETAPDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
#ifdef OLE_CLIENT_SUPPORT	
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, COleDocument::OnUpdatePasteMenu)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, COleDocument::OnUpdatePasteLinkMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, COleDocument::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_OLE_EDIT_CONVERT, COleDocument::OnEditConvert)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, COleDocument::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, COleDocument::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, COleDocument::OnUpdateObjectVerbMenu)
#endif
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CETAPDemoDoc construction/destruction

CETAPDemoDoc::CETAPDemoDoc()
{
	// TODO: add one-time construction code here
	//E-XD++ Library add lines.
	m_pModelManager = new CExtTabModelManager;
	bNewDocument = TRUE;
	bOpenDocument = FALSE;
	// Use OLE compound files
//	EnableCompoundFile();
	
	EnableConnections();
	
	EnableAutomation();
	
	AfxOleLockApp();
}

CETAPDemoDoc::~CETAPDemoDoc()
{
	AfxOleUnlockApp();
	//E-XD++ Library add lines.
	if(m_pModelManager != NULL)
	{
		delete m_pModelManager;
		m_pModelManager = NULL;
	}
}

BOOL CETAPDemoDoc::OnNewDocument()
{
	if (!COleDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}


CString CETAPDemoDoc::GetViewTitle()
{
	CString str = GetPathName();
	if(str.IsEmpty())
	{
		return _T("");
	}
	
	return theApp.XGetBaseFileName(str);
}

CView *CETAPDemoDoc::GetCurView()
{
	POSITION pos = GetFirstViewPosition();
	if (pos != NULL)
		return (CView*)GetNextView(pos); // get first one
	
	return NULL;
}


/////////////////////////////////////////////////////////////////////////////
// CETAPDemoDoc serialization

void CETAPDemoDoc::Serialize(CArchive& ar)
{
	//E-XD++ Library add lines.
	m_pModelManager->Serialize(ar);
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}



//E-XD++ Library add lines.
void CETAPDemoDoc::SetModifiedFlag(BOOL b)
{
	// Do nothing
	m_pModelManager->SetModifiedFlag(b);
}

//added override
BOOL CETAPDemoDoc::IsModified()
{
	return m_pModelManager->IsModified();
}

void CETAPDemoDoc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	COleDocument::DeleteContents();
	m_pModelManager->ResetContent();
}


BOOL CETAPDemoDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	bOpenDocument = TRUE;
	if (!COleDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	return TRUE;
}

BOOL CETAPDemoDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized code here and/or call the base class
	return COleDocument::OnSaveDocument(lpszPathName);
}
/////////////////////////////////////////////////////////////////////////////
// CETAPDemoDoc diagnostics

#ifdef _DEBUG
void CETAPDemoDoc::AssertValid() const
{
	COleDocument::AssertValid();
}

void CETAPDemoDoc::Dump(CDumpContext& dc) const
{
	COleDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CETAPDemoDoc commands
 
/////////////////////////////////////////////////////////
IMPLEMENT_ACTION(CExtAddCompsAction, CFOAction, EXT_ACTION_ADDSHAPES)
/////////////////////////////////////////////////////////////////////////////
// CExtAddCompsAction

CExtAddCompsAction::CExtAddCompsAction(CFODataModel* pModel, const CFODrawShapeList& listx)
: CFOAction(pModel), m_listShapes(listx.GetCount())
{
	m_listShapes.AddTail((CFODrawShapeList*)&listx);
}

CExtAddCompsAction::~CExtAddCompsAction()
{
	m_listShapes.RemoveAll();
}

CRect CExtAddCompsAction::GetMaxPosition()
{
	CRect rcReturn;
	rcReturn.SetRectEmpty();
	BOOL bAtFirst = TRUE;
	CFODrawShape *pShape = NULL;
	POSITION pos = m_listShapes.GetHeadPosition();
	while(pos != NULL)
	{
		pShape = m_listShapes.GetNext(pos);
		if(pShape != NULL)
		{
			CRect rcTemp = pShape->GetBoundRect();
			int nBorder = pShape->CalcExtraBorder();
			rcTemp.InflateRect(nBorder,nBorder,nBorder,nBorder);
			if(bAtFirst)
			{
				rcReturn = rcTemp;
				bAtFirst = FALSE;
			}

			if(rcTemp.left<rcReturn.left)
			{
				rcReturn.left = rcTemp.left;
			}
			if(rcTemp.right > rcReturn.right)
			{
				rcReturn.right = rcTemp.right;
			}
			if(rcTemp.top < rcReturn.top)
			{
				rcReturn.top = rcTemp.top;
			}
			if(rcTemp.bottom > rcReturn.bottom)
			{
				rcReturn.bottom = rcTemp.bottom;
			}
		}
	}
	return rcReturn;
}

BOOL CExtAddCompsAction::Execute()
{
	SetSaveUpdateRect(GetMaxPosition());

	CExtTabModelManager *pManager = (CExtTabModelManager *)((CExtTabModel *)m_pModel)->GetManager();
	if(0)
	{
		CFODrawShape *pShape = NULL;
		
		POSITION posShape = m_listShapes.GetHeadPosition();
		
		while(posShape != NULL)
		{
			pShape = (CFODrawShape *)m_listShapes.GetNext(posShape);
			if(HAS_BASE(pShape, CBPMActTaskShape))
			{
				CBPMActTaskShape *pSubsystemCopy = static_cast<CBPMActTaskShape *>(pShape);
				
				CString strMethod = _T("");
				pSubsystemCopy->GetPropStringValue(strMethod, P_ID_EXT_CONNECT_FORM);
				if(!strMethod.IsEmpty() && pManager != NULL)
				{
					CExtTabModel *pNewModel = pManager->FindInCache(strMethod);
					if(pNewModel != NULL)
					{
// 						pManager->InsertTab(pNewModel);
// 						CFOPMDIChildWnd* pChildFrame = (CFOPMDIChildWnd *)((CMDIFrameWnd*)::AfxGetMainWnd())->MDIGetActive();
// 						if (pChildFrame)
// 						{
// 							CChildFrame *child = static_cast<CChildFrame *>(pChildFrame);
// 							child->AddNew(pNewModel);
// 						}
// 						pManager->RemoveCache(strMethod);
					}
				}
				
			}
			
		}
	}

	if (m_shapeIndices.GetCount() > 0)
	{
		int nIndex;
		POSITION pos = m_listShapes.GetHeadPosition();
		while(pos != NULL)
		{
			CFODrawShape *pComp = (CFODrawShape *)m_listShapes.GetNext(pos);
			{
				if (GetIndex(pComp, nIndex) && nIndex < GetModel()->GetShapes()->GetCount())
					m_pModel->InsertShapeAt(pComp, nIndex);
				else
					m_pModel->AddShape(pComp);
			}
		}
	}
	else
	{
		m_pModel->AddShapes(m_listShapes);
	}
	
	return TRUE;
}

CFOBaseAction* CExtAddCompsAction::GetUndoAction() const
{
	return new CExtRemoveCompsAction(m_pModel, m_listShapes);
}

CFOBaseAction* CExtAddCompsAction::GetRedoAction() const
{
	int nIndex;
	CExtAddCompsAction *pAction = new CExtAddCompsAction(m_pModel, m_listShapes);
	POSITION pos = m_listShapes.GetHeadPosition();
	while(pos != NULL)
	{
		CFODrawShape *pComp = (CFODrawShape *)m_listShapes.GetNext(pos);
		if (GetIndex(pComp, nIndex))
			pAction->SetIndex(pComp, nIndex);
	}
	return pAction;
}

// Clear all index
void CExtAddCompsAction::ClearAllIndex()
{
	m_shapeIndices.RemoveAll();
}

// Obtain index of a shape
BOOL CExtAddCompsAction::GetIndex(CFODrawShape* pComp, int& nIndex) const
{
	return m_shapeIndices.Lookup(pComp, nIndex);
}

// Change the index of a shape.
void CExtAddCompsAction::SetIndex(CFODrawShape* pComp, int nIndex)
{
	m_shapeIndices.SetAt(pComp, nIndex);
}

void CExtAddCompsAction::AddShape(CFODrawShape* pShape)
{
	ASSERT_VALID(pShape);
	if (pShape && (m_listShapes.Find(pShape) == NULL))
	{
		m_listShapes.AddTail(pShape);
	}
}

void CExtAddCompsAction::AddShapes(CFODrawShapeList &listx)
{
	m_listShapes.AddTail(&listx);
}

void CExtAddCompsAction::AddShapes(CFODrawShapeSet &listx)
{
	CFODrawShape *pShape = NULL;
	int xy = 0;
	for( xy = 0; xy < listx.GetCount(); xy ++)
	{
		pShape = (CFODrawShape *)listx.GetObject(xy);
		m_listShapes.AddTail(pShape);
	}
}

void CExtAddCompsAction::RemoveShape(CFODrawShape* pShape)
{
	POSITION pos = m_listShapes.Find(pShape);
	if (pos == NULL)
	{
		return;
	}
	m_listShapes.RemoveAt(pos);
}

void CExtAddCompsAction::RemoveAllShapes()
{
	m_listShapes.RemoveAll();
}

void CExtAddCompsAction::Sprint(CString& strLabel) const
{ 
	strLabel.LoadString(IDS_CMD_ADD_COMPS); 
}

/////////////////////////////////////////////////////////
IMPLEMENT_ACTION(CExtRemoveCompsAction, CFOAction, EXT_ACTION_REMOVESHAPES)

CExtRemoveCompsAction::CExtRemoveCompsAction(CFODataModel* pModel, const CFODrawShapeList& listx)
: CFOAction(pModel), m_listShapes(listx.GetCount())
{
	m_listShapes.AddTail((CFODrawShapeList*)&listx);
}

CExtRemoveCompsAction::~CExtRemoveCompsAction()
{
	m_listShapes.RemoveAll();
}

CRect CExtRemoveCompsAction::GetMaxPosition()
{
	CFODrawShapeList m_list;
	m_list.AddTail(&m_listShapes);
	
	GetModel()->GetAllLinkedShape(m_list, m_list);
	CRect rcReturn;
	rcReturn.SetRectEmpty();
	BOOL bAtFirst = TRUE;
	CFODrawShape *pShape = NULL;
	POSITION pos = m_list.GetHeadPosition();
	while(pos != NULL)
	{
		pShape = m_list.GetNext(pos);
		if(pShape != NULL)
		{
			CRect rcTemp = pShape->GetBoundRect();
			int nBorder = pShape->CalcExtraBorder();
			rcTemp.InflateRect(nBorder,nBorder,nBorder,nBorder);
			if(bAtFirst)
			{
				rcReturn = rcTemp;
				bAtFirst = FALSE;
			}
			
			if(rcTemp.left<rcReturn.left)
			{
				rcReturn.left = rcTemp.left;
			}
			if(rcTemp.right > rcReturn.right)
			{
				rcReturn.right = rcTemp.right;
			}
			if(rcTemp.top < rcReturn.top)
			{
				rcReturn.top = rcTemp.top;
			}
			if(rcTemp.bottom > rcReturn.bottom)
			{
				rcReturn.bottom = rcTemp.bottom;
			}
		}
	}
	return rcReturn;
}

BOOL CExtRemoveCompsAction::Execute()
{
	SetSaveUpdateRect(GetMaxPosition());
	ClearAllIndex();
	UpdateIndices(&m_listShapes);
	CExtTabModelManager *pManager = (CExtTabModelManager *)((CExtTabModel *)m_pModel)->GetManager();
	if(0)
	{
		CFODrawShape *pShape = NULL;
		
		POSITION posShape = m_listShapes.GetHeadPosition();

		while(posShape != NULL)
		{
			pShape = (CFODrawShape *)m_listShapes.GetNext(posShape);
			if(HAS_BASE(pShape, CBPMActTaskShape))
			{
				CBPMActTaskShape *pSubsystemCopy = static_cast<CBPMActTaskShape *>(pShape);

				CString strMethod = _T("");
				pSubsystemCopy->GetPropStringValue(strMethod, P_ID_EXT_CONNECT_FORM);
				if(!strMethod.IsEmpty() && pManager != NULL)
				{
// 					CFOPMDIChildWnd* pChildFrame = (CFOPMDIChildWnd *)((CMDIFrameWnd*)::AfxGetMainWnd())->MDIGetActive();
// 					if (pChildFrame)
// 					{
// 						CChildFrame *child = static_cast<CChildFrame *>(pChildFrame);
// 						child->DeleteTab(strMethod);
// 					}
// 					pManager->DeleteTabNew(strMethod);
				}

			}
			
		}
	}

	return m_pModel->RemoveShapes(m_listShapes);
}

CFOBaseAction* CExtRemoveCompsAction::GetUndoAction() const
{
	int nIndex;
	CExtAddCompsAction *pAction = new CExtAddCompsAction(m_pModel, m_listShapes);
	POSITION pos = m_listShapes.GetHeadPosition();
	while(pos != NULL)
	{
		CFODrawShape *pComp = (CFODrawShape *)m_listShapes.GetNext(pos);
		if (GetIndex(pComp, nIndex))
			pAction->SetIndex(pComp, nIndex);
	}
	return pAction;
}

CFOBaseAction* CExtRemoveCompsAction::GetRedoAction() const
{
	int nIndex;
	CExtRemoveCompsAction *pAction = new CExtRemoveCompsAction(m_pModel, m_listShapes);
	POSITION pos = m_listShapes.GetHeadPosition();
	while(pos != NULL)
	{
		CFODrawShape *pComp = (CFODrawShape *)m_listShapes.GetNext(pos);
		if (GetIndex(pComp, nIndex))
			pAction->SetIndex(pComp, nIndex);
	}

	return pAction;
}

void CExtRemoveCompsAction::AddShape(CFODrawShape* pShape)
{
	ASSERT_VALID(pShape);
	if (pShape && (m_listShapes.Find(pShape) == NULL))
	{
		m_listShapes.AddTail(pShape);
	}
}

void CExtRemoveCompsAction::AddShapes(CFODrawShapeList &listx)
{
	m_listShapes.AddTail(&listx);
}

void CExtRemoveCompsAction::AddShapes(CFODrawShapeSet &listx)
{
	CFODrawShape *pShape = NULL;
	int xy = 0;
	for( xy = 0; xy < listx.GetCount(); xy ++)
	{
		pShape = (CFODrawShape *)listx.GetObject(xy);
		m_listShapes.AddTail(pShape);
	}
}

void CExtRemoveCompsAction::RemoveShape(CFODrawShape* pShape)
{
	POSITION pos = m_listShapes.Find(pShape);
	if (pos == NULL)
	{
		return;
	}
	m_listShapes.RemoveAt(pos);
}

void CExtRemoveCompsAction::RemoveAllShapes()
{
	m_listShapes.RemoveAll();
}

void CExtRemoveCompsAction::Sprint(CString& strLabel) const
{ 
	strLabel.LoadString(IDS_CMD_REMOVE_SHAPES); 
}

// Clear all index
void CExtRemoveCompsAction::ClearAllIndex()
{
	m_shapeIndices.RemoveAll();
}

// Obtain index of a shape
BOOL CExtRemoveCompsAction::GetIndex(CFODrawShape* pComp, int& nIndex) const
{
	return m_shapeIndices.Lookup(pComp, nIndex);
}

// Change the index of a shape.
void CExtRemoveCompsAction::SetIndex(CFODrawShape* pComp, int nIndex)
{
	m_shapeIndices.SetAt(pComp, nIndex);
}

// Update all shape's index.
void CExtRemoveCompsAction::UpdateIndices(CFODrawShapeList* pCompList)
{
	
	CFODrawShape* pComp = NULL;
	POSITION pos = pCompList->GetHeadPosition();
	while(pos != NULL)
	{
		pComp = pCompList->GetNext(pos);
		int nIndex = GetIndexWithin(pComp, GetModel()->GetShapes());
		if( nIndex != -1 )
		{
			m_shapeIndices.SetAt(pComp, nIndex);
		}
	}
}

int CExtRemoveCompsAction::GetIndexWithin(CFODrawShape *pShape, CFODrawShapeSet* pCompList)
{
	for(int x = 0; x < pCompList->GetCount(); x++)
	{
		CFODrawShape *pComp = (CFODrawShape *)pCompList->GetObject(x);
		if(pComp == pShape)
		{
			return x;
		}
	}

	return -1;
}
