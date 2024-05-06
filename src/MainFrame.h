#pragma once

// #include <wx/wxprec.h>
// #ifndef WX_PRECOMP
#include <wx/wx.h>

// #endif
#include <wx/wfstream.h>
#include <wx/listctrl.h>

#include "deviceClass.h"
#include "myExceptions.h"

enum Controls
{
    CONFIG_TC_ID = 2
};

class MainFrame : public wxFrame
{
private:
    uint32_t verticalSize = 675,
             horizontalSize = 1000;

    Device *myDevice;

    //  buttons
    wxButton *_exeAllB;
    wxButton *_compareB;
    wxButton *_loadConfigB;
    wxButton *_loadScriptsB;
    wxButton *_fileDialogConfigB;
    wxButton *_fileDialogScriptsB;
    wxButton *_fileDialogRefDumpB;
    wxButton *_clearLogB;

    //  text controls
    wxTextCtrl *_configPathTC;
    wxTextCtrl *_scriptsPathTC;
    wxTextCtrl *_refDumpPathTC;

    // static text
    wxStaticText *_configPathST;
    wxStaticText *_scriptsPathST;
    wxStaticText *_refDumpPathST;

    //  log box
    wxTextCtrl *_exeLog;

    //  loaded scripts list
    wxListBox *_loadedScriptsLB;
    wxListCtrl *_compareResultLC;

    wxString defaultDir;
    wxString lastConfigDir;
    wxString lastScriptDir;
    wxString lastRefDumpDir;

    // wxArrayString loadedScripts;
    std::ostream *logStream;

    void OnStartButtonClicked(wxCommandEvent &evt);
    void OnCompareButtonClicked(wxCommandEvent &evt);
    void OnLoadConfigButtonClicked(wxCommandEvent &evt);
    void OnLoadScriptsButtonClicked(wxCommandEvent &evt);
    void OnOpenDialogConfigButtonClicked(wxCommandEvent &evt);
    void OnOpenDialogScriptsButtonClicked(wxCommandEvent &evt);
    void OnClearLogButtonClicked(wxCommandEvent &evt);

public:
    // MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
    MainFrame(const wxString &title);
    ~MainFrame();
};
