// Copyright 2018, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#include "RVEdModeToolkit.h"
#include "RVEdMode.h"
#include "Engine/Selection.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Text/STextBlock.h"
#include "EditorModeManager.h"


#include "PropertyEditorModule.h"
#include "SlateOptMacros.h"

#include "IDetailsView.h"
#include "IIntroTutorials.h"

#include "Widgets/Input/SButton.h"
#include "Widgets/Text/STextBlock.h"
#include "EditorModeManager.h"

#include "RVEdToolCustomization.h"

#define LOCTEXT_NAMESPACE "FRVEdModeToolkit"

// Ctor
FRVEdModeToolkit::FRVEdModeToolkit()
{
}

// Initializes the mode toolkit
void FRVEdModeToolkit::Init(const TSharedPtr<IToolkitHost>& InitToolkitHost)
{
	FRVEdMode* RVizEdMode = GetEditorMode();
	
	RVizToolsWidget = SNew(SRVEdWidget, SharedThis(this));

	FModeToolkit::Init(InitToolkitHost);
}

FName FRVEdModeToolkit::GetToolkitFName() const
{
	return FName("RVEdMode");
}

FText FRVEdModeToolkit::GetBaseToolkitName() const
{
	return NSLOCTEXT("RVEdModeToolkit", "DisplayName", "RViz Mode");
}

class FRVEdMode* FRVEdModeToolkit::GetEditorMode() const
{
	return (FRVEdMode*) GLevelEditorModeTools().GetActiveMode(FRVEdMode::EM_RVizEditorMode);
}

TSharedPtr<class SWidget> FRVEdModeToolkit::GetInlineContent() const 
{
	return RVizToolsWidget; 
}

/////////////////////////////////////////////////////////////////////////
BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
// Construct a SWidget based on initial parameters.
void SRVEdWidget::Construct(const FArguments& InArgs, TSharedRef<FRVEdModeToolkit> InParentToolkit)
{
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

	PropertyEditorModule.RegisterCustomClassLayout(URVEdTool::StaticClass()->GetFName(), FOnGetDetailCustomizationInstance::CreateStatic(
		&FRVEdToolCustomization::MakeInstance));
	PropertyEditorModule.NotifyCustomizationModuleChanged();

	FDetailsViewArgs DetailsViewArgs(false, false, false, FDetailsViewArgs::HideNameArea);

	DetailsPanel = PropertyEditorModule.CreateDetailView(DetailsViewArgs);
	DetailsPanel->SetIsPropertyVisibleDelegate(FIsPropertyVisible::CreateSP(this, &SRVEdWidget::GetIsPropertyVisible));

	FRVEdMode* RVizEditorMode = GetEditorMode();

	if (RVizEditorMode)
	{
		// Refresh details panel
		DetailsPanel->SetObject(RVizEditorMode->RVizEditorTool);
	}

	ChildSlot
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.Padding(0)
		[
			SNew(SVerticalBox)
			.IsEnabled(this, &SRVEdWidget::GetRVizEditorIsEnabled)
			+ SVerticalBox::Slot()
			.Padding(0)
			[
				DetailsPanel.ToSharedRef()
			]
		]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FRVEdMode* SRVEdWidget::GetEditorMode() const
{
	return (FRVEdMode*)GLevelEditorModeTools().GetActiveMode(FRVEdMode::EM_RVizEditorMode);
}

FText SRVEdWidget::GetErrorText() const
{
	FRVEdMode* RVizEdMode = GetEditorMode();
	return FText::GetEmpty();
}

bool SRVEdWidget::GetRVizEditorIsEnabled() const
{
	FRVEdMode* RVizEdMode = GetEditorMode();
	if (RVizEdMode)
	{
		return true;
	}
	return false;
}

bool SRVEdWidget::GetIsPropertyVisible(const FPropertyAndParent& PropertyAndParent) const
{
	return true;
}

void SRVEdWidget::RefreshDetailPanel()
{
	FRVEdMode* RVizEdMode = GetEditorMode();
	if (RVizEdMode)
	{
		// Refresh details panel
		DetailsPanel->SetObject(RVizEdMode->RVizEditorTool, true);
	}
}
#undef LOCTEXT_NAMESPACE
