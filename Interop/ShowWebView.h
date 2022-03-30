#pragma once
#include <wtypes.h>
#include "exports.h"

namespace Interop
{
   class INTEROP_API ShowWebView
   {
   public:
      static void Go( HWND hWndParent );
   };
}
