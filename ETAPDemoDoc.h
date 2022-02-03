// ETAPDemoDoc.h : interface of the CETAPDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ETAPDEMODOC_H__E4FA9075_6C02_454F_8985_16770216113B__INCLUDED_)
#define AFX_ETAPDEMODOC_H__E4FA9075_6C02_454F_8985_16770216113B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//E-XD++ Library add lines.
#include "ExtTabModelManager.h"	

 
//===========================================================================
// Summary:
//     The CETAPDemoDoc class derived from COleDocument
//      E T A P Demo Document
//===========================================================================

class CETAPDemoDoc : public COleDocument
{
protected: // create from serialization only
	
	//-----------------------------------------------------------------------
	// Summary:
	// E T A P Demo Document, Constructs a CETAPDemoDoc object.
	//		Returns A  value.
	CETAPDemoDoc();
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ D Y N C R E A T E, None Description.
	//		Returns A  value.  
	// Parameters:
	//		CETAPDemoDoc---E T A P Demo Document, Specifies a CETAPDemoDoc object.
	DECLARE_DYNCREATE(CETAPDemoDoc)

// Attributes
public:

	//E-XD++ Library add lines.
 
	// Model Manager, This member maintains a pointer to the object CExtTabModelManager.  
	CExtTabModelManager *m_pModelManager;
 
	// New Document, This member sets TRUE if it is right.  
	BOOL bNewDocument;
 
	// Open Document, This member sets TRUE if it is right.  
	BOOL bOpenDocument;
// Operations
public:
	// Obtain view.
	CView *GetCurView();
	
	// Obtain title.
	CString GetViewTitle();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CETAPDemoDoc)
	public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// On New Document, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.
	virtual BOOL OnNewDocument();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Serialize, Reads or writes this object from or to an archive.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		ar---Specifies a CArchive& ar object.
	virtual void Serialize(CArchive& ar);
	//E-XD++ Library add lines.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Delete Contents, Deletes the given object.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void DeleteContents();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Modified Flag, Sets a specify value to current class CETAPDemoDoc
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		bModified---bModified, Specifies A Boolean value.
	virtual void SetModifiedFlag(BOOL bModified = TRUE);
	
	//-----------------------------------------------------------------------
	// Summary:
	// Is Modified, Determines if the given value is correct or exist.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.
	virtual BOOL IsModified();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Save Document, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		lpszPathName---Path Name, Specifies A 32-bit pointer to a constant character string that is portable for Unicode and DBCS.
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Open Document, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		lpszPathName---Path Name, Specifies A 32-bit pointer to a constant character string that is portable for Unicode and DBCS.
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// C E T A P Demo Document, Destructor of class CETAPDemoDoc
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CETAPDemoDoc();
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

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CETAPDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//===========================================================================
// Summary:
//     The CExtAddCompsAction class derived from CFOAction
//      F O Add Components Action
//===========================================================================

class  CExtAddCompsAction : public CFOAction
{
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ A C T I O N, .
	//		Returns A  value (Object).  
	// Parameters:
	//		CExtAddCompsAction---F O Add Components Action, Specifies a E-XD++ CExtAddCompsAction object (Value).
	DECLARE_ACTION(CExtAddCompsAction)

public:
	// Constructor. 
	
	//-----------------------------------------------------------------------
	// Summary:
	// F O Add Components Action, Constructs a CExtAddCompsAction object.
	//		Returns A  value (Object).  
	// Parameters:
	//		pModel---pModel, A pointer to the CFODataModel or NULL if the call failed.  
	//		list---Specifies a const CFODrawShapeList& list object(Value).
	CExtAddCompsAction(CFODataModel* pModel, const CFODrawShapeList& list);

	// Destructor. 
	
	//-----------------------------------------------------------------------
	// Summary:
	// C F O Add Components Action, Destructor of class CExtAddCompsAction
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value (Object).
	virtual ~CExtAddCompsAction();

// Overrides
public:

	
	//-----------------------------------------------------------------------
	// Summary:
	// Execute, Executes the action.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns BOOLvalue, TRUE on success; FALSE otherwise.
	// Executes the action. 
	virtual BOOL Execute();

	// Return the inverse action of this one
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Undo Action, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CFOBaseAction,or NULL if the call failed
	virtual CFOBaseAction* GetUndoAction() const;

