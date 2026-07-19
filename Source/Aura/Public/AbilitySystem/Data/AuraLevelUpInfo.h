// copy right ly

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AuraLevelUpInfo.generated.h"

USTRUCT(BlueprintType)
struct FAuraLevelUpInfoRow
{
	GENERATED_BODY();

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	float LevelUpRequirement = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float AttributePointAward = 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float SpellPointReward = 1;
};
/**
 * 
 */
UCLASS()
class AURA_API UAuraLevelUpInfo : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AbilityInformation")
	TArray<FAuraLevelUpInfoRow> LevelUpInformation;
	
	int32 FindLevelForXP(int32 XP);
};
