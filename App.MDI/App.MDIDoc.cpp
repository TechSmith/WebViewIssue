#include "pch.h"
#include "framework.h"
#include "App.MDIDoc.h"
#include <propkey.h>

IMPLEMENT_DYNCREATE( CAppMDIDoc, CDocument )

BEGIN_MESSAGE_MAP( CAppMDIDoc, CDocument )
END_MESSAGE_MAP()

void CAppMDIDoc::Serialize( CArchive& ar )
{
   if ( ar.IsStoring() )
   {
   }
   else
   {
   }
}
