#include <wx/wxprec.h>

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#define PROGRAM_NAME "market"
#define PROGRAM_NAME_LONG "Open Food Market"
#define PROGRAM_DESCRIPTION "Open Food Market created by Daffa Rahman"
#define PROGRAM_VERSION "4.0.2"

#define WINDOW_WIDTH 480
#define WINDOW_HEIGHT 240

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

private:
	void OnAbout(wxCommandEvent &event);
	void OnExit(wxCommandEvent &event);
};

wxIMPLEMENT_APP(MainApp);

bool MainApp::OnInit()
{
	MainFrame *frame = new MainFrame(PROGRAM_NAME_LONG, wxSize(WINDOW_WIDTH, WINDOW_HEIGHT));
	frame->Show(true);
	return true;
}

MainFrame::MainFrame(const wxString &title, wxSize size)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, size)
{
	///creating menu and menubar///
	wxMenu *file_menu = new wxMenu;
	file_menu->Append(wxID_EXIT);
	
	wxMenu *help_menu = new wxMenu;
	help_menu->Append(wxID_ABOUT);
	
	wxMenuBar *menu_bar = new wxMenuBar;
	menu_bar->Append(file_menu, "&File");
	menu_bar->Append(help_menu, "&Help");
	
	SetMenuBar(menu_bar);
	
	Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
	Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);

	// components
	wxStaticText *m_stxt_title = new wxStaticText(this, wxID_ANY, PROGRAM_NAME_LONG, wxPoint(10, 10), wxDefaultSize);
	
	// inputs
	wxStaticText *m_stxt_label_product = new wxStaticText(this, wxID_ANY, "product name", wxPoint(10, 50), wxDefaultSize);
	wxTextCtrl *m_txtc_input_product = new wxTextCtrl(this, wxID_ANY, "", wxPoint(120, 50), TEXTCTRL_SIZE);
}

void MainFrame::OnAbout(wxCommandEvent &event)
{
	wxMessageBox(PROGRAM_DESCRIPTION, "About Food Market", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnExit(wxCommandEvent &event)
{
	Close(true);
}
