#include "MainFrame.h"

/*
    исправить парсинг свойств, представленных в json как строка, а в protobuf как enum
*/

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title)
{
    wxPanel *panel = new wxPanel(this);

    this->_configPathTC = new wxTextCtrl(panel, wxID_ANY, "/home/inf/Projects/vendotek/input/config.json", wxPoint(150, 50), wxSize(200, -1));
    this->_configPathTC->SetLabelText("Config path");

    // wxStaticText *configPathST = new wxStaticText(panel, wxID_ANY, "Config path", wxPoint(50, 50), wxDefaultSize);

    wxButton *startB = new wxButton(panel, wxID_ANY, "Start", wxPoint(300, 275), wxSize(200, 50));
    wxButton *loadConfigB = new wxButton(panel, wxID_ANY, "Load config", wxPoint(300, 350), wxSize(200, 50));

    startB->Bind(wxEVT_BUTTON, &MainFrame::OnStartButtonClicked, this);
    loadConfigB->Bind(wxEVT_BUTTON, &MainFrame::OnLoadConfigButtonClicked, this);

    CreateStatusBar();

    this->myDevice = new Device();
}

void MainFrame::OnStartButtonClicked(wxCommandEvent &evt)
{
    try
    {
        this->myDevice->_print_scripts();
        this->myDevice->execute_scripts();
    }
    catch (const ex::JsonParsingException &ex)
    {
        wxLogMessage(wxString(ex.what()));
    }
    catch (const ex::FailedExecution &ex)
    {
        wxLogMessage(wxString(ex.what()));
    }
    catch (const ex::InvalidMessageIR &ex)
    {
        wxLogMessage(wxString(ex.what()));
    }
    catch (...)
    {
        wxLogMessage("Unknown problem");
    }
}

void MainFrame::OnLoadConfigButtonClicked(wxCommandEvent &evt)
{
    std::string configPath;

    if (this->_configPathTC->GetLineLength(0) == 0)
    {
        wxFileDialog openFileDialog(this, "Load config .json", "../input", "", "JSON files (*.json)|*.json", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
        if (openFileDialog.ShowModal() == wxID_CANCEL)
            return; // the user changed idea...

        // proceed loading the file chosen by the user;
        // this can be done with e.g. wxWidgets input streams:

        wxFileInputStream input_stream(openFileDialog.GetPath());
        if (!input_stream.IsOk())
        {
            wxLogError("Cannot open file '%s'.", openFileDialog.GetPath());
            return;
        }

        configPath = openFileDialog.GetPath().ToStdString();
        this->_configPathTC->WriteText(configPath);
    }
    else
        configPath = this->_configPathTC->GetLineText(0).ToStdString();

    try
    {
        this->myDevice->loadConfig(configPath);
    }
    catch (const ex::CantOpenFile &ex)
    {
        wxLogMessage(wxString(ex.what()));
    }
    catch (const ex::JsonParsingException &ex)
    {
        wxLogMessage(wxString(ex.what()));
    }
    catch (...)
    {
        wxLogMessage("Unknown problem");
    }
}
