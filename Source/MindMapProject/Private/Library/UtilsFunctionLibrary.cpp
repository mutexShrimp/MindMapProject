// Fill out your copyright notice in the Description page of Project Settings.


#include "Library/UtilsFunctionLibrary.h"
#include "Kismet/KismetStringLibrary.h"

FString UUtilsFunctionLibrary::MakeJsonFields(const TMap<FString, FJsonFieldsV2Struct>& Fields)
{
	FString ReturnValue = "{";
	for (auto& field : Fields)
	{
		ReturnValue += MakeJsonField(field.Key, field.Value);
	}
	ReturnValue = UKismetStringLibrary::GetSubstring(ReturnValue, 0, ReturnValue.Len() - 1);
	return ReturnValue + "}";
}

FString UUtilsFunctionLibrary::MakeJsonField(const FString& FieldName, const FJsonFieldsV2Struct& StringValue)
{
	FString ReturnValue;
	ReturnValue += "\"" + FieldName + "\"" + ":";
	if (StringValue.bIsCustomizeContent)
	{		//自定义内容
		FString FieldContent = UKismetStringLibrary::TrimTrailing(StringValue.FieldContent);
		if (UKismetStringLibrary::EndsWith(FieldContent, ","))
		{
			ReturnValue += FieldContent;
		}
		else
		{
			ReturnValue += FieldContent + ",";
		}
	}
	else
	{
		ReturnValue += StringValue.bIsContainQuotMark ? "\"" + StringValue.FieldContent + "\"" + "," : StringValue.FieldContent + ",";
	}
	return ReturnValue;
}