// Fill out your copyright notice in the Description page of Project Settings.


#include "MySphere.h"
#include "Components/SphereComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine.h"
#include "DiceCharacter.h"

// Sets default values
AMySphere::AMySphere()
{
    // Set this actor to call Tick() every frame.  
    PrimaryActorTick.bCanEverTick = true;

    // Create and attach a static mesh component.
    SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
    RootComponent = SphereMesh;

    // Set the static mesh to a sphere.
    static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/Mesh/SM_Cylinder.SM_Cylinder'"));
    if (SphereMeshAsset.Succeeded())
    {
        SphereMesh->SetStaticMesh(SphereMeshAsset.Object);
    }

    // Setup collision to ignore all but allow pawn to pass through.
    SphereMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    SphereMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

    float RandomX = FMath::RandRange(-5000.0f, 5000.0f);
    float RandomY = FMath::RandRange(-5000.0f, 5000.0f);

    SphereMesh->SetRelativeLocation(FVector(RandomX, RandomY, -100.0f));
    SphereMesh->SetWorldScale3D(FVector(100.0f, 100.0f, 100.0f));
  
   

}



// Called when the game starts or when spawned
void AMySphere::BeginPlay()
{
	Super::BeginPlay();
    

}

	

// Called every frame
void AMySphere::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // 스태틱 메시의 크기 감소 예제
    FVector NewScale = GetActorScale3D() - FVector(DeltaTime, DeltaTime, 0);
    if (NewScale.X > 1.0f)
    {
        SetActorScale3D(NewScale);
    }

    static float ElapsedTime = 0.0f;
    ElapsedTime += DeltaTime;

    // 1초가 지날 때마다 health를 감소시킵니다.
    if (ElapsedTime >= 1.0f)
    {
        CheckCharacterPositionAndReduceHealth(DeltaTime);
        ElapsedTime = 0.0f; // 타이머를 초기화
    }
}

void AMySphere::CheckCharacterPositionAndReduceHealth(float DeltaTime)
{
    for (TActorIterator<ADiceCharacter> It(GetWorld()); It; ++It)
    {
        ADiceCharacter* Character = *It;

        // 스태틱 메시의 월드 위치
        FVector SphereOrigin = GetActorLocation();

        // 스태틱 메시의 현재 스케일
        float SphereScale = GetActorScale3D().X; // X, Y, Z 스케일을 모두 고려할 수 있습니다.

        // 스태틱 메시의 기본 크기 (가정: 기본 반지름 50)
        float BaseRadius = 50.0f;

        // 스태틱 메시의 현재 반지름 계산
        float SphereRadius = SphereScale * BaseRadius;

        // 캐릭터와 스태틱 메시의 거리를 계산
        float Distance = FVector::Dist(Character->GetActorLocation(), SphereOrigin);

        // 만약 캐릭터가 메시의 반지름 밖에 있다면, health를 감소시킵니다.
        if (Distance > SphereRadius)
        {
            Character->UpdateHealth(-5.0f); // 정확하게 5씩 감소
        }
    }
}

