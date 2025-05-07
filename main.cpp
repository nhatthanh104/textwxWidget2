#include <wx/wx.h>
#include <wx/statline.h>

class LoginFrame : public wxFrame
{
public:
    LoginFrame() : wxFrame(NULL, wxID_ANY, "Đăng nhập", wxDefaultPosition, wxSize(350, 250))
    {
        Centre(); // căn giữa cửa sổ
        wxPanel* panel = new wxPanel(this);

        wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

        // Tiêu đề
        wxStaticText* title = new wxStaticText(panel, wxID_ANY, "ĐĂNG NHẬP HỆ THỐNG");
        title->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
        vbox->Add(title, 0, wxALIGN_CENTER | wxTOP, 20);

        vbox->Add(new wxStaticLine(panel), 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
        vbox->AddSpacer(15);

        // Sizer lưới cho username/password
        wxFlexGridSizer* grid = new wxFlexGridSizer(2, 2, 10, 10);

        grid->Add(new wxStaticText(panel, wxID_ANY, "Tên đăng nhập:"), 0, wxALIGN_CENTER_VERTICAL | wxALIGN_RIGHT);
        m_username = new wxTextCtrl(panel, wxID_ANY);
        grid->Add(m_username, 1, wxEXPAND);

        grid->Add(new wxStaticText(panel, wxID_ANY, "Mật khẩu:"), 0, wxALIGN_CENTER_VERTICAL | wxALIGN_RIGHT);
        m_password = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
        grid->Add(m_password, 1, wxEXPAND);

        grid->AddGrowableCol(1, 1);
        vbox->Add(grid, 0, wxEXPAND | wxLEFT | wxRIGHT, 20);
        vbox->AddSpacer(15);

        // Nút
        wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
        wxButton* btnLogin = new wxButton(panel, wxID_OK, "Đăng nhập");
        wxButton* btnExit = new wxButton(panel, wxID_CANCEL, "Thoát");

        hbox->AddStretchSpacer(1);
        hbox->Add(btnLogin, 0, wxRIGHT, 10);
        hbox->Add(btnExit, 0);
        hbox->AddStretchSpacer(1);

        vbox->Add(hbox, 0, wxEXPAND | wxALL, 10);
        panel->SetSizer(vbox);

        // Gán sự kiện
        btnLogin->Bind(wxEVT_BUTTON, &LoginFrame::OnLogin, this);
        btnExit->Bind(wxEVT_BUTTON, [&](wxCommandEvent&){ Close(); });
    }

private:
    wxTextCtrl* m_username;
    wxTextCtrl* m_password;

    void OnLogin(wxCommandEvent&)
    {
        wxString username = m_username->GetValue();
        wxString password = m_password->GetValue();

        if (username.IsEmpty() || password.IsEmpty())
        {
            wxMessageBox("Vui lòng nhập đầy đủ thông tin!", "Thông báo", wxICON_WARNING);
            return;
        }

        if (username == "admin" && password == "123456")
        {
            wxMessageBox("Đăng nhập thành công!", "Thông báo", wxICON_INFORMATION);
        }
        else
        {
            wxMessageBox("Sai tên đăng nhập hoặc mật khẩu!", "Lỗi", wxICON_ERROR);
        }
    }
};

class LoginApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        LoginFrame* frame = new LoginFrame();
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(LoginApp);

