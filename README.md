## WebViewIssue

This repository consists of several projects under one Solution file: WebViewIssue.sln

#### View.NET

Consists of WPF `System.Windows.Window` and `System.Windows.Controls.UserControl` UI elements which are meant for hosting/displaying a `Microsoft.Web.WebView2.Wpf.WebView2` control.

#### App.NET

WPF Application meant to initiate the display of the WebView2 control via View.NET.

#### App.MDI

Multiple-document-interface C++/MFC application used to start the display of the WPF WebView2 control in View.NET.

#### App.MFC

Dialog-based C++/MFC application which serves as another example of what App.MDI basically does.

#### Interop

C++/CLI library used for wrapping calls to the managed View.NET assembly in order to display the WebView2 control.

The method Interop::Show::Go() has 3 strategies for showing the WebView2 host window in View.NET
a) Show the window as a modal window by calling into View.NET (the presenter class will do this)
b) Show the window as a no-owner modeless window via the View.NET presenter
c) Show the window directly with C++/CLI
