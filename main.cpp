#include <wx/wxprec.h>

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include "version.hpp"

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
	MainFrame *frame = new MainFrame(PROGRAM_NAME_LONG, wxSize(480, 480));
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
}

void MainFrame::OnAbout(wxCommandEvent &event)
{
	wxMessageBox("iFoodsoft Computers\nFood Market Software\nCurrent version 4.0 Alpha", "About Food Market", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnExit(wxCommandEvent &event)
{
	Close(true);
}
