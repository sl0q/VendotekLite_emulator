#pragma once

// #include <wx/wxprec.h>
// #ifndef WX_PRECOMP
#include <wx/wx.h>

// #endif
#include <wx/wfstream.h>

#include "deviceClass.h"
#include "myExceptions.h"

enum Controls
{
    CONFIG_TC_ID = 2
};

class MainFrame : public wxFrame
{
private:
    Device *myDevice;
    wxTextCtrl *_configPathTC;

    void OnStartButtonClicked(wxCommandEvent &evt);
    void OnLoadConfigButtonClicked(wxCommandEvent &evt);

public:
    // MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
    MainFrame(const wxString &title);
};
