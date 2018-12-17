// Copyright 2018, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#include "RVEdStyle.h"
#include "SlateGameResources.h"
#include "IPluginManager.h"
#include "Styling/SlateTypes.h"
#include "Interfaces/IPluginManager.h"

TSharedPtr<FSlateStyleSet> FRVEdStyle::StyleSetInstance = NULL;

// Create style singleton
void FRVEdStyle::Initialize()
{
	if (!StyleSetInstance.IsValid())
	{
		StyleSetInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleSetInstance);
	}
};

// Destroy singleton
void FRVEdStyle::Shutdown()
{
	if (StyleSetInstance.IsValid())
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*StyleSetInstance);
		ensure(StyleSetInstance.IsUnique());
		StyleSetInstance.Reset();
	}
}

// Get reference to the style singleton
const ISlateStyle& FRVEdStyle::Get()
{
	return *StyleSetInstance;
}

// Style name
FName FRVEdStyle::GetStyleSetName()
{
	static FName StyleName(TEXT("RVEdStyle"));
	return StyleName;
}

#define IMAGE_BRUSH_RV(RelativePath, ...) FSlateImageBrush(Style->RootToContentDir(RelativePath, TEXT(".png")), __VA_ARGS__)
// Returns a new style
TSharedRef< FSlateStyleSet > FRVEdStyle::Create()
{
	const FVector2D Icon20x20(20.0f, 20.0f);
	const FVector2D Icon40x40(40.0f, 40.0f);

	TSharedRef<FSlateStyleSet> Style = MakeShareable(new FSlateStyleSet(GetStyleSetName()));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin(TEXT("URViz"))->GetContentDir());

	Style->Set("LevelEditor.RVizEd", new IMAGE_BRUSH_RV(TEXT("Icons/RobCoG_RViz_Mode_40px"), Icon40x40));
	Style->Set("LevelEditor.RVizEd.Small", new IMAGE_BRUSH_RV(TEXT("Icons/RobCoG_RViz_Mode_40px"), Icon20x20));

	return Style;
}
#undef IMAGE_BRUSH_RV

// Reloads all texture resources from disk
void FRVEdStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}