	// Return a copy of this action
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Redo Action, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CFOBaseAction,or NULL if the call failed
	virtual CFOBaseAction* GetRedoAction() const;

	// Get the name of the action
	
	//-----------------------------------------------------------------------
	// Summary:
	// Sprint, .
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		strLabel---strLabel, Specifies A CString type value.
	virtual void Sprint(CString& strLabel) const;

	// Returns a pointer to the list of actions.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Shape List, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CFODrawShapeList,or NULL if the call failed
	virtual CFODrawShapeList* GetShapeList();

	// Add a new component to the list.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Add Shape, Adds an object to the specify list.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pShape---pShape, A pointer to the CFODrawShape or NULL if the call failed.
	virtual void AddShape(CFODrawShape* pShape);

	// Add a new component to the list.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Add Shapes, Adds an object to the specify list.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		&list---Specifies a E-XD++ CFODrawShapeList &list object (Value).
	virtual void AddShapes(CFODrawShapeList &list);

	// Add a new component to the list.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Add Shapes, Adds an object to the specify list.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		&list---Specifies a E-XD++ CFODrawShapeSet &list object (Value).
	virtual void AddShapes(CFODrawShapeSet &list);

	// Remove a component from the list.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Remove Shape, Call this function to remove a specify value from the specify object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pShape---pShape, A pointer to the CFODrawShape or NULL if the call failed.
	virtual void RemoveShape(CFODrawShape* pShape);

	// Remove all shapes from the list.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Remove All Shapes, Call this function to remove a specify value from the specify object.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void RemoveAllShapes();

	// Get max position of list.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Maximize Position, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CRect type value.
	virtual CRect GetMaxPosition();

	// Clear all index
	
	//-----------------------------------------------------------------------
	// Summary:
	// Clear All Index, Remove the specify data from the list.

	void ClearAllIndex();
	
	// Obtain index of a shape
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Index, Returns the specified value.
	//		Returns BOOLvalue, TRUE on success; FALSE otherwise.  
	// Parameters:
	//		pComp---pComp, A pointer to the CFODrawShape or NULL if the call failed.  
	//		nIndex---nIndex, Specifies A integer value.
	BOOL GetIndex(CFODrawShape* pComp, int& nIndex) const;
	
	// Change the index of a shape.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Index, Sets a specify value to current class CExtAddCompsAction
	// Parameters:
	//		pComp---pComp, A pointer to the CFODrawShape or NULL if the call failed.  
	//		nIndex---nIndex, Specifies A integer value.
	void SetIndex(CFODrawShape* pComp, int nIndex);

// Attributes
protected:

	// Shapes list
 
	// Shapes, This member specify E-XD++ CFODrawShapeList object.  
	CFODrawShapeList m_listShapes;

	// Shape index.
	CMap<CFODrawShape*,CFODrawShape*,int,int> m_shapeIndices;

    //Declare friend class CFOPCanvasCore
 
	// F O P Canvas Core, This member specify friend class object.  
	friend class CFOPCanvasCore;
};

// Returns a pointer to the list of actions.
_FOLIB_INLINE CFODrawShapeList* CExtAddCompsAction::GetShapeList()
{
	return &m_listShapes;
}

///////////////////////////////////////////////////////////////////////////////////
// CExtRemoveCompsAction -- action that remove components from canvas.

 
//===========================================================================
// Summary:
//     The CExtRemoveCompsAction class derived from CFOAction
//      F O Remove Components Action
//===========================================================================

class  CExtRemoveCompsAction : public CFOAction
{
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ A C T I O N, .
	//		Returns A  value (Object).  
	// Parameters:
	//		CExtRemoveCompsAction---F O Remove Components Action, Specifies a E-XD++ CExtRemoveCompsAction object (Value).
	DECLARE_ACTION(CExtRemoveCompsAction)

public:

	// Constructor.
	
	//-----------------------------------------------------------------------
	// Summary:
	// F O Remove Components Action, Constructs a CExtRemoveCompsAction object.
	//		Returns A  value (Object).  
	// Parameters:
	//		pModel---pModel, A pointer to the CFODataModel or NULL if the call failed.  
	//		list---Specifies a const CFODrawShapeList& list object(Value).
	CExtRemoveCompsAction(CFODataModel* pModel, const CFODrawShapeList& list);

	// destructor
	
