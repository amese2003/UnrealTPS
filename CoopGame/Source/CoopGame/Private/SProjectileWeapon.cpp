// Fill out your copyright notice in the Description page of Project Settings.


#include "SProjectileWeapon.h"


void ASProjectileWeapon::Fire() {
	AActor* myOwner = GetOwner();
	if (myOwner) {

		FVector eyeLoction;
		FRotator eyeRotation;
		myOwner->GetActorEyesViewPoint(eyeLoction, eyeRotation);

		FVector muzzleLocation = MeshComp->GetSocketLocation(MuzzleSocketName);
		FRotator muzzleRotation = MeshComp->GetSocketRotation(MuzzleSocketName);

		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		GetWorld()->SpawnActor<AActor>(projectileClass, muzzleLocation, muzzleRotation, SpawnParams);
	}
}