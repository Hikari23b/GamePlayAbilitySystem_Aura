// copy right ly


#include "AI/BTService_FindNearestPlayer.h"
#include "AIController.h"
#include <Kismet/GameplayStatics.h>
#include <BehaviorTree/BTFunctionLibrary.h>

void UBTService_FindNearestPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* OwningPawn = AIOwner->GetPawn();

	const FName TargetTag = OwningPawn->ActorHasTag(FName("Player")) ? FName("Enemy") : FName("Player");

	TArray<AActor*> ActorsWithTag;
	UGameplayStatics::GetAllActorsWithTag(OwningPawn, TargetTag, ActorsWithTag);

	float ClosestDistance = TNumericLimits<float>::Max();
	AActor* CloestActor = nullptr;

	for (auto Actor : ActorsWithTag)
	{
		GEngine->AddOnScreenDebugMessage(2, .5f, FColor::Orange, *Actor->GetName());
		if (IsValid(Actor) && IsValid(OwningPawn))
		{
			const float Distance = OwningPawn->GetDistanceTo(Actor);
			if (Distance < ClosestDistance)
			{
				ClosestDistance = Distance;
				CloestActor = Actor;
			}
		}
	}
	UBTFunctionLibrary::SetBlackboardValueAsObject(this, TargetToFollowSelector, CloestActor);
	UBTFunctionLibrary::SetBlackboardValueAsFloat(this, DistanceToTargetSelector, ClosestDistance);
}
