// copy right ly


#include "AbilitySystem/Abilities/AuraFireBolt.h"
#include "Aura/Public/AuraGameplayTags.h"

FString UAuraFireBolt::GetDescription(int32 Level)
{
	const int32 Damage = GetDamageByDamageType(Level,FAuraGameplayTags::Get().Damage_Fire);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	if (Level == 1)
	{
		return FString::Printf(TEXT(
			// 标题
			"<Title>FIRE BOLT</>\n\n"
			// 等级以及消耗
			"<Small>Level : </><Level>%d</>\n"
			"<Small>ManaCost</><ManaCost>%.1f</>\n"
			//冷却时间
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			//伤害类型
			"<Default>Launches a bolt of fire ,exploding on impact and dealing: </>"
			"<Damage> % d</>"
			"<Default>fire damage, chance to burn</>"),
			Level,
			ManaCost,
			Cooldown,
			Damage);
	}
	else
	{
		return FString::Printf(TEXT(
			// 标题
			"<Title>FIRE BOLT</>\n\n"
			// 等级以及消耗
			"<Small>Level : </><Level>%d</>\n"
			"<Small>ManaCost</><ManaCost>%.1f</>\n"
			//冷却时间
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			//伤害类型
			"<Default>Launches %d bolts of fire ,exploding on impact and dealing: </>"
			"<Damage> % d</>"
			"<Default>fire damage, chance to burn</>"),
			Level,
			ManaCost,
			Cooldown,
			FMath::Min(Level, NumProjectiles),
			Damage);
	}
}

FString UAuraFireBolt::GetNextLevelDescription(int32 Level)
{
	const int32 Damage = DamageTypes[FAuraGameplayTags::Get().Damage_Fire].GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	return FString::Printf(TEXT(
		// 标题
		"<Title>Next Level</>\n\n"
		// 等级以及消耗
		"<Small>Level : </><Level>%d</>\n"
		"<Small>ManaCost</><ManaCost>%.1f</>\n"
		//冷却时间
		"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
		//伤害类型
		"<Default>Launches %d bolts of fire ,exploding on impact and dealing: </>"
		"<Damage> % d</>"
		"<Default>fire damage, chance to burn</>"),
		Level,
		ManaCost,
		Cooldown,
		FMath::Min(Level, NumProjectiles),
		Damage);
}