#include "wxPokemon.h"

MainFrame::MainFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(600, 400),
wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN)
{
	wxBoxSizer* main_sizer;
	main_sizer = new wxBoxSizer(wxVERTICAL);

	savefile_button = new wxButton(this, wxID_FILE, wxT("NO SAVEFILE HAS BEEN LOADED!"), wxDefaultPosition, wxDefaultSize, 0);
	main_sizer->Add(savefile_button, 0, wxALL | wxEXPAND, 5);

	wxBoxSizer* side_sizer;
	side_sizer = new wxBoxSizer(wxHORIZONTAL);

	m_panel1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));

	wxBoxSizer* player_sizer;
	player_sizer = new wxBoxSizer(wxVERTICAL);

	m_staticText12 = new wxStaticText(m_panel1, wxID_ANY, wxT("PLAYER:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText12->Wrap(-1);
	m_staticText12->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial")));

	player_sizer->Add(m_staticText12, 0, wxALL | wxEXPAND, 5);

	player_name_text = new wxStaticText(m_panel1, wxID_ANY, wxT("Player Name: PLAYER"), wxDefaultPosition, wxDefaultSize, 0);
	player_name_text->Wrap(-1);
	player_sizer->Add(player_name_text, 0, wxALL, 5);

	rival_name_text = new wxStaticText(m_panel1, wxID_ANY, wxT("Rival Name: RIVAL"), wxDefaultPosition, wxDefaultSize, 0);
	rival_name_text->Wrap(-1);
	player_sizer->Add(rival_name_text, 0, wxALL, 5);

	money_text = new wxStaticText(m_panel1, wxID_ANY, wxT("Money: 00000$"), wxDefaultPosition, wxDefaultSize, 0);
	money_text->Wrap(-1);
	player_sizer->Add(money_text, 0, wxALL, 5);

	m_listBox1 = new wxListBox(m_panel1, wxID_OPEN, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	m_listBox1->Append(wxT("Pokemon 1"));
	m_listBox1->Append(wxT("Pokemon 2"));
	m_listBox1->Append(wxT("Pokemon 3"));
	m_listBox1->Append(wxT("Pokemon 4"));
	m_listBox1->Append(wxT("Pokemon 5"));
	m_listBox1->Append(wxT("Pokemon 6"));
	player_sizer->Add(m_listBox1, 0, wxALL, 5);


	m_panel1->SetSizer(player_sizer);
	m_panel1->Layout();
	player_sizer->Fit(m_panel1);
	side_sizer->Add(m_panel1, 1, wxEXPAND | wxALL, 5);

	m_panel2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));

	wxBoxSizer* pokemon_sizer;
	pokemon_sizer = new wxBoxSizer(wxVERTICAL);

	m_staticText13 = new wxStaticText(m_panel2, wxID_ANY, wxT("POKEMON:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText13->Wrap(-1);
	m_staticText13->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial")));

	pokemon_sizer->Add(m_staticText13, 0, wxALL, 5);

	m_staticText14 = new wxStaticText(m_panel2, wxID_ANY, wxT("Name:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText14->Wrap(-1);
	pokemon_sizer->Add(m_staticText14, 0, wxALL, 5);

	m_staticText15 = new wxStaticText(m_panel2, wxID_ANY, wxT("Race:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText15->Wrap(-1);
	pokemon_sizer->Add(m_staticText15, 0, wxALL, 5);

	m_staticText16 = new wxStaticText(m_panel2, wxID_ANY, wxT("Move 1:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText16->Wrap(-1);
	m_staticText16->SetFont(wxFont(8, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial")));

	pokemon_sizer->Add(m_staticText16, 0, wxALL, 5);

	m_staticText161 = new wxStaticText(m_panel2, wxID_ANY, wxT("Move 2:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText161->Wrap(-1);
	m_staticText161->SetFont(wxFont(8, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial")));

	pokemon_sizer->Add(m_staticText161, 0, wxALL, 5);

	m_staticText1611 = new wxStaticText(m_panel2, wxID_ANY, wxT("Move 3:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText1611->Wrap(-1);
	m_staticText1611->SetFont(wxFont(8, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial")));

	pokemon_sizer->Add(m_staticText1611, 0, wxALL, 5);

	m_staticText1612 = new wxStaticText(m_panel2, wxID_ANY, wxT("Move 4:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText1612->Wrap(-1);
	m_staticText1612->SetFont(wxFont(8, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial")));

	pokemon_sizer->Add(m_staticText1612, 0, wxALL, 5);

	m_staticText16121 = new wxStaticText(m_panel2, wxID_ANY, wxT("Health:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText16121->Wrap(-1);
	m_staticText16121->SetFont(wxFont(8, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial")));

	pokemon_sizer->Add(m_staticText16121, 0, wxALL, 5);

	m_staticText161211 = new wxStaticText(m_panel2, wxID_ANY, wxT("Attack:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText161211->Wrap(-1);
	m_staticText161211->SetFont(wxFont(8, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial")));

	pokemon_sizer->Add(m_staticText161211, 0, wxALL, 5);

	m_staticText161212 = new wxStaticText(m_panel2, wxID_ANY, wxT("Defense:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText161212->Wrap(-1);
	m_staticText161212->SetFont(wxFont(8, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial")));

	pokemon_sizer->Add(m_staticText161212, 0, wxALL, 5);

	m_staticText161213 = new wxStaticText(m_panel2, wxID_ANY, wxT("Special:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText161213->Wrap(-1);
	m_staticText161213->SetFont(wxFont(8, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial")));

	pokemon_sizer->Add(m_staticText161213, 0, wxALL, 5);

	m_staticText1612131 = new wxStaticText(m_panel2, wxID_ANY, wxT("Speed:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText1612131->Wrap(-1);
	m_staticText1612131->SetFont(wxFont(8, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial")));

	pokemon_sizer->Add(m_staticText1612131, 0, wxALL, 5);


	m_panel2->SetSizer(pokemon_sizer);
	m_panel2->Layout();
	pokemon_sizer->Fit(m_panel2);
	side_sizer->Add(m_panel2, 1, wxEXPAND | wxALL, 5);


	main_sizer->Add(side_sizer, 1, wxEXPAND, 5);


	this->SetSizer(main_sizer);
	this->Layout();

	Connect(wxID_FILE, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MainFrame::LoadSave));
	Connect(wxID_OPEN, wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,
		wxCommandEventHandler(MainFrame::UpdatePokemon));

	Centre();
}

void MainFrame::UpdatePokemon(wxCommandEvent& event) {
	if (m_listBox1->GetSelection() != wxNOT_FOUND) {
		int select = m_listBox1->GetSelection();
		m_staticText14->SetLabelText("Name: " + std::string(sf.party_data[select].name));
		m_staticText15->SetLabelText("Race: " + Gen1::Pokemon_List[sf.party_data[select].id].name);
		m_staticText16->SetLabelText("Move 1: " + Gen1::Move_List[sf.party_data[select].move1].name);
		m_staticText161->SetLabelText("Move 2: " + Gen1::Move_List[sf.party_data[select].move2].name);
		m_staticText1611->SetLabelText("Move 3: " + Gen1::Move_List[sf.party_data[select].move3].name);
		m_staticText1612->SetLabelText("Move 4: " + Gen1::Move_List[sf.party_data[select].move4].name);
		m_staticText16121->SetLabelText("Health: " + std::to_string(sf.party_data[select].hp));
		m_staticText161211->SetLabelText("Attack: " + std::to_string(sf.party_data[select].atk));
		m_staticText161212->SetLabelText("Defense: " + std::to_string(sf.party_data[select].def));
		m_staticText161213->SetLabelText("Special: " + std::to_string(sf.party_data[select].spc));
		m_staticText1612131->SetLabelText("Speed: " + std::to_string(sf.party_data[select].spd));
	}
}


void MainFrame::LoadSave(wxCommandEvent& event)
{
	wxFileDialog * openFileDialog = new wxFileDialog(this,("Open SAV file"),"","Pokemon Yellow.sav","SAV file (*.sav)|*.sav", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if(openFileDialog->ShowModal() == wxID_OK)
	{
		wxString filename = openFileDialog->GetPath();
		Gen1::SaveFileReader sfr;
		sfr.ReadToFile(sf, filename.c_str());
		savefile_button->SetLabel(filename);
		player_name_text->SetLabelText("Player Name: " + (std::string(sf.player_data.name)));
		rival_name_text->SetLabelText("Rival Name: " + (std::string(sf.player_data.rival_name)));
		money_text->SetLabelText("Money: " + std::to_string(sf.player_data.money) + "$");
		m_listBox1->Clear();
		for (auto i = 0; i < sf.party_size; i++) {
			m_listBox1->Append(Gen1::Pokemon_List[sf.party_data[i].id].name);
		}
	}
}

IMPLEMENT_APP(App)

bool App::OnInit()
{
	MainFrame* main_frame = new MainFrame(wxT("GEN 1 Save Reader"));
	main_frame->Show(true);

	return true;
}