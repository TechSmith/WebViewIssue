#pragma once

class CAppMDIDoc : public CDocument
{
protected:
   DECLARE_DYNCREATE( CAppMDIDoc )

   // Overrides
public:
   virtual void Serialize( CArchive& ar );

   // Generated message map functions
protected:
   DECLARE_MESSAGE_MAP()
};
