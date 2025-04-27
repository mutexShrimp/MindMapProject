// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UtilsFunctionLibrary.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FJsonFieldsV2Struct
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "JsonFieldsStruct")
	bool bIsContainQuotMark = true;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "JsonFieldsStruct")
	bool bIsCustomizeContent = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "JsonFieldsStruct")
	FString FieldContent;
};


UCLASS()
class MINDMAPPROJECT_API UUtilsFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Function | ConvertOperations")
	static FString MakeJsonFields(const TMap<FString, FJsonFieldsV2Struct>& Fields);

	static FString MakeJsonField(const FString& FieldName, const FJsonFieldsV2Struct& StringValue);

};
