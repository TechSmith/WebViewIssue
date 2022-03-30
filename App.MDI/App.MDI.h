#pragma once
#include "resource.h"

class CAppMDIApp : public CWinApp
{
public:
   CAppMDIApp() noexcept;

   // Overrides
public:
   virtual BOOL InitInstance();
   virtual int ExitInstance();

   // Implementation
   afx_msg void OnAppAbout();
   DECLARE_MESSAGE_MAP()
   afx_msg void OnFileOpenwebview();
};

extern CAppMDIApp theApp;
