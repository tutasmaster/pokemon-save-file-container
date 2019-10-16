#include "wxPokemon.h"

MainFrame::MainFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(600, 400),
wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN)
{
	wxPanel *panel = new wxPanel(this, wxID_ANY);
	panel->SetBackgroundColour(wxColour("ffffff"));

	load_save_button = new wxButton(panel, wxID_FILE, wxT("NO SAVEFILE HAS BEEN LOADED!"),wxDefaultPosition,wxSize(600,26));

	wxPanel* player_panel = new wxPanel(this, wxID_ANY);
	player_panel->SetBackgroundColour(wxColour("ff0000"));
	player_name_text = new wxStaticText(player_panel, wxID_ANY, "Player Name: PLAYER");
	rival_name_text = new wxStaticText(player_panel, wxID_ANY, "Rival Name: RIVAL");
	money_text = new wxStaticText(player_panel, wxID_ANY, "Money: 00000$");

	wxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(load_save_button,0,0,0);
	sizer->Add(player_panel);
	panel->SetSizer(sizer);
	sizer->SetSizeHints(panel);
	wxSizer* player_sizer = new wxBoxSizer(wxVERTICAL);
	player_sizer->Add(player_name_text);
	player_sizer->Add(rival_name_text);
	player_sizer->Add(money_text);
	player_panel->SetSizer(player_sizer);
	player_sizer->SetSizeHints(player_panel);

	Connect(wxID_FILE, wxEVT_COMMAND_BUTTON_CLICKED, 
		wxCommandEventHandler(MainFrame::LoadSave));
	Centre();
}
void MainFrame::LoadSave(wxCommandEvent& event)
{
	wxFileDialog * openFileDialog = new wxFileDialog(this,("Open SAV file"),"","Pokemon Yellow.sav","SAV file (*.sav)|*.sav", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if(openFileDialog->ShowModal() == wxID_OK)
	{
		wxString filename = openFileDialog->GetPath();
		Gen1::SaveFileReader sfr;
		sfr.ReadToFile(sf, filename.c_str());
		load_save_button->SetLabel(filename);
		player_name_text->SetLabelText("Player Name: " + (std::string(sf.player_data.name)));
		rival_name_text->SetLabelText("Rival Name: " + (std::string(sf.player_data.rival_name)));
		money_text->SetLabelText("Money: " + std::to_string(sf.player_data.money) + "$");
	}
}

IMPLEMENT_APP(App)

bool App::OnInit()
{
	MainFrame* main_frame = new MainFrame(wxT("GEN 1 Save Reader"));
	main_frame->Show(true);

	return true;
}