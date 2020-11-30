#include <wx/wxprec.h>

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#define PROGRAM_NAME "market"
#define PROGRAM_NAME_LONG "Open Food Market"
#define PROGRAM_DESCRIPTION "Open Food Market created by Daffa Rahman"
#define PROGRAM_VERSION "4.0.2"

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 300

#define TEXTCTRL_SIZE wxSize(200, 30)

class MainApp : public wxApp
{
public:
	virtual bool OnInit();
};

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString &title, wxSize size);
	
	// define some inputs
	wxTextCtrl *m_txtc_input_product = nullptr;
	wxTextCtrl *m_txtc_input_price = nullptr;
	wxTextCtrl *m_txtc_input_amount = nullptr;

private:
	void OnProceed(wxCommandEvent &event);
	void OnAbout(wxCommandEvent &event);
	void OnExit(wxCommandEvent &event);
};

wxIMPLEMENT_APP(MainApp);

enum 
{
	ID_Proceed = wxID_HIGHEST + 1
};

bool MainApp::OnInit()
{
	MainFrame *frame = new MainFrame(PROGRAM_NAME_LONG, wxSize(WINDOW_WIDTH, WINDOW_HEIGHT));
	frame->Show(true);
	return true;
}

MainFrame::MainFrame(const wxString &title, wxSize size)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, size)
{
	SetMinSize(wxSize(WINDOW_WIDTH, WINDOW_HEIGHT));	
	SetMaxSize(wxSize(WINDOW_WIDTH, WINDOW_HEIGHT));

	///creating menu and menubar///
	wxMenu *file_menu = new wxMenu;
	file_menu->Append(ID_Proceed, "&Proceed\tCtrl-P");
	file_menu->AppendSeparator();
	file_menu->Append(wxID_EXIT);
	
	wxMenu *help_menu = new wxMenu;
	help_menu->Append(wxID_ABOUT);
	
	wxMenuBar *menu_bar = new wxMenuBar;
	menu_bar->Append(file_menu, "&File");
	menu_bar->Append(help_menu, "&Help");
	
	SetMenuBar(menu_bar);

	Bind(wxEVT_MENU, &MainFrame::OnProceed, this, ID_Proceed);	
	Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
	Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);

	// components
	wxStaticText *m_stxt_title = new wxStaticText(this, wxID_ANY, PROGRAM_NAME_LONG, wxPoint(10, 10), wxDefaultSize);
	
	// inputs
	wxStaticText *m_stxt_label_product = new wxStaticText(this, wxID_ANY, "product", wxPoint(10, 50), wxDefaultSize);
	m_txtc_input_product = new wxTextCtrl(this, wxID_ANY, "", wxPoint(110, 50), TEXTCTRL_SIZE);

	wxStaticText *m_stxt_label_price = new wxStaticText(this, wxID_ANY, "price", wxPoint(10,90), wxDefaultSize);
	m_txtc_input_price = new wxTextCtrl(this, wxID_ANY, "", wxPoint(110, 90), TEXTCTRL_SIZE);	

	wxStaticText *m_stxt_label_amount = new wxStaticText(this, wxID_ANY, "amount", wxPoint(10, 130), wxDefaultSize);
	m_txtc_input_amount = new wxTextCtrl(this, wxID_ANY, "", wxPoint(110, 130), TEXTCTRL_SIZE);
}

void MainFrame::OnProceed(wxCommandEvent &event)
{
	wxMessageBox(
		wxString(m_txtc_input_product->GetValue()),
		"Thank you for buying",
		wxOK | wxICON_INFORMATION
	);
}

void MainFrame::OnAbout(wxCommandEvent &event)
{
	wxMessageBox(PROGRAM_DESCRIPTION, "About Food Market", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnExit(wxCommandEvent &event)
{
	Close(true);
}
