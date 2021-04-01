//$Id$
//------------------------------------------------------------------------------
//                            TransTlePanel
//------------------------------------------------------------------------------
// GMAT: General Mission Analysis Tool
//
//
// Copyright (c) 2002 - 2020 United States Government as represented by the
// Administrator of the National Aeronautics and Space Administration.
// All Other Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License"); 
// You may not use this file except in compliance with the License. 
// You may obtain a copy of the License at:
// http://www.apache.org/licenses/LICENSE-2.0. 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either 
// express or implied.   See the License for the specific language
// governing permissions and limitations under the License.
//
// Developed jointly by NASA/GSFC and Thinking Systems, Inc. under contract
// number NNG04CC06P.
//
//
// Author: Phillip Silvia, based on the OrbitPanel by Allison Greene
// Created: 2009/08/12
/**
 * Panel for displaying the currently loaded model for the spacecraft and storing
 * initial parameters.
 */
//------------------------------------------------------------------------------
#include "TransTlePanel.hpp"
#include "MessageInterface.hpp"
#include "FileManager.hpp"
#include "GmatStaticBoxSizer.hpp"
#include "GmatColorPanel.hpp"
#include "RgbColor.hpp"             // for RgbColor
#include <wx/clrpicker.h>           // for wxColorPickerCtrl
#include "FileUtil.hpp"    
//#define DEBUG_PANEL_CREATE
//#define DEBUG_PANEL_LOAD
//#define DEBUG_PANEL_SAVE


//------------------------------------------------------------------------------
// event tables for wxWindows
//------------------------------------------------------------------------------
BEGIN_EVENT_TABLE(TransTlePanel, wxPanel)
 
   EVT_TEXT(ID_MODELFILE_TEXT, TransTlePanel::OnTextCtrlChange)
   EVT_TEXT(ID_ROT_TEXT, TransTlePanel::OnTextCtrlChange)
   EVT_TEXT(ID_TRAN_TEXT, TransTlePanel::OnTextCtrlChange)
   EVT_TEXT(ID_SCALE_TEXT, TransTlePanel::OnTextCtrlChange)
   EVT_BUTTON(ID_BROWSE_BUTTON, TransTlePanel::OnBrowseButton)
 
END_EVENT_TABLE()

//------------------------------
// public methods
//------------------------------
//------------------------------------------------------------------------------
// TransTlePanel(GmatPanel *scPanel, wxWindow *parent, Spacecraft *spacecraft,
//            SolarSystem *solarsystem
//------------------------------------------------------------------------------
/**
 * Constructs TransTlePanel object.
 *
 * @param <parent> input parent.
 *
 * @note Creates the Universe GUI
 */
//------------------------------------------------------------------------------
TransTlePanel::TransTlePanel(GmatPanel *scPanel, wxWindow *parent,
                       Spacecraft *spacecraft)
   : wxPanel(parent)
{
   #ifdef DEBUG_PANEL_CREATE
   MessageInterface::ShowMessage
      ("TransTlePanel() constructor entered, spacecraft=<%p>'%s'\n", spacecraft,
       spacecraft ? spacecraft->GetName().c_str() : "NULL");
   #endif
   
   // initalize data members
   theScPanel = scPanel;
   theGuiManager = GuiItemManager::GetInstance();
   currentSpacecraft = spacecraft;
   
   FileManager *fm = FileManager::Instance();
   try
   {
      modelPath = wxString(fm->GetPathname("VEHICLE_MODEL_PATH").c_str());
   }
   catch (BaseException &be)
   {
      MessageInterface::ShowMessage("%s\n", be.GetFullMessage().c_str());
   }
   
   #ifdef DEBUG_PANEL_CREATE
   MessageInterface::ShowMessage("   modelPath = '%s'\n", modelPath.WX_TO_C_STRING);
   #endif
   
   Create();
   LoadData();
   
   #ifdef DEBUG_PANEL_CREATE
   MessageInterface::ShowMessage
      ("TransTlePanel() constructor leaving, spacecraft=<%p>'%s'\n", spacecraft,
       spacecraft ? spacecraft->GetName().c_str() : "NULL");
   #endif
}


//------------------------------------------------------------------------------
// ~TransTlePanel()
//------------------------------------------------------------------------------
TransTlePanel::~TransTlePanel()
{
}


//-------------------------------
// private methods
//-------------------------------

//------------------------------------------------------------------------------
// void Create()
//------------------------------------------------------------------------------
/**
 *
 * @note Creates the page for orbit information
 */
