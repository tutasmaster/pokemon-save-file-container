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
	void UpdatePokemon(wxCommandEvent& event);
	Gen1::SaveFile sf;

protected:
	wxButton* savefile_button;
	wxPanel* m_panel1;
	wxStaticText* m_staticText12;
	wxStaticText* player_name_text;
	wxStaticText* rival_name_text;
	wxStaticText* money_text;
	wxListBox* m_listBox1;
	wxPanel* m_panel2;
	wxStaticText* m_staticText13;
	wxStaticText* m_staticText14;
	wxStaticText* m_staticText15;
	wxStaticText* m_staticText16;
	wxStaticText* m_staticText161;
	wxStaticText* m_staticText1611;
	wxStaticText* m_staticText1612;
	wxStaticText* m_staticText16121;
	wxStaticText* m_staticText161211;
	wxStaticText* m_staticText161212;
	wxStaticText* m_staticText161213;
	wxStaticText* m_staticText1612131;
};