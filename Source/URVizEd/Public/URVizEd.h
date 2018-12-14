// Copyright 2018, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

// Declare log types
DECLARE_LOG_CATEGORY_EXTERN(LogRVEd, All, All);

class FURVizEd : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
