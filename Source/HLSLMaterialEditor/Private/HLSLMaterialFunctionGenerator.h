﻿// Copyright 2021 Phyronnaz

#pragma once

#include "CoreMinimal.h"

class IMaterialEditor;
class UHLSLMaterialFunctionLibrary;
struct FHLSLMaterialFunction;

class FHLSLMaterialFunctionGenerator
{
public:
	static FString GenerateFunction(
		UHLSLMaterialFunctionLibrary& Library,
		const TArray<FString>& IncludeFilePaths,
		FHLSLMaterialFunction Function,
		FMaterialUpdateContext& UpdateContext);

private:
	static FString GenerateFunctionCode(const UHLSLMaterialFunctionLibrary& Library, const FHLSLMaterialFunction& Function);
	static IMaterialEditor* FindMaterialEditorForAsset(UObject* InAsset);
	static UObject* CreateAsset(FString AssetName, FString FolderPath, UClass* Class, FString& OutError);

	template<typename T>
	static T* CreateAsset(FString AssetName, FString FolderPath, FString& OutError)
	{
		return CastChecked<T>(CreateAsset(AssetName, FolderPath, T::StaticClass(), OutError), ECastCheckedType::NullAllowed);
	}
};