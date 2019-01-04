// Copyright 2018, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#pragma once

#include "CoreMinimal.h"
#include "RVEdMode.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Toolkits/IToolkitHost.h"
#include "Toolkits/BaseToolkit.h"

// Forward declarations
class Error;
class IDetailsView;
class SErrorText;
class SRVEdWidget;
struct FPropertyAndParent;

/**
 * RViz class for all editor mode toolkit
 */
class FRVEdModeToolkit : public FModeToolkit
{
public:
	// Ctor
	FRVEdModeToolkit();
	
	/** FModeToolkit interface */
	virtual void Init(const TSharedPtr<IToolkitHost>& InitToolkitHost) override;

	/** IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FRVEdMode* GetEditorMode() const override;
	virtual TSharedPtr<class SWidget> GetInlineContent() const override;

private:
	// RViz tools widget
	TSharedPtr<SRVEdWidget> RVizToolsWidget;
};

/**
* Slate widget for the RViz Editor Mode
*/
class SRVEdWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SRVEdWidget)
	{
	}
	SLATE_END_ARGS()

	// Construct a SWidget based on initial parameters.
	void Construct(const FArguments& InArgs, TSharedRef<FRVEdModeToolkit> InParentToolkit);

	// Refresh panel
	void RefreshDetailPanel();

protected:
	FRVEdMode* GetEditorMode() const;

	FText GetErrorText() const;

	bool GetRVizEditorIsEnabled() const;

	bool GetIsPropertyVisible(const FPropertyAndParent& PropertyAndParent) const;

protected:
	TSharedPtr<SErrorText> Error;

	TSharedPtr<IDetailsView> DetailsPanel;
};