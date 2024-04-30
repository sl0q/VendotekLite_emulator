#include "MainFrame.h"

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title)
{
    wxPanel *panel = new wxPanel(this);

    wxStaticText *configPathST = new wxStaticText(panel, wxID_ANY, "Config file path:", wxPoint(40, 50), wxDefaultSize);
    wxStaticText *scriptsPathST = new wxStaticText(panel, wxID_ANY, "Scripts file path:", wxPoint(40, 100), wxDefaultSize);
    this->_configPathTC = new wxTextCtrl(panel, wxID_ANY, "/home/inf/Projects/vendotek/input/config.json", wxPoint(150, 50), wxSize(300, -1));
    this->_scriptsPathTC = new wxTextCtrl(panel, wxID_ANY, "/home/inf/Projects/vendotek/input/test_mifare/ultralight/input_auth_clear_password.json", wxPoint(150, 100), wxSize(300, -1));

    _loadedScriptsLB = new wxListBox(panel, wxID_ANY, wxPoint(40, 150), wxSize(200, 200));

    _exeAllB = new wxButton(panel, wxID_ANY, "Execute All", wxPoint(40, 375), wxSize(200, 50));
    wxButton *loadConfigB = new wxButton(panel, wxID_ANY, "Load config", wxPoint(40, 450), wxSize(200, 50));
    wxButton *loadScriptsB = new wxButton(panel, wxID_ANY, "Load scripts", wxPoint(40, 525), wxSize(200, 50));

    wxButton *fileDialogConfigB = new wxButton(panel, wxID_ANY, "Open", wxPoint(470, 50), wxSize(60, 25));
    wxButton *fileDialogScriptsB = new wxButton(panel, wxID_ANY, "Open", wxPoint(470, 100), wxSize(60, 25));
    wxButton *clearLogB = new wxButton(panel, wxID_ANY, "Clear Log", wxPoint(300, 300), wxSize(100, 50));

    _exeLog = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(555, 50), wxSize(300, 525), wxTE_MULTILINE | wxTE_READONLY);

    logStream = new std::ostream(_exeLog);

    _exeAllB->Bind(wxEVT_BUTTON, &MainFrame::OnStartButtonClicked, this);
    loadConfigB->Bind(wxEVT_BUTTON, &MainFrame::OnLoadConfigButtonClicked, this);
    loadScriptsB->Bind(wxEVT_BUTTON, &MainFrame::OnLoadScriptsButtonClicked, this);
    fileDialogConfigB->Bind(wxEVT_BUTTON, &MainFrame::OnOpenDialogConfigButtonClicked, this);
    fileDialogScriptsB->Bind(wxEVT_BUTTON, &MainFrame::OnOpenDialogScriptsButtonClicked, this);
    clearLogB->Bind(wxEVT_BUTTON, &MainFrame::OnClearLogButtonClicked, this);

    CreateStatusBar();

    this->myDevice = new Device();

    _exeAllB->Enable(false);
}

MainFrame::~MainFrame()
{
    // if (myDevice != nullptr)
    delete myDevice;

    delete _exeAllB;

    // if (_configPathTC != nullptr)
    delete _configPathTC;
    // if (_scriptsPathTC != nullptr)
    delete _scriptsPathTC;
    // if (_loadedScriptsLB != nullptr)
    delete _loadedScriptsLB;

    delete logStream;
}

void MainFrame::OnStartButtonClicked(wxCommandEvent &evt)
{
    wxLogStatus("Executing...");
    try
    {
        if (!this->myDevice->is_config_loaded())
            std::cout << "WARNING: configuration file was not provided. Default device settings will be used." << std::endl;
        this->myDevice->_print_scripts();
        this->myDevice->execute_scripts(*logStream);
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
        if (!lastConfigDir.IsEmpty())
            defaultDir = lastConfigDir;
        wxFileDialog openFileDialog(this, "Load config .json", defaultDir, "", "JSON files (*.json)|*.json", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
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
        lastConfigDir = openFileDialog.GetDirectory().ToStdString();
        this->_configPathTC->Clear();
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
    std::string filePath;

    if (this->_scriptsPathTC->GetLineLength(0) == 0)
    {
        if (!lastScriptDir.IsEmpty())
            defaultDir = lastScriptDir;
        wxFileDialog openFileDialog(this, "Load input scripts .json", defaultDir, "", "JSON files (*.json)|*.json", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
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

        filePath = openFileDialog.GetPath().ToStdString();
        lastScriptDir = openFileDialog.GetDirectory().ToStdString();
        this->_scriptsPathTC->Clear();
        this->_scriptsPathTC->WriteText(filePath);
    }
    else
        filePath = this->_scriptsPathTC->GetLineText(0).ToStdString();

    wxLogStatus("Loading scripts...");

    try
    {
        // this->myDevice->load_input_script_file(filePath);
        // loadedScripts.Clear();
        _loadedScriptsLB->Clear();
        for (auto &scriptTitle : this->myDevice->load_input_script_file(filePath))
            _loadedScriptsLB->AppendString(scriptTitle);

        wxLogStatus("Scripts were loaded successfuly.");
        _exeAllB->Enable(true);
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

void MainFrame::OnOpenDialogConfigButtonClicked(wxCommandEvent &evt)
{
    std::string filePath;
    if (!lastConfigDir.IsEmpty())
        defaultDir = lastConfigDir;
    wxFileDialog openFileDialog(this, "Load config .json", defaultDir, "", "JSON files (*.json)|*.json", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
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

    filePath = openFileDialog.GetPath().ToStdString();
    lastConfigDir = openFileDialog.GetDirectory().ToStdString();
    this->_configPathTC->Clear();
    this->_configPathTC->WriteText(filePath);
}

void MainFrame::OnOpenDialogScriptsButtonClicked(wxCommandEvent &evt)
{
    std::string filePath;
    if (!lastScriptDir.IsEmpty())
        defaultDir = lastScriptDir;
    wxFileDialog openFileDialog(this, "Load scripts .json", defaultDir, "", "JSON files (*.json)|*.json", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
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

    filePath = openFileDialog.GetPath().ToStdString();
    lastScriptDir = openFileDialog.GetDirectory().ToStdString();
    this->_scriptsPathTC->Clear();
    this->_scriptsPathTC->WriteText(filePath);
}

void MainFrame::OnClearLogButtonClicked(wxCommandEvent &evt)
{
    _exeLog->Clear();
}
