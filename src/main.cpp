#include <wx/wxprec.h>

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include <ofm/version.h>
#include <ofm/window.h>
#include <ofm/component.h>

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
	void OnError(const wxString &info);
	void OnClear(wxCommandEvent &event);
	void OnProceed(wxCommandEvent &event);
	void OnAbout(wxCommandEvent &event);
	void OnExit(wxCommandEvent &event);
};

wxIMPLEMENT_APP(MainApp);

enum 
{
	ID_Proceed = wxID_HIGHEST + 1,
	ID_Clear = ID_Proceed + 1
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
	Center();
	SetMinSize(wxSize(WINDOW_WIDTH, WINDOW_HEIGHT));	
	SetMaxSize(wxSize(WINDOW_WIDTH, WINDOW_HEIGHT));

	///creating menu and menubar///
	wxMenu *file_menu = new wxMenu;
	file_menu->Append(ID_Proceed, "&Proceed\tCtrl-P");
	file_menu->Append(ID_Clear, "&Clear");
	file_menu->AppendSeparator();
	file_menu->Append(wxID_EXIT);
	
	wxMenu *help_menu = new wxMenu;
	help_menu->Append(wxID_ABOUT);
	
	wxMenuBar *menu_bar = new wxMenuBar;
	menu_bar->Append(file_menu, "&File");
	menu_bar->Append(help_menu, "&Help");
	
	SetMenuBar(menu_bar);

	Bind(wxEVT_MENU, &MainFrame::OnProceed, this, ID_Proceed);	
	Bind(wxEVT_MENU, &MainFrame::OnClear, this, ID_Clear);
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

void MainFrame::OnError(const wxString &message)
{
	wxMessageBox(message, "Error", wxOK | wxICON_ERROR);
}

void MainFrame::OnClear(wxCommandEvent &event)
{
	m_txtc_input_product->SetValue(wxString(""));
	m_txtc_input_price->SetValue(wxString(""));
	m_txtc_input_amount->SetValue(wxString(""));

	m_txtc_input_product->SetFocus();
}

void MainFrame::OnProceed(wxCommandEvent &event)
{
	double d_price = 0;
	long i_amount = 0;
	double d_total = 0;

	if(!m_txtc_input_price->GetValue().ToDouble(&d_price) 
	|| !m_txtc_input_amount->GetValue().ToLong(&i_amount))
	{OnError("Error Converting, please check your input");return;}

	d_total = d_price * (double)i_amount;

	wxCharBuffer buffer = m_txtc_input_product->GetValue().ToUTF8();
	const char* c_product = buffer.data();

	wxString message = wxString::Format(wxT("Thank you for buying %s for %.2f"), (char*)c_product, d_total);

	wxMessageBox(message, "Thank You!", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnAbout(wxCommandEvent &event)
{
	wxMessageBox(wxString(get_version_info()), "About Food Market", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnExit(wxCommandEvent &event)
{
	Close(true);
}
