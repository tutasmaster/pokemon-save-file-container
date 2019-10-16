#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class App : public wxApp
{
public:
	virtual bool OnInit();
};

class Simple : public wxFrame
{
public:
	Simple(const wxString& title);

};