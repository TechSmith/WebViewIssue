#pragma once
#include "resource.h"

class CAppMFCApp : public CWinApp
{
public:
   virtual BOOL InitInstance();

   DECLARE_MESSAGE_MAP()
};

extern CAppMFCApp theApp;
