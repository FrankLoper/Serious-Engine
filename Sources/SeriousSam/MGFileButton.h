/* Copyright (c) 2002-2012 Croteam Ltd. All rights reserved. */

#ifndef SE_INCL_MENU_GADGET_FILEBUTTON_H
#define SE_INCL_MENU_GADGET_FILEBUTTON_H
#ifdef PRAGMA_ONCE
  #pragma once
#endif

#include "MGEdit.h"

// file button states
#define FBS_NORMAL    0 // normal active state
#define FBS_SAVENAME  1 // typing in the save name
#define FBS_RENAME    2 // renaming existing file
class CMGFileButton : public CMGEdit {
public:
	CMGFileButton(void);
	CTFileName mg_fnm;
	CTString mg_strDes;   // entire description goes here
	CTString mg_strInfo;  // info part of text to print above the gadget tip
	INDEX mg_iState;
	// refresh current text from description
	void RefreshText(void);
	// save description to disk
	void SaveDescription(void);
	void SaveYes(void);
	void DoSave(void);
	void DoLoad(void);
	void StartEdit(void);

	// return TRUE if handled
	BOOL OnKeyDown(int iVKey);
	void OnActivate(void);
	void OnSetFocus(void);
	void OnKillFocus(void);

	// overrides from edit gadget
	void OnStringChanged(void);
	void OnStringCanceled(void);
	void Render(CDrawPort *pdp);
};

#endif  /* include-once check. */