// Copyright 2018, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#pragma once

#include "IDetailCustomization.h"
#include "Input/Reply.h"

class IDetailLayoutBuilder;

//////////////////////////////////////////////////////////////////////////
// FRVEdToolCustomization

class FRVEdToolCustomization : public IDetailCustomization
{
public:
	// Makes a new instance of this detail layout class for a specific detail view requesting it
	static TSharedRef<IDetailCustomization> MakeInstance();

	//IDetailCustomization interface
	void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;
	//End of IdetailCustomization interface

	static FReply ExecuteCommand(IDetailLayoutBuilder* DetailBuilder, UFunction* MethodToExecute);
};