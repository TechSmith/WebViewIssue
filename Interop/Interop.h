#pragma once
#include <wtypes.h>

using namespace System;

namespace Interop
{
   public ref class Show
   {
   public:
      Show();

      void Go( HWND hWndParent );
   };
}
