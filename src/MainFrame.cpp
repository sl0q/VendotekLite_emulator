#include "MainFrame.h"

/*
    unknown error
    go debugging
*/

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title)
{
    wxPanel *panel = new wxPanel(this);

    wxStaticText *configPathST = new wxStaticText(panel, wxID_ANY, "Input file path:", wxPoint(50, 25), wxDefaultSize);
    this->_configPathTC = new wxTextCtrl(panel, wxID_ANY, "/home/inf/Projects/vendotek/input/config.json", wxPoint(150, 50), wxSize(200, -1));
    this->_inputPathTC = new wxTextCtrl(panel, wxID_ANY, "/home/inf/Projects/vendotek/input/test_contactless/input_poll_for_token.json", wxPoint(150, 75), wxSize(200, -1));

    // wxStaticText *configPathST = new wxStaticText(panel, wxID_ANY, "Config path", wxPoint(50, 50), wxDefaultSize);

    wxButton *startB = new wxButton(panel, wxID_ANY, "Start", wxPoint(300, 275), wxSize(200, 50));
    wxButton *loadConfigB = new wxButton(panel, wxID_ANY, "Load config", wxPoint(300, 350), wxSize(200, 50));
    wxButton *loadInputB = new wxButton(panel, wxID_ANY, "Load scripts", wxPoint(300, 425), wxSize(200, 50));

    startB->Bind(wxEVT_BUTTON, &MainFrame::OnStartButtonClicked, this);
    loadConfigB->Bind(wxEVT_BUTTON, &MainFrame::OnLoadConfigButtonClicked, this);
    loadInputB->Bind(wxEVT_BUTTON, &MainFrame::OnLoadScriptsButtonClicked, this);

    CreateStatusBar();

    this->myDevice = new Device();
}

MainFrame::~MainFrame()
{
    if (myDevice != nullptr)
        delete myDevice;

    if (_configPathTC != nullptr)
        delete _configPathTC;
    if (_inputPathTC != nullptr)
        delete _inputPathTC;
}

void MainFrame::OnStartButtonClicked(wxCommandEvent &evt)
{
    wxLogStatus("Executing...");
    try
    {
        if (!this->myDevice->is_config_loaded())
            std::cout << "WARNING: configuration file was not provided. Default device settings will be used." << std::endl;
        this->myDevice->_print_scripts();
        this->myDevice->execute_scripts();
        wxLogStatus("Scripts were executed.");
    }
    catch (const ex::JsonParsingException &ex)
    {
        wxLogMessage(wxString(ex.what()));
        wxLogStatus("Error");
    }
    catch (const ex::FailedExecution &ex)
    {
        wxLogMessage(wxString(ex.what()));
        wxLogStatus("Error");
    }
    catch (const ex::InvalidMessageIR &ex)
    {
        wxLogMessage(wxString(ex.what()));
        wxLogStatus("Error");
    }
    catch (...)
    {
        wxLogMessage("Unknown problem");
        wxLogStatus("Error");
    }
    wxLogStatus("Finished execution.");
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

    wxLogStatus("Loading config...");

    try
    {
        this->myDevice->load_config(configPath);
        wxLogStatus("Config was loaded successfuly.");
    }
    catch (const ex::CantOpenFile &ex)
    {
        wxLogMessage(wxString(ex.what()));
        wxLogStatus("Error");
    }
    catch (const ex::JsonParsingException &ex)
    {
        wxLogMessage(wxString(ex.what()));
        wxLogStatus("Error");
    }
    catch (const ex::InvalidMessageIR &ex)
    {
        wxLogMessage(wxString(ex.what()));
        wxLogStatus("Error");
    }
    catch (const std::invalid_argument &ex)
    {
        wxLogMessage(wxString(ex.what()));
        wxLogStatus("Error");
    }
    catch (...)
    {
        wxLogMessage("Unknown problem");
        wxLogStatus("Error");
    }
}

void MainFrame::OnLoadScriptsButtonClicked(wxCommandEvent &evt)
{
    std::string inputPath;

    if (this->_inputPathTC->GetLineLength(0) == 0)
    {
        wxFileDialog openFileDialog(this, "Load input scripts .json", "../input", "", "JSON files (*.json)|*.json", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
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

        inputPath = openFileDialog.GetPath().ToStdString();
        this->_inputPathTC->WriteText(inputPath);
    }
    else
        inputPath = this->_inputPathTC->GetLineText(0).ToStdString();

    wxLogStatus("Loading scripts...");

    try
    {
        this->myDevice->load_input_script_file(inputPath);
        wxLogStatus("Scripts were loaded successfuly.");
    }
    catch (const ex::CantOpenFile &ex)
    {
        wxLogMessage(wxString(ex.what()));
        wxLogStatus("Error");
    }
    catch (const ex::JsonParsingException &ex)
    {
        wxLogMessage(wxString(ex.what()));
        wxLogStatus("Error");
    }
    catch (const ex::InvalidMessageIR &ex)
    {
        wxLogMessage(wxString(ex.what()));
        wxLogStatus("Error");
    }
    catch (const std::invalid_argument &ex)
    {
        wxLogMessage(wxString(ex.what()));
        wxLogStatus("Error");
    }
    catch (...)
    {
        wxLogMessage("Unknown problem");
        wxLogStatus("Error");
    }
}