//------------------------------------------------------------------------------
void TransTlePanel::Create()
{
   #ifdef DEBUG_PANEL_CREATE
      MessageInterface::ShowMessage("TransTlePanel::Create() entered\n");
   #endif
   
   Integer bsize = 2.0; // border size
   
   //-----------------------------------------------------------------
   // Platform dependent button size
   //-----------------------------------------------------------------
   #ifdef __WXMAC__
   int buttonWidth = 40;
   #else
   int buttonWidth = 25;
   #endif
   
   // Creates the sizer for the overall panel
   wxBoxSizer *visSizer = new wxBoxSizer(wxHORIZONTAL);//wxHORIZONTAL
   // Sizer for the left side, which has all the sliders
   wxBoxSizer *leftSizer = new wxBoxSizer(wxVERTICAL);//wxVERTICAL
   // A box containing the file loader
   wxStaticBox *filenameBox = new wxStaticBox(this, ID_STATIC_ELEMENT, wxString("File Name")); //
   wxStaticBoxSizer* filenameSizer = new wxStaticBoxSizer(filenameBox, wxVERTICAL); //wxVERTICAL
   // Sizer for the file loader
   wxFlexGridSizer *flexFileSizer = new wxFlexGridSizer(1, 2, bsize, bsize);
   // Text and button for the file loader
   modelTextCtrl = new wxTextCtrl(this, ID_MODELFILE_TEXT, wxT(""), wxDefaultPosition, wxSize(180, -1), wxTE_PROCESS_ENTER);
   wxButton *browseButton = new wxButton(this, ID_BROWSE_BUTTON, wxT(" Browse"));
   //browseButton->SetToolTip(wxT("Find a model file to attach to the spacecraft"));

   // Add all components to their appropriate sizers
   flexFileSizer->Add(modelTextCtrl, 0, wxALIGN_LEFT | wxALL, bsize);
   flexFileSizer->Add(browseButton, 0, wxALIGN_LEFT | wxALL, bsize);
 
   // Add the inner sizers to their out sizers
   filenameSizer->Add(flexFileSizer, 0, wxALIGN_LEFT | wxALL, bsize);
   
   // Put all of the sizers into their appropriate sides of the panel
   leftSizer->Add(filenameSizer, 0, wxGROW | wxALIGN_CENTER, bsize);
 
   // Add the left and right halves together
   visSizer->Add(leftSizer, 1, wxGROW | wxALIGN_CENTER, bsize);
  // GmatStaticBoxSizer *modelSizer = new GmatStaticBoxSizer(wxVERTICAL, this, "TLE File");
  // modelSizer->Add(visSizer, 0, wxALIGN_CENTER, 0);

   // Sizer for the page
  // wxBoxSizer *pageSizer = new wxBoxSizer(wxVERTICAL);
  // pageSizer->Add(modelSizer, 0, wxGROW | wxALIGN_CENTER, bsize);
  
      
   // Set the sizer to the overall sizer
   this->SetAutoLayout(true);  
   this->SetSizer(visSizer);//pageSizer
   
#ifdef DEBUG_PANEL_CREATE
   MessageInterface::ShowMessage("TransTlePanel::Create() leaving\n");
#endif
}
//------------------------------------------------------------------------------
// virtual void LoadData()
//------------------------------------------------------------------------------
void TransTlePanel::LoadData()
{

   // Reset data changed flags
   dataChanged = false;
   mTextChanged = false;
   
   #ifdef DEBUG_PANEL_LOAD
   MessageInterface::ShowMessage("TransTlePanel::LoadData() exiting.\n");
   #endif
}

//------------------------------------------------------------------------------
// void OnTextCtrlChange(wxCommandEvent &event)
//------------------------------------------------------------------------------
/**
 * Processes the the events where the filename text ctrl changes.
 */
//------------------------------------------------------------------------------
void TransTlePanel::OnTextCtrlChange(wxCommandEvent& event)
{
   mTextChanged = true;
	dataChanged = true;
	theScPanel->EnableUpdate(true);
}


//------------------------------------------------------------------------------
// void OnBrowseButton(wxCommandEvent& event)
//------------------------------------------------------------------------------
/**
 * This function occurs when the Browse button is pushed by the user.
 * It opens up a file dialog that allows the user to select a model.
 */
//------------------------------------------------------------------------------
void TransTlePanel::OnBrowseButton(wxCommandEvent& event)
{
	wxString filename, path;
	wxFileDialog fileDialog(this, wxT("Please select a model."), modelPath, wxEmptyString,
		wxT("tle files (*)|*"), gmatFD_OPEN);

	// If it succeeded...
	if (fileDialog.ShowModal() == wxID_OK)
	{
		// Load the model indicated by the path
		path = fileDialog.GetPath();

#ifdef DEBUG_NEW_MODEL
		MessageInterface::ShowMessage
		("VisualModelPanel::OnBrowseButton() New model path = '%s'\n", path.c_str());
#endif
		if (GmatFileUtil::DoesFileExist(path.c_str()))
		{
			modelTextCtrl->SetValue(path);
			// Save to cloned base spacecraft
			currentSpacecraft->SetStringParameter("ModelFile", path.c_str());
			// Auto scale model so that model can be shown
			dataChanged = true;
			theScPanel->EnableUpdate(true);
		}
		else
		{
			MessageInterface::ShowMessage
			("*** WARNING *** The model file '%s' does not exist. Please check the path.\n",
				path.WX_TO_C_STRING);
			return;
		}
		
	}
}





//------------------------------------------------------------------------------
// wxString ToString(Real rval)
//------------------------------------------------------------------------------
wxString TransTlePanel::ToString(Real rval)
{
   return theGuiManager->ToWxString(rval);
}

//------------------------------------------------------------------------------
// void SaveData()
//------------------------------------------------------------------------------
/**
 * Saves data to base Spacecraft.
 */
//------------------------------------------------------------------------------
void TransTlePanel::SaveData()
{
   canClose    = true;
   
   #ifdef DEBUG_PANEL_SAVE
   MessageInterface::ShowMessage
      ("TransTlePanel::SaveData() entered, mTextChanged=%d, dataChanged=%d, canClose=%d\n",
       mTextChanged, dataChanged, canClose);
   #endif
   

   if (canClose)
      dataChanged = false;
   
   #ifdef DEBUG_PANEL_SAVE
   MessageInterface::ShowMessage
      ("TransTlePanel::SaveData() leaving, mTextChanged=%d, dataChanged=%d, canClose=%d\n",
       mTextChanged, dataChanged, canClose);
   #endif
}
