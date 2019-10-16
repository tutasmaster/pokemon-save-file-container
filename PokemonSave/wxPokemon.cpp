#include "wxPokemon.h"

Simple::Simple(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(600, 400))
{
	Centre();
}

IMPLEMENT_APP(App)

bool App::OnInit()
{
	Simple* simple = new Simple(wxT("GEN 1 Save Reader"));
	simple->Show(true);

	return true;
}