	//-----------------------------------------------------------------------
	// Summary:
	// C F O Remove Components Action, Destructor of class CExtRemoveCompsAction
	//		Returns A  value (Object).
	~CExtRemoveCompsAction();

	// Overrides
public:

	
	//-----------------------------------------------------------------------
	// Summary:
	// Execute, Executes the action.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns BOOLvalue, TRUE on success; FALSE otherwise.
	// Execute the action.
	virtual BOOL Execute();

	// Return the inverse action of this one
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Undo Action, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CFOBaseAction,or NULL if the call failed
	virtual CFOBaseAction* GetUndoAction() const;

	// Return a copy of this action
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Redo Action, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CFOBaseAction,or NULL if the call failed
	virtual CFOBaseAction* GetRedoAction() const;

	// Get the name of the action.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Sprint, .
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		strLabel---strLabel, Specifies A CString type value.
	virtual void Sprint(CString& strLabel) const;

	// Get shapes.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Shape List, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CFODrawShapeList,or NULL if the call failed
	virtual CFODrawShapeList* GetShapeList();

	// Add new shape to the list.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Add Shape, Adds an object to the specify list.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pShape---pShape, A pointer to the CFODrawShape or NULL if the call failed.
	virtual void AddShape(CFODrawShape* pShape);

	// Add shapes to the list.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Add Shapes, Adds an object to the specify list.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		&list---Specifies a E-XD++ CFODrawShapeList &list object (Value).
	virtual void AddShapes(CFODrawShapeList &list);

	// Add shapes to the list.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Add Shapes, Adds an object to the specify list.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		&list---Specifies a E-XD++ CFODrawShapeSet &list object (Value).
	virtual void AddShapes(CFODrawShapeSet &list);

	// Remove shape from the list.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Remove Shape, Call this function to remove a specify value from the specify object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pShape---pShape, A pointer to the CFODrawShape or NULL if the call failed.
	virtual void RemoveShape(CFODrawShape* pShape);

	// Remove all shapes from the list.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Remove All Shapes, Call this function to remove a specify value from the specify object.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void RemoveAllShapes();

	// Get max position of list.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Maximize Position, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CRect type value.
	virtual CRect GetMaxPosition();

	// Clear all index
	
	//-----------------------------------------------------------------------
	// Summary:
	// Clear All Index, Remove the specify data from the list.

	void ClearAllIndex();
	
	// Obtain index of a shape
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Index, Returns the specified value.
	//		Returns BOOLvalue, TRUE on success; FALSE otherwise.  
	// Parameters:
	//		pComp---pComp, A pointer to the CFODrawShape or NULL if the call failed.  
	//		nIndex---nIndex, Specifies A integer value.
	BOOL GetIndex(CFODrawShape* pComp, int& nIndex) const;
	
	// Change the index of a shape.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Index, Sets a specify value to current class CExtRemoveCompsAction
	// Parameters:
	//		pComp---pComp, A pointer to the CFODrawShape or NULL if the call failed.  
	//		nIndex---nIndex, Specifies A integer value.
	void SetIndex(CFODrawShape* pComp, int nIndex);
	
	// Update all shape's index.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Update Indices, Call this member function to update the object.
	// Parameters:
	//		pCompList---Component List, A pointer to the CFODrawShapeList or NULL if the call failed.
	void UpdateIndices(CFODrawShapeList* pCompList);

	// Obtain index within list.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Index Within, Returns the specified value.
	//		Returns a int type value.  
	// Parameters:
	//		*pShape---*pShape, A pointer to the CFODrawShape  or NULL if the call failed.  
	//		pCompList---Component List, A pointer to the CFODrawShapeSet or NULL if the call failed.
	int GetIndexWithin(CFODrawShape *pShape, CFODrawShapeSet* pCompList);

	// Attributes
protected:

	// The list of shapes.
 
	// Shapes, This member specify E-XD++ CFODrawShapeList object.  
	CFODrawShapeList m_listShapes;
	
	// Shape index.
	CMap<CFODrawShape*,CFODrawShape*,int,int> m_shapeIndices;

 
	// F O P Canvas Core, This member specify friend class object.  
	friend class CFOPCanvasCore;
};

_FOLIB_INLINE CFODrawShapeList* CExtRemoveCompsAction::GetShapeList()
{
	return &m_listShapes;
}


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ETAPDEMODOC_H__E4FA9075_6C02_454F_8985_16770216113B__INCLUDED_)
