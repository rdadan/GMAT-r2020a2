//$Id$
//------------------------------------------------------------------------------
//                            VisualModelPanel
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
// Author: Phillip Silvia, Jr.
// Created: 2009/08/12
/**
 * This class contains information needed to setup users spacecraft visual 
 * model through GUI.
 */
//------------------------------------------------------------------------------
#ifndef TransTlePanel_hpp
#define TransTlePanel_hpp

#include "gmatwxdefs.hpp"
#include "GuiInterpreter.hpp"
#include "GuiItemManager.hpp"
#include "GmatAppData.hpp"
#include "GmatPanel.hpp"
#include "wx/spinctrl.h"
#include <wx/clrpicker.h>           // for wxColorPickerCtrl
#include "Spacecraft.hpp"

class TransTlePanel: public wxPanel
{
public:
   TransTlePanel(GmatPanel *scPanel, wxWindow *parent,
              Spacecraft *spacecraft);
   ~TransTlePanel();
   
   bool IsDataChanged() { return dataChanged; }
   bool CanClosePanel() { return canClose; }
   void SaveData();

   bool CanvasOn(bool onOrOff);

protected:
      
   // Event Handling
   DECLARE_EVENT_TABLE();
   
   void OnTextCtrlChange(wxCommandEvent& event);
  // void OnTextCtrlEnter(wxCommandEvent& event);
   void OnBrowseButton(wxCommandEvent& event);
 
  // void UpdateTextCtrl(int id);
   
private:

   bool dataChanged;
   bool canClose;
   bool mTextChanged;
	bool interfaceEnabled;
   
   wxString modelPath;
   
   // The current spacecraft
   Spacecraft     *currentSpacecraft;

   // The gui manager
   GuiItemManager *theGuiManager;
   //// The canvas for drawing the model and its transformations
   //VisualModelCanvas *modelCanvas;


   // Text Display for the current scale value
   wxTextCtrl *scaleValueText;

   // Text for loading the model
   wxTextCtrl *modelTextCtrl;

   // The spacecraft panel that this panel belongs to
   GmatPanel *theScPanel;
   
   void Create();
   void LoadData();
 //  void ToggleInterface(bool enable);
   wxString ToString(Real rval);
  
   // IDs for the controls and the menu commands
   enum
   {     
      ID_TEXT = 30200,
      ID_MODELFILE_TEXT,
      ID_CANVAS,
      ID_FRAME,
      
      ID_BROWSE_BUTTON,
      ID_RECENTER_BUTTON,
		ID_AUTOSCALE_BUTTON,
      ID_EARTH_BUTTON,
      
      ID_ROT_SLIDER,
      ID_TRAN_SLIDER,
      ID_SCALE_SLIDER,
      
      ID_ROT_TEXT,
      ID_TRAN_TEXT,
      ID_SCALE_TEXT,
      
      ID_STATIC_ELEMENT,
      
      ID_COLOR_CTRL,
   };
};
#endif

