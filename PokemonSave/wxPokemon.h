#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/notebook.h>

#include "Gen1.h"

class App : public wxApp
{
public:
	virtual bool OnInit();
};

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
	void LoadSave(wxCommandEvent& event);
	Gen1::SaveFile sf;
	wxButton *load_save_button;
	wxStaticText* player_name_text;
	wxStaticText* rival_name_text;
	wxStaticText* money_text;
};