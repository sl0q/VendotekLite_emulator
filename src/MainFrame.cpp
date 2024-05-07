#include "MainFrame.h"

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title)
{
    this->SetClientSize(horizontalSize, verticalSize);

    wxPanel *panel = new wxPanel(this);

    uint32_t leftPadding = 40,
             rightPadding = horizontalSize - 25,
             topPadding = 25,
             bottomPadding = verticalSize - 50;

    //  static text
    _configPathST = new wxStaticText(panel, wxID_ANY, "Config path:", wxPoint(leftPadding, topPadding), wxDefaultSize);
    _scriptsPathST = new wxStaticText(panel, wxID_ANY, "Scripts path:", wxPoint(leftPadding, topPadding + 50), wxDefaultSize);
    _refDumpPathST = new wxStaticText(panel, wxID_ANY, "Ref dump path:", wxPoint(leftPadding, topPadding + 100), wxDefaultSize);

    //  path text controls
    _configPathTC = new wxTextCtrl(panel, wxID_ANY, "/home/inf/Projects/vendotek/input/config.json", wxPoint(150, topPadding), wxSize(300, -1));
    _scriptsPathTC = new wxTextCtrl(panel, wxID_ANY, "/home/inf/Projects/vendotek/input/test_mifare/ultralight/input_auth_clear_password.json", wxPoint(150, topPadding + 50), wxSize(300, -1));
    _refDumpPathTC = new wxTextCtrl(panel, wxID_ANY, "/home/inf/Projects/vendotek/input/reference_dumps/dump 1 - mfr_ul_auth_clear_password.json", wxPoint(150, topPadding + 100), wxSize(300, -1));

    // loaded scripts list (titles)
    uint32_t loadedScriptsLB_vertical = _refDumpPathTC->GetPosition().y + _refDumpPathTC->GetSize().y + 25;
    _loadedScriptsLB = new wxListBox(panel, wxID_ANY, wxPoint(leftPadding, loadedScriptsLB_vertical), wxSize(505, 150));

    //  dump comparison results
    uint32_t compareResultLB_vertical = _loadedScriptsLB->GetPosition().y + _loadedScriptsLB->GetSize().y + 25;
    _compareResultLC = new wxListCtrl(panel, wxID_ANY, wxPoint(leftPadding + 250, compareResultLB_vertical), wxSize(255, bottomPadding - compareResultLB_vertical), wxLC_REPORT);
    _compareResultLC->InsertColumn(0, "Message index");
    _compareResultLC->InsertColumn(1, "Status");
    _compareResultLC->SetColumnWidth(0, 180);
    _compareResultLC->SetColumnWidth(1, 75);

    uint32_t menu_vertical = _loadedScriptsLB->GetPosition().y + _loadedScriptsLB->GetSize().y + 25;
    // menu buttons
    _exeAllB = new wxButton(panel, wxID_ANY, "Execute All", wxPoint(leftPadding, menu_vertical), wxSize(200, 50));
    _compareB = new wxButton(panel, wxID_ANY, "Compare dumps", wxPoint(leftPadding, menu_vertical + 75), wxSize(200, 50));
    _loadConfigB = new wxButton(panel, wxID_ANY, "Load config", wxPoint(leftPadding, menu_vertical + 150), wxSize(200, 50));
    _loadScriptsB = new wxButton(panel, wxID_ANY, "Load scripts", wxPoint(leftPadding, menu_vertical + 225), wxSize(200, 50));

    //  file dialog buttons
    _fileDialogConfigB = new wxButton(panel, wxID_ANY, "Open", wxPoint(470, topPadding), wxSize(60, 25));
    _fileDialogScriptsB = new wxButton(panel, wxID_ANY, "Open", wxPoint(470, topPadding + 50), wxSize(60, 25));
    _fileDialogRefDumpB = new wxButton(panel, wxID_ANY, "Open", wxPoint(470, topPadding + 100), wxSize(60, 25));

    //  log box
    _exeLog = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(555, topPadding), wxSize(rightPadding - 555, 525), wxTE_MULTILINE | wxTE_READONLY);

    uint32_t clearLogB_vertical = _exeLog->GetPosition().y + _exeLog->GetSize().y + 25;
    //  clear log button
    _clearLogB = new wxButton(panel, wxID_ANY, "Clear Log", wxPoint(rightPadding - 100, clearLogB_vertical), wxSize(100, 50));

    //  stream for log
    logStream = new std::ostream(_exeLog);

    //  button binding
    _exeAllB->Bind(wxEVT_BUTTON, &MainFrame::OnStartButtonClicked, this);
    _compareB->Bind(wxEVT_BUTTON, &MainFrame::OnCompareButtonClicked, this);
    _loadConfigB->Bind(wxEVT_BUTTON, &MainFrame::OnLoadConfigButtonClicked, this);
    _loadScriptsB->Bind(wxEVT_BUTTON, &MainFrame::OnLoadScriptsButtonClicked, this);
    _fileDialogConfigB->Bind(wxEVT_BUTTON, &MainFrame::OnOpenDialogConfigButtonClicked, this);
    _fileDialogScriptsB->Bind(wxEVT_BUTTON, &MainFrame::OnOpenDialogScriptsButtonClicked, this);
    _clearLogB->Bind(wxEVT_BUTTON, &MainFrame::OnClearLogButtonClicked, this);

    CreateStatusBar();

    this->myDevice = new Device();

    _exeAllB->Enable(false);
    _compareB->Enable(false);
}

MainFrame::~MainFrame()
{
    // if (myDevice != nullptr)
    delete myDevice;

    delete _exeAllB;
    delete _compareB;
    delete _loadConfigB;
    delete _loadScriptsB;
    delete _fileDialogConfigB;
    delete _fileDialogScriptsB;
    delete _fileDialogRefDumpB;
    delete _clearLogB;

    delete _configPathST;
    delete _scriptsPathST;
    delete _refDumpPathST;

    delete _configPathTC;
    delete _scriptsPathTC;
    delete _refDumpPathTC;

    delete _loadedScriptsLB;
    delete _compareResultLC;

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
        _compareB->Enable(true);
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

void MainFrame::OnCompareButtonClicked(wxCommandEvent &evt)
{
    for (int i = 0; i < 21; ++i)
    {
        _compareResultLC->InsertItem(i, std::to_string(i) + " message");
        _compareResultLC->SetItem(i, 1, "OK");
        // Set the background color of an item
        _compareResultLC->SetItemBackgroundColour(i, wxColour(0, 255, 70, 100));
    }
    // for (int i = 3; i < 6; ++i)
    // {
    //     _compareResultLC->InsertItem(i, std::to_string(i) + " message");
    //     _compareResultLC->SetItem(i, 1, "NOT OK");
    //     // Set the background color of an item
    //     _compareResultLC->SetItemBackgroundColour(i, wxColour(255, 50, 50, 100));
    // }
